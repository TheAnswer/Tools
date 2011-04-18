package org.swgemu.core3.plugin.wizards;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.PlatformUI;
import org.eclipse.core.runtime.*;
import org.eclipse.jface.operation.*;
import java.lang.reflect.InvocationTargetException;

import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.core.resources.*;
import org.eclipse.core.runtime.CoreException;
import java.io.*;

import org.eclipse.ui.*;
import org.eclipse.ui.ide.IDE;

import org.swgemu.core3.plugin.shared.Core3Shared;
import org.swgemu.core3.plugin.wizards.ManagerNewWizardPage;


/**
 * This is a sample new wizard. Its role is to create a new file 
 * resource in the provided container. If the container resource
 * (a folder or a project) is selected in the workspace 
 * when the wizard is opened, it will accept it as the target
 * container. The wizard creates one file with the extension
 * "cpp". If a sample multi-page editor (also available
 * as a template) is registered for the same extension, it will
 * be able to open it.
 */

public class ManagerNewWizard extends Wizard implements INewWizard {
	private ManagerNewWizardPage page;
	private ISelection selection;

	/**
	 * Constructor for ManagerNewWizard.
	 */
	public ManagerNewWizard() {
		super();
		setNeedsProgressMonitor(true);
	}

	/**
	 * Adding the page to the wizard.
	 */

	public void addPages() {
		page = new ManagerNewWizardPage(selection);
		addPage(page);
	}

	/**
	 * This method is called when 'Finish' button is pressed in
	 * the wizard. We will create an operation and run it
	 * using wizard as execution context.
	 */
	public boolean performFinish() {
		final String containerName = page.getContainerName();
		final String fileName = page.getFileName();
		final String superClass = page.getSuperClass();
		final boolean generateService = page.generateManagedService();
		final boolean generateImplementationCpp = page.generateImplementationCpp();
		final boolean registerMakefile = page.registerMakefile();
		final boolean createInProcessor = page.createInZoneProcessor();

		IRunnableWithProgress op = new IRunnableWithProgress() {
			public void run(IProgressMonitor monitor) throws InvocationTargetException {
				try {

					doFinish(containerName, fileName, monitor, superClass, generateService, generateImplementationCpp, registerMakefile, createInProcessor);

				} catch (CoreException e) {
					throw new InvocationTargetException(e);
				} finally {
					monitor.done();
				}
			}
		};

		try {
			getContainer().run(true, false, op);
		} catch (InterruptedException e) {
			return false;
		} catch (InvocationTargetException e) {
			Throwable realException = e.getTargetException();
			MessageDialog.openError(getShell(), "Error", realException.getMessage());
			return false;
		}

		return true;
	}

	private IFile generateSingleton(String className, String superClass, IContainer container, IProgressMonitor monitor, final String packageName)
	throws CoreException {
		final IFile file = container.getFile(new Path(className + ".h"));

		try {

			InputStream stream = Core3Shared.generateHeader(className, superClass, packageName);

			if (file.exists()) {
				file.setContents(stream, true, true, monitor);
			} else {
				file.create(stream, true, monitor);
			}

			stream.close();
		} catch (IOException e) {
		}

		final IFile cppFile = container.getFile(new Path(className + ".cpp"));

		try {

			InputStream stream = Core3Shared.generateSource(className);

			if (cppFile.exists()) {
				cppFile.setContents(stream, true, true, monitor);
			} else {
				cppFile.create(stream, true, monitor);
			}

			stream.close();
		} catch (IOException e) {
		}

		return cppFile;
	}

	private void createManagerInProcessor(final String memberName, final String className, String managerContainer, IContainer container, IProgressMonitor monitor, boolean singleton) 
	throws CoreException {
		try {
			final IFile file = container.getFile(new Path("ZoneProcessServerImplementation.cpp"));

			InputStream oldFile = file.getContents();

			BufferedReader reader = new BufferedReader(new InputStreamReader(oldFile));

			StringBuffer fileData = Core3Shared.getStringBufferFromReader(reader);

			reader.close();
			
			//creating our class
			StringBuffer sb = null;
			
			if (singleton) {
				sb = Core3Shared.replaceText(fileData.toString(), "zonePacketHandler = new", memberName + " = " + className + "::instance();\n\n\tzonePacketHandler = new", true);
			} else {
				sb = Core3Shared.replaceText(fileData.toString(), "zonePacketHandler = new", memberName + " = new " + className + "(_this);\n\n\tzonePacketHandler = new", true);
			}
			
			String includePath = managerContainer.substring(managerContainer.indexOf("server"));
			
			sb = Core3Shared.replaceText(sb.toString(), "#include", "#include \"" + includePath + "/" + className + ".h\"\n#include", true);
			
			//include our file
						
			oldFile.close();

			InputStream writeStream = new ByteArrayInputStream(sb.toString().getBytes()); 

			file.setContents(writeStream, true, true, monitor);

			writeStream.close();

		} catch (IOException e) {

		}

	}

