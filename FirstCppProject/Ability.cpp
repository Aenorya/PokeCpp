#include "Ability.h"
using namespace std;

//Constructors / Desctructor
Ability::Ability()
{
	mName = "Default";
	mDescription = "Default";
	mDamages = 0;
	mEnergyCost = -1;
	mType = PokeType::Normal;
}
Ability::Ability(string name, string desc, int damages, PokeType type)
{
	mName = name;
	mDescription = desc;
	mDamages = damages;
	mEnergyCost = 0;
	mType = type;

}
Ability::Ability(string name, string desc, int damages, int energy, PokeType type)
{
	mName = name;
	mDescription = desc;
	mDamages = damages;
	mEnergyCost = energy;
	mType = type;
}

Ability::~Ability() {}
//Getters for attributes
string Ability::GetName() { return mName;  }
string Ability::GetDescription() { return mDescription; }
int Ability::GetDamages() { return mDamages; }
int Ability::GetEnergyCost() { return mEnergyCost; }

PokeType Ability::GetType()
{
	return mType;
}
