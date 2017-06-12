CC = g++
CFLAGS = -w -std=c++11 

game: main.o item.o game.o player.o map.o room.o menu.o
	$(CC) $(CFLAGS) -o game main.o item.o game.o player.o map.o room.o menu.o
	mv game ../

run: main.o item.o game.o player.o map.o room.o menu.o
	$(CC) $(CFLAGS) -o game main.o item.o game.o player.o map.o room.o menu.o
	mv game ../
	../game

clean :
	rm ../game
