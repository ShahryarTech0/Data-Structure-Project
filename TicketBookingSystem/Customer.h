#ifndef CUSTOMER_H
#define CUSTOMER_H



#include <iostream>
#include<string>

class Customer {
	std::string firstName;
	std::string lastName;
	std::string  phoneNumber;
	std::string passportNumber;
public:
	Customer();
	Customer(std::string, std::string, std::string, std::string);
	void setFirstName(std::string);
	void setLastName(std::string);
	void setPhoneNumber(std::string);
	void setPassportNumber(std::string);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getFullName() const;
	std::string setPhoneNumber() const;
	std::string getPassportNumber() const;
	void display();



};


#endif // ! CUSTOMERH