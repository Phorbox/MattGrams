package swing.model;

public class Option {
	// Ex: Batter and Pitcher
	String PlayerName;
	Choice[] choices;

	public Option(String playerName) {
		super();
		this.PlayerName = playerName;
		this.choices = new Choice[3];
	}

	public void genBatterOption() {
		// TODO Auto-generated method stub
		this.genRockPaperScissors();

	}

	public void genPitcherOption() {
		// TODO Auto-generated method stub
		this.genRockPaperScissors();

	}

	public void genRockPaperScissors() {
		// TODO Auto-generated method stub
		this.choices[0] = new Choice("rock", "scissors", "paper");
		this.choices[1] = new Choice("paper", "rock", "scissors");
		this.choices[2] = new Choice("scissors", "paper", "rock");

	}

}
