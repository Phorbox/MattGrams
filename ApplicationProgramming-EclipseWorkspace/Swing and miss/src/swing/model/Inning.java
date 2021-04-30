package swing.model;

import java.util.Random;
import java.util.Scanner;

public class Inning {
	int outs;
	int strikes;
	int balls;
	int points;
	int inningNumber;
	boolean[] Bases;
	Option batterSelection;
	Option pitcherSelection;
	Choice batterChosen;
	Choice pitcherChosen;

	public Inning(int roundNumber) {
		outs = 0;
		strikes = 0;
		balls = 0;
		points = 0;
		inningNumber = roundNumber;
		Bases = new boolean[] { false, false, false };
		batterSelection = new Option("batter");
		batterSelection.genBatterOption();
		pitcherSelection = new Option("pitcher");
		pitcherSelection.genPitcherOption();
	}

	public int PlayerSelection(int playersTurn) {
		// TODO Auto-generated method stub
		if (playersTurnTest(playersTurn)) {
			batterSelection.printOptions();
		} else {
			pitcherSelection.printOptions();
		}
		int chosen = chooseOption();
		return chosen;
	}

	private int chooseOption() {

		Scanner baseballScan = new Scanner(System.in);
		int toReturn = baseballScan.nextInt();
		baseballScan.close();
		return toReturn;
	}

	private boolean playersTurnTest(int playersTurn) {
		if(playersTurn%2 == 0) {
			return false;
		}
		return true;
		
	}

	void printSelection() {

	}

	public Outcome selectionTest(int pitcherChoiceIndex, int batterChoiceIndex) {
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
		return ((rand.nextInt(33*cases)) % (cases-1));
	}
}

