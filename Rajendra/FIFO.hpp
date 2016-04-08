#ifndef FIFO_HPP
#define FIFO_HPP
#include "Flit.hpp"
#include "sytsemc.h"

struct FIFO{

	Flit memory[10];
	bool full;
	bool empty;
	int count_flits;
	FIFO()
	{
		full=false;
		empty=true;
		count_flits=0;
	}
	void input_Flit(const Flit& flit)	//input the flits to the buffer
	{
		if(full==true)
		{
			cout<<"The Buffer is full"<,endl;
		}
		else
		{
			count_flits=count_flits+1;
			memory[count_flits]==flit;
			if(count_flits !=0)
			{
				empty=false;
			}
			if(count_flits==10)
			{
				full==true;
			}

		}
	}
	Flit output_Flit()	//output the flit from the buffer
	{
		if(empty==true)
		{
			cout<<"The Buffer is empty"<,endl;
		}
		else
		{
			Flit temp=memory[0];
			
			for(int i=1;i<=count_flits;i++)
			{
				memory[i-1]=memory[i];
			}			
			count_flits=count_flits-1;
			if(count_flits ==0)
			{
				empty=true;
			}
			if(count_flits!=10)
			{
				full==false;
			}

		}
	}
	bool isempty()			//Check whether the FIFO is Empty or not
		{
			if(empty==true)
				{return true;}
			return false;
		}
	bool isfull()			//Check whether the FIFO is Full or not
		{
			if(full==true)
				{return true;}
			return false;
		}
	int FlitsinFIFO()		//Check the Current size of the FIFO 
		{
			return count_flits;
		}
};

#endif
