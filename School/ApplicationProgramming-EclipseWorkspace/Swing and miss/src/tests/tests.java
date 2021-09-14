package tests;

import org.junit.Test;

import swing.model.Choice;
import swing.model.Inning;
import swing.model.Option;
import swing.model.Outcome;
import swing.model.Round;

public class tests {

	
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
	
	@Test
	public void testInning() {
		Inning testInning = new Inning();
		int i,j;
		int playerSelectionIndex;
		int comSelectionIndex;
		Round inningRound;
		
		for (i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
				 playerSelectionIndex = i;
				 comSelectionIndex = j;
				

				inningRound = testInning.makeRound(playerSelectionIndex, comSelectionIndex);

				inningRound.playRound();
				Outcome tempOutcome = inningRound.playRound();
				testInning.applyOutcome(tempOutcome);
				tempOutcome.printOutcome();
				testInning.printInning();
				System.out.println("");

			}
		}
		
	}
	
	@Test
	public void testApplyOutcome() {
		
		Inning testInning = new Inning();
		int i,j;
		int playerSelectionIndex;
		int comSelectionIndex;
		Round inningRound;
		
		for (i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
				 playerSelectionIndex = i;
				 comSelectionIndex = j;
				

				inningRound = testInning.makeRound(playerSelectionIndex, comSelectionIndex);

				Outcome tempOutcome = inningRound.playRound();
				testInning.applyOutcome(tempOutcome);
				tempOutcome.printOutcome();
				testInning.printInning();
				System.out.println("");

			}
		}
		
	}
	

}