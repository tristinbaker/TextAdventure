#include "item.h"
#include <iostream>

Item::Item() {}

Item::Item(std::string name) {
	this->name = name;
}

void Item::setStats(int lit, int str, int thf, bool isKey, bool isWeapon, bool isArmor, bool isConsumable, int defense, int hp) {
    this->lit = lit;
    this->str = str;
    this->thf = thf;
    this->isKey = isKey;
    this->isWeapon = isWeapon;
    this->isArmor = isArmor;
    this->isConsumable = isConsumable;
    this->defense = defense;
    this->hp = hp;
}

void Item::deleteItem(Item item) {
	item.setName("");
}


