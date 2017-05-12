#include <iostream>
#include "room.h"
#include "player.h"
#ifndef MAP_H
#define MAP_H

class Map {

public: 
	Map();
	~Map();
	void allocRoom(Room room, int vertIndex, int horizIndex) { this->rooms[vertIndex][horizIndex] = room; }
	void printMap(Player player);
	void setRoom(std::string roomName);
	Room getRoom() { return this->currRoom; }

private:
	Room rooms[10][10];
	Room currRoom;
};
#endif
