#include "Pokemon.h"

#include <iostream>
using namespace std;


Pokemon::Pokemon()
{
	mName = "Default";
	mDescription = "Default";
	petName = "Default";
	mMaxLifePoints = 1;
	mCurrentLifePoints = mMaxLifePoints;
	mType = PokeType::Normal;
}
Pokemon::Pokemon(string name, string desc, PokeType type, int maxLifePoints)
{
	mName = name;
	mDescription = desc;
	petName = mName;
	mMaxLifePoints = maxLifePoints;
	mCurrentLifePoints = mMaxLifePoints;
	mType = type;
}
//Add constructor with abilities parameter

Pokemon::~Pokemon()
{
	//Empty until we have complex members
}

string Pokemon::GetName()
{
	return mName;
}
string Pokemon::GetDescription()
{
	return mDescription;
}
int Pokemon::GetMaxLifePoints()
{
	return mMaxLifePoints;
}
int Pokemon::GetCurrentLifePoints()
{
	return mCurrentLifePoints;
}
void Pokemon::Hurt(int points)
{
	cout << petName << " has taken " << points << " hp of damages.\n";
	//Do not allow less than 0 health
	if(mCurrentLifePoints - points < 0)
	{
		//The pokemon dies
		cout << petName << " has passed out.... You should take better care of your pokemons\n";
		mCurrentLifePoints = 0;
	}
	else
	{
		mCurrentLifePoints -= points; // mCurrentLifePoints = mCurrentLifePoints - points;
		cout << petName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
void Pokemon::Heal(int points)
{
	cout << petName << " has been healed of " << points << " hp.\n";
	if(mCurrentLifePoints + points > mMaxLifePoints)
	{
		//The pokemon is full health
		cout << petName << "'s health is back to maximum.\n";
		mCurrentLifePoints = mMaxLifePoints;
	} else
	{
		mCurrentLifePoints += points;  // mCurrentLifePoints = mCurrentLifePoints + points;
		cout << petName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
//Add learn ability
void Pokemon::LearnAbility(Ability ability)
{
	if(mAbilities.size() < MAX_ABILITIES)
	{
		//I can add ability
		mAbilities.push_back(ability);
		cout << mName << " learned : " << ability.GetName()<<endl;
	} else
	{
		cout << mName << " already knows " << MAX_ABILITIES << " abilities.\n";
		//TODO choose ability to replace
		int choice = 0;
		do
		{
			DisplayAbilities();
			cout << "Which one do you want to replace ?";
			cin >> choice;
		} while (choice <= 0 || choice > MAX_ABILITIES);
		mAbilities[choice - 1] = ability;
		cout << "Ability was replaced with success.\n";
	}
	cout<<"New abilities are : \n";
	DisplayAbilities();
}

void Pokemon::DisplayAbilities()
{
	cout << petName << " knows the following abilities : \n";
	for(int a = 0; a < mAbilities.size(); a++)
	{
		cout << "\t*" << (a+1) << " : " << mAbilities[a].GetName()
		<<" | "<<mAbilities[a].GetDescription()
		<<" | dmg : "<<mAbilities[a].GetDamages()<<" hp.\n";
	}
}
int Pokemon::GetAbilityCount()
{
	return mAbilities.size();
}
Ability Pokemon::GetAbility(int index)
{
	if (index > 0 && index < mAbilities.size()) {
		return mAbilities[index];
	}
	return Ability();
}
void Pokemon::Attack(Pokemon& target, int ability)
{
	cout << petName << " attacks " << target.petName << " with " << mAbilities[ability].GetName() << endl;
	int damages = mAbilities[ability].GetDamages();
	if (target.IsResistantTo(mAbilities[ability].GetType())) {
		damages /= 2; // damages = damages / 2;
		cout << "It's not very effective..\n";
	}
	else if (target.IsWeakTo(mAbilities[ability].GetType())) {
		damages *= 2; //damages = damages *2;
		cout << "It's very effective!\n";
	}
	target.Hurt(damages);
}
//Add attack

void Pokemon::DisplaySumUp()
{
	cout << petName << " is a " << mName << endl;
	cout<< "A " << mName << " is " << mDescription << endl;
	cout << petName << " has " << mCurrentLifePoints << "/" << mMaxLifePoints << " hp.\n";
}

bool Pokemon::IsWeakTo(PokeType attackType)
{
	switch (attackType) {
	case PokeType::Electric:
		return mType == PokeType::Water;
	case PokeType::Fire:
		return mType == PokeType::Grass;
	case PokeType::Grass:
		return mType == PokeType::Water || mType == PokeType::Grass;
	case PokeType::Ground:
		return mType == PokeType::Electric || mType == PokeType::Fire;
	case PokeType::Water:
		return mType == PokeType::Fire || mType == PokeType::Ground;
	}
	return false;
}

bool Pokemon::IsResistantTo(PokeType attackType)
{
	switch (attackType) {
	case PokeType::Electric:
		return mType == PokeType::Ground || mType == PokeType::Grass;
	case PokeType::Fire:
		return mType == PokeType::Ground || mType == PokeType::Fire;
	case PokeType::Grass:
		return mType == PokeType::Fire || mType == PokeType::Grass;
	case PokeType::Ground:
		return mType == PokeType::Grass;
	case PokeType::Water:
		return mType == PokeType::Grass || mType == PokeType::Water;
	}
	return false;
}
