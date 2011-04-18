package org.swgemu.core3.plugin.editors;

import java.awt.Font;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.jface.text.*;
import org.eclipse.jface.text.rules.*;

import org.swgemu.core3.plugin.editors.KeyWordDetector;


public class IDLCodeScanner extends RuleBasedScanner {
	public static String[] keywords = { "include", "abstract", "break", "case", "catch", "class", "continue", "default", "do", "else", "extends", "final", "finally", "for", "if", "implements", "import", "instanceof", "interface", "native", "new", "package", "private", "protected", "public", "return", "static", "super", "switch", "synchronized", "this", "throw", "throws", "transient", "try", "volatile", "while" }; 

	public static String[] types = { "void", "boolean", "char", "byte", "short", "int", "long", "float", "double", "unicode", "string", "unsigned" }; 

	public static String[] constants = { "false", "null", "true" }; //$NON-NLS-3$ //$NON-NLS-2$ //$NON-NLS-1$
	
	/**
	 * Creates a Java code scanner with the given color provider.
	 *
	 * @param provider the color provider
	 */
	public IDLCodeScanner(ColorManager provider) {

		IToken keyword = new Token(new TextAttribute(provider.getColor(IDLColorConstants.KEYWORD), null, Font.BOLD));
		IToken type = new Token(new TextAttribute(provider.getColor(IDLColorConstants.TYPE), null, Font.BOLD));
		IToken string = new Token(new TextAttribute(provider.getColor(IDLColorConstants.STRING)));
		//IToken comment= new Token(new TextAttribute(provider.getColor(IDLColorConstants.SINGLE_LINE_COMMENT)));
		IToken other = new Token(new TextAttribute(provider.getColor(IDLColorConstants.DEFAULT)));
		IToken annotation = new Token(new TextAttribute(provider.getColor(IDLColorConstants.ANNOTATION)));

		List<IRule> rules = new ArrayList<IRule>();
		
		rules.add(new WhitespaceRule(new IDLWhitespaceDetector()));

		// Add rule for strings and character constants.		
		rules.add(new SingleLineRule("\"", "\"", string, '\\')); //$NON-NLS-2$ //$NON-NLS-1$
		rules.add(new SingleLineRule("'", "'", string, '\\')); //$NON-NLS-2$ //$NON-NLS-1$

		// Add generic whitespace rule.
				
        CombinedWordRule combinedWordRule = new CombinedWordRule(new KeyWordDetector(), other);
		
        CombinedWordRule.WordMatcher wordRule = new CombinedWordRule.WordMatcher();
		
		for (int i= 0; i < keywords.length; i++)
			wordRule.addWord(keywords[i], keyword);
		
		for (int i= 0; i < types.length; i++)
			wordRule.addWord(types[i], type);
		
		for (int i= 0; i < constants.length; i++)
			wordRule.addWord(constants[i], type);
		
		combinedWordRule.addWordMatcher(wordRule);
		
		rules.add(combinedWordRule);
		
		//annotation		
		rules.add(new WordPatternRule(new KeyWordDetector(), "@", "", annotation));

		IRule[] result= new IRule[rules.size()];
		rules.toArray(result);
		setRules(result);
	}
}
