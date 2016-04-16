#include <systemc.h>
#include "ALU.h"
#include "Combiner.hpp"
using namespace std;

SC_MODULE(SYSTEM){
ALU *alu1;
Combiner *combine;

sc_clock clksig;
sc_signal < bool > inp_vldsig;
sc_signal < bool > inp_rdysig;



sc_signal < Operation  > inp1_sig;
sc_signal < int* > inp2_sig;
sc_signal < int* > inp3_sig;


	SC_CTOR(SYSTEM)
	: clksig ("clksig",10,SC_NS)	
	{
	combine= new Combiner("COMBINING");
	combine->clk(clksig);
	combine->outp1(inp1_sig);
	combine->outp2(inp2_sig);
	combine->outp3(inp3_sig);
	combine->inp_vld(inp_vldsig);
	combine->inp_rdy(inp_rdysig);	
	

	alu1= new ALU("ALUREADY");
	alu1->clk(clksig);
	alu1->inp1(inp1_sig);
	alu1->inp2(inp2_sig);
	alu1->inp3(inp3_sig);
	alu1->inp_vld(inp_vldsig);
	alu1->inp_rdy(inp_rdysig);
	
	}




};





int sc_main (int argc, char* argv[]) {


SYSTEM s1("SYSTEM");
sc_start();
return 0;
        }



