all: a.out

a.out: main.o vector.o
	g++ -std=c++17 -Wall -O3  main.o vector.o -o a.out
vector.o: vector.cpp vector.h
	g++ -std=c++17 -c vector.cpp
main.o: main.cpp
	g++ -std=c++17 -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
