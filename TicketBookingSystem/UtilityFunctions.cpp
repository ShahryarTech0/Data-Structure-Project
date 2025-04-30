
#include<iostream>
#include<string>
#include "UtilityFunctions.h"
using namespace std;

int UtilityFunctions::stationId = 1;
int UtilityFunctions::purchaseId = 1;
int UtilityFunctions::ticketId = 1;

bool UtilityFunctions::checkIsAlphaNumeric(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 48 && s[i] <= 57))
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}

bool UtilityFunctions::checkIsInteger(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= '0' && s[i] <= '9'))
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}


void UtilityFunctions::replaceAll(string& s, const string& search, const string& replace, size_t startingPosition) {
	for (size_t pos = startingPosition; ; pos += replace.length()) {
		// Locate the substring to replace
		pos = s.find(search, pos);
		if (pos == string::npos) break;
		// Replace by erasing and inserting
		s.erase(pos, search.length());
		s.insert(pos, replace);
	}
}

bool UtilityFunctions::checkIsFloat(string myString) {
	std::istringstream iss(myString);
	float f;
	iss >> noskipws >> f; // noskipws considers leading whitespace invalid
	// Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

string UtilityFunctions::trim(string s)
{
	auto start = s.begin();
	while (start != s.end() && std::isspace(*start)) {
		start++;
	}

	auto end = s.end();
	do {
		end--;
	} while (std::distance(start, end) > 0 && std::isspace(*end));

	return string(start, end + 1);
}


string UtilityFunctions::convertStringToUpperCase(string s)
{
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] = s[i] - 32;
		}
	}
	return s;
}

vector<string> UtilityFunctions::split(string stringToBeSplitted, string delimeter)
{
	vector<string> splittedString;
	int startIndex = 0;
	int  endIndex = 0;
	while ((endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size())
	{

		string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
		splittedString.push_back(val);
		startIndex = endIndex + delimeter.size();

	}
	if (startIndex < stringToBeSplitted.size())
	{
		string val = stringToBeSplitted.substr(startIndex);
		splittedString.push_back(val);
	}
	return splittedString;

}

vector<string> UtilityFunctions::splitBySpecificForInsert(string stringToBeSplitted, char delimeter)
{
	vector<string> splittedString;
	string tempWord = "";
	for (int i = 0; i < stringToBeSplitted.size(); i++)
	{
		if (stringToBeSplitted[i] == delimeter)
		{
			splittedString.push_back(tempWord);

			tempWord = "";
		}
		else
		{
			if (stringToBeSplitted[i] == '\'')
			{
				tempWord += stringToBeSplitted[i++];
				while (i < stringToBeSplitted.size() && stringToBeSplitted[i] != '\'')
				{
					tempWord += stringToBeSplitted[i++];

				}
				if (i >= stringToBeSplitted.size())
				{
					splittedString.push_back(tempWord);
				}
				else
				{
					tempWord += stringToBeSplitted[i];
				}
			}
			else if (stringToBeSplitted[i] == '\"')
			{
				tempWord += stringToBeSplitted[i++];
				while (i < stringToBeSplitted.size() && stringToBeSplitted[i] != '\"')
				{
					tempWord += stringToBeSplitted[i++];

				}
				if (i >= stringToBeSplitted.size())
				{
					splittedString.push_back(tempWord);
				}
				else
				{
					tempWord += stringToBeSplitted[i];
				}

			}
			else {
				tempWord += stringToBeSplitted[i];
			}
		}
	}
	splittedString.push_back(tempWord);

	return splittedString;
}


vector<string> UtilityFunctions::split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}




	return internal;
}

void UtilityFunctions::removeDataFromVector(vector<string>& dat, int till)
{
	if (till <= dat.size())
	{
		for (int i = 0; i < till; i++)
		{
			dat.erase(dat.begin() + 0);
		}
	}
}

