#include <iostream>

using namespace std;

void initInfo();
void eraseInfo();
int calcNum();

int testCaseNum;
int num;

int main() {
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++) {
		initInfo();
		int result = calcNum();

		cout << "#" << (i + 1) << " " << result << endl;
		eraseInfo();
	}
}

int calcNum() {
	int startNum = 1;
	int count = 0;

	while (true) {
		if (startNum > num) {
			break;
		}

		int sum = 0;
		int currentNum = startNum;

		while (true) {
			if (sum > num) {
				break;
			}

			else if (sum == num) {
				count++;
				break;
			}

			sum += currentNum;
			currentNum++;
		}

		startNum++;
	}

	return count;
}

void eraseInfo() {
	num = 0;
}

void initInfo() {
	cin >> num;
}