#ifndef POKEDEX_H_
#define POKEDEX_H_

#include "Pokemon.h"           /** Pokemon                    **/
#include "PokemonEvolutions.h" /** PokemonEvolution           **/
#include "PokemonWeakness.h"   /** PokemonWeakness            **/
#include "Moveset.h"           /** Moveset                    **/

//Namespace for the global constants in the class
/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR ARRAY/VECTOR SIZE
 * ------------------------------------------------------------------------
 * AR_SIZE	: The size of the array/vector
 * ------------------------------------------------------------------------
 * USED FOR MAX REGION DEX SIZES
 * ------------------------------------------------------------------------
 * KANTO_DEX	: The size of the Kanto Pokedex
 * JOHTO_DEX	: The size of the Johto Pokedex
 * HOENN_DEX	: The size of the Hoenn Pokedex
 * SINNOH_DEX	: The size of the Sinnoh Pokedex
 * UNOVA_DEX	: The size of the Unova Pokedex
 * KALOS_DEX	: The size of the Kalos Pokedex
 * ALOLA_DEX	: The size of the Alola Pokedex
 *************************************************************************/
namespace globalPDexConsts
{
    const int AR_SIZE          = 807;
    const int MAX_ATTKS        = 724;
    const int KANTO_DEX        = 151;
    const int JOHTO_DEX        = 251;
    const int HOENN_DEX        = 386;
    const int SINNOH_DEX       = 493;
    const int UNOVA_DEX        = 649;
    const int KALOS_DEX        = 721;
    const int ALOLA_DEX        = 807;
    const int INVALID_COL      = 30;
}

//A Pokemon object with it's information
struct Pkmn
{
    Pokemon           currentPkmn;
    PokemonEvolutions pkmnEvos;
    Moveset           pkmnMoves;
    PokemonWeakness   pkmnWeakness;
};

/************************************************************************
* Pokedex Class
* 	This class represents a Pokedex object. It manages 4 attributes:
* 		pokedex, attackDex, pokedexCopy, and currentPokemon
*************************************************************************/
class Pokedex //Base class
{
    public:
        /******************************
         **      OVERLOADERS         **
         ******************************/
        //Overloading the array operator
        Pkmn& operator[] (int index){return pokedex[index];}

        /******************************
         ** CONSTRUCTOR & DESTRUCTOR **
         ******************************/

        /****************************************************************
         * Pokedex ();
         *   Constructor; this method initializes the Pokdex object
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        Pokedex(); //Default Constructor

        /****************************************************************
         * ~Pokedex ();
         *   Deconstructor; does not perform any specific function
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        ~Pokedex(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        /****************************************************************
         * 	void CreateAttackList(const string& INPUT_FILE);
         *
         *   Mutator; this method creates the attackdex for the program
         *   Parameters: INPUT_FILE (string) - the name of the input file
         *   Return: none
         ***************************************************************/
        void CreateAttackList(const string& INPUT_FILE);

        /****************************************************************
         * 	void CreatePokedexCopy();
         *
         *   Mutator; this method creates a copy of the Pokedex with only a
         *   		  Pokemon and not attacks or weaknesses
         *   Parameters:
         *   Return: none
         ***************************************************************/
        void CreatePokedexCopy();

        /****************************************************************
         * 	void LoadRegion(const string& INPUT_FILE, const int& REGION_MAX,
         * 					const string& ATTACK_FILE);
         *
         *   Mutator; this method initializes the pokedex by loading in a region
         *   Parameters: INPUT_FILE (string) - the name of the input file
         *   			 REGION_MAX (int)    - the regional max in the pokedex
         *   			 ATTACK_FILE(string) - the attacks for that region
         *   Return: none
         ***************************************************************/
        void LoadRegion(const string& INPUT_FILE, const int& REGION_MAX,
                        const string& ATTACK_FILE);

        /****************************************************************
         * 	void LoadPokemonMoves(std::ifstream & fin,
         * 						  vector<string>& attackNames,
         *		   	   	   	      vector<int>   & attackLvls);
         *
         *   Mutator; this method loads the moves of a pokemon from the
         *   		  input file
         *   Parameters: fin         (ifstream)       - the input file variable
         *   			 attackNames (vector<string>) - the list of attack names
         *   			 attackLvls  (vector<int>)    - the list of attack
         *   			 								levels
         *   Return: attackNames and attackLvls
         ***************************************************************/
        void LoadPokemonMoves(std::ifstream& fin, vector<string>& attackNames,
                              vector<int>& attackLvls);

        /****************************************************************
         * 	void SetEvolutions();
         *
         *   Mutator; this method sets the evolutions to every Pokemon
         *   Parameters:
         *   Return: none
         ***************************************************************/
        void SetEvolutions();

        /*******************
         **** ACCESSORS ****
         *******************/

        /****************************************************************
         * 	vector<Pkmn> GetRegion(const int& START, const int& END);
         *
         *   Accessor; this gets a region range of Pokemon from the Pokedex
         *   Parameters: START  (int) - the starting index of the region
         *   			 END    (int) - the ending index of the region
         *   Return: a vector of the Pokemon specified
         ***************************************************************/
        vector<Pkmn> GetRegion(const int& START, const int& END) const;

    private:
        vector<Pkmn>      pokedex;			//The Pokedex
        vector<Attack>    attackDex;		//The AttackDex
        vector<Pokemon>   pokedexCopy;		//The Copy of the Pokedex
        Pkmn              currentPokemon;	//The current Pokemon
};

#endif /* POKEDEX_H_ */
