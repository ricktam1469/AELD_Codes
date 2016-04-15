#include <systemc.h>
#include "NOC.hpp"
#include "loadProgram.hpp"

void NOC::execute(){

while( true ){
	
	inp_rdy.write(1);

	do{
	wait();
	} while(!inp_vld.read());

	p=input.read();
	cout<<"Packet ----> ";
	cout << *(p.value2) << " | " ;
	cout << *(p.value1) << " | " ;
	cout << p.xCoordinate << " | " ;
	cout << p.yCoordinate << " | " ;


	if (p.operation == ADD){
		cout << "Addition" <<endl ;
	}
	if (p.operation == SUB){
		cout << "Subtraction" <<endl ;
	}
	if (p.operation == MUL){
		cout << "Multiplication" <<endl ;
	}
	if (p.operation == DIV){
		cout << "Division" <<endl ;
	}
	inp_rdy.write(0);
	}


}
