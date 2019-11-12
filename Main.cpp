#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "Gamesystem.h"
#include "HScores.h"
using namespace std;

int main() {

	char input;
	bool valid = false;

	while (!valid) {

		Gamesystem gamesystem("level1.txt");
		gamesystem.playGame();

		bool valid1 = false;

		while (!valid1) {


			printf("\t\tPlay Again? (y/n)");
			cin >> input;

			switch (input) {
			case 'y':
			case 'n':
				valid1 = true;
				break;
			default:
				printf("\t\tPlay Again? (y/n)");
				cin >> input;
				break;
			}
		}

		switch (input) {
		case 'n':
			valid = true;
			break;
		}
	}

	system("pause");
	return 0;
}