#include "player.h"
#include "item.h"

#include <iostream>
#include <iomanip>

Player::Player(int x, int y) {
	this->x = x;
	this->y = y;
}

Player::~Player() {}

int Player::findNextSlot() {
	for(int i = 0; i < 128; i++) {
		if(this->inventory[i].getAllocated() == 0) {
			this->inventory[i].setAllocated(1);
			return i;
		} else {
			continue;	
		}
	}
	return -1;
}

void Player::giveItem(Item item) {
	int i = this->findNextSlot();
	this->inventory[i] = item;
}

void Player::takeItem(Item item) {
	Item findItem;
	for(int i = 0; findItem.getName() != item.getName(); i++) {
		findItem = this->inventory[i];
		if(findItem.isSameItem(item)) {
			deleteItem(i);
		} else {
			continue;
		}
	}
}

void Player::equipItem(Item item, std::string tag) {
    if(tag == "weapon") {
        this->equippedWeapon = item;
    } else if(tag == "helm") {
        this->equippedHelm = item;
    } else if(tag == "chest") {
        this->equippedChest = item;
    } else if(tag == "pants") {
        this->equippedPants = item;
    } else if(tag == "gloves") {
        this->equippedGloves = item;
    } else {
        std::cout << "Unable to equip item." << std::endl;
    }
}

void Player::getEquipment() {
    std::cout << std::setw(50) << std::setfill('-') << "-" << std::endl << std::setfill(' '); 
    std::cout << "| " << std::left << this->name << " |" << std::endl;
    std::cout << "| Weapon: " << std::left << this->equippedWeapon.getName() << " |" << std::endl;
    std::cout << "| Helmet: " << std::left << this->equippedHelm.getName() << " |" << std::endl;
    std::cout << "| Chest:  " << std::left << this->equippedChest.getName() << " |" << std::endl;
    std::cout << "| Gloves: " << std::left << this->equippedGloves.getName() << " |" << std::endl;
    std::cout << "| Pants:  " << std::left << this->equippedPants.getName() << " |" << std::endl;
    std::cout << std::setfill('-') << "-" << std::endl; 
}

void Player::seeInventory() {
	for(int i = 0; i < 128; i++) {
		if(this->inventory[i].getName() != "") {
			std::cout << "-----------------------------------" << std::endl;
			std::cout << "         | " << this->inventory[i].getName() << " |" << std::endl;
			std::cout << "| " << "Lit: " << this->inventory[i].getLit() << " | Str: " << 
				this->inventory[i].getStr() << " | Thf: " << this->inventory[i].getThf() << " |" << std::endl;
			std::cout << "-----------------------------------" << std::endl;	
		}
	}
}

void Player::deleteItem(int index) {
	for(int i = index; i < 128; i++) {
		if(i == 127) {
			this->inventory[i].setName("");
		} else {
			this->inventory[i] = this->inventory[i+1];
		}
	}	
} 

void Player::setLocation(int x, int y) {
			
}

void Player::getLocation() {	

}

void Player::getStats() {

}

void Player::setStats(int stat) {

}

void Player::setRoom(Room * room) {
	this->currRoom = room;
}

