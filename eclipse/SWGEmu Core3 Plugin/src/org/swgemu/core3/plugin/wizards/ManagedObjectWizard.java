package org.swgemu.core3.plugin.wizards;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
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
import org.swgemu.core3.plugin.shared.*;

import org.swgemu.core3.plugin.shared.Core3Shared;
import org.swgemu.core3.plugin.wizards.ManagedObjectWizardPage;


/**
 * This is a sample new wizard. Its role is to create a new file 
 * resource in the provided container. If the container resource
 * (a folder or a project) is selected in the workspace 
 * when the wizard is opened, it will accept it as the target
 * container. The wizard creates one file with the extension
 * "idl". If a sample multi-page editor (also available
 * as a template) is registered for the same extension, it will
 * be able to open it.
 */

public class ManagedObjectWizard extends Wizard implements INewWizard {
	private ManagedObjectWizardPage page;
	private ISelection selection;

	/**
	 * Constructor for ManagedObjectWizard.
	 */
	public ManagedObjectWizard() {
		super();
		setNeedsProgressMonitor(true);
	}

	/**
	 * Adding the page to the wizard.
	 */

	public void addPages() {
		page = new ManagedObjectWizardPage(selection);
		addPage(page);
	}

	/**
	 * This method is called when 'Finish' button is pressed in
	 * the wizard. We will create an operation and run it
	 * using wizard as execution context.
	 */
	public boolean performFinish() {
		final String containerName = page.getContainerName();
		final String fileName = page.getClassName();
		final boolean createImpl = page.createImplementationCpp();
		final String superClassName = page.getSuperClassName();
		final String packageName = page.getPackageName();
		final String[] interfaces = page.getInterfaces();
		final boolean makefile = page.updateMakefile();

		IRunnableWithProgress op = new IRunnableWithProgress() {
			public void run(IProgressMonitor monitor) throws InvocationTargetException {
				try {
					doFinish(containerName, fileName, superClassName, packageName, createImpl, interfaces, makefile, monitor);
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

	/**
	 * The worker method. It will find the container, create the
	 * file if missing or just replace its contents, and open
	 * the editor on the newly created file.
	 */

	private void doFinish(
			String containerName,
			String fileName,
			String superClassName,
			String packageName,
			boolean createImpl,
			String[] interfaces,
			boolean makefile,
			IProgressMonitor monitor)
	throws CoreException {
		// create a sample file
		// register makefile
		if (makefile)
			Core3Shared.registerMakefile(fileName, containerName, createImpl, monitor, true);

		monitor.beginTask("Creating " + fileName, 2);
		IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
		IResource resource = root.findMember(new Path(containerName));

		if (!resource.exists() || !(resource instanceof IContainer)) {
			throwCoreException("Container \"" + containerName + "\" does not exist.");
		}

		IContainer container = (IContainer) resource;

		final IFile file = container.getFile(new Path(fileName + ".idl"));

		try {
			InputStream stream = Core3Shared.generateManagedObject(fileName, superClassName, packageName, interfaces, null, null, null, null);
			
			if (file.exists()) {
				file.setContents(stream, true, true, monitor);
			} else {
				file.create(stream, true, monitor);
			}
			stream.close();
		} catch (IOException e) {
		}

		if (createImpl) {
			final IFile implementationFile = container.getFile(new Path(fileName + "Implementation.cpp"));

			try {
				InputStream stream = Core3Shared.generateImplementation(fileName);

				if (implementationFile.exists()) {
					implementationFile.setContents(stream, true, true, monitor);
				} else {
					implementationFile.create(stream, true, monitor);
				}

				stream.close();

			} catch (IOException e) {

			}
		}

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

	/**
	 * We will initialize file contents with a sample text.
	 */

	private void throwCoreException(String message) throws CoreException {
		IStatus status =
			new Status(IStatus.ERROR, "SWGEmu_Core3_Plugin", IStatus.OK, message, null);
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