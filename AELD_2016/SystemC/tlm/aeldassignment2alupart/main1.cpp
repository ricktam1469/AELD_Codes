#include<systemc.h>
#include "ALU.hpp"
#include "Tb_ALU.hpp"

SC_MODULE(SYSTEM){
	
	sc_signal<bool> reset_sig,en_sig;
	sc_signal< sc_uint<4> > output_sig;
	sc_signal<bool> output_vld_sig;
	sc_signal<bool> output_rdy_sig;
	sc_signal<bool> inp_vld_sig;
	sc_signal<bool> inp_rdy_sig; 
	sc_signal< sc_uint<4> > b_sig,a_sig;
	sc_signal< sc_uint<4> > op;
	sc_clock clok;
ALU *alu1;
Tb_alu *tb0;
	SC_CTOR(SYSTEM)
		:clok("clok",10,SC_NS)
	{
		alu1=new ALU("alu");
		tb0=new Tb_alu("ab0");
		
		alu1->a(a_sig);
		alu1->b(b_sig);
		alu1->output(output_sig);
		alu1->clk(clok);
		alu1->output_vld(output_vld_sig);
		alu1->output_rdy(output_rdy_sig);
		alu1->inp_vld(inp_vld_sig);
		alu1->inp_rdy(inp_rdy_sig);
		alu1->operation(op);

	
		tb0->a(a_sig);
		tb0->b(b_sig);		
		tb0->output(output_sig);
		tb0->clk(clok);
		tb0->output_vld(output_vld_sig);
		tb0->output_rdy(output_rdy_sig);
		tb0->inp_vld(inp_vld_sig);
		tb0->inp_rdy(inp_rdy_sig);
		tb0->operation(op);
		
		
	}
		
	~SYSTEM(){
		//delete tb0;
		//delete alu1;
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
	
