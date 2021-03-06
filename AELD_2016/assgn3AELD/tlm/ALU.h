
#ifndef ALU_H
#define ALU_H
#include<systemc.h>

typedef enum {ADD, SUB, MUL, DIV, CMP,LOAD,COUTALL,COUT,JMP} Operation;

SC_MODULE(ALU)
{
Operation oppp; 
   
sc_in < bool > clk;
//sc_in < bool > rst;
sc_in < Operation > inp1;
sc_in < int*  > op0;
sc_in < int*  > op1; 
sc_in < bool > inp_vld;
sc_out < bool > inp_rdy;


       void execute() ;
        int Z;
	SC_CTOR(ALU){
	SC_CTHREAD(execute,clk.pos()); 
	//reset_signal_is(rst,true);	    //  need to send data from SYSTEM to ALU....
	}
        
    };
#endif // ALU_H
typedef enum {ADD,SUB,MUL,DIV,CMP} Operation;
typedef enum {LOAD,JMP,JNZ,JZ,JGT,JGE,HALT,NOP,COUT,COUTALL} OperationMain;


SC_MODULE(ALU) {

	int op0;
	int op1;
	sc_in<bool> clock;	
	Registers registers;	//object of Registers class

	
	
	int *register_location;	//Access to Registers class instances 
	//Registers reg;

	SC_CTOR(ALU)
	{
		//registers=reg;
		//register_location=registers.storage_array;
		SC_CTHREAD(execute,clock.pos());
	}
		

};

