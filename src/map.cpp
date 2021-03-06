#include "map.h"
#include "room.h"
#include "player.h"

Map::Map() {
	Room * blankRoom = new Room(false, false, false, "");
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			rooms[i][j] = blankRoom;
		}
	}
}

Map::~Map() {}

void Map::printMap(Room room) {
	for(int i = 0; i < 10; i++) {
		std::cout << " ---------------------------------------------------------------------------------" << std::endl;
		for(int j = 0; j < 10; j++) {
			if(rooms[i][j]->getRoomName() == room.getRoomName()) {
				std::cout << " | " << "\033[1;31m" << rooms[i][j]->getRoomName() << "\033[0m";
			} else {
				std::cout << " | " << rooms[i][j]->getRoomName();
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
			if(roomName == rooms[i][j]->getRoomName()) {
                std::cout << "roomName: " << roomName << "rooms[" << i << "][" << j << "->getRoomName(): " << rooms[i][j]->getRoomName() << std::endl;
				this->currRoom = rooms[i][j];
			}
		}
	}
}
