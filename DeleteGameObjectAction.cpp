#include "DeleteGameObjectAction.h"
#include"CellPosition.h"
#include"Grid.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp) {
	
}  // Constructor

void DeleteGameObjectAction:: ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("Click on an Object To Delete...");
	
		DeletedObj = pIn->GetCellClicked();
		Obj = pGrid->GetCell(DeletedObj.VCell(), DeletedObj.HCell())->GetGameObject(); //Gets the gameobj to be deleted (if exist)
		if (Obj==NULL) //if there is no object
		{

			pGrid->PrintErrorMessage("There is no Object here!...");
			
			return;
		}
		pOut->ClearStatusBar();
	
} 

void DeleteGameObjectAction::Execute() {
	ReadActionParameters();
	if (Obj != NULL) 
	{
		Grid* pGrid = pManager->GetGrid();
		if (pGrid->RemoveObjectFromCell(DeletedObj)) //if deleted successfully
		{
			pManager->UpdateInterface();
			pGrid->PrintErrorMessage("ObjectDeleted!...");

		}
	}
} 
DeleteGameObjectAction:: ~DeleteGameObjectAction() {

}