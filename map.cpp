#include "map.h"
#include "room.h"
#include "player.h"

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

void Map::printMap(Player player) {
	for(int i = 0; i < 10; i++) {
		std::cout << " ---------------------------------------------------------------------------------" << std::endl;
		for(int j = 0; j < 10; j++) {
			if(rooms[i][j].getName() == player.getRoomName()) {
				std::cout << " | " << "\033[1;31m" << rooms[i][j].getName() << "\033[0m";
			} else {
				std::cout << " | " << rooms[i][j].getName();
			}
			if(j == 9) {
				std::cout << " |" << std::endl;
			}
		}
	} 
	std::cout << " ---------------------------------------------------------------------------------" << std::endl;
}

void Map::setRoom(std::string roomName) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(roomName == rooms[i][j].getName()) {
				this->currRoom = rooms[i][j];
			}
		}
	}
}
