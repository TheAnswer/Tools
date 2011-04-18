package org.swgemu.core3.plugin.editors;

import java.awt.Font;

import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.ITextDoubleClickStrategy;
import org.eclipse.jface.text.TextAttribute;
import org.eclipse.jface.text.contentassist.ContentAssistant;
import org.eclipse.jface.text.contentassist.IContentAssistProcessor;
import org.eclipse.jface.text.contentassist.IContentAssistant;
import org.eclipse.jface.text.presentation.IPresentationReconciler;
import org.eclipse.jface.text.presentation.PresentationReconciler;
import org.eclipse.jface.text.rules.DefaultDamagerRepairer;
import org.eclipse.jface.text.rules.Token;
import org.eclipse.jface.text.source.ISourceViewer;
import org.eclipse.jface.text.source.SourceViewerConfiguration;

import org.swgemu.core3.plugin.editors.ColorManager;
import org.swgemu.core3.plugin.editors.IDLColorConstants;
import org.swgemu.core3.plugin.editors.IDLDoubleClickStrategy;
import org.swgemu.core3.plugin.editors.IDLPartitionScanner;
import org.swgemu.core3.plugin.editors.NonRuleBasedDamagerRepairer;

public class IDLConfiguration extends SourceViewerConfiguration {
	private IDLDoubleClickStrategy doubleClickStrategy;
	private ColorManager colorManager;
	private IDLCodeScanner codeScanner;
	private IDLCompletionProcessor completionProcessor;
	private IDLEditor editor;

	public IDLConfiguration(ColorManager colorManager, IDLEditor editor) {
		this.colorManager = colorManager;
		this.editor = editor;
	}
	
	public String[] getConfiguredContentTypes(ISourceViewer sourceViewer) {
		return new String[] {
				IDocument.DEFAULT_CONTENT_TYPE,
				IDLPartitionScanner.IDL_COMMENT,
				IDLPartitionScanner.IDL_DOC
				};
	}
	
	public ITextDoubleClickStrategy getDoubleClickStrategy(
			ISourceViewer sourceViewer,
			String contentType) {
		if (doubleClickStrategy == null)
			doubleClickStrategy = new IDLDoubleClickStrategy();
		
		return doubleClickStrategy;
	}
	
	public IDLCompletionProcessor getIDLCompletionProcessor() {
		if (completionProcessor == null)
			completionProcessor = new IDLCompletionProcessor(editor);
		
		return completionProcessor;
	}
	
	public IContentAssistant getContentAssistant(ISourceViewer sv) {
        ContentAssistant ca = new ContentAssistant();
        IContentAssistProcessor cap = getIDLCompletionProcessor();
        
        ca.setContentAssistProcessor(cap, IDocument.DEFAULT_CONTENT_TYPE);
        ca.setInformationControlCreator(getInformationControlCreator(sv));
        
        return ca;
     }
	
	protected IDLCodeScanner getIDLCodeScanner() {
		if (codeScanner == null) {
			codeScanner = new IDLCodeScanner(colorManager);
			codeScanner.setDefaultReturnToken(new Token(new TextAttribute(colorManager.getColor(IDLColorConstants.DEFAULT))));
		}
		
		return codeScanner;
	}
	
	public IPresentationReconciler getPresentationReconciler(ISourceViewer sourceViewer) {
		PresentationReconciler reconciler = new PresentationReconciler();

		DefaultDamagerRepairer dr = new DefaultDamagerRepairer(getIDLCodeScanner());
		reconciler.setDamager(dr, IDocument.DEFAULT_CONTENT_TYPE);
		reconciler.setRepairer(dr, IDocument.DEFAULT_CONTENT_TYPE);
		
		NonRuleBasedDamagerRepairer ndr2 = new NonRuleBasedDamagerRepairer(new TextAttribute(colorManager.getColor(IDLColorConstants.IDL_DOC)));
		
		reconciler.setDamager(ndr2, IDLPartitionScanner.IDL_DOC);
		reconciler.setRepairer(ndr2, IDLPartitionScanner.IDL_DOC);

		NonRuleBasedDamagerRepairer ndr = new NonRuleBasedDamagerRepairer(new TextAttribute(colorManager.getColor(IDLColorConstants.IDL_COMMENT)));
		reconciler.setDamager(ndr, IDLPartitionScanner.IDL_COMMENT);
		reconciler.setRepairer(ndr, IDLPartitionScanner.IDL_COMMENT);
		
		/*TextAttribute attr = new TextAttribute(colorManager.getColor(IDLColorConstants.KEYWORD),  null, Font.BOLD);
		
		NonRuleBasedDamagerRepairer ndr3 = new NonRuleBasedDamagerRepairer(attr);
		reconciler.setDamager(ndr3, IDLPartitionScanner.IDL_KEYWORD);
		reconciler.setRepairer(ndr3, IDLPartitionScanner.IDL_KEYWORD);*/

		return reconciler;
	}

}