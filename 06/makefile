all: a.out

a.out: main.o format.o
	g++ -std=c++17 -Wall -O3  main.o format.o -o a.out
format.o: format.cpp format.h
	g++ -std=c++17 -c format.cpp
main.o: main.cpp
	g++ -std=c++17 -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
