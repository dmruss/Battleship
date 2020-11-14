#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Player.h"

using namespace std;

class HumanPlayer : public Player {
	
	
	

public :
	//Default constructor, not used
	HumanPlayer();
	/*
	@Desc: This constructor creates a human player object using a csv with ship names, starting points,
		and orientations.
	@Pre: A csv must be in the root folder containing that information.
	@Post: A player object will be instantiated which has an empty attackboard and a ship board
		with ships placed based on the csv file.
	*/
	HumanPlayer(string csv);
	/*
	@Desc: This function reads the ship names, starting points, and orientations from an external csv.
			Called from within the HumanPlayer(string csv) constructor.
	@Pre: A csv must exist with the correct information.
	@Post: A vector of ship objects will be returned if all 5 ships are listed with valid starting points
		and orientations.
	*/
	vector<Ship> ReadFile(string csv);
	/*
	@Desc: This function prompts the user to input a guess to attack the computer player.
			A player may either enter a valid location, or quit the game.
	@Pre: A human player must exist.
	@Post: Either a valid row and column will be stored in the player's variables or the game will end.
	*/
	bool getInput();

	


};




#endif