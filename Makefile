# Filename: Makefile
# Authors: Moiz Qureshi, Ye Huang, Eduardo Rosales
# Description: Beeth9 Assembler C++ Makefile
# Date: 11/9/16

# Use g++ compiler
CC=g++

# Include debugging symbols in object files
# Enable all warnings
# Use C++11 Standard
CXXFLAGS=-gdwarf-3 -Wall -std=c++11 -g

# Include debugging symbols in executable
LDFLAGS=-g


# Main target to compule Beeth9 Assembler
all: Beeth9Asm

Beeth9Asm: Beeth9Asm.o Parser.o

Parser.o: Parser.hpp

# Clean/Remove all object files
clean: 
	rm -rf Beeth9Asm *.o 
