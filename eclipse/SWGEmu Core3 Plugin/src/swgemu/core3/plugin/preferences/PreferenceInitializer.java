package swgemu.core3.plugin.preferences;

import org.eclipse.core.runtime.preferences.AbstractPreferenceInitializer;
import org.eclipse.jface.preference.IPreferenceStore;

import swgemu.core3.plugin.Activator;

/**
 * Class used to initialize default preference values.
 */
public class PreferenceInitializer extends AbstractPreferenceInitializer {

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.eclipse.core.runtime.preferences.AbstractPreferenceInitializer#initializeDefaultPreferences()
	 */
	public void initializeDefaultPreferences() {
		IPreferenceStore store = Activator.getDefault().getPreferenceStore();
		store.setDefault(PreferenceConstants.P_PATH, "");
		store.setDefault(PreferenceConstants.P_LICENSE, "/*\n" +
				"Copyright (C) 2007 <SWGEmu>\n" +
				"This File is part of Core3.\n" +
				"This program is free software; you can redistribute\n" +
				"it and/or modify it under the terms of the GNU Lesser\n" +
				"General Public License as published by the Free Software\n" +
				"Foundation; either version 2 of the License,\n" +
				"or (at your option) any later version.\n" +
				"\n" +
				"This program is distributed in the hope that it will be useful,\n" +
				"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" +
				"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n" +
				"See the GNU Lesser General Public License for\n" +
				"more details.\n" +
				"\n" +
				"You should have received a copy of the GNU Lesser General\n" +
				"Public License along with this program; if not, write to\n" +
				"the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA\n" +
				"\n" +
				"Linking Engine3 statically or dynamically with other modules\n" +
				"is making a combined work based on Engine3.\n" +
				"Thus, the terms and conditions of the GNU Lesser General Public License\n" +
				"cover the whole combination.\n" +
				"\n" +
				"In addition, as a special exception, the copyright holders of Engine3\n" +
				"give you permission to combine Engine3 program with free software\n" +
				"programs or libraries that are released under the GNU LGPL and with\n" +
				"code included in the standard release of Core3 under the GNU LGPL\n" +
				"license (or modified versions of such code, with unchanged license).\n" +
				"You may copy and distribute such a system following the terms of the\n" +
				"GNU LGPL for Engine3 and the licenses of the other code concerned,\n" +
				"provided that you include the source code of that other code when\n" +
				"and as the GNU LGPL requires distribution of source code.\n" +
				"\n" +
				"Note that people who make modified versions of Engine3 are not obligated\n" +
				"to grant this special exception for their modified versions;\n" +
				"it is their choice whether to do so. The GNU Lesser General Public License\n" +
				"gives permission to release a modified version without this exception;\n" +
				"this exception also makes it possible to release a modified version\n" +
				"which carries forward this exception.\n" +
				"\n*/" +
				"\n" );
		/*store.setDefault(PreferenceConstants.P_BOOLEAN, true);
		store.setDefault(PreferenceConstants.P_CHOICE, "choice2");
		store.setDefault(PreferenceConstants.P_STRING, "Default value");*/
	}

}
