#include "room.h"

Room::Room() {}

Room::Room(std::string lore, bool hasLock, bool hasItem, bool hasEnemy, std::string roomName) {
	setLore(lore);
	setLock(hasLock);
	setItem(hasItem);
	setEnemy(hasEnemy);
	setName(roomName);
}

Room::~Room() {}
