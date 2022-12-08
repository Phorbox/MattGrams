package swing.model;

import java.util.ArrayList;
import java.util.Random;

public class Choice {

	Rps Name;
	Rps Beats;
	Rps Loses;
	// all game play decisions are made in terms of the batter;
	public ArrayList<Outcome> resultBeats;
	public ArrayList<Outcome> resultTies;
	public ArrayList<Outcome> resultLoses;

	public Choice(Rps rock, Rps scissors, Rps paper) {
		Name = rock;
		Beats = scissors;
		Loses = paper;
		resultBeats = new ArrayList<Outcome>();
		resultTies = new ArrayList<Outcome>();
		resultLoses = new ArrayList<Outcome>();
	}

	public void genBatterRock() {
		// ex: fast swing
		Outcome tempResult;
		tempResult = new Outcome(Umpire.BASE, 2);
		resultBeats.add(tempResult);
		tempResult = new Outcome(Umpire.FOUL, 1);
		resultTies.add(tempResult);
		tempResult = new Outcome(Umpire.STRIKE, 1);
		resultLoses.add(tempResult);

	}

	public void genBatterPaper() {
		// ex: slow swing
		Outcome tempResult;
		tempResult = new Outcome(Umpire.BASE, 1);
		resultBeats.add(tempResult);
		tempResult = new Outcome(Umpire.FOUL, 1);
		resultTies.add(tempResult);
		tempResult = new Outcome(Umpire.STRIKE, 1);
		resultLoses.add(tempResult);

	}

	public void genBatterScissors() {
		// ex: no swing
		Outcome tempResult;
		tempResult = new Outcome(Umpire.BALL, 1);
		resultBeats.add(tempResult);
		tempResult = new Outcome(Umpire.FOUL, 1);
		resultTies.add(tempResult);
		tempResult = new Outcome(Umpire.STRIKE, 1);
		resultLoses.add(tempResult);
	}

	public Outcome compareChoice(Choice pitcherChosenName) {
		if (testBeats(pitcherChosenName.Name)) {
			return randOutcome(resultBeats);
		}
		if (testTies(pitcherChosenName.Name)) {
			return randOutcome(resultTies);
		}
		if (testLoses(pitcherChosenName.Name)) {
			return randOutcome(resultLoses);
		}
		return null;
	}

	public Outcome randOutcome(ArrayList<Outcome> listOfOutcomes) {
		int size = listOfOutcomes.size();
		return listOfOutcomes.get(randNum(size));
	}

	public int randNum(int cases) {
		Random rand = new Random();
		if (cases <= 1) {
			return 0;
		}
		return ((rand.nextInt(33 * cases)) % (cases - 1));
	}

	public boolean testBeats(Rps pitcherChosenName) {
		return Beats == pitcherChosenName;
	}

	public boolean testTies(Rps pitcherChosenName) {
		return Name == pitcherChosenName;
	}

	public boolean testLoses(Rps pitcherChosenName) {
		return Loses == pitcherChosenName;
	}

	public void printChoice() {
		System.out.println(Name);
		System.out.println(Beats);
		System.out.println(Loses);

	}

}
