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
    void setLevel(int level) { this->level = level; }
    int  getLevel() { return this->level; }
    void setName(std::string name) { this->name = name; }
    std::string getName() { return this->name; }
    int getStr() { return this->strengthStat; }
	void setRoom(Room * room);
	Room * getRoom() { return this->currRoom; }
	std::string getRoomName() { return this->currRoom->getRoomName(); }
    void setCurrHP(int hp);
    void takeDamage(int hp);
    int getCurrHP() { return this->healthPoints; }
    int getMaxHP() { return this->maxHealth; }
	bool alive() { return this->healthPoints >= 0; }
    int determineDmg();
    void setPotionCount(int pc) { this->potionCount = pc; }
    int getPotionCount() { return this->potionCount; }
    void incrementPotionCount();
    void decrementPotionCount();
    bool hasPotion();

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
    int level = 1;
    int potionCount;
    std::string name;

};
#endif
