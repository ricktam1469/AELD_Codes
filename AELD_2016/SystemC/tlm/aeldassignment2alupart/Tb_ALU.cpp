#include "Tb_ALU.hpp"
#include <iostream>

void Tb_alu::source() {
int i=0;
	sc_int<4> temp1,temp2;
	sc_uint<1> temp3;

	while(1){
		wait();
	
	inp_vld.write(1);

	a.write(10);
	b.write(5);
	operation.write(2);
	wait();
	operation.write(3);
i++;
	do{
	   wait();
	  }while(!inp_rdy.read() );
	inp_vld.write(0);
}
}//source close

void Tb_alu::sink() {

	sc_int<4> indata;
while(1){
	wait();
	output_rdy.write(1);
	do {
	    wait();
	   }while(!output_vld.read() );		
	indata = output.read();
	cout<<"OUTPUT: "<<indata.to_int()<<endl;
	output_rdy.write(0);
	}

}// sink close
