#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>  
#include "ALU.hpp"
#include "reg.hpp"
#include "lp.hpp"


/*
 * Implementing ADD,SUB,MUL,DIV,CMP
 *
 */
int ALU::execute(int op0,int op1,Operation operation){
	
	switch(operation){
	
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




