#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int timetaken = time(0);

Level::Level() {

}
void Level::load(string fileName, Player &player) {
	
	ifstream file;
	file.open(fileName);

	if (file.fail()) {
		perror(fileName.c_str());
		system("pause");
		exit(1);
	}

	string line;

	while (getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();
	
	//Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			//name, tile, level, attack, defense, health, xp

			switch (tile) {
			case '@': //player
				player.init(1, 100, 100, 100, 0);
				player.setPosition(j, i);
				
				break;
			case 'S': //snake
				_enemies.push_back(Enemy("Snake", tile, 100, 2000, 2000, 200, 2000)); //
				_enemies.back().setPosition(j, i);
				break;
			case 'g':
				_enemies.push_back(Enemy("Goblin", tile, 2, 4, 4, 4, 150));
				_enemies.back().setPosition(j, i);
				break;
			case 'O' :
				_enemies.push_back(Enemy("Ogre", tile, 2, 10, 10, 10, 500));
				_enemies.back().setPosition(j, i);
				break;
			case 'D':
				_enemies.push_back(Enemy("Dragon", tile,1000, 20000, 20000, 2000, 2000));
				_enemies.back().setPosition(j, i);
				break;
			case 'B':
				_enemies.push_back(Enemy("Bandit", tile,3, 15, 10, 100, 250));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}

}

void Level::print(Player &player) {
	int i, j, i1, j1, minj2, maxj2, mini2, maxi2, fov;
	
	fov = player.getfov();
	
	player.getPosition(j1, i1); // position of player

	if (j1 - fov < 2) // ensuring fov isnt outside text file
		minj2 = 0;
	else minj2 = j1 - fov;

	if (j1 + fov > _levelData[i1].size())
		maxj2 = _levelData[i1].size();
	else maxj2 = j1 + fov;

	if (i1 - fov < 2)
		mini2 = 0;
	else mini2 = i1 - fov;

	if (i1 + fov > _levelData.size())
		maxi2 = _levelData.size();
	else maxi2 = i1 + fov;

	cout << string(100, '\n');

	for ( i = mini2; i < maxi2; i++) {
		cout << setw(30);
		for (j = minj2; j < maxj2; j++) {
			cout << _levelData[i][j];
		}
		cout << endl;
	}

}


char Level::getTile(int x, int y){
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}

void Level::battleMonster(Player &player, int targetX, int targetY) {

	int enemyX, enemyY, attackRoll, attackResult, playerX, playerY;
	string enemyName;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++) {

		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();

		if (targetX == enemyX && targetY == enemyY) {
			//Battle
			attackRoll = player.attack();
			printf(" \n \t\t Player attacked %s with a roll of %d \n", enemyName.c_str(), attackRoll);
			attackResult = _enemies[i].takeDamage(attackRoll);

			if (attackResult != 0) {
				setTile(targetX,targetY, '.'); // removes enemy
				print(player);
				player.addExperience(_enemies[i].getStat('e'));
				printf("\t\t Monster died! \n");
				_enemies[i] = _enemies.back(); // removes enemy
				_enemies.pop_back();
				i--;
				system("pause");
				
				return;
			}
			
			//Enemy turn
			attackRoll = _enemies[i].attack();
			printf(" \n \t\t%s attacked player with a roll of %d \n", enemyName.c_str(), attackRoll);
			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0) {
				if (_enemies[i].getTile() == 'D') {
					int elapsed = time(0) - timetaken;
					//setTile(playerX, playerY, 'X');
					print(player);
					printf("\t\t You found your pet Dragon, now you can escape!. \n\t\t\t\t You won! \n");
					cout << "\t\t Level: " << player.getStat('l');
					cout  << "\t\t Time taken: " << elapsed << endl;
					cout << "\t\t\t Number of Moves: " << player.numMoves << endl << endl << endl;

					ofstream outfile;
					outfile.open("highscores.txt", ios::app);
					outfile << player.numMoves << "\t" << player.getPName() << "\t" << elapsed << "\t" << player.getStat('l') << endl;
					outfile.close();
				}

				else {
					setTile(playerX, playerY, 'X');
					print(player);
					printf("\t\t You lost! \n");
					cout << "\t\t Level: " << player.getStat('l') << endl;
					printf("\t\t %s killed you \n", enemyName.c_str());
					int elapsed = time(0) - timetaken;
					cout << "\t\t Time taken: " << elapsed << endl << endl << endl;;
				}

				bool valid = false; // prevent terminal closing instantly
				while (!valid) {
					char input = _getch();
					switch (input) {
					case 'w':
					case 'a':
					case 's':
					case 'd':
						system("pause");
						break;
					default:
						valid = true;
						break;
					}
				}

				endGame = true;
			}
			system("pause");
			return;
		}
	}
}

void Level::movePlayer(char input, Player &player) {

	int playerX, playerY;
	player.getPosition(playerX, playerY);


	switch (input) {
	case 'w': //up
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's': // down
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a': // left
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd': //right
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("invalid input. \n");
		//system("pause");
		break;
	}
}

void Level::processPlayerMove(Player &player, int targetX, int targetY) {

	int playerX, playerY;
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
		// doesnt move into wall only 1 case allows to move
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.'); // previous position deleted
		setTile(targetX, targetY, '@'); // new position added
		player.numMoves++;
		break;
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;

	}
}


void Level::updateEnemies(Player &player) {
	char aiMove;

	int playerX, playerY;
	int enemyX, enemyY;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++) {
		aiMove = _enemies[i].getMove(playerX,playerY);
		_enemies[i].getPosition(enemyX, enemyY);

		switch (aiMove) {
		case 'w': //up
			processEnemyMove(player,i, enemyX, enemyY - 1);
			break;
		case 's': // down
			processEnemyMove(player,i, enemyX, enemyY + 1);
			break;
		case 'a': // left
			processEnemyMove(player,i, enemyX - 1, enemyY);
			break;
		case 'd': //right
			processEnemyMove(player,i, enemyX + 1, enemyY);
			break;
		
		}
	}
}

void Level::processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY) {

	int playerX, playerY, enemyX, enemyY;

	_enemies[enemyIndex].getPosition(enemyX,enemyY);
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
		// doesnt move into wall only 1 case allows to move
	case '.':
		_enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, _enemies[enemyIndex].getTile());
		break;
	case '#':
		break;
	case '@':
		battleMonster(player, enemyX, enemyY);
	default:
		break;
	}
}

