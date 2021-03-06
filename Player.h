#pragma once

#include "Grid.h"
#include "Cell.h"

enum AttackType { ice, fire, poison, lightning };

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
						   // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
						   // and reset again when reached 3
						   // it is used to indicate when to move and when to add to your wallet
	int turnsToSkip;	   // Number of turns the player will be unable to play "initailly 0"
protected:
	int AttackCounter;     // Number of special attacks left for the player "initially 2"
	int SpecialAttacks[4]; // Special attacks the user can use each of only once
	int burning;		   // Number of turns the player will lose 20 coins at the start of "initially 0"
	int poisoned;		   // Number of turns the player will be poisoned for "deduct 1 from diceroll"
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount
	void turnIncrement();			// Increments the turn by 1, from 0 to 2
	///TODO: You can add setters and getters for data members here (if needed)

	void setTurnCount(int);
	int GetStepCount() const;
	void setStepCount(int);
	int getPlayerNum() const;
	int getJustRolledDice() const;
	void setTurnsToSkip(int);
	void setBurning(int);
	void setPoisoned(int);
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======
	void skipCheck(Grid*);					// Checks if the player has to skip his turn
	void burnCheck(Grid*);					// Checks if the player is burning "deduct 20 coins"
	bool poisonCheck(Grid*);				// Checks if the player is poisoned "deduct 1 from dice roll"

	void AttackChoice(Grid*);						// Choose to attack or not every wallet turn
	bool UseAttack(AttackType, Grid*);				// Uses one of the player's special attacks
	void restart(Grid*);

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
												// and Applies the Game Object's effect (if any) of the end reached cell 
												// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
													   // for example: P0(wallet, turnCount)


	Player* GetPlayerWithLeastMoney(Grid * pGrid);// Gets a Pointer to the Player has s the least amount of coins in his wallet.
};
