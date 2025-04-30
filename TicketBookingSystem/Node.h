#ifndef NODE_H
#define NODE_H

#include<iostream>
#include <string>
#include "Station.h"

class Node {
	Station* station;
	Node* next;
	Node* previous;
public:
	Node();
	Node(Station* station, Node* next, Node* previous);
	void setNext(Node* next);
	void setPrevious(Node* previous);
	void setStation(Station* station);
	Node* getNext()const;
	Node* getPrevious()const;
	Station* getStation()const;
	void display();
};


#endif // !NODE_H
