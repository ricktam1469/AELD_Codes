#ifndef TBCOUNTER_HPP
#define TBCOUNTER_HPP

#include <systemc.h>

SC_MODULE( tbCounter ) {
	
	sc_in< bool > clock;
	sc_out<bool> reset;
	sc_in < sc_uint<8> > output;
	

	void display();

	SC_CTOR( tbCounter ) {

		SC_CTHREAD(display,clock.pos());
		reset_signal_is(reset,true);
	}
};

#endif //TBCOUNTER_HPP
