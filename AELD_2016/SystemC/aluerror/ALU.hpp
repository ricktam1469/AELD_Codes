#ifndef ALU_HPP
#define ALU_HPP
#include <systemc.h>

SC_MODULE(ALU){
	sc_in <bool> clk ;
	sc_in< sc_int<4> > op1,op2;
	sc_in < sc_uint<4> > op;
	sc_out < sc_int<8> > out;
	sc_in <bool> inp_vld, outp_rdy;
	sc_out <bool> inp_rdy, outp_vld;
	
	void ALUfunc();

	SC_CTOR(ALU) {

		SC_CTHREAD (ALUfunc, clk.pos());
	}
};
#endif
