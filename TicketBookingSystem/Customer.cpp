#include<iostream>
#include<string>
#include "Customer.h"
using namespace std;


Customer::Customer()
{
	firstName = "";
	lastName = "";
	phoneNumber = "";
	passportNumber = "";
}
Customer::Customer(string firstName, string lastName, string phoneNumber, string passportNumber) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->passportNumber = passportNumber;
}
void Customer::setFirstName(string firstName){
	this->firstName = firstName;
}
void Customer::setLastName(string lastName)
{
	this->lastName = lastName;
}
void Customer::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Customer::setPassportNumber(string passportNumber) {
	this->passportNumber = passportNumber;
}
string Customer::getFirstName() const {
	return this->firstName;
}
string Customer::getLastName() const {
	return this->lastName;
}
string Customer::getFullName() const {
	return this->firstName + " " + this->lastName;
}
string Customer::setPhoneNumber() const {
	return this->phoneNumber;
}
string Customer::getPassportNumber() const {
	return this->passportNumber;
}

void Customer::display()
{
	cout << "Name : " << getFullName() << endl;
	cout << "Phone      : " << phoneNumber << endl;
	cout << "Passport   : " << passportNumber << endl;

}