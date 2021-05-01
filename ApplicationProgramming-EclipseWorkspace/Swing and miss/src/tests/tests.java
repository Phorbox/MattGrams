package tests;

import org.junit.Test;

import swing.model.Choice;
import swing.model.Inning;
import swing.model.Option;
import swing.model.Outcome;
import swing.model.Round;

public class tests {

	@Test
	public void testChoice() {
		Option testBatter = new Option();
		testBatter.genBatterOption();
		Option testPitcher = new Option();
		testPitcher.genPitcherOption();
		Outcome TestOutcome = null;

		Choice testChoice = testBatter.choices[0];
		TestOutcome = testChoice.compareChoice(testBatter.choices[0]);
		System.out.println("1");
		TestOutcome.printOutcome();

		TestOutcome = testChoice.compareChoice(testBatter.choices[1]);
		System.out.println("\n2");
		TestOutcome.printOutcome();

		TestOutcome = testChoice.compareChoice(testBatter.choices[2]);
		System.out.println("\n3");
		TestOutcome.printOutcome();

		testChoice = testBatter.choices[1];
		TestOutcome = testChoice.compareChoice(testBatter.choices[0]);
		System.out.println("\n4");
		TestOutcome.printOutcome();

		TestOutcome = testChoice.compareChoice(testBatter.choices[1]);
		System.out.println("\n5");
		TestOutcome.printOutcome();

		TestOutcome = testChoice.compareChoice(testBatter.choices[2]);
		System.out.println("\n6");
		TestOutcome.printOutcome();

		testChoice = testBatter.choices[2];
		TestOutcome = testChoice.compareChoice(testBatter.choices[0]);
		System.out.println("\n7");
		TestOutcome.printOutcome();

		TestOutcome = testChoice.compareChoice(testBatter.choices[1]);
		System.out.println("\n8");
		TestOutcome.printOutcome();

		TestOutcome = testChoice.compareChoice(testBatter.choices[2]);
		System.out.println("\n9");
		TestOutcome.printOutcome();

	}

	private void testInning() {
		Inning testInning = new Inning;
		int playerSelectionIndex = testInning.PlayerSelection();
		
		int comSelectionIndex = testInning.comSelection();


		Round inningRound = makeRound(playerSelectionIndex, comSelectionIndex);

		inningRound.playRound();
		Outcome tempOutcome = inningRound.playRound();
		applyOutcome(tempOutcome);
	}

}