CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -Wno-unused
CC = g++

analog:main.o Log.o Graphe.o
	$(CC) -o $@ $^

main.o:main.cpp
Log.o:Log.h Log.cpp
Graphe.o:Graphe.h Graphe.cpp

clean:
	@rm -f *.out *.o
