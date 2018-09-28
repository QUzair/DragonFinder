#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int next_field(ifstream& csv, char * buffer, int max_len);

int main() {

	ifstream csv;
	csv.open("items.csv");

	if (!csv) {
		perror("Error opening file");
		system("pause");
	}



	int returned;
	int field = 1;
	char buffer[50];
	int mlen = 20;
	string name, bb, line, category;
	int price, quantity;

	while (true) {
		returned = next_field(csv, buffer, mlen);

		if (returned == 0) {
			printf("fieldnum %d \n", field);
			switch (field) {
			case 1:
				line = buffer;
				cout << "[" << line << "]" << endl;
				break;
			case 2:
				category = buffer;
				cout << "[" << category << "]" << endl;
				break;
			case 3:
				name = buffer;
				cout << "[" << name << "]" << endl;
				break;
			case 4:
				bb = buffer;
				cout << "[" << bb << "]" << endl;
				break;
			case 5:
				price = atoi(buffer);
				cout << "[" << price << "]" << endl;
				break;
			case 6:
				quantity = atoi(buffer);
				cout << "[" << quantity << "]" << endl;
				break;
			}
			field++;
		}

		else if (returned == 1) {
			field = 0;
			quantity = atoi(buffer);
			cout << line << endl;
			printf("\n");
		}
		else if (returned == -1) {
			field = 0;
			quantity = atoi(buffer);
			cout << line << endl;
			printf("\nReached end of file\n");
			break;
		}
	}

	system("pause");
	return 0;
}




int next_field(ifstream& csv, char * buffer, int max_len) {
	bool inQuote = false;
	char c;
	int n = 0;

	while (true && n<max_len) {
		(csv).get(c);
		if (csv.eof()) return -1;
		if (c == '\n' || (csv).eof()) {
			buffer[n] = '\0';
			return 1;
		}
		else if (c == '"') inQuote = !inQuote;
		else if (c == ',' && !inQuote) {
			buffer[n] = '\0';
			return 0;
		}

		else {
			buffer[n] = c;
			n++;
		}
	}

}