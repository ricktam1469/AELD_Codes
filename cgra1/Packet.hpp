#ifndef PACKET_HPP
#define PACKET_HPP

#include <systemc.h>
#include "loadProgram.hpp"

// Packet -- Packet definition

class Packet {
  public:
    int xCoordinate;
    int yCoordinate;
    int *value1;
    int *value2;
    Operation operation;
    bool flagForCheck;
    
  public:

    // constructor
    Packet (int xCoordinate_ = 0, int yCoordinate_ =0,int *value1_ = 0,int *value2_ = 0, Operation operation_ = SUB ,bool flagForCheck_ = false) {
	xCoordinate = xCoordinate_ ;
	yCoordinate = yCoordinate_ ;
      	value1 = value1_;
      	value2 = value2_;
      	flagForCheck = flagForCheck_;
      	operation = operation_;
    }

    inline bool operator == (const Packet & rhs) const {
      return (rhs.xCoordinate == xCoordinate && rhs.yCoordinate == yCoordinate && rhs.value1 == value1 && rhs.value2 == value2 && rhs.operation == operation && rhs.flagForCheck == flagForCheck);
    }

    inline Packet& operator = (const Packet& rhs) {
      xCoordinate = rhs.xCoordinate;
      yCoordinate = rhs.yCoordinate;
      value1 = rhs.value1;
      value2 = rhs.value2;
      operation = rhs.operation;
      flagForCheck = rhs.flagForCheck;
      return *this;
    }

    inline friend void sc_trace(sc_trace_file *tf, const Packet & v, const std::string & NAME ) {
	sc_trace(tf,v.xCoordinate, NAME + ".xCoordinate");
	sc_trace(tf,v.yCoordinate, NAME + ".yCoordinate");	
        sc_trace(tf,v.value1, NAME + ".value1");
        sc_trace(tf,v.value2, NAME + ".value2");
        sc_trace(tf,v.operation, NAME + ".operation");
        sc_trace(tf,v.flagForCheck, NAME + ".flagForCheck");
    }

    inline friend ostream& operator << ( ostream& os,  Packet const & v ) {
      os << "(" << v.xCoordinate << v.yCoordinate << v.value1 << v.value2 << v.operation << "," << std::boolalpha << v.flagForCheck << ")";
      return os;
    }

};
#endif

