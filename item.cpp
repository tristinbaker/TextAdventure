#include "item.h"
#include <iostream>

Item::Item() {}

Item::Item(int x, int y, std::string name) {
	this->x = x;
	this->y = y;
	this->name = name;
}

void Item::setLocation(int x, int y) {
	
}

void Item::getLocation() {

}

void Item::setStats(int lit, int str, int thf, bool isKey){
	this->lit = lit;
	this->str = str;
	this->thf = thf;
	this->isKey = isKey;
}

void Item::deleteItem(Item item) {
	item.setX(0);
	item.setY(0);
	item.setName("");
}


