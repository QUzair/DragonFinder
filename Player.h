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


class Player {

public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	int attack();
	int takeDamage(int attack);

	void addExperience(int experience);

	void setPosition(int x, int y);
	void getPosition(int &x, int &y);

	int getexperience();

	int getfov();
	void setfov(int);

	int numMoves;

	void setStat(char stat, int value);
	int getStat(char stat);

	string getPName();
	void setPName(string);
	Stats player_stats;
	
private:
	//position
	int _x, _y;
	string name;
	//Properties
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;
	int fov = 1;
};

