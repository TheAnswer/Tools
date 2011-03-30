package swgemu_core3_plugin.wizards;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.eclipse.core.runtime.*;
import org.eclipse.jface.operation.*;
import org.eclipse.jface.preference.IPreferenceStore;

import java.lang.reflect.InvocationTargetException;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.core.resources.*;
import org.eclipse.core.runtime.CoreException;
import java.io.*;
import org.eclipse.ui.*;
import org.eclipse.ui.ide.IDE;
import swgemu_core3_plugin.Activator;
import swgemu_core3_plugin.preferences.PreferenceConstants;
import java.util.regex.*;


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

	private void registerMakefile(final String className, final String containerName, boolean registerImplementation, IProgressMonitor monitor) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		monitor.beginTask("Registering to makefile.am", 1);

		final String core3Path = store.getString(PreferenceConstants.P_PATH);
		String srcPath = containerName.substring(containerName.indexOf("src/"));
		srcPath = srcPath.replaceAll("src/", "");

		try {
			StringBuffer fileData = new StringBuffer(1000);
			File file = new File (core3Path + "/src/Makefile.am");
			
			if (!file.exists())
				return;
			
			BufferedReader reader = new BufferedReader(new FileReader(file));
			
			char[] buf = new char[1024];

			int numRead = 0;

			while ((numRead = reader.read(buf)) != -1){
				String readData = String.valueOf(buf, 0, numRead);
				fileData.append(readData);
				buf = new char[1024];
			}

			reader.close();
			
			 // Create a pattern to match cat
	        Pattern p = Pattern.compile("core3_IDLS =");
	        // Create a matcher with an input string
	        Matcher m = p.matcher(fileData);
	        StringBuffer sb = new StringBuffer();
	        boolean result = m.find();
	        // Loop through and create a new String 
	        // with the replacements
	        
	        if (result) {
	        	m.appendReplacement(sb, "core3_IDLS =\t" + srcPath + "/" + className + ".cpp \\\\\n\t\t\t");
	        }
	        
	        // Add the last segment of input to 
	        // the new String
	        m.appendTail(sb);
	        
	        if (registerImplementation) {
	        	p = Pattern.compile("core3_IDLS\\) \\\\");
	        	m = p.matcher(sb.toString());
	        	
	        	sb.delete(0, sb.length() - 1);
	        	
	        	result = m.find();
	        	
	        	if (result)
	        		m.appendReplacement(sb, "core3_IDLS\\) \\\\\n\t\t" + srcPath + "/" + className + "Implementation.cpp \\\\");
	        	
	        	m.appendTail(sb);
	        }
	        	        
	        BufferedWriter out = new BufferedWriter(new FileWriter(core3Path + "/src/Makefile.am"));
	        out.write(sb.toString());
	        out.close();
	        
		} catch (FileNotFoundException ex) {
			return;
		} catch (IOException ex) {
			return;
		}
		
		monitor.worked(1);
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
			registerMakefile(fileName, containerName, createImpl, monitor);
		
		monitor.beginTask("Creating " + fileName, 2);
		IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
		IResource resource = root.findMember(new Path(containerName));

		if (!resource.exists() || !(resource instanceof IContainer)) {
			throwCoreException("Container \"" + containerName + "\" does not exist.");
		}

		IContainer container = (IContainer) resource;

		final IFile file = container.getFile(new Path(fileName + ".idl"));

		try {
			InputStream stream = openContentStream(fileName, superClassName, packageName, interfaces);
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
				InputStream stream = openImplementationContentStream(fileName);

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

	private InputStream openImplementationContentStream(final String className) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		String contents = store.getString(PreferenceConstants.P_LICENSE) + "\n" + "#include \"" + className + ".h\"\n";

		return new ByteArrayInputStream(contents.getBytes());
	}

	private InputStream openContentStream(final String className, final String superClassName, final String packageName, String[] interfaces) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		String contents = store.getString(PreferenceConstants.P_LICENSE) + "\n" +
		"package " + packageName + ";\n" +
		"import engine.core.ManagedObject;" +
		"\n" +
		"\n" +
		"class " + className + " extends " + superClassName + " ";
		
		if (interfaces.length > 0) {
			contents += "implements ";
			
			for (int i = 0; i < interfaces.length; i++) {
				contents += interfaces[i];
				
				if (i + 1 < interfaces.length)
					contents += ", ";
				
				if (i % 4 == 0)
					contents += "\n\t\t\t\t";
			}
			
			contents += " ";
		}
		
		contents += "{\n";
		
		contents += generateConstructor(className);
		
		contents += "}\n";
		
		return new ByteArrayInputStream(contents.getBytes());
	}
	
	private String generateConstructor(String className) {
		String returnString = "\n\tpublic " + className + "() {" + "\n" 
								+ "\t}\n";
		
		return returnString;
	}
	
	/*private String generateHelperMethds() {
		String data = "\n\t\t\t public initializeTransientMembers() {\n" +
						"\t\t\t\t super.initializeTransientMembers();\n" +
						"\t\t\t\t}\n" +
						"\t\t\t public initializeTransientMembers() {\n"
		
		
		return data;
	}*/

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