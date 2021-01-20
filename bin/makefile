CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -Wno-unused
CC = g++

analog:main.o Log.o
	$(CC) -o $@ $^

main.o:main.cpp
Log.o:Log.h Log.cpp

clean:
	@rm -f *.out *.o
