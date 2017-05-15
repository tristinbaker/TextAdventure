#ifndef ITEM_H
#define ITEM_H
#include <iostream>
class Item {
public:
	Item();
	Item(std::string name);
	void setStats(int lit, int str, int thf, bool isKey);
	void setAllocated(int i) { this->allocated = i; }
	bool getAllocated() { return this->allocated; }
	bool isSameItem(Item i) { return this->name == i.name; }
	std::string getName() { return this->name; }
	void deleteItem(Item item);
	void setName(std::string name) { this->name = name; }
	int getLit() { return this->lit; }
	int getStr() { return this->str; }
	int getThf() { return this->thf; }

private: 
	int lit, str, thf;
	bool isKey;
	std::string name;
	bool allocated = 0;
	
};
#endif
