#
# Makefile for assignment2 counterBig
#
#

# Defining Variables

CC = g++

#SYSTEMC_HOME=/opt/systemc-2.3.1
SYSTEMC_ARCH =linux

LIB_DIRS =$(SYSTEMC_HOME)/lib-$(SYSTEMC_ARCH)
INCLUDE_DIRS =-I. -I$(SYSTEMC_HOME)/include
PATH_DIRS = $(SYSTEMC_HOME)/lib-$(SYSTEMC_ARCH)
LIBS = -lsystemc -lstdc++ -lm

HEADERS = ALU.hpp
SOURCES = main.cpp ALU.cpp
DEPENDENCIES = \
		Makefile \
		$(HEADERS) \
		$(SOURCES) 


TESTS = main

all: $(TESTS)
	./$(TESTS)

$(TESTS) : $(DEPENDENCIES)
		$(CC) -g -o $@ $(SOURCES) $(INCLUDE_DIRS) -L. -L$(LIB_DIRS) -Wl,-rpath=$(PATH_DIRS) $(LIBS)

# Removing all temporary files from the directory
clean : 
	rm -f $(TESTS) *.dat 

