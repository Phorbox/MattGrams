/**
 * Animal is a Java class containing a String Type, String Name, and a boolean
 * Carnivorous. It also contains getter and setter methods this class can create
 * a animal.
 * 
 * @author Matthew Henderson (rmt564)
 */
public class Animal {

	String Type;
	String Name;
	boolean Carnivorous; // True means that the animal is Carnivorous

	/**
	 * @param AnimalType
	 * @param AnimalName
	 * @param AnimalDiet
	 */
	public Animal( String AnimalName, String AnimalType, boolean AnimalDiet) {
		this.Name = AnimalName;
		this.Type = AnimalType;
		this.Carnivorous = AnimalDiet;

	}

	/**
	 * Returns the type of the animal
	 * 
	 * @return String Type of this Animal
	 */
	public String getType() {
		return this.Type;
	}

	/**
	 * Returns the name of the animal
	 * 
	 * @return String Name of this Animal
	 */
	public String getAnimalName() {
		return this.Name;
	}

	/**
	 * Returns the diet of animal
	 * 
	 * @return boolean Diet of this Animal
	 */
	public boolean getDiet() {
		return this.Carnivorous;
	}

	/**
	 * Sets the type of animal
	 * 
	 * @param NewType String Type of the Animal
	 */
	public void setType(String NewType) {
		this.Type = NewType;
	}

	/**
	 * Sets the name of animal
	 * 
	 * @param NewName String Name of the Animal
	 */
	public void setName(String NewName) {
		this.Name = NewName;
	}

	/**
	 * Sets the Diet of animal
	 * 
	 * @param NewDiet boolean Diet of the Animal
	 */
	public void setDiet(boolean NewDiet) {
		this.Carnivorous = NewDiet;
	}

	/**
	 * Formats the class when printed as a string.
	 * 
	 * example: Tiger - Shere Khan (Carnivore)
	 */
	public String toString() {

		return String.format("%s - %s (%s)", this.getAnimalName(), this.getType(), this.Meal());
	}

	/**
	 * interprets the animals diet boolean to determine if it is carnivorous
	 * 
	 * @return String Diet of this Animal
	 */
	public String Meal() {
		if (this.getDiet() == true) {
			return "Carnivore";

		}
		return "Vegetarian";

	}

}
