#include <systemc.h>
#include "ALU.hpp"
#include "tbALU.hpp"


SC_MODULE(SYSTEM){

	tbALU *tbALU0=NULL;
	ALU *ALU0=NULL;
	
	sc_clock clk_sig;
	sc_signal < sc_int<4> > op1_sig,op2_sig;
	sc_signal < sc_uint<4> > op_sig;
	sc_signal < sc_int<8> > out_sig;
	sc_signal <bool> inp_vld_sig;
	sc_signal <bool> inp_rdy_sig;
	sc_signal <bool> outp_rdy_sig;
	sc_signal <bool> outp_vld_sig;

	SC_CTOR(SYSTEM):clk_sig("clk_sig", 10, SC_NS)
	{
		tbALU0 = new tbALU("tbALU0");
		tbALU0 -> clk(clk_sig);
		tbALU0 -> op1(op1_sig);
		tbALU0 -> op2(op2_sig);
		tbALU0 -> op(op_sig);
		tbALU0 -> out(out_sig);
		tbALU0 -> inp_vld(inp_vld_sig);
		tbALU0 -> inp_rdy(inp_rdy_sig);
		tbALU0 -> outp_vld(outp_vld_sig);
		tbALU0 -> outp_rdy(outp_rdy_sig);
		
		
		ALU0 = new ALU("ALU0");
		ALU0 -> clk(clk_sig);
		ALU0 -> op1(op1_sig);
		ALU0 -> op2(op2_sig);
		ALU0 -> op(op_sig);
		ALU0 -> out(out_sig);
		ALU0 -> inp_vld(inp_vld_sig);
		ALU0 -> inp_rdy(inp_rdy_sig);
		ALU0 -> outp_vld(outp_vld_sig);
		ALU0 -> outp_rdy(outp_rdy_sig);
	}
	
	~SYSTEM()
	{
		delete tbALU0;
		delete ALU0;
	}
};

SYSTEM *top = NULL;

int sc_main(int argc, char* argv[])
{
	top = new SYSTEM ("top");
	sc_start(400,SC_NS);
	return 0;
}

