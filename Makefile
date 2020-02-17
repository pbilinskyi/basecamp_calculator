CXX = g++
CXXFLAGS = -Wall -g
objects = main.o Calc.o

calc: main.o Calc.o
	$(CXX) $(CXXFLAGS) -o calc main.o Calc.o

main.o: main.cpp Calc.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Calc.o: Calc.h

.PHONY : clean
clean :
	-rm calc $(objects)