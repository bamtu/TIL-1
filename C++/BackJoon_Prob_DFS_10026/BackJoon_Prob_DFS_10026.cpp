#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> makeMap(int size);
void solution(vector<vector<char>> map, int size);
int printResult(vector<vector<char>>& map, int size);
void printMap(vector<vector<char>> map, int size);
void findAreas(vector<vector<char>>& map, int size, char target, int col, int row);
bool canIGoThere(vector<vector<char>> map, int size, char target, int tCol, int tRow);

int directionCol[4] = {1, -1, 0, 0};
int directionRow[4] = {0, 0, 1, -1};

int main() {
	int size = 0;
	cin >> size;

	vector<vector<char>> map = makeMap(size);
	solution(map, size);
}

bool canIGoThere(vector<vector<char>> map, int size, char target, int tCol, int tRow) {
	if (tCol < 0 || tCol >= size || tRow < 0 || tRow >= size) {
		return false;
	}

	else if (map[tCol][tRow] != target) {
		return false;
	}

	return true;
}

void findAreas(vector<vector<char>>& map, int size, char target, int col, int row) {
	map[col][row] = '.';

	for (int i = 0; i < 4; i++) {
		int tCol = col + directionCol[i];
		int tRow = row + directionRow[i];

		if (canIGoThere(map, size, target, tCol, tRow)) {
			findAreas(map, size, target, tCol, tRow);
		}
	}
}

void printMap(vector<vector<char>> map, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << map[i][j];
		}

		cout << endl;
	}
}

vector<vector<char>> makeMap(int size) {
	vector<vector<char>> map;
	
	for (int i = 0; i < size; i++) {
		vector<char> oneLine;
		
		for (int j = 0; j < size; j++) {
			char oneChar = ' ';
			cin >> oneChar;

			oneLine.push_back(oneChar);
		}

		map.push_back(oneLine);
	}

	return map;
}

int printResult(vector<vector<char>>& map, int size) {
	int areas = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] != '.') {
				findAreas(map, size, map[i][j], i, j);
				areas++;

				printMap(map, size);
			}
		}
	}

	return areas;
}

void solution(vector<vector<char>> map, int size) {
	vector<vector<char>> mapForNormal;
	vector<vector<char>> mapForUnNormal;

	for (int i = 0; i < size; i++) {
		vector<char> oneLineForNormal;
		vector<char> oneLineForUnNormal;

		for (int j = 0; j < size; j++) {
			if (map[i][j] == 'R') {
				oneLineForNormal.push_back('R');
				oneLineForUnNormal.push_back('R');
			}

			else if (map[i][j] == 'B') {
				oneLineForNormal.push_back('B');
				oneLineForUnNormal.push_back('B');
			}

			else {
				oneLineForNormal.push_back('G');
				oneLineForUnNormal.push_back('R');
			}
		}

		mapForNormal.push_back(oneLineForNormal);
		mapForUnNormal.push_back(oneLineForUnNormal);
	}

	cout << printResult(mapForNormal, size);
	cout << " ";
	cout << printResult(mapForUnNormal, size);
}