#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include "room.h"
class Player {

public: 
	Player(int x, int y);
	~Player();
	int findNextSlot(); 
	void giveItem(Item item);
	void takeItem(Item item);
	void seeInventory();
	void setLocation(int x, int y);
	void getLocation();
	void seeStats();
	void setStats(int stat);
	void deleteItem(int index);
	void setRoom(Room * room);
	Room * getRoom() { return this->currRoom; }
	std::string getRoomName() { return this->currRoom->getRoomName(); }
	bool alive() { return this->healthPoints >= 0; }

private:
	Item inventory[128];
	Item equippedItem;
	Room * currRoom;
	int x, y;
	int literacyStat, strengthStat, thiefStat;	
	int healthPoints = 100;
	int maxHealth = 100;

};
#endif
