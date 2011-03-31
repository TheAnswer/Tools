package swgemu.core3.plugin.shared;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.FileNotFoundException;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.StringTokenizer;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.preference.IPreferenceStore;

import swgemu.core3.plugin.Activator;
import swgemu.core3.plugin.preferences.PreferenceConstants;

public class Core3Shared {
	
	//probably should create Header, Source and Makfile classes and store the logic there TODO if needed or have time
	
	static public StringBuffer getStringBufferFromReader(BufferedReader reader) 
	throws IOException {
		StringBuffer fileData = new StringBuffer(1000);
		
		char[] buf = new char[1024];

		int numRead = 0;

		while ((numRead = reader.read(buf)) != -1){
			String readData = String.valueOf(buf, 0, numRead);
			fileData.append(readData);
			buf = new char[1024];
		}

		return fileData;
	}
	
	static public StringBuffer replaceText(final String text, final String searchPattern, final String replacement, boolean once) {
		Pattern p = Pattern.compile(searchPattern);
		Matcher m = p.matcher(text);

		StringBuffer sb = new StringBuffer(text.length());
		
		if (once) {
			if (m.find())
				m.appendReplacement(sb, replacement);
		} else {
			while (m.find())
				m.appendReplacement(sb, replacement);
		}

		m.appendTail(sb);
		
		return sb;
	}
	
	static public void registerMakefile(final String className, final String containerName, boolean registerImplementation, IProgressMonitor monitor, boolean idl) 
	throws CoreException {

		monitor.beginTask("Registering to makefile.am", 1);
		
		String srcPath = containerName.substring(0, containerName.indexOf("src") + 3);
		String filePath = containerName.substring(containerName.indexOf("server"));

		IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
		IResource resource = root.findMember(new Path(srcPath));

		if (!resource.exists() || !(resource instanceof IContainer)) {
			IStatus status =
				new Status(IStatus.ERROR, "SWGEmu_Core3_ManagedObject_Plugin", IStatus.OK, "Container \"" + srcPath + "\" does not exist.", null);
			
			throw new CoreException(status);
		}

		IContainer container = (IContainer) resource;


		try {
			final IFile file = container.getFile(new Path("Makefile.am"));
			
			InputStream oldContents = file.getContents();
			
			BufferedReader reader = new BufferedReader(new InputStreamReader(oldContents));
			
			StringBuffer fileData = getStringBufferFromReader(reader);

			reader.close();
			
			final String searchPattern, replacementPattern;
			
			if (idl) {
				searchPattern = "core3_IDLS =";
				replacementPattern = "core3_IDLS =\t" + filePath + "/" + className + ".cpp \\\\\n\t\t\t";
			} else {
				searchPattern = "core3_IDLS\\) \\\\";
				replacementPattern = "core3_IDLS\\) \\\\\n\t\t" + filePath + "/" + className + ".cpp \\\\";
				
				registerImplementation = false;
			}
						
			StringBuffer sb = replaceText(fileData.toString(), searchPattern, replacementPattern, true);
			
			if (registerImplementation) {
				sb = replaceText(sb.toString(), "core3_IDLS\\) \\\\", "core3_IDLS\\) \\\\\n\t\t" + filePath + "/" + className + "Implementation.cpp \\\\", true);
			}
			
			oldContents.close();
			
			InputStream writeStream = new ByteArrayInputStream(sb.toString().getBytes());
			
			file.setContents(writeStream, true, true, monitor);
			
			writeStream.close();

		} catch (FileNotFoundException ex) {
			return;
		} catch (IOException ex) {
			return;
		}

		monitor.worked(1);
	}
	
	static public InputStream generateManagedObject(final String className, final String superClassName, final String packageName, String[] interfaces, String[] imports, String[] members, String[] ctorParameters, String ctorContents) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		String contents = store.getString(PreferenceConstants.P_LICENSE) + "\n" +
		"package " + packageName + ";\n" +
		"import engine.core.ManagedObject;\n";

