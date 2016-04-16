#ifndef ALU_HPP
#define ALU_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef enum {ADD,SUB,MUL,DIV,CMP} Operation;
typedef enum {LOAD,JMP,JNZ,JZ,JGT,JGE,HALT,NOP,COUT,COUTALL} OperationMain;

class Registers {

	public :
		int storage_array[16]; //Array of Registers
		int z;  //zero Flag
		int ge; //Greater Equal Flag
		int pc; //Program  counter

		Registers(){
			z=0;
			ge=0;
			pc=0;
		}
		
};
class ALU {

	int op0;
	int op1;	

	public :
		int *register_location;	//Access to Registers class instances 
		ALU(Registers reg);
		int execute(int,int,Operation operation) ;
		Registers registers;	//object of Registers class
		

};

class loadProgram{
	
	ifstream file;
	public:
		loadProgram(char *file);
		~loadProgram(){
			file.close();
		}		
		struct commandM32 {
			char* command;
			char* operand1;
			char* operand2;
		}objcommandM32;
		vector<commandM32> storageVector;	//Structured type vector
		void fileReading();	//Reading the file and store in a vector 	

};


#endif
