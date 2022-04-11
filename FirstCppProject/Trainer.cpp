#include "Trainer.h"
#include <iostream>

using namespace std;

Trainer::Trainer(){
	mName = "Default";
	mCatchphrase = "Hello";
	mMoney = 10;
	mType = "Scout";
	mPokeballCount = 6;
	mActivePokemon = -1;
}
Trainer::Trainer(string name, string type, string catchPhrase, vector<Pokemon> pokemons) {
	mName = name;
	mCatchphrase = catchPhrase;
	mMoney = 10;
	mType = type;
	mPokeballCount = 6;
	mActivePokemon = -1;
}
Trainer::~Trainer() {
	mPokemons.~vector();
}

//Getters / Setters
string Trainer::GetName() {
	return mName;
}
string Trainer::GetCatchphrase() {
	return mCatchphrase;
}
int Trainer::GetMoney() {
	return mMoney;
}
string Trainer::GetType() { 
	return mType;
}
int Trainer::GetPokeballCount() {
	return mPokeballCount;
}
Pokemon& Trainer::GetPokemon(int index) {
	if (index >= 0 && index < mPokemons.size()) {
		return mPokemons[index];
	}
	else {
		Pokemon defaultPokemon = Pokemon();
		cerr << "You tried to access a pokemon that doesn't exist...\n";
		return defaultPokemon;
	}
}
Pokemon& Trainer::GetActivePokemon() {
	return GetPokemon(mActivePokemon);
}
int Trainer::GetPokemonCount() {
	return mPokemons.size();
}
void Trainer::Introduce() {
	cout << mName << " : \"" << mCatchphrase <<"\"\n";
	cout << mType << " " << mName << " wants to fight\n";
} // Display type, name, catchphrase
void Trainer::DisplayPokemons() {
	for (int p = 0; p < mPokemons.size(); p++) {
		cout << "->";
		cout << " * " << p << " : " << mPokemons[p].GetName() << " | "
			<< mPokemons[p].GetDescription() << " | " << mPokemons[p].GetCurrentLifePoints()
			<< "/" << mPokemons[p].GetMaxLifePoints() << " hp\n";
	}

} // Display each pokemon the trainer has