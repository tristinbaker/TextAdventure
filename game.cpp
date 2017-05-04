#include "game.h"
#include "player.h"
#include "map.h"
#include "item.h"

#include <iostream>

void init() {
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
}

