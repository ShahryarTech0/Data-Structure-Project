#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include "Node.h"

#include "Ticket.h"
class DoubleLinkedList {
	Node* head;
	int size;
public:
	DoubleLinkedList();
	void addNode(Node* node, int index);
	Node* getNodeAt(int index);
	int getSize();
	void displayForwardStationList();
	void displayBackwordStationList();  
	void displayInfoBetweenTwoStationForForward(int station1,int station2);
	void displayInfoBetweenTwoStationForBackword(int station1,int station2);
	Ticket* getTicketBetweenTwoStationsForForward(int station1, int station2);
	Ticket* getTicketBetweenTwoStationsForBackward(int station1, int station2);

};

#endif // !"DOUBLELINKEDLIST_H"
