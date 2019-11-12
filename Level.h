#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include  "Player.h"
#include "Enemy.h"
using namespace std;

class Level {

public:
	Level();
	void load(string fileName, Player &player);
	void print(Player &player);
	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);

	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

	bool endGame = false;

private:
	vector<string> _levelData;
	vector <Enemy> _enemies;

	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void processPlayerMove(Player &player, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
};