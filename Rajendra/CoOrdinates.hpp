#ifndef COORDINATES_H
#define COORDINATES_H
#include "systemc.h"

// CoOrdinates -- CoOrdinates definition
struct CoOrdinates {
	sc_uint<2> x_co;
	sc_uint<2> y_co;
	
	inline bool operator == (const CoOrdinates& src) const // arregment of flit elements
		{
			return (src.x_co == x_co && src.y_co == y_co);
		}
    };
#endif
