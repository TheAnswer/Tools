package org.swgemu.core3.plugin.wizards;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.Path;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.dialogs.ContainerSelectionDialog;

/**
 * The "New" wizard page allows setting the container for the new file as well
 * as the file name. The page will only accept file name without the extension
 * OR with the extension that matches the expected one (cpp).
 */

public class ManagerNewWizardPage extends WizardPage {
	private Text containerText;

	private Text fileText;

	private ISelection selection;
	private Label lblmanagerName;
	private Label lbldirectory;
	private Label lblSuperClass;
	private Text txtZonemanager;
	private Button btnSingleton;
	private Button btnManagedservice;
	private Button btnCreateInZoneprocessserver;
	private Button btnUpdateMakefileam;
	private Button btnCreateImplementationcpp;

	/**
	 * Constructor for SampleNewWizardPage.
	 * 
	 * @param pageName
	 */
	public ManagerNewWizardPage(ISelection selection) {
		super("wizardPage");
		setTitle("Manager");
		setDescription("This wizard creates a new Core3 Manager Class");
		this.selection = selection;
	}

	/**
	 * @see IDialogPage#createControl(Composite)
	 */
	public void createControl(Composite parent) {
		Composite container = new Composite(parent, SWT.NULL);
		GridLayout layout = new GridLayout();
		container.setLayout(layout);
		layout.numColumns = 3;
		layout.verticalSpacing = 9;
		lbldirectory = new Label(container, SWT.NULL);
		lbldirectory.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lbldirectory.setText("&Directory:");

		containerText = new Text(container, SWT.BORDER | SWT.SINGLE);
		GridData gd = new GridData(GridData.FILL_HORIZONTAL);
		containerText.setLayoutData(gd);
		containerText.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				dialogChanged();
			}
		});

		Button button = new Button(container, SWT.PUSH);
		button.setText("Browse...");
		button.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleBrowse();
			}
		});
		lblmanagerName = new Label(container, SWT.NULL);
		lblmanagerName.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblmanagerName.setText("&Manager name:");

		fileText = new Text(container, SWT.BORDER | SWT.SINGLE);
		gd = new GridData(GridData.FILL_HORIZONTAL);
		fileText.setLayoutData(gd);
		fileText.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				dialogChanged();
			}
		});
		initialize();
		dialogChanged();
		setControl(container);
		new Label(container, SWT.NONE);
		
		lblSuperClass = new Label(container, SWT.NONE);
		lblSuperClass.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblSuperClass.setText("Super Class");
		
		txtZonemanager = new Text(container, SWT.BORDER);
		txtZonemanager.setText("ZoneManager");
		txtZonemanager.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(container, SWT.NONE);
		new Label(container, SWT.NONE);
		
		btnSingleton = new Button(container, SWT.CHECK);
		btnSingleton.setText("Singleton");
		
		btnSingleton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleSingletonSelection();
			}
		});
		new Label(container, SWT.NONE);
		new Label(container, SWT.NONE);
		
		btnManagedservice = new Button(container, SWT.CHECK);
		btnManagedservice.setSelection(true);
		btnManagedservice.setText("ManagedService");
		btnManagedservice.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleServiceSelection();
			}
		});
		new Label(container, SWT.NONE);
		new Label(container, SWT.NONE);
		
		btnCreateImplementationcpp = new Button(container, SWT.CHECK);
		btnCreateImplementationcpp.setSelection(true);
		btnCreateImplementationcpp.setText("Create Implementation.cpp");
		new Label(container, SWT.NONE);
		new Label(container, SWT.NONE);
		
		btnCreateInZoneprocessserver = new Button(container, SWT.CHECK);
		btnCreateInZoneprocessserver.setSelection(true);
		btnCreateInZoneprocessserver.setText("Create in ZoneProcessServer");
		new Label(container, SWT.NONE);
		new Label(container, SWT.NONE);
		
		btnUpdateMakefileam = new Button(container, SWT.CHECK);
		btnUpdateMakefileam.setSelection(true);
		btnUpdateMakefileam.setText("Update Makefile.am");
		new Label(container, SWT.NONE);
	}

	/**
	 * Tests if the current workbench selection is a suitable container to use.
	 */

	private void initialize() {
		if (selection != null && selection.isEmpty() == false
				&& selection instanceof IStructuredSelection) {
			IStructuredSelection ssel = (IStructuredSelection) selection;
			if (ssel.size() > 1)
				return;
			Object obj = ssel.getFirstElement();
			if (obj instanceof IResource) {
				IContainer container;
				if (obj instanceof IContainer)
					container = (IContainer) obj;
				else
					container = ((IResource) obj).getParent();
				containerText.setText(container.getFullPath().toString());
			}
		}
		fileText.setText("NewZoneManager");
	}

	/**
	 * Uses the standard container selection dialog to choose the new value for
	 * the container field.
	 */

	private void handleBrowse() {
		ContainerSelectionDialog dialog = new ContainerSelectionDialog(
				getShell(), ResourcesPlugin.getWorkspace().getRoot(), false,
				"Select new file container");
		if (dialog.open() == ContainerSelectionDialog.OK) {
			Object[] result = dialog.getResult();
			if (result.length == 1) {
				containerText.setText(((Path) result[0]).toString());
			}
		}
	}

	/**
	 * Ensures that both text fields are set.
	 */

	private void dialogChanged() {
		IResource container = ResourcesPlugin.getWorkspace().getRoot()
				.findMember(new Path(getContainerName()));
		String fileName = getFileName();

		if (getContainerName().length() == 0) {
			updateStatus("File container must be specified");
			return;
		}
		if (container == null
				|| (container.getType() & (IResource.PROJECT | IResource.FOLDER)) == 0) {
			updateStatus("File container must exist");
			return;
		}
		if (!container.isAccessible()) {
			updateStatus("Project must be writable");
			return;
		}
		if (fileName.length() == 0) {
			updateStatus("File name must be specified");
			return;
		}
		if (fileName.replace('\\', '/').indexOf('/', 1) > 0) {
			updateStatus("File name must be valid");
			return;
		}
		
		if (!getContainerName().contains("src") || !getContainerName().contains("server")) {
			updateStatus("Invalid directory");
			return;
		}
		
		updateStatus(null);
	}
	
	private void handleSingletonSelection() {
		if (btnSingleton.getSelection()) {
			btnManagedservice.setSelection(false);
			btnCreateImplementationcpp.setSelection(false);
			txtZonemanager.setText("");
		} else {
			btnManagedservice.setSelection(true);
			txtZonemanager.setText("ZoneManager");
		}
	}
	
	private void handleServiceSelection() {
		if (btnManagedservice.getSelection()) {
			btnSingleton.setSelection(false);
			txtZonemanager.setText("ZoneManager");
		} else {
			btnSingleton.setSelection(true);
			btnCreateImplementationcpp.setSelection(false);
			txtZonemanager.setText("");
		}
	}

	private void updateStatus(String message) {
		setErrorMessage(message);
		setPageComplete(message == null);
	}

	public String getContainerName() {
		return containerText.getText();
	}
	
	public String getSuperClass() {
		return txtZonemanager.getText();
	}

	public String getFileName() {
		return fileText.getText();
	}
	
	public String getClassName() {
		return getFileName();
	}
	
	public boolean generateManagedService() {
		return btnManagedservice.getSelection();
	}
	
	public boolean generateImplementationCpp() {
		return btnCreateImplementationcpp.getSelection();
	}
	
	public boolean registerMakefile() {
		return btnUpdateMakefileam.getSelection();
	}
	
	public boolean createInZoneProcessor() {
		return btnCreateInZoneprocessserver.getSelection();
	}
}