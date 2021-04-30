package application;

public class Model {
	
	public float calculate(long number1, long number2, String operator) {
		
		// Basic operations we are expecting from our calculator 
		//+, -, *, /
		
		switch (operator) {
		case "+":
			return number1 + number2;
		case "-":
			return number1 - number2;
		case "*":
			return number1 * number2;
		case "/":
			if(number2 == 0)
				return 0;
			return number1 / number2;
			
		//case "%":
			
		default:
			return 0;
		}
	}
}