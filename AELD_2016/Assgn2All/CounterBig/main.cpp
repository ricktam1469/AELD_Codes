#include <systemc.h>
#include "counter.hpp"
#include "TbCounter.hpp"
#include "CounterBig.hpp"
 
SC_MODULE(SYSTEM){
	sc_signal<sc_uint<4> > counter1,counter2;
	sc_signal<sc_uint<8> > counter;
	sc_signal<bool>   reset;
	sc_clock clk,clk1;
	sc_uint<4> x;
	sc_uint<4> y;
	sc_uint<8> z;
	tbCounter *tb0=NULL;
	CounterBig *cb=NULL;



	SC_CTOR(SYSTEM)
		:clk("clk", 10,SC_NS), clk1("clk1",160,SC_NS)
	{
		reset.write(1);
		
		tb0=new tbCounter("tb0");
		cb=new CounterBig("cb");
		
		tb0->clock (clk);
		tb0->reset(reset);
		tb0->output(cb->output);
		
		cb->c1.output(counter1);
		
		cb->c2.output(counter2);
		
		cb->c1.clock(clk);
		
		cb->c2.clock(clk1);
		
		cb->c1.reset(reset);
		
		cb->c2.reset(reset);
		
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
	
	sys=new SYSTEM("sys");

	sc_start(4000,SC_NS);

    return 0;// Terminate simulation
}

