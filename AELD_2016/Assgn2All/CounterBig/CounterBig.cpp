#include "CounterBig.hpp"
#include <iostream>

void CounterBig ::counterBigFunc() {


  while (1) {
  	wait();
//cout<<"-->"<<c1.output.read()<<"------";
//cout<<"-->"<<c2.output.read()<<endl;
output=(c2.output.read(),c1.output.read());
    // output.write(value);
    // wait() ;
     //value++;
  }
}
