#pragma once

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {


private:
	int moves;
	string name;
	int time;
	int level;
	Node* next;

public:

	Node();
	Node(int,string, int, int);

	void setMoves(int);
	void setName(string);
	void setTime(int);
	void setLevel(int);

	int getMoves();
	string getName();
	int getTime();
	int getLevel();

	Node* getNext();
	void setNext(Node* newNext);

	void printNode();
};