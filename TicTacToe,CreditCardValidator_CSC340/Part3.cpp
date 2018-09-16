//PART 3 


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>


using namespace std;

class dictionaryItem {
private:
	string name{ "none" };
	string description{ "none" };
	string speech{ "none" };
public:
	dictionaryItem() {}
	dictionaryItem(string name, string description, string speech) : name(name), description(description), speech(speech) {};

	string getName() const {
		return this->name;
	}
	string getDescription() const {
		return this->description;
	}
	string getSpeech() const {
		return this->speech;
	}
};

bool validSpeech(const string&);
string trimString(string);
void printSearchValues(string, string);
void readFile(const string&);

							
multimap<string, dictionaryItem> dictionary;

int main()
{
	//Read file
	readFile("Data.CS.SFSU.txt");

//****************I/O and Search******************

	cout << "-----DICTIONARY 340 C++-----\n\n";
	while (true) {
		string searchLine{ "" };
		string name{ "" };
		string partOfSpeech{ "" };

		cout << "Search: ";
		getline(cin, searchLine);
		trimString(searchLine);
		transform(searchLine.begin(), searchLine.end(), searchLine.begin(), ::tolower);
		if (searchLine == "!q") {
			cout << "\n -----THANK YOU-----" << endl;
			break;
		}
		size_t found = searchLine.find(' ');
		if (found != string::npos) {
			name = trimString(searchLine.substr(0, searchLine.find(' ')));
			partOfSpeech = trimString(searchLine.substr(searchLine.find(' ') + 1));
			size_t extraWords = partOfSpeech.find(' ');
			if ((extraWords != string::npos)) {
				cout << "<Please enter a search key (and a part of speech).>" << endl;
			}
			else if (validSpeech(partOfSpeech)) {
				printSearchValues(name, partOfSpeech);
			}
			else {
				cout << "<2nd argument must be a part of speech.> \n";
			}
		}
		else {
			name = trimString(searchLine);
			printSearchValues(name, "none");
		}
	}
	return 0;
}
//***************Read File and Close**************

void readFile(const string& location) {
	ifstream inFile;
	cout << "! Opening data file... ./Data.CS.SFSU.txt" << endl;
	inFile.open(location);
	string currentLine{ "" };
	cout << "! Loading data..." << endl;
//********************Read line by line***************
	while (getline(inFile, currentLine)) {
		
		int lastPos = currentLine.find('|');
		string name{ trimString(currentLine.substr(0, lastPos)) };
		currentLine.erase(0, lastPos + 1);

//*******Extract description and speech***********

		stringstream stream(currentLine);
		string speechAndDescription{ "" };
		while (getline(stream, speechAndDescription, '|')) {
			string speech{ trimString(speechAndDescription.substr(0, speechAndDescription.find("=>"))) };
			string description{ trimString(speechAndDescription.substr((speechAndDescription.find("=>") + 2))) };

			dictionary.insert(make_pair(name, *(new dictionaryItem(name, description, speech))));
		}
	}
	cout << "! Loading completed..." << endl;
	cout << "! Closing data file... ./Data.CS.SFSU.txt \n" << endl;
	inFile.close();
}
//*************Print search res************
void printSearchValues(string key, string prtOfSpch = "none") {
	if (key.size() == 0) {
		cout << "<Please enter a search key (and a part of speech).>" << endl;
		return;
	}
	else if (dictionary.count(key) == 0) {
		cout << "<Not found.>" << endl;
		return;
	}
	typedef multimap<string, dictionaryItem>::iterator dictionaryItemsIterator;
	pair<dictionaryItemsIterator, dictionaryItemsIterator> result = dictionary.equal_range(key);
	if (prtOfSpch == "none") {
		for (dictionaryItemsIterator it = result.first; it != result.second; it++) {
			cout << it->first << "[" << (it->second).getSpeech() << "] : " << (it->second).getDescription() << endl;
		}
	}
	else {
		int countOfMatches{ 0 };
		for (dictionaryItemsIterator it = result.first; it != result.second; it++) {
			if ((it->second).getSpeech() == prtOfSpch) {
				cout << it->first << "[" << (it->second).getSpeech() << "] : " << (it->second).getDescription() << endl;
				countOfMatches++;
			}
		}
		if (countOfMatches == 0) {
			cout << "<Not found.>" << endl;
		}
	}
}

bool validSpeech(const string& arg) {
	string typesOfSpeech[3] = { "noun", "verb", "adjective" };
	for (int i = 0; i < 3; i++) {
		if (typesOfSpeech[i] == arg) {
			return true;

		}
	}
	return false;
}
string trimString(string arg) {
	if (arg.length() >= 2) {
		if (arg[0] == ' ') {
			arg = arg.substr(1);
		}
		if (arg[arg.length() - 1] == ' ') {
			arg = arg.substr(0, arg.length() - 1);
		}
	}
	return arg;
}