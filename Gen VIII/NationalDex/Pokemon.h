#ifndef POKEMON_H_
#define POKEMON_H_

#include <sstream> 			 /** ostringstream                 **/
#include <fstream> 			 /** fstream 					   **/
#include <iomanip>           /** setw                          **/
#include <string>            /** string                        **/
using std::string;
using std::endl;

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR COLUMN SIZE
 * ------------------------------------------------------------------------
 * DESC_COL    : The size of the column to display the description
 * ABILITY_COL : The size of the column to display the ability
 *************************************************************************/
namespace globalPkmnConsts{
    const int DESC_COL    = 75;
    const int ABILITY_COL = 60;
}

//The struct that holds the basic information that a Pokemon would have
struct basicInfo{
    int    pokedexNumber;	  //The pokedex number of the Pokemon
    string name;			  //The name of the Pokemon
    string species;			  //The species of the Pokemon
    string priType;			  //The primary type of the Pokemon
    string secType;			  //The second type of the Pokemon
    string description;		  //The description of the Pokemon
    int    abilites;		  //The amount of abilities the Pokemon has
    string ability;			  //The name of the first ability
    string abilityDesc;		  //The description of the first ability
    string altAbility;		  //The name of the alternative ability
    string altAbilityDesc;	  //The description of the alternative ability
    string hiddenAbility;	  //The name of the hidden ability
    string hiddenAbilityDesc; //The description of the hidden ability
    string versionOneLocation;//The location of the pokemon in version one of
                              //the current generation
    string versionTwoLocation;//The location of the pokemon in version two of
                              //the current generation
};

//The struct that holds the information pertaining to the Pokemon's evolutions
struct evolutionInfo{
    int    evolutions;		//The amount of different evolutions the Pokemon has
    bool   secondEvo;		//If the Pokemon is the second evolution
    bool   finalEvo;		//If the Pokemon is the final evolution
    bool   branchEvo;		//If the Pokemon is the branch evolution
    bool   evoThroughLvl;	//If the Pokemon evolves through leveling up
    bool   evoThroughCond;	//If the Pokemon evolves through special conditions
    int    evoLvl;			//The level that the Pokemon evolves at
    int    finalEvoLvl;		//The final evolution level to evolve
    int    firstEvoNum;		//The pokedex number of the first evolution
    int    secondEvoNum;	//The pokedex number of the second evolution
    int    finalEvoNum;		//The pokedex number of the final evolution
    int    branchEvoNum;	//The pokedex number of the branch evolution
    string secondEvoCond;	//The condition to evolve into the second evolution
    string finalEvoCond;	//The condition to evolve into the final evolution
};

/************************************************************************
* Pokemon Class
* 	This class represents a Pokemon object
*************************************************************************/
class Pokemon{
    public:
        //Overloading the extraction operator for reading from a file
        friend std::ifstream& operator >>(std::ifstream&, Pokemon&);

        Pokemon(); //Default Constructor

        virtual ~Pokemon(); //Deconstructor

        /*******************
         **** ACCESSORS ****
         *******************/

        int GetPokedexNumber() const{return basic.pokedexNumber;}

        string GetName()const{return basic.name;}

        string GetSpecies()const{return basic.species;}

        string GetPriType()const{return basic.priType;}

        string GetSecType()const{return basic.secType;}

        string GetDescription()const{return basic.description;}

        int GetAbilites()const{return basic.abilites;}

        string GetAbility()const{return basic.ability;}

        string GetAbilityDesc()const{return basic.abilityDesc;}

        string GetAltAbility()const{return basic.altAbility;}

        string GetAltAbilityDesc()const{return basic.altAbilityDesc;}

        string GetHiddenAbility()const{return basic.hiddenAbility;}

        string GetHiddenAbilityDesc()const{return basic.hiddenAbilityDesc;}

        string GetVersionOneLocation() const{return basic.versionOneLocation;}

        string GetVersionTwoLocation() const{return basic.versionTwoLocation;}

        int GetEvolutions()const {return evol.evolutions;}

        bool GetSecondEvo()const {return evol.secondEvo;}

        bool GetFinalEvo()const {return evol.finalEvo;}

        bool GetBranchEvo()const {return evol.branchEvo;}

        bool GetEvoThroughLvl()const {return evol.evoThroughLvl;}

        bool GetEvoThroughCond()const {return evol.evoThroughCond;}

        int GetEvoLvl()const {return evol.evoLvl;}

        int GetFinalEvoLvl()const {return evol.finalEvoLvl;}

        int GetFirstEvoNum()const {return evol.firstEvoNum;}

        int GetSecondEvoNum()const {return evol.secondEvoNum;}

        int GetFinalEvoNum()const {return evol.finalEvoNum;}

        int GetBranchEvoNum()const {return evol.branchEvoNum;}

        string GetSecondEvoCond()const {return evol.secondEvoCond;}

        string GetFinalEvoCond()const {return evol.finalEvoCond;}

        //Return the ability as a string
        string PrintAbility() const;

    private:
        basicInfo       basic;		//The basic information of a Pokemon
        evolutionInfo   evol;		//The evolution information of a Pokemon
};

#endif /* POKEMON_H_ */
