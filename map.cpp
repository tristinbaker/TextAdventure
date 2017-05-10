#include "map.h"
#include "room.h"

Map::Map() {
	Room blankRoom;
	blankRoom.setLore("");
	blankRoom.setLock(false);
	blankRoom.setEnemy(false);
	blankRoom.setBoss(false);
	blankRoom.setName("EMPTY");
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			rooms[i][j] = blankRoom;
		}
	}
}

Map::~Map() {}

void Map::printMap() {
	for(int i = 0; i < 10; i++) {
		std::cout << " ---------------------------------------------------------------------------------" << std::endl;
		for(int j = 0; j < 10; j++) {
			std::cout << " | " << rooms[i][j].getName();
			if(j == 9) {
				std::cout << " |" << std::endl;
			}
		}
	} 
	std::cout << " ---------------------------------------------------------------------------------" << std::endl;
}
