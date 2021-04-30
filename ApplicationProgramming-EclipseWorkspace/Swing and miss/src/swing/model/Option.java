package swing.model;

public class Option {
	// Ex: Batter and Pitcher
	String PlayerName;
	Choice[] choices;

	public Option(String playerName) {
		super();
		PlayerName = playerName;
		choices = new Choice[3];
	}

	public void genBatterOption() {
		// TODO Auto-generated method stub
		genRockPaperScissors();
		genBatterOutcome();

	}

	private void genBatterOutcome() {
		choices[0].genBatterRock();
		choices[1].genBatterPaper();
		choices[2].genBatterScissors();

	}

	public void genPitcherOption() {
		// TODO Auto-generated method stub
		genRockPaperScissors();

	}

	public void genRockPaperScissors() {
		// TODO Auto-generated method stub
		choices[0] = new Choice("rock", "scissors", "paper");
		choices[1] = new Choice("paper", "rock", "scissors");
		choices[2] = new Choice("scissors", "paper", "rock");

	}

	public void printOptions() {
		int i = 0;
		while (printTest(i)) {
			// implement button update
			System.out.println(choices[i]);
		}

	}

	private boolean printTest(int i) {
		if (i < 3) {
			return true;
		}
		return false;
	}

}
