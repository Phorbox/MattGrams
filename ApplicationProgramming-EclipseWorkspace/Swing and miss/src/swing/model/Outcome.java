
package swing.model;

public class Outcome {
	// Ex: 1 Base, 2 Base, 1 Ball, 1 Strike, 1 Foul
	Umpire Name;
	int value;

	public Outcome(Umpire newName, int newValue) {
		Name = newName;
		value = newValue;
	}

	public void printOutcome() {
		System.out.println(Name);
		System.out.println(value);
	}

}