int UtilityFunctions::countWordLengthTillSize(vector<string>& dat, int till)
{
	int size = 0;
	if (till <= dat.size())
	{
		for (int i = 0; i < till; i++)
		{
			size += dat[i].size() + 1;
		}
	}

	return size;
}

string UtilityFunctions::removeSpacesAndAllowAlphaNumerice(string str)
{
	int check = 0;       //new string
	char c;
	int index = 0;                //for indexing the new string
	int i = 0;
	//string from which spaces are to be removed
	//string str = "    I    am a    string with     too   many   extra spaces    ";    // change this string
	string newstr = str;
	while (str[i]) {                          //while loop runs till end of string
		c = str[i];
		if (isspace(c) && check == 0) {           //check spaces
			newstr[index++] = str[i];
			check = 1;
		}
		else if (isalnum(c) /*|| c == ',' || c == '(' || c == ')' || c == ';'*/) {                //check alphabets and numbers
			newstr[index++] = str[i];
			check = 0;
		}
		i++;
	}
	newstr = newstr.substr(0, index);
	if (newstr.size() > 0)
		if (newstr[0] == ' ')
		{
			newstr = newstr.substr(1, index);
		}
	if (newstr.size() > 0)
		if (newstr[newstr.size() - 1] == ' ')
		{
			newstr = newstr.substr(0, newstr.size() - 1);

		}
	//cout << "Initial value of string-" << endl;      //old string
	//cout << str << endl;
	//cout << endl;
	//cout << "Final value of string-" << endl;        //changed string after removing extra spaces
	//cout << newstr << endl;
	return newstr;
}

string UtilityFunctions::removeSpaces(string str)
{
	// n is length of the original string 
	int n = str.length();

	// i points to next position to be filled in 
	// output string/ j points to next character 
	// in the original string 
	int i = 0, j = -1;

	// flag that sets to true is space is found 
	bool spaceFound = false;

	// Handles leading spaces 
	while (++j < n && str[j] == ' ');

	// read all characters of original string 
	while (j < n)
	{
		// if current characters is non-space 
		if (str[j] != ' ')
		{
			// remove preceding spaces before dot, 
			// comma & question mark 
			/*if ((str[j] == '.' || str[j] == ',' ||
				str[j] == '?') && i - 1 >= 0 &&
				str[i - 1] == ' ')
				str[i - 1] = str[j++];

			else*/
			// copy current character at index i 
			// and increment both i and j 
			str[i++] = str[j++];

			// set space flag to false when any 
			// non-space character is found 
			spaceFound = false;
		}
		// if current character is a space 
		else if (str[j++] == ' ')
		{
			// If space is encountered for the first 
			// time after a word, put one space in the 
			// output and set space flag to true 
			if (!spaceFound)
			{
				str[i++] = ' ';
				spaceFound = true;
			}
		}
	}

	// Remove trailing spaces 
	if (i <= 1)
		str.erase(str.begin() + i, str.end());
	else
		str.erase(str.begin() + i, str.end());


	str = trim(str);
	return str;
}

string UtilityFunctions::displayContent(const string stringaData, const int intData, const float floatData, const int type, const int decDigits, const int width, const int side) {
	stringstream ss;
	if (side == 1)
	{
		ss << fixed << right;
	}
	else
	{
		ss << fixed << left;
	}
	ss.fill(' ');        // fill space around displayed #
	ss.width(width);     // set  width around displayed #

	if (type == 1)
	{
		ss << stringaData;
	}
	else if (type == 2)
	{
		ss << intData;
	}
	else if (type == 3)
	{
		ss.precision(decDigits); // set # places after decimal
		ss << floatData;
	}

	return ss.str();
}

string UtilityFunctions::center(const string s, const int w, string fillup) {
	stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i < padding / 2; ++i)
		spaces << fillup;
	ss << spaces.str() << s << spaces.str();    // format with padding
	if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
		ss << fillup;
	return ss.str();
}






