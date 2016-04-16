#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <systemc.h>

SC_MODULE( Counter ) {
	
	sc_in< bool > clock,reset;
	sc_out< sc_uint<4> > output;
	
	void counterFunc();	//Function declaration for implementing counter

	SC_CTOR( Counter ) {
		
    		 SC_CTHREAD(counterFunc,clock.pos());
			 reset_signal_is(reset,true);
	}
	
};

#endif   //COUNTER_HPP
