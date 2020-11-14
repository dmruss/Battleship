#ifndef COMPPLAYER_H
#define COMPPLAYER_H

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "Ship.h"
#include "Player.h"

using namespace std;

class CompPlayer : public Player {
private:
	vector<vector <int>> prevGuess; //stores all previous computer guesses

public:
	/*
	@Desc: Default constructor.  Calls the RandomizeShips() function and stores them in the shipboard.
	@Pre: none
	@Post: A computer player object exists with an attack board and 5 randomly placed ships on a shipboard.
	*/
	CompPlayer();
	//Getter
	vector<vector <int>> getPrevGuess() { return prevGuess; }
	//Setter
	void setPrevGuess(vector<vector <int>> somePrevGuesses) { prevGuess = somePrevGuesses; }
	/*
	@Desc: This function instantiates 5 ship objects in random locations on the board.
	@Pre: A computer player constructor must be called
	@Post: 5 randomly placed ships are returned in a vector.
	*/
	vector<Ship> RandomizeShips();
	/*
	@Desc: This function produces a new random guess location for the computer's attack.  
		Checks the prevGuess vector until finds a new guess.  Stores new guesses in prevGuess
	@Pre: A computer player object must exist.  
	@Post: A new row and column combination will be stored in the computer player's variables.
	*/
	void randGuess();
};






#endif