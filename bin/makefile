CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -Wno-unused
CC = g++

analog:main.o Log.o Graphe.o HitCounter.o
	$(CC) -o $@ $^

main.o:main.cpp
	$(CC) -c $(CPPFLAGS) $<

Log.o:Log.cpp Log.h
	$(CC) -c $(CPPFLAGS) $<

Graphe.o:Graphe.cpp Graphe.h
	$(CC) -c $(CPPFLAGS) $<

HitCounter.o:HitCounter.cpp
	$(CC) -c $(CPPFLAGS) $<

clean:
	@rm -f *.out *.o
