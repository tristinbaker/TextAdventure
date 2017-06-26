#include "enemy.h"
#include "player.h"

Enemy::Enemy() {}

Enemy::Enemy(std::string name) {
    this->name = name;
}

Enemy::~Enemy() {}

void Enemy::setStats(int healthPoints, int lowDmg, int highDmg, int weakness, int resistance, bool isBoss) {
    this->healthPoints = healthPoints;
    this->lowDmg = lowDmg;
    this->highDmg = highDmg;
    this->weakness = weakness;
    this->resistance = resistance;
    this->isBoss = isBoss;
    this->currHP = healthPoints;
}

void Enemy::battle(Player *player, Enemy enemy) {
    int enemyDmg;
    int playerDmg;
    char choice;
    while(enemy.getCurrHP() >= 0) {
       enemyDmg = enemy.determineDmg();
       playerDmg = player->determineDmg();
       if(player->alive()) {
		   std::cout << "\033[2J\033[1;1H";
           std::cout << "----------------------------------------------------------------------------------" << std::endl;
           std::cout << enemy.getName() << ": " << enemy.getCurrHP() << "/" << enemy.getMaxHP() << std::endl;
           std::cout << "----------------------------------------------------------------------------------" << std::endl;
           std::cout << player->getName() << ": " << player->getCurrHP() << "/" << player->getMaxHP() << std::endl;
           std::cout << "----------------------------------------------------------------------------------" << std::endl;
           std::cout << player->getName() << " hit " << enemy.getName() << " for " <<
              playerDmg << " damage. " << std::endl;
           std::cout << "----------------------------------------------------------------------------------" << std::endl;
           std::cout << enemy.getName() << " hit " << player->getName() << " for " << 
              enemyDmg << " damage. " << std::endl; 
           std::cout << "----------------------------------------------------------------------------------" << std::endl;
       } else {
           std::cout << "You have died. Game over." << std::endl;
       }
       player->takeDamage(enemyDmg);
       enemy.takeDamage(playerDmg);
       usleep(1000000);
       if(player->hasPotion()) {
           std::cout << "You are currently at " << player->getCurrHP() << "HP. Would you like to heal with a potion? (Y/N) ";
           std::cin >> choice; 
           if(choice == 'Y' || choice == 'y') {
               player->setCurrHP(30); 
               player->decrementPotionCount();
           }
       } 
    }
    std::cout << enemy.getName() << " has been slain.";
	std::cout << "\nPress 'y' followed by 'ENTER' to continue." << std::endl;
	while(choice != 'y') {
		std::cin >> choice;
	}
}

int Enemy::determineDmg() {
    int dmg;

    std::random_device rd; 
    std::mt19937 eng(rd()); 
    std::uniform_int_distribution<> distr(this->getLowDmg(), this->getHighDmg());

    dmg = distr(eng);
    return dmg;
}

void Enemy::takeDamage(int hp) {
    this->currHP = this->currHP - hp;
}
