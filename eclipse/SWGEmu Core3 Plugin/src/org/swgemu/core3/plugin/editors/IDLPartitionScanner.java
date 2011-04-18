package org.swgemu.core3.plugin.editors;

import org.eclipse.jface.text.rules.*;

public class IDLPartitionScanner extends RuleBasedPartitionScanner {
	public final static String IDL_COMMENT = "__idl_comment";
	public final static String IDL_DOC = "__idl_doc";
	//public final static String XML_TAG = "__xml_tag";

	public IDLPartitionScanner() {

		IToken idlComment = new Token(IDL_COMMENT);
		//IToken tag = new Token(XML_TAG);
		IToken idlDoc = new Token(IDL_DOC);

		IPredicateRule[] rules = new IPredicateRule[3];

		rules[0] = new MultiLineRule("/**", "*/", idlDoc);
		rules[1] = new MultiLineRule("/*", "*/", idlComment);
		//rules[2] = new TagRule(tag);
		rules[2] = new EndOfLineRule("//", idlComment);
		
		setPredicateRules(rules);
	}
}
