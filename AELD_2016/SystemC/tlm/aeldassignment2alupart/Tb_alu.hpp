#ifndef TB_ALU_HPP
#define TB_ALU_HPP

#include <systemc.h>

SC_MODULE(Tb_alu) {
	
	sc_in<bool> clk;
	sc_out< sc_uint<4> > a,b;
	sc_in< sc_uint<4> > output;
	sc_out< sc_uint<4> > operation;
	sc_in<bool> output_vld;
	sc_out<bool> output_rdy;
	sc_out<bool> inp_vld;
	sc_in<bool> inp_rdy;
	
	void source();	
	void sink();

	SC_CTOR(Tb_alu) {

	  SC_CTHREAD(source,clk.pos());	
	  SC_CTHREAD(sink,clk.pos());
	
	}
};

#endif
