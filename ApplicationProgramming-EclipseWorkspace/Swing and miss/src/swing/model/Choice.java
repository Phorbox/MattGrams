package swing.model;

import java.util.ArrayList;
import java.util.Random;

public class Choice {

	String Name;
	String Beats;
	String Loses;
	// all game play decisions are made in terms of the batter;
	public ArrayList<Outcome> resultBeats;
	public ArrayList<Outcome> resultTies;
	public ArrayList<Outcome> resultLoses;

	public Choice(String newName, String newBeats, String newLoses) {
		Name = newName;
		Beats = newBeats;
		Loses = newLoses;
		resultBeats = new ArrayList<Outcome>();
		resultTies = new ArrayList<Outcome>();
		resultLoses = new ArrayList<Outcome>();
	}

	public void genBatterRock() {
		// ex: fast swing
		Outcome tempResult;
		tempResult = new Outcome("Base", 2);
		resultBeats.add(tempResult);
		tempResult = new Outcome("Foul", 1);
		resultTies.add(tempResult);
		tempResult = new Outcome("Strike", 1);
		resultLoses.add(tempResult);

	}

	public void genBatterPaper() {
		// ex: slow swing
		Outcome tempResult;
		tempResult = new Outcome("Base", 1);
		resultBeats.add(tempResult);
		tempResult = new Outcome("Foul", 1);
		resultTies.add(tempResult);
		tempResult = new Outcome("Strike", 1);
		resultLoses.add(tempResult);

	}

	public void genBatterScissors() {
		// ex: no swing
		Outcome tempResult;
		tempResult = new Outcome("Ball", 1);
		resultBeats.add(tempResult);
		tempResult = new Outcome("Foul", 1);
		resultTies.add(tempResult);
		tempResult = new Outcome("Strike", 1);
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

	public boolean testBeats(String pitcherChosenName) {
		return Beats.equals(pitcherChosenName);
	}

	public boolean testTies(String pitcherChosenName) {
		return Name.equals(pitcherChosenName);
	}

	public boolean testLoses(String pitcherChosenName) {
		return Loses.equals(pitcherChosenName);
	}

	public void printChoice() {
		System.out.println(Name);
		System.out.println(Beats);
		System.out.println(Loses);
		
	}

}
