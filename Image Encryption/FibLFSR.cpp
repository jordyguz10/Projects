#include "FibLFSR.h"

FibLFSR::FibLFSR(std::string seed){
	bits = seed;
	if (bits.length() < 16){
		while (bits.length() < 16){
			bits.push_back('0');
		}
	}else if (bits.length() > 16){
		bits.resize(16);
	}
}
int FibLFSR::step(){
		
	int bit = (bits.at(0) - '0') ^ (bits.at(2) - '0') ^ (bits.at(3) - '0') ^ (bits.at(5) - '0');
	bits.erase(bits.begin() + 0);
	bits.push_back(bit + '0');
	lastBit = bit;
	return bit;
}
int FibLFSR::generate(int k){
	int value = 0;
	for(int i = 0; i < k; i++){
    	value = value * 2 + step();
	}
	return value;
}
std::ostream& operator <<(std::ostream& outStream, const FibLFSR& BitSeed){
	outStream << BitSeed.bits;
	return outStream;
}
