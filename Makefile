game: main.cpp item.cpp game.cpp player.cpp map.cpp
	g++ -std=c++11 -o game main.cpp item.cpp game.cpp player.cpp map.cpp

clean :
	rm game
