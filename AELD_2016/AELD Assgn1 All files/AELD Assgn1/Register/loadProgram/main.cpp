#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include "ALU.hpp"

using namespace std;

//Global Declaration
int op0=0,op1=0; //Two operands for storing the value of registers 

int op0RegAdr;	//Stores index of Register in first operand i.e value of n in Rn 
int op1RegAdr;	//Stores index of Register in Second operand i.e value of n in Rn 

Registers reg;	//Object of Register Class

ALU aluObject(reg);  //Object of ALU class with Register Object

/*
 *
 * Extracting operands on the basis of Register name and only specific to R0 to R7(max R9)
 * It wont work for R10 to R15.It will give error for R10 to R15 and any other variable of size>2.
 * Parsing Rn to R and n and getting access to n from the register array by indexes and storing 
 * the values in operands	
 */

void parse(char* opr1,char* opr2) {
	if(strlen(opr1)<=2) {
		if(opr1!=NULL) {
			if(opr1[0]=='R'||opr1[0]=='r') {	//Checking for R or r in Registers
			
				op0RegAdr=opr1[1]-'0';
				op0=reg.storage_array[op0RegAdr];	//Storing the value of array of index n from Rn into operand
			}
			else
				op0=atoi(opr1);		//Converting char array to string
		}
		else
			op0=0;
	}

	else if((opr1[0]>='a'&& opr1[0]<='z') || (opr1[0]>='A' && opr1[0]<='Z')){
		cout<<"Presently use R0 to R9. Remaining is under development!!"<<endl;
		exit (EXIT_FAILURE);
	}
	if(strlen(opr2)<=2) {
		if(opr2!=NULL) {
			if(opr2[0]=='R'||opr2[0]=='r') {	//Checking for R or r in Registers
					
				op1RegAdr=opr2[1]-'0';
				op1=reg.storage_array[op1RegAdr];	//Storing the value of array of index n from Rn into operand
			}
			else
				op1=atoi(opr2);		//Converting char array to string
		}
		else	
			op1=0;
	}
	else if((opr2[0]>='a'&& opr2[0]<='z') || (opr2[0]>='A' && opr2[0]<='Z')){
		cout<<"Presently use R0 to R9. Remaining is under development!!"<<endl;
		exit (EXIT_FAILURE);
	}
}

/*
 *
 * Extracting operation from enum on the basis switch case and 
 * performOperation function pass the values to this function
 *	
 */

void operationExecute(int opnd0,int opnd1,OperationMain opm) {

	switch(opm) {
	
		case 0 : reg.storage_array[op0RegAdr]=opnd1;
			 break;
		case 1 : reg.pc=opnd0;
			 break;
		case 2 : reg.pc=opnd0;
			 break;	
		case 3 : reg.pc=opnd0;
			 break;	
		case 4 : reg.pc=opnd0;
			 break;	
		case 5 : reg.pc=opnd0;
			 break;	
		default: cout<<"No operation is there!! Please check!!\n";
			 break;
	}
}

/*
 *
 * Defining a string array which holds all the operation handled by ALU  
 * Implementation of first five is done in ALU class and Remaining in main
 *	
 */

void performOperation(loadProgram& lp){

	const char* operandALU[]={"ADD","SUB","MUL","DIV","CMP"};
	const char* operandMain[]={"LOAD","JMP","JNZ","JZ","JGT","JGE","HALT","NOP","COUT","COUTALL"};	
	int flag;
	lp.fileReading();

		for(unsigned int iterate=0;iterate<lp.storageVector.size();iterate++) {
			flag=0;			
			cout<<"Assembler Command: "<<lp.storageVector[iterate].command<<"  "<<lp.storageVector[iterate].operand1<<"  "<<lp.storageVector[iterate].operand2<<endl;
			for(int strIterate=0;strIterate<10;strIterate++){
				if(strIterate<5)
				if(strcmp(lp.storageVector[iterate].command,operandALU[strIterate])==0){	//Handling operation in ALU
					parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
					if(strIterate==4)	//Not storing in register for CMP operation
						aluObject.execute(op0,op1,Operation(strIterate));
					else
						reg.storage_array[op0RegAdr]=aluObject.execute(op0,op1,Operation(strIterate));
					cout<<"Array Element: ";
					for(int arrIterate=0;arrIterate<8;arrIterate++)
						cout<<reg.storage_array[arrIterate]<<" ";
					cout<<" Zero Flag: "<<aluObject.registers.z;
					cout<<" Greater Equal Flag: "<<aluObject.registers.ge;
					cout<<endl<<endl;	
									
				}
				if(strcmp(lp.storageVector[iterate].command,operandMain[strIterate])==0){	//Handling Operation in Main
					flag=1;
					switch(strIterate){
						case 0: cout<<"inLOAD"; 
								if(isdigit(atoi(lp.storageVector[iterate].operand1))){
								cout<<"LOAD First operand can't be Number";
								return;
							}
							parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
							operationExecute(op0,op1,LOAD);	
							cout<<"Array Element: ";
							for(int arrIterate=0;arrIterate<8;arrIterate++)
								cout<<reg.storage_array[arrIterate]<<" ";
							cout<<" Zero Flag: "<<aluObject.registers.z;
							cout<<" Greater Equal Flag: "<<aluObject.registers.ge;
							cout<<endl<<endl;
							break;
						case 1: parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);													
							operationExecute(op0,op1,JMP);
							iterate=reg.pc-1;
							cout<<endl<<endl;
							break;
						case 2:	parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
							if(aluObject.registers.z==0) {							
								operationExecute(op0,op1,JNZ);
								iterate=reg.pc-1;
								cout<<endl<<endl;
								break;
							}
							else {
								cout<<"Skipped as Zero Flag is set"<<endl<<endl;	     									break;							
							}
							
						case 3: parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
							if(aluObject.registers.z==1) {							
								operationExecute(op0,op1,JZ);
								iterate=reg.pc-1;
								cout<<endl<<endl;	
								break;
							}
							else {
								cout<<"Skipped as Zero Flag is Not set"<<endl<<endl;	     									break;							
							}
							
						case 4: parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);					//aluObject.registers.ge==((1)^(aluObject.registers.z));
							if(aluObject.registers.ge==0) {							
								operationExecute(op0,op1,JGT);
								iterate=reg.pc-1;
								cout<<endl<<endl;	
								break;
							}
							else {
								cout<<"Skipped as Greater Equal Flag is Not set "<<endl<<endl;	     									break;							
							}
							
						case 5: parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
							if(aluObject.registers.ge==1) {							
								operationExecute(op0,op1,JGE);
								iterate=reg.pc-1;
								cout<<endl<<endl;
								break;
							}
							else {
								cout<<"Skipped as Greater Equal Flag is set"<<endl<<endl;	     									break;							
							}
							
						case 6: cout<<"HALT!! Program Aborted!!\n"; return;
						case 7: break;
						case 8: parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
							cout<<"Array Element at pos "<< op0RegAdr<<" :"<<reg.storage_array[op0RegAdr];
							cout<<endl<<endl;
							break;
						case 9: parse(lp.storageVector[iterate].operand1,lp.storageVector[iterate].operand2);		
							cout<<"Array Element: ";
							for(int arrIterate=0;arrIterate<16;arrIterate++)
								cout<<reg.storage_array[arrIterate]<<" ";
							cout<<" Zero Flag: "<<aluObject.registers.z;
							cout<<" Greater Equal Flag: "<<aluObject.registers.ge;
							cout<<endl<<endl;
							break;
					        default: cout<<"No Such Operation exists presently !!"<<endl; 
					}	
				}

				if(flag==1) break;
			}
			
			
		}


}
/*
 * Calling all functions in main and File Handling
 *
 */
int main(int argc, char **argsfile)
{
	
	cout<<"\n\t WELCOME TO RK ALU "<<endl;
	cout<<"\t ^^^^^^^ ^^ ^^ ^^^ "<<endl<<endl;		
	
	for(unsigned int arrIterate=0 ; arrIterate < (sizeof(reg.storage_array)/sizeof(*reg.storage_array)) ; arrIterate++) 
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
	performOperation(lp);		//function call for implementing all Operations
	cout<<endl;
	
	cout<<"Specific Statement (For listing 4) :"<<endl;
	cout<<"For Fibonacci Series(011235..) given in listing 4 Output is stored in R5 according to ASCII_File.asm(.txt): Value is: "<<reg.storage_array[5]<<" for n = "<<reg.storage_array[0]<<endl<<endl;
	return 0;
}
