#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"
class Trainer
{
private:
	//Name
	std::string mName;
	//Catchphrase
	std::string mCatchphrase;
	//Money
	int mMoney;
	//Type string
	std::string mType;
	//Pokeballs count
	int mPokeballCount;
	//Pokemons
	std::vector<Pokemon> mPokemons;
	//Inventory with Item objects

	//Which pokemon is active now ?
public:
	int mActivePokemon;
	//Constructors / Destructor
	Trainer();
	Trainer(std::string name,std::string type, std::string catchPhrase, std::vector<Pokemon> pokemons);
	~Trainer();
	//Getters / Setters
	std::string GetName();
	std::string GetCatchphrase();
	int GetMoney();
	std::string GetType();
	int GetPokeballCount();
	Pokemon& GetPokemon(int index);
	Pokemon& GetActivePokemon();
	int GetPokemonCount();
	void Introduce(); // Display type, name, catchphrase
	void DisplayPokemons(); // Display each pokemon the trainer has


	//CatchPokemon
	void CatchPokemon(Pokemon pokemon);
	//SendPokemon
	void ChangePokemon(int newPokemon);
	//Inventory Handling
	//BuyItem
	//SellItem
};

