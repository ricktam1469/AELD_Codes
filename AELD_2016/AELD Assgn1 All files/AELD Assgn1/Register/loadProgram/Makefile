#
# Makefile for Arithmetic Operation in assignment1
#
# Author: Ricktam
#

# Defining Variables
CC = g++
CFLAGS = -c -Wall -g

# Default Target
all: arithmetic

# $@ give the output file name same as target name (i.e arithmatic) and it is easy to clear all temporary files
# Generating all object files and Temporary files
arithmetic: main.o ALU.o
	@echo "Generating Output File.."
	$(CC) main.o ALU.o -o $@

# Compiling main.cpp file and $< gives the name of first dependency(i.e main.cpp)
main.o: main.cpp
	$(CC) $(CFLAGS) $<

# Compiling ALU.cpp
ALU.o: ALU.cpp
	$(CC) $(CFLAGS) $<

# Removing all temporary files from the directory
clear: 
	rm -rf *.o arithmetic
