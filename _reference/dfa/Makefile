# Makefile for DFA

all: builddir dfa
clean:
	rm -rf dfa build

dfa: src/dfa-main.cpp build/dfa.o
	g++ src/dfa-main.cpp build/dfa.o -o dfa
build/dfa.o: src/dfa.h src/dfa.cpp
	g++ -c src/dfa.cpp -o build/dfa.o
builddir:
	rm -rf build
	mkdir build
