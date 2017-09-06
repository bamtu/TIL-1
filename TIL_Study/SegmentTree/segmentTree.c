#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputArgs(int*);
long long* inputLeap(int*);
void init(long long*, int);
void inputRequest(int*);
void sum();
void update();

void main(void) {
	int inputNums[3] = {0,};
	long long* storeSum = NULL;

	inputArgs(inputNums);
	storeSum = inputLeap(inputNums);

	int countSum = 0;
	int countChange = 0;
	int request[3] = {0,};

	while(countSum != inputNums[2] || countChange != inputNums[1]) {
		scanf("%d %d %d",&request[0], &request[1], &request[2]);

		// Please insert your codes...
	}
}

void inputArgs(int* inputNums) {
	scanf("%d %d %d",&inputNums[0],&inputNums[1],&inputNums[2]);
}

long long* inputLeap(int* inputNums) {
	int checkLayer = 1;
	int checkSize = 0;
	long long* storeSum = NULL;

	while(1) {
		if(checkLayer > inputNums[0]) {
			checkSize += checkLayer;
			break;
		}

		checkSize += checkLayer;
		checkLayer = checkLayer * 2;
	}

	storeSum = (long long*)malloc(sizeof(long long) * checkSize);
	memset(storeSum, 0, checkSize);

	int inx = 0;
	for(; inx < checkLayer; inx++) {
		if(inx >= inputNums[0]) {
			storeSum[checkLayer -1 + inx] = 0;
			continue;
		}

		scanf("%lld",&storeSum[checkLayer -1 + inx]);
	}
	
	init(storeSum, checkLayer);

	return storeSum;
}

void init(long long* storeSum, int checkLayer) {
	int saveChild = checkLayer;
	int currentLayer = saveChild / 2;
	
	while(1) {
		if(currentLayer == saveChild) {
			if(currentLayer == 2) {
				break;
			}
			saveChild = saveChild / 2;
			currentLayer = saveChild / 2;
		}

		storeSum[currentLayer - 1] = storeSum[currentLayer * 2 - 1] + storeSum[currentLayer * 2];
		currentLayer++;
	}
}
