#ifndef TICKET_H
#define TICKET_H

#include<iostream>
#include<string>


class Ticket {
	std::string ticketId;
	std::string fromStation;
	std::string toStation;
	int totalDistance;
	int totalTime;
	int totalFare;
public:
	Ticket();
	void setFromStation(std::string fromStation);
	void setToStation(std::string toStation);
	void setTicketId(std::string ticketId);
	void setTotalDistance(int totalDistance);
	void setTotalTime(int totalTime);
	void setTotalFare(int totalFare);
	void display();
};


#endif // !TICKET_H
