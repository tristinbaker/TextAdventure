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
    void equipItem(Item item, std::string tag);
	void deleteItem(int index);
    void getEquipment();
	void seeInventory();
	void setLocation(int x, int y);
	void getLocation();
	void setStats(int stat);
	void getStats();
    void setName(std::string name) { this-> name = name; }
    std::string getName() { return this->name; }
	void setRoom(Room * room);
	Room * getRoom() { return this->currRoom; }
	std::string getRoomName() { return this->currRoom->getRoomName(); }
	bool alive() { return this->healthPoints >= 0; }

private:
	Item inventory[128];
	Item equippedWeapon;
    Item equippedHelm;
    Item equippedChest;
    Item equippedPants;
    Item equippedGloves;
	Room * currRoom;
	int x, y;
	int literacyStat, strengthStat, thiefStat;	
	int healthPoints = 100;
	int maxHealth = 100;
    std::string name;

};
#endif
