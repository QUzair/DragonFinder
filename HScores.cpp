#include "HScores.h"


void HScores::orderHScores(Player _player) {

	HighScoreList HighScores;
	ifstream dataFile;
	string name;
	int moves, time, level;

	dataFile.open("highscores.txt", ios::in);

	while (dataFile.fail()) {
		cout << "HighScore File not found.";
		exit(0);
	}


	while (!dataFile.eof()) {
		dataFile >> moves >> name>> time >> level;
		HighScores.addStu(moves, name, time, level);
	
	}

	Node* headref = HighScores.gethead();
	HighScores.quickSort(&headref);
	cout << "\n\t\t" << "Moves" << "\t" << "Name" << "\t" << "Time" << "\t" << "Level";
	cout << "\n\t\t" << "-----" << "\t" << "----" << "\t" << "----" << "\t" << "-----" << endl;

	HighScores.printAllStudents(_player);
	cout << endl << endl;
}











