package org.swgemu.core3.plugin.editors;

import org.eclipse.jface.text.rules.IWordDetector;

public class KeyWordDetector implements IWordDetector {	
	
	
	public KeyWordDetector(/*String word*/) {
		//this.word = word;
	}

	@Override
	public boolean isWordPart(char character) {
        return Character.isJavaIdentifierPart(character);
		//return (Character.isLetter(character) && Character.isJavaIdentifierPart(character));
		//return false;
		
		//return word.contains(String.valueOf(character));
	}

	@Override
	public boolean isWordStart(char character) {		
		return Character.isJavaIdentifierStart(character);
		//return (Character.isLetter(character) && Character.isJavaIdentifierStart(character));
		//return false;
		
		//return word.charAt(0) == character;
	}

}
