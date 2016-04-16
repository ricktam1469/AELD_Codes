#include <systemc.h>
#include "counter.hpp"
#include "TbCounter.hpp"
#include "CounterBig.hpp"
 
SC_MODULE(SYSTEM){
	
	sc_signal<sc_uint<8> > counter;
	sc_signal<bool>   reset;
	sc_clock clk;
	
	tbCounter *tb0=NULL;
	CounterBig *cb=NULL;



	SC_CTOR(SYSTEM)
		:clk("clk", 10,SC_NS)
	{
		reset.write(1);
		
		tb0=new tbCounter("tb0");
		cb=new CounterBig("cb");
		
		tb0->clock (clk);
		tb0->reset(reset);
		tb0->output(cb->output);
		
		cb->clock(clk);
		cb->reset(reset);
		cb->output(counter);
		
		
	}
		
	~SYSTEM(){
		delete tb0;
		delete cb;
}


};

SYSTEM *sys=NULL;

int sc_main(int argc, char **argv){
	
	int put_time = 0;

	if (argc==2)
		put_time = atoi(argv[1]);

	if (put_time==0)
		put_time = 4000;

	sys=new SYSTEM("system");

	sc_start(put_time,SC_NS);

    return 0;// Terminate simulation
}

