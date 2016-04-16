
#include <systemc.h>
#include <iostream>
#include "TbCounter.hpp"

void tbCounter::display() {
	
	reset.write(0);
 	
 	while(1){

    	wait();
  		cout<<"OutputBigCounter:"<<output.read()<<endl;
    }

}
