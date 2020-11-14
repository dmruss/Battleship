#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;


class Ship {

private:
	string name;  //name of ship
	int size;  //length of ship 
	string startPoint;  //start point, imported from csv for human player, format: letternumber
	int startRow;  //row position of startPoint as an int
	int startColumn;   //column position of startPoint as an int
	string orient;   //vertical or horizontal
	char symbol;   //letter representing the ship
	vector<vector <int>> coordList;   //holds the coordinates for each ship

public:
	/*
	@Desc: default constructor. sets all variable to 0 or ' '.  not used in program
	@Pre: none
	@Post: none
	*/
	Ship();
	/*
	@Desc: Ship constructor with ship name argument.  Used by the CompPlayer class
			to randomly generate ship positions
	@Pre: CompPlayer object must exist
	@Post: CompPlayer object's ship board will have randomly placed ships
	*/
	Ship(string name);  
	/*
	@Desc: Ship constructor with ship name, starting point, and orientation arguments.  Used
			by the HumanPlayer class to instantiate ship objects from external file with these parameters.
	@Pre: Root folder must contain a csv with 5 ships, they're names, starting point, and orientation
	@Post: A ship object will exist with these characteristics
	*/
	Ship(string name, string startPoint, string orient);

	//Setters
	void setName(string name) { this->name = name; }
	void setSize(int size) { this->size = size; }
	void setStartPoint(string startPoint) { this->startPoint = startPoint; }
	void setOrient(string orient) { this->orient = orient; }
	void setStartRow(int coord) { startRow = coord; }
	void setStartColumn(int coord) { startColumn = coord; }
	void setSymbol(char symbol) { this->symbol = symbol; }

	//Getters
	string getName() { return name; }
	int getSize() { return size; }
	string getStartPoint() { return startPoint; }
	string getOrient() { return orient; }
	int getStartRow() { return startRow; }
	int getStartColumn() { return startColumn; }
	char getSymbol() { return symbol; }
	vector<vector <int>> getcoordList() { return coordList; }

	/*
	@Desc: This function checks if a ship will be placed outside the game board.
	@Pre: There must be a potential ship object with an orientation, 
	a starting point row, a starting point column and size.
	@Post:  If the ship is placed within bounds then the function will execute and no flag will be thrown.
			A flag will be thrown and the program terminated if the ship will be placed out of bounds.
	*/
	void checkOOB(string orient, int startRow, int startColumn, int size);


};




#endif