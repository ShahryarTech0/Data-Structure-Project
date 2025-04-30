#include<iostream>
#include <string>
#include <vector>
#include "Database.h"
#include<algorithm>
#include "UtilityFunctions.h"
using namespace std;

Database::Database() {
	stations = new DoubleLinkedList();
	populateStations();

}
void Database::addPurchase(Purchase* purchase) {
	this->purchase.push_back(purchase);
}
void Database::viewSpecificPurchaseHistory(std::string passportNumber) {
	for (int i = 0; i < purchase.size(); i++)
	{
		if (UtilityFunctions::convertStringToUpperCase(purchase[i]->getCustomer()->getPassportNumber()).compare(UtilityFunctions::convertStringToUpperCase(passportNumber)) == 0)
		{
			 purchase[i]->display();
		}
	}

}
void Database::viewPurchaseHistory() {
	for (int i = 0; i < purchase.size(); i++)
	{
			purchase[i]->display();
	}
}
void Database::viewSortedPruchaseHistory() {
	vector<Purchase* > tempPurchase(purchase);
	//sort(tempPurchase.begin(), tempPurchase.end(), comparePurchase);
	//viewPurchaseHistory();
	for (int i = 0; i < tempPurchase.size(); i++)
	{

	}
	int n = purchase.size();
	for (int i = 1; i < n; ++i) {
		Purchase* key = tempPurchase[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && comparePurchase(tempPurchase[j], key)) {
			tempPurchase[j + 1] = tempPurchase[j];
			j = j - 1;
		}
		tempPurchase[j + 1] = key;
	}
	viewPurchaseHistory();
}


bool Database::comparePurchase(Purchase* p1, Purchase* p2)
{
	return UtilityFunctions::convertStringToUpperCase(p1->getCustomer()->getFullName()).compare(UtilityFunctions::convertStringToUpperCase(p1->getCustomer()->getFullName())) <= 0;
}
void Database::deletePurchaseHistory(std::string transactionId) {
	bool isDeleted = false;
	for (int i = 0; i < purchase.size(); i++)
	{
		if (UtilityFunctions::convertStringToUpperCase(purchase[i]->getTransactionId()).compare(UtilityFunctions::convertStringToUpperCase(transactionId)) == 0)
		{
			isDeleted = true;
			purchase.erase(purchase.begin() + i);
			break;

		}
	}
	if (isDeleted)
	{
		cout << "Transaction with id " << transactionId << " deleted successfully.\n";
	}
	else {
		cout << "Transaction with id " << transactionId << " does not exist.\n";

	}
}

void Database::populateStations() {
	//	Node* firstCity =;
	stations->addNode(new Node(new Station(UtilityFunctions:: generateSubwayId(), 1, 4, 0.4, 0, 0, 0, "Karachi"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 7, 8, 0.8, 3, 4, 0.4, "Hyderabad"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 7, 8, 0.8, 7, 8, 0.8, "Nawabshah"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 5, 6, 0.6, 7, 8, 0.8, " Larkana"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 9, 10, 1, 5, 6, 0.6, "Sukkur"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 4, 5, 0.5, 9, 10, 1, "MUltan"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 4, 5, 0.5, 4, 5, 0.5, "Faislabad"), nullptr, nullptr), stations->getSize());
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), 0, 0, 0, 4, 5, 0.5, "Islamabad"), nullptr, nullptr), stations->getSize());
}
void Database::Add_new_subway_station_information(int  nextStationTime, int nextStationDistance, double nextStationFair, int previousStationTime, int prviousStationDistance, double previousStaitonFair,std::string currentStationName)
{
	stations->addNode(new Node(new Station(UtilityFunctions::generateSubwayId(), nextStationTime, nextStationDistance, nextStationFair, previousStationTime, prviousStationDistance, previousStaitonFair, currentStationName), nullptr, nullptr), stations->getSize());
}

//int  nextStationTime, int nextStationDistance, double nextStationFair,
//int previousStationTime, int prviousStationDistance, double previousStaitonFair, string currentStationName)


DoubleLinkedList* Database::getStations() {
	return this->stations;
}