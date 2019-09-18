#ifndef POKEMON_H_
#define POKEMON_H_

#include <sstream> 			 /** ostringstream                 **/
#include <fstream> 			 /** fstream 					   **/
#include <iomanip>           /** setw                          **/
#include <string>            /** string                        **/
using std::string;
using std::endl;

//Namespace for the global constants and function used in and out of the class
/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR COLUMN SIZE
 * ------------------------------------------------------------------------
 * DESC_COL    : The size of the column to display the description
 * ABILITY_COL : The size of the column to display the ability
 *************************************************************************/
namespace globalPkmnConsts
{
    const int DESC_COL    = 75;
    const int ABILITY_COL = 60;
}

//The struct that holds the basic information that a Pokemon would have
struct basicInfo
{
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
struct evolutionInfo
{
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
* 	This class represents a Pokemon object. It manages 3 attributes:
* 		basic, evol, and weaknessAr
*************************************************************************/
class Pokemon //Base Class
{
    public:
        /******************************
         **      OVERLOADERS         **
         ******************************/
        //Overloading the extraction operator for reading from a file
        friend std::ifstream& operator >>(std::ifstream&, Pokemon&);

        /******************************
         ** CONSTRUCTOR & DESTRUCTOR **
         ******************************/

        /****************************************************************
         * Pokemon ();
         *   Constructor; this method initializes the Pokemon object
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        Pokemon(); //Default Constructor

        /****************************************************************
         * ~Pokemon ();
         *   Deconstructor; does not perform any specific function
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        virtual ~Pokemon(); //Deconstructor

        /*******************
         **** ACCESSORS ****
         *******************/

        /****************************************************************
         * int GetPokedexNumber() const;
         *
         *   Accessor; This returns the Pokemon's pokedex number
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: pokedexNumber
         ***************************************************************/
        int GetPokedexNumber() const{return basic.pokedexNumber;}

        /****************************************************************
         * string GetName() const;
         *
         *   Accessor; This returns the Pokemon's name
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: name
         ***************************************************************/
        string GetName()const{return basic.name;}

        /****************************************************************
         * string GetSpecies() const;
         *
         *   Accessor; This returns the Pokemon's species
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: species
         ***************************************************************/
        string GetSpecies()const{return basic.species;}

        /****************************************************************
         * string GetPriType() const;
         *
         *   Accessor; This returns the Pokemon's primary type
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: priType
         ***************************************************************/
        string GetPriType()const{return basic.priType;}

        /****************************************************************
         * string GetSecType() const;
         *
         *   Accessor; This returns the Pokemon's secondary type
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: secType
         ***************************************************************/
        string GetSecType()const{return basic.secType;}

        /****************************************************************
         * string GetDescription() const;
         *
         *   Accessor; This returns the Pokemon's description
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: description
         ***************************************************************/
        string GetDescription()const{return basic.description;}

        /****************************************************************
         * int GetAbilites() const;
         *
         *   Accessor; This returns the Pokemon's number of abilities
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: abilites
         ***************************************************************/
        int GetAbilites()const{return basic.abilites;}

        /****************************************************************
         * string GetAbility() const;
         *
         *   Accessor; This returns the Pokemon's ability name
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: ability
         ***************************************************************/
        string GetAbility()const{return basic.ability;}

        /****************************************************************
         * string GetAbilityDesc() const;
         *
         *   Accessor; This returns the Pokemon's ability description
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: abilityDesc
         ***************************************************************/
        string GetAbilityDesc()const{return basic.abilityDesc;}

        /****************************************************************
         * string GetAltAbility() const;
         *
         *   Accessor; This returns the Pokemon's alternative ability name
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: altAbility
         ***************************************************************/
        string GetAltAbility()const{return basic.altAbility;}

        /****************************************************************
         * string GetAltAbilityDesc() const;
         *
         *   Accessor; This returns the Pokemon's alternative ability
         *   		   description
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: altAbilityDesc
         ***************************************************************/
        string GetAltAbilityDesc()const{return basic.altAbilityDesc;}

        /****************************************************************
         * string GetHiddenAbility() const;
         *
         *   Accessor; This returns the Pokemon's hidden ability name
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: hiddenAbility
         ***************************************************************/
        string GetHiddenAbility()const{return basic.hiddenAbility;}

        /****************************************************************
         * string GetHiddenAbilityDesc() const;
         *
         *   Accessor; This returns the Pokemon's hidden ability description
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: hiddenAbilityDesc
         ***************************************************************/
        string GetHiddenAbilityDesc()const{return basic.hiddenAbilityDesc;}

