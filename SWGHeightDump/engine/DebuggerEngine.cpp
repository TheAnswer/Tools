#include "DebuggerEngine.h"

DebuggerEngine::DebuggerEngine() : Mutex("Engine"), Thread() {
	processHandle 	= (HANDLE) INVALID_HANDLE_VALUE;
	threadHandle	= (HANDLE) INVALID_HANDLE_VALUE;

	engineInUse		= false;

	processSuspended = false;

	DebugSetProcessKillOnExit(false);

	debugProcessID = 0;
	
	waitingForEvent = false;
	
	doRun = true;
	
	running = false;
	
	clientAppearancePointer = 0;
	
	clientControllerPointer = 0;
	messageQueueDataTransformPointer = 0;
}

DebuggerEngine::~DebuggerEngine() {
	finish();
}

void DebuggerEngine::clearBreakpoints(bool doLock) {
	lock(doLock);

	Breakpoint* breakpoint;
	
	while ((breakpoint = breakpointList.begin()->second) != NULL)
		removeBreakpoint(breakpoint->getAddress(), false);
	
	unlock(doLock);
}

bool DebuggerEngine::init() {
	lock();

	unsigned long processID;

	printProcessList(false);

	cout << "\nEnter processID to attach:";
	cin >> processID;

	if (!attachToProcess(processID, false)) {
		cout << "\nUnable to attach to process!\n";
		unlock();
		
		return false;
	} else
		cout << "Succesufully attached to process!\n";
	
	running = true;
	
	unlock();
	
	return true;
}

void DebuggerEngine::finish() {
	lock();
	
	if (!running) {
		unlock();
		return;
	}
	
	clearBreakpoints(false);
	
	closeProcessHandle(false);

	if (debugProcessID != 0) {
		if (!DebugActiveProcessStop(debugProcessID)) {
			DWORD error = GetLastError();
			
			cout << "DebugActiveProcessStop() failed with error[0x" << hex << error << "]\n";
		}
		
		debugProcessID = 0;
	}

	running = false;

	unlock();
}

void DebuggerEngine::run() {
	if (!init())
		return;
	
	DWORD dwContinueStatus = DBG_CONTINUE;

	DEBUG_EVENT debugEvent;
	
	while (doRun) {
		if (WaitForDebugEvent(&debugEvent, 1000)) {
			setWaitingForEvent(true);
			
			processDebuggingEvent(debugEvent);

			// Resume executing the thread that reported the debugging event. .
			ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, dwContinueStatus);
		} else {
			DWORD error = GetLastError();

			if (error != 0x79)	{
				cout << "WaitForDebugEvent() failed with error[0x" << hex << error << "]!\n";
				break;
			}
		}
	}

	setWaitingForEvent(false);
	
	finish();
}

void DebuggerEngine::stop() {
	lock();
	
	doRun = false;
	
	unlock();
}

bool DebuggerEngine::closeProcessHandle(bool doLock) {
	lock(doLock);
	
	if (engineInUse) {
		// are we in use?
		if (CloseHandle(processHandle)) {
			// yup, so close the process handle
			engineInUse = false;

			unlock(doLock);
			return true;
		}
	}

	unlock(doLock);
	return false;
}

bool DebuggerEngine::terminateProcess() {
	lock();
	
	if (engineInUse) {
		if (TerminateProcess(processHandle, (UINT) 0x0D1ED1E)) {
			CloseHandle(processHandle);
			engineInUse = false;
			
			unlock();
			return true;
		}
	}

	unlock();
	return false;
}


void DebuggerEngine::printProcessList(bool doLock) {
	lock(doLock);
	
	DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
    	unlock(doLock);
        return;
    }

    // Calculate how many process identifiers were returned.

    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.
	char x;

	for (i = 0; i < cProcesses; ++i) {
        if (aProcesses[i] != 0)
            printProcessNameAndID(aProcesses[i], false);

		if ((i % 8) == 0 && (i != 0)) {
			cout << "\ncontinue? ";
			cin >> x;

			if (x == 'n') {
				unlock(doLock);
				return;
			}
		}
	}
	
	unlock(doLock);
}

