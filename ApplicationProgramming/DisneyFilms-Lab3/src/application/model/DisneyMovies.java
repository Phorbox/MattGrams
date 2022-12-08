package application.model;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class DisneyMovies {
	ArrayList<Movies> Movies;

	public DisneyMovies() {
		this.Movies = new ArrayList<Movies>();
	}

	public void loadMovies(String FileName) throws FileNotFoundException {
//		ArrayList<Movies> moviesR = new ArrayList<Movies>();
		File moviesFile = new File(FileName);
		Scanner scan = new Scanner(moviesFile);

		String line;
		String[] movieParts;

		while (scan.hasNext()) {
			line = scan.nextLine();
			movieParts = seperateCSVLine(line);
			this.addMovie(movieParts);
		}
		scan.close();

	}

	public void addMovie(String[] movieParts) {
		Movies TempMovie;
		TempMovie = new Movies(movieParts[0], movieParts[1], movieParts[2]);
		this.Movies.add(TempMovie);
	}

	public void loadCrews(String FileName) throws FileNotFoundException {
		File crewFile = new File(FileName);
		Scanner scan = new Scanner(crewFile);

		String line;
		String[] crewParts;

		while (scan.hasNext()) {
			line = scan.nextLine();
			crewParts = seperateCSVLine(line);
			this.addCrewToMovie(crewParts);
		}
		scan.close();
	}
	
	public void loadBoth() throws FileNotFoundException {
		this.loadMovies("/application/data/movies.csv");
		this.loadCrews("/application/data/characters.csv");	
	}

	private void addCrewToMovie(String[] crewParts) {
		int index;
		index = findCrewPlace(crewParts[3]);
		Movies tempMovie = this.Movies.get(index);
		tempMovie.addCrew(crewParts);
		this.Movies.set(index, tempMovie);
	}

	public int findCrewPlace(String movieId) {
		int length = this.Movies.size();
		Movies temp;
		for (int i = 0; i < length; i++) {
			temp = this.Movies.get(i);
			if (movieId.equalsIgnoreCase(temp.Id)) {
				return i;
			}
		}
		return -1;
	}

	/**
	 * Parses a CSV line into an Array without the delimiting commas
	 * 
	 * @param CSVLine
	 * @return
	 */
	public static String[] seperateCSVLine(String CSVLine) {
		String Delimiter = "\\,";
		String[] parser;

		parser = CSVLine.split(Delimiter);

		return parser;

	}

	public String toString() {
		String allMovies;
		allMovies = this.ConcatenateMovies();
//		String VisibleLine = this.MakeLine(16 + 18);
		return String.format("%s", allMovies);
	}

	public String ConcatenateMovies() {
		String Output = "";
		int Length = this.Movies.size();
		for (int i = 0; i < Length; i++) {
			Output = Output + this.Movies.get(i);

		}

		return Output;
	}

	public String searchPrint(String key) {
		String allMovies;
		allMovies = this.searchenateMovies(key.toLowerCase());

		return String.format("%s", allMovies);
	}

	public String searchenateMovies(String key) {
		String Output = "";
		Movies tempMovie;
		String tempName;
		int Length = this.Movies.size();
		for (int i = 0; i < Length; i++) {
			tempMovie = this.Movies.get(i);
			tempName = tempMovie.Name.toLowerCase();
			if (tempName.contains(key)) {
				Output = Output + this.Movies.get(i);
			}

		}

		return Output;
	}

}
