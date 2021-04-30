
package application.model;

import java.util.ArrayList;

/**
 * @author dabox
 *
 */
public class Movies {

	String Name;
	String Id;
	String Genre;
	ArrayList<Cast> Crew;

	public Movies(String newName, String newId, String newGenre) {
		this.Name = newName;
		this.Id = newId;
		this.Genre = newGenre;
		this.Crew = new ArrayList<Cast>();
	}

	public void addCrew(String[] crewLine) {
		Cast tempCrew = new Cast(crewLine[0], crewLine[1], crewLine[2], crewLine[4]);
		this.Crew.add(tempCrew);

	}

	public String toString() {
		String allCrew = this.ConcatenateCrew();

		return String.format("%s [%s], Genre: %s, Cast: %d\n" + "%s\n", this.Name, this.Id, this.Genre,
				this.Crew.size(), allCrew);
	}

	public String ConcatenateCrew() {
		String Output = "";
		int Length = this.Crew.size();
		for (int i = 0; i < Length; i++) {
			Output = Output + this.Crew.get(i) + "\n";
		}

		return Output;
	}

}
