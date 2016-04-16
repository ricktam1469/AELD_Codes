"ALU.hpp' is the given basic class file which contains three classes with two different enumeration.

	Registers: Provide 16 Registers each od 32 bit wide and also contains Zero Flag, Greater Equal Flag and Program Counter

	ALU:It contains operands and execution of command ADD,SUB,MUL,DIV,CMP in a generic way.

	loadProgram: It contains the structure of Command M32 ,a vector which is a structure type,a constructor which open the ASCII 
	file and a function which reads the data from the file line by line and stores in a vector.

"ALU.cpp" contains Implemenntation of classes functions.

"main.cpp" contains main function for implementing the classes.Here I am asuming Registers R0 to R7 and Parsing R0 to R7 with 
character 'R' and the next value 0-7 will be used to access the storage registers.It can handle commands with one 
Operation(ADD,LOAD,JMP etc.) and 2 operands or 1 operands or no operands in a very generic way.All the operations are defined 
in character array which is then invoked using vector iterator and switch case by comapring the operation string with the 
operation invoked from the file.

"Makefile" contains compilation commands with proper comments.
