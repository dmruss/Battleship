
#include "CompPlayer.h"
#include "HumanPlayer.h"
#include "Ship.h"
#include "ShipBoard.h"
#include "Player.h"

using namespace std;

int main() {
	srand(time(NULL));
	string file = "ship_placement1_good.csv";
	HumanPlayer* p1 = new HumanPlayer(file);
	CompPlayer* p2 = new CompPlayer();
	cout << "  Welcome to Battleship!!!\n";
	bool hit = false;
	bool quit = false;
	//gameloop
	while (!hit) {
		
		cout << "	  Attack Board\n";
		p1->getAttackBoard().draw();
		cout << "	  Ship Board\n";
		p1->getShipBoard().draw();

		//get player input
		quit = p1->getInput();
		if (quit) {
			cout << "Thanks for playing\n";
			cout << "Computer player's ship board: \n";
			p2->getShipBoard().draw();
			return 0;
		}

		//check if user input is a hit, update board
		hit = p2->guessCheck(p1->getGuessCol(), p1->getGuessRow());
		if (hit) {
			cout << "Player 1 wins. Game over.\n";
			cout << "Computer player's ship board\n";
			p2->getShipBoard().draw();
			return 0;
		}

		//update p1 attackboard
		p1->changeAttackBoard(p1->getGuessCol(), p1->getGuessRow(), hit);


		//P2 turn: computer random guess
		p2->randGuess();
		//p1 check if hit
		hit = p1->guessCheck(p2->getGuessCol(), p2->getGuessRow());
		
		if (hit) {
			cout << "Computer player wins! Game over.\n";
			p1->getShipBoard().draw();
			cout << "Computer player's ship board:\n";
			p2->getShipBoard().draw();
		}
		//update computer attack board
		p2->changeAttackBoard(p2->getGuessCol(), p2->getGuessRow(), hit);
		
	}
	
	

	return 0;
}