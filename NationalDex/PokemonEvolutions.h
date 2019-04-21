#ifndef POKEMONEVOLUTIONS_H_
#define POKEMONEVOLUTIONS_H_

#include "Pokemon.h"	/** Pokemon **/
#include <vector>		/** vector  **/
using std::vector;

//Namespace for the global constants in the class
/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR COLUMN SIZE
 * ------------------------------------------------------------------------
 * EVO_COL        : The size of the evolution column
 * BRANCH_EVO_COL : The size of the branch evolution column
 * ------------------------------------------------------------------------
 * USED FOR SPECIFIC VALUES
 * ------------------------------------------------------------------------
 * SPECIAL_BRANCHE_EVOS : The Pokemon that have speacial branch evolutions
 * WURPLE_EVOLUTIONS    : The Wurmple evolutions that have branch evolutions
 * TYROGUE_EVOLUTIONS   : The Tyrogue evolutions that have branch evolutions
 * EEVEELUTIONS			: The Eeveelutions that have branch evolutions
 *************************************************************************/
namespace globalPkmEvoConsts
{
    const vector<int> SPECIAL_BRANCHE_EVOS
    {106, 107, 133, 134, 135, 136, 196, 197, 236, 237, 265, 266, 267,
     268, 269, 470, 471, 700};

    const vector<int> WURPLE_EVOLUTIONS{265, 266, 267, 268, 269};

    const vector<int> TYROGUE_EVOLUTIONS{236, 106, 107, 237};

    const vector<int> EEVEELUTIONS{133, 134, 135, 136, 196, 197, 470, 471,
                                   700};
    const int EVO_COL        = 70;
    const int BRANCH_EVO_COL = 50;
}

/************************************************************************
* PokemonEvolutions Class
* 	This class represents Pokemon Evolutions. It manages 6 attributes:
* 		pokedexCopy, mainPokemon, firstEvo, secondEvo, finalEvo, and branchEvo
*************************************************************************/
class PokemonEvolutions //Base Class
{
    public:
        /******************************
         ** CONSTRUCTOR & DESTRUCTOR **
         ******************************/

        /****************************************************************
         * PokemonEvolutions ();
         *   Constructor; this method initializes the Pokemon Evolutions object
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        PokemonEvolutions(); //Default Constructor

        /****************************************************************
         * PokemonEvolutions ();
         *   Constructor; this method initializes the Pokemon Evolutions object
         *   			  with values
         *   Parameters: pokedex       (vector<Pokemon>) - the pokedex
         *   			 currentPokemon(currentPokemon)  - the current Pokemon
         *   Return: none
         ***************************************************************/
        PokemonEvolutions(const vector<Pokemon>& pokedex,
                          const Pokemon& currentPokemon);//Non-Default
                                                         //Constructor

        /****************************************************************
         * ~PokemonEvolutions ();
         *   Deconstructor; does not perform any specific function
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        ~PokemonEvolutions(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        /****************************************************************
         *void SetInitialValues(const vector<Pokemon>& pokedex,
         *	 	 	 	        const Pokemon& currentPokemon);
         *   Mutator; this method set the values of the Pokemon Evolutions
         *   		  object
         *   Parameters: pokedex       (vector<Pokemon>) - the pokedex
         *   			 currentPokemon(currentPokemon)  - the current Pokemon
         *   Return: none
         ***************************************************************/
        void SetInitialValues(const vector<Pokemon>& pokedex,
                              const Pokemon& currentPokemon);

        /*******************
         **** ACCESSORS ****
         *******************/

        /****************************************************************
         * 	void PrintEvoTree(std::ostream &fout) const;
         *
         *   Accessor; this prints the evolution tree
         *   Parameters: fout (ostream) - the output variable
         *   Return: none
         ***************************************************************/
        string PrintEvoTree() const;

        /****************************************************************
         * 	void PrintTwoEvos(std::ostream &fout) const;
         *
         *   Accessor; this prints a two evolution family tree
         *   Parameters: fout (ostream) - the output variable
         *   Return: none
         ***************************************************************/
        string PrintTwoEvos() const;

        /****************************************************************
         * 	void PrintThreeEvos(std::ostream &fout) const;
         *
         *   Accessor; this prints a three evolution family tree
         *   Parameters: fout (ostream) - the output variable
         *   Return: none
         ***************************************************************/
        string PrintThreeEvos() const;

        /****************************************************************
         * 	void PrintBranchEvos(std::ostream &fout) const;
         *
         *   Accessor; this prints a branch evolution family tree
         *   Parameters: fout (ostream) - the output variable
         *   Return: none
         ***************************************************************/
        string PrintBranchEvos() const;

        /****************************************************************
         * 	void PrintSpecialEvosBranch(std::ostream &fout) const;
         *
         *   Accessor; this prints the special branch evolution family tree
         *   Parameters: fout (ostream) - the output variable
         *   Return: none
         ***************************************************************/
        string PrintSpecialEvosBranch() const;

    private:
        vector<Pokemon> pokedexCopy; //A copy of the Pokedex

        Pokemon mainPokemon;		 //The main Pokemon
        Pokemon firstEvo;			 //The first evolution of the Pokemon
        Pokemon secondEvo;			 //The second evolution of the Pokemon
        Pokemon finalEvo;			 //The final evolution of the Pokemon
        Pokemon branchEvo;			 //The branch evolution of the Pokemon
};

#endif /* POKEMONEVOLUTIONS_H_ */
