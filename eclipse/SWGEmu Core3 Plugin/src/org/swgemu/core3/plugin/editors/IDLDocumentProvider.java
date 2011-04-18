package org.swgemu.core3.plugin.editors;

import org.eclipse.core.runtime.CoreException;
import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.IDocumentPartitioner;
import org.eclipse.jface.text.rules.FastPartitioner;
import org.eclipse.ui.editors.text.FileDocumentProvider;

import org.swgemu.core3.plugin.editors.IDLPartitionScanner;

public class IDLDocumentProvider extends FileDocumentProvider {

	protected IDocument createDocument(Object element) throws CoreException {
		IDocument document = super.createDocument(element);
		
		if (document != null) {
			IDocumentPartitioner partitioner =
				new FastPartitioner(
					new IDLPartitionScanner(),
					new String[] {
						IDLPartitionScanner.IDL_COMMENT,
						IDLPartitionScanner.IDL_DOC
						});
			
			partitioner.connect(document);
			
			document.setDocumentPartitioner(partitioner);
		}
		
		return document;
	}
}