package SW_Prob_1953;
import java.util.Scanner;

public class SW_1953 {
	static int testCaseNum;
	static int upDownSize;
	static int rightLeftSize;
	static int[] startPoint;
	static int spendedTime;
	static int[][] map;
	static boolean[][] visit;
	static int[][] resultMap;
	static int[][] directionUpDown;
	static int[][] directionRightLeft;
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		initInfo(scanner);
		
		for (int i = 0 ; i < testCaseNum ; i++) {
			setInfo(scanner);
			
			trackPerson(startPoint[0] , startPoint[1] , 1);
			System.out.println("#" + (i + 1) + " " + printResult());
		}
	}
	
	static boolean canIGoThere(int dUpDown, int dRightLeft, int tUpDown, int tRightLeft) {
		if (tUpDown < 0 || tUpDown >= upDownSize || tRightLeft < 0 || tRightLeft >= rightLeftSize) {
			return false;
		}
		
		if (visit[tUpDown][tRightLeft] == true) {
			return false;
		}
		
		if (map[tUpDown][tRightLeft] == 0) {
			return false;
		}
		
		for (int i = 0 ; i < directionUpDown[map[tUpDown][tRightLeft] - 1].length ; i++) {
			if (dUpDown + directionUpDown[map[tUpDown][tRightLeft] - 1][i] == 0 && dRightLeft + directionRightLeft[map[tUpDown][tRightLeft] - 1][i] == 0) {
				return true;
			}
		}
		
		return false;
	}
	
	static int printResult() {
		int count = 0;
		
		for (int i = 0 ; i < upDownSize ; i++) {
			for (int j = 0 ; j < rightLeftSize ; j++) {
				if (resultMap[i][j] == 1) {
					count++;
				}
			}
		}
		
		return count;
	}
	
	static void trackPerson(int upDown, int rightLeft, int time) {
		visit[upDown][rightLeft] = true;
		resultMap[upDown][rightLeft] = 1;
		
		if (time >= spendedTime) {
			visit[upDown][rightLeft] = false;
			return;
		}
		
		for (int i = 0 ; i < directionUpDown[map[upDown][rightLeft] - 1].length ; i++) {
			int tUpDown = upDown + directionUpDown[map[upDown][rightLeft] - 1][i];
			int tRightLeft = rightLeft + directionRightLeft[map[upDown][rightLeft] - 1][i];
			
			if (canIGoThere(directionUpDown[map[upDown][rightLeft] - 1][i], directionRightLeft[map[upDown][rightLeft] - 1][i], tUpDown, tRightLeft) == true) {
				trackPerson(tUpDown, tRightLeft, time + 1);
			}
		}
		
		visit[upDown][rightLeft] = false;
	}
	
	static void setInfo(Scanner scanner) {
		upDownSize = scanner.nextInt();
		rightLeftSize = scanner.nextInt();
		startPoint[0] = scanner.nextInt();
		startPoint[1] = scanner.nextInt();
		spendedTime = scanner.nextInt();
		
		map = new int[upDownSize][rightLeftSize];
		visit = new boolean[upDownSize][rightLeftSize];
		resultMap = new int[upDownSize][rightLeftSize];
		
		for (int i = 0 ; i < upDownSize ; i++) {
			for (int j = 0 ; j < rightLeftSize ; j++) {
				map[i][j] = scanner.nextInt();
				visit[i][j] = false;
				resultMap[i][j] = 0;
			}
		}
	}
	
	static void initInfo(Scanner scanner) {
		testCaseNum = scanner.nextInt();
		upDownSize = 0;
		rightLeftSize = 0;
		startPoint = new int[2];
		startPoint[0] = 0;
		startPoint[1] = 0;
		spendedTime = 0;
		
		directionUpDown = new int[7][];
		directionRightLeft = new int[7][];
		
		directionUpDown[0] = new int[4];
		directionRightLeft[0] = new int[4];
		
		directionUpDown[0][0] = 1;
		directionUpDown[0][1] = -1;
		directionUpDown[0][2] = 0;
		directionUpDown[0][3] = 0;
		
		directionRightLeft[0][0] = 0;
		directionRightLeft[0][1] = 0;
		directionRightLeft[0][2] = 1;
		directionRightLeft[0][3] = -1;
		
		directionUpDown[1] = new int[2];
		directionRightLeft[1] = new int[2];
		
		directionUpDown[1][0] = 1;
		directionUpDown[1][1] = -1;
		
		directionRightLeft[1][0] = 0;
		directionRightLeft[1][1] = 0;
		
		directionUpDown[2] = new int[2];
		directionRightLeft[2] = new int[2];
		
		directionUpDown[2][0] = 0;
		directionUpDown[2][1] = 0;
		
		directionRightLeft[2][0] = 1;
		directionRightLeft[2][1] = -1;
		
		directionUpDown[3] = new int[2];
		directionRightLeft[3] = new int[2];
		
		directionUpDown[3][0] = -1;
		directionUpDown[3][1] = 0;
		
		directionRightLeft[3][0] = 0;
		directionRightLeft[3][1] = 1;
		
		directionUpDown[4] = new int[2];
		directionRightLeft[4] = new int[2];
		
		directionUpDown[4][0] = 1;
		directionUpDown[4][1] = 0;
		
		directionRightLeft[4][0] = 0;
		directionRightLeft[4][1] = 1;
		
		directionUpDown[5] = new int[2];
		directionRightLeft[5] = new int[2];
		
		directionUpDown[5][0] = 1;
		directionUpDown[5][1] = 0;
		
		directionRightLeft[5][0] = 0;
		directionRightLeft[5][1] = -1;
		
		directionUpDown[6] = new int[2];
		directionRightLeft[6] = new int[2];
		
		directionUpDown[6][0] = 0;
		directionUpDown[6][1] = -1;
		
		directionRightLeft[6][0] = -1;
		directionRightLeft[6][1] = 0;
	}
}