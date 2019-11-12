#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include <windows.h>
#include "Player.h"
using namespace std;


class HighScoreList {

public:
	HighScoreList();
	
	void addStu(int newmoves,string newName,int newTime, int newLevel);
	
	void printAllStudents(Player);
	
	Node* gethead();
	void quickSort(Node **headRef);
	Node* getTail(Node *cur);
	Node* quickSortRecur(Node *head, Node *end);
	Node* partition(Node *head, Node* end, Node* *newHead, Node* *newEnd);

private:
	Node* head;
	Node* tail;
};
