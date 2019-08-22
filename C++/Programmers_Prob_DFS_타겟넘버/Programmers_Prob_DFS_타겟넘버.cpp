#include <iostream>
#include <string>
#include <vector>

using namespace std;

int addNum(const vector<int>& numbers, const int& target, int number, int depth);
int solution(vector<int> numbers, int target);

int main() {
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);

	int target = 3;

	int result = solution(numbers, target);
	cout << result;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	answer = addNum(numbers, target, 0, 0);

	return answer;
}

int addNum(const vector<int>& numbers, const int& target, int number, int depth) {
	if (depth == numbers.size()) {
		if (number == target) {
			return 1;
		}
		return 0;
	}
	else {
		int result = 0;
		int num = numbers[depth];
		result += addNum(numbers, target, number + num, depth + 1);
		result += addNum(numbers, target, number - num, depth + 1);
		return result;
	}
}