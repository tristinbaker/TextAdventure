#include "enemy.h"
#include "player.h"

Enemy::Enemy() {}

Enemy::Enemy(std::string name) {
    this->name = name;
}

Enemy::~Enemy() {}

void Enemy::setStats(int healthPoints, int lowDmg, int highDmg, int weakness, int resistance, bool isBoss, int exp) {
    this->healthPoints = healthPoints;
    this->lowDmg = lowDmg;
    this->highDmg = highDmg;
    this->weakness = weakness;
    this->resistance = resistance;
    this->isBoss = isBoss;
    this->currHP = healthPoints;
    this->exp = exp;
}

void Enemy::battle(Player *player, Enemy enemy) {
    int enemyDmg;
    int playerDmg;
    int option = 0;
    char choice;
    std::string menuText;
    this->battleMenu.clearChoices();
    menuText = "Attack " + enemy.getName() + ".";
    this->battleMenu.setChoice(0, menuText); 
    this->battleMenu.setChoice(1, "Use item.");
    std::cout << "\033[2J\033[1;1H";
    while(enemy.getCurrHP() >= 0) {
        enemyDmg = enemy.determineDmg();
        playerDmg = player->determineDmg();
        if(player->alive()) {
		    //std::cout << "\033[2J\033[1;1H";
            std::cout << std::endl;
            std::cout << "----------------------------------------------------------------------------------" << std::endl;
            std::cout << enemy.getName() << ": " << enemy.getCurrHP() << "/" << enemy.getMaxHP() << std::endl;
            std::cout << "----------------------------------------------------------------------------------" << std::endl;
            std::cout << player->getName() << ": " << player->getCurrHP() << "/" << player->getMaxHP() << std::endl;
            std::cout << "----------------------------------------------------------------------------------" << std::endl;
            this->battleMenu.printChoices();
            std::cout << "What will you do?: ";
            std::cin >> option;
            switch(option) {
            case 1: 
		        std::cout << "\033[2J\033[1;1H";
                std::cout << "----------------------------------------------------------------------------------" << std::endl;
                std::cout << player->getName() << " hit " << enemy.getName() << " for " <<
                    playerDmg << " damage. " << std::endl;
                std::cout << "----------------------------------------------------------------------------------" << std::endl;
                std::cout << enemy.getName() << " hit " << player->getName() << " for " << 
                    enemyDmg << " damage. " << std::endl; 
                std::cout << "----------------------------------------------------------------------------------" << std::endl;
                player->takeDamage(enemyDmg);
                enemy.takeDamage(playerDmg);
                usleep(2000000);
                break;
            case 2: 
                player->seeInventory(); 
                if(player->hasPotion()) {
                    player->healHP(30); 
                    player->decrementPotionCount();
                    int i = player->potionIndex();
                    player->removePotion(i);
                    std::cout << "You have healed 30HP. You are now at " << player->getCurrHP() << "/" 
                        << player->getMaxHP() << std::endl;
                } else {
                    std::cout << "You do not have a potion." << std::endl; 
                }
                usleep(2000000);
                break;
            default: 
                std::cout << "Error. Invalid choice. Choose again." << std::endl;
                usleep(2000000);
                break;
            }
       } else {
           std::cout << "You have died. Game over." << std::endl;
       }
    }
    std::cout << '\n' << enemy.getName() << " has been slain.";
    player->gainEXP(enemy.getEXP());
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
