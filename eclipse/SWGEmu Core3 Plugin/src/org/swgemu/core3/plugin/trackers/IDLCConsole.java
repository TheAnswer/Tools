package org.swgemu.core3.plugin.trackers;

import org.eclipse.debug.core.model.IProcess;
import org.eclipse.debug.core.model.IStreamMonitor;
import org.eclipse.debug.core.model.IStreamsProxy;
import org.eclipse.debug.ui.console.IConsole;
import org.eclipse.debug.ui.console.IConsoleHyperlink;
import org.eclipse.jface.text.IRegion;
import org.eclipse.ui.console.IHyperlink;
import org.eclipse.ui.console.IOConsoleOutputStream;
import org.eclipse.ui.console.MessageConsole;

public class IDLCConsole extends MessageConsole implements IConsole {
	
	public IDLCConsole() {
		super("idlc", null);
	}

	@Override
	public void addLink(IConsoleHyperlink arg0, int arg1, int arg2) {
		// TODO Auto-generated method stub

	}

	@Override
	public void addLink(IHyperlink arg0, int arg1, int arg2) {
		// TODO Auto-generated method stub

	}

	@Override
	public void connect(IStreamsProxy arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void connect(IStreamMonitor arg0, String arg1) {
		// TODO Auto-generated method stub

	}

	@Override
	public IProcess getProcess() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public IRegion getRegion(IConsoleHyperlink arg0) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public IOConsoleOutputStream getStream(String arg0) {
		// TODO Auto-generated method stub
		return null;
	}

}
