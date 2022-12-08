
import java.util.Scanner;

public class FiboMath {
	public int fiboInput() {
		Scanner fiboScan= new Scanner(System.in);
		System.out.println("Enter the number of digits from the fibonacci sequence that you would like:");
		int fiboLength = fiboScan.nextInt();
		fiboScan.close();
		return fiboLength;		
	}

	public long fiboSum(long a, long b) {
		return a + b;
	}

	public long fiboLoop(int upperBound) {
		long[] numbers = new long [] {0,1,1};
		long print;
		int index = 0;
		long returnVal = 0;
		while(printCondition(index, upperBound) && fiboLessThan2(index)) {
			print = numbers[index];
			fiboPrint(print, index, upperBound);
			index++;	
		}
		if(!fiboLessThan2(upperBound)) {
			returnVal = fiboSecondLoop(upperBound, numbers);	
		}else {
			
			returnVal = numbers[upperBound];
		}
		System.out.println();
		System.out.println(returnVal);
		
		return returnVal;
	}
	
	public long fiboSecondLoop(int upperBound, long[] numbers) {
		long print;
		int index = 2;
		while(printCondition(index, upperBound)){
			print = numbers[2];
			fiboPrint(print, index, upperBound);
			if(commaCondition(index, upperBound)) {
				fiboIncrement(numbers);
			}
			index++;		
		}
		return numbers[2];
	}
	
	public boolean fiboLessThan2(int index) {
		
		if(index < 2) {
			return true;
		}
		return false;
	}

	public void fiboPrint(long print,int index, int upperBound) {
		System.out.print(print);
		if(commaCondition(index, upperBound)) {
			System.out.print(", ");
		}
	}
	public boolean printCondition(int index, int upperBound) {
		if (index < upperBound) {
			return true;
		}
		return false;
	}
	public boolean commaCondition(int index, int upperBound) {
		if (index < upperBound-1) {
			return true;
		}
		return false;
	}

	public void fiboStart() {
		int upperBound = fiboInput();
		
		fiboLoop(upperBound);
	}

	public void fiboIncrement(long[] numbers) {
		long a = numbers[1];
		long b = numbers[2];
		numbers[0] = a;
		numbers[1] = b;
		numbers[2] = fiboSum(a,b);
	}

	public long termSumTester() {
		long[] difference = new long [3];
		difference[0] = fiboLoop(9);
		difference[1] = fiboLoop(10);
		difference[2] = fiboLoop(11);
		return difference[0] + difference[1] - difference[2];
	}

}
