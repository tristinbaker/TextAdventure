#include <iostream>
#ifndef MAP_H
#define MAP_H

class Map {

public: 
	Map();
	~Map();
	void setRoom(std::string lore, std::string special[5], bool hasLock, bool hasItem);
			

private:
	int map[30][30]; 
	std::string lore;
	std::string special[5];
	bool hasLock = false, hasItem = false;
};
#endif