void DebuggerEngine::printProcessNameAndID(DWORD processID, bool doLock) {
	lock(doLock);
	
	if (processID == 0) {
		unlock(doLock);
		return;
	}

	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.

    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, processID );

    // Get the process name.

    if (NULL != hProcess ) {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
            GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));

    }

    // Print the process name and identifier.

    _tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, (unsigned int)processID);

    CloseHandle(hProcess);
    
    unlock(doLock);
}


bool DebuggerEngine::openProcess(char* processWindowTitle, bool doLock) {
	lock(doLock);

	HWND 	targetWindowHandle	= (HWND) -1;
	DWORD 	processId 			= 0xFFFFFFFF;
	//HANDLE 	WindowProcessId		= (HANDLE) INVALID_HANDLE_VALUE;

	if (engineInUse) {
		// we are already in use...
		unlock(doLock);
		return false;
	}

	targetWindowHandle = FindWindow(NULL, processWindowTitle); 	// see if it exist

	if (targetWindowHandle) {
		// got the window handle...
		bool processIDSucces = GetWindowThreadProcessId(targetWindowHandle, &processId); //get a PROCESS number

		if (processIDSucces) {
			// we have a valid process id, now to open it...
			processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
			
			if (processHandle) {
				// process succesfully opened
				engineInUse = true;
				
				unlock(doLock);
				return true;
			 }
		}
	}
	
	unlock(doLock);

	return false;
}

bool DebuggerEngine::openProcess(DWORD processID, bool doLock) {
	lock(doLock);

	//HWND 	TargetWindowHandle	= (HWND) -1;
	DWORD 	ProcessId 			= processID;
	//HANDLE 	WindowProcessId		= (HANDLE) INVALID_HANDLE_VALUE;

	if (engineInUse) {
		// we are already in use...
		unlock(doLock);
		return false;
	}

		// we have a valid process id, now to open it...
	processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);

	if (processHandle) {
		// process succesfully opened
		engineInUse = true;
		unlock(doLock);
		return true;
	}
	
	unlock(doLock);

	return false;
}

bool DebuggerEngine::attachToProcess(DWORD processID, bool doLock) {
	lock(doLock);
	
	if (!openProcess(processID, false)) {
		unlock(doLock);
		return false;
	}

	engineInUse = DebugActiveProcess(processID);

	debugProcessID = processID;
	
	unlock(doLock);
	
	return engineInUse;
}

bool DebuggerEngine::addBreakpoint(unsigned long address) {
	cout << "Trying to create breakpoint in: [0x" << hex << address << "]\n";
	
	lock();
	
	if (!engineInUse) {
		unlock();
		return false;
	}

	suspendProcess(false);

	unsigned char oldByte = 0;
	unsigned char int3 = 0xCC;

	if (!readMemory(address, &oldByte, 1, false, false)) {
		awakeProcess(false);
		unlock();
		return false;
	}

	if (!writeMemory(address, &int3, 1, false, false)) {
		awakeProcess(false);
		unlock();
		return false;
	}

	cout << "Created breakpoint with oldData:" << hex << (unsigned short)oldByte << "\n";

	Breakpoint* breakpoint = new Breakpoint(address, oldByte);
	breakpointList[address] = breakpoint;

	awakeProcess(false);
	
	unlock();

	return true;
}

