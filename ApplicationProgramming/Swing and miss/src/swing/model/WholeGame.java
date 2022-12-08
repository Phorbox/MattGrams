package swing.model;

import java.util.ArrayList;
import java.util.Random;

public class WholeGame {
	public ArrayList<Integer> score;
	public Inning currentInning;
	public int total;
	public int totalInnings;
	public int inningBattingOffset;

	public WholeGame() {
		total = 0;
		totalInnings = 0;
		inningBattingOffset = 0;
		score = new ArrayList<Integer>();
	}

	public void gameLoop() {
		int i = 0;
		Outcome verdict;

		while (gameEndTest(i)) {

			// Standard game loop:
			//  accept input
			//  update game state
			//  display game state
			
			verdict = currentInning.playInning();
			i++;
			// batter

		}
	}

	public void setUpGame(int newTotalInnings) {
		totalInnings = newTotalInnings;
	}

	public void ApplyScore() {
		// TODO Auto-generated method stub

	}

	public boolean gameEndTest(int i) {
		if (i < totalInnings) {
			return false;
		}
		return true;
	}

	public void FirstPlayFlip(String coinCall) {
		String coinFlip = flipCoin();
		if (coinCompare(coinCall, coinFlip)) {
			inningBattingOffset = 0;
		}
		inningBattingOffset = 1;
	}

	public boolean coinCompare(String aCoin, String bCoin) {
		return (aCoin == bCoin);
	}

	public String flipCoin() {
		int check = randNum(2);
		if (check == 0) {
			return "Heads";
		}
		return "Tails";
	}

	public int randNum(int cases) {
		Random rand = new Random();
		if (cases <= 1) {
			return 0;
		}
		return ((rand.nextInt(33 * cases)) % (cases - 1));
	}

}
