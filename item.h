#ifndef ITEM_H
#define ITEM_H
#include <iostream>
class Item {
public:
	Item(int x, int y, std::string name);
	void setLocation(int x, int y);
	void getLocation();
	void setStats(int lit, int str, int thf, bool isKey);
	void setAllocated(int i) { this->allocated = i; }
	bool getAllocated() { return this->allocated; }
	bool isSameItem(Item i1, Item i2) { return i1.name == i2.name; }

private: 
	int lit, str, thf;
	int x, y;
	bool isKey;
	std::string name;
	bool allocated = 0;
	
};
#endif
