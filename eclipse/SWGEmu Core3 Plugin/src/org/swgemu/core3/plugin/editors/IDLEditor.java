package org.swgemu.core3.plugin.editors;

import org.eclipse.cdt.internal.ui.editor.CEditor;
import org.eclipse.ui.editors.text.TextEditor;
import org.sr.idlc.compiler.Compiler;

import org.swgemu.core3.plugin.editors.ColorManager;
import org.swgemu.core3.plugin.editors.IDLConfiguration;
import org.swgemu.core3.plugin.editors.IDLDocumentProvider;
//import org.eclipse.cdt.*;

public class IDLEditor extends TextEditor {

	private ColorManager colorManager;

	public IDLEditor() {
		super();
		
		colorManager = new ColorManager();
		setSourceViewerConfiguration(new IDLConfiguration(colorManager, this));
		setDocumentProvider(new IDLDocumentProvider());
	}
	
	public void dispose() {
		colorManager.dispose();
		
		super.dispose();
	}

}

