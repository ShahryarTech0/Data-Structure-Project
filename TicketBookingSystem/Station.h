#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <string>



class Station {
	std::string subwayId;
	int nextStationTime;
	int nextStationDistance;
	double nextStationFair;
	int previousStationTime;
	int prviousStationDistance;
	double previousStaitonFair;
	std::string currentStationName;
public:
	Station();
	Station(std::string subwayId, int  nextStationTime, int nextStationDistance, double nextStationFair,
		int previousStationTime, int prviousStationDistance, double previousStaitonFair, std::string currentStationName);
	void setCurrentSatationName(std::string currentStationName);
	void setSubWayId(std::string subwayId);
	void setNextStationTime(int time);
	void setNextStationDistance(int distance);
	void setNextStationFair(double fair);
	void setPreviousStationTime(int time);
	void setPreviousStationDistance(int distance);
	void setPreviousStationFair(double fair);
	std::string getCurrentStationName()const;
	std::string getSubwayId()const;
	int getNextStationTime()const;
	int getNextStationDistance()const;
	double getNextStationFair()const;
	int getPreviousStationTime()const;
	int getPreviousStationDistance()const;
	double getPreviousStationFair()const;
	void display()const;
};

#endif
