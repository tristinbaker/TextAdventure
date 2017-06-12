#include "menu.h"

Menu::Menu() {
	for(int i = 0; i < 10; i++) {
		choices[i] = "";
	}
}

void Menu::printChoices() {
	for(int i = 0; i < 10; i++) {
		if(choices[i] == "") {
		} else {
			std::cout << i + 1 << ". " << choices[i] << std::endl;
		}
	}
}

void Menu::clearChoices() {
    for(int i = 0; i < 10; i++) {
        choices[i] = "";
    }
}
