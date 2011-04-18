package org.swgemu.idlc;

import java.io.PrintStream;

import org.sr.idlc.compiler.Compiler;
import org.sr.idlc.compiler.symtab.SymbolTree;

public class IDLCInstance {
	public final org.sr.idlc.compiler.Compiler idlc = new Compiler();
	
	public void setPrintStream(PrintStream stream) {
		org.sr.djcc.engine.compiler.Compiler.out = stream;
	}
	
	public void clearPrintStream() {
		org.sr.djcc.engine.compiler.Compiler.out = System.out;
	}
	
	public synchronized void run(String[] args) throws Exception {
		//org.sr.idlc.compiler.symtab.SymbolTree.clearInstance();
		
		if (idlc.initialize(args))
			idlc.run();
	}
	
	public static SymbolTree getSymbolTree() {
		return org.sr.idlc.compiler.symtab.SymbolTree.getInstance();
	}
	
}
