CXX = g++
CXXFLAGS = -std=c++11 -w

game: main.o item.o game.o player.o map.o room.o menu.o notebook.o enemy.o	
	$(CXX) $(CXXFLAGS) -o game main.o item.o game.o player.o map.o room.o menu.o notebook.o enemy.o
	mv game ../

run: main.o item.o game.o player.o map.o room.o menu.o notebook.o enemy.o	
	$(CXX) $(CXXFLAGS) -o game main.o item.o game.o player.o map.o room.o menu.o notebook.o enemy.o
	mv game ../
	../game

clean :
	rm ../game *.o
