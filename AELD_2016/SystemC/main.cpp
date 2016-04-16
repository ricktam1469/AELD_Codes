#include <systemc.h>
#include "xor.h"
#include "tb.h"

SC_MODULE(SYSTEM){

	tb *tb0;
	xor2 *xor0;
	sc_signal<bool> a_sig,b_sig,c_sig;
	 
	
	SC_CTOR(SYSTEM){
		tb0=new tb("tb0");
		xor0=new xor2("xor0");
		
		tb0->a(a_sig);
		tb0->b(b_sig);
		tb0->f(c_sig);
		
		xor0->a(a_sig);
		xor0->b(b_sig);
		xor0->f(c_sig);
	}
	
	~SYSTEM(){
		delete tb0;
		delete xor0;
	}


};

SYSTEM *sys=NULL;

int sc_main(int argc, char **argv){
	sys=new SYSTEM("sys");
	sc_start();
	return 0;
}

