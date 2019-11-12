#include "Enemy.h"


Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp) {
	enemy_stats.StatsInit(level, attack, defense, health, xp);
	_name = name;
	_tile = tile;
}

void Enemy::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

void Enemy::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

int Enemy::attack() {
	//static default_random_engine randomEngine(time(NULL));
	//uniform_int_distribution<int> attackRoll(0, enemy_stats.getStat('a')); //template therefore say int

	//return attackRoll(randomEngine);
	return enemy_stats.attack();
}

int Enemy::takeDamage(int attack) {
	//attack -= enemy_stats.getStat('d'); // can the attack do damage
	if (attack > 0) {
	//	enemy_stats.setStat('h', enemy_stats.getStat('h')-attack); // check if he died    halth = health-attack
	//	if (enemy_stats.getStat('h') <= 0)
	//		return enemy_stats.getStat('e');
		return enemy_stats.takeDamage(attack);
	}
	return 0;
}

string Enemy::getName() {
	return _name; 
}

char Enemy::getMove(int playerX, int playerY) {
	
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0,6);

	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx); //abs slow function therfore stored in a variable
	int ady = abs(dy);
	int distance = adx + ady;

	if (distance <= 3) {
		//Moving along x axis
		if (adx > ady) {
			if (dx > 0) {
				return 'a';
			}
			else
				return 'd';
		}
		else {
			//Move along y axis
			if (dy > 0) {
				return 'w';
			}
			else
				return 's';
		}
	}
	//when distance isnt less than 5, move randomly
	int  randMove = moveRoll(randomEngine);

	switch (randMove) {
	case 0 :
		return 'a';
	case 1 :
		return 'w';
	case 2: 
		return 's';
	case 3:
		return 'd';
	default:
		return '.'; // dont move 4/7 chance in moving, 2/7 chance staying still
	}
}

char Enemy::getTile() {
	return _tile;
}


void Enemy::setStat(char stat, int value) {
	enemy_stats.setStat(stat, value);
}

int Enemy::getStat(char stat) {
	return enemy_stats.getStat(stat);
}






