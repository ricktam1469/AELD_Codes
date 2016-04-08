#ifndef FLIT_H
#define FLIT_H

#include "CoOrdinates.hpp"
// Flit -- Flit definition
struct Flit {
	CoOrdinates source_id;
	CoOrdinates destination_id;
	sc_int<24> data;
	inline bool operator== (const Flit &flit) const
	{
		return(flit.source_id==source_id && flit.destination_id=destination_id && flit.data= data);
	}
	
    };
#endif
