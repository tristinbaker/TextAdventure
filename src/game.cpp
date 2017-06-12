#include "game.h"
#include "map.h"
#include "player.h"
#include "item.h"

#include <iostream>

Player player = Player(9, 2);
Map map = Map();
Item items[128];

void init() {

	bool hasLock = false;
	bool hasItem = true;
	bool hasEnemy = false;
	std::string roomName = "START";
	std::string lore = "";

	Room *room = new Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 2); 
	player.setRoom(room);
	map.setRoom("START");

    roomName = "ARTIE";
    room = new Room(hasLock, hasItem, hasEnemy, roomName);
    map.allocRoom(room, 9, 1);
    map.setRoom("ARTIE");

}

void gameLoop() {

	int choice = 0;
	std::string strChoice = "";
	char charChoice = '0';
	Room * currRoom = player.getRoom();
	map.setRoom(currRoom->getRoomName());
	Item item; 
	int itemIndex = 0;
    Menu menu;

	std::cout << "\033[2J\033[1;1H";
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|                                                |" << std::endl;
	std::cout << "|                   THE DUNGEON                  |" << std::endl;	
	std::cout << "|                                                |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Do you choose to enter? (Yes/No): ";
	
	std::cin >> strChoice;

	if(strChoice != "Yes" && strChoice != "yes" && strChoice != "Y" && strChoice != "y") {
		return;
	}


	while(player.alive()) {
        menu.clearChoices();
		charChoice = '0';
		std::cout << "\033[2J\033[1;1H";
		if(currRoom->getRoomName() == "START") {
			currRoom->determineLore();
			std::cout << currRoom->getLore() << std::endl;
			if(currRoom->containsItem()) {
				menu.setChoice(0, "Leave room. (Left)");
				menu.setChoice(1, "Pick up sword.");
				menu.setChoice(2, "View map.");
				menu.setChoice(3, "View inventory.");
				menu.setChoice(4, "Save and quit.");
				menu.printChoices();
				std::cin >> choice;
	
				switch(choice) {
					case 1:
						map.setRoom("ARTIE");
						currRoom = map.getRoom();
						player.setRoom(currRoom);
						break;
					case 2:
						item.setName("Rusty Sword");
						item = Item(item.getName());
						item.setStats(0, 5, 0, false);
						player.giveItem(item);
						items[itemIndex] = item;
						itemIndex++;
						currRoom->setItem(false);
						std::cout << "Picked up " << item.getName() << ". Press 'y' followed "
                            << "by 'Enter to continue." << std::endl;
                        while(charChoice != 'y') {
                            std::cin >> charChoice;
                        }
						break;
					case 3:
						map.printMap(*currRoom);
						std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 4:
						player.seeInventory();
						std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 5:
						return;
					default: 
                        std::cout << "You entered an invalid option. Try again." << std::endl;
                        break;
				}
			} else {
				menu.setChoice(0, "Leave room. (Left)");
				menu.setChoice(1, "View map.");
				menu.setChoice(2, "View inventory.");	
				menu.setChoice(3, "Save and quit.");
				menu.printChoices();
				std::cin >> choice;
				switch(choice) {
					case 1:
						map.setRoom("ARTIE");
						currRoom = map.getRoom();
						player.setRoom(currRoom);
						break;
					case 2:
						map.printMap(*currRoom);
						std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 3:
						player.seeInventory();
						std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 4:
						return;
					default: 
						return;
				}
			}
		} else if(currRoom->getRoomName() == "ARTIE") {
			std::cout << "In ARTIE." << std::endl;
			std::cout << currRoom->getLore() << std::endl;
			menu.setChoice(0, "Leave room. (Left)");  	
			menu.setChoice(1, "Leave room. (Right)");  	
			menu.setChoice(2, "Leave room. (Up)");  	
			menu.setChoice(3, "View map.");
			menu.setChoice(4, "View inventory.");
			menu.setChoice(5, "Save and quit.");
			menu.printChoices();
			std::cin >> choice;
			currRoom->setItem(false);
			switch(choice) {
				case 1: 
					map.setRoom("DAYAK");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
				case 2:
					map.setRoom("START");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
				case 3: 
					map.setRoom("MITRE");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
				case 4:
					map.printMap(*currRoom);
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 5:
				    player.seeInventory();
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 6:
					return;
				default: 
                    std::cout << "You entered an invalid option. Try again." << std::endl;
                    break;
			}		
       }
	} 	
}

