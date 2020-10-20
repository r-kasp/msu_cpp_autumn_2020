all: a.out

a.out: main.o parser.o
	g++ -Wall -O3  main.o parser.o -o a.out
parser.o: parser.cpp parser.h
	g++ -c parser.cpp
main.o: main.cpp
	g++ -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
