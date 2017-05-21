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

	Room room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 2); 
	player.setRoom(room);

	hasItem = false;
	roomName = "ARTIE"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 1);

	roomName = "DAYAK"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 0);

	roomName = "     "; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 8, 0);

	roomName = "MITRE"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 8, 1);

	roomName = "     "; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 8, 2);

	roomName = "IONIA"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 7, 0);

	roomName = "FAULT"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 7, 1);

	roomName = "ARTEL"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 7, 2);

	roomName = "     "; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 6, 0);

	roomName = "DRUID"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 6, 1);

	roomName = "     "; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 6, 2);

	roomName = "     "; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 5, 0);

	roomName = "TARIM"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 5, 1);

	roomName = "TIRED"; 
	room = Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 5, 2);

	/*int choice;
	int playerX = 0, playerY = 0;
	Player player = Player(playerX, playerY);	

	int itemX = 0, itemY = 0;
	std::string name = "Gun";
	Item items[128];
	Item item = Item(itemX, itemY, name); 
	item.setAllocated(1);

	std::cout << "Giving gun." << std::endl;
	player.giveItem(item);
	player.seeInventory();	
	items[0] = item;

	name = "Hat";
	item = Item(itemX, itemY, name);
	item.setAllocated(1);
	
	std::cout << "Giving hat." << std::endl;
	player.giveItem(item);
	player.seeInventory();	
	items[1] = item;
	
	std::cout << "Taking gun." << std::endl;
	player.takeItem(items[0]);
	player.seeInventory();
	*/
}

void gameLoop() {

	int choice = 0;
	std::string strChoice = "";
	char charChoice = '0';
	Room currRoom = player.getRoom();
	map.setRoom(currRoom.getRoomName());
	Item item; 
	int itemIndex = 0;

	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|                                                |" << std::endl;
	std::cout << "|                   THE DUNGEON                  |" << std::endl;	
	std::cout << "|                                                |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Do you choose to enter? (Yes/No): ";
	
	std::cin >> strChoice;

	if(strChoice != "Yes") {
		return;
	}


	while(player.alive()) {
		charChoice = '0';
		std::cout << "\033[2J\033[1;1H";
		if(currRoom.getRoomName() == "START") {
			std::cout << currRoom.getLore() << std::endl;
			std::cout << "currRoom.containsItem(): " << currRoom.containsItem() << std::endl;
			currRoom.determineLore();
			if(currRoom.containsItem()) {

				currRoom.setChoice(0, "Leave room. (Left)");
				currRoom.setChoice(1, "Pick up sword.");
				currRoom.setChoice(2, "View map.");
				currRoom.setChoice(3, "View inventory.");
				currRoom.setChoice(4, "Save and quit.");
				currRoom.getMenu().printChoices();
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
						currRoom.setItem(false);
						std::cout << "Picked up " << item.getName() << "." << std::endl;
						break;
					case 3:
						map.printMap(player);
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
						return;
				}
			} else {
				currRoom.setChoice(0, "Leave room. (Left)");
				currRoom.setChoice(1, "View map.");
				currRoom.setChoice(2, "View inventory.");	
				currRoom.setChoice(3, "Save and quit.");
				currRoom.setChoice(4, "");
				currRoom.getMenu().printChoices();
				std::cin >> choice;
				switch(choice) {
					case 1:
						map.setRoom("ARTIE");
						currRoom = map.getRoom();
						player.setRoom(currRoom);
						break;
					case 2:
						map.printMap(player);
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
		} else if(currRoom.getRoomName() == "ARTIE") {
			std::cout << "In ARTIE." << std::endl;
			std::cout << currRoom.getLore() << std::endl;
			currRoom.setChoice(0, "Leave room. (Left)");  	
			currRoom.setChoice(1, "Leave room. (Right)");  	
			currRoom.setChoice(2, "Leave room. (Up)");  	
			currRoom.setChoice(3, "View map.");
			currRoom.setChoice(4, "View inventory.");
			currRoom.setChoice(5, "Save and quit.");
			currRoom.getMenu().printChoices();
			std::cin >> choice;
			currRoom.setItem(false);
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
					map.printMap(player);
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 5:
					break;
				case 6:
					return;
				default: 
					return;
			}		
		} else if(currRoom.getRoomName() == "DAYAK") {
			std::cout << "In DAYAK." << std::endl;
			currRoom.setChoice(0, "Leave room. (Right)");  	
			currRoom.setChoice(1, "View map.");
			currRoom.setChoice(2, "View inventory.");
			currRoom.setChoice(3, "Save and quit.");
			currRoom.getMenu().printChoices();
			std::cin >> choice;
			switch(choice) {
				case 1: 
					map.setRoom("ARTIE");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
				case 2:
					map.printMap(player);
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 3: 
					break;
				case 4:
					return;	
				default: 
					return;
			}		
		} else if(currRoom.getRoomName() == "MITRE") {
			std::cout << "In MITRE." << std::endl;
			currRoom.setChoice(0, "Leave room. (Up)");  	
			currRoom.setChoice(1, "Leave room. (Down)");  	
			currRoom.setChoice(2, "View map.");
			currRoom.setChoice(3, "View inventory.");
			currRoom.setChoice(4, "Save and quit.");
			currRoom.getMenu().printChoices();
			std::cin >> choice;
			switch(choice) {
				case 1: 
					map.setRoom("FAULT");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
				case 2:
					map.setRoom("ARTIE");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
				case 3: 
					map.printMap(player);
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 4:
					break;
				case 5:
					return;
				default: 
					return;
			}		
		}
	}	
}

