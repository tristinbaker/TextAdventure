#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include "room.h"
#include <memory>
class Player {

public: 

    // Player initialization functions
	Player(int x, int y);
	~Player();

    // Inventory functions
	int findNextSlot(); 
	void giveItem(Item item);
	void takeItem(Item item);
    void equipItem(Item item, std::string tag);
	void deleteItem(int index);
    void getEquipment();
	void seeInventory();

    // Setters
	void setLocation(int x, int y);
	void setStats(int stat);
    void setLevel(int level) { this->level = level; }
    void setName(std::string name) { this->name = name; }
    void setStr(int str) { this->strengthStat = str; }
    void setThf(int thf) { this->thiefStat = thf; }
    void setLit(int lit) { this->literacyStat = lit; }
    void setPlayerClass(std::string playerClass) { this->playerClass = playerClass; }
    void assignClassStats(std::string playerClass);
    void setInitialEquipment();

    // Getters 
	void getLocation();
	void getStats();
    std::string askForPlayerName();
    void askForPlayerClass();
    int  getLevel() { return this->level; }
    std::string getName() { return this->name; }
    int getStr() { return this->strengthStat; }
    int getThf() { return this->thiefStat; }
    int getLit() { return this->literacyStat; }
    int getEXP() { return this->exp; }
    std::string getPlayerClass() { return this->playerClass; }

    // Location Functions
	void setRoom(Room * room);
	Room * getRoom() { return this->currRoom; }
	std::string getRoomName() { return this->currRoom->getRoomName(); }

    // Potion Functions
    void setPotionCount(int pc) { this->potionCount = pc; }
    int getPotionCount() { return this->potionCount; }
    void incrementPotionCount();
    void decrementPotionCount();
    bool hasPotion();
    int potionIndex();
    void removePotion(int i);

    // Battle functions
    void healHP(int hp);
    void takeDamage(int hp);
    int getCurrHP() { return this->healthPoints; }
    int getMaxHP() { return this->maxHealth; }
	bool alive() { return this->healthPoints >= 0; }
    int determineDmg();
    void gainEXP(int exp);


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
    int exp = 0;
    int potionCount;
    std::string name;
    std::string playerClass;

};
#endif
