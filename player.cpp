#include "player.h"
#include "item.h"

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
	findItem = this->inventory[0];
	for(int i = 0; findItem.getName() != item.getName(); i++) {
		if(findItem.isSameItem(item)) {
			this->inventory[i].setAllocated(0);
		} else {
			findItem = this->inventory[i];
		}
	}
}

void Player::seeInventory() {

}

void Player::setLocation(int x, int y) {
			
}

void Player::getLocation() {	

}

void Player::seeStats() {

}

void Player::setStats(int stat) {

}
