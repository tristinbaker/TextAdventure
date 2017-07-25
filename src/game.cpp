#include "game.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "notebook.h"

#include <iostream>
#include <unistd.h>
#include <fstream>

Player player = Player(9, 2);
Map map = Map();
Item items[128];

void init() {

	bool hasLock = false;
	bool hasItem = false;
	bool hasEnemy = false;
    std::string roomName = "     ";
	Room *room = new Room(hasLock, hasItem, hasEnemy, roomName);

    for(int i = 0; i < 10; i++) {
       for(int j = 0; j < 10; j++) {
          map.allocRoom(room, i, j);
       }
    } 

    roomName = "START";
    hasItem = true;
    room = new Room(hasLock, hasItem, hasEnemy, roomName);
	map.allocRoom(room, 9, 2); 
	player.setRoom(room);
	map.setRoom("START");

    roomName = "ARTIE";
    hasItem = false;
    room = new Room(hasLock, hasItem, hasEnemy, roomName);
    map.allocRoom(room, 9, 1);

    roomName = "DAYAK";
    hasEnemy = true;
    hasItem = true;
    room = new Room(hasLock, hasItem, hasEnemy, roomName);
    map.allocRoom(room, 9, 0);

    roomName = "MITRE";
    hasEnemy = false;
    hasItem = false;
    room = new Room(hasLock, hasItem, hasEnemy, roomName);
    map.allocRoom(room, 8, 1);

    roomName = "FAULT";
    room = new Room(hasLock, hasItem, hasEnemy, roomName);
    map.allocRoom(room, 7, 1);
}

