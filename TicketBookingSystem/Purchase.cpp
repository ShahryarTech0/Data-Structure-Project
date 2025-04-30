#include<iostream>
#include <string>
#include "Purchase.h"
using namespace std;

Purchase::Purchase() {

}
Purchase::Purchase(string tranactionId, Customer* customer, Ticket* ticket) {
	this->tranactionId = tranactionId;
	this->customer = customer;
	this->ticket = ticket;
}
void Purchase::setTransactionId(string tranactionId) {
	this->tranactionId = tranactionId;
}
void Purchase::setCustomer(Customer* customer) {
	this->customer = customer;
}
void Purchase::setTicket(Ticket* ticket) {
	this->ticket = ticket;
}
string Purchase::getTransactionId()
{
	return this->tranactionId;
}
Customer* Purchase::getCustomer() {
	return this->customer;
}
Ticket* Purchase::getTicket() {
	return this->ticket;
}
void Purchase::display() {

	cout << "Purchase Id : " << this->tranactionId << endl;
	cout << "     ===Ticket Detail===" << endl;
	ticket->display();
	cout << "     === Customer Detail===" << endl;

	customer->display();
}