*******************************************************
*  Name      :  David Russell        
*  Student ID:  101147569     
*  Class     :  CSCI 2312
*  Assignment: Battleship Final Project               
*  Due Date  :  May 8, 2020
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program runs a single player version of the classic tabletop game battleship.  
The player faces off against the computer to see which one can sink the other’s 5 ships 
first.  The player’s ship coordinates and orientation are first read in from an external 
csv file and then the computer’s ship positions are randomly generated.  
The player and computer take turns guessing a coordinate which may contain a ship.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that creates an instance of the
   player classes and runs the game loop.

Name:  Ship.h
   Contains member variables and methods for the ship class.

Name:  Player.h
   Contains member variables and methods for the player class.

Name:  HumanPlayer.h
   Contains methods for the HumanPlayer class.  Child of Player class.

Name:  CompPlayer.h
   Contains methods for the CompPlayer class.  Child of Player class.

Name:  Board.h
   Contains member variables and methods for the board class.

Name:  Shipboard.h
   Contains member variables and methods for the shipboard class.  Child of board class.

Name:  Player.cpp
   Contains function definitions for player class.

Name:  Ship.cpp
   Contains function definitions for ship class.

Name:  Board.cpp
   Contains function definitions for board class.

Name:  Shipboard.cpp
   Contains function definitions for shipboard class.

Name:  HumanPlayer.cpp
   Contains function definitions for HumanPlayer class.

Name:  CompPlayer.cpp
   Contains function definitions for CompPlayer class.  


   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Visual Studio version 16.2.3.  It was 
   compiled, run, and tested on gcc version 6.3.1 on csegrid.cudenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [russell_battleship]

   Now you should see a directory named homework with the files:
        main.cpp
        Ship.h
	Player.h
	HumanPlayer.h
	CompPlayer.h
	Board.h
	Shipboard.h
	Player.cpp
	Ship.cpp
	Board.cpp
	Shipboard.cpp
	HumanPlayer.cpp
	CompPlayer.cpp
        makefile
        README.txt
	ship_placement1_good.csv

2. Build the program.

    Change to the directory that contains the file by:
    % cd [russell_battleship] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[battleship]

4. Delete the obj files, executables, and core dump by
   %./make clean
