#include <systemc.h>

SC_MODULE(nand2){

	sc_in<bool> a,b;
	sc_out<bool> f;
	
	void func(){
		
		f.write( !(a.read() && b.read()) );			
	}
	
	SC_CTOR(nand2){
		SC_METHOD(func);
		sensitive<<a<<b;
	}
};
