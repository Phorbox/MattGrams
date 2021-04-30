import java.util.ArrayList;

/**
 * Zone is a Java class containing a String Name and Animal ArrayList Pens. It
 * also contains getter and setter methods This Class can create a zone with a
 * dynamic amount of animals
 * 
 * @author Matthew Henderson (rmt564)
 */
public class Zone {
	private String Name;
	private String Safety;
	private String Code;
	
	private ArrayList<Animal> Pens;
	

	/**
	 * This is the constructor for the class from a zone name and number of pens
	 * 
	 * @param ZoneName
	 * @param ZonePens
	 */
	public Zone(String ZoneName, String ZoneSafety, String ZoneCode) {
		this.Name = ZoneName;
		this.Safety = ZoneSafety;
		this.Code = ZoneCode;
		this.Pens = new ArrayList<>();

	}

	/**
	 * Returns the name of the Zone
	 * 
	 * @return String Name of this Zone
	 */
	public String getName() {
		return this.Name;
	}

	/**
	 * Returns the animal array of all pens in the zone
	 * 
	 * @return Animal Array Pens of this Zone
	 */
	public ArrayList<Animal> getAllPens() {
		return this.Pens;
	}

	/**
	 * Returns the int number of all pens in the zone
	 * 
	 * @return int number of pens in this Zone
	 */
	public int getNumberOfPens() {
		return this.Pens.size();
	}

	/**
	 * Returns the ith specific animal from the Animal array
	 * 
	 * @param i
	 * @return
	 */
	public Animal getAnimal(int i) {
		return this.Pens.get(i);
	}

	/**
	 * @return the zoneCode
	 */
	public String getZoneCode() {
		return Code;
	}

	/**
	 * @return the safety
	 */
	public String getSafety() {
		return Safety;
	}

	/**
	 * @param safety the safety to set
	 */
	public void setSafety(String safety) {
		Safety = safety;
	}

	/**
	 * @param zoneCode the zoneCode to set
	 */
	public void setZoneCode(String zoneCode) {
		Code = zoneCode;
	}

	/**
	 * Sets the name of the zone
	 * 
	 * @param NewName String Name of the Zone
	 */
	public void setName(String NewName) {
		this.Name = NewName;
	}

	/**
	 * Sets the whole animal array to a specific array
	 * 
	 * @param NewPens is the new Animal array to set
	 */
	public void setPens(ArrayList<Animal> NewPens) {
		this.Pens = NewPens;
	}

	/**
	 * Sets a new animal to a specific index of the animal arraylist
	 * 
	 * @param NewAnimal Animal to set
	 * @param Index     int place to set the animal
	 */
	public void insertAnimal(Animal NewAnimal, int Index) {
		this.Pens.add(Index, NewAnimal);
	}

	/**
	 * Adds a new animal to the end of the animal arraylist
	 * 
	 * @param NewAnimal Animal to set
	 * @param Index     int place to set the animal
	 */
	public void appendAnimal(Animal NewAnimal) {
		this.Pens.add(NewAnimal);
	}

	/**
	 * Adds a new animal to the end of the animal arraylist
	 * 
	 * @param NewAnimal Animal to set
	 * @param Index     int place to set the animal
	 */
	public void prependAnimal(Animal NewAnimal) {
		this.Pens.add(0,NewAnimal);
	}

	/**
	 * Checks to see if a particular pen is populated with an animal
	 * 
	 * @param i the int index of the animal array to check for a null value
	 * @return boolean false if null, true if populated
	 */
	public boolean checkAnimal(int i) {
		if (this.getAnimal(i) == null) {
			return false;
		}
		return true;

	}

	/**
	 * Formats the class when printed as a string.
	 * 
	 * Example:
	 * 
	 * L: Lion Zone : 
	 * ________________ 
	 * >> Lion - Aslan (Carnivore) 
	 * >> Lion - Simba (Carnivore) 
	 * >> Lion - Christian (Carnivore)
	 * 
	 */
	public String toString() {
		String ZonedAnimals;
		ZonedAnimals = this.ConcatenateAnimals();
		
//		String VisibleLine = this.MakeLine(16);
		String VisibleLine = "----------------------------";
		return String.format("%s: %s Zone (%s) :\n" + "%s\n" + "%s",this.Code, this.Name, this.Safety, VisibleLine, ZonedAnimals);
	}

	/**
	 * Concatenates the animal array into a string that the toString method can use
	 * 
	 * @return Output String to be used by toString
	 */
	public String ConcatenateAnimals() {
		String Output = "";
		int Length = this.getNumberOfPens();
		for (int i = 0; i < Length; i++) {
			if (this.checkAnimal(i)) {
				Output = Output + " >> " + this.getAnimal(i) + "\n";
			} else {
				i = Length;
			}
		}

		return Output;
	}
	
	public boolean ZoneCheck(String key) {
		String Checker = this.getZoneCode();
		if (Checker.equals(key)) {
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Makes a Line of underscores for separating sections of the text output of
	 * toString
	 * 
	 * @param Length number of underscores
	 * @return Output String to be used by toString
	 */
	private String MakeLine(int Length) {
		String Output = "";
		for (int i = 0; i < Length; i++) {
			Output = Output + "_";
		}

		return Output;
	}
}
