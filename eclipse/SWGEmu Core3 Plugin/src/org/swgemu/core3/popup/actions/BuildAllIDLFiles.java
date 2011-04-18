/**
 * 
 */
package org.swgemu.core3.popup.actions;

import java.io.File;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.core.runtime.jobs.Job;
import org.eclipse.jface.action.IAction;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IObjectActionDelegate;
import org.eclipse.ui.IWorkbenchPart;

import org.swgemu.core3.plugin.shared.Core3Shared;

/**
 * @author victor
 *
 */
public class BuildAllIDLFiles implements IObjectActionDelegate {

	private Shell shell;
	private ISelection selection;

	/**
	 * @see org.eclipse.ui.IActionDelegate#run(org.eclipse.jface.action.IAction)
	 */
	@Override
	public void run(IAction action) {
		try {
			String fullPath = new String();
			String workingDirectory = new String();

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

					workingDirectory = selectedResource.getProject().getLocation().toOSString();

					IContainer container = selectedResource.getParent();

					String idlcData[] = Core3Shared.getIDLCData(selectedResource.getProject());

					fullPath += (container.getFullPath() + String.valueOf(File.separatorChar));
					fullPath += selectedResource.getName();

					selectedResource.deleteMarkers(null, true, IResource.DEPTH_ONE);
					
					Core3Shared.currentProjectResource = selectedResource.getProject();
					
					final String idlcPath = idlcData[0];
					final String idlcClasspath = idlcData[1];
					final String path = fullPath;
					final String dir = workingDirectory;
					
					Job idlcJob = new Job("idlc") {
						public IStatus run(IProgressMonitor mon) {
							try {
								Core3Shared.runIDLC(idlcPath, idlcClasspath, path, dir, true);
							} catch (CoreException e) {
							}
							
							IStatus tStatus = new Status(IStatus.OK, "SWGEmu core3", 0, "idlc rebuild all idl job finished", null);
							
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
	 * @see org.eclipse.ui.IActionDelegate#selectionChanged(org.eclipse.jface.action.IAction, org.eclipse.jface.viewers.ISelection)
	 */
	@Override
	public void selectionChanged(IAction action, ISelection selection) {
		this.selection = selection;
	}

	/**
	 * @see org.eclipse.ui.IObjectActionDelegate#setActivePart(org.eclipse.jface.action.IAction, org.eclipse.ui.IWorkbenchPart)
	 */
	@Override
	public void setActivePart(IAction action, IWorkbenchPart targetPart) {
		shell = targetPart.getSite().getShell();
	}

}
