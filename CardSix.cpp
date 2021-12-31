#include "CardSix.h"
CardSix::CardSix(CellPosition& p) :Card(p) {
	SetCardNumber(6);
}
void CardSix::ReadCardParameters(Grid * pGrid) {
	pGrid->GetOutput()->PrintMessage("Please, Click on a Cell....");
	cellNumToMove= pGrid->GetInput()->GetCellClicked().GetCellNum();
}
void CardSix::Apply(Grid* pGrid, Player * pPlayer) {
	
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pPlayer->MoveWithoutDice(pGrid, pPlayer->GetCell()->GetCellPosition().GetCellPositionFromNum(cellNumToMove));
}