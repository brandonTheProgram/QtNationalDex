#ifndef POKEDEX_H_
#define POKEDEX_H_

#include "PokemonEvolutions.h" /** PokemonEvolution           **/
#include "PokemonWeakness.h"   /** PokemonWeakness            **/
#include "Moveset.h"           /** Moveset                    **/

/*!
 * \namespace globalPkmnConsts
 * \brief global constants to be used for a Pokedex
 */
namespace globalPDexConsts{
    /*!
     * \variable AR_SIZE
     * \brief The size of the array/vector which is the max amount of Pokemon
     */
    const unsigned short AR_SIZE = 898;

    /*!
     * \variable MAX_ATTKS
     * \brief The size of the array/vector which is the max amount of attacks
     */
    const unsigned short MAX_ATTKS = 768;
}

/*!
 * \brief A Pokemon object with all its corresponding information
 */
struct Pkmn{
    /*!
     * \variable currentPkmn
     * \brief The current Pokemon with its basic information
     */
    Pokemon currentPkmn;

    /*!
     * \variable pkmnEvos
     * \brief The current Pokemon's evolution information
     */
    PokemonEvolutions pkmnEvos;

    /*!
     * \variable pkmnMoves
     * \brief The current Pokemon's moveset information
     */
    Moveset pkmnMoves;

    /*!
     * \variable pkmnWeakness
     * \brief The current Pokemon's type weakness information
     */
    PokemonWeakness pkmnWeakness;
};

/*!
 * \class Pokedex
 * \brief This class represents a Pokemon Encyclopedia (Pokedex) object
 */
class Pokedex{
    public:
        /*!
         * \fn operator[]
         * \brief This returns the Pokemon at the specified index
         */
        Pkmn& operator[] (const unsigned int& INDEX){return pokedex[INDEX];}

        /*!
         * \fn Pokedex()
         * \brief This is the default Pokedex constructor
         */
        Pokedex();

        /*!
         * \fn ~Pokedex()
         * \brief This is the Pokedex deconstructor
         */
        virtual ~Pokedex();

        /*!
         * \fn CreateAttackList(const string& INPUT_FILE)
         * \brief This method creates an encyclopedia of Pokemon attack moves
         * \param INPUT_FILE - the name of the input file
         */
        void CreateAttackList(const string& INPUT_FILE);

        /*!
         * \fn CreatePokedexCopy()
         * \brief This method creates a clone of the Pokedex with basic Pokemon
         *        information(without moves, evolutions, and weakness)
         */
        void CreatePokedexCopy();

        /*!
         * \fn LoadRegion(const string& INPUT_FILE,
                          const int unsigned& REGION_MAX,
                          const string& ATTACK_FILE)
         * \brief This method loads in a region of Pokemon and stores all them
         * \param INPUT_FILE - the name of the input file
         * \param REGION_MAX - the max index of the current region
         * \param ATTACK_FILE - the name of the input file for attacks
         */
        void LoadRegion(const string& INPUT_FILE,
                        const int unsigned& REGION_MAX,
                        const string& ATTACK_FILE);

        /*!
         * \fn LoadPokemonMoves(std::ifstream& fin, vector<string>& attackNames,
                              vector<unsigned int>& attackLvls)
         * \brief This method loads in the current moves the Pokemon can learn
         * \param fin - the variable for the input file for pokemon attacks
         * \param attackNames - the container for the name of the attacks
         * \param attackLvls - the container for the levels of the attacks
         */
        void LoadPokemonMoves(std::ifstream& fin, vector<string>& attackNames,
                              vector<unsigned int>& attackLvls);

        /*!
         * \fn SetEvolutions()
         * \brief This method assigns the evolutions that the
         *        Pokemon can achieve
         */
        void SetEvolutions();

        /*!
         * \fn GetRegion(const unsigned int& START,
                         const unsigned int& END) const
         * \brief This method returns a specified region based on the indices
         * \param START - starting index of the region
         * \param END - ending index of the region
         */
        vector<Pkmn> GetRegion(const unsigned int& START,
                               const unsigned int& END) const;

    private:
        /*!
         * \variable pokedex
         * \brief This is an Encyclopedia of every Pokemon available
         */
        vector<Pkmn> pokedex;

        /*!
         * \variable attackDex
         * \brief This is an Encyclopedia of every Pokemon attack available
         */
        vector<Attack> attackDex;

        /*!
         * \variable pokedexCopy
         * \brief This is a list of every basic Pokemon(no weakness,
         *        evolutions, or moves)
         */
        vector<Pokemon> pokedexCopy;

        /*!
         * \variable currentPokemon
         * \brief This is the current Pokemon the Encyclopedia is working with
         */
        Pkmn currentPokemon;
};

#endif /* POKEDEX_H_ */
