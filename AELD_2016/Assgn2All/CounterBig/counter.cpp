#include "counter.hpp"
#include <iostream>

void Counter::counterFunc( ) {

sc_uint<4> value = 0;	//Assigning the value to 0 initially


  while (1) {

     output.write(value);
     wait() ;
     value++;
  }
}
