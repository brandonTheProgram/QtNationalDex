#ifndef POKEMONEVOLUTIONS_H_
#define POKEMONEVOLUTIONS_H_

#include "Pokemon.h"	/** Pokemon **/
#include <vector>		/** vector  **/
#include <algorithm>
using std::vector;

/*!
 * \namespace globalPkmEvoConsts
 * \brief global constants to be used for a Pokemon Evolutions
 */
namespace globalPkmEvoConsts
{
    /*!
     * \variable SPECIAL_BRANCHE_EVOS
     * \brief The Pokemon that have speacial branch evolutions
     */
    const vector<unsigned int> SPECIAL_BRANCHE_EVOS{
    106, 107, 133, 134, 135, 136, 196, 197, 236, 237, 265, 266, 267, 268, 269,
    470, 471, 700};

    /*!
     * \variable WURMPLE_EVOLUTIONS
     * \brief The evolutions of Wurmple that have special branch evolutions
     */
    const vector<unsigned int> WURMPLE_EVOLUTIONS{265, 266, 267, 268, 269};

    /*!
     * \variable TYROGUE_EVOLUTIONS
     * \brief The evolutions of Tyrogue that have special branch evolutions
     */
    const vector<unsigned int> TYROGUE_EVOLUTIONS{236, 106, 107, 237};

    /*!
     * \variable EEVEELUTIONS
     * \brief The evolutions of Eevee that have special branch evolutions
     */
    const vector<unsigned int> EEVEELUTIONS{133, 134, 135, 136, 196, 197, 470,
                                            471, 700};

    /*!
     * \variable EVO_COL
     * \brief The size of the evolution column
     */
    const int EVO_COL = 70;

    /*!
     * \variable BRANCH_EVO_COL
     * \brief The size of the branch evolution column
     */
    const int BRANCH_EVO_COL = 50;
}

/*!
 * \class PokemonEvolutions
 * \brief This class represents an object that contains the Pokemon's evolutions
 */
class PokemonEvolutions{
    public:
        /*!
         * \fn PokemonEvolutions()
         * \brief This is the default PokemonEvolutions constructor
         */
        PokemonEvolutions();

        /*!
         * \fn PokemonEvolutions(const vector<Pokemon>& POKEDEX,
         *                       const Pokemon        & CURRENT_POKEMON)
         * \brief This is the non-default PokemonEvolutions constructor
         * \param POKEDEX - The list of Pokemon without moves and weaknesses
         * \param CURRENT_POKEMON - the current Pokemon being observed
         */
        PokemonEvolutions(const vector<Pokemon>& POKEDEX,
                          const Pokemon        & CURRENT_POKEMON);

        /*!
         * \fn ~PokemonEvolutions()
         * \brief This is the PokemonEvolutions deconstructor
         */
        virtual ~PokemonEvolutions();

        /*!
         * \fn SetInitialValues(const vector<Pokemon>& POKEDEX,
         *                      const Pokemon        & CURRENT_POKEMON)
         * \brief This methods sets the intial values for the Pokemon evolutions
         * \param POKEDEX - The list of Pokemon without moves and weaknesses
         * \param CURRENT_POKEMON - the current Pokemon being observed
         */
        void SetInitialValues(const vector<Pokemon>& POKEDEX,
                              const Pokemon        & CURRENT_POKEMON);

        /*!
         * \fn PrintEvoTree() const
         * \brief This method prints out the evolution tree of the Pokemon
         */
        string PrintEvoTree() const;

        /*!
         * \fn PrintTwoEvos() const
         * \brief This method prints out the Pokemon and one other evolution
         */
        string PrintTwoEvos() const;

        /*!
         * \fn PrintThreeEvos() const
         * \brief This method prints out the Pokemon and two other evolution
         */
        string PrintThreeEvos() const;

        /*!
         * \fn PrintBranchEvos() const
         * \brief This method prints out the Pokemon and its branch evolution
         */
        string PrintBranchEvos() const;

        /*!
         * \fn PrintSpecialEvosBranch() const
         * \brief This method prints out the Pokemon and its 3+ branch evolution
         */
        string PrintSpecialEvosBranch() const;

    private:
        /*!
         * \variable pokedexCopy
         * \brief This is a copy of the Pokedex without moves and weaknesses
         */
        vector<Pokemon> pokedexCopy;

        /*!
         * \variable mainPokemon
         * \brief This is the main Pokemon being observed
         */
        Pokemon mainPokemon;

        /*!
         * \variable firstEvo
         * \brief This is the first evolution of the main Pokemon
         */
        Pokemon firstEvo;

        /*!
         * \variable secondEvo
         * \brief This is the second evolution of the main Pokemon
         */
        Pokemon secondEvo;

        /*!
         * \variable finalEvo
         * \brief This is the third and final evolution of the main Pokemon
         */
        Pokemon finalEvo;

        /*!
         * \variable finalEvo
         * \brief This is the branch evolution of the main Pokemon
         */
        Pokemon branchEvo;
};

#endif /* POKEMONEVOLUTIONS_H_ */
