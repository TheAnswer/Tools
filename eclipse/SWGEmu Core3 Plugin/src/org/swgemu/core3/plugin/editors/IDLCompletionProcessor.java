/*******************************************************************************
 * Copyright (c) 2000, 2008 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.swgemu.core3.plugin.editors;


import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Vector;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.runtime.Platform;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.text.BadLocationException;
import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.ITextViewer;
import org.eclipse.jface.text.TextPresentation;
import org.eclipse.jface.text.contentassist.CompletionProposal;
import org.eclipse.jface.text.contentassist.ContextInformation;
import org.eclipse.jface.text.contentassist.ICompletionProposal;
import org.eclipse.jface.text.contentassist.IContentAssistProcessor;
import org.eclipse.jface.text.contentassist.IContextInformation;
import org.eclipse.jface.text.contentassist.IContextInformationPresenter;
import org.eclipse.jface.text.contentassist.IContextInformationValidator;
import org.eclipse.jface.viewers.StyledString;
import org.eclipse.swt.graphics.Image;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.internal.editors.text.EditorsPlugin;
import org.eclipse.ui.part.EditorActionBarContributor;
import org.eclipse.ui.part.FileEditorInput;
import org.sr.idlc.compiler.sym.MemberSym;
import org.sr.idlc.compiler.symtab.Symbol;
import org.sr.idlc.compiler.symtab.SymbolTree;
import org.swgemu.core3.plugin.editors.IDLEditorMessages;
import org.swgemu.idlc.IDLCInstance;
//import org.eclipse.jdt.ui.JavaElementLabelProvider;
//import org.eclipse.cdt.ui.;

import org.eclipse.cdt.internal.ui.viewsupport.CElementImageProvider;
import org.eclipse.cdt.ui.CUIPlugin;

/**
 * Example Java completion processor.
 */
public class IDLCompletionProcessor implements IContentAssistProcessor {

	private IDLEditor editor;
	private char[] fAutoCompletionCharacters = { '.' };

	public IDLCompletionProcessor(IDLEditor editor) {
		this.editor = editor;
	}

	/**
	 * Simple content assist tip closer. The tip is valid in a range
	 * of 5 characters around its popup location.
	 */
	protected static class Validator implements IContextInformationValidator, IContextInformationPresenter {

		protected int fInstallOffset;

		/*
		 * @see IContextInformationValidator#isContextInformationValid(int)
		 */
		public boolean isContextInformationValid(int offset) {
			return Math.abs(fInstallOffset - offset) < 5;
		}

		/*
		 * @see IContextInformationValidator#install(IContextInformation, ITextViewer, int)
		 */
		public void install(IContextInformation info, ITextViewer viewer, int offset) {
			fInstallOffset = offset;
		}

		/*
		 * @see org.eclipse.jface.text.contentassist.IContextInformationPresenter#updatePresentation(int, TextPresentation)
		 */
		public boolean updatePresentation(int documentPosition, TextPresentation presentation) {
			return false;
		}
	}

	protected final static String[] fgProposals=
	{ "abstract", "boolean", "break", "byte", "case", "catch", "char", "class", "continue", "default", "do", "double", "else", "extends", "false", "final", "finally", "float", "for", "if", "implements", "import", "instanceof", "int", "interface", "long", "native", "new", "null", "package", "private", "protected", "public", "return", "short", "static", "super", "switch", "synchronized", "this", "throw", "throws", "transient", "true", "try", "void", "volatile", "while" }; //$NON-NLS-48$ //$NON-NLS-47$ //$NON-NLS-46$ //$NON-NLS-45$ //$NON-NLS-44$ //$NON-NLS-43$ //$NON-NLS-42$ //$NON-NLS-41$ //$NON-NLS-40$ //$NON-NLS-39$ //$NON-NLS-38$ //$NON-NLS-37$ //$NON-NLS-36$ //$NON-NLS-35$ //$NON-NLS-34$ //$NON-NLS-33$ //$NON-NLS-32$ //$NON-NLS-31$ //$NON-NLS-30$ //$NON-NLS-29$ //$NON-NLS-28$ //$NON-NLS-27$ //$NON-NLS-26$ //$NON-NLS-25$ //$NON-NLS-24$ //$NON-NLS-23$ //$NON-NLS-22$ //$NON-NLS-21$ //$NON-NLS-20$ //$NON-NLS-19$ //$NON-NLS-18$ //$NON-NLS-17$ //$NON-NLS-16$ //$NON-NLS-15$ //$NON-NLS-14$ //$NON-NLS-13$ //$NON-NLS-12$ //$NON-NLS-11$ //$NON-NLS-10$ //$NON-NLS-9$ //$NON-NLS-8$ //$NON-NLS-7$ //$NON-NLS-6$ //$NON-NLS-5$ //$NON-NLS-4$ //$NON-NLS-3$ //$NON-NLS-2$ //$NON-NLS-1$

	protected IContextInformationValidator fValidator = new Validator();

	protected String getPrefix(IDocument doc, int offset) {
		String prefix = new String();
		char character;

		StringBuffer stringBuffer = new StringBuffer();

		try {
			while (offset > 0) {
				character = doc.getChar(--offset);

				if (!Character.isWhitespace(character)) {
					stringBuffer.insert(0, character);
				} else {
					prefix = stringBuffer.toString();
					return prefix;
				}

			}
		} catch (BadLocationException e) {
			e.printStackTrace();
		}

		return prefix;
	}

