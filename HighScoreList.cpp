#include "HighScoreList.h"


HighScoreList::HighScoreList() {
	head = NULL;
	tail = NULL;
}

void HighScoreList::addStu(int newmoves,string newName, int newTime, int newLevel) {

	Node* newNode = new Node(newmoves, newName, newTime, newLevel);
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}

	else {
		tail->setNext(newNode);
		tail = newNode;
	}
}

void HighScoreList::printAllStudents(Player _player) {
	Node* temp;
	temp = head->getNext();
	int i = 1, count =0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (temp != NULL) {

		if (temp->getName() == _player.getPName()) {
			SetConsoleTextAttribute(hConsole, 10);
			cout << i;
			temp->printNode();
			SetConsoleTextAttribute(hConsole, 15);
		}

		else {
			cout << i;
			i++;
			temp->printNode();
		}

		temp = temp->getNext();
		
		
	}
}

Node* HighScoreList::partition(Node *head, Node* end, Node* *newHead, Node* *newEnd)
{
	Node *pivot = end;
	Node *prev = NULL, *cur = head, *tail = pivot;


	while (cur != pivot)
	{
		if (((1/(cur->getLevel())) + (cur->getMoves() + cur->getTime())) < (((1/pivot->getLevel())  + (pivot->getMoves() + pivot->getTime()))))
		{

			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->getNext();;
		}

		else
		{
			if (prev)
				prev->setNext(cur->getNext());

			Node *tmp = cur->getNext();
			cur->setNext(NULL);
			tail->setNext(cur);
			tail = cur;
			cur = tmp;
		}
	}


	if ((*newHead) == NULL)
		(*newHead) = pivot;

	(*newEnd) = tail;

	return pivot;
}

Node* HighScoreList::quickSortRecur(Node *head, Node *end)
{

	if (!head || head == end)
		return head;

	Node *newHead = NULL, *newEnd = NULL;
	Node *pivot = partition(head, end, &newHead, &newEnd);


	if (newHead != pivot)
	{

		Node *tmp = newHead;
		while (tmp->getNext() != pivot)
			tmp = tmp->getNext();
		tmp->setNext(NULL);

		newHead = quickSortRecur(newHead, tmp);

		tmp = getTail(newHead);
		tmp->setNext(pivot);
	}

	pivot->setNext(quickSortRecur(pivot->getNext(), newEnd));
	
	return newHead;
}


void HighScoreList::quickSort(Node **headRef)
{
	*headRef = quickSortRecur(*headRef, getTail(*headRef));
	return;
}

Node* HighScoreList::gethead() {
	return head;
}

Node* HighScoreList::getTail(Node *cur)
{
	while (cur != NULL && cur->getNext() != NULL)
		cur = cur->getNext();
	return cur;
}

