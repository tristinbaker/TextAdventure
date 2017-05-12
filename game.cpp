#include "game.h"
#include "map.h"
#include "player.h"
#include "item.h"

#include <iostream>

Player player = Player(9, 2);
Map map = Map();

void init() {

//	Room::Room(std::string lore, bool hasLock, bool hasItem, bool hasEnemy, std::string roomName) {

	std::string lore = 
	"  Your head throbs, your body aches, as you slowly come to. You don't remember what happened before you fell asleep and as \n";
	lore += 
	"you open your eyes you realize that you have no idea where you are. The air was heavy with moisture and smelled of mold \n";
	lore += 
	"and in the distance you could hear water dripping onto the stone floor, echoing through the barely illuminated hallway \n";
	lore += 
	"to your left. As you take a moment to collect yourself you realize that you are in a square room, made entirely of grey \n";
	lore += 
	"stone bricks,  with three altar like slabs against the walls. As you shuffle and get your bearings you realize that you \n";
	lore +=
	"were laid upon one of these slabs, stripped of all possessions.\n \n  Faintly from the hall you hear what sounds like a scream.";
	lore +=
	" You realize then that you are not in a safe place and you \nstrain your eyes to search the room you are in for some sort of";
	lore +=
	"weapon. It is at this point you take note of the skeletal \nremains at the center of the room and as you rise to inspect you"; 
	lore +=
	"realize that this unfortunate warrior grasped a rusted-out \nsword. Dull as it may be, it would be wise to take it. As you scan";
	lore +=
	"the rest of the room you notice two other bodies on the other\nslabs. Will you investigate these bodies or will you begin your escape?\n";

	bool hasLock = false;
	bool hasItem = true;
	bool hasEnemy = false;
	std::string roomName = "START";

	Room room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 2); 
	player.setRoom(room);

	roomName = "ARTIE"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	room.setLore("Fuck dogs.\n");
	map.allocRoom(room, 9, 1);

	roomName = "DAYAK"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 0);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 8, 0);

	roomName = "MITRE"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 8, 1);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 8, 2);

	roomName = "IONIA"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 7, 0);

	roomName = "FAULT"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 7, 1);

	roomName = "ARTEL"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 7, 2);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 6, 0);

	roomName = "DRUID"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 6, 1);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 6, 2);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 5, 0);

	roomName = "TARIM"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 5, 1);

	roomName = "TIRED"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
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
		std::cout << "\033[2J\033[1;1H";
		if(currRoom.getRoomName() == "START") {
			std::cout << currRoom.getLore() << std::endl;
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
					break;
				case 3:
					map.printMap(player);
					std::cout << "Press ENTER to continue." << std::endl;
					while(charChoice != '\n') {
						charChoice = std::cin.get();
					}
					break;
				case 4:
					break;
				case 5:
					return;
				default: 
					return;
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
					std::cout << "Press ENTER to continue." << std::endl;
					while(charChoice != '\n') {
						charChoice = std::cin.get();
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
					std::cout << "Press ENTER to continue." << std::endl;
					while(charChoice != '\n') {
						charChoice = std::cin.get();
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
					std::cout << "Press ENTER to continue." << std::endl;
					while(charChoice != '\n') {
						charChoice = std::cin.get();
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

