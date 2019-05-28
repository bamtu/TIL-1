#include <iostream>
#include <string>

using namespace std;

void initInfo();
void eraseInfo();
void findRoute(int, int, int);
bool canIGoThere(int, int);

void initVariables();
void eraseVariables();

bool* mapCheck;
char** map;
int testCaseNum;
int rows;
int cols;
int maximumRoute;
int* directionCols;
int* directionRows;

int main() {
	cin >> testCaseNum;

	initVariables();

	for (int i = 0; i < testCaseNum; i++) {
		initInfo();
		findRoute(0,0,1);

		cout << "#" << (i + 1) << " " << maximumRoute << endl;
		eraseInfo();
	}

	eraseVariables();
}

void eraseVariables() {
	delete directionCols;
	delete directionRows;
}

void initVariables() {
	directionCols = new int[4];
	directionRows = new int[4];

	directionCols[0] = 0;
	directionCols[1] = 0;
	directionCols[2] = 1;
	directionCols[3] = -1;

	directionRows[0] = 1;
	directionRows[1] = -1;
	directionRows[2] = 0;
	directionRows[3] = 0;
}

bool canIGoThere(int tCol, int tRow) {
	if (tCol < 0 || tCol >= cols || tRow < 0 || tRow >= rows) {
		return false;
	}

	else if (mapCheck[map[tRow][tCol] - 'A']) {
		return false;
	}

	return true;
}

void findRoute(int col, int row, int depth) {
	int currentRow = row;
	int currentCol = col;
	mapCheck[map[currentRow][currentCol] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int tCol = currentCol + directionCols[i];
		int tRow = currentRow + directionRows[i];

		if (canIGoThere(tCol, tRow)) {
			findRoute(tCol, tRow, depth + 1);
		}
	}

	if (depth > maximumRoute) {
		maximumRoute = depth;
	}

	mapCheck[map[currentRow][currentCol] - 'A'] = false;
}

void initInfo() {
	cin >> rows;
	cin >> cols;

	map = new char*[rows];
	mapCheck = new bool [26];

	for (int i = 0; i < rows; i++) {
		map[i] = new char[cols];

		for (int j = 0; j < cols; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 26; i++) {
		mapCheck[i] = false;
	}
}

void eraseInfo() {
	for (int i = 0; i < rows; i++) {
		delete map[i];
	}

	delete[] map;
	delete mapCheck;
	rows = 0;
	cols = 0;
	maximumRoute = 0;
}