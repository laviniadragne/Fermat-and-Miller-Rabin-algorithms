CC = g++
CFLAGS = -O0 -Wall -Wextra

all: build

run_tests: build
	./checker

build: algo1.o algo2.o checker.o
	g++ algo1.o algo2.o checker.o -o checker $(CFLAGS)

algo1.o: algo1.cpp
	g++ algo1.cpp -c $(CFLAGS)

algo2.o: algo2.cpp
	g++ algo2.cpp -c $(CFLAGS)	

checker.o: checker.cpp
	g++ checker.cpp -c $(CFLAGS)

clean:
	rm -rf *.o checker
