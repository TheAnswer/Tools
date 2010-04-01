#ifndef THREAD_H_
#define THREAD_H_

// made by Oru

#include "../system.h"


/*! 
 * thread wrapper class. the inheriting classes must implement a run() method that have to contain the code to be executed
 */
class Thread {
	pthread_t thread;

	static void* execute_thread(void* th) {
		Thread* impl = (Thread*) th;
		impl->run();

		return NULL;
	}

public:
	//! allocates a new Thread
	Thread() { }

	//! causes this thread to begin execution
	void start() {
		pthread_create(&thread, NULL, execute_thread, this);
	}

	//! causes this thread to be cancelled
	void cancel() {
		pthread_cancel(thread);
	}

	//! causes the calling thread to be waiting until this thread finishes
	void join() {
		pthread_join(thread, NULL);
	}

	static void sleepMili(unsigned long long time) {
		Sleep((DWORD)time);
	}

	//! this method is called when the thread starts
	virtual void run() = 0;
};


#endif /*THREAD_H_*/
