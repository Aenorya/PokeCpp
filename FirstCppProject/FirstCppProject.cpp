// FirstCppProject.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Utils.h"
#include "Battle.h"


using namespace std;



int main()
{
    cout << "Hello World!\n";
    int life = 10;
    cout << "The value " << life << " is stored at memory adress : " << &life << endl;
    Damage(life);
    cout << life << endl;
    DamageReference(life);
    cout << life << endl;
    DamagePointedObject(&life);
    cout << life << endl;
    //if life > 5 show "Alive" else show "Dying"
    cout << "Player is " << GetLifeText(life) << endl;

    //ShowMultiDimensionalMap();
    //ShowVector();
    cout << "============PIKACHU=============\n";
    Pokemon pikachu = Pokemon("Pikachu", "chunky boi",PokeType::Electric, 40);
    pikachu.DisplaySumUp();
    cout << "=========================\n";
    pikachu.petName = "Pika Pika";
    pikachu.Hurt(6);
    pikachu.Heal(12);
    pikachu.DisplaySumUp();
    Ability thunderShock = Ability("Thunder Shock", "Goes bzzzz", 20, 2, PokeType::Electric);
    Ability gnaw = Ability("Gnaw", "Gnaws", 10, PokeType::Normal);
    Ability cutie = Ability("Cutie Pie", "2 Cute 2 be true", 10, PokeType::Normal);
    pikachu.LearnAbility(thunderShock);
    pikachu.LearnAbility(gnaw);
    pikachu.LearnAbility(cutie);

    Pokemon stari = Pokemon("Staryu", "A cute starfish",PokeType::Water, 30);
    stari.LearnAbility(Ability("Splash", "It's wet", 13, PokeType::Water));
    stari.LearnAbility(Ability("Water Jet", "It's wetter", 15, PokeType::Water));

    Battle fight (pikachu, stari);
    fight.StartBattle();
}

