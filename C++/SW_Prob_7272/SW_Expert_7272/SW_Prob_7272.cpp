#include <iostream>
#include <string>

using namespace std;

void initVariables();
void eraseVariables();
void initInfo();
void eraseInfo();
int compareString();

string zeroHole;
string oneHole;
string twoHole;

int testCaseNum;
string firstString;
string secondString;

int main() {
	cin >> testCaseNum;

	initVariables();

	for (int i = 0; i < testCaseNum; i++) {
		initInfo();

		int result = compareString();

		cout << "#" << (i + 1) << " ";

		if (result) {
			cout << "SAME" << endl;
		}

		else {
			cout << "DIFF" << endl;
		}

		eraseInfo();
	}

	eraseVariables();
}

int compareString() {
	if (firstString.length() != secondString.length()) {
		return 0;
	}

	for (int i = 0; i < firstString.size(); i++) {
		int firstResult = -1;
		int secondResult = -1;

		if (zeroHole.find(firstString[i]) != string::npos) {
			firstResult = 0;
		}

		else if (oneHole.find(firstString[i]) != string::npos) {
			firstResult = 1;
		}

		else {
			firstResult = 2;
		}

		if (zeroHole.find(secondString[i]) != string::npos) {
			secondResult = 0;
		}

		else if (oneHole.find(secondString[i]) != string::npos) {
			secondResult = 1;
		}

		else {
			secondResult = 2;
		}

		if (firstResult != secondResult) {
			return 0;
		}
	}

	return 1;
}

void initVariables() {
	zeroHole = "CEFGHIJKLMNSTUVWXYZ";
	oneHole = "ADOPQR";
	twoHole = "B";
}

void eraseVariables() {
	zeroHole = "";
	oneHole = "";
	twoHole = "";
}

void initInfo() {
	cin >> firstString;
	cin >> secondString;
}

void eraseInfo() {
	firstString = "";
	secondString = "";
}


