#pragma once

#include "Card.h"
#include "ApplicationManager.h"

/*
[ CardSeven ] Summary:
Restarts the game for the first player whose cell is after the current player in the grid.
Restarting the game for a player makes him go to cell number 1.
*/


class CardSeven : public Card
{
	ApplicationManager* pManager; //This card needs to utilize Appmanager to execute an extra RollDiceAction

public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); 
	Card* CopyCard(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);// Applies the effect of CardSeven on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardSeven(); // A Virtual Destructor
};

