import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Zone is a Java class containing a String Name and Animal Array Pens. It also
 * contains getter and setter methods This class can create a zoo with a dynamic
 * amount of Zones
 * 
 * @author Matthew Henderson (rmt564)
 */

/**
 * @author dabox
 *
 */
public class Zoo {
	private String Name;
	private ArrayList<Zone> Zones;

	/**
	 * @param ZooName
	 * @param ZooSize
	 */
	public Zoo(String ZooName) {
		this.Name = ZooName;
		this.Zones = new ArrayList<>();
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
	 * Returns the Zone arraylist of all Zones in the zoo
	 * 
	 * @return Zone Array Zones in this Zoo
	 */
	public ArrayList<Zone> getAllZones() {
		return this.Zones;
	}

	/**
	 * Returns the number of zones in the zoo
	 * 
	 * @return int number Zones of this Zoo
	 */
	public int getNumberOfZones() {
		return this.Zones.size();
	}

	/**
	 * Returns the ith specific zone from the zone array
	 * 
	 * @param i
	 * @return Zone from this Zoo at the specified index
	 */
	public Zone getSingleZone(int i) {
		return this.Zones.get(i);
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
	public void setZones(ArrayList<Zone> NewZones) {
		this.Zones = NewZones;
	}

	/**
	 * Sets a new Zone to a specific index of the Zone array
	 * 
	 * @param NewZone Zone to set
	 * @param i       int place to set the Zone
	 */
	public void insertZone(Zone NewZone, int i) {
		this.Zones.add(i, NewZone);
	}

	// Action Methods
	/**
	 * Adds a new Zone to the first open slot of the zone array
	 * 
	 * @param NewZone Zone to set in this Zone Array.
	 */
	public void appendZone(Zone NewZone) {
		this.Zones.add(NewZone);
	}

	// Action Methods
	/**
	 * Adds a new Zone to the front of the zone array
	 * 
	 * @param NewZone Zone to set in this Zone Array.
	 */
	public void prependZone(Zone NewZone) {
		this.Zones.add(NewZone);
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
	 * Welcome to "Animal Kingdom Zoo Zoo"! __________________________________
	 * Monkey Zone : ________________ >> Monkey - Bubbles the Chimp (Vegetarian) >>
	 * Monkey - Grape Ape (Vegetarian)
	 * 
	 * Tiger Zone : ________________ >> Tiger - Shere Khan (Carnivore) >> Tiger -
	 * Tigger (Carnivore)
	 * 
	 */
	public String toString() {
		String ZooZones;
		ZooZones = this.ConcatenateZones();
		String VisibleLine = "=============================";
//		String VisibleLine = this.MakeLine(16 + 18);
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
	 * Makes a Line of underscores for separating sections of the text output of
	 * toString
	 * 
	 * @param Length number of underscores
	 * @return Output String to be used by toString
	 */
	private String MakeLine(int Length) {
		String Output = "";
		for (int i = 0; i < Length; i++) {
			Output = Output + "=";
		}

		return Output;
	}

	public void loadZones(String FileName) throws FileNotFoundException {
		File Zonefile = new File(FileName);
		Scanner scan = new Scanner(Zonefile);
		Zone newZone;
		String CSVLine;
		while (scan.hasNext()) {
			CSVLine = scan.next();
			newZone = this.CSVLineToZone(CSVLine);
			this.appendZone(newZone);
		}
		scan.close();

	}

	/**
	 * Converts a line from a csv into a zone
	 * @param csvLine
	 * @return
	 */
	private Zone CSVLineToZone(String csvLine) {
		String[] parser = this.seperateCSVLine(csvLine);
		Zone outputZone = new Zone(parser[0], parser[1], parser[2]);

		return outputZone;
	}

	/**
	 * Converts a line from a CSV into an animal and returns it
	 * @param parser
	 * @return 
	 */
	private Animal CSVLineToAnimal(String[] parser) {

		boolean Diet = dietToBool(parser[2]);
		Animal outputAnimal = new Animal(parser[0], parser[1], Diet);
		return outputAnimal;

	}

	/**
	 * Changes a string to its boolean form
	 * @param convert
	 * @return
	 */
	private boolean dietToBool(String convert) {
		String checker = convert.toLowerCase();
		if (checker.equals("true")) {
			return true;
		} else {
			return false;
		}

	}

	/**
	 * Parses a CSV line into an Array without the delimiting commas
	 * @param CSVLine
	 * @return
	 */
	public String[] seperateCSVLine(String CSVLine) {
		String Delimiter = "\\,";
		String[] parser;

		parser = CSVLine.split(Delimiter);

		return parser;

	}

	/**
	 * loads animals from a file to the zoo
	 * @param FileName
	 * @throws FileNotFoundException
	 */
	public void loadAnimals(String FileName) throws FileNotFoundException {
		File Animalfile = new File(FileName);
		Scanner scan = new Scanner(Animalfile);
		Animal newAnimal;
		String destinationCode;
		String CSVLine;
		String[] csvParts;
		int index;

		while (scan.hasNext()) {
			CSVLine = scan.nextLine();
			csvParts = this.seperateCSVLine(CSVLine);
			newAnimal = this.CSVLineToAnimal(csvParts);
			destinationCode = csvParts[3];
			index = this.getZoneIndexfromZoo(destinationCode);
			if (index != -1) {
				this.addAnimaltoZone(newAnimal, index);
			}
		}
		scan.close();

	}

	/**
	 * Adds an animal to a zone from the zoo level
	 * @param NewAnimal
	 * @param IndexofZone
	 */
	public void addAnimaltoZone(Animal NewAnimal, int IndexofZone) {

		(this.getSingleZone(IndexofZone)).appendAnimal(NewAnimal);

	}

	/**
	 * Returns a zone index from the zoo level for a specific code
	 * @param codeToFind
	 * @return
	 */
	public int getZoneIndexfromZoo(String codeToFind) {
		int i = 0;

		Zone zoneToCheck;

		while (i < this.Zones.size()) {
			zoneToCheck = this.getSingleZone(i);
			if (zoneToCheck.ZoneCheck(codeToFind)) {
				return i;
			}
			i++;
		}
		return -1;
	}

	/**
	 * Moves an animal from one zone to another
	 * 
	 * @param animalToMove
	 * @param NewZone
	 */
	public void relocate(String animalToMove, String NewZone) {
		int oldindex[] = searchAnimal(animalToMove);
		System.out.println(oldindex[0] + " " + oldindex[1] + "old index");
		Animal Moving = this.getAnimalfromZoo(oldindex);
		System.out.println(Moving + "moving");
		this.removeAnimal(oldindex);
		int newIndex = this.getZoneIndexfromZoo(NewZone);
		System.out.println(newIndex + "newindex");
		this.appendAnimalfromZoo(newIndex, Moving);

	}

	/**Gets an animal from the zoo level
	 * @param index
	 * @return
	 */
	public Animal getAnimalfromZoo(int[] index) {
		Zone tempZone = this.Zones.get(index[0]);
		return tempZone.getAnimal(index[1]);
	}

	/** Adds an animal to the end of a pen at a zoo level
	 * @param z
	 * @param a
	 */
	public void appendAnimalfromZoo(int z, Animal a) {

		Zone tempZone = this.Zones.get(z);
		tempZone.appendAnimal(a);
		this.Zones.set(z, tempZone);
	}

	/**removes an animal from the zoo
	 * @param index
	 */
	public void removeAnimal(int[] index) {
		Zone tempZone = this.Zones.get(index[0]);
		ArrayList<Animal> tempPen = tempZone.getAllPens();
		tempPen.remove(index[1]);
		tempZone.setPens(tempPen);
		this.Zones.set(index[0], tempZone);
	}

	/**Searches for an animal in the zoo
	 * @param animalToMove
	 * @return
	 */
	public int[] searchAnimal(String animalToMove) {
		System.out.println(animalToMove);
		int[] animalHome = new int[2];
		int nZones = this.getNumberOfZones();
		int nAnimals;
		Zone ZoneToSearch;
		Animal AnimalToCheck;
		for (int z = 0; z < nZones; z++) {
			ZoneToSearch = this.getSingleZone(z);
			nAnimals = ZoneToSearch.getNumberOfPens();
			for (int a = 0; a < nAnimals; a++) {

				AnimalToCheck = ZoneToSearch.getAnimal(a);
				System.out.println(AnimalToCheck.getAnimalName());

				if (this.NameCheck(animalToMove, AnimalToCheck)) {
					animalHome[0] = z;
					animalHome[1] = a;
					return animalHome;
				}

			}

		}

		return animalHome;
	}

	/**compares the name of two animals
	 * @param key
	 * @param animalToCheck
	 * @return
	 */
	public boolean NameCheck(String key, Animal animalToCheck) {
		String a = animalToCheck.getAnimalName();
		a = a.toLowerCase();
		String b = key.toLowerCase();
		if (a.equals(b)) {
			return true;
		}
		return false;
	}

	/**saves the zoo to two csv files
	 * @throws IOException
	 */
	public void save() throws IOException {
		
		this.writeAnimals();
		this.writeZones();
	}

	/*writes the animals to a file
	 * @throws IOException
	 */
	public void writeAnimals() throws IOException {
		File file = new File("animalData/animals.csv");
		FileWriter printer = new FileWriter(file);
		Zone tempZone;
		String outputLine;
		Animal tempAnimal;
		int nAnimals;
		int nZones = this.Zones.size();
		String Zonecode;
		String Diet;

		for (int z = 0; z < nZones; z++) {
			tempZone = this.getSingleZone(z);
			Zonecode = tempZone.getZoneCode();
			nAnimals = tempZone.getNumberOfPens();
			for (int a = 0; a < nAnimals; a++) {
				tempAnimal = tempZone.getAnimal(a);
				Diet = boolToString(tempAnimal.getDiet());
				outputLine = tempAnimal.getAnimalName() + "," + tempAnimal.getType() + "," + Diet + ","
						+ Zonecode+ "\n";
				printer.write(outputLine);
			}

		}
		printer.close();

	}

	/**
	 * changes a boolean to a string 
	 * @param b
	 * @return
	 */
	private static String boolToString(boolean b) {
		if (b == true) {
			return "TRUE";
		} else {
			return "FALSE";
		}
	}

	/**writes the zones to a file
	 * @throws IOException
	 * 
	 *
	 */
	public void writeZones() throws IOException {
		File file = new File("animalData/zones.csv");
		FileWriter printer = new FileWriter(file);
		Zone tempZone;
		String outputLine;
		int length = this.Zones.size();
		for (int i = 0; i < length; i++) {
			tempZone = this.Zones.get(i);
			outputLine = tempZone.getName() + "," + tempZone.getSafety() + "," + tempZone.getZoneCode() + "\n";
			printer.write(outputLine);
		}
		printer.close();
	}

}
