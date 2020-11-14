#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() {
	Player();

}

HumanPlayer::HumanPlayer(string csv) {
	Player();
	setVectorOfShips(ReadFile(csv));
	setShipBoard(ShipBoard(getVectorOfShip()));
	
	

}

//reads in ships and coordinates, does error checking
vector<Ship> HumanPlayer::ReadFile(string csv) {
	vector<Ship> shipVector;
	int shipArraySize = 0;
	bool carrier = false;
	bool battleship = false;
	bool cruiser = false;
	bool sub = false;
	bool destroyer = false;

	int totalItems = 0;
	
	string line, temp;
	fstream infile;
	infile.open(csv);

	while (infile >> line) {
		
		string name, coord, orientation;
		int items = 0;
		
		stringstream s(line);

		getline(s, name, ',');
		items++;

		getline(s, coord, ',');
		items++;

		getline(s, orientation, ',');
		items++;

		if (name == "Carrier") {
			carrier = true;
			
		}
		else if (name == "Battleship") {
			battleship = true;
			
		}
		else if (name == "Cruiser") {
			cruiser = true;
			
		}
		else if (name == "Submarine") {
			sub = true;
			
		}
		else if (name == "Destroyer") {
			destroyer = true;
			
		}
		else {
			cout << "File format error: unexpected ship name.'\n'";
			unexpected();
		}


		if (items != 3) {
			cout << "File format error (not 3 items).'\n'";
			unexpected();
			
		}
		totalItems += items;

		
		shipVector.push_back( Ship(name, coord, orientation));
		

	}

	

	if (carrier == false) {
		cout << "File error. No carrier ship placed.\n'";
		unexpected();
	}
	else if (battleship == false) {
		cout << "File error. No battleship ship placed.\n'";
		unexpected();
	}
	else if (cruiser == false) {
		cout << "File error. No cruiser ship placed.\n'";
		unexpected();
	}
	else if (sub == false) {
		cout << "File error. No submarine ship placed.\n'";
		unexpected();
	}
	else if (destroyer == false) {
		cout << "File error. No destroyer ship placed.\n'";
		unexpected();
	}
	if (totalItems != 15) {
		cout << "File format error (not 15 items).'\n'";
		unexpected();
	}

	return shipVector;
	


}


bool HumanPlayer::getInput() {
	bool quit = false;
	char columnLetterGuess;
	cout << "Enter column guess (A-J), or 'Q' to end game: ";
	cin >> columnLetterGuess;
	columnLetterGuess = toupper(columnLetterGuess);

	
	while (columnLetterGuess > 'J' || columnLetterGuess < 'A') {
		if (columnLetterGuess == 'Q') {
			quit = true;
			return quit;
		}
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Invalid Input. \n";
		cout << "Enter column guess (A-J), or 'Q' to end game:\n";
		cin >> columnLetterGuess;
		columnLetterGuess = toupper(columnLetterGuess);
	}
	



	if (columnLetterGuess == 'A') {
		setGuessCol(0);
	}
	else if (columnLetterGuess == 'B') {
		setGuessCol(1);
	}
	else if (columnLetterGuess == 'C') {
		setGuessCol(2);
	}
	else if (columnLetterGuess == 'D') {
		setGuessCol(3);
	}
	else if (columnLetterGuess == 'E') {
		setGuessCol(4);
	}
	else if (columnLetterGuess == 'F') {
		setGuessCol(5);
	}
	else if (columnLetterGuess == 'G') {
		setGuessCol(6);
	}
	else if (columnLetterGuess == 'H') {
		setGuessCol(7);
	}
	else if (columnLetterGuess == 'I') {
		setGuessCol(8);
	}
	else if (columnLetterGuess == 'J') {
		setGuessCol(9);
	}
	

	
	int aguessRow = -1;
	cout << "Enter row guess (1-10): ";
	cin >> aguessRow;
	while (aguessRow < 1 || aguessRow > 10) {
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Invalid Input. \n";
		cout << "Enter row guess (1-10): ";
		cin >> aguessRow;
		
	}
	setGuessRow(aguessRow - 1);
	return quit;
}


