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

typedef enum {ADD,SUB,MUL,DIV,CMP} Operation;
typedef enum {LOAD,JMP,JNZ,JZ,JGT,JGE,HALT,NOP,COUT,COUTALL} OperationMain;

SC_MODULE(Registers) {

	sc_in<bool> clock;
		int storage_array[16]; //Array of Registers
		int z;  //zero Flag
		int ge; //Greater Equal Flag
		int pc; //Program  counter
void abc(){
z=0;
			ge=0;
			pc=0;
}
		SC_CTOR(Registers){
			SC_CTHREAD(abc,clock.pos());
		}
		
};
SC_MODULE(ALU) {

	int op0;
	int op1;
	sc_in<bool> clock;	
	Registers registers;	//object of Registers class

	int execute(int,int,Operation operation) ;
	
	int *register_location;	//Access to Registers class instances 
	Registers reg;
	SC_CTOR(ALU):reg("reg"),registers("registers"){registers=reg;
	register_location=registers.storage_array;
	SC_CTHREAD(execute,clock.pos());
}
		

};

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

	SC_CTOR(loadProgram){ 
		file.open("ASCII_File.asm", ios::in);
		SC_CTHREAD(fileReading,clock.pos());
	}
	~loadProgram(){
	file.close();
	}		
	
		

};


#endif
