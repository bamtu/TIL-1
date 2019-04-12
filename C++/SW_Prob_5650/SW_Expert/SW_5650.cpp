#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct {
	int rightLeft;
	int upDown;
}Position;

int testCaseNum;
int boardSize;
int** board;
int* directionUpDown;
int* directionRightLeft;
int** wallType;
map<int, vector<Position>> warmHoles;

void initVariables();
void eraseVariables();
void getInfo();
void eraseInfo();

int checkBiggestScore();
int traveling(int, int);
int controlDirection(int*, int*, int, int*);

int main() {
	initVariables();

	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++) {
		getInfo();

		int result = checkBiggestScore();
		cout << "#" << (i + 1) << " " << result << endl;
		
		eraseInfo();
	}

	eraseVariables();

	return 0;
}

int controlDirection(int* upDown, int* rightLeft, int direction, int* score) {
	int boardStatus = board[*upDown][*rightLeft];

	if (boardStatus == -1) {
		return boardStatus;
	}

	else if (boardStatus == 0) {
		return direction;
	}

	else {
		int tDirection = wallType[boardStatus - 1][direction];

		if (boardStatus > 0 && boardStatus < 6) {
			*score += 1;
		}

		else if (boardStatus >= 6) {
			vector<Position> positions = warmHoles[boardStatus];

			if (*upDown == positions[0].upDown && *rightLeft == positions[0].rightLeft) {
				*upDown = positions[1].upDown;
				*rightLeft = positions[1].rightLeft;
			}

			else {
				*upDown = positions[0].upDown;
				*rightLeft = positions[0].rightLeft;
			}
		}

		return tDirection;
	}
}

int traveling(int upDown, int rightLeft) {
	int biggestScore = 0;

	for (int i = 0; i < 4; i++) {
		int tUpDown = upDown + directionUpDown[i];
		int tRightLeft = rightLeft + directionRightLeft[i];
		int direction = i;
		int score = 0;

		while (true) {
			direction = controlDirection(&tUpDown, &tRightLeft, direction, &score);

			if (direction == -1 || (tUpDown == upDown && tRightLeft == rightLeft) ) {
				break;
			}

			tUpDown = tUpDown + directionUpDown[direction];
			tRightLeft = tRightLeft + directionRightLeft[direction];
		}

		if (biggestScore < score) {
			biggestScore = score;
		}
	}

	return biggestScore;
}

int checkBiggestScore() {
	int biggestScore = 0;

	for (int i = 1; i < boardSize + 1; i++) {
		for (int j = 1; j < boardSize + 1; j++) {
			if (board[i][j] != 0) {
				continue;
			}

			int score = traveling(i, j);

			if (biggestScore < score) {
				biggestScore = score;
			}
		}
	}

	return biggestScore;
}

void initVariables() {
	directionUpDown = new int[4];
	directionRightLeft = new int[4];

	directionRightLeft[0] = 1;
	directionRightLeft[1] = 0;
	directionRightLeft[2] = 0;
	directionRightLeft[3] = -1;

	directionUpDown[0] = 0;
	directionUpDown[1] = 1;
	directionUpDown[2] = -1;
	directionUpDown[3] = 0;

	wallType = new int*[10];

	for (int i = 0; i < 10; i++) {
		wallType[i] = new int[4];
	}

	wallType[0][0] = 3;
	wallType[0][1] = 0;
	wallType[0][2] = 1;
	wallType[0][3] = 2;

	wallType[1][0] = 3;
	wallType[1][1] = 2;
	wallType[1][2] = 0;
	wallType[1][3] = 1;

	wallType[2][0] = 1;
	wallType[2][1] = 2;
	wallType[2][2] = 3;
	wallType[2][3] = 0;

	wallType[3][0] = 2;
	wallType[3][1] = 3;
	wallType[3][2] = 1;
	wallType[3][3] = 0;

	wallType[4][0] = 3;
	wallType[4][1] = 2;
	wallType[4][2] = 1;
	wallType[4][3] = 0;

	wallType[5][0] = 0;
	wallType[5][1] = 1;
	wallType[5][2] = 2;
	wallType[5][3] = 3;

	wallType[6][0] = 0;
	wallType[6][1] = 1;
	wallType[6][2] = 2;
	wallType[6][3] = 3;

	wallType[7][0] = 0;
	wallType[7][1] = 1;
	wallType[7][2] = 2;
	wallType[7][3] = 3;

	wallType[8][0] = 0;
	wallType[8][1] = 1;
	wallType[8][2] = 2;
	wallType[8][3] = 3;

	wallType[9][0] = 0;
	wallType[9][1] = 1;
	wallType[9][2] = 2;
	wallType[9][3] = 3;
}

void eraseVariables() {
	delete directionRightLeft;
	delete directionUpDown;

	for (int i = 0; i < 10; i++) {
		delete wallType[i];
	}

	delete[] wallType;
}

void eraseInfo() {
	for (int i = 0; i < boardSize + 2; i++) {
		delete board[i];
	}

	delete[] board;

	warmHoles.clear();
	boardSize = 0;
}

void getInfo() {
	cin >> boardSize;

	board = new int*[boardSize + 2];

	for (int i = 0; i < boardSize + 2; i++) {
		board[i] = new int[boardSize + 2];
	}

	for (int i = 0; i < boardSize + 2; i++) {
		for (int j = 0; j < boardSize + 2; j++) {
			if (i == 0 || i == boardSize + 1 || j == 0 || j == boardSize + 1) {
				board[i][j] = 5;
			}

			else {
				cin >> board[i][j];

				if (board[i][j] > 5) {
					Position position;
					position.upDown = i;
					position.rightLeft = j;

					vector<Position> positions;

					if (warmHoles.count(board[i][j]) != 0) {
						vector<Position> positions = warmHoles[board[i][j]];
						positions.push_back(position);
						warmHoles[board[i][j]] = positions;
					}

					else {
						positions.push_back(position);
						warmHoles.insert(make_pair(board[i][j], positions));
					}
				}
			}
		}
	}
}