#include "memory_routines.h"
#include <math.h>

namespace structures {
	byte & MemoryRoutines::byteSet(byte & B)
	{
		B = 255;
		return B;
	}
	byte & MemoryRoutines::byteReset(byte & B)
	{
		B = 0;
		return B;
	}
	byte & MemoryRoutines::byteXOR(byte & B)
	{
		//TODO 01: MemoryRoutines
		byte result = 0;
		while (B) {
			result ^= B & 1;
			B >>= 1;
		}
		return B;
	}
	byte & MemoryRoutines::byteSHL(byte & B)
	{
		B = B << 1;
		return B;
	}
	byte & MemoryRoutines::byteSHR(byte & B)
	{
		B = B >> 1;
		return B;
	}
	bool MemoryRoutines::byteNthBitGet(byte & B, int n)
	{
		byte a = B >> n;
		if (a % 2 == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	byte & MemoryRoutines::byteNthBitTo0(byte & B, int n)
	{
		B ^= (0 ^ B) & (1UL << n);
		return B;
	}

	byte & MemoryRoutines::byteNthBitTo1(byte & B, int n)
	{
		B ^= (-1 ^ B) & (1UL << n);
		return B;
	}

	byte & MemoryRoutines::byteNthBitToggle(byte & B, int n)
	{
		if((B >> n) & 1) { 
			byteNthBitTo0(B,n);
		}
		else
		{
			byteNthBitTo1(B, n);
		}
		return B;
	}

	MemoryRoutines::MemoryRoutines()
	{
	}

}
