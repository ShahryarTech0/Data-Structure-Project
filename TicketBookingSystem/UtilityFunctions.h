#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTION_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class UtilityFunctions
{
	static int stationId ;
	static int purchaseId;
	static int ticketId;
public:

	static void replaceAll(string& s, const string& search, const string& replace, size_t startingPosition = 0);
	static vector<string> split(string stringToBeSplitted, string delimeter);
	static vector<string> split(string str, char delimiter);
	static string removeSpacesAndAllowAlphaNumerice(string str);
	static string removeSpaces(string str);
	static string center(const string s, const int w, string spaces = " ");
	static string displayContent(const string stringaData = "", const int intData = 0, const float floatData = 0.0, const int type = 1, const int decDigits = 2, const int width = 5, const int side = 1);
	static void removeDataFromVector(vector<string>& dat, int till);
	static int  countWordLengthTillSize(vector<string>& dat, int till);
	static string trim(string s);
	static string convertStringToUpperCase(string s);
	static vector<string> splitBySpecificForInsert(string stringToBeSplitted, char delimeter);
	static bool checkIsFloat(string myString);
	static bool checkIsAlphaNumeric(string s);
	static bool checkIsInteger(string s);
	static string generateSubwayId() {
		return "S_" + to_string(stationId++);
	}
	static string generateTicketId() {
		return "T_" + to_string(ticketId++);
	}
	static string generatePurchaseId() {
		return "P_" + to_string(purchaseId++);
	}

};
#endif