#ifndef LP_HPP
#define LP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include <systemc.h>
#include "reg.hpp"
#include "ALU.hpp"

SC_MODULE(loadProgram){
	sc_in<bool> clock;
	ifstream file;
	struct commandM32 {
		char* command;
		char* operand1;
		char* operand2;
	}objcommandM32;
	
	vector<commandM32> storageVector;	//Structured type vector
	void fileReading();	//Reading the file and store in a vector 
	ALU aluObject;
	Register reg;
	SC_CTOR(loadProgram):reg("register"),aluObject("ALU"){ 
/*
 * Reading all values form file line by line and storing in a vector of structure type
 *
 */
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
	~loadProgram(){
	file.close();
	}		
	
		

};
#endif