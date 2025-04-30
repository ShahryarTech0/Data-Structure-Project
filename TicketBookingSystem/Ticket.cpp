#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

Ticket::Ticket() {
	totalDistance = 0;
	totalTime = 0;
	totalFare = 0;
}
void Ticket::setFromStation(string fromStation) {
	this->fromStation = fromStation;
}
void Ticket::setToStation(string toStation) {
	this->toStation = toStation;
}

void Ticket::setTicketId(std::string ticketId) {
	this->ticketId;
}
void Ticket::setTotalDistance(int totalDistance) {
	this->totalDistance = totalDistance;
}
void Ticket::setTotalTime(int totalTime) {
	this->totalTime = totalTime;
}
void Ticket::setTotalFare(int totalFare) {
	this->totalFare = totalFare;
}
void Ticket::display() {
	cout << "Ticket Id : " << ticketId << endl;
	cout << "From Station : " << fromStation<<endl;
	cout << "To Station : " << toStation << endl;
	cout << "Total Distance : " << totalDistance << endl;
	cout << "Total Time : " << totalTime << endl;
	cout << "Total Fare : " << totalFare << endl;
}