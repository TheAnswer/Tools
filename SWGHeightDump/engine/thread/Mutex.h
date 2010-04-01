#ifndef MUTEX_H_
#define MUTEX_H_

// made by Oru

#include "../system.h"

class Mutex {
		pthread_mutex_t mutex;
	
		bool doLog;
		string lockName;
			
		int lockCount;
		int currentCount;
	
	public:
		Mutex() {
			//mutex = PTHREAD_MUTEX_INITIALIZER;
			pthread_mutex_init(&mutex, NULL);
				
			doLog = true;
			lockName = "Mutex";
	
			lockCount = 0;
		}
	
		Mutex(const string& s) {
			//mutex = PTHREAD_MUTEX_INITIALIZER;
			pthread_mutex_init(&mutex, NULL);
				
			doLog = true;
			lockName = s;
	
			lockCount = 0;
		}

		void setMutexLogging(bool dolog) {
			doLog = dolog;
		}
	
		void setLockName(const string& s) {
			lockName = s;
		}
	
		inline void lock(bool doLock = true) {
			if (!doLock)
				return;
			
			int res = pthread_mutex_lock(&mutex); 
				
			if (res != 0)
				cout << "(" << /*Time::currentNanoTime()*/0 << " nsec) lock() failed on Mutex \'" << lockName << "\' (" << res << ")\n";
	
		}
	
		inline bool tryLock() {
			return pthread_mutex_trylock(&mutex) == 0;
		}
		
		inline void unlock(bool doLock = true) {
			if (!doLock)
				return;
	
			int res = pthread_mutex_unlock(&mutex);
			
			if (res != 0) {
				cout << "(" << /*Time::currentNanoTime()*/0 << " nsec) unlock() failed on Mutex \'" << lockName << "\' (" << res << ")\n";
			}
		}

	};

#endif /*MUTEX_H_*/
