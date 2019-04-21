#include "Pokemon.h"

/************************************************************************
* Method Pokemon: Class Pokemon
*----------------------------------------------------------------------
* 	 This method creates the Pokemon object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Pokemon::Pokemon()
{
    basic.pokedexNumber 				    = 0;
    basic.name								.clear();
    basic.species							.clear();
    basic.priType							.clear();
    basic.secType							.clear();
    basic.description						.clear();
    basic.abilites 							= 0;
    basic.ability							.clear();
    basic.abilityDesc						.clear();
    basic.altAbility						.clear();
    basic.altAbilityDesc					.clear();
    basic.hiddenAbility						.clear();
    basic.hiddenAbilityDesc					.clear();
    evol.evolutions 						= 0;
    evol.secondEvo							= false;
    evol.finalEvo							= false;
    evol.branchEvo							= false;
    evol.evoThroughLvl 						= false;
    evol.evoThroughCond 					= false;
    evol.evoLvl 							= 0;
    evol.finalEvoLvl 						= 0;
    evol.firstEvoNum 						= 0;
    evol.secondEvoNum 						= 0;
    evol.finalEvoNum 						= 0;
    evol.branchEvoNum 						= 0;
    evol.secondEvoCond						.clear();
    evol.finalEvoCond						.clear();
}

/************************************************************************
* Method ~Pokemon: Class Pokemon
*----------------------------------------------------------------------
* 	 This method deletes the Pokemon object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Pokemon::~Pokemon()
{

}

/************************************************************************
* Method PrintAbility: Class Pokemon
*----------------------------------------------------------------------
* 	 This method prints the abilities of the Pokemon
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		fout (ostream) - the output variable
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
string Pokemon::PrintAbility() const
{
    std::ostringstream out; //OUT - the output stream variable

    //PROCESSING - Based on how many abilities the pokemon has, print their info
    switch(basic.abilites)
    {
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
    }

    return out.str();
}

//Overloading the extraction operator to get input from the file
std::ifstream& operator >>(std::ifstream& isObject, Pokemon& cObject)
{
    isObject >> cObject.basic.pokedexNumber;

    isObject.ignore(10000, '\n');

    getline(isObject, cObject.basic.name);

    getline(isObject, cObject.basic.species);

    getline(isObject, cObject.basic.priType);

    getline(isObject, cObject.basic.secType);

    getline(isObject, cObject.basic.description);

    getline(isObject, cObject.basic.ability);

    getline(isObject, cObject.basic.abilityDesc);

    getline(isObject, cObject.basic.hiddenAbility);

    getline(isObject, cObject.basic.hiddenAbilityDesc);

    isObject >> cObject.basic.abilites;

    isObject.ignore(1000, '\n');

    getline(isObject, cObject.basic.altAbility);

    getline(isObject, cObject.basic.altAbilityDesc);

    isObject >> cObject.evol.evolutions;

    isObject >> cObject.evol.secondEvo;

    isObject >> cObject.evol.evoThroughLvl;

    isObject >> cObject.evol.evoThroughCond;

    isObject >> cObject.evol.evoLvl;

    isObject >> cObject.evol.firstEvoNum;

    isObject.ignore(1000, '\n');

    getline(isObject, cObject.evol.secondEvoCond);

    isObject >> cObject.evol.secondEvoNum;

    isObject >> cObject.evol.finalEvo;

    isObject >> cObject.evol.finalEvoLvl;

    isObject.ignore(1000, '\n');

    getline(isObject, cObject.evol.finalEvoCond);

    isObject >> cObject.evol.finalEvoNum;

    isObject >> cObject.evol.branchEvo;

    isObject >> cObject.evol.branchEvoNum;

    isObject.ignore(1000, '\n');

    return isObject;
}
