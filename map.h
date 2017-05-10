#include <iostream>
#include "room.h"
#ifndef MAP_H
#define MAP_H

class Map {

public: 
	Map();
	~Map();
	void setRoom(Room room, int vertIndex, int horizIndex) { this->rooms[vertIndex][horizIndex] = room; }
	void printMap();

private:
	Room rooms[10][10];
};
#endif
