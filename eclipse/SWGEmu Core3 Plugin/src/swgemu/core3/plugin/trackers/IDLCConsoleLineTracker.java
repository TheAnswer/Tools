package swgemu.core3.plugin.trackers;

import java.io.File;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IMarker;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.Path;
import org.eclipse.debug.ui.console.IConsole;
import org.eclipse.debug.ui.console.IConsoleLineTrackerExtension;
import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.IRegion;
import org.eclipse.ui.externaltools.internal.model.IExternalToolConstants;
import org.eclipse.ui.editors.text.TextFileDocumentProvider;
import org.eclipse.ui.texteditor.IDocumentProvider;
import swgemu.core3.plugin.shared.Core3Shared;

@SuppressWarnings("restriction")
public class IDLCConsoleLineTracker implements IConsoleLineTrackerExtension {
	private IConsole console;

	public IDLCConsoleLineTracker() {
		super();
	}

	@Override
	public void dispose() {
		// TODO Auto-generated method stub

	}

	@Override
	public void init(IConsole arg0) {
		// TODO Auto-generated method stub
		console = arg0;
	}
	
	private IFile getWorkingFile(final String fileName, final String workingDirectory) 
	throws CoreException {
		
		if (Core3Shared.currentProjectResource == null)
			return null;
		
		IFile file = Core3Shared.currentProjectResource.getFile(new Path("src" + File.separatorChar + fileName));
		
		return file;
		
		/*
		IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
		String fullString = workingDirectory + File.separatorChar + "src" + File.separatorChar + fileName;
		//fullString.substring(beginIndex)
		IResource resource = root.findMember(new Path(fullString));

		if (!resource.exists() || !(resource instanceof IFile)) {
			IStatus status =
				new Status(IStatus.ERROR, "SWGEmu_Core3_ManagedObject_Plugin", IStatus.OK, "Container \"" + workingDirectory + "\" does not exist.", null);

			throw new CoreException(status);
		}

		IFile fileResource = (IFile) resource;
		
		return fileResource;*/
	}

	@Override
	public void lineAppended(IRegion line) {
		
		IDocument doc = console.getDocument();

		try {
			final String lineText = doc.get(line.getOffset(), line.getLength());

			Pattern p = Pattern.compile("\\(.+\\)");

			Matcher m = p.matcher(lineText);

			boolean b = m.find();
			
			if (b) {
				@SuppressWarnings("deprecation")
				String workingDirectory = console.getProcess().getLaunch().getLaunchConfiguration().getAttribute(IExternalToolConstants.ATTR_WORKING_DIRECTORY, "notFound");
				workingDirectory = workingDirectory.substring(workingDirectory.lastIndexOf(File.separatorChar) + 1);
				
				int serverIdx = lineText.indexOf("server");
				
				if (serverIdx >= 0) {
					String fileName = lineText.substring(serverIdx, lineText.indexOf("("));

					IFile fileResource = getWorkingFile(fileName, workingDirectory);
					
					if (fileResource == null)
						return;

					String lineNumber1 = m.group();
					lineNumber1 = lineNumber1.substring(1, lineNumber1.length() - 1);
					
					int lineInt = Integer.parseInt(lineNumber1);

				    IDocumentProvider provider = new TextFileDocumentProvider(); 

				    provider.connect(fileResource); 
				    
				    IDocument document = provider.getDocument(fileResource);
				    
				    if (document != null)  { 
				    	int lineStart = document.getLineOffset(lineInt - 1);
				    	int lineEnd = lineStart;
				    	
				    	if (lineInt < document.getNumberOfLines() + 1)
				    		lineEnd = document.getLineOffset(lineInt);
				    	
				    	IMarker marker = fileResource.createMarker(IMarker.PROBLEM);
						marker.setAttribute(IMarker.MESSAGE, lineText.substring(lineText.indexOf(")") + 1));
						marker.setAttribute(IMarker.LINE_NUMBER, lineInt);
						marker.setAttribute(IMarker.SEVERITY, IMarker.SEVERITY_ERROR);
				    	marker.setAttribute(IMarker.CHAR_START, lineStart);
						marker.setAttribute(IMarker.CHAR_END, lineEnd);
				    }
				    
				    provider.disconnect(fileResource);
				    
				    IContainer parent = fileResource.getParent();
				    
				    if (parent != null)
				    	parent.refreshLocal(IContainer.DEPTH_ONE, null);
				    
				}
			} else {
				int idx = lineText.indexOf(".idl");
				
				if (idx >= 0) {
					@SuppressWarnings("deprecation")
					String workingDirectory = console.getProcess().getLaunch().getLaunchConfiguration().getAttribute(IExternalToolConstants.ATTR_WORKING_DIRECTORY, "notFound");
					workingDirectory = workingDirectory.substring(workingDirectory.lastIndexOf(File.separatorChar) + 1);

					int serverIdx = lineText.indexOf("server");

					if (serverIdx > 0) {
						String fileName = lineText.substring(serverIdx, idx + 4);

						IFile fileResource = getWorkingFile(fileName, workingDirectory);

						if (fileResource != null) {
							fileResource.deleteMarkers(null, true, IResource.DEPTH_ONE);
							
							IContainer parent = fileResource.getParent();
						    
						    if (parent != null)
						    	parent.refreshLocal(IContainer.DEPTH_ONE, null);
						}
					}
				}
			}


		} catch (org.eclipse.jface.text.BadLocationException e) {
			// TODO Auto-generated catch block
		} catch (CoreException e) {
			// TODO Auto-generated catch block
		}
		

	}

	@Override
	public void consoleClosed() {
		// TODO Auto-generated method stub

		

	}

}
