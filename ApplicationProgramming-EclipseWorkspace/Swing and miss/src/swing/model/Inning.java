package swing.model;

import java.util.Random;
import java.util.Scanner;

public class Inning {
	int outs;
	int strikes;
	int balls;
	int points;
	int RoundNumber;

	boolean[] Bases;
	boolean playerBatting;

	Option batterSelection;
	Choice batterChosen;

	Option pitcherSelection;
	Choice pitcherChosen;

	public Inning() {
		outs = 0;
		strikes = 0;
		balls = 0;
		points = 0;

		Bases = new boolean[] { false, false, false, false, false };

		batterSelection = new Option();
		batterSelection.genBatterOption();

		pitcherSelection = new Option();
		pitcherSelection.genPitcherOption();
	}

	public void playInning() {

		int playerSelectionIndex = PlayerSelection();
		int comSelectionIndex = comSelection();
		Round inningRound = makeRound(playerSelectionIndex, comSelectionIndex);
		inningRound.playRound();
		Outcome tempOutcome = inningRound.playRound();
		applyOutcome(tempOutcome);
		
	}

	private void applyOutcome(Outcome tempOutcome) {
		String name = tempOutcome.Name;
		int strength = tempOutcome.value;

		switch (name) {
		case "Strike":
			incrementStrike(strength);
			;
		case "Foul":
			incrementFoul(strength);
			;
		case "Base":
			increaseBase(strength);
			;
		case "Ball":
			incrementBall(strength);
			;
		default:
			// Java code
			;
		}

	}

	private void incrementBall(int strength) {
		balls += strength;
		if (balls >= 4) {
			increaseBase(1);
			balls = 0;
		}
		
	}

	private void incrementFoul(int strength) {
		strikes += strength;
		if (strikes >= 3) {
			strikes = 2;
		}
	}

	private void incrementStrike(int strength) {
		strikes += strength;
		if (strikes >= 3) {
			incrementOuts(1);
			strikes = 0;
		}
	}

	private void incrementOuts(int strength) {
		outs += strength;
		if (outs >= 3) {
			outs = 0;
			endInning();
		}
	}

	private void endInning() {
		// TODO Auto-generated method stub
		
	}

	private void increaseBase(int strength) {
		int i;
		int j;
		Bases[0] = true;
		for (j = 0; j < strength; j++) {
			for (i = 4; i > 0; i++) {
				incrementBase(i);
				homeRun();
			}
		}
	}

	public void homeRun() {
		if (Bases[4]) {
			Bases[4] = false;
			points++;
		}
	}

	public boolean baseRunCondition(int i) {
		return Bases[i - 1];
	}

	private void incrementBase(int index) {
		if (baseRunCondition(index)) {
			Bases[index] = true;
			Bases[index - 1] = false;
		}
	}

	public Round makeRound(int batterIndex, int pitcherIndex) {
		Choice battersChoice = batterSelection.choices[batterIndex];
		Choice pitchersChoice = pitcherSelection.choices[pitcherIndex];
		Round inningRound = new Round(battersChoice, pitchersChoice);
		return inningRound;
	}

	public int PlayerSelection() {
		printPlayerSelection();
		int chosen = chooseOption();
		return chosen;
	}

	public void printPlayerSelection() {
		if (isPlayerBatting()) {
			batterSelection.printOptions();
		} else {
			pitcherSelection.printOptions();
		}
	}

	public int chooseOption() {
		Scanner baseballScan = new Scanner(System.in);
		int toReturn = baseballScan.nextInt();
		baseballScan.close();
		return toReturn;
	}

	public void determineBatter(int turnOffset, int currentInning) {
		int tempInt = ((turnOffset + currentInning) % 2);
		playerBatting = (tempInt == 0);
	}

	public boolean isPlayerBatting() {
		int tempInt = RoundNumber % 2;
		return (tempInt == 0);
	}

	void printSelection() {

	}

	public Outcome selectionTest(int batterChoiceIndex, int pitcherChoiceIndex) {
		// TODO Auto-generated method stub
		Outcome verdict;
		batterChosen = playerChoiceFromOption(batterChoiceIndex, batterSelection);
		pitcherChosen = playerChoiceFromOption(pitcherChoiceIndex, pitcherSelection);
		verdict = batterChosen.compareChoice(pitcherChosen);
		return verdict;
	}

	public Choice playerChoiceFromOption(int index, Option choiceList) {
		Choice returnChoice;
		returnChoice = choiceList.choices[index];
		return returnChoice;

	}

	public void selectionEffect() {
		// TODO Auto-generated method stub

	}

	public void inningEndTest() {
		// TODO Auto-generated method stub

	}

	public int comSelection() {
		return randNum(3);
	}

	public int randNum(int cases) {
		Random rand = new Random();
		if (cases <= 1) {
			return 0;
		}
		return ((rand.nextInt(33 * cases)) % (cases - 1));
	}
}
