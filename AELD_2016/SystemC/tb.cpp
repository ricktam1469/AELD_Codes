#include <systemc.h>
#include <iostream>
#include "tb.h"

void tb::inp(){


	a.write(false);
	b.write(false);
	cout<<"a1 "<<a<<endl;
	cout<<"b1 "<<b<<endl;
	cout<<"f "<<f<<endl;
	wait();	
	a.write(true);
	b.write(false);
cout<<"a2 "<<a<<endl;
	cout<<"b2 "<<b<<endl;
	cout<<"f "<<f<<endl;
	wait();	
	a.write(false);
	b.write(true);
cout<<"a3 "<<a<<endl;
	cout<<"b3 "<<b<<endl;
	cout<<"f "<<f<<endl;
	wait();	
	a.write(true);
	b.write(true);
cout<<"a4 "<<a<<endl;
	cout<<"b4 "<<b<<endl;
	cout<<"f "<<f<<endl;
	wait();	

	
}


void tb::outp(){

	
	sc_int<1> fout;
	int i=0;
	while(1){
		i++;
		cout<<i<<" : "<<f.read()<<endl;
		
	wait();
}
	sc_stop();
}
