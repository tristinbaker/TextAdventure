#include "menu.h"

Menu::Menu() {

	this->setChoice(0, "View map.");
    this->setChoice(1, "View stats.");
    this->setChoice(2, "View notebook.");
	this->setChoice(3, "View inventory.");
    this->setChoice(4, "View equipment.");
	this->setChoice(5, "Save and quit.");
	for(int i = 6; i < 10; i++) {
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
    for(int i = 6; i < 10; i++) {
        choices[i] = "";
    }
}
