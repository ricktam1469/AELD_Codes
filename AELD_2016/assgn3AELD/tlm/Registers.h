#ifndef REGISTERS_H
#define REGISTERS_H
#include<systemc.h>

SC_MODULE(Registers)
{
        int repp[15];
        SC_CTOR(Registers){

	
	for(int i=0;i<15;i++)
	repp[i]=0;
	



	}
    
};

#endif // REGISTERS_H
