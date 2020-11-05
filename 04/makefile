all: a.out

a.out: main.o bigint.o
	g++ -Wall -O3  main.o bigint.o -o a.out
bigint.o: bigint.cpp bigint.h
	g++ -c bigint.cpp
main.o: main.cpp
	g++ -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
