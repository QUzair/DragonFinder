#include "Node.h"


Node::Node() {

}
Node::Node(int newmoves, string newName,  int newTime , int newLevel) {
	moves = newmoves;
	name = newName;
	level = newLevel;
	time = newTime;
	next = NULL;
}

void Node::setNext(Node* newNext) {
	next = newNext;
}

void Node::setMoves(int newmoves) {
	moves = newmoves;
}

void Node::setName(string newname) {
	name = newname;
}

void Node::setTime(int newTime) {
	time = newTime;
}

void Node::setLevel(int newLevel) {
	level = newLevel;
}

int Node::getMoves() {
	return moves;
}
string Node::getName() {
	return name;
}

int Node::getTime() {
	return time;
}

int Node::getLevel() {
	return level;
}

Node* Node::getNext() {
	return next;
}

void Node::printNode() {
	cout << "\t\t" << moves << "\t" << name << "\t" << time << "\t" << level << endl;
}