	private void createInZoneProcessor(String className, String containerName, IProgressMonitor monitor, String packageName, boolean singleton) 
	throws CoreException {
		String zoneProcessorPath = containerName.substring(0, containerName.indexOf("zone") + 4);

		IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
		IResource resource = root.findMember(new Path(zoneProcessorPath));

		if (!resource.exists() || !(resource instanceof IContainer)) {
			throwCoreException("Container \"" + zoneProcessorPath + "\" does not exist.");
		}

		IContainer container = (IContainer) resource;

		final IFile idlFile = container.getFile(new Path("ZoneProcessServer.idl"));

		//adding as member and a getter to ZoneProcessServer.idl
		try {			
			InputStream oldFile = idlFile.getContents();

			BufferedReader reader = new BufferedReader(new InputStreamReader(oldFile));

			StringBuffer fileData = Core3Shared.getStringBufferFromReader(reader);

			reader.close();

			final String classMember = className.substring(0, 1).toLowerCase() + className.substring(1);

			//inserting the member
			StringBuffer sb = Core3Shared.replaceText(fileData.toString(), "ZoneServer zoneServer;", "ZoneServer zoneServer;\n\n\ttransient protected " + className + " " + classMember +";", true);

			//inserting the getter
			if (!singleton)
				sb = Core3Shared.replaceText(sb.toString(), "// setters and getters", "// setters and getters\n\tpublic " + className + " get" + className + "() {\n\t\treturn " + classMember + ";\n\t}\n", true);
			else
				sb = Core3Shared.replaceText(sb.toString(), "// setters and getters", "// setters and getters\n\t@local\n\tpublic " + className + " get" + className + "() {\n\t\treturn " + classMember + ";\n\t}\n", true);
			
			//inserting the import
			sb = Core3Shared.replaceText(sb.toString(), "import", "import " + packageName + "." + className + ";\nimport", true);

			//done
			oldFile.close();

			InputStream writeStream = new ByteArrayInputStream(sb.toString().getBytes()); 

			idlFile.setContents(writeStream, true, true, monitor);

			writeStream.close();
			
			createManagerInProcessor(classMember, className, containerName, container, monitor, singleton);

		} catch (IOException e) {
		}

	}

	private IFile generateManagedService(String className, String superClass, String packageName, boolean generateImplementationCpp, IContainer container, IProgressMonitor monitor)
	throws CoreException {
		final IFile file = container.getFile(new Path(className + ".idl"));

		try {
			String[] imports = { "server.zone.managers.ZoneManager" };
			String[] ctorParameters = { "ZoneProcessServer" };
			String[] members = null;

			String ctorContents = new String();

			if (superClass.equalsIgnoreCase("ZoneManager")) {
				ctorContents += "super(\"" + className + "\");\n";

				ctorContents += "super.setZoneProcessor(zoneProcessServer);";
			} else {
				members = new String[]{ "ZoneProcessServer" };

				ctorContents += "this.zoneProcessServer = zoneProcessServer;";

				if (superClass.length() < 1) {
					superClass = "ManagedService";
				}
			}

			InputStream stream = Core3Shared.generateManagedObject(className, superClass, packageName, null, imports, members, ctorParameters, ctorContents);

			if (file.exists()) {
				file.setContents(stream, true, true, monitor);
			} else {
				file.create(stream, true, monitor);
			}

			stream.close();
		} catch (IOException e) {
		}

		if (generateImplementationCpp) {
			try {

				final IFile cppFile = container.getFile(new Path(className + "Implementation.cpp"));

				InputStream stream = Core3Shared.generateImplementation(className);

				if (cppFile.exists()) {
					cppFile.setContents(stream, true, true, monitor);
				} else {
					cppFile.create(stream, true, monitor);
				}

				stream.close();
			} catch (IOException e) {
			}
		}

		return file;
	}

	/**
	 * The worker method. It will find the container, create the
	 * file if missing or just replace its contents, and open
	 * the editor on the newly created file.
	 */

	private void doFinish(String containerName, 
			String fileName, 
			IProgressMonitor monitor, 
			String superClass, 
			boolean generateService, 
			boolean generateImplementationCpp,
			boolean registerMakefile,
			boolean createInProcessor)
	throws CoreException {
		// create a sample file
		monitor.beginTask("Creating " + fileName, 2);
		IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
		IResource resource = root.findMember(new Path(containerName));

		if (!resource.exists() || !(resource instanceof IContainer)) {
			throwCoreException("Container \"" + containerName + "\" does not exist.");
		}

		IContainer container = (IContainer) resource;

		String packageName = containerName.substring(containerName.indexOf("server"));
		packageName = packageName.replaceAll(String.valueOf(File.separatorChar), ".");

		final IFile file;

		if (generateService)
			file = generateManagedService(fileName, superClass, packageName, generateImplementationCpp, container, monitor);
		else
			file = generateSingleton(fileName, superClass, container, monitor, packageName);

		if (registerMakefile)
			Core3Shared.registerMakefile(fileName, containerName, generateImplementationCpp, monitor, generateService);

		if (createInProcessor)
			createInZoneProcessor(fileName, containerName, monitor, packageName, !generateService);

		monitor.worked(1);

		monitor.setTaskName("Opening file for editing...");

		getShell().getDisplay().asyncExec(new Runnable() {

			public void run() {
				IWorkbenchPage page =
					PlatformUI.getWorkbench().getActiveWorkbenchWindow().getActivePage();
				try {
					IDE.openEditor(page, file, true);
				} catch (PartInitException e) {
				}
			}
		});

		monitor.worked(1);
	}

	private void throwCoreException(String message) throws CoreException {
		IStatus status =
			new Status(IStatus.ERROR, "SWGEmu_Core3_ManagedObject_Plugin", IStatus.OK, message, null);
		throw new CoreException(status);
	}

	/**
	 * We will accept the selection in the workbench to see if
	 * we can initialize from it.
	 * @see IWorkbenchWizard#init(IWorkbench, IStructuredSelection)
	 */
	public void init(IWorkbench workbench, IStructuredSelection selection) {
		this.selection = selection;
	}
}