		if (imports != null) {
			for (int i = 0; i < imports.length; i++) {
				contents += "import ";
				contents += imports[i];
				contents += ";\n";
			}
		}
		
		contents += "\n";
		contents += "\n";
		contents += ("class " + className + " extends " + superClassName + " ");

		if (interfaces != null && interfaces.length > 0) {
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
		
		if (members != null)
			contents += generateMembers(members);
		
		contents += generateConstructor(className, ctorParameters, ctorContents);
		
		contents += "}\n";

		return new ByteArrayInputStream(contents.getBytes());
	}
	
	static public String generateMembers(String[] members) {
		String returnString = new String();
		
		for (int i = 0; i < members.length; i++) {
			returnString += ("\tprotected " + members[i] + " " + members[i].substring(0, 1).toLowerCase() + members[i].substring(1) + ";\n");
		}
		
		returnString += "\n";
		
		return returnString;
	}

	static public String generateConstructor(String className, String[] ctorParameters, String ctorContents) {
		String returnString = "\n\tpublic " + className + "(";
		
		if (ctorParameters != null && ctorParameters.length > 0) {
			for (int i = 0; i < ctorParameters.length; i++) {
				returnString += ctorParameters[i] + " " + ctorParameters[i].substring(0, 1).toLowerCase() + ctorParameters[i].substring(1);
				
				if (i + 1 < ctorParameters.length)
					returnString += ", ";
			}
		}
		
		returnString += ") {" + "\n";
		
		if (ctorContents != null) {
			ctorContents = "\t\t" + ctorContents.replaceAll("\n", "\n\t\t");
			
			returnString += ctorContents;
			
			returnString += "\n";
		}
		
		returnString += "\t}\n";

		return returnString;
	}
	
	static public InputStream generateSource(final String className) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		String contents = store.getString(PreferenceConstants.P_LICENSE) + "\n";
		contents += ("#include \"" + className + ".h\"\n");
		
		contents += "\n";
		
		contents += (className + "::" + className + "() {\n");
		contents += ("}\n");
		
		contents += "\n";
		
		contents += (className + "::~" + className + "() {\n");
		contents += ("}\n");
		
		contents += "\n";
		
		return new ByteArrayInputStream(contents.getBytes());
	}
	
	static public InputStream generateHeader(final String className, final String superClass, final String packageName) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		String contents = store.getString(PreferenceConstants.P_LICENSE) + "\n";
		contents += "#include \"engine/engine.h\"\n";
		contents += "\n";
		
		int namespaces = 0;
		
		if (packageName != null && packageName.length() > 0) {
			StringTokenizer tokenizer = new StringTokenizer(packageName, ".");
			
			while (tokenizer.hasMoreTokens()) {
				String parsedToken = tokenizer.nextToken();
				
				contents += ("namespace " + parsedToken + " {\n");
				
				namespaces++;
			}
			
			contents += "\n\n";
		}
		
		contents += ("class " + className + " : public Singleton<" + className + ">");
		
		if (superClass.length() > 0)
			contents += (", public " + superClass);
		
		contents += " {\n";
	
		contents += "public:\n";
		contents += ("\t" + className + "();\n");
		contents += ("\t~" + className + "();\n");
		
		contents += "};\n\n";
		
		for (int i = 0; i < namespaces; i++) {
			contents += "}\n";
		}

		return new ByteArrayInputStream(contents.getBytes());
	}
	
	static public InputStream generateImplementation(final String className) {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();

		String contents = store.getString(PreferenceConstants.P_LICENSE) + "\n" + "#include \"" + className + ".h\"\n";

		return new ByteArrayInputStream(contents.getBytes());
	}
	
	/*static public String generateHelperMethds() {
	String data = "\n\t\t\t public initializeTransientMembers() {\n" +
					"\t\t\t\t super.initializeTransientMembers();\n" +
					"\t\t\t\t}\n" +
					"\t\t\t public initializeTransientMembers() {\n"


	return data;
}*/




}
