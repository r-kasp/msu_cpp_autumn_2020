All: a.out

a.out: unit_tests.o allocator.o
	g++ -Wall -O3  unit_tests.o allocator.o -o a.out
allocator.o: allocator.cpp allocator.h
	g++ -c allocator.cpp
unit_tests.o: unit_tests.cpp
	g++ -c unit_tests.cpp

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
