import static org.junit.Assert.*;

import org.junit.Test;

public class FibonacciTest {

	@Test
	public void fibonacciTest() {
		FiboMath junitObject = new FiboMath();
		long result = junitObject.fiboLoop(11);
		long shouldBe = 55;
		assertEquals(shouldBe, result);
		
	}

}
