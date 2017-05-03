#ifndef ITEM_H
#define ITEM_H
#include <iostream>
class Item {
public:
	Item();
	Item(int x, int y, std::string name);
	void setLocation(int x, int y);
	void getLocation();
	void setStats(int lit, int str, int thf, bool isKey);
	void setAllocated(int i) { this->allocated = i; }
	bool getAllocated() { return this->allocated; }
	bool isSameItem(Item i) { return this->name == i.name; }
	std::string getName() { return this->name; }

private: 
	int lit, str, thf;
	int x, y;
	bool isKey;
	std::string name;
	bool allocated = 0;
	
};
#endif
