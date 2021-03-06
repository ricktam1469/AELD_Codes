#include <systemc.h>
#include "nand.h"

SC_MODULE(xor2)
{
	sc_in<bool> a,b;
	sc_out<bool> f;
	nand2 n1,n2,n3,n4;
	sc_signal<bool> s1,s2,s3;

	SC_CTOR(xor2): n1("n1"),n2("n2"),n3("n3"),n4("n4")
	{		
		n1.a(a);
		n1.b(b);
		n1.f(s1);

		n2.a(a);
		n2.b(s1);
		n2.f(s2);

		n3.a(s1);
		n3.b(b);
		n3.f(s3);

		n4.a(s2);
		n4.b(s3);
		n4.f(f);

	}


};