void gameLoop() {
    
    // Player input variables
	int choice = 0;
	std::string strChoice = "";
	char charChoice = '0';

    // Game variables
	Room * currRoom = player.getRoom();
	map.setRoom(currRoom->getRoomName());
	Item item; 
    Enemy enemy;
	int itemIndex = 0;
    Menu menu;
    Notebook notebook;

    notebook.setRoom(currRoom);

	std::cout << "\033[2J\033[1;1H";
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|                                                |" << std::endl;
	std::cout << "|                   THE DUNGEON                  |" << std::endl;	
	std::cout << "|                                                |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Begin? (Yes/No): ";
	
	std::cin >> strChoice;

	if(strChoice != "Yes" && strChoice != "yes" && strChoice != "Y" && strChoice != "y") {
		return;
	}

    // Get player's name
    std::cout << "What is your name? ";
    std::cin >> strChoice;
    player.setName(strChoice);

    //Get player's class
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "| 1. Warrior (6 STR, 1 LIT, 0 THF)               |" << std::endl;
    std::cout << "| 2. Mage    (2 STR, 5 LIT, 1 THF)               |" << std::endl;
    std::cout << "| 3. Thief   (3 STR, 2 LIT, 4 THF)               |" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Choose your class. ";
    std::cin >> choice;
    if(choice == 1) {
        player.setStr(6);
        player.setLit(1);
        player.setThf(0);
    } else if(choice == 2) {
        player.setStr(2);
        player.setLit(5);
        player.setThf(1);
    } else if(choice == 3) {
        player.setStr(3);
        player.setLit(2);
        player.setThf(4);
    } else {
        std::cout << "Invalid choice. Choosing for you." << std::endl;
        player.setStr(6);
        player.setLit(1);
        player.setThf(0);
    } 

/*   
    // Welcome the player
    std::string welcome = "    Hello " + player.getName() + ".\n\n";
    welcome +=            "      Welcome to \n";
    welcome +=            "  T H E D U N G E O N   \n\n";
    welcome +=            "    Are you ready? (Y/N) ";
    std::cout << "\033[2J\033[1;1H";
    for(int i = 0; i < welcome.size(); i++) {
        std::cout << welcome[i] << std::flush;
        usleep(100000);
    }
    std::cin >> strChoice;
    if(strChoice != "Y" && strChoice != "y") {
        return;
    }
    */
    
    // Set initial equipment for the player.
    item.setName("Empty");
    item = Item(item.getName());
    item.setStats(0, 0, 0, false, false, 0, 0);
    player.equipItem(item, "weapon");

    item.setName("Empty");
    item = Item(item.getName());
    item.setStats(0, 0, 0, false, false, 0, 0);
    player.equipItem(item, "gloves");

    item.setName("Empty");
    item = Item(item.getName());
    item.setStats(0, 0, 0, false, false, 0, 0);
    player.equipItem(item, "helm");

    item.setName("Ragged shirt");
    item = Item(item.getName());
    item.setStats(0, 0, 0, false, false, 3, 0);
    player.equipItem(item, "chest");

    item.setName("Torn pants");
    item = Item(item.getName());
    item.setStats(0, 0, 0, false, false, 2, 0);
    player.equipItem(item, "pants");
     

	while(player.alive()) {
        menu.clearChoices();
		charChoice = '0';
		std::cout << "\033[2J\033[1;1H";
		if(currRoom->getRoomName() == "START") {
			notebook.determineLore();
            currRoom->determineLore();
            std::cout << currRoom->getLore();
			if(currRoom->containsItem()) {
				menu.setChoice(0, "Leave room. (Left)");
				menu.setChoice(1, "Pick up sword.");
                menu.setChoice(2, "View notebook.");
				menu.setChoice(3, "View map.");
				menu.setChoice(4, "View inventory.");
                menu.setChoice(5, "View equipment.");
                menu.setChoice(6, "View stats.");
				menu.setChoice(7, "Save and quit.");
                std::cout << std::endl;
				menu.printChoices();
                std::cout << std::endl << "What is your choice? ";
				std::cin >> choice;
	
				switch(choice) {
					case 1:
						map.setRoom("ARTIE");
						currRoom = map.getRoom();
						player.setRoom(currRoom);
						break;
					case 2:
		                std::cout << "\033[2J\033[1;1H";
						item.setName("Rusty Sword");
						item = Item(item.getName());
						item.setStats(0, 5, 0, false, true, 0, 0);
						player.giveItem(item);
						items[itemIndex] = item;
						itemIndex++;
						currRoom->setItem(false);
                        loadArt("RustySword");
                        std::cout << "\nPicked up " << item.getName() << ". Would you like to equip the " <<
                            item.getName() << "? (Y/N)" << std::endl;
                        std::cin >> charChoice;
                        if(charChoice == 'Y' || charChoice == 'y') {
                            player.equipItem(item, "weapon");
                        } else {
                            break;
                        }
						break;
                    case 3:
		                std::cout << "\033[2J\033[1;1H";
                        std::cout << notebook.getLore();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 4:
		                std::cout << "\033[2J\033[1;1H";
						map.printMap(*currRoom);
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 5:
		                std::cout << "\033[2J\033[1;1H";
						player.seeInventory();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 6:
		                std::cout << "\033[2J\033[1;1H";
                        player.getEquipment();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
                    case 7: 
                        std::cout << "\033[2J\033[1;1H";
                        player.getStats();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
                    case 8:
                        return;
					default: 
                        std::cout << "You entered an invalid option. Try again." << std::endl;
                        break;
				}
			} else {
				menu.setChoice(0, "Leave room. (Left)");
                menu.setChoice(1, "View notebook.");
				menu.setChoice(2, "View map.");
				menu.setChoice(3, "View inventory.");	
                menu.setChoice(4, "View equipment.");
                menu.setChoice(5, "View stats.");
				menu.setChoice(6, "Save and quit.");
                std::cout << std::endl;
				menu.printChoices();
                std::cout << std::endl << "What is your choice? ";
				std::cin >> choice;
				switch(choice) {
					case 1:
						map.setRoom("ARTIE");
						currRoom = map.getRoom();
						player.setRoom(currRoom);
						break;
                    case 2:
		                std::cout << "\033[2J\033[1;1H";
                        std::cout << notebook.getLore();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 3:
		                std::cout << "\033[2J\033[1;1H";
						map.printMap(*currRoom);
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 4:
		                std::cout << "\033[2J\033[1;1H";
						player.seeInventory();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 5:
		                std::cout << "\033[2J\033[1;1H";
                        player.getEquipment();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
                    case 6: 
                        std::cout << "\033[2J\033[1;1H";
                        player.getStats();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 7:
						return;
					default: 
						return;
				}
			}
		} else if(currRoom->getRoomName() == "ARTIE") {
			std::cout << currRoom->getLore() << std::endl;
			menu.setChoice(0, "Leave room. (Left)");  	
			menu.setChoice(1, "Leave room. (Right)");  	
			menu.setChoice(2, "Leave room. (Up)");  	
			menu.setChoice(3, "View map.");
			menu.setChoice(4, "View inventory.");
            menu.setChoice(5, "View equipment.");
            menu.setChoice(6, "View stats.");
			menu.setChoice(7, "Save and quit.");
			menu.printChoices();
            std::cout << std::endl << "What is your choice? ";
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
		            std::cout << "\033[2J\033[1;1H";
					map.printMap(*currRoom);
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 5:
		            std::cout << "\033[2J\033[1;1H";
				    player.seeInventory();
					std::cout << "Press 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
                case 6:
		            std::cout << "\033[2J\033[1;1H";
                    player.getEquipment();
			        std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
               case 7: 
                   std::cout << "\033[2J\033[1;1H";
                   player.getStats();
				   std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 8:
					return;
				default: 
                    std::cout << "You entered an invalid option. Try again." << std::endl;
                    break;
			}		
       } else if(currRoom->getRoomName() == "DAYAK") {
			notebook.determineLore();
            currRoom->determineLore();
            std::cout << currRoom->getLore();
			if(currRoom->containsItem() && currRoom->containsEnemy()) {
				menu.setChoice(0, "Leave room. (Right)");
				menu.setChoice(1, "Pick up potion.");
                menu.setChoice(2, "Fight Remnant Knight.");
				menu.setChoice(3, "View notebook.");
                menu.setChoice(4, "View map.");
				menu.setChoice(5, "View inventory.");
                menu.setChoice(6, "View equipment.");
                menu.setChoice(7, "View stats.");
				menu.setChoice(7, "Save and quit.");
                std::cout << std::endl;
				menu.printChoices();
                std::cout << std::endl << "What is your choice? ";
				std::cin >> choice;
	
				switch(choice) {
					case 1:
						map.setRoom("ARTIE");
						currRoom = map.getRoom();
						player.setRoom(currRoom);
						break;
					case 2:
		                std::cout << "\033[2J\033[1;1H";
						item.setName("Potion");
						item = Item(item.getName());
						item.setStats(0, 0, 0, false, false, 0, 20);
						player.giveItem(item);
                        player.incrementPotionCount();
						items[itemIndex] = item;
						itemIndex++;
						currRoom->setItem(false);
                        loadArt("Potion");
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
                    case 3:
                        enemy = Enemy("Remnant Knight");
                        enemy.setStats(30, 3, 7, 0, 0, false, 50);
                        enemy.battle(&player, enemy);
                        currRoom->setEnemy(false);
                        break;
                    case 4:
		                std::cout << "\033[2J\033[1;1H";
                        std::cout << notebook.getLore();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 5:
		                std::cout << "\033[2J\033[1;1H";
						map.printMap(*currRoom);
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 6:
		                std::cout << "\033[2J\033[1;1H";
						player.seeInventory();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
					case 7:
		                std::cout << "\033[2J\033[1;1H";
                        player.getEquipment();
						std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
						while(charChoice != 'y') {
							std::cin >> charChoice;
						}
						break;
                    case 8: 
                        std::cout << "\033[2J\033[1;1H";
                        player.getStats();
				        std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					    while(charChoice != 'y') {
						    std::cin >> charChoice;
					    }
					    break;
                    case 9:
                        return;
					default: 
                        std::cout << "You entered an invalid option. Try again." << std::endl;
                        break;
				}
          } else if(!currRoom->containsItem() && currRoom->containsEnemy()) { 
			  menu.setChoice(0, "Leave room. (Right)");
              menu.setChoice(1, "Fight Remnant Knight.");
			  menu.setChoice(2, "View notebook.");
              menu.setChoice(3, "View map.");
			  menu.setChoice(4, "View inventory.");
              menu.setChoice(5, "View equipment.");
              menu.setChoice(6, "View stats.");
			  menu.setChoice(7, "Save and quit.");
              std::cout << std::endl;
			  menu.printChoices();
              std::cout << std::endl << "What is your choice? ";
			  std::cin >> choice;
	
		   	  switch(choice) {
			    case 1:
					map.setRoom("ARTIE");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
                case 2:
                    enemy = Enemy("Remnant Knight");
                    enemy.setStats(30, 3, 7, 0, 0, false, 50);
                    enemy.battle(&player, enemy);
                    currRoom->setEnemy(false);
                    break;
                case 3:
		            std::cout << "\033[2J\033[1;1H";
                    std::cout << notebook.getLore();
		    		std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
		    		while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 4:
		            std::cout << "\033[2J\033[1;1H";
		    		map.printMap(*currRoom);
					std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 5:
		            std::cout << "\033[2J\033[1;1H";
		    		player.seeInventory();
					std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 6:
		            std::cout << "\033[2J\033[1;1H";
                    player.getEquipment();
		    		std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
               case 7:
                    std::cout << "\033[2J\033[1;1H";
                    player.getStats();
				    std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
			          std::cin >> charChoice;
					}
					break;
                case 8:
                   return;
				default: 
                    std::cout << "You entered an invalid option. Try again." << std::endl;
                    break;
		   	 }
          } else if(currRoom->containsItem() && !currRoom->containsEnemy()) { 
			  menu.setChoice(0, "Leave room. (Right)");
              menu.setChoice(1, "Pick up potion.");
			  menu.setChoice(2, "View notebook.");
              menu.setChoice(3, "View map.");
			  menu.setChoice(4, "View inventory.");
              menu.setChoice(5, "View equipment.");
              menu.setChoice(6, "View stats.");
			  menu.setChoice(7, "Save and quit.");
              std::cout << std::endl;
			  menu.printChoices();
              std::cout << std::endl << "What is your choice? ";
			  std::cin >> choice;
	
		   	  switch(choice) {
			    case 1:
					map.setRoom("ARTIE");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
                case 2:
		            std::cout << "\033[2J\033[1;1H";
				    item.setName("Potion");
					item = Item(item.getName());
					item.setStats(0, 0, 0, false, false, 0, 20);
					player.giveItem(item);
                    player.incrementPotionCount();
					items[itemIndex] = item;
				    itemIndex++;
					currRoom->setItem(false);
                    loadArt("Potion");
				    std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
                case 3:
		            std::cout << "\033[2J\033[1;1H";
                    std::cout << notebook.getLore();
		    		std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
		    		while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 4:
		            std::cout << "\033[2J\033[1;1H";
		    		map.printMap(*currRoom);
					std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 5:
		            std::cout << "\033[2J\033[1;1H";
		    		player.seeInventory();
					std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 6:
		            std::cout << "\033[2J\033[1;1H";
                    player.getEquipment();
		    		std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
               case 7:
                    std::cout << "\033[2J\033[1;1H";
                    player.getStats();
				    std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
			          std::cin >> charChoice;
					}
					break;
                case 8:
                   return;
				default: 
                    std::cout << "You entered an invalid option. Try again." << std::endl;
                    break;
		   	 }
          } else { 
			  menu.setChoice(0, "Leave room. (Right)");
			  menu.setChoice(1, "View notebook.");
              menu.setChoice(2, "View map.");
			  menu.setChoice(3, "View inventory.");
              menu.setChoice(4, "View equipment.");
              menu.setChoice(5, "View stats.");
			  menu.setChoice(6, "Save and quit.");
              std::cout << std::endl;
			  menu.printChoices();
              std::cout << std::endl << "What is your choice? ";
			  std::cin >> choice;
	
		   	  switch(choice) {
			    case 1:
					map.setRoom("ARTIE");
					currRoom = map.getRoom();
					player.setRoom(currRoom);
					break;
                case 2:
		            std::cout << "\033[2J\033[1;1H";
                    std::cout << notebook.getLore();
		    		std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
		    		while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 3:
		            std::cout << "\033[2J\033[1;1H";
		    		map.printMap(*currRoom);
					std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 4:
		            std::cout << "\033[2J\033[1;1H";
		    		player.seeInventory();
					std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
				case 5:
		            std::cout << "\033[2J\033[1;1H";
                    player.getEquipment();
		    		std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
						std::cin >> charChoice;
					}
					break;
               case 6:
                    std::cout << "\033[2J\033[1;1H";
                    player.getStats();
				    std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
					while(charChoice != 'y') {
			          std::cin >> charChoice;
					}
					break;
                case 7:
                   return;
				default: 
                    std::cout << "You entered an invalid option. Try again." << std::endl;
                    break;
		   	 }
          }
       }
	} 	
}

void loadArt(std::string artName) {
    std::string shift;
    std::string file;
    file += "./bin/";
    file += artName;
    file += ".art";
    std::ifstream inFile;
    inFile.open(file.c_str());

    if (!inFile) {
        std::cout << "Unable to open file: ";
        std::cout << file;
        return;
    }

    while (std::getline(inFile, shift)) {
        std::cout << shift << std::endl;
    }
   inFile.close();
}
