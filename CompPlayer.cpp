#include "CompPlayer.h"

CompPlayer::CompPlayer() {

	Player();
	setVectorOfShips(RandomizeShips());
	setShipBoard(ShipBoard(getVectorOfShip()));


}


vector<Ship> CompPlayer::RandomizeShips() {
	vector<Ship> shipVector = {};
	vector<string> ships = { "Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer" };

	//for loop iterates through each ship
	for (int i = 0; i < ships.size(); i++) {
		//while loop repeats until current ship is placed
		bool fit = false;
		while (!fit) {
			string name = ships[i];
			Ship current = Ship(name);
			
			bool coordError = false;
			
			//check if ship is out of bounds
			for (int i = 0; i < current.getSize(); i++) {
			
				//cout << shipVector[i].getcoordList()[i][0];
				//cout << currShip->getcoordList()[i][1];
				if (current.getcoordList()[i][0] > 9)
					coordError = true;
				if (current.getcoordList()[i][1] > 9)
					coordError = true;
			}
			
			//compare currShip coordinates to coordnates in shipArray
			//stepping through each ship in shipArray
			if (!coordError) {
				
				if (shipVector.size() > 0) {
					//each ship
					for (int j = 0; j < shipVector.size(); j++) {
						//stepping through each coordinate in the ship in shipArray
						for (int k = 0; k < shipVector[j].getSize(); k++) {
							//iterate through each coordinate in current ship to check for overlap
							for (int l = 0; l < current.getSize(); l++) {

								if (current.getcoordList()[l][0] == shipVector[j].getcoordList()[k][0] && current.getcoordList()[l][1] == shipVector[j].getcoordList()[k][1]) {
									//cout << "Flag\n";
									coordError = true;
								}
							}
						}
					}
				}
				
			}
			//fit = true;
			//if no overlap then add ship to array
			if (!coordError) {
				shipVector.push_back(current);
				
				fit = true;
			}
		}

	}
	/*cout << shipVector.size() << endl;
	for (int i = 0; i < shipVector.size(); i++) {
		int size = shipVector[i].getcoordList().size();
		cout << size << endl;
		for (int k = 0; k < size; k++) {
			cout << shipVector[i].getcoordList()[k][0] << " ";
			cout << shipVector[i].getcoordList()[k][1] << " ";
			cout << shipVector[i].getOrient() << endl;

		}
	}*/ // end loop for testing input

	return shipVector;
}

void CompPlayer::randGuess() {
	int currCol, currRow;
	bool newGuessFound = false;

	while (!newGuessFound) {
		vector<int> currGuess;
		//make guess
		currCol = rand() % 9;
		currRow = rand() % 9;
		currGuess.push_back(currCol);
		currGuess.push_back(currRow);
		//check if guess has already been made
		if (!prevGuess.empty()) {
			for (int i = 0; i < prevGuess.size(); i++) {
				if (prevGuess[i] != currGuess) {
					newGuessFound = true;
					prevGuess.push_back(currGuess);
					break;

				}
			}
		}
		else {//first guess
			newGuessFound = true;
			prevGuess.push_back(currGuess);
		}
		
	}
	


	setGuessCol(currCol);
	setGuessRow(currRow);
	
	cout << "Computer guess: ";


	if (currCol == 0) {
		cout << "A";
	}
	else if (currCol == 1) {
		cout << "B";
	}
	else if (currCol == 2) {
		cout << "C";
	}
	else if (currCol == 3) {
		cout << "D";
	}
	else if (currCol == 4) {
		cout << "E";
	}
	else if (currCol == 5) {
		cout << "F";
	}
	else if (currCol == 6) {
		cout << "G";
	}
	else if (currCol == 7) {
		cout << "H";
	}
	else if (currCol == 8) {
		cout << "I";
	}
	else if (currCol == 9) {
		cout << "J";
	}

	cout << (getGuessRow())+1 << endl;


}