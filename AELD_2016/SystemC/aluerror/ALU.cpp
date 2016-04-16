#include "ALU.hpp"

void ALU :: ALUfunc(){
	
	sc_int<4> op1n;
	sc_int<4> op2n;
	int opn ;

	inp_rdy.write(0);
	outp_vld.write(0);
	inp_rdy.write(1);
	do{wait();}while(!inp_vld.read());

	op1n = op1.read();
	op2n = op2.read();
	opn = op.read().to_int();

	inp_rdy.write(0);
	
	sc_int<8> answer;
	while(1)
	{
		//wait();
		switch(opn)
		{
			case 1 : //wait();
				cout<<"adding "<<op1n<<" and "<<op2n<<endl;
				wait(3);
				answer = op1n+op2n ; 
				break;
			case 2: //wait();
				cout<<"subtracting "<<op2n<<" by "<<op1n<<endl;
				wait(4);
				answer = op1n-op2n;
				break;
			case 3: //wait();
				cout<<"multiplying "<<op1n<<" and "<<op2n<<endl;
				wait(18);
				answer = op1n * op2n ;
				break;
			case 4: //wait();
				cout<<"dividing "<<op1n<<" by "<<op2n<<endl;
				wait(119);
				if(op2n == 0) {cout<<"cannot divide by zero!";}
				else { answer = op1n/op2n;}
				break;
			case 5: //wait();
				cout<<"comparing "<<op1n<<" and "<<op2n<<endl;
				wait();
				if(op1n>op2n){cout<<op1<<" is greater than "<<op2n; answer =1;}
				else{cout<<op1n<<" is smaller than "<<op2n; answer =0;}
				break;
			default: cout<<"other instructions"<<endl;
				 //wait();
				 answer = 0;
		}
	outp_vld.write(1);
	out.write(answer);
	do{ wait();} while( !outp_rdy.read() );
	outp_vld.write(0);
	}
}
