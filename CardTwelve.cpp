#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number 
}

CardTwelve::~CardTwelve(void)
{
}
void CardTwelve::Save(ofstream& OutFile) {
	OutFile <<  GetCardNumber() << " " << position.VCell() << " " << position.HCell()  << endl;
}
void CardTwelve::Load(ifstream& Infile) {
	int vstart = -1, h = -1;
	
	Infile >> vstart >> h;
	position.SetHCell(h);
	position.SetVCell(vstart);
	

}

Card* CardTwelve::CopyCard(CellPosition pos)
{
	CardTwelve* ptr = new CardTwelve(pos);
	return ptr;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	

	
	Card::Apply(pGrid, pPlayer);
	//Find out which stations the player owns
	int p1=0, p2=0, p3=0;
	if(pPlayer == CardNine::GetOwner())
	{
		p1 = CardNine::GetStationPrice();
	}
	if (pPlayer == CardTen::GetOwner())
	{
		p2 = CardTen::GetStationPrice();
	}
	if (pPlayer == CardEleven::GetOwner())
	{
		p3 = CardEleven::GetStationPrice();
	}
	//Check if the player does not have stations
	if (p1 == 0 && p2 == 0 && p3 == 0)
	{
		pGrid->PrintErrorMessage("You don't have any stations to lose ...");
		return;
	}
	//Check if the player has least amount of coins
	if (pPlayer->GetPlayerWithLeastMoney(pGrid)==pPlayer)
	{
		pGrid->PrintErrorMessage("You are the player with the least amount of coins. You don't lose any of your stations ...");
		return;
	}
	//Transfer the most expensive station to the player with the least amount of coins
	if (p1 >= p2 && p1 >= p3)
	{
		CardNine::SetOwner(pPlayer->GetPlayerWithLeastMoney(pGrid));
		pGrid->PrintErrorMessage("Now Player NO." + to_string((pPlayer->GetPlayerWithLeastMoney(pGrid))->getPlayerNum ()) + "take station NO.9 from Player NO." + to_string(pPlayer->getPlayerNum()) + "  ...");
	}
	else if (p2 >= p1 && p2 >= p3)
	{
		CardTen::SetOwner(pPlayer->GetPlayerWithLeastMoney(pGrid));
		pGrid->PrintErrorMessage("Now Player NO." + to_string((pPlayer->GetPlayerWithLeastMoney(pGrid))->getPlayerNum()) + "take station NO.10 from Player NO." + to_string(pPlayer->getPlayerNum()) + "  ...");

	}
	else if (p3 >= p1 && p3 >= p2)
	{
		CardEleven::SetOwner(pPlayer->GetPlayerWithLeastMoney(pGrid));
		pGrid->PrintErrorMessage("Now Player NO." + to_string((pPlayer->GetPlayerWithLeastMoney(pGrid))->getPlayerNum()) + "take station NO.11 from Player NO." + to_string(pPlayer->getPlayerNum()) + "  ...");

	}

}