#include "ALU.hpp"

void ALU::ArithmeticFunc() {

	sc_uint<4> temp_out;
	inp_rdy.write(1);

	do {
	    wait();
	   }while(!inp_vld.read() );

	inp_rdy.write(0);

	while(1){

cout<<operation.read()<<endl;
cout<<a.read()<<"<<--->>"<<b.read();
switch(operation.read()){

	case 0: wait(3);
		temp_out = a.read() + b.read();
		cout<<"--->"<<temp_out;
		break;
	case 1: wait(4);
		temp_out = a.read() - b.read();
		break;
	case 2: wait(119);
		if(b.read()==0){ cout<< "Math Error.."<<endl; }
		else
		temp_out = a.read() / b.read();
		break;
	case 3: wait(18);
		temp_out = a.read() * b.read();
		break;
	case 4: wait();
		temp_out = a.read() % b.read();
		if(temp_out>1) {
		cout<< "1st operand is greater: "<< a.read()<<endl;  }
		else if(temp_out<1) {
		cout<< "2nd operand is greater: "<< b.read()<<endl;  }
		else if(temp_out=1) {
		cout<< "operands are equal : "<< a.read()<<endl;  }
	default: wait();
		cout << "Any other Instruction..."<< endl;
		break;

}
	output_vld.write(1);

	do {
	    wait();
	    }while(!output_rdy.read() );

cout<<"---->>>>"<<temp_out;
	output.write(temp_out);
	wait();
	output_vld.write(0);

}//while close

} // ALUfun close
