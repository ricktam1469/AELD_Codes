#include "ALU.h"
#include <systemc.h>

void ALU::execute(){
inp_rdy.write(0);



while( true ){
int *ptrre;
int *ptrim;
inp_rdy.write(1);

do{
wait();
} while(!inp_vld.read());

oppp=inp1.read();
ptrim=op1.read();
ptrre=op0.read();

inp_rdy.write(0);


int op0,op1;

switch(oppp){
	
		case 0 : return op0+op1;
			 
		case 1 : return op0-op1;
			 
		case 2 : return op0*op1;
			
		case 3 : try{
				if(op1==0)
					throw op1;
				return op0/op1;
				}
				catch(int i){
					cout<<"Divide by Zero Exception!! Division(op0/op1) is not possible! Program Aborted!"<<endl;
					exit (EXIT_FAILURE);
				}
			
		case 4 : if(op0>op1){
				registers.ge=1;
				registers.z=0;
				return 1;
			 }
			 else if(op0==op1){
				registers.z=1;
				registers.ge=1;				
				return 0;
			 }
			 else{
				registers.ge=0;
				registers.z=0;	
				return -1;
			 }
			
		default: cout<<"Check Enumeration\n";
			 break;
	}
	return 0;
  if(oppp==ADD)
	{
cout<< "in ADD"<<endl;
	op0=*ptrre;
	op1=*ptrim;

	*ptrre=op0+op1;
		wait(4);
	
	}

  if(oppp==SUB)
        {
cout <<"in sub"<<endl;
             op0=*ptrre;
            op1=*ptrim;
	    
            *ptrre=op0-op1;
		wait(5);

        }

    if(oppp==MUL)

        {
             op0=*ptrre;
            cout <<"in MUL"<<endl;
            op1=*ptrim;
	       *ptrre=op0*op1;
	wait(10);


        }


    if(oppp==DIV)
        {
             op0=*ptrre;
            op1=*ptrim;
	    wait();
            *ptrre=op0/op1;

        }

    if(oppp==CMP)
        {
            op0=*ptrre;
            op1=*ptrim;
	    wait();
             if(*ptrre==*ptrim)
                Z=1;
            if(*ptrre!=*ptrim)
                Z=0;



        }

}}
int ALU::execute(int op0,int op1,Operation operation){
	
	switch(oppp){
	
		case 0 : return op0+op1;
			 
		case 1 : return op0-op1;
			 
		case 2 : return op0*op1;
			
		case 3 : try{
				if(op1==0)
					throw op1;
				return op0/op1;
				}
				catch(int i){
					cout<<"Divide by Zero Exception!! Division(op0/op1) is not possible! Program Aborted!"<<endl;
					exit (EXIT_FAILURE);
				}
			
		case 4 : if(op0>op1){
				registers.ge=1;
				registers.z=0;
				return 1;
			 }
			 else if(op0==op1){
				registers.z=1;
				registers.ge=1;				
				return 0;
			 }
			 else{
				registers.ge=0;
				registers.z=0;	
				return -1;
			 }
			
		default: cout<<"Check Enumeration\n";
			 break;
	}
	return 0;
}


