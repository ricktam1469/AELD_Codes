#ifndef ALU_HPP
#define ALU_HPP

#include <iostream>

using namespace std;

typedef enum {ADD,SUB,MUL,DIV,CMP} Operation;

class Registers {

	public :
		int storage_array[16];	//Array of Registers
		
};
class ALU {

	public :
		int op0;
		int op1;
		int *register_location;	//Access to Registers class instances 
		int execute(Operation operation) ;
		Registers registers;
		ALU(Registers reg); //object of Registers class

};



#endif
