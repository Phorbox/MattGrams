/**
 * Zone is a Java class containing a String Name and Animal Array Pens. It also
 * contains getter and setter methods
 * This class can create a zoo with a dynamic amount of Zones
 * 
 * @author Matthew Henderson (rmt564)
 */

public class Zoo {
	private String Name;
	private Zone[] Zones;

	/**
	 * @param ZooName
	 * @param ZooSize
	 */
	public Zoo(String ZooName, int ZooSize) {
		this.Name = ZooName;
		this.Zones = new Zone[ZooSize];
	}

	/**
	 * Returns the name of the Zoo
	 * 
	 * @return String Name of this Zoo
	 */
	public String getName() {
		return this.Name;
	}

	/**
	 * Returns the Zone array of all Zones in the zoo
	 * 
	 * @return Zone Array Zones in this Zoo
	 */
	public Zone[] Zones() {
		return this.Zones;
	}

	/**
	 * Returns the number of zones in the zoo
	 * 
	 * @return int number Zones of this Zoo
	 */
	public int getNumberOfZones() {
		return this.Zones.length;
	}

	/**
	 * Returns the ith specific zone from the zone array
	 * 
	 * @param i
	 * @return Zone from this Zoo at the specified index
	 */
	public Zone getSingleZone(int i) {
		return this.Zones[i];
	}

	/**
	 * Sets the name of the zoo
	 * 
	 * @param NewName String Name of the Zoo
	 */
	public void setName(String NewName) {
		this.Name = NewName;
	}

	/**
	 * Sets the whole Zone array to a specific array
	 * 
	 * @param NewZones is the new Zone array to set
	 */
	public void setZones(Zone[] NewZones) {
		this.Zones = NewZones;
	}

	/**
	 * Sets a new Zone to a specific index of the Zone array
	 * 
	 * @param NewZone Zone to set
	 * @param i       int place to set the Zone
	 */
	public void setSingleZone(Zone NewZone, int i) {
		this.Zones[i] = NewZone;
	}

	// Action Methods
	/**
	 * Adds a new Zone to the first open slot of the zone array
	 * 
	 * @param IncomingZone Zone to set in this Zone Array.
	 */
	public void addZone(Zone IncomingZone) {
		int Length = this.getNumberOfZones();
		for (int i = 0; i < Length; i++) {
			if (!(this.checkZone(i))) {
				this.setSingleZone(IncomingZone, i);
				i += Length;
			}
		}

	}

	/**
	 * Checks to see if a particular Zone is populated or null
	 * 
	 * @param i the int index of the animal array to check for a null value
	 * @return boolean false if null, true if populated
	 */
	public boolean checkZone(int i) {
		if (this.getSingleZone(i) == null) {
			return false;
		}
		return true;
	}

	/**
	 * Formats the class when printed as a string.
	 * 
	 * Example:
	 * 
	 * Welcome to "Animal Kingdom Zoo Zoo"!
	 * __________________________________
	 *  Monkey Zone :
	 * ________________
	 * >> Monkey - Bubbles the Chimp (Vegetarian)
 	 * >> Monkey - Grape Ape (Vegetarian)
 	 * 
	 * Tiger Zone :
	 * ________________
	 * >> Tiger - Shere Khan (Carnivore)
	 * >> Tiger - Tigger (Carnivore)
	 * 
	 */
	public String toString() {
		String ZooZones;
		ZooZones = this.ConcatenateZones();
		String VisibleLine = this.MakeLine(16 + 18);
		return String.format("Welcome to \"%s Zoo\"!\n" + "%s\n" + "%s", this.Name, VisibleLine, ZooZones);
	}

	/**
	 * Concatenates the Zone array into a string that the toString method can use
	 * 
	 * @return Output String to be used by toString
	 */
	public String ConcatenateZones() {
		String Output = "";
		int Length = this.getNumberOfZones();
		for (int i = 0; i < Length; i++) {
			if (this.checkZone(i)) {
				Output = Output + this.getSingleZone(i) + "\n";
			} else {
				i = Length;
			}
		}

		return Output;
	}

	/**
	 * Makes a Line of underscores for separating sections of the text output of toString
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
