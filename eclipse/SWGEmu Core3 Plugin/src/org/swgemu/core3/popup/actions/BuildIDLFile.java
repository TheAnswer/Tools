package org.swgemu.core3.popup.actions;


import java.io.File;

import org.eclipse.jface.action.IAction;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IObjectActionDelegate;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.IContainer;
import org.eclipse.core.runtime.*;
import org.eclipse.core.runtime.jobs.Job;

import org.swgemu.core3.plugin.shared.Core3Shared;

public class BuildIDLFile implements IObjectActionDelegate {

	private Shell shell;
	private ISelection selection;

	/**
	 * Constructor for Action1.
	 */
	public BuildIDLFile() {
		super();
	}

	/**
	 * @see IObjectActionDelegate#setActivePart(IAction, IWorkbenchPart)
	 */
	public void setActivePart(IAction action, IWorkbenchPart targetPart) {
		shell = targetPart.getSite().getShell();
	}

	/**
	 * @see IActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		try {
			String fullPath = new String();
			/*final String workingDirectory = new String();*/

			if (selection != null && !selection.isEmpty()
					&& selection instanceof IStructuredSelection) {				

				IStructuredSelection ssel = (IStructuredSelection) selection;

				if (ssel.size() > 1)
					return;

				Object obj = ssel.getFirstElement();

				if (obj instanceof IResource) {

					IResource selectedResource = (IResource) obj;

					if (selectedResource.getParent() == null)
						return;

					final String workingDirectory = selectedResource.getProject().getLocation().toOSString();

					IContainer container = selectedResource.getParent();

					String idlcData[] = Core3Shared.getIDLCData(selectedResource.getProject());

					fullPath += (container.getFullPath() + String.valueOf(File.separatorChar));
					fullPath += selectedResource.getName();
					
					selectedResource.deleteMarkers(null, true, IResource.DEPTH_ONE);
					
					Core3Shared.currentProjectResource = selectedResource.getProject();
					
					final String idlcPath = idlcData[0];
					final String idlcClasspath = idlcData[1];
					final String path = fullPath;
					
					Job idlcJob = new Job("idlc") {
						public IStatus run(IProgressMonitor mon) {
							try {
								Core3Shared.runIDLC(idlcPath, idlcClasspath, path, workingDirectory, false);
							} catch (CoreException e) {
							}
							
							Status tStatus = new Status(IStatus.OK, "SWGEmu core3", 0, "idlc build idl job finished", null);
							
							return tStatus;
						}
					};
					
					idlcJob.schedule();
	
				}
			}

		
		} catch (CoreException e) {
			MessageDialog.openWarning(shell, "SWGEmu Core3 Plugin", "Could not locate/execute idlc");
		}

	}

	/**
	 * @see IActionDelegate#selectionChanged(IAction, ISelection)
	 */
	public void selectionChanged(IAction action, ISelection selection) {
		this.selection = selection;
	}

}
