#include "game.h"
#include "player.h"
#include "map.h"
#include "item.h"

#include <iostream>

void init() {

//	Room::Room(std::string lore, bool hasLock, bool hasItem, bool hasEnemy, std::string roomName) {

	Map map = Map();
	Player player = Player(9, 2);
	std::string lore = "This is the start.";
	bool hasLock = false;
	bool hasItem = true;
	bool hasEnemy = false;
	std::string roomName = "START";

	Room room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 9, 2); 
	player.setRoom(room);

	roomName = "ARTIE"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 9, 1);

	roomName = "DAYAK"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 9, 0);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 8, 0);

	roomName = "MITRE"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 8, 1);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 8, 2);

	roomName = "IONIA"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 7, 0);

	roomName = "FAULT"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 7, 1);

	roomName = "ARTEL"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 7, 2);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 6, 0);

	roomName = "DRUID"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 6, 1);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 6, 2);

	roomName = "     "; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 5, 0);

	roomName = "TARIM"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 5, 1);

	roomName = "TIRED"; 
	room = Room(lore, hasLock, hasItem, hasEnemy, roomName);
	map.setRoom(room, 5, 2);

	map.printMap(player);
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
	
}
