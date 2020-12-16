all: a.out

a.out: main.o thread.o
	g++ -std=c++17 -Wall -O3 -pthread main.o thread.o -o a.out
thread.o: thread.cpp thread.h
	g++ -std=c++17 -c thread.cpp
main.o: main.cpp
	g++ -std=c++17 -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
