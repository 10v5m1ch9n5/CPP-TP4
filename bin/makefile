CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -DDEBUG
CC = g++

analog:main.o
	$(CC) -o $@ $^

main.o:main.cpp

clean:
	@rm -f *.out *.o
