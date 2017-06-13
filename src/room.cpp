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
				"  Your head throbs, your body aches, as you slowly come to. You don't remember what happened before you fell asleep and as \n";
			this->lore += 
				"you open your eyes you realize that you have no idea where you are. The air was heavy with moisture and smelled of mold \n";
			this->lore += 
				"and in the distance you could hear water dripping onto the stone floor, echoing through the barely illuminated hallway \n";
			this->lore += 
				"to your left. As you take a moment to collect yourself you realize that you are in a square room, made entirely of grey \n";
			this->lore += 
				"stone bricks, with three altar like slabs against the walls. As you shuffle and get your bearings you realize that you \n";
			this->lore +=
				"were laid upon one of these slabs, stripped of all possessions.\n \n  Faintly from the hall you hear what sounds like a scream.";
			this->lore +=
				" You realize then that you are not in a safe place and you \nstrain your eyes to search the room you are in for some sort of";
			this->lore +=
				" weapon. It is at this point you take note of the skeletal \nremains at the center of the room and as you rise to inspect you"; 
			this->lore +=
				" realize that this unfortunate warrior grasped a rusted-out \nsword. Dull as it may be, it would be wise to take it. As you scan";
			this->lore +=
				" the rest of the room you notice two other bodies on the other\nslabs. Will you investigate these bodies or will you begin your escape?\n";
		} else {
			this->lore = 
				"You've picked up a rusty sword. What do you do now?\n";
		}
	} else if(this->roomName == "ARTIE") {
		this->lore = "  In ARTIE.\n";
	}
}

Room::~Room() {}