        /****************************************************************
         * string GetVersionOneLocation() const;
         *
         *   Accessor; This returns the Pokemon's location in version one of
         *             the current generation
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: versionOneLocation
         ***************************************************************/
        string GetVersionOneLocation() const{return basic.versionOneLocation;}

        /****************************************************************
         * string GetVersionTwoLocation() const;
         *
         *   Accessor; This returns the Pokemon's location in version two of
         *             the current generation
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: ultraMoonLoc
         ***************************************************************/
        string GetVersionTwoLocation() const{return basic.versionTwoLocation;}

        /****************************************************************
         * int GetEvolutions() const;
         *
         *   Accessor; This returns the Pokemon's number of evolution
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: evolutions
         ***************************************************************/
        int GetEvolutions()const {return evol.evolutions;}

        /****************************************************************
         * bool GetSecondEvo() const;
         *
         *   Accessor; This returns if the Pokemon is the second evolution
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: secondEvo
         ***************************************************************/
        bool GetSecondEvo()const {return evol.secondEvo;}

        /****************************************************************
         * bool GetFinalEvo() const;
         *
         *   Accessor; This returns if the Pokemon is the final evolution
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: finalEvo
         ***************************************************************/
        bool GetFinalEvo()const {return evol.finalEvo;}

        /****************************************************************
         * bool GetBranchEvo() const;
         *
         *   Accessor; This returns if the Pokemon has a branch evolution
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: branchEvo
         ***************************************************************/
        bool GetBranchEvo()const {return evol.branchEvo;}

        /****************************************************************
         * bool GetEvoThroughLvl() const;
         *
         *   Accessor; This returns if the Pokemon can evolve through leveling
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: evoThroughLvl
         ***************************************************************/
        bool GetEvoThroughLvl()const {return evol.evoThroughLvl;}

        /****************************************************************
         * bool GetEvoThroughCond() const;
         *
         *   Accessor; This returns if the Pokemon can evolve through special
         *   		   conditions
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: evoThroughCond
         ***************************************************************/
        bool GetEvoThroughCond()const {return evol.evoThroughCond;}

        /****************************************************************
         * int GetEvoLvl() const;
         *
         *   Accessor; This returns the Pokemon's evolution level
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: evoLvl
         ***************************************************************/
        int GetEvoLvl()const {return evol.evoLvl;}

        /****************************************************************
         * int GetFinalEvoLvl() const;
         *
         *   Accessor; This returns the Pokemon's evolution final level
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: finalEvoLvl
         ***************************************************************/
        int GetFinalEvoLvl()const {return evol.finalEvoLvl;}

        /****************************************************************
         * int GetFirstEvoNum() const;
         *
         *   Accessor; This returns the Pokemon's first evolution pokedex number
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: firstEvoNum
         ***************************************************************/
        int GetFirstEvoNum()const {return evol.firstEvoNum;}

        /****************************************************************
         * int GetSecondEvoNum() const;
         *
         *   Accessor; This returns the Pokemon's second evolution pokedex
         *   		   number
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: secondEvoNum
         ***************************************************************/
        int GetSecondEvoNum()const {return evol.secondEvoNum;}

        /****************************************************************
         * int GetFinalEvoNum() const;
         *
         *   Accessor; This returns the Pokemon's final evolution pokedex number
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: finalEvoNum
         ***************************************************************/
        int GetFinalEvoNum()const {return evol.finalEvoNum;}

        /****************************************************************
         * int GetBranchEvoNum() const;
         *
         *   Accessor; This returns the Pokemon's branch evolution
         *   		   pokedex number
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: branchEvoNum
         ***************************************************************/
        int GetBranchEvoNum()const {return evol.branchEvoNum;}

        /****************************************************************
         * string GetSecondEvoCond() const;
         *
         *   Accessor; This returns the Pokemon's special condition to evolve
         *   		   into the second evolution
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: secondEvoCond
         ***************************************************************/
        string GetSecondEvoCond()const {return evol.secondEvoCond;}

        /****************************************************************
         * string GetFinalEvoCond() const;
         *
         *   Accessor; This returns the Pokemon's special condition to evolve
         *   		   into the final evolution
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: finalEvoCond
         ***************************************************************/
        string GetFinalEvoCond()const {return evol.finalEvoCond;}

        /****************************************************************
         * void PrintAbility() const;
         *
         *   Accessor; This prints out the Pokemon's abilities
         *-----------------------------------------------------------------
         *   Parameters: fout (ostream) - the output variable
         *-----------------------------------------------------------------
         *   Return: none
         ***************************************************************/
        string PrintAbility() const;

    private:
        basicInfo       basic;		//The basic information of a Pokemon
        evolutionInfo   evol;		//The evolution information of a Pokemon
};

#endif /* POKEMON_H_ */
