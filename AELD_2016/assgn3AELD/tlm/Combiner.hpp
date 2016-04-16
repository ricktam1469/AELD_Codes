#ifndef COMBINER_H
#define COMBINER_H
#include<systemc.h>
#include<ALU.h>
#include "LoadProgram.h"
#include "Registers.h"



SC_MODULE(Combiner){

sc_in < bool > clk;
sc_out < Operation > outp1;
sc_out < int*  > outp2;
sc_out < int*  > outp3; 
sc_out < bool > inp_vld;
sc_in < bool > inp_rdy;


LoadProgram load;
Registers rest1;
int *regptr,*coutallptr;
vector<Operation> operation1;
    string operand11;
    string operand22; vector<string> op22;
    string operand33; vector<string> op33;

void letssend(){

inp_vld.write(0);


int *ptr;
int *ptr1;
                     int value2;
 for(int i=0;i<operation1.size();i++)
        {
//cout<<i<<endl;

          // how to implement load instruction
	

          if(operation1[i]==ADD || operation1[i]==SUB ||operation1[i]==MUL ||operation1[i]==DIV ||operation1[i]==CMP)
                {
                        ptr=stringtopointer(op22[i],regptr);
                        if(ptr==0) 
                        {

                            int value1;
                            istringstream convert(op22[i]);
                              convert>>value1;
                              ptr=&value1;
                         }
                        ptr1=stringtopointer(op33[i],regptr);
                         if(ptr1==0) 
                        {
			
                            istringstream convert(op33[i]);
                            convert >> value2; 
                              ptr1=&value2;
                         }
			inp_vld.write(1);			
cout << "the value in combiner "<<*ptr1<<endl;			
			outp1.write(operation1[i]);
			outp2.write(ptr);
			outp3.write(ptr1);

			do{			
			wait();
			} while(!inp_rdy.read());
		       inp_vld.write(0);		
		
		wait();
		
                }
	if(operation1[i]==COUTALL){
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

int* stringtopointer(string str,int *regptr)
{
    string regno[16]={"R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","R10","R11","R12","R13","R14","R15"};
    for(int i=0;i<15;i++)
    {
        if(str==regno[i])
        return regptr;
        else
        regptr++;
    }
    return 0;

}

SC_CTOR(Combiner) : load("LOAD"),rest1("REGISTER"){
    
    

    operation1=load.operation;
    op22=load.op2;
    op33=load.op3;
	
    regptr=&rest1.repp[0];
    

SC_CTHREAD(letssend,clk.pos());



}





};
#endif // COMBINER_H
