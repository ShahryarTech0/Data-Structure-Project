#include <iostream>
#include "Station.h"
#include<string>
using namespace std;

Station::Station() {
	subwayId = "unknown";
	this->nextStationDistance = 0;
	this->nextStationTime = 0;
	this->nextStationFair = 0;
	this->previousStaitonFair = 0;
	this->previousStationTime = 0;
	this->prviousStationDistance = 0;
	this->currentStationName = "unknown";
}
Station::Station(string subwayId, int  nextStationTime, int nextStationDistance, double nextStationFair,
	int previousStationTime, int prviousStationDistance, double previousStaitonFair, string currentStationName) {
	this->subwayId = subwayId;
	this->nextStationDistance = nextStationDistance;
	this->nextStationTime = nextStationTime;
	this->nextStationFair = nextStationFair;
	this->previousStaitonFair = previousStaitonFair;
	this->previousStationTime = previousStationTime;
	this->prviousStationDistance = prviousStationDistance;
	this->currentStationName = currentStationName;
}
void Station::setCurrentSatationName(string currentStationName) {
	this->currentStationName = currentStationName;
}
void Station::setSubWayId(string subwayId) {
	this->subwayId = subwayId;
}
void Station::setNextStationTime(int time) {
	if (time > 0) {
		this->nextStationTime = time;
   }
}
void Station::setNextStationDistance(int distance) {
	if (distance > 0)
	{
		this->nextStationDistance = distance;
	}
}
void Station::setNextStationFair(double fair) {
	if (fair > 0)
	{
		this->nextStationFair = 0;
	}
}
void Station::setPreviousStationTime(int time) {
	if (time > 0) {
		this->previousStationTime = time;
	}
}
void Station::setPreviousStationDistance(int distance) {
	if (distance > 0)
	{
		this->prviousStationDistance = distance;
	}
}
void Station::setPreviousStationFair(double fair) {
	if (fair > 0)
	{
		this->previousStaitonFair = fair;
	}
}
string Station::getCurrentStationName()const {
	return this->currentStationName;
}
string Station::getSubwayId()const {
	return this->subwayId;
}
int Station::getNextStationTime()const {
	return this->nextStationTime;
}
int Station::getNextStationDistance()const {
	return this->nextStationDistance;
}
double Station::getNextStationFair()const {
	return this->nextStationFair;
}
int Station::getPreviousStationTime()const {
	return this->previousStationTime;
}
int Station::getPreviousStationDistance()const {
	return this->prviousStationDistance;
}
double Station::getPreviousStationFair()const {
	return this->previousStaitonFair;
}
void Station::display()const {
	cout << "SubwayId                  : " << subwayId << endl;
	cout << "Station Name              :  " << currentStationName << endl;
	cout << "Previous Station Time     :  " << previousStationTime << endl;
	cout << "Previous Station Distance :   " << prviousStationDistance << endl;
	cout << "Previous Station Fair     :   " << previousStaitonFair << endl;
	cout << "Next Station Time         :  " << nextStationTime << endl;
	cout << "Next Station Distance     :   " << nextStationDistance << endl;
	cout << "Next Station Fair         :   " << nextStationFair << endl;
}