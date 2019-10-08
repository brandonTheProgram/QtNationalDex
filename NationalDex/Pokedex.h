#ifndef POKEDEX_H_
#define POKEDEX_H_

#include "Pokemon.h"           /** Pokemon                    **/
#include "PokemonEvolutions.h" /** PokemonEvolution           **/
#include "PokemonWeakness.h"   /** PokemonWeakness            **/
#include "Moveset.h"           /** Moveset                    **/

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
namespace globalPDexConsts{
    const int AR_SIZE          = 807;
    const int MAX_ATTKS        = 724;
    const int KANTO_DEX        = 151;
    const int JOHTO_DEX        = 251;
    const int HOENN_DEX        = 386;
    const int SINNOH_DEX       = 493;
    const int UNOVA_DEX        = 649;
    const int KALOS_DEX        = 721;
    const int ALOLA_DEX        = 807;
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
* 	This class represents a Pokedex object
*************************************************************************/
class Pokedex{
    public:
        Pkmn& operator[] (const int& INDEX){return pokedex[INDEX];}

        Pokedex(); //Default Constructor

        virtual ~Pokedex(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        void CreateAttackList(const string& INPUT_FILE);

        //Creates a copy of the Pokedex with only a Pokemon and not attacks
        void CreatePokedexCopy();

        void LoadRegion(const string& INPUT_FILE, const int& REGION_MAX,
                        const string& ATTACK_FILE);

        void LoadPokemonMoves(std::ifstream& fin, vector<string>& attackNames,
                              vector<int>& attackLvls);

        void SetEvolutions();

        /*******************
         **** ACCESSORS ****
         *******************/
        vector<Pkmn> GetRegion(const int& START, const int& END) const;

    private:
        vector<Pkmn>      pokedex;			//The Pokedex
        vector<Attack>    attackDex;		//The AttackDex
        vector<Pokemon>   pokedexCopy;		//The Copy of the Pokedex
        Pkmn              currentPokemon;	//The current Pokemon
};

#endif /* POKEDEX_H_ */
