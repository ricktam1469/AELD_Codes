#ifndef REG_HPP
#define REG_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include <systemc.h>

SC_MODULE( Registers ) {

	sc_in<bool> clock;
		int storage_array[16]; //Array of Registers
		int z;  //zero Flag
		int ge; //Greater Equal Flag
		int pc; //Program  counter
	
	
	
	SC_CTOR( Registers ){
			z=0;
		ge=0;
		pc=0;
		for(int i=0;i<16;i++)
		{
			storage_array[i]=0;
		}
		}
		
};

#endif