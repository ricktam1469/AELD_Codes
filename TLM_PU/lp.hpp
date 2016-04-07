#ifndef LP_HPP
#define LP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include <systemc.h>
#include "reg.hpp"
#include "ALU.hpp"

SC_MODULE(loadProgram){
	sc_in<bool> clock;
	ifstream file;
	struct commandM32 {
		char* command;
		char* operand1;
		char* operand2;
	}objcommandM32;
	
	vector<commandM32> storageVector;	//Structured type vector
	void fileReading();	//Reading the file and store in a vector 
	void parse(char* opr1,char* opr2);
	void operationExecute(int opnd0,int opnd1,OperationMain opm);
	void performOperation();  
	ALU aluObject;
	Registers reg;
	SC_CTOR(loadProgram):reg("register"),aluObject("ALU"){ 
		SC_CTHREAD(fileReading,clock.pos());
	}
	~loadProgram(){
	file.close();
	}		
	
		

};
#endif