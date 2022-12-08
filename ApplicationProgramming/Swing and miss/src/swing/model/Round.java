package swing.model;

public class Round {
	Choice batterChoice;
	Choice pitcherChoice;
	Outcome roundOutcome;

	public Round(Choice newBatterChoice, Choice newPitcherChoice) {
		batterChoice = newBatterChoice;
		pitcherChoice = newPitcherChoice;

	}
	
	public Outcome playRound() {
		roundOutcome = batterChoice.compareChoice(pitcherChoice);
		return roundOutcome;
	}

	public void printRound() {
		batterChoice.printChoice();
		pitcherChoice.printChoice();
		roundOutcome.printOutcome();
		
		
	}
}