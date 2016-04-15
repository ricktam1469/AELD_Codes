#ifndef INTEGRATE_HPP
#define INTEGRATE_HPP
#include <systemc.h>
#include "loadProgram.hpp"
#include "Registers.hpp"
#include "Packet.hpp"


SC_MODULE(Integrate){

sc_in < bool > clk;
sc_out <Packet> output;

sc_out < bool > inp_vld;
sc_in < bool > inp_rdy;

Packet p1;
loadProgram load;
Registers reg;
int *regptr,*coutallptr;
vector<Operation> opr;

string operand11;
string operand22; 
vector<string> operators;
string operand33; 
vector<string> operators1;

void letssend(){

	inp_vld.write(0);


	int *ptr;
	int *ptr1;
	int value2;

	for(int iteretor=0;iteretor<opr.size();iteretor++)
		{
	
	// how to implement load instruction
	if(opr[iteretor]==ADD || opr[iteretor]==SUB ||opr[iteretor]==MUL ||opr[iteretor]==DIV ||opr[iteretor]==CMP)
	{
		ptr=strParsingToPointer(operators[iteretor],regptr);
		
		// Here we have to put the details of xCoordinate and yCoordinate coordinates corresponding to each instruction
	
		/*{*/
		string registers[16]={"R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","R10","R11","R12","R13","R14","R15"};
	   		  
		if(operators[iteretor] ==registers[0]){
	    		p1.xCoordinate=0;
	   		p1.yCoordinate=0;
	   	 }
	    	 if(operators[iteretor] ==registers[1]){
		    p1.xCoordinate=1;
		    p1.yCoordinate=0;
		    }
		 if(operators[iteretor] ==registers[2]){
		    p1.xCoordinate=2;
		    p1.yCoordinate=0;
		    }
		 if(operators[iteretor] ==registers[3]){
		    p1.xCoordinate=3;
		    p1.yCoordinate=0;
		    }
		 if(operators[iteretor] ==registers[4]){
		    p1.xCoordinate=0;
		    p1.yCoordinate=1;
		    }
		 if(operators[iteretor] ==registers[5]){
		    p1.xCoordinate=1;
		    p1.yCoordinate=1;
		    }
		 if(operators[iteretor] ==registers[6]){
		    p1.xCoordinate=2;
		    p1.yCoordinate=1;
		    }
		 if(operators[iteretor] ==registers[7]){
		    p1.xCoordinate=3;
		    p1.yCoordinate=1;
		    }
		 if(operators[iteretor] ==registers[8]){
		    p1.xCoordinate=0;
		    p1.yCoordinate=2;
		    }
		 if(operators[iteretor] ==registers[9]){
		    p1.xCoordinate=1;
		    p1.yCoordinate=2;
		    }
		 if(operators[iteretor] ==registers[10]){
		    p1.xCoordinate=2;
		    p1.yCoordinate=2;
		    }
		 if(operators[iteretor] ==registers[11]){
		    p1.xCoordinate=3;
		    p1.yCoordinate=2;
		    }
		 if(operators[iteretor] ==registers[12]){
		    p1.xCoordinate=0;
		    p1.yCoordinate=3;
		    }
		 if(operators[iteretor] ==registers[13]){
		    p1.xCoordinate=1;
		    p1.yCoordinate=3;
		    }
		 if(operators[iteretor] ==registers[14]){
		    p1.xCoordinate=2;
		    p1.yCoordinate=3;
		    }
		 if(operators[iteretor] ==registers[15]){
		    p1.xCoordinate=3;
		    p1.yCoordinate=3;
		    }
	   
		      
	          if(ptr==0)
		  {

		        int value1;
		        istringstream convert(operators[iteretor]);
		        convert>>value1;
		        ptr=&value1;
		  }
		  ptr1=strParsingToPointer(operators1[iteretor],regptr);
		  if(ptr1==0)
		  {
		      istringstream convert(operators1[iteretor]);
		      convert >> value2;
		      ptr1=&value2;
		  }
		inp_vld.write(1);           
		p1.operation=opr[iteretor];
		p1.flagForCheck= true;
		p1.value1= ptr;
		p1.value2= ptr1;
		   
		output.write(p1);               // convert to flits
		   
		    do{           
		    wait();
		    } while(!inp_rdy.read());
		       inp_vld.write(0);       
	       
		wait();
	       
		}

	    if(opr[iteretor]==COUTALL){
	    coutallptr=regptr;
            cout<<endl;
            for(int p=0;p<15;p++){
	            cout<< *coutallptr<<endl;
	            coutallptr++;
	           }
	    wait();
	    }
	   
        }
	sc_stop();


}

int* strParsingToPointer(string str,int *regptr)
{
    string regno[16]={"R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","R10","R11","R12","R13","R14","R15"};
    for(int iteretorptr=0;iteretorptr<15;iteretorptr++)
    {
        if(str==regno[iteretorptr])
        return regptr;
        else
        regptr++;
    }
    return 0;

}

SC_CTOR(Integrate) : load("LOAD"),reg("REGISTER"){
 
	opr=load.operation;
    	operators=load.op2;
    	operators1=load.op3;
   
   	regptr=&reg.storageArray[0];
   
	SC_CTHREAD(letssend,clk.pos());



}





};
#endif 
