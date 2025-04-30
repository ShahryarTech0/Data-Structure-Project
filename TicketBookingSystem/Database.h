#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "DoubleLinkedList.h"
#include "Purchase.h"

class Database {
	DoubleLinkedList* stations;
	std::vector<Purchase*> purchase;
public:
	Database();
	void addPurchase(Purchase* purchase);
	void viewSpecificPurchaseHistory(std::string passportNumber);
	void viewPurchaseHistory();
	void viewSortedPruchaseHistory();
	void deletePurchaseHistory(std::string purchaseId);
	bool comparePurchase(Purchase* p1, Purchase* p2);
	void populateStations();
	DoubleLinkedList* getStations();
	void Add_new_subway_station_information(int  nextStationTime, int nextStationDistance, double nextStationFair, int previousStationTime, int prviousStationDistance, double previousStaitonFair,std::string  currentStationName);
};

#endif // !DATABASE_H
