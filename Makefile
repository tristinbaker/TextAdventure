game: main.cpp item.cpp game.cpp player.cpp map.cpp room.cpp menu.cpp
	g++ -std=c++11 -g -o game main.cpp item.cpp game.cpp player.cpp map.cpp room.cpp menu.cpp

run: 
	g++ -std=c++11 -o game main.cpp item.cpp game.cpp player.cpp map.cpp room.cpp
	./game

clean :
	rm game
