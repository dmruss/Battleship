#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

using namespace std;

class Board {
private:
	
	char boardArray[10][10];  //The board array, holds hit/miss and ship location information

public:
	/*
	@Desc:  Default constructor.  Instantiates a 10x10 array in memory with each space a ' ' character.
	@Pre: None.
	@Post: board object instantiated.
	*/
	Board(); 
	//Setter and getter
	void setPoint(int column, int row, char symbol) { boardArray[row][column] = symbol; }
	char getPoint(int column, int row) { return boardArray[row][column]; }
	
	/*
	@Desc: This function prints a board object to the console.
	@Pre: A board object must exists to call this function.
	@Post: A board will be output to the console.  Axis positions will be labeled.
	*/
	void draw();
	

};



#endif