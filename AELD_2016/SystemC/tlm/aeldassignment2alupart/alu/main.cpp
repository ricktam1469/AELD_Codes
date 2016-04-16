#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include "ALU.hpp"
#include "reg.hpp"
#include "lp.hpp"

using namespace std;

/*
 * Calling all functions in main and File Handling
 *
 */
SC_MODULE(SYSTEM){
ALU *alu1;
loadProgram *lp;

sc_clock clksig;
sc_signal < bool > inp_vldsig;
sc_signal < bool > inp_rdysig;



sc_signal < Operation  > inp1_sig;
sc_signal < int* > inp2_sig;
sc_signal < int* > inp3_sig;


	SC_CTOR(SYSTEM)
	: clksig ("clksig",10,SC_NS)	
	{
	lp= new loadProgram("loadProgram");
	lp->clock(clksig);
	/*lp->outp1(inp1_sig);
	lp->outp2(inp2_sig);
	lp->outp3(inp3_sig);
	lp->inp_vld(inp_vldsig);
	lp->inp_rdy(inp_rdysig);*/	
	

	alu1= new ALU("ALUREADY");
	alu1->clock(clksig);
	/*alu1->inp1(inp1_sig);
	alu1->inp2(inp2_sig);
	alu1->inp3(inp3_sig);
	alu1->inp_vld(inp_vldsig);
	alu1->inp_rdy(inp_rdysig);*/
	
	}




};





int sc_main (int argc, char* argv[]) {


SYSTEM s1("SYSTEM");
sc_start();
return 0;
        }

