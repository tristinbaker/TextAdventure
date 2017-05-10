#ifndef ENEMY_H
#define ENEMY_H

class Enemy {

public:

	Enemy();
	~Enemy();

	void takeDamage(int dmg);
	int attack();

private:

	int healthPoints;
	bool isBoss = false;
	int attackPoints;
	int weakness, resistance;
	int lowDmg, highDmg;

};

#endif
