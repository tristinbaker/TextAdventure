#include "game.h"
#include "player.h"
#include "map.h"
#include "item.h"

#include <iostream>

void init() {

//	Room::Room(std::string lore, bool hasLock, bool hasItem, bool hasEnemy, std::string roomName) {

	Map map = Map();
	std::string lore = "This is the start.";
	bool hasLock = false;
	bool hasItem = true;
	bool hasEnemy = false;
	std::string roomName = "START";

	Room room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 9, 2); 
	map.printMap();


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
