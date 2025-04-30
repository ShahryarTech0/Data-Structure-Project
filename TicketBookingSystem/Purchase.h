#ifndef PURCHASE_H
#define PURCHASE_H

#include<iostream>
#include <string>
#include "Ticket.h"
#include "Customer.h"

class Purchase {
	std::string tranactionId;
	Customer* customer;
	Ticket* ticket;
public:
	Purchase();
	Purchase(std::string tranactionId, Customer* customer, Ticket* ticket);
	void setTransactionId(std::string tranactionId);
	void setCustomer(Customer* customer);
	void setTicket(Ticket* ticket);
	std::string getTransactionId();
	Customer* getCustomer();
	Ticket* getTicket();
	void display();

};


#endif // !PURCHASE_H
