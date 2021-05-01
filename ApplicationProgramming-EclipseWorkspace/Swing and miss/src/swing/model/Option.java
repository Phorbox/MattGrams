package swing.model;

public class Option {
	// Ex: Batter and Pitcher
	public Choice[] choices;

	public Option() {
		choices = new Choice[3];
	}

	public void genBatterOption() {
		// TODO Auto-generated method stub
		genRockPaperScissors();
		genBatterOutcome();

	}

	public void genBatterOutcome() {
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
		choices[0] = new Choice(Rps.ROCK, Rps.SCISSORS, Rps.PAPER);
		choices[1] = new Choice(Rps.PAPER, Rps.ROCK, Rps.SCISSORS);
		choices[2] = new Choice(Rps.SCISSORS, Rps.PAPER, Rps.ROCK);

	}

	public void printOptions() {
		int i = 0;
		while (printTest(i)) {
			// implement button update
			System.out.println(choices[i]);
		}

	}

	public boolean printTest(int i) {
		if (i < 3) {
			return true;
		}
		return false;
	}

}
