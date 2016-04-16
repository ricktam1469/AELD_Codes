#ifndef TBALU_HPP
#define TBALU_HPP
#include <systemc.h>

SC_MODULE(tbALU)
{
	sc_in <bool> clk ;
	sc_out < sc_int<4> > op1,op2;
	sc_out < sc_uint<4> > op;
	sc_in < sc_int<8> > out;
	sc_out <bool> inp_vld, outp_rdy;
	sc_in <bool> inp_rdy, outp_vld;

	void source();
	void sink();
	SC_CTOR(tbALU)
	{
		SC_CTHREAD (source, clk.pos());
		SC_CTHREAD (sink, clk.pos());
	}

};
#endif
