package SW_Prob_4013;
import java.util.Scanner;

public class SW_4013 {
	final static int SIZE = 8;
	final static int FIRST = SIZE - SIZE;
	final static int LAST = SIZE -1;
	final static int MAGNET_NUM = 4;
	final static int TURNRIGHT = 1;
	final static int TURNLEFT = -1;
	
	static int testCaseNum;
	static int turnCount;
	static int[][] magnets;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		testCaseNum = scanner.nextInt();
		
		for (int i = 0 ; i < testCaseNum ; i++) {
			getInfo(scanner);
			
			for (int j = 0 ; j < turnCount ; j++) {
				int magnetNum = scanner.nextInt();
				int turn = scanner.nextInt();
				
				turnMagnets(magnetNum, magnetNum, turn);
			}
			
			System.out.println("#" + (i + 1) + " " + calcResult());
		}
	}
	
	static int calcResult() {
		int result = 0;
		
		for (int i = 0 ; i < magnets.length ; i++) {
			if (magnets[i][0] == 1) {
				result += Math.pow(2, i);
			}
		}
		
		return result;
	}
	
	static void getInfo(Scanner scanner) {
		turnCount = scanner.nextInt();
		magnets = new int[MAGNET_NUM][SIZE];
		
		for (int i = 0 ; i < MAGNET_NUM ; i++) {
			for (int j = 0 ; j < SIZE ; j++) {
				magnets[i][j] = scanner.nextInt();
			}
		}
	}

	static void turnMagnets(int previousMagnetNum, int magnetNum, int turnDirection) {
		if (magnetNum < 1 || magnetNum > 4) {
			return;
		}

		if (canITurnMagnet(previousMagnetNum, magnetNum) == true) {
			if (previousMagnetNum == magnetNum) {
				turnMagnets(magnetNum, magnetNum -1, turnDirection * -1);
				turnMagnets(magnetNum, magnetNum + 1, turnDirection * -1);
			}
			
			else if (previousMagnetNum > magnetNum) {
				turnMagnets(magnetNum, magnetNum -1 , turnDirection * -1);
			}
			
			else {
				turnMagnets(magnetNum, magnetNum + 1, turnDirection * -1);
			}
			
			if (turnDirection == TURNRIGHT) {
				turnRight(magnets[magnetNum - 1]);
			}
			
			else {
				turnLeft(magnets[magnetNum - 1]);
			}
		}
	}
	
	static boolean canITurnMagnet(int previousMagnetNum, int magnetNum) {
		if (previousMagnetNum == magnetNum) {
			return true;
		}
		
		else if (previousMagnetNum > magnetNum) {
			if (magnets[previousMagnetNum - 1][6] == magnets[magnetNum - 1][2]) {
				return false;
			}
			
			return true;
		}
		
		else {
			if(magnets[previousMagnetNum - 1][2] == magnets[magnetNum - 1][6]) {
				return false;
			}
			
			return true;
		}
	}
	
	static void turnRight(int[] magnet) {
		int lastOne = magnet[LAST];
		
		for(int i = LAST - 1 ; i >= FIRST ; i--) {
			magnet[i + 1] = magnet[i];
		}
		
		magnet[FIRST] = lastOne;
	}
	
	static void turnLeft(int[] magnet) {
		int firstOne = magnet[FIRST];
		
		for(int i = FIRST + 1 ; i <= LAST ; i++) {
			magnet[i - 1] = magnet[i];
		}
		
		magnet[LAST] = firstOne;
	}
}
