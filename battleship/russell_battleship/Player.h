#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Ship.h"
#include "ShipBoard.h"

using namespace std;

class Player {

private:
	int guessCol, guessRow; //The integer locations of the player's guess within the 2D array
	Board attackBoard; //Holds the player's guessed locations
	ShipBoard shipBoard;  //Holds the player's locations
	vector<Ship> vectorOfShips;  //Holds the player's ship objects

public:
	//Default Constructor, not used in program
	Player();
	//Setters
	void setAttackBoard(Board anAttackBoard) { attackBoard = anAttackBoard; }
	void setShipBoard(ShipBoard aShipBoard) { shipBoard = aShipBoard; }
	void setGuessCol(int guess) { guessCol = guess; }
	void setGuessRow(int guess) { guessRow = guess; }
	void setVectorOfShips(vector<Ship> vectOfships) { vectorOfShips = vectOfships; }
	//Getters
	Board getAttackBoard() { return attackBoard; }
	ShipBoard getShipBoard() { return shipBoard; }
	int getGuessCol() { return guessCol; }
	int getGuessRow() { return guessRow; }
	vector<Ship> getVectorOfShip() { return vectorOfShips; }
	/*
	@Desc: This function checks if the calling player's ships are hit by an attack at the passed coordinates.
	@Pre:  An opposing player must make a guess with a column and row in integer form, between 0 and 9.
	@Post: If returning true, a ship is sunk and the game is over.  The function will print the name of the ship.
			If false, the attack is a miss, the board is updated and the game continues.
	*/
	bool guessCheck(int guessCol, int guessRow);
	/*
	@Desc: This function updates the calling player's attack board at the given coordinates.
			If hit is true, it updates with a 'O'.  If hit is falsem, it updates with a 'X'.
			Called by the attacking player.
	@Pre: An attack location must be guessed, and a hit must already be determined to have occured or not occured.
	@Post: The attack board is updated.
	*/
	void changeAttackBoard(int col, int row, bool hit);
	/*
	@Desc: This function updates the calling player's ship board at the given coordinates.
	If hit is true, it updates with a 'O'.  If hit is falsem, it updates with a 'X'.
			Called by the player being attacked.
	@Pre: An attack location must be guessed and a hit must already be determined to have occured or not.
	@Post: The ship board is updated.
	*/
	void changeShipBoard(int col, int row, bool hit);
};




#endif