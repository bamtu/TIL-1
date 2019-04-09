package SW_Prob_2105;

import java.util.ArrayList;
import java.util.Scanner;

public class SW_2105 {
	static int testCaseNum;
	static int[][] map;
	static int mapSize;
	static int[] directionRightLeft;
	static int[] directionUpDown;
	static int biggestTravel;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		initInfo();
		
		Scanner scanner = new Scanner(System.in);
		testCaseNum = scanner.nextInt();
		
		for (int i = 0 ; i < testCaseNum ; i++) {
			getInfo(scanner);
			
			biggestTravel = -1;
			startTravel();
			
			System.out.println("#" + (i + 1) + " " + biggestTravel);
		}
	}
	
	static boolean canIGoThere(ArrayList<Integer> visit, int tRightLeft, int tUpDown, int[] directionCount, int direction) {
		if (tRightLeft < 0 || tRightLeft >= mapSize || tUpDown < 0 || tUpDown >= mapSize) {
			return false;
		}
		
		if (direction > 2 && directionCount[0] == directionCount[2] && directionCount[1] - 1 == directionCount[3]) { 
			return true;
		}
		
		if (visit.contains(map[tUpDown][tRightLeft]) == true) {
			return false;
		}
		
		return true;
	}
	
	static void traveling(ArrayList<Integer> visit, int rightLeft, int upDown, int direction, boolean isFirstTime, int[] directionCount) {
		visit.add(map[upDown][rightLeft]);
		
		if (direction < 2) {
			for (int i = direction ; i < direction + 2 ; i++) {
				if (isFirstTime == true && i == direction + 1) {
					continue;
				}
				
				int tRightLeft = rightLeft + directionRightLeft[i];
				int tUpDown = upDown + directionUpDown[i];
				
				if (canIGoThere(visit, tRightLeft, tUpDown, directionCount, direction) == true) {
					int[] newDirectionCount = new int[4];
					newDirectionCount[0] = directionCount[0];
					newDirectionCount[1] = directionCount[1];
					newDirectionCount[2] = directionCount[2];
					newDirectionCount[3] = directionCount[3];
					
					newDirectionCount[i] += 1;
					traveling(new ArrayList<Integer>(visit), tRightLeft, tUpDown, i, false, newDirectionCount);
				}
			}
		}
		
		else if (direction >= 2) {
			while (true) {
				if (directionCount[direction] == directionCount[direction % 2]) {
					direction++;
				}
				
				if (direction == 4) {
					if (biggestTravel < visit.size() - 1) {
						biggestTravel = visit.size() - 1;
					}
					
					break;
				}
				
				int tRightLeft = rightLeft + directionRightLeft[direction];
				int tUpDown = upDown + directionUpDown[direction];
				
				if (canIGoThere(visit, tRightLeft, tUpDown, directionCount, direction) == true) {
					visit.add(map[tUpDown][tRightLeft]);
					
					directionCount[direction] += 1;
					rightLeft = tRightLeft;
					upDown = tUpDown;
				}
				
				else {
					break;
				}
			}
		}
	}
	
	static void startTravel() {
		for (int i = 0 ; i < mapSize - 1 ; i++) {
			for (int j = 1 ; j < mapSize - 1 ; j++) {
				traveling(new ArrayList<Integer>(), j, i, 0, true, new int[4]);
			}
		}
	}
	
	static void initInfo() {
		directionRightLeft = new int[4];
		directionUpDown = new int[4];
		
		directionRightLeft[0] = 1;
		directionRightLeft[1] = -1;
		directionRightLeft[2] = -1;
		directionRightLeft[3] = 1;
		
		directionUpDown[0] = 1;
		directionUpDown[1] = 1;
		directionUpDown[2] = -1;
		directionUpDown[3] = -1;
	}
	
	static void getInfo(Scanner scanner) {
		mapSize = scanner.nextInt();
		
		map = new int[mapSize][mapSize];
		
		for (int i = 0 ; i < mapSize ; i++) {
			for (int j = 0 ; j < mapSize ; j++) {
				map[i][j] = scanner.nextInt();
			}
		}
	}
}