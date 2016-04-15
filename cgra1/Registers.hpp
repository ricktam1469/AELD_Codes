#ifndef REGISTERS_HPP
#define REGISTERS_HPP
#include<systemc.h>

SC_MODULE(Registers)
{
        int storageArray[15];
        
	SC_CTOR(Registers){
	
		for(int iterate=0;iterate<15;iterate++)
			storageArray[iterate]=0;
	}
    
};

#endif // REGISTERS_HPP
