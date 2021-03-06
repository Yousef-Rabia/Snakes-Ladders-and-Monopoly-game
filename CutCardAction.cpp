#include "CutCardAction.h"
#include"Grid.h"
#include"CellPosition.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp) {
	CuttedCard = NULL;
}

void CutCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
		pOut->PrintMessage("Click On A Card...");
		CuttedPos = pIn->GetCellClicked();
		
		CuttedCard = pGrid->GetCell(CuttedPos.VCell(), CuttedPos.HCell())->HasCard();

		if(CuttedCard == NULL) //if there is no card in the cell
		{
				pGrid->PrintErrorMessage("No Cards Here! Click to continue...");
				return;
		}
	pOut->ClearStatusBar();


} // Reads parameters required for action to execute 
										 // (code depends on action type so virtual)

void CutCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	if (pGrid->GetClipboard() != NULL) //checks if there is no cards in clipboard
	{ 
		// checks if the card in clipboard is cutted or not, then we delete it if cutted
		if (pGrid->GetClipboard() != pGrid->GetCell(pGrid->GetClipboard()->GetPosition().VCell(), pGrid->GetClipboard()->GetPosition().HCell())->GetGameObject())
		{
			delete pGrid->GetClipboard();
			pGrid->SetClipboard(NULL);
		}
	}
	if (CuttedCard != NULL) // if there card on the cell clicked
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->SetClipboard(CuttedCard); //set the card in clipboard
		pGrid->RemoveObjectFromCell(CuttedPos); // remove it from its position
		pManager->UpdateInterface();
		pGrid->PrintErrorMessage("Cut!...");
	}

}  // Executes action (code depends on action type so virtual)
CutCardAction:: ~CutCardAction() {

}