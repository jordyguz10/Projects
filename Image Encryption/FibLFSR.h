#pragma once
#ifndef LFSR_H
#define LFSR_H

#include <iostream>
#include <string>

class FibLFSR{
public:
	FibLFSR(std::string seed);
	int step();
	int generate(int k);
	std::string getSeed(void) const{
		return bits;
	}
	int getLastBit(void) const {
		return lastBit;
	}
	friend std::ostream& operator <<(std::ostream& outStream, const FibLFSR& BitSeed);
private:
	std::string bits;
	int lastBit;
};

#endif