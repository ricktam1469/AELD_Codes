
#include <systemc.h>
#include <iostream>
#include "TbCounter.hpp"


void tbCounter::display() {
  int i=0;

  reset.write(0);

  while(1){
  
wait();
 
 cout<<"@"<<sc_time_stamp()<<" Outputbig:"<<output.read()<<endl;
 
  
  }

}
