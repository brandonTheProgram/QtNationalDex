#include "Pokemon.h"

Pokemon::Pokemon(){
    this->basic.pokedexNumber   = 0;
    this->basic.abilites 		= 0;
    this->evol.evolutions 		= 0;
    this->evol.secondEvo		= false;
    this->evol.finalEvo			= false;
    this->evol.branchEvo		= false;
    this->evol.evoThroughLvl 	= false;
    this->evol.evoThroughCond 	= false;
    this->evol.evoLvl 			= 0;
    this->evol.finalEvoLvl 		= 0;
    this->evol.firstEvoNum 		= 0;
    this->evol.secondEvoNum 	= 0;
    this-> evol.finalEvoNum 	= 0;
    this->evol.branchEvoNum 	= 0;
}

Pokemon::Pokemon(const basicInfo& BI, const evolutionInfo& EI){
    this->basic = BI;
    this->evol  = EI;
}

Pokemon::~Pokemon(){}

string Pokemon::PrintAbility() const
{
    std::ostringstream out; //The output stream variable

    //PROCESSING - Based on how many abilities the pokemon has, print their info
    switch(basic.abilites){
    case 1: out << "Ability: " << basic.ability << endl << endl;
            out << basic.ability << ": " << basic.abilityDesc << endl;
            break;

    case 2: out << "Abilities: " << basic.ability << " - "
                 << basic.hiddenAbility << " (Hidden Ability)" << endl << endl;

            out << basic.ability << ": " << basic.abilityDesc;

            out << "\n\nHidden Ability\n\n";

            out << basic.hiddenAbility << ": " << basic.hiddenAbilityDesc
                << endl;
            break;

    case 3:	out << "Abilities: "       << basic.ability << " - "
                 << basic.altAbility    << " - "         << basic.hiddenAbility
                 << " (Hidden Ability)" << endl          << endl;

            out << basic.ability << ": " << basic.abilityDesc
                 << endl << endl;

            out << basic.altAbility << ": " << basic.altAbilityDesc;

            out << "\n\nHidden Ability\n\n";

            out << basic.hiddenAbility << ": " << basic.hiddenAbilityDesc
                << endl;
            break;

    default: break;
    }

    return out.str();
}

std::ifstream& operator >>(std::ifstream& isObject, Pokemon& cObject){
    //IN - Read in the information for a Pokemon and assign the values
    isObject >> cObject.basic.pokedexNumber;

    isObject.ignore(10000, '\n');

    getline(isObject, cObject.basic.name);

    getline(isObject, cObject.basic.species);

    getline(isObject, cObject.basic.priType);

    getline(isObject, cObject.basic.secType);

    getline(isObject, cObject.basic.description);

    getline(isObject, cObject.basic.versionOneLocation);

    getline(isObject, cObject.basic.versionTwoLocation);

    getline(isObject, cObject.basic.ability);

    getline(isObject, cObject.basic.abilityDesc);

    getline(isObject, cObject.basic.hiddenAbility);

    getline(isObject, cObject.basic.hiddenAbilityDesc);

    getline(isObject, cObject.basic.altAbility);

    getline(isObject, cObject.basic.altAbilityDesc);

    getline(isObject, cObject.evol.secondEvoCond);

    getline(isObject, cObject.evol.finalEvoCond);

    isObject >> cObject.basic.abilites;

    isObject >> cObject.evol.evolutions;

    isObject >> cObject.evol.secondEvo;

    isObject >> cObject.evol.evoThroughLvl;

    isObject >> cObject.evol.evoThroughCond;

    isObject >> cObject.evol.evoLvl;

    isObject >> cObject.evol.firstEvoNum;

    isObject >> cObject.evol.secondEvoNum;

    isObject >> cObject.evol.finalEvo;

    isObject >> cObject.evol.finalEvoLvl;

    isObject >> cObject.evol.finalEvoNum;

    isObject >> cObject.evol.branchEvo;

    isObject >> cObject.evol.branchEvoNum;

    isObject.ignore(1000, '\n');

    isObject.ignore(1000, '\n');

    return isObject;
}
