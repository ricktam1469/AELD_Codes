#include "tbALU.hpp"

void tbALU :: source()
{	
	int x=0;
	inp_vld.write(0);

	for(int i=0; i<10 ; i++)
	{	

		x++;
		inp_vld.write(1);
		op1.write(x+5);
		op2.write(x*2+1);
		op.write(x);
		do{wait();}while(!inp_rdy.read());
		inp_vld.write(0);
	}		
};

void tbALU :: sink()
{
	int display_answer ;
	outp_rdy.write(0);
	for(int i=0; i<10 ; i++)	
	{
		outp_rdy.write(1);
		do{wait();}while(!outp_vld.read());
		display_answer = out.read().to_int();
		outp_rdy.write(0);
		cout<<sc_time_stamp()<<"\t"<<"answer :\t"<<display_answer<<endl;
	}
	sc_stop();
};
