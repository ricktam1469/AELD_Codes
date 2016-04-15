#include <systemc.h>
#include "NOC.hpp"
#include "Integrate.hpp"

using namespace std;

SC_MODULE(SYSTEM)
{
	NOC *networkOnChip;
	Integrate *integrate;
	sc_clock clksig;
	sc_signal < bool > inp_vldsig;
	sc_signal < bool > inp_rdysig;

	sc_signal <Packet> inputsig;

	SC_CTOR(SYSTEM)	: clksig ("clockSignal",10,SC_NS)	
	{

		integrate=new Integrate("Integrating");
		integrate->clk(clksig);
		integrate->output(inputsig);
		integrate->inp_vld(inp_vldsig);
		integrate->inp_rdy(inp_rdysig);

		networkOnChip= new NOC("NOC");
	       	networkOnChip->clk(clksig);
	  	networkOnChip->input(inputsig);
		networkOnChip->inp_vld(inp_vldsig);
		networkOnChip->inp_rdy(inp_rdysig);

	}



};

int sc_main (int argc, char* argv[]) {

	SYSTEM s1("SYSTEM");
	sc_start();
	return 0;
}
