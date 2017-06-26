#ifndef ITEM_H
#define ITEM_H
#include <iostream>
class Item {
public:
	Item();
	Item(std::string name);
    void setStats(int lit, int str, int thf, bool isKey, bool isWeapon, int defense, int hp);
	void setAllocated(int i) { this->allocated = i; }
	bool getAllocated() { return this->allocated; }
	bool isSameItem(Item i) { return this->name == i.name; }
	void deleteItem(Item item);
	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }
	int getLit() { return this->lit; }
	int getStr() { return this->str; }
	int getThf() { return this->thf; }
    int getHP() { return this->hp; }
    bool isAKey() { return this->isKey; }
    bool isAWeapon() { return this->isWeapon; }
    int getDef() { return this->defense; }

private: 
	int lit, str, thf;
    int defense;
    int hp;
	bool isKey, isWeapon;
	std::string name;
	bool allocated = 0;
	
};
#endif