void DebuggerEngine::processDebuggingEvent(DEBUG_EVENT debugEvent) {
	switch (debugEvent.dwDebugEventCode) {
	case EXCEPTION_DEBUG_EVENT: 
		// Process the exception code. When handling 
		// exceptions, remember to set the continuation 
		// status parameter (dwContinueStatus). This value 
		// is used by the ContinueDebugEvent function. 

		switch(debugEvent.u.Exception.ExceptionRecord.ExceptionCode) { 
		case EXCEPTION_ACCESS_VIOLATION: 
			// First chance: Pass this on to the system. 
			// Last chance: Display an appropriate error. 
			break;

		case EXCEPTION_BREAKPOINT:
			// First chance: Display the current 
			// instruction and register values. 
			handleBreakpointEvent(debugEvent);
			break;

		case EXCEPTION_DATATYPE_MISALIGNMENT: 
			// First chance: Pass this on to the system. 
			// Last chance: Display an appropriate error. 
			break;

		case EXCEPTION_SINGLE_STEP: 
			// First chance: Update the display of the 
			// current instruction and register values. 
			break;

		case DBG_CONTROL_C: 
			// First chance: Pass this on to the system. 
			// Last chance: Display an appropriate error. 
			break;

		default:
			// Handle other exceptions. 
			break;
		}

		case CREATE_THREAD_DEBUG_EVENT: 
			// As needed, examine or change the thread's registers 
			// with the GetThreadContext and SetThreadContext functions; 
			// and suspend and resume thread execution with the 
			// SuspendThread and ResumeThread functions. 

			//dwContinueStatus = OnCreateThreadDebugEvent(debugEvent);
			break;

		case CREATE_PROCESS_DEBUG_EVENT: 
			// As needed, examine or change the registers of the
			// process's initial thread with the GetThreadContext and
			// SetThreadContext functions; read from and write to the
			// process's virtual memory with the ReadProcessMemory and
			// WriteProcessMemory functions; and suspend and resume
			// thread execution with the SuspendThread and ResumeThread
			// functions. Be sure to close the handle to the process image
			// file with CloseHandle.

			//dwContinueStatus = OnCreateProcessDebugEvent(debugEvent);
			break;

		case EXIT_THREAD_DEBUG_EVENT: 
			// Display the thread's exit code. 

			//dwContinueStatus = OnExitThreadDebugEvent(debugEvent);
			break;

		case EXIT_PROCESS_DEBUG_EVENT: 
			// Display the process's exit code. 

			//dwContinueStatus = OnExitProcessDebugEvent(debugEvent);
			break;

		case LOAD_DLL_DEBUG_EVENT: 
			// Read the debugging information included in the newly 
			// loaded DLL. Be sure to close the handle to the loaded DLL 
			// with CloseHandle.

			//dwContinueStatus = OnLoadDllDebugEvent(debugEvent);
			break;

		case UNLOAD_DLL_DEBUG_EVENT: 
			// Display a message that the DLL has been unloaded. 

			//dwContinueStatus = OnUnloadDllDebugEvent(debugEvent);
			break;

		case OUTPUT_DEBUG_STRING_EVENT: 
			// Display the output debugging string. 

			//dwContinueStatus = OnOutputDebugStringEvent(debugEvent);
			break;

		case RIP_EVENT:
			//dwContinueStatus = OnRipEvent(debugEvent);
			break;
	}
}

bool DebuggerEngine::handleBreakpointEvent(DEBUG_EVENT debugEvent) {
	lock();
	
	cout << "Breakpoint reached!\n";

	bool exit = false;
	//int test;

	HANDLE	debugProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, debugEvent.dwProcessId);
	HANDLE	debugThreadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, debugEvent.dwThreadId);

	unsigned long breakpointLocation = 0;
	
	CONTEXT context;

	context.ContextFlags = CONTEXT_FULL;
	GetThreadContext(debugThreadHandle, &context);

	breakpointLocation = context.Eip - 1;

	Breakpoint* breakpoint = breakpointList[breakpointLocation];
	
	if (breakpoint != NULL) {
		if (breakpointLocation == 0x00B5DF51) {
			DWORD ecx = context.Ecx;
		
			cout << "ECX:[" << hex << ecx << "]\n";
		
			clientAppearancePointer = ecx;
		} else if (breakpointLocation = 0x006E5767) {
			DWORD ecx = context.Ecx;
			DWORD eax = context.Eax;
			
			messageQueueDataTransformPointer = eax;
			clientControllerPointer = ecx;
		}
		
		removeBreakpoint(breakpointLocation, false);

		--context.Eip;

		exit = true;

		/*addressX = esi;
		addressZ = esi + 0x10;
		addressY = esi + 0x10;*/
	}

	SetThreadContext(debugThreadHandle, &context);
	CloseHandle(debugProcessHandle);
	CloseHandle(debugThreadHandle);
	
	unlock();

	return exit;
}


