#include <random>
#include "Player.h"
#include <ctime>


Player::Player() {
	_x = 0;
	_y = 0; //level st appropriate position regardless
}

//Initializes palyers' properties
void Player::init(int level, int health, int attack, int defense, int experience) {
	player_stats.StatsInit(level, health, attack, defense, experience);
}

//Sets the position of the player 
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

void Player::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

void Player::addExperience(int experience) {
	player_stats.setStat('e',player_stats.getStat('e') + experience);
	
	// Level up
	
	while (player_stats.getStat('e') > 140) {
		printf("\t\t Leveled up! \n");

		player_stats.setStat('e', player_stats.getStat('e') - 140);
		player_stats.setStat('a', player_stats.getStat('a') + 10);
		player_stats.setStat('d', player_stats.getStat('d') + 5);
		player_stats.setStat('h', player_stats.getStat('h') + 10);
		player_stats.setStat('l', player_stats.getStat('l') + 1);

		cout << "\t\t Level  " << player_stats.getStat('l') << endl;
	}
}

int Player::attack() {
	return player_stats.attack();
}

int Player::takeDamage(int attack) {
	return player_stats.takeDamage(attack);
}

int Player::getexperience() {
	return player_stats.getStat('e');
}

int Player::getfov() {
	return fov;
}

void Player::setfov(int newfov) {
	fov = newfov;
}

void Player::setStat(char stat, int value) {
	player_stats.setStat(stat, value);
}

int Player::getStat(char stat) {
	return player_stats.getStat(stat);

}

string Player::getPName() {
	return name;
}

void Player::setPName(string newname) {
	name = newname;
}