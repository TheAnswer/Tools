#include "engine/debuggerEngine.h"
#include "inject.h"

HANDLE injectCode(HANDLE hRemoteProcess, INJECT& local);
DebuggerEngine* startEngine();
DWORD getClientAppearance(DebuggerEngine* engine);
DWORD getClientController(DebuggerEngine* engine);


int main(int argc, char* argv[]) {
	int x = -7640;

	if (argc > 1)
		x = atoi(argv[1]);

	DebuggerEngine* engine = startEngine();

	DWORD clientAppearance = getClientAppearance(engine);

	DWORD clientControllerPointer = getClientController(engine);

	DWORD messageQueueDataTransformPointer = engine->getMessageQueueDataTransformPointer();

	INJECT local;
	local.clientAppearanceAddress = clientAppearance;
	local.clientControllerPointer = clientControllerPointer;
	local.messageQueueDataTransformPointer = messageQueueDataTransformPointer;
	local.x = x;

	cout << "Injecting Code...\n";

	HANDLE hThread = injectCode(engine->getProcessHandle(), local);

	if (hThread != NULL) {
		cout << "Code Injected...\n";
		cout << "Dumping";

		while (WaitForSingleObject(hThread, 1000) == WAIT_TIMEOUT)
			cout << ".";

		//CloseHandle(hThread);

		cout << "\nLook for heights.bin in your swg folder\n";
	} else {
		cout << "Failed to inject code..\n";
	}

	engine->stop();

	cout << "Wating for engine to finish..\n";

	while (engine->isRunning())
		Sleep(500);

	delete engine;

	cout << "Shutting down.";
	return 0;
}


DebuggerEngine* startEngine() {
	DebuggerEngine* engine = new DebuggerEngine();

	engine->start();

	cout << "Loading Engine...\n";

	while (!engine->isWaitingForEvent())
		Sleep(500);

	cout << "Engine Started!\n";

	return engine;
}

DWORD getClientAppearance(DebuggerEngine* engine) {
	engine->addBreakpoint(0x00B5DF51); // @bool getHeight(Coordinates* coords, float* posZ);

	cout << "Getting ClientAppearance address";

	DWORD clientAppearance;

	while (!(clientAppearance = engine->getClientAppearancePointer())) {
		cout << ".";
		Sleep(100);
	}

	cout << "\nSuccesufully intercepted ClientAppearance address!\n";

	return clientAppearance;
}

DWORD getClientController(DebuggerEngine* engine) {
	DWORD clientControllerPointer;

	engine->addBreakpoint(0x006E5767);

	cout << "Getting clientControllerPointer && messageQueueDataTransformPointer\n";

	while (!(clientControllerPointer = engine->getClientControllerPointer())) {
		cout << ".";
		Sleep(100);
	}

	cout << "Address intercepted\n";

	return clientControllerPointer;
}

HANDLE injectCode(HANDLE hRemoteProcess, INJECT& local) {
	BYTE *code = (BYTE *)VirtualAllocEx(hRemoteProcess, 0, sizeof(INJECT) + 3072,
			   MEM_RESERVE|MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	INJECT *remote = (INJECT *)(code + 3072);

	HMODULE hKernel32 = GetModuleHandle("kernel32.dll");

	local.fnWaitForSingleObject =   (WAIT_PROC)GetProcAddress(hKernel32, "WaitForSingleObject");
	local.fnCloseHandle         =  (CLOSE_PROC)GetProcAddress(hKernel32, "CloseHandle");
	local.fnExitProcess         =   (EXIT_PROC)GetProcAddress(hKernel32, "ExitProcess");
	local.fnDeleteFile          = (DELETE_PROC)GetProcAddress(hKernel32, "DeleteFileA");
	local.fnCreateFile          = (CREATE_PROC)GetProcAddress(hKernel32, "CreateFileA");
	local.fnWriteFile           = (WRITE_PROC)GetProcAddress(hKernel32, "WriteFile");
	local.fnWinExec             = (EXEC_PROC)GetProcAddress(hKernel32, "WinExec");
	local.fnVirtualAlloc		=	(VIRTUALALLOC_PROC)GetProcAddress(hKernel32, "VirtualAlloc");
	local.fnVirtualFree			=	(VIRTUALFREE_PROC)GetProcAddress(hKernel32, "VirtualFree");
	local.fnSetEndOfFile		=	(SETENDOFFILE_PROC)GetProcAddress(hKernel32, "SetEndOfFile");
	local.fnSleep				=	(SLEEP_PROC)GetProcAddress(hKernel32, "Sleep");
	local.fnItoa				=	(ITOA_PROC)0x01335F2F;
	local.fnSprintf				=	(SPRINTF_PROC)0x0131EAE8;
	local.fnGetHeight			=	(GETHEIGHT_PROC)(code + 1024);
    local.fnTeleport			=	(TELEPORT_PROC)(code + 2048);

	memcpy(local.szFileName, "%d %d.bin", sizeof("%d %d.bin"));

	// Write in code to execute, and the remote structure
	WriteProcessMemory(hRemoteProcess, code, (const void*)&RemoteThread, 1024, 0);
	WriteProcessMemory(hRemoteProcess, code + 1024, (const void*)&GetHeight, 1024, 0);
	WriteProcessMemory(hRemoteProcess, code + 2048, (const void*)&Teleport, 1024, 0);
	WriteProcessMemory(hRemoteProcess, remote, &local, sizeof(local), 0);

	// Execute the code in remote process
	DWORD  dwThreadId = 0;
	HANDLE hThread = CreateRemoteThread(hRemoteProcess, NULL, 0, (REMOTETHREAD)code, remote, 0, &dwThreadId);

	return hThread;
}
