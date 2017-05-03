game: main.cpp item.cpp game.cpp player.cpp map.cpp
	g++ -std=c++11 -o game main.cpp item.cpp game.cpp player.cpp map.cpp

a: main.o item.o game.o player.o map.o
	g++ -std=c++11 -o game main.o item.o game.o player.o map.o

clean :
	rm game *.o
