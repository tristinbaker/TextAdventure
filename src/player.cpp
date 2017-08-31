#include "player.h"
#include "item.h"

#include <iostream>
#include <random>
#include <iomanip>
#include <memory>

Player::Player(int x, int y) {
	this->x = x;
	this->y = y;
    this->exp = 0;
}

Player::~Player() {}

int Player::findNextSlot() { 
    for(int i = 0; i < 128; i++) {
        //std::cout << this->inventory[i].getName() << " is allocated to: " << this->inventory[i].getAllocated() << std::endl;
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
    this->inventory[i].setAllocated(1);
}

void Player::takeItem(Item item) {
	Item findItem = this->inventory[0];
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
   
    // Weapon information
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Weapon: " << std::setw(15) << std::left << this->equippedWeapon.getName()  
        << " |" << " Strength: " << std::setw(5) << this->equippedWeapon.getStr() << " |" 
        << std::endl;  
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    // Armor Information
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Head:   " << std::setw(15) << this->equippedHelm.getName() << " |" << 
        " Defense:  " << std::setw(5) << this->equippedHelm.getDef() << " |" << std::endl;  
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Chest:  " << std::setw(15) << this->equippedChest.getName() << " |" << 
        " Defense:  " << std::setw(5) << this->equippedChest.getDef() << " |" << std::endl;  
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Hands:  " << std::setw(15) << this->equippedGloves.getName() << " |" << 
        " Defense:  " << std::setw(5) << this->equippedGloves.getDef() << " |" << std::endl;  
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Legs:   " << std::setw(15) << this->equippedPants.getName() << " |" << 
        " Defense:  " << std::setw(5) << this->equippedPants.getDef() << " |" << std::endl;  
    std::cout << std::setw(45) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

}

void Player::getStats() {
   
    // Player information
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Name: " << std::setw(15) << std::left << this->getName()
        << " |" << " Level: " << std::setw(5) << this->getLevel() << " |" << std::endl;
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std::cout << "| HP: " << std::setw(3) << std::right << this->getCurrHP() << std::left 
        << "/" << std::left << std::setw(14) << this->getMaxHP() << std::left 
        << "| Exp: " << std::setw(7) << std::left << this->getEXP() << " |" << std::endl;
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    // Stat Information
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Strength: " << std::setw(26) << this->getStr() << " |" << std::endl; 
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Literacy: " << std::setw(26) << this->getLit() << " |" << std::endl; 
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
    std:: cout << "| Thief:    " << std::setw(26) << this->getThf() << " |" << std::endl;
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

}

void Player::seeInventory() {
	for(int i = 0; i < 128; i++) {
		if(this->inventory[i].getName() != "") {
            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
            std::cout << "| " << std::left << i+1 << std::left << ". " << std::setw(32) << std::left 
                << this->inventory[i].getName() << " |" << std::endl;

            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
            std:: cout << "| Strength: " << std::setw(26) << this->inventory[i].getStr() << " |" << std::endl; 
            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
            std:: cout << "| Literacy: " << std::setw(26) << this->inventory[i].getLit() << " |" << std::endl; 
            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');
            std:: cout << "| Thief:    " << std::setw(26) << this->inventory[i].getThf() << " |" << std::endl;
            std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::setfill(' ');

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

void Player::setRoom(Room * room) {
	this->currRoom = room;
}

int Player::determineDmg() {
    int dmg;
    int lowDmg = this->getStr();
    int highDmg = this->getStr() + this->equippedWeapon.getStr(); 

    std::random_device rd; 
    std::mt19937 eng(rd()); 
    std::uniform_int_distribution<> distr(lowDmg, highDmg);

    dmg = distr(eng);
    return dmg;

}

void Player::healHP(int hp) {
    this->healthPoints += hp;
    if(this->healthPoints > 100) {
        this->healthPoints = 100;
    }
}

void Player::takeDamage(int hp) {
    this->healthPoints = this->healthPoints - hp;
}

void Player::incrementPotionCount() {
    this->setPotionCount(this->getPotionCount() + 1);
}

void Player::decrementPotionCount() {
    this->setPotionCount(this->getPotionCount() - 1);
}

bool Player::hasPotion() {
    return (this->potionCount > 0);
}

void Player::gainEXP(int exp) {
    this->exp = this->exp + exp;
}

int Player::potionIndex() {
    for(int i = 0; i < 128; i++) {
        if(this->inventory[i].getName() == "Potion") {
            return i;
        }
    }
    std::cout << "You do not have a potion." << std::endl;
    return -1;
}

void Player::removePotion(int i) {
    Item potion = this->inventory[i];
    this->takeItem(potion);
}

std::string Player::askForPlayerName() {
    std::string name;
    std::cout << "What is your name? ";
    std::cin >> name;
    return name;
}

void Player::askForPlayerClass() {
    int choice;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "| 1. Warrior (6 STR, 1 LIT, 0 THF)               |" << std::endl;
    std::cout << "| 2. Mage    (2 STR, 5 LIT, 1 THF)               |" << std::endl;
    std::cout << "| 3. Thief   (3 STR, 2 LIT, 4 THF)               |" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Choose your class. ";
    std::cin >> choice;
    if(choice == 1) {
        this->assignClassStats("warrior");
    } else if(choice == 2) {
        this->assignClassStats("mage");
    } else if(choice == 3) {
        this->assignClassStats("thief");
    } else {
        std::cout << "Invalid choice. Choosing for you." << std::endl;
        this->assignClassStats("warrior");
    } 
}

void Player::assignClassStats(std::string playerClass) {
    if(playerClass == "warrior") {
        this->setPlayerClass("Warrior");
        this->setStr(6);
        this->setLit(1);
        this->setThf(0);
    } else if(playerClass == "mage") {
        this->setPlayerClass("Mage");
        this->setStr(2);
        this->setLit(5);
        this->setThf(1);
    } else { 
        this->setPlayerClass("Thief");
        this->setStr(3);
        this->setLit(2);
        this->setThf(4);
   }
}

void Player::setInitialEquipment() {

    Item item; 

    item.setName("Empty");
    item.setStats(0, 0, 0, false, false, false, false, 0, 0);
    this->equipItem(item, "weapon");

    item.setName("Empty");
    item.setStats(0, 0, 0, false, false, false, false, 0, 0);
    this->equipItem(item, "gloves");

    item.setName("Empty");
    item.setStats(0, 0, 0, false, false, false, false, 0, 0);
    this->equipItem(item, "helm");

    item.setName("Ragged shirt");
    item.setStats(0, 0, 0, false, false, true, false, 3, 0);
    this->equipItem(item, "chest");

    item.setName("Torn pants");
    item.setStats(0, 0, 0, false, false, true, false, 2, 0);
    this->equipItem(item, "pants");
}
