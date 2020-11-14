#include "Ship.h"

Ship::Ship() {
	name = " ";
	size = 0;
	startPoint = " ";
	orient = " ";
	symbol = ' ';


}
//constructor used by compplayer class
//This constructor places ships randomly
Ship::Ship(string name) {
	
	this->name = name;
	if (name == "Carrier") {
		size = 5;
		symbol = 'C';
	}
	else if (name == "Battleship") {
		size = 4;
		symbol = 'B';
	}
	else if (name == "Cruiser") {
		size = 3;
		symbol = 'R';
	}
	else if (name == "Submarine") {
		size = 3;
		symbol = 'S';
	}
	else if (name == "Destroyer") {
		size = 2;
		symbol = 'D';
	}
	else {
		cout << "Unexpected ship type.";
		unexpected();
	}

	//generate random point and orientation
	string orient;
	int startRow = rand() % 9;
	setStartRow(startRow);
	int startCol = rand() % 9;
	setStartColumn(startCol);
	int orientNum = rand() % 2;
	if (orientNum == 0)
		this->orient = "H";
	if (orientNum == 1)
		this->orient = "V";

	//add starting point to coord list
	vector<int> pair = { startCol, startRow };
	coordList.push_back(pair);

	//add each coordinate point to the coordList
	
		if (orientNum == 0) {
			for (int i = 1; i < size; i++) {
				int nextCol = startCol + i;
				vector<int> nextPoint = { nextCol, startRow };
				coordList.push_back(nextPoint);
			}
		}

		if (orientNum == 1) {
			for (int i = 1; i < size; i++) {
				int nextRow = startRow + i;
				vector<int> nextPoint = { startCol, nextRow };
				coordList.push_back(nextPoint);
			}
		}
	



	startPoint = " ";
}

//Constructor used by humanplayer class
Ship::Ship(string name, string startPoint, string orient) {
	this->name = name;
	this->startPoint = startPoint;
	this->orient = orient;

	if (startPoint[0] == 'A')
		startColumn = 0;
	else if (startPoint[0] == 'B')
		startColumn = 1;
	else if (startPoint[0] == 'C')
		startColumn = 2;
	else if (startPoint[0] == 'D')
		startColumn = 3;
	else if (startPoint[0] == 'E')
		startColumn = 4;
	else if (startPoint[0] == 'F')
		startColumn = 5;
	else if (startPoint[0] == 'G')
		startColumn = 6;
	else if (startPoint[0] == 'H')
		startColumn = 7;
	else if (startPoint[0] == 'I')
		startColumn = 8;
	else if (startPoint[0] == 'J')
		startColumn = 9;
	else {
		cout << "Ship cannot be placed out of bound.\n";
		unexpected();
	}
	
	//convert second coord point to an int
	stringstream str;
	str << startPoint[1];
	int x;
	str >> x;
	startRow = (x - 1);
	if (startRow > 9) {
		cout << "Ship cannot be placed out of bounds.\n";
		unexpected();
	}


	if (name == "Carrier") {
		size = 5;
		symbol = 'C';
		checkOOB(orient, startRow, startColumn, size);
	}	
	else if (name == "Battleship") {
		size = 4;
		symbol = 'B';
		checkOOB(orient, startRow, startColumn, size);

	}	
	else if (name == "Cruiser") {
		size = 3;
		symbol = 'R';
		checkOOB(orient, startRow, startColumn, size);

	}	
	else if (name == "Submarine") {
		size = 3;
		symbol = 'S';
		checkOOB(orient, startRow, startColumn, size);

	}
	else if (name == "Destroyer") {
		size = 2;
		symbol = 'D';
		checkOOB(orient, startRow, startColumn, size);

	}
	else {
		cout << "Unexpected ship type.";
		unexpected();
	}
		
}



void Ship::checkOOB(string orient, int startRow, int startColumn, int size) {

	if (orient == "V") {
		if ((startRow + size - 1) > 9) {
			cout << "Ship cannot be placed out of bounds.\n";
			unexpected();
		}
	}
	else if (orient == "H") {
		if ((startColumn + size - 1) > 9) {
			cout << "Ship cannot be placed out of bounds. \n";
			unexpected();
		}
	}

}