package swing.model;

public class Inning {
	int outs;
	int strikes;
	int balls;
	int points;
	int inningNumber;
	boolean[] Bases;
	Option batterSelection;
	Option pitcherSelection;

	public Inning(int roundNumber) {
		this.outs = 0;
		this.strikes = 0;
		this.balls = 0;
		this.points = 0;
		this.inningNumber = roundNumber;
		Bases = new boolean[] {false,false,false};
		this.batterSelection = new Option("batter");
		this.batterSelection.genBatterOption();
		this.pitcherSelection = new Option("pitcher");
	}

}
	

