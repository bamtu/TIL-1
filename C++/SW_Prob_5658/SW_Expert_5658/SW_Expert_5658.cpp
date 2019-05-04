#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int testCaseNum;
int lineSize;
int targetIndex;
char* arrayOfLine;
string line;
vector<string> words;

void initInfo();
void eraseInfo();
void printInfo();
int stringToInteger(string);
void insertPassword();
void rotate();
string start();

int main() {
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++) {
		initInfo();
		string result = start();
		int HexToInt = stringToInteger(result);

		cout << "#" << (i + 1) << " " << HexToInt << endl;
		eraseInfo();
	}
}

int stringToInteger(string wordResult) {
	int result = 0;

	for (int i = wordResult.length() - 1 ; i >= 0; i--) {
		char oneChar = wordResult.at(i);
		int HexToInt = 0;

		if (oneChar >= 'A') {
			HexToInt = oneChar - 'A' + 10;
		}

		else {
			HexToInt = oneChar - '0';
		}

		for (int j = 0; j < wordResult.length()  - 1 - i; j++) {
			HexToInt *= 16;
		}

		result += HexToInt;
	}

	return result;
}

void insertPassword() {
	int wordStandard = lineSize / 4;

	for (int j = 0; j < 4; j++) {
		string word = "";
		bool isContained = false;

		for (int i = 0; i < wordStandard; i++) {
			word = word + arrayOfLine[wordStandard * j + i];
		}

		for (string premadedWord : words) {
			if (premadedWord.compare(word) == 0) {
				isContained = true;
			}
		}

		if (isContained == false) {
			words.push_back(word);
		}
	}

}

void rotate() {
	int lastChar = arrayOfLine[lineSize - 1];

	for (int i = lineSize - 2; i >= 0; i--) {
		arrayOfLine[i + 1] = arrayOfLine[i];
	}

	arrayOfLine[0] = lastChar;
}

string start() {
	int rotateLimit = lineSize / 4;

	for (int i = 0; i < rotateLimit; i++) {
		insertPassword();
		rotate();
	}

	sort(words.begin(), words.end(), greater<string>());

	string result = words.at(targetIndex - 1);

	return result;
}

void printInfo() {
	for (int i = 0; i < lineSize; i++) {
		cout << arrayOfLine[i];
	}

	cout << endl;

	for (string word : words) {
		cout << word << endl;
	}

	cout << endl;
}

void initInfo() {
	cin >> lineSize;
	cin >> targetIndex;

	arrayOfLine = new char[lineSize];

	for (int i = 0; i < lineSize; i++) {
		arrayOfLine[i] = 0;
	}

	cin >> line;

	for (int i = 0; i < lineSize; i++) {
		arrayOfLine[i] = line.at(i);
	}

	words.clear();
}

void eraseInfo() {
	delete arrayOfLine;

	lineSize = 0;
	targetIndex = 0;
	line = "";

	words.clear();
}