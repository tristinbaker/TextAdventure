#ifndef ROOM_H
#define ROOM_H
#include <iostream>

class Room {

public: 
	Room();	
	Room(std::string lore, bool hasLock, bool hasItem, bool hasEnemy, std::string name);
	~Room();	
	void setLore(std::string lore) { this->lore = lore; }
	void setLock(bool hasLock) { this->hasLock = hasLock; }
	void setItem(bool hasItem) { this->hasItem = hasItem; }
	void setEnemy(bool hasEnemy) { this->hasEnemy = hasEnemy; }
	void setBoss(bool hasBoss) { this->hasBoss = hasBoss; }
	void setName(std::string roomName) { this->roomName = roomName; } 
	std::string getName() { return roomName; }

private: 	
	std::string lore;
	std::string special[5];
	bool hasLock = false, hasItem = false;
	bool hasEnemy;
	bool hasBoss;
	std::string roomName;
};
#endif
