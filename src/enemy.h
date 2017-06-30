#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <random>
#include <unistd.h>

#include "player.h"
#include "menu.h"

class Enemy {

public:

	Enemy();
    Enemy(std::string name); 
	~Enemy();

    void setStats(int healthPoints, int lowDmg, int highDmg, int weakness, int resistance, bool isBoss, int exp);
	void takeDamage(int dmg);
    std::string setName(std::string name) { this->name = name; }
    std::string getName() { return this->name; }
    void setCurrHP(int hp);
    int getCurrHP() { return this->currHP; }
    int getMaxHP() { return this->healthPoints; }
    int getLowDmg() { return this->lowDmg; }
    int getHighDmg() { return this->highDmg; }
    int getEXP() { return this->exp; }
    int determineDmg(); 
    void battle(Player *player, Enemy enemy);

private:

    int currHP;
	int healthPoints;
	bool isBoss;
    int exp;
	int attackPoints;
	int weakness, resistance;
	int lowDmg, highDmg;
    std::string name;
    Menu battleMenu;

};

#endif
