#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

Node::Node() {
	next = previous = nullptr;
	station = nullptr;
}
Node::Node(Station* station, Node* next, Node* previous) {
	this->station = station;
	this->next = next;
	this->previous = previous;
}
void Node::setNext(Node* next) {
	this->next=next;
}
void Node::setPrevious(Node* previous){
	this->previous = previous;
}
void Node::setStation(Station* station) {
	this->station = station;
}
Node* Node::getNext()const {
	return this->next;
}
Node* Node::getPrevious()const {
	return this->previous;
}
Station* Node::getStation()const {
	return this->station;
}


void Node::display() {
	station->display();
	cout << "Next Station Name         :   ";
	if (next == nullptr) {
		cout << " -- " << endl;
	}
	else {
		cout << next->getStation()->getCurrentStationName() << endl;
	}
	cout << "Previous Station Name     :   ";
	if (previous == nullptr) {
		cout << " -- " << endl;
	}
	else {
		cout << previous->getStation()->getCurrentStationName() << endl;
	}
}