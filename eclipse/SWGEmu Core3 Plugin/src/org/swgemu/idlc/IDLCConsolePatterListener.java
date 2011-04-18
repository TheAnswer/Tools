package org.swgemu.idlc;

import org.eclipse.debug.ui.console.IConsole;
import org.eclipse.jface.text.IRegion;
import org.eclipse.ui.console.IPatternMatchListener;
import org.eclipse.ui.console.PatternMatchEvent;
import org.eclipse.ui.console.TextConsole;
import org.swgemu.core3.plugin.trackers.IDLCConsoleLineTracker;

public class IDLCConsolePatterListener implements IPatternMatchListener {

	final IDLCConsoleLineTracker tracker = new IDLCConsoleLineTracker();
	
	@Override
	public void matchFound(PatternMatchEvent arg0) {
		// TODO Auto-generated method stub
		
		//arg0.
		
		final int offset = arg0.getOffset();
		final int length = arg0.getLength(); 
		
		IRegion region = new IRegion() {
			
			@Override
			public int getOffset() {
				// TODO Auto-generated method stub
				return offset;
			}
			
			@Override
			public int getLength() {
				// TODO Auto-generated method stub
				return length;
			}
		};
		
		tracker.lineAppended(region);
		
	}
	
	@Override
	public void disconnect() {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public void connect(TextConsole arg0) {
		// TODO Auto-generated method stub
		tracker.init((IConsole) arg0);
	}
	
	@Override
	public String getPattern() {
		// TODO Auto-generated method stub
		//return Pattern.compile(".+\\n").;
		return ".+\\n";
	}
	
	@Override
	public String getLineQualifier() {
		// TODO Auto-generated method stub
		//return null;
		//return ".+\\n";
		return null;
	}
	
	@Override
	public int getCompilerFlags() {
		// TODO Auto-generated method stub
		return 0;
	}

}
