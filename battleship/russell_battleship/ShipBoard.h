#ifndef SHIPBOARD_H
#define SHIPBOARD_H

#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Ship.h"

using namespace std;

class ShipBoard : public Board {


public:

	ShipBoard(); //Default constructor, not used.
	/*
	@Desc:  This constructor takes a vector of ship objects and places them on a 2D array ship board
	@Pre: 5 ship objects must exist within a vector
	@Post: A ship board object exists with 5 ships placed on the board.
	*/
	ShipBoard(vector<Ship> shipVector);
	


};



#endif