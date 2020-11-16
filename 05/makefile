all: a.out

a.out: main.o serializer.o
	g++ -Wall -O3  main.o serializer.o -o a.out
serializer.o: serializer.cpp serializer.h
	g++ -c serializer.cpp
main.o: main.cpp
	g++ -c main.cpp

test: a.out
	./a.out

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
