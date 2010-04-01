#ifndef BREAKPOINT_H_
#define BREAKPOINT_H_

class Breakpoint {
	unsigned long address;
	unsigned char originalData;

public:
	Breakpoint(unsigned long address, unsigned char originalData) {
		this->address = address;
		this->originalData = originalData;
	}

	inline unsigned long getAddress() {
		return address;
	}

	inline unsigned char getOriginalData() {
		return originalData;
	}

};

#endif /*BREAKPOINT_H_*/
