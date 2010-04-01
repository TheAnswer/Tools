#ifndef DEBUGGERENGINE_H_
#define DEBUGGERENGINE_H_

#include "system.h"

#include "Breakpoint.h"

class DebuggerEngine : public Mutex, public Thread {
	HANDLE processHandle;
	HANDLE threadHandle;

	bool engineInUse;
	bool processSuspended;

	DWORD debugProcessID;

	map<unsigned long, Breakpoint*> breakpointList;
	
	bool waitingForEvent;
	bool doRun;
	bool running;
	
	DWORD clientAppearancePointer;
	
	DWORD clientControllerPointer;
	DWORD messageQueueDataTransformPointer;

private:
	bool init();
	void finish();
	
	void processDebuggingEvent(DEBUG_EVENT debugEvent);
	
	bool handleBreakpointEvent(DEBUG_EVENT debugEvent);

public:
	DebuggerEngine();
	virtual ~DebuggerEngine();

	void printProcessList(bool doLock = true);
	void printProcessNameAndID(DWORD processID, bool doLock = true);
	
	bool openProcess(char* processWindowTitle, bool doLock = true);
	bool openProcess(DWORD processID, bool doLock = true);

	bool attachToProcess(DWORD processID, bool doLock = true);

	bool closeProcessHandle(bool doLock = true);
	void clearBreakpoints(bool doLock = true);
	
	void run();
	void stop();

	bool addBreakpoint(unsigned long address);
	bool removeBreakpoint(unsigned long address, bool doLock = true);

	bool terminateProcess();
	
	bool writeMemory(unsigned long lpBaseAddress, LPVOID lpBuffer, DWORD nSize, bool suspProcess = true, bool doLock = true);
	bool readMemory(unsigned long lpBaseAddress, LPVOID lpBuffer, DWORD nSize, bool suspProcess = true, bool doLock = true);

	void* allocateMemory(int size, bool suspProcess = true);
	void freeMemory(void* address, int size, bool suspProcess = true);

	void suspendProcess(bool doLock = true);
	void awakeProcess(bool doLock = true);
	
	inline HANDLE getProcessHandle() {
		return processHandle;
	}
	
	inline DWORD getClientAppearancePointer() {
		DWORD ret;
		
		lock();
		
		ret = clientAppearancePointer;
		
		unlock();
		
		return ret;
	}
	
	inline DWORD getClientControllerPointer() {
		DWORD ret;

		lock();

		ret = clientControllerPointer;

		unlock();

		return ret;
	}
	
	inline DWORD getMessageQueueDataTransformPointer() {
		DWORD ret;

		lock();

		ret = messageQueueDataTransformPointer;

		unlock();

		return ret;
	}
	
	inline void setWaitingForEvent(bool val) {
		lock();
		
		waitingForEvent = val;
		
		unlock();
	}
	
	inline bool isWaitingForEvent() {
		bool ret;
		
		lock();
		
		ret = waitingForEvent;
		
		unlock();
		
		return ret;
	}
	
	inline bool isRunning() {
		bool ret;
		
		lock();
		
		ret = running;
		
		unlock();
		
		return ret;
	}
};


#endif /*DEBUGGERENGINE_H_*/
