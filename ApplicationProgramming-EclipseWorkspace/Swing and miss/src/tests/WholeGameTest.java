package tests;

import static org.junit.Assert.*;
import java.util.Random;
import org.junit.Test;

import swing.model.WholeGame;

public class WholeGameTest {

	@Test
	public void test() {
		Random rand = new Random();
		rand.setSeed(0);
		WholeGame testGame = new WholeGame();
		int intShouldBe = 0;
		int intResult = testGame.total;
		assertEquals(intShouldBe, intResult);
		
		testGame.setUpGame(5);
		intShouldBe = 5;
		intResult = testGame.totalInnings;
		assertEquals(intShouldBe, intResult);
	
		//0 is player batting first, 1 is player pitching first
		intShouldBe = 1;
		int i;
		for(i = 0; i < 100; i++) {
			testGame.FirstPlayFlip("Heads");
			intResult = testGame.inningBattingOffset;
			assertEquals(intShouldBe, intResult);
		}
		
		WholeGame.playInning(1,0);
		
	}

}
