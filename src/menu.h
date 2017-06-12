#ifndef MENU_H
#define MENU_H
#include <iostream>
class Menu {

public:
	Menu();
	void setChoice(int index, std::string choice) { this->choices[index] = choice; }
	void printChoices();
    void clearChoices();

private:
	std::string choices[10];

};

#endif 
