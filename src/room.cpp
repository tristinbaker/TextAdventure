#include "room.h"

Room::Room() {}

Room::Room(bool hasLock, bool hasItem, bool hasEnemy, std::string roomName) {
	setLock(hasLock);
	setItem(hasItem);
	setEnemy(hasEnemy);
	setName(roomName);
	determineLore();
}

void Room::determineLore() {
	if(this->roomName == "START") {
		if(this->hasItem) {
			this->lore = 
				" You wake up in a dark room. You look around and jot down what you see in your notebook.\n";
		} else {
			this->lore = 
				"You've picked up a rusty sword. What do you do now?\n";
		}
	} else if(this->roomName == "ARTIE") {
		this->lore = "  In ARTIE.\n";
	}
}

Room::~Room() {}

void Room::setRoomAtExit(std::string direction, Room *room) {
    if(direction == "north") {
        room = this->nRoom;
    } else if(direction == "south") {
        room = this->sRoom;
    } else if(direction == "west") {
        room = this->wRoom;
    } else if(direction == "east") {
        room = this->eRoom;
    } else {
        std::cout << "Invalid room." << std::endl;
    }

}
