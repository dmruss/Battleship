#include "Board.h"

Board::Board() {
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 10; column++) {
			boardArray[row][column] = ' ';
		}
	}

}

void Board::draw() {
	cout << "  |A||B||C||D||E||F||G||H||I||J|\n";
	for (int row = 0; row < 9; row++) {
		cout << row + 1 << " ";
		for (int column = 0; column < 10; column++) {
			
			cout << '|';
			cout << boardArray[row][column];
			cout << '|';


		}
		cout << '\n';
	}
	//10th row for formatting
	cout << 10;
	for (int column = 0; column < 10; column++) {

		cout << '|';
		cout << boardArray[9][column];
		cout << '|';


	}
	cout << '\n';
	



}
	