bool DebuggerEngine::removeBreakpoint(unsigned long address, bool doLock) {
	lock(doLock);
	
	if (!engineInUse) {
		unlock(doLock);
		return false;
	}
	
	Breakpoint* breakpoint = breakpointList[address];
	
	if (breakpoint == NULL) {
		unlock(doLock);
		return false;
	}
	
	unsigned char oldData = breakpoint->getOriginalData();
	
	writeMemory(address, &oldData, 1, false, false);
	
	breakpointList.erase(breakpointList.find(address));
	
	delete breakpoint;

	unlock(doLock);
	
	return true;
}

bool DebuggerEngine::writeMemory(unsigned long lpBaseAddress, LPVOID lpBuffer, DWORD nSize, bool suspProcess, bool doLock) {
	lock(doLock);
	
	bool successCode = false;

	if (engineInUse) {
		// are we in use
		if (processHandle) {
			// do we have a process handle
			DWORD BytesWritten = 0;
			
			if (suspProcess)
				suspendProcess(false);

			if ((WriteProcessMemory(processHandle, (LPVOID)lpBaseAddress, lpBuffer, nSize, &BytesWritten) 
					&& BytesWritten == nSize)) {
				// write was successful
				// flush the instruction cache (for safety)
				FlushInstructionCache(processHandle, (LPVOID)lpBaseAddress, nSize);
				successCode = true;
			}

			if (suspProcess)
				awakeProcess(false);
		}
	}
	
	unlock(doLock);

	return successCode;
}

void* DebuggerEngine::allocateMemory(int size, bool suspProcess) {
	lock();
	
	void* address = NULL;

	if (suspProcess)
		suspendProcess(false);

	address = VirtualAllocEx(processHandle, NULL, size, MEM_COMMIT, PAGE_READWRITE);

	if (suspProcess)
		awakeProcess(false);
	
	unlock();

	return address;
}

void DebuggerEngine::freeMemory(void* address, int size, bool suspProcess) {
	lock();
	
	if (suspProcess)
		suspendProcess(false);

	VirtualFreeEx(processHandle, address, size, MEM_RELEASE);

	if (suspProcess)
		awakeProcess(false);
	
	unlock();
}

void DebuggerEngine::suspendProcess(bool doLock) {
	lock(doLock);
	
	if (!processSuspended) {
		if (SuspendThread(processHandle) != (DWORD) -1) {
			processSuspended = TRUE;
		}
	}
	
	unlock(doLock);
}

void DebuggerEngine::awakeProcess(bool doLock) {
	lock(doLock);
	
	if (processSuspended) {
		ResumeThread(processHandle);
		processSuspended = false;
	}
	
	unlock(doLock);
}

bool DebuggerEngine::readMemory(unsigned long lpBaseAddress, LPVOID lpBuffer, DWORD nSize, bool suspProcess, bool doLock) {
	lock(doLock);
	
	bool SuccessCode = false;

	if (engineInUse) {
		if (processHandle) {
			DWORD BytesRead = 0;

			if (suspProcess)
				suspendProcess(false);

			if ((ReadProcessMemory(processHandle, (LPVOID)lpBaseAddress, lpBuffer, nSize, &BytesRead) 
					&& BytesRead == nSize)) {
				SuccessCode = true;
			}

			if (suspProcess)
				awakeProcess(false);
		}
	}
	
	unlock(doLock);

	return SuccessCode;
}
