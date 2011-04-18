package org.swgemu.core3.plugin.editors;

//import org.eclipse.jface.text.IDocument;
import org.eclipse.jface.text.IRegion;
import org.eclipse.jface.text.ITextHover;
import org.eclipse.jface.text.ITextViewer;
import org.eclipse.jface.text.Region;

public class TextHover implements ITextHover {

	public IRegion getHoverRegion(ITextViewer tv, int off) {
		return new Region(off, 0);
	}
	
	public String getHoverInfo(ITextViewer tv, IRegion r) {
	/*	try {
			IDocument doc = tv.getDocument();
			EscriptModel em = EscriptModel.getModel(doc, null);
			return em.getElementAt(r.getOffset()).
			getHoverHelp();
		}
		catch (Exception e) {            
			return ""; 
		}*/
		
		return "";
	}


}
