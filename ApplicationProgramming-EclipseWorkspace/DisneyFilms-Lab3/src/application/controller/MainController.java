package application.controller;

import java.io.FileNotFoundException;

import application.model.DisneyMovies;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

public class MainController {

	@FXML
	private TextField searchField;

	@FXML
	private Button showButton;

	@FXML
	private Text searchResults;

	int loaded = 0;
	DisneyMovies Films = new DisneyMovies();

	@FXML
	void activateSearch(ActionEvent event) throws FileNotFoundException {

		String textToSearch = this.searchField.getText();
		if (this.loaded == 0) {
			this.Films.loadBoth();
		}
		this.applySearch(textToSearch);

	}

	public void applySearch(String textToSearch) {
		String tempString = this.Films.searchPrint(textToSearch);
		searchResults.setText(tempString);
	}

}