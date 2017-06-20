#include "item.h"
#include <iostream>

Item::Item() {}

Item::Item(std::string name) {
	this->name = name;
}

void Item::setStats(int lit, int str, int thf, bool isKey, int defense) {
    this->lit = lit;
    this->str = str;
    this->thf = thf;
    this->isKey = isKey;
    this->defense = defense;
}

void Item::deleteItem(Item item) {
	item.setName("");
}


