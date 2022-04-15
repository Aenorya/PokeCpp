 #include "Battle.h"
#include <iostream>

using namespace std;

void Battle::PlayTurn()
{
	//Check who is attacking and who is defending
	int attacker=0, defender=1;
	if(!mTurn)
	{
		attacker = 1;
		defender = 0;
	}
	cout << mpFighters[attacker]->petName << " begins their turn !\n";
	//If it is the player : let them choose an attack and play it
	mpFighters[attacker]->DisplayAbilities();
	int choice = 0;

	if(mTurn)
	{
		do
		{
			cout << "Choose an attack : \n";
			cin >> choice;
		} while (choice < 1 || choice > mpFighters[attacker]->GetAbilityCount());
	}
	//If it is the AI : choose a random attack and play it
	else
	{
		choice = (rand() % mpFighters[attacker]->GetAbilityCount()) + 1;
	}
	//Attack other pokemon with chosen attack
	mpFighters[attacker]->Attack(*mpFighters[defender], (choice-1));

	//If the defending pokemon reaches 0 hp, it means the battle is over, attacker won
	if(mpFighters[defender]->GetCurrentLifePoints() == 0)
	{
		cout <<mpFighters[defender]->petName <<" passed out from exhaustion."<< endl;
		cout << "Congrats to " << mpFighters[attacker]->petName;
		EndBattle();
	}
	else {
		//Else play next turn
		NextTurn();
	}
}

void Battle::NextTurn()
{
	cout << "=========================\n";
	cout << mpFighters[0]->petName << " : "
		<< mpFighters[0]->GetCurrentLifePoints() << "/"
		<< mpFighters[0]->GetMaxLifePoints() << endl;
	cout << mpFighters[1]->petName << " : "
		<< mpFighters[1]->GetCurrentLifePoints() << "/"
		<< mpFighters[1]->GetMaxLifePoints() << endl;
	cout << "=========================\n";
	mTurn = !mTurn;
	PlayTurn();
}

void Battle::EndBattle()
{
}

Battle::Battle()
{
	//Default constructor
	mpFighters[0] = nullptr;
	mpFighters[1] = nullptr;
}

Battle::Battle(Pokemon& first, Pokemon& second)
{
	mpFighters[0] = &first;
	mpFighters[1] = &second;
}

Battle::~Battle()
{
}

void Battle::StartBattle()
{
	//Display message of the battle starting
	cout << "Battle starts between " << mpFighters[0]->petName<<" and "<<mpFighters[1]->petName<<endl;
	//Play first turn
	mTurn = true;
	PlayTurn();
}
