#include "map.h"

Map::Map() {}
Map::~Map() {}

void Map::setRoom(std::string lore, std::string special[5], bool hasLock, bool hasItem) {
	this->lore = lore;
	for(int i = 0; i < 5; i++) {
		this->special[i] = special[i];
	}
	this->hasLock = hasLock;
	this->hasItem = hasItem;	
}

