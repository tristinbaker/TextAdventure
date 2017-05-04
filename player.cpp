#include "player.h"
#include "item.h"

#include <iostream>

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

void Player::seeInventory() {
	for(int i = 0; i < 128; i++) {
		if(this->inventory[i].getName() != "") {	
			std::cout << "Item " << i << ": " << this->inventory[i].getName() << std::endl;
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

void Player::seeStats() {

}

void Player::setStats(int stat) {

}

