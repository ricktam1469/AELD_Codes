#ifndef ALU_HPP
#define ALU_HPP

#include <systemc.h>

SC_MODULE(ALU) {
	
	sc_in< sc_uint<4> > a,b;
	sc_out< sc_uint<4> > output;
	sc_in< sc_uint<4> > operation;
	sc_in<bool> clk;
	sc_out<bool> output_vld;
	sc_in<bool> output_rdy;
	sc_in<bool> inp_vld;
	sc_out<bool> inp_rdy;

	void ArithmeticFunc();

	SC_CTOR(ALU)
	{
	  SC_CTHREAD(ArithmeticFunc,clk.pos() );

	}
};

#endif
