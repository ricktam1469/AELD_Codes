#include "CounterBig.hpp"
#include <iostream>

void CounterBig ::concatenate() {

	wait(17);
  	while (1) {

  		wait();
		output=(c2.output.read(),c1.output.read());

  	}

}

void CounterBig ::clocking() {
  	
  	while(1){
  		wait();
  		nor_sig=and_reduce(countSig1);
  	
	}

  }