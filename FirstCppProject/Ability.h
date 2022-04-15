#pragma once
#include <string>
#include "PokeType.h"
//Describes a pokemon ability
class Ability
{
private:
	//Name
	std::string mName;
	//Description
	std::string mDescription;
	//Damages
	int mDamages;
	//Energy cost
	int mEnergyCost;
	//Ability Type
	PokeType mType;

public:
	//Constructors / Desctructor
	Ability();
	Ability(std::string name, std::string desc, int damages, PokeType type);
	Ability(std::string name, std::string desc, int damages, int energy, PokeType type);

	~Ability();
	//Getters for attributes
	std::string GetName();
	std::string GetDescription();
	int GetDamages();
	int GetEnergyCost();
	PokeType GetType();
	//If you need help, raise your hand on the
	//Google Meet ! :)
};

