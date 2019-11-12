#include "Gamesystem.h"
#include <ctime>
//Constructor sets up the game
Gamesystem::Gamesystem(string levelFileName) {
	
	_level.load(levelFileName, _player);
	_level.print(_player);
}

void Gamesystem::playGame() {

	cout << "\n\n\t\t OH hek. U lost ur  dragon (D) find him to excape this maze. \n\t\t Be vary theres nasty monsteros lurking that follow you.\n\t\t If you dare come close \n\n";
	system("pause");

	string pname;
	cout << "\t\t What is your nickname, adventurer: ";
	cin >> pname;
	_player.setPName(pname);
	setDifficulty();

	bool isDone = false;

	while (endGame() == false) {
		_level.print(_player);
		playerMove();
		_level.updateEnemies(_player);
	}

	HScores HighScores;
	HighScores.orderHScores(_player);
}

void Gamesystem::playerMove() {
	char input;
	cout << "\n\n\n" << setw(30) << " Enter a move command (w/a/s/d): ";
	
	input = _getch();
	_level.movePlayer(input, _player);
	
}

bool Gamesystem::endGame() {
	return _level.endGame;
}

void Gamesystem::setDifficulty() {
	string difficulty;

	
	bool valid = false;
	while (!valid) {

		printf("\n\t\tWhat difficulty do you require?: (HARD/MEDIUM/EASY): ");
		cin >> difficulty;
		cout << endl;

		if (difficulty == "HARD" || difficulty == "hard") {
			_player.setfov(3);
			valid = true;
		}
		else if (difficulty == "MEDIUM" || difficulty == "medium") {
			_player.setfov(7);
			valid = true;
		}
		else if (difficulty == "EASY" || difficulty == "easy") {
			_player.setfov(10);
			valid = true;
		}
		else {
			printf("\n\t\tPlease enter appropriate difficulty. \n");
		}
	}
}

Player Gamesystem::getPlayer() {
	return _player;
}




