#include<iostream>
#include <string>
#include "ApplicationView.h"
#include "UtilityFunctions.h"
using namespace std;
ApplicationView::ApplicationView() {
	database = new Database();
	isForward = true;


}
//int ApplicationView::takeInput(int min, int max) {
//	string choice = "";
//	getline(cin, choice);
//	int ch = 0;
//	bool isCorrectValue = false;
//	do {
//		while (!UtilityFunctions::checkIsInteger(choice))
//		{
//			cout << "Enter Valid value." << endl;
//			getline(cin, choice);
//		}
//		ch = stoi(choice);
//		if (ch >= min && ch <= max)
//		{
//			isCorrectValue = true;
//		}
//		else {
//			choice = "a";
//		}
//	} while (!isCorrectValue);
//	return ch;
//}
int ApplicationView::mainScreenForPassenger() {
	cout << "Press : \n";
	cout << "1 : For route from Karachi to Islamabad" << endl;
	cout << "2 : For route from Islamabad to Karachi" << endl;
	cout << "3 : For Exit." << endl;
	cout << "Enter choice : ";

	int ch;
	cin >> ch;
	if (ch == 3) {
		return 3;

	}
	else if (ch == 1) {
		isForward = true;
	}
	else if (ch == 2) {
		isForward = false;
	}
	return true;
}
void ApplicationView::showInnerMenuForPassenger() {
	int ch = 0;
	while (ch != 6)
	{
	cout << "\n\n============================================" << endl;
	cout << "Press : " << endl;
	cout << "1 : For Display All Subway Menu." << endl;
	cout << "2 : Search Subway Detail." << endl;
	cout << "3 : View Detail between two cities." << endl;
	cout << "4 : Purchase Ticket." << endl;
	cout << "5 : View Purchase History." << endl;
	cout << "6 : Exit." << endl;
	cout << "==============================================" << endl;
	cout << "Enter Choice : ";
	
	cin >> ch;
		switch (ch)
		{
		case 1: displaySubwayMenu();
			break;
		case 2: searchSubwayDetails();
			break;
		case 3:displayBetweenTwoCities();
			break;
		case 4:purchaseTicket();
			break;
		case 5:displaySpecificPurchaseHistory();
			break;
		case 6:
			return;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	}

}
Customer * ApplicationView::getCustomerDetails() {
	Customer* customer = new Customer();
	string firstName = "",lastName="",phoneNumber="",passportNumber="";
	cout << "Enter First Name : ";
	fflush(stdin);
	cin >> firstName;
	cout << "Enter Last Name : ";
	fflush(stdin);
	cin >> lastName;
	cout << "Enter Phone Number : ";
	cin >> phoneNumber;
	cout << "Enter Passport Number : ";
	cin >> passportNumber;
	customer->setFirstName(firstName);
	customer->setLastName(lastName);
	customer->setPhoneNumber(phoneNumber);
	customer->setPassportNumber(passportNumber);
	return customer;
}
void ApplicationView::viewPurchaseTransactionHistory() {

}
void ApplicationView::purchaseTicket() {
	cout << "Enter Station 1 Number : ";
	int stationNumber1;
	cin>> stationNumber1;
	if (stationNumber1 > database->getStations()->getSize())
	{
		cout<<"Invalid Input";
	}
	cout << "Enter Station 2 Number : ";
	int stationNumber2 ;
		cin>> stationNumber2;
		if (stationNumber2 > database->getStations()->getSize())	
		{
			cout << "Invalid Input";
		}
	if (stationNumber1 >= stationNumber2)
	{
		cout << "Invalid Station Numbers." << endl;
	}
	else {
		Ticket* ticket = nullptr;
		cout << endl;
		if (isForward) {
			ticket=database->getStations()->getTicketBetweenTwoStationsForForward(stationNumber1, stationNumber2);
		}
		else {
			ticket=database->getStations()->getTicketBetweenTwoStationsForForward(stationNumber1, stationNumber2);
		}
		ticket->setTicketId(UtilityFunctions::generateTicketId());
		Customer* customer = getCustomerDetails();
		Purchase* purchase=new Purchase(UtilityFunctions::generatePurchaseId(),customer,ticket);
		cout << "=====================================================" << endl;
		cout << "               PURCHASED SUCCESSFULLY" << endl;
		cout << "=====================================================" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		purchase->display();
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

		database->addPurchase(purchase);
	}
}

void  ApplicationView::displaySubwayMenu() {
	cout << "---------  SUBWAY STATIONS --------" << endl;
	if (isForward) {
		database->getStations()->displayForwardStationList();
	}
	else {
		database->getStations()->displayBackwordStationList();
	}
	cout << "-----------------------------------" << endl;
}


void ApplicationView::searchSubwayDetails() {
	cout << "Enter Subway Number : ";
	int stationNumber;
	bool input = true;
	while (input) {
		cin >> stationNumber;
		if (stationNumber <= database->getStations()->getSize())
		{
			input = false;
		}
	}
	cout << endl;
	cout << "Subway Details are: " << endl;
	database->getStations()->getNodeAt(stationNumber - 1)->display();
}


void ApplicationView::displayBetweenTwoCities()
{
	cout << "Enter Station 1 Number : ";
	int stationNumber1;
	bool input = true;
	while (input) {
		cin >> stationNumber1;
		if (stationNumber1 <= database->getStations()->getSize())
		{
			input = false;
		}
	}
	cout << "Enter Station 2 Number : ";
	int stationNumber2;
	 input = true;
	while (input) {
		cin >> stationNumber2;
		if (stationNumber2 <= database->getStations()->getSize())
		{
			input = false;
		}
	}
	if (stationNumber1 >= stationNumber2)
	{
		cout << "Invalid Station Numbers." << endl;
	}
	else {
		cout << endl;
		if (isForward) {
			database->getStations()->displayInfoBetweenTwoStationForForward(stationNumber1, stationNumber2);
		}
		else {
			database->getStations()->displayInfoBetweenTwoStationForBackword(stationNumber1, stationNumber2);
		}
	}
}


void ApplicationView:: displaySpecificPurchaseHistory() {
	string passportNumber = "";
	cout << "Enter Passport Number : ";
	getline(cin, passportNumber);
	cout << "      PURCHASE HISTORY " << endl;
	database->viewSpecificPurchaseHistory(passportNumber);
	cout << endl;
}
int ASKPERSON()
{
	cout << "PRESS\n1.PASSENGER\n2.Admin\n3.Exit\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		return 1;
	}
	else if(choice==2)
	{
		return 2;
	}
	else
	{
		return false;
	}
}
bool Enter_Crediantials()
{
	cout << "Enter Admin PIN:";
	int pin;
	
	cin >> pin;
	if (pin == 123)
	{
		return true;
	}
	return false;
}
void ApplicationView::ADD_Station()
{
	int new_station_Time, next_station_Distance, previous_Station_time, prviousStationDistance;
	double nextStationFair, previousStaitonFair;
	std::string currentStationName;
	cout << "Enter new_station_Time" << endl;
	cin >> new_station_Time;
	cout << "Enter next_station_Distance" << endl;
	cin >> next_station_Distance;
	cout << "Enter previous_Station_time" << endl;
	cin >> previous_Station_time;
	cout << "Enter prviousStationDistance" << endl;
	cin >> prviousStationDistance;
	cout << "Enter nextStationFair" << endl;
	cin >> nextStationFair;
	cout << "Enter previousStaitonFair" << endl;
	cin >> previousStaitonFair;
	cout << "Enter currentStationName" << endl;
	cin >> currentStationName;
	database->Add_new_subway_station_information(new_station_Time, next_station_Distance, nextStationFair, previous_Station_time, prviousStationDistance, previousStaitonFair, currentStationName);
	cout << "\nNew Station has been added";
	
}
void ApplicationView::showInnerMenuForAdmin()
{
	int ch = 0;
	while (ch != 8)
	{
		cout << "\n\n============================================" << endl;
		cout << "Press : " << endl;
		cout << "1 : For Add new Subway Station." << endl;	
		cout << "2 : For View all purshase." << endl;
		cout << "3 : For sort puchase." << endl;
		cout << "4 : Delete specific customer ticket purchase information." <<endl;
		cout << "5 : Exit. "<<endl;
		cout << "==============================================" << endl;
		cout << "Enter Choice : ";
		cin >> ch;
		if (ch == 5)
		{
			break;
		}
			switch (ch) {

			case 1:
				ADD_Station();
				break;
			case 2:
				database->viewPurchaseHistory();
				break;
			case 3:
				database->viewSortedPruchaseHistory();
				break;
			case 4:
				std::string id_S;
				cout << "\nEnter ID\n";
				cin >> id_S;
				database->deletePurchaseHistory(id_S);
				break;
				
			}
		
	}

}
void ApplicationView::startApp() {
	bool appliaction=true;
	while (appliaction){
		int ask = ASKPERSON();
	
		if (ask==1) {
			int ch = 0;
			do {
				system("cls");
				ch = mainScreenForPassenger();
				if (ch != 3) {
					system("cls");
					showInnerMenuForPassenger();
				}
			} while (ch != 3);
		}
		else if(ask == 2)
		{
			system("cls");
			if (Enter_Crediantials())
			{
				system("cls");
				showInnerMenuForAdmin();
			}
			else
			{
				cout << "----------------------ENTERING FAILED--------------------";
			}


		}
		else
		{
			appliaction = false;
		}

	}
}