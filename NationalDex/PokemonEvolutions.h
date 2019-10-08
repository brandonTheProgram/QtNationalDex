#ifndef POKEMONEVOLUTIONS_H_
#define POKEMONEVOLUTIONS_H_

#include "Pokemon.h"	/** Pokemon **/
#include <vector>		/** vector  **/
using std::vector;

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
    const vector<int> SPECIAL_BRANCHE_EVOS{
    106, 107, 133, 134, 135, 136, 196, 197, 236, 237, 265, 266, 267, 268, 269,
    470, 471, 700};

    const vector<int> WURPLE_EVOLUTIONS{265, 266, 267, 268, 269};

    const vector<int> TYROGUE_EVOLUTIONS{236, 106, 107, 237};

    const vector<int> EEVEELUTIONS{133, 134, 135, 136, 196, 197, 470, 471,
                                   700};
    const int EVO_COL        = 70;
    const int BRANCH_EVO_COL = 50;
}

/************************************************************************
* PokemonEvolutions Class
* 	This class represents Pokemon Evolutions object
*************************************************************************/
class PokemonEvolutions{
    public:
        PokemonEvolutions(); //Default Constructor

        //Non-Default Constructor
        PokemonEvolutions(const vector<Pokemon>& POKEDEX,
                          const Pokemon        & CURRENT_POKEMON);

        virtual ~PokemonEvolutions(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        void SetInitialValues(const vector<Pokemon>& POKEDEX,
                              const Pokemon        & CURRENT_POKEMON);

        /*******************
         **** ACCESSORS ****
         *******************/

        //Return the evolution tree as a string
        string PrintEvoTree() const;

        //Return the evolution tree as a string for pokemon with 2 evolutions
        string PrintTwoEvos() const;

        //Return the evolution tree as a string for pokemon with 3 evolutions
        string PrintThreeEvos() const;

        //Return the evolution tree as a string for pokemon with a branch evo
        string PrintBranchEvos() const;

        //Return the evolution tree as a string for pokemon with 2+ branch evos
        string PrintSpecialEvosBranch() const;

    private:
        vector<Pokemon> pokedexCopy; //A copy of the Pokedex

        Pokemon         mainPokemon; //The main Pokemon
        Pokemon         firstEvo;	 //The first evolution of the Pokemon
        Pokemon         secondEvo;	 //The second evolution of the Pokemon
        Pokemon         finalEvo;	 //The final evolution of the Pokemon
        Pokemon         branchEvo;	 //The branch evolution of the Pokemon
};

#endif /* POKEMONEVOLUTIONS_H_ */
