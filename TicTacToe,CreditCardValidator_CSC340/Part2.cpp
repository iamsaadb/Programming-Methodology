#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

bool isvalidcc(const string& input) {
	const int N = 16;
	int card[N];
	int evenSum = 0;
	int oddSum = 0;
	int sum = 0;
	// ***********stock string input into an int array***********
	for (int i = 0; i<input.size(); i++) {
		card[i] = input[i] - '0';
		}
	//***********traverse the card array***********
	for (int i = input.size(); i >=0; i--) {
		int p;
		int num = card[i];
		//*******if the index is pair then double it, if the number is has 2 digit, then num = num - 9 (same as add digits) 
		// and increase evenSum by that number**********
		if (i % 2 == 0) {
			p = num * 2;
			if (p>9) { p = p - 9; }
			evenSum += p;
		}
		//*******if index isnt pair, add odd numbers **********
		else {
			p = num;
			oddSum += p;
		}
		//*********sum is sum of even and odd sums*********
		sum = evenSum + oddSum;
	}
	//*******if sum is divisible by 10 return true, else return false*********
	if (sum % 10 == 0) { return true; }
	else {
		return false;
	}

}




int main()
{
	//
	// PLEASE DO NOT CHANGE main()
	//
	vector<string> cardnumbers = {
		"371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		"372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;

	}
	system("pause");
	return 0;
}
