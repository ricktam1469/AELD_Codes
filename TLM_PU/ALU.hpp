#ifndef ALU_HPP
#define ALU_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include <systemc.h>
#include "reg.hpp"

typedef enum {ADD,SUB,MUL,DIV,CMP} Operation;
typedef enum {LOAD,JMP,JNZ,JZ,JGT,JGE,HALT,NOP,COUT,COUTALL} OperationMain;


SC_MODULE(ALU) {

	int op0;
	int op1;
	sc_in<bool> clock;	
	Registers registers;	//object of Registers class

	int execute(int,int,Operation operation) ;
	
	int *register_location;	//Access to Registers class instances 
	//Registers reg;

	SC_CTOR(ALU)
	{
		//registers=reg;
		//register_location=registers.storage_array;
		//SC_CTHREAD(execute,clock.pos());
		SC_METHOD(execute);
	}
		

};



#endif