	private ICompletionProposal[] getClassProposals(String className, SymbolTree tree, int documentOffset) {
		Symbol classSymbol = tree.findClass(className);

		if (classSymbol == null)
			return null;

		List<Symbol> methods = tree.getMethods(classSymbol);
		List<Symbol> members = tree.getDescendants(classSymbol, Symbol.CLASSMEMBER);

		Iterator<Symbol> iter = methods.iterator();
		Iterator<Symbol> membersIterator = members.iterator();

		ICompletionProposal[] result = new ICompletionProposal[methods.size() + members.size()];
		int i = 0;

		ImageDescriptor imagedesc = CElementImageProvider.getFunctionImageDescriptor();
		Image image = imagedesc != null ? CUIPlugin.getImageDescriptorRegistry().get(imagedesc) : null;

		while (iter.hasNext()) {
			Symbol sym = iter.next();
			
			IContextInformation info = new ContextInformation(sym.getName(), sym.getName()); //$NON-NLS-1$
			result[i++] = new CompletionProposal(sym.getName(), documentOffset, 0, sym.getName().length(), image, sym.getName(), info, sym.getName()); //$NON-NLS-1$
		}

		imagedesc = CElementImageProvider.getVariableImageDescriptor();
		image = imagedesc != null ? CUIPlugin.getImageDescriptorRegistry().get(imagedesc) : null;

		while (membersIterator.hasNext()) {
			Symbol sym = membersIterator.next();

			IContextInformation info = new ContextInformation(sym.getName(), sym.getName()); //$NON-NLS-1$
			result[i++] = new CompletionProposal(sym.getName(), documentOffset, 0, sym.getName().length(), image, sym.getName(), info, sym.getName()); //$NON-NLS-1$					
		}

		return result;
	}

	/* (non-Javadoc)
	 * Method declared on IContentAssistProcessor
	 */
	public ICompletionProposal[] computeCompletionProposals(ITextViewer viewer, int documentOffset) {

		//EditorsPlugin.getDefault().
		//PlatformUI.getWorkbench().getActiveWorkbenchWindow().getActivePage().getActiveEditor().

		IEditorInput input = editor.getEditorInput();
		String prefix = getPrefix(viewer.getDocument(), documentOffset);

		if (!(input instanceof FileEditorInput))
			return null;

		FileEditorInput fileInput = (FileEditorInput) input;
		IFile file = fileInput.getFile();

		String fileName = file.getName();
		String className = fileName.replace(".idl", "");

		SymbolTree tree = IDLCInstance.getSymbolTree();

		if (prefix.endsWith(".")) {
			String member = prefix.substring(0, prefix.indexOf("."));

			if (member.contentEquals("this")) {
				return getClassProposals(className, tree, documentOffset);
			} else {
				Symbol classSymbol = tree.findClass(className);

				if (classSymbol != null) {
					MemberSym sym = tree.findMember(classSymbol, member);

					if (sym != null) {
						return getClassProposals(sym.getTypeName(), tree, documentOffset);
					}

				}
			}
		} else {
			Symbol classSymbol = tree.findClass(className);
			
			if (classSymbol != null) {
				List<Symbol> members = tree.getDescendants(classSymbol, Symbol.CLASSMEMBER);
				
				//members.
				
				if (members.size() != 0) {
					Iterator<Symbol> membersIterator = members.iterator();
										
					Vector<Symbol> contained = new Vector<Symbol>();
					
					while (membersIterator.hasNext()) {
						Symbol sym = membersIterator.next();
						
						if (sym.getName().contains(prefix)) {
							contained.add(sym);
						}																	
					}
					
					if (contained.size() != 0) {
						ICompletionProposal[] result = new ICompletionProposal[contained.size()];

						ImageDescriptor imagedesc = CElementImageProvider.getFunctionImageDescriptor();
						Image image = imagedesc != null ? CUIPlugin.getImageDescriptorRegistry().get(imagedesc) : null;
						
						for (int i = 0; i < contained.size(); ++i) {
							Symbol sym = contained.get(i);
							
							IContextInformation info = new ContextInformation(sym.getName(), sym.getName()); //$NON-NLS-1$
							result[i++] = new CompletionProposal(sym.getName(), documentOffset - prefix.length(), prefix.length(), sym.getName().length(), image, sym.getName(), info, sym.getName()); //$NON-NLS-1$
						}

						return result;
					}

				}

			}			
		}

		return null;

	}

	/* (non-Javadoc)
	 * Method declared on IContentAssistProcessor
	 */
	public IContextInformation[] computeContextInformation(ITextViewer viewer, int documentOffset) {
		IContextInformation[] result= new IContextInformation[5];

		for (int i= 0; i < result.length; i++)
			result[i]= new ContextInformation(
					MessageFormat.format(IDLEditorMessages.getString("CompletionProcessor.ContextInfo.display.pattern"), new Object[] { new Integer(i), new Integer(documentOffset) }),  //$NON-NLS-1$
					MessageFormat.format(IDLEditorMessages.getString("CompletionProcessor.ContextInfo.value.pattern"), new Object[] { new Integer(i), new Integer(documentOffset - 5), new Integer(documentOffset + 5)})); //$NON-NLS-1$

		return result;
	}

	/* (non-Javadoc)
	 * Method declared on IContentAssistProcessor
	 */
	public char[] getCompletionProposalAutoActivationCharacters() {
		//return new char[] { '.' };
		return fAutoCompletionCharacters;
	}

	/* (non-Javadoc)
	 * Method declared on IContentAssistProcessor
	 */
	public char[] getContextInformationAutoActivationCharacters() {
		//return new char[] { '#' };
		return null;
	}

	/* (non-Javadoc)
	 * Method declared on IContentAssistProcessor
	 */
	public IContextInformationValidator getContextInformationValidator() {
		return fValidator;
	}

	/* (non-Javadoc)
	 * Method declared on IContentAssistProcessor
	 */
	public String getErrorMessage() {
		return null;
	}
}