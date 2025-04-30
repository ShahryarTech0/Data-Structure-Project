#ifndef APPLICATIONVIEW_H
#define APPLICATIONVIEW_H


#include <iostream>
#include "Database.h"
class ApplicationView {
	Database* database;
	bool isForward;

	int mainScreenForPassenger();
	void showInnerMenuForPassenger();
	void showInnerMenuForAdmin();
	Customer* getCustomerDetails();
	void viewPurchaseTransactionHistory();
	void purchaseTicket();
	//int takeInput(int min, int max);
	void displaySubwayMenu();
	void searchSubwayDetails();
	void displayBetweenTwoCities();
	void displaySpecificPurchaseHistory();
	void ADD_Station();

public:

	ApplicationView();
	void startApp();


};

#endif // !APPLICATIONVIEW_H
