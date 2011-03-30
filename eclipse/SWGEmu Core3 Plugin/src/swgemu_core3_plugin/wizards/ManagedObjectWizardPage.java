package swgemu_core3_plugin.wizards;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.Path;
import org.eclipse.jface.dialogs.InputDialog;
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
import org.eclipse.swt.widgets.List;
import org.eclipse.jface.viewers.ListViewer;

/**
 * The "New" wizard page allows setting the container for the new file as well
 * as the file name. The page will only accept file name without the extension
 * OR with the extension that matches the expected one (idl).
 */

public class ManagedObjectWizardPage extends WizardPage {
	private Text containerText;

	private Text classNameText;

	private ISelection selection;
	private Label lblpath;
	private Text superClassText;
	private Text packageNameText;
	private GridData gd_classNameText;
	private Button buttonCreateImpl;
	private List list;
	private Button btnUpdateMakefileam;

	/**
	 * Constructor for SampleNewWizardPage.
	 * 
	 * @param pageName
	 */
	public ManagedObjectWizardPage(ISelection selection) {
		super("wizardPage");
		setTitle("ManagedObject Class");
		setDescription("This wizard creates a new file with *.idl extension that can be opened by a multi-page editor.");
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
		layout.verticalSpacing = 13;
		Label lblclass;
		lblpath = new Label(container, SWT.NULL);
		lblpath.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblpath.setText("&Path:");

		containerText = new Text(container, SWT.BORDER | SWT.SINGLE);
		containerText.setLayoutData(new GridData(GridData.FILL_HORIZONTAL));
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
		lblclass = new Label(container, SWT.NULL);
		lblclass.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblclass.setText("&Class:");
		
				classNameText = new Text(container, SWT.BORDER | SWT.SINGLE);
				gd_classNameText = new GridData(GridData.FILL_HORIZONTAL);
				classNameText.setLayoutData(gd_classNameText);
				classNameText.addModifyListener(new ModifyListener() {
					public void modifyText(ModifyEvent e) {
						dialogChanged();
					}
				});
		new Label(container, SWT.NONE);
		initialize();
		dialogChanged();
		setControl(container);
		
		Label lblsuperClass = new Label(container, SWT.NONE);
		lblsuperClass.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblsuperClass.setText("&Super Class:");
		
		superClassText = new Text(container, SWT.BORDER);
		superClassText.setText("ManagedObject");
		superClassText.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(container, SWT.NONE);
		
		Label lblpackage = new Label(container, SWT.NONE);
		lblpackage.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblpackage.setText("&Package:");
		
		packageNameText = new Text(container, SWT.BORDER);
		packageNameText.setText("server.path.to.object");
		packageNameText.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(container, SWT.NONE);
		
		Label lblinterfaces = new Label(container, SWT.NONE);
		lblinterfaces.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblinterfaces.setText("&Interfaces:");
		
		ListViewer listViewer = new ListViewer(container, SWT.BORDER | SWT.V_SCROLL);
		list = listViewer.getList();
		GridData gd_list = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
		gd_list.widthHint = 418;
		list.setLayoutData(gd_list);
		
		Button btnNewButton = new Button(container, SWT.NONE);
		GridData gd_btnNewButton = new GridData(SWT.LEFT, SWT.BOTTOM, false, false, 1, 1);
		gd_btnNewButton.widthHint = 67;
		btnNewButton.setLayoutData(gd_btnNewButton);
		btnNewButton.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				handleAddInterface();
			}
		});
		btnNewButton.setText("Add");
		new Label(container, SWT.NONE);
		
		buttonCreateImpl = new Button(container, SWT.CHECK);
		buttonCreateImpl.setText("Create Implementation.cpp");
		
		Button btnNewButton_1 = new Button(container, SWT.NONE);
		btnNewButton_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				removeInterface();
			}
		});
		btnNewButton_1.setText("Remove");
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
		classNameText.setText("NewClass");
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
	
	private void handleAddInterface() {
		InputDialog dialog = new InputDialog(getShell(), "Interfaces", "Enter an interface class", "", null);
		
		if (dialog.open() == InputDialog.OK) {
			String val = dialog.getValue();
			
			if (val.length() > 0)
				list.add(val);
		}
	}
	
	private void removeInterface() {
		int selected = list.getFocusIndex();
		
		if (selected != -1) {
			list.remove(selected);
		}
	}

	/**
	 * Ensures that both text fields are set.
	 */

	private void dialogChanged() {
		IResource container = ResourcesPlugin.getWorkspace().getRoot()
				.findMember(new Path(getContainerName()));
		String fileName = getClassName();

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
		int dotLoc = fileName.lastIndexOf('.');
		if (dotLoc != -1) {
			String ext = fileName.substring(dotLoc + 1);
			if (ext.equalsIgnoreCase("idl") == false) {
				updateStatus("File extension must be \"idl\"");
				return;
			}
		}
		updateStatus(null);
	}

	private void updateStatus(String message) {
		setErrorMessage(message);
		setPageComplete(message == null);
	}

	public String getContainerName() {
		return containerText.getText();
	}

	public String getClassName() {
		return classNameText.getText();
	}
	
	public String getPackageName() {
		return packageNameText.getText();
	}
	
	public String getSuperClassName() {
		return superClassText.getText();
	}
	
	public String[] getInterfaces() {
		return list.getItems();
	}
	
	public boolean createImplementationCpp() {
		return buttonCreateImpl.getSelection();
	}
	
	public boolean updateMakefile() {
		return btnUpdateMakefileam.getSelection();
	}
}