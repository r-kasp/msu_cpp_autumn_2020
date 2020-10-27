all: a.out

a.out: main.o matrix.o
	g++ -Wall -O3  main.o matrix.o -o a.out
matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp
main.o: main.cpp
	g++ -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
