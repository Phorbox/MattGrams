import java.util.Arrays;

public class SortNumbers {

	public void sortLargeNumbers(String[] stringArray) {
		Arrays.sort(stringArray, (leftNumber, rightNumber) -> {
			if (leftNumber.length() != rightNumber.length())
				return leftNumber.length() - rightNumber.length();
			return leftNumber.compareTo(rightNumber);
		});
	}

}
