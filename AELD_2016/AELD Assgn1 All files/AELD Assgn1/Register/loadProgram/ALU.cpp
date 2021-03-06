#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>  
#include "ALU.hpp"

ALU::ALU(Registers reg) {
	registers=reg;
	register_location=registers.storage_array;
}

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

loadProgram::loadProgram(char *filename) {
	file.open(filename, ios::in);
}

/*
 * Reading all values form file line by line and storing in a vector of structure type
 *
 */
void loadProgram::fileReading(){
			
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

