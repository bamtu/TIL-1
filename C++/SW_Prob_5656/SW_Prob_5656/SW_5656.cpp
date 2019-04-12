#include <iostream>

using namespace std;

int testCaseNum;
int shootingNum;
int width;
int height;
int** board;
int** usedBoard;
int* directionWidth;
int* directionHeight;

void initVariables();
void eraseVariables();

void getInfo();
void eraseInfo();

int startGame();
void resetUsedBoard();
int countBlocks();
int shootBall(int*);
void reArrangeBlocks();
bool canIGoThere(int, int);
void breakBlocks(int, int, int, int, bool);

int main() {
	cin >> testCaseNum;

	initVariables();

	for (int i = 0; i < testCaseNum; i++) {
		getInfo();

		int result = startGame();
		cout << "#" << (i + 1) << " " << result << endl;
		eraseInfo();
	}

	eraseVariables();
}

int startGame() {
	int* shootingPoint = new int[shootingNum];
	int originalCount = 0;
	bool isFull = false;
	int smallestBlocks = height * width + 1;

	while (true) {
		resetUsedBoard();
		int shootingCount = originalCount;
		isFull = true;

		for (int i = 0; i < shootingNum; i++) {
			int remainder = shootingCount % (width);
			int quotient = shootingCount / (width);

			shootingPoint[i] = remainder;

			if (shootingPoint[i] != width - 1) {
				isFull = false;
			}

			shootingCount = quotient;
		}

		int result = shootBall(shootingPoint);

		if (smallestBlocks > result) {
			smallestBlocks = result;
		}

		if (isFull) {
			break;
		}

		originalCount++;
	}

	return smallestBlocks;
}

void resetUsedBoard() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			usedBoard[i][j] = board[i][j];
		}
	}
}

int countBlocks() {
	int count = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (usedBoard[i][j] > 0) {
				count++;
			}
		}
	}

	return count;
}

int shootBall(int* targetWidth) {
	for (int i = 0; i < shootingNum; i++) {
		int targetHeight = 0;
		bool isEmpty = false;

		while (true) {
			if (targetHeight >= height) {
				isEmpty = true;
				break;
			}

			else if (usedBoard[targetHeight][targetWidth[i]] == 0) {
				targetHeight++;
			}

			else {
				break;
			}
		}

		if (isEmpty) {
			continue;
		}

		breakBlocks(targetHeight, targetWidth[i], usedBoard[targetHeight][targetWidth[i]], 0, true);
		reArrangeBlocks();
	}

	return countBlocks();
}

void reArrangeBlocks() {
	for (int i = 0; i < width; i++) {
		int heightCount = height - 1;

		while (true) {
			if (heightCount < 1) {
				break;
			}

			if (usedBoard[heightCount][i] == 0) {
				for (int j = heightCount; j >= 0; j--) {
					if (usedBoard[j][i] != 0) {
						usedBoard[heightCount][i] = usedBoard[j][i];
						usedBoard[j][i] = 0;

						break;
					}
				}
			}

			heightCount--;
		}
	}
}

bool canIGoThere(int tHeight, int tWidth) {
	if (tHeight < 0 || tHeight >= height || tWidth < 0 || tWidth >= width) {
		return false;
	}
		
	return true;
}

void breakBlocks(int targetHeight, int targetWidth, int remainedBlocks, int direction, bool isFirst) {
	usedBoard[targetHeight][targetWidth] = 0;

	if (remainedBlocks > 1) {

		if (isFirst) {
			for (int i = 0; i < 4; i++) {
				int tHeight = targetHeight + directionHeight[i];
				int tWidth = targetWidth + directionWidth[i];

				if (canIGoThere(tHeight, tWidth)) {
					if (usedBoard[tHeight][tWidth] > 1) {
						breakBlocks(tHeight, tWidth, usedBoard[tHeight][tWidth], 0, true);
					}

					breakBlocks(tHeight, tWidth, remainedBlocks - 1, i, false);

				}
			}
		}

		else {
			int tHeight = targetHeight + directionHeight[direction];
			int tWidth = targetWidth + directionWidth[direction];

			if (canIGoThere(tHeight, tWidth)) {
				if (usedBoard[tHeight][tWidth] > 1) {
					breakBlocks(tHeight, tWidth, usedBoard[tHeight][tWidth], 0, true);
				}

				breakBlocks(tHeight, tWidth, remainedBlocks - 1, direction, false);

			}
		}
	}
}

void getInfo() {
	cin >> shootingNum;
	cin >> width;
	cin >> height;

	board = new int*[height];
	usedBoard = new int*[height];

	for (int i = 0; i < height; i++) {
		board[i] = new int[width];
		usedBoard[i] = new int[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> board[i][j];
		}
	}
}

void eraseInfo() {
	for (int i = 0; i < height; i++) {
		delete board[i];
		delete usedBoard[i];
	}

	delete[] board;
	delete[] usedBoard;

	shootingNum = 0;
	width = 0;
	height = 0;
}

void initVariables() {
	directionWidth = new int[4];
	directionHeight = new int[4];

	directionWidth[0] = 1;
	directionWidth[1] = -1;
	directionWidth[2] = 0;
	directionWidth[3] = 0;

	directionHeight[0] = 0;
	directionHeight[1] = 0;
	directionHeight[2] = 1;
	directionHeight[3] = -1;
}

void eraseVariables() {
	delete[] directionHeight;
	delete[] directionWidth;
}