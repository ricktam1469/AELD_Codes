#ifndef COUNTERBIG_HPP
#define COUNTERBIG_HPP

#include <systemc.h>
#include "counter.hpp"

SC_MODULE( CounterBig ) {
	
	sc_in< bool > clock,reset;
	sc_out< sc_uint<8> > output;
	Counter c1,c2;

void counterBigFunc();

	SC_CTOR( CounterBig ): c1("counter1"),c2("counter2") {
		
    	SC_CTHREAD(counterBigFunc,clock.pos());
		reset_signal_is(reset,true);
	}
	
};

#endif   //COUNTERBIG_HPP
