#include "Player.h"

Player::Player() {
	attackBoard = Board();
	shipBoard = ShipBoard();
}

bool Player::guessCheck(int guessCol, int guessRow) {
	bool hit;


	if (shipBoard.getPoint(guessCol, guessRow) != ' ' && shipBoard.getPoint(guessCol, guessRow) != 'X')
	{
		hit = true;
		if (shipBoard.getPoint(guessCol, guessRow) == 'C') {
			cout << "Hit!\n";
			cout << "Carrier sunk.\n";
		}
		else if (shipBoard.getPoint(guessCol, guessRow) == 'B') {
			cout << "Hit!\n";
			cout << "Battleship sunk.\n";
		}
		else if (shipBoard.getPoint(guessCol, guessRow) == 'R') {
			cout << "Hit!\n";
			cout << "Cruiser sunk.\n";
		}
		else if (shipBoard.getPoint(guessCol, guessRow) == 'S') {
			cout << "Hit!\n";
			cout << "Submarine sunk.\n";
		}
		else if (shipBoard.getPoint(guessCol, guessRow) == 'D') {
			cout << "Hit!\n";
			cout << "Destroyer sunk.\n";
		}
		shipBoard.setPoint(guessCol, guessRow, 'O');
		
	}
	else {
		hit = false;
		shipBoard.setPoint(guessCol, guessRow, 'X');
		cout << "Miss.\n";
	}
		




	return hit;
}


void Player::changeAttackBoard(int col, int row, bool hit) {

	if (hit) {
		attackBoard.setPoint(col, row, 'O');
	}
	else {
		attackBoard.setPoint(col, row, 'X');
	}
	
}

void Player::changeShipBoard(int col, int row, bool hit) {

	if (hit) {
		shipBoard.setPoint(col, row, 'O');
	}
	else {
		shipBoard.setPoint(col, row, 'X');
	}
}