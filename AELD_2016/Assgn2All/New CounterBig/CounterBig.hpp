#ifndef COUNTERBIG_HPP
#define COUNTERBIG_HPP

#include <systemc.h>
#include "counter.hpp"

SC_MODULE( CounterBig ) {
	
	sc_in< bool > clock,reset;
	sc_out< sc_uint<8> > output;
	sc_signal<bool> nor_sig;
	sc_signal<sc_uint<4> > countSig1,countSig2;
	Counter c1,c2;

void concatenate();
void clocking();

	SC_CTOR( CounterBig ): c1("counter1"),c2("counter2") {
		
		c1.output(countSig1);
		c1.clock(clock);
		c1.reset(reset);

		c2.output(countSig2);
		c2.clock(nor_sig);
		c2.reset(reset);

		SC_CTHREAD(concatenate,clock.pos());
		reset_signal_is(reset,true);

		SC_CTHREAD(clocking,clock.pos());
		reset_signal_is(reset,true);

	}
	
};

#endif   //COUNTERBIG_HPP
