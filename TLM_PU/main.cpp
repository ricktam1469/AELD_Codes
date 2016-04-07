#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include "ALU.hpp"
#include "reg.hpp"
#include "lp.hpp"
#include "combiner.hpp"
using namespace std;
Combiner *c;
Register reg;
/*
 * Calling all functions in main and File Handling
 *
 */
int sc_main(int argc, char **argsfile)
{

	//sys=new SYSTEM("sys");
	c=new Combiner("combiner");

	cout<<"\n\t WELCOME TO RK ALU "<<endl;
	cout<<"\t ^^^^^^^ ^^ ^^ ^^^ "<<endl<<endl;		
	
	for(unsigned int arrIterate=0 ; arrIterate < (sizeof(sys.reg.storage_array)/sizeof(*sys.reg.storage_array)) ; arrIterate++) 
		reg.storage_array[arrIterate]=0;	//Initially store 0 to all elements of Registers
	
	FILE *fileptr; //File Pointer
	if(argsfile[1] == NULL || (fileptr = fopen(argsfile[1], "r")) == NULL) {	//Input the fileName in argument 1
		cout<<"Please put a filename in argument :" <<argc<<endl;
		return 0;
	}
	if(fileptr == NULL){	
		cout<<"Can't opening file.\n"; 
		return 0;
	}

	loadProgram lp(argsfile[1]);	//Creating object of loadProgram class and passing filename to parameterized constructor
	//sys.performOperation(lp);		//function call for implementing all Operations
	cout<<endl;
	
	sc_start();

	cout<<"Specific Statement (For listing 4) :"<<endl;
	cout<<"For Fibonacci Series(011235..) given in listing 4 Output is stored in R5 according to ASCII_File.asm(.txt): Value is: "<<reg.storage_array[5]<<" for n = "<<reg.storage_array[0]<<endl<<endl;
	
	return 0;
}
