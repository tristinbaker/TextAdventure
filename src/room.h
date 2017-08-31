#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "menu.h"
#include "item.h"

class Room {

public: 
	Room();	
	Room(bool hasLock, bool hasItem, bool hasEnemy, std::string name);
	~Room();	
	void determineLore();
	void setLore(std::string lore) { this->lore = lore; }
	void setLock(bool hasLock) { this->hasLock = hasLock; }
	void setItem(bool hasItem) { this->hasItem = hasItem; }
	void setEnemy(bool hasEnemy) { this->hasEnemy = hasEnemy; }
	void setBoss(bool hasBoss) { this->hasBoss = hasBoss; }
	void setName(std::string roomName) { this->roomName = roomName; } 
	std::string getRoomName() { return roomName; }
	std::string getLore() { return lore; }
	Item getItem() { return this->item; }
	bool containsItem() { return this->hasItem; }
    bool containsEnemy() { return this->hasEnemy; }
	void setItem(Item item) { this->item = item; }
    void setRoomAtExit(std::string direction, Room *room);

private: 	
	std::string lore;
	bool hasLock = false, hasItem = false;
	bool hasEnemy;
	bool hasBoss;
	std::string roomName;
	Item item;

    // North, south, east, west rooms
    Room *nRoom;
    Room *eRoom;
    Room *wRoom;
    Room *sRoom;
};
#endif
