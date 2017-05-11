#include <iostream>
#include "room.h"
#include "player.h"
#ifndef MAP_H
#define MAP_H

class Map {

public: 
	Map();
	~Map();
	void setRoom(Room room, int vertIndex, int horizIndex) { this->rooms[vertIndex][horizIndex] = room; }
	void printMap(Player player);

private:
	Room rooms[10][10];
};
#endif
