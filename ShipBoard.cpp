#include "ShipBoard.h"
#include "Ship.h"

ShipBoard::ShipBoard() {
	Board();
	
}

//This constructor places ships on the board
ShipBoard::ShipBoard(vector<Ship> vectorOfShips) {
	Board();

	for (int i = 0; i < 5; i++) {
		Ship current = vectorOfShips[i];
		int row = current.getStartRow();
		int column = current.getStartColumn();
		
		string orient = current.getOrient();
		//set first point
		this->setPoint(row, column, current.getSymbol());

		if (orient == "H") {
			for (int length = 0; length < current.getSize() - 1; length++) {
				column++;
				this->setPoint(row, column, current.getSymbol());
			}
		}
		else if (orient == "V") {
			for (int length = 0; length < current.getSize() - 1; length++) {
				row++;
				this->setPoint(row, column, current.getSymbol());
			}

		}
		
	}


}