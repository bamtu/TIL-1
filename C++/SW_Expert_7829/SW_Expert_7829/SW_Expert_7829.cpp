#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int testCaseNum;
int targetCount;
int* target;
map<long, int> primeTarget;

void initInfo();
void eraseInfo();

long getResult();
void printInfo();
void calcPrime(long);
void checkPrime(map<long, int>);
long lastCheck(long, long);

int main() {
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++) {
		initInfo();
		//printInfo();
		int result = getResult();
		
		cout << "#" << (i + 1) << " " << result << endl;
		eraseInfo();
	}
}

void checkPrime(map<long, int> primeNum) {
	for (auto iter = primeNum.begin(); iter != primeNum.end(); iter++) {
		if (primeTarget.count(iter->first)) {
			if (primeTarget[iter->first] < primeNum[iter->first]) {
				primeTarget[iter->first] = primeNum[iter->first];
			}
		}

		else {
			primeTarget[iter->first] = primeNum[iter->first];
		}
	}
}

void calcPrime(long num) {
	map <long, int> primeNum;

	for (long i = 2; i <= num;) {
		if (num % i == 0) {
			if (primeNum.count(i)) {
				primeNum[i] += 1;
			}

			else {
				primeNum[i] = 1;
			}

			num = num / i;
		}

		else {
			i++;
		}
	}

	checkPrime(primeNum);
}

void printInfo() {
	for (int i = 0; i < targetCount; i++) {
		cout << target[i] << " ";
	}

	cout << endl;
}

long lastCheck(long max, long min) {
	long result = 1;

	for (auto iter = primeTarget.begin(); iter != primeTarget.end(); iter++) {
		result *= pow(iter->first, iter->second);
	}

	if (result == max) {
		result *= min;
	}

	return result;
}

long getResult() {
	long min = 1000000L;
	long max = -1;

	for (int i = 0; i < targetCount; i++) {
		if (target[i] < min) {
			min = target[i];
		}

		if (target[i] > max) {
			max = target[i];
		}

		calcPrime(target[i]);
	}

	return lastCheck(max, min);
}

void initInfo() {
	cin >> targetCount;
	target = new int[targetCount];

	for (int i = 0; i < targetCount; i++) {
		cin >> target[i];
	}
}

void eraseInfo() {
	delete target;
	targetCount = 0;

	primeTarget.clear();
}