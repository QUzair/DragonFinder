#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <random>
#include "Stats.h"

using namespace std;
class Enemy {

public:


	Enemy(string name, char tile, int level, int attack, int defense, int health, int xp);

	void setPosition(int x, int y);
	void getPosition(int &x, int &y);

	string getName();
	char getTile();

	int attack();
	int takeDamage(int attack);

	void setStat(char stat, int value);
	int getStat(char stat);

	//Gets AI move command
	char getMove(int playerX, int playerY);


private:
	Stats enemy_stats;
	//Stats EnemyStats;
	//postion
	//Stats enemy_stats;
	int _x, _y;

	//Properties
	string _name;
	char _tile; // what monster

};