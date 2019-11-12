#pragma once
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include <CoreWindow.h>
#include "HScores.h"
#include <iomanip>

class Gamesystem {

public:
	Gamesystem(string fileName);
	void playGame();
	void playerMove();
	bool endGame();
	void setDifficulty();


	Player getPlayer();
private:
	Level _level;
	Player _player;

};