# Sans utilisation de la variable MAP :

CCFLAGS=-ansi -pedantic -Wall -std=c++11

# Avec utilisation de la variable MAP :

#CCFLAGS=-DMAP -ansi -pedantic -Wall -std=c++11

prog : Appli.o CollectionLog.o Flux.o Log.o
	g++ -o prog Appli.o CollectionLog.o Flux.o Log.o

Application.o : Appli.cpp
	g++ -c Appli.cpp -o Appli.o $(CCFLAGS)

CollectionLog.o : CollectionLog.cpp CollectionLog.h
	g++ -c CollectionLog.cpp -o CollectionLog.o $(CCFLAGS)

Flux.o : Flux.cpp Flux.h
	g++ -c Flux.cpp -o Flux.o $(CCFLAGS)

Log.o : Log.cpp
	g++ -c Log.cpp -o Log.o $(CCFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf prog

valgrind: prog
	valgrind --leak-check=full ./prog

run: prog
	./prog
