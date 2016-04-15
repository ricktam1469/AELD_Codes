#ifndef NOC_H
#define NOC_H
#include <systemc.h>
#include "loadProgram.hpp"
#include "Packet.hpp"

 using namespace std;

SC_MODULE(NOC){

	sc_in < bool > clk;
	sc_in < bool > inp_vld;
	sc_out < bool > inp_rdy;
	sc_in < Packet > input;

	Packet p;
        void execute();
        
	SC_CTOR(NOC){

		SC_CTHREAD(execute,clk.pos()); 
	
	}
        
    };
#endif // NOC_H








