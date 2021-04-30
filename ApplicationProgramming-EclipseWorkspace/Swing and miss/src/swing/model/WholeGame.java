package swing.model;

import java.util.ArrayList;

public class WholeGame {
	ArrayList<int> score;
	int total;
	int totalInnings;
	
	public void gameLoop() {
		int i = 0;
		int PlayersTurn = 0;
		int comChoice;
		int playerChoice;
		Inning currentInning;
		Outcome verdict;
		while (gameEndTest(i)) {
			currentInning = new Inning(i);
			
			//batter
			playerChoice = currentInning.PlayerSelection(PlayersTurn);
			comChoice = currentInning.comSelection();
			//pitcher
			playerChoice = currentInning.PlayerSelection(PlayersTurn+1);
			comChoice = currentInning.comSelection();
			
			verdict = currentInning.selectionTest(playerChoice,comChoice);
			currentInning.selectionEffect();
			currentInning.inningEndTest();
			ApplyScore();
		}
	}
	
	
	private void ApplyScore() {
		// TODO Auto-generated method stub
		
	}


	public boolean gameEndTest(int i) {
		if (i < totalInnings) {
			return false;
		}
		return true;
	}
	
	
}
