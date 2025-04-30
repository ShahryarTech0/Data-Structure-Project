#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
	this->head = nullptr;
	this->size = 0;
}
void DoubleLinkedList::addNode(Node* node, int index) {
	if (index == 0) {
		if (head == nullptr)
		{
			head = node;
		}
		else {
			node->setNext(head);
			head->setPrevious(node);
			head = node;
		}
	}
	else if(index==size) {
		Node* temp = head;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		node->setPrevious(temp);
		temp->setNext(node);
	}
	else {
		Node* temp = getNodeAt(index);
		temp->getPrevious()->setNext(node);
		node->setPrevious(temp->getNext());
		node->setNext(temp);
		temp->setPrevious(node);
	}
	size++;
}
Node* DoubleLinkedList::getNodeAt(int index) {
	int currentIndex = 0;
	Node* temp = head;
	while (temp != nullptr && index != currentIndex)
	{
		temp = temp->getNext();
		currentIndex++;
	}
	return temp;
}
int DoubleLinkedList::getSize() {
	return size;
}

void DoubleLinkedList::displayForwardStationList() {

	Node* temp=head;
	int sno = 1;
	while (temp !=nullptr)
	{
		cout << sno++ << " -- " << temp->getStation()->getCurrentStationName() << endl;
		temp = temp->getNext();
	}

}

void DoubleLinkedList::displayBackwordStationList() {

	Node* temp = getNodeAt(size-1);
	int sno = 1;
	while (temp != nullptr)
	{
		cout << sno++ << " -- " << temp->getStation()->getCurrentStationName() << endl;
		temp = temp->getPrevious();
	}

}

void DoubleLinkedList:: displayInfoBetweenTwoStationForForward(int station1, int station2) {

	Node* start = getNodeAt(station1);
	Node* end = getNodeAt(station2);
	string startStationName = start->getStation()->getCurrentStationName();
	int totalDistance = 0;
	int totalTime = 0;
	double totalFare = 0;
	while (start != end)
	{
		totalDistance += start->getStation()->getNextStationDistance();
		totalTime += start->getStation()->getNextStationTime();
		totalFare += start->getStation()->getNextStationFair();
		start = start->getNext();
	}

	cout << "   Detail between  " << startStationName << " and " << end->getStation()->getCurrentStationName() << endl;
	cout << "Total Distance : " << totalDistance << endl;
	cout << "Total Time : " << totalTime << endl;
	cout << "Total Fare : " << totalFare << endl;
}

void DoubleLinkedList::displayInfoBetweenTwoStationForBackword(int station1, int station2) {

	Node* start = getNodeAt(station1);
	Node* end = getNodeAt(station2);
	string startStationName = start->getStation()->getCurrentStationName();
	int totalDistance = 0;
	int totalTime = 0;
	double totalFare = 0;
	while (start != end)
	{
		totalDistance += start->getStation()->getNextStationDistance();
		totalTime += start->getStation()->getNextStationTime();
		totalFare += start->getStation()->getNextStationFair();
		start = start->getPrevious();
	}

	cout << "   Detail between  " << startStationName << " and " << end->getStation()->getCurrentStationName() << endl;
	cout << "Total Distance : " << totalDistance << endl;
	cout << "Total Time : " << totalTime << endl;
	cout << "Total Fare : " << totalFare << endl;
}


Ticket * DoubleLinkedList::getTicketBetweenTwoStationsForForward(int station1, int station2) {


	Node* start = getNodeAt(station1);
	Node* end = getNodeAt(station2);
	string startStationName = start->getStation()->getCurrentStationName();
	int totalDistance = 0;
	int totalTime = 0;
	int totalFare = 0;
	while (start != end)
	{
		totalDistance += start->getStation()->getNextStationDistance();
		totalTime += start->getStation()->getNextStationTime();
		totalFare += start->getStation()->getNextStationFair();
		start = start->getNext();
	}

	Ticket* ticket = new Ticket();
	ticket->setFromStation(startStationName);
	ticket->setToStation(end->getStation()->getCurrentStationName());
	ticket->setTotalDistance(totalDistance);
	ticket->setTotalTime(totalTime);
	ticket->setTotalFare(totalFare);

	return ticket;
}

Ticket * DoubleLinkedList::getTicketBetweenTwoStationsForBackward(int station1, int station2) {

	Node* start = getNodeAt(station1);
	Node* end = getNodeAt(station2);
	string startStationName = start->getStation()->getCurrentStationName();
	int totalDistance = 0;
	int totalTime = 0;
	int totalFare = 0;
	while (start != end)
	{
		totalDistance += start->getStation()->getNextStationDistance();
		totalTime += start->getStation()->getNextStationTime();
		totalFare += start->getStation()->getNextStationFair();
		start = start->getPrevious();
	}

	Ticket* ticket = new Ticket();
	ticket->setFromStation(startStationName);
	ticket->setToStation(end->getStation()->getCurrentStationName());
	ticket->setTotalDistance(totalDistance);
	ticket->setTotalTime(totalTime);
	ticket->setTotalFare(totalFare);

	return ticket;
}