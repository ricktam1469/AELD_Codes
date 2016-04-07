#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include <systemc.h>
#include "lp.hpp"

void loadProgram::fileReading(){

file.open("ASCII_File.asm", ios::in);
		string fileLine;
		while(getline(file,fileLine))
		{
			char *temp=new char[fileLine.length()+1];
			int i=0;    
	    	char *parser;
		   		
			strcpy(temp,fileLine.c_str());

	   		char* receivedDataString[3]={NULL}; //As File is having only 3 Coloumn
				
			//IF LINE IS BLANK, CONTINUE
			if(fileLine.empty()){
				cout<<"Empty line!\n";
				continue;
		}
		else{
	   		parser = strtok(temp, " ");
 		  		
			while (parser!=NULL)
			{
		    		receivedDataString[i]=parser;
		    		parser = strtok(NULL, " ");
					i++;
				
			}
			
		}	
		objcommandM32.command=receivedDataString[0];
		if(receivedDataString[1]!=NULL)
			objcommandM32.operand1=receivedDataString[1];
		else 	
			objcommandM32.operand1=" ";
		if(receivedDataString[2]!=NULL)
			objcommandM32.operand2=receivedDataString[2];
		else 	
			objcommandM32.operand2=" ";
		storageVector.push_back(objcommandM32);	
	}
}
void loadProgram::parse(char* opr1,char* opr2) {
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

	void loadProgram::operationExecute(int opnd0,int opnd1,OperationMain opm) {

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
	 * Extracting operation from enum on the basis switch case and 
	 * performOperation function pass the values to this function
	 *	
	 */

	 void loadProgram::performOperation(){

		const char* operandALU[]={"ADD","SUB","MUL","DIV","CMP"};
		const char* operandMain[]={"LOAD","JMP","JNZ","JZ","JGT","JGE","HALT","NOP","COUT","COUTALL"};	
		int flag;
		

			for(unsigned int iterate=0;iterate<storageVector.size();iterate++) {
				flag=0;			
				cout<<"Assembler Command: "<<storageVector[iterate].command<<"  "<<storageVector[iterate].operand1<<"  "<<storageVector[iterate].operand2<<endl;
				for(int strIterate=0;strIterate<10;strIterate++){
					if(strIterate<5)
					if(strcmp(storageVector[iterate].command,operandALU[strIterate])==0){	//Handling operation in ALU
						parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
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
					if(strcmp(storageVector[iterate].command,operandMain[strIterate])==0){	//Handling Operation in Main
						flag=1;
						switch(strIterate){
							//Handling LOAD
							case 0: /*if(isdigit(atoi(storageVector[iterate].operand1))){
									cout<<"LOAD First operand can't be Number";
									return;}*/ //For Handling integer in first operand
								parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
								operationExecute(op0,op1,LOAD);	
								cout<<"Array Element: ";
								for(int arrIterate=0;arrIterate<8;arrIterate++)
									cout<<reg.storage_array[arrIterate]<<" ";
								cout<<" Zero Flag: "<<aluObject.registers.z;
								cout<<" Greater Equal Flag: "<<aluObject.registers.ge;
								cout<<endl<<endl;
								break;
							//Handling JMP
							case 1: parse(storageVector[iterate].operand1,storageVector[iterate].operand2);													
								operationExecute(op0,op1,JMP);
								iterate=reg.pc-1;
								cout<<endl<<endl;
								break;
							//Handling JNZ
							case 2:	parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
								if(aluObject.registers.z==0) {							
									operationExecute(op0,op1,JNZ);
									iterate=reg.pc-1;
									cout<<endl<<endl;
									break;
								}
								else {
									cout<<"Skipped as Zero Flag is set"<<endl<<endl;	     									break;							
								}
							//Handling JZ	
							case 3: parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
								if(aluObject.registers.z==1) {							
									operationExecute(op0,op1,JZ);
									iterate=reg.pc-1;
									cout<<endl<<endl;	
									break;
								}
								else {
									cout<<"Skipped as Zero Flag is Not set"<<endl<<endl;	     									break;							
								}
							//Handling JGT	
							case 4: parse(storageVector[iterate].operand1,storageVector[iterate].operand2);					//aluObject.registers.ge==((1)^(aluObject.registers.z));
								if(aluObject.registers.ge==0) {							
									operationExecute(op0,op1,JGT);
									iterate=reg.pc-1;
									cout<<endl<<endl;	
									break;
								}
								else {
									cout<<"Skipped as Greater Equal Flag is Not set "<<endl<<endl;	     									break;							
								}
							//Handling JGE	
							case 5: parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
								if(aluObject.registers.ge==1) {							
									operationExecute(op0,op1,JGE);
									iterate=reg.pc-1;
									cout<<endl<<endl;
									break;
								}
								else {
									cout<<"Skipped as Greater Equal Flag is set"<<endl<<endl;	     									break;							
								}
							//Handling HALT	
							case 6: cout<<"HALT!! Program Aborted!!\n"; return;
							//Handling NOP
							case 7: break;
							//Handling COUT
							case 8: parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
								cout<<"Array Element at pos "<< op0RegAdr<<" :"<<reg.storage_array[op0RegAdr];
								cout<<endl<<endl;
								break;
							//Handling COUTALL
							case 9: parse(storageVector[iterate].operand1,storageVector[iterate].operand2);		
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
