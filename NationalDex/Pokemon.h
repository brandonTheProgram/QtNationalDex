#ifndef POKEMON_H_
#define POKEMON_H_

#include <sstream> 			 /** ostringstream                 **/
#include <fstream> 			 /** fstream 					   **/
#include <iomanip>           /** setw                          **/
#include <string>            /** string                        **/
using std::string;
using std::endl;

/*!
 * \namespace globalPkmnConsts
 * \brief global constants to be used for a Pokemon
 */
namespace globalPkmnConsts{
    /*!
     * \variable DESC_COL
     * \brief The size of the column to display the description
     */
    const unsigned int DESC_COL    = 75;

    /*!
     * \variable ABILITY_COL
     * \brief The size of the column to display the ability
     */
    const unsigned int ABILITY_COL = 60;
}

/*!
 * \brief The struct that holds the basic information that a Pokemon would have
 */
struct basicInfo{
    /*!
     * \variable pokedexNumber
     * \brief The pokedex number of the Pokemon
     */
    unsigned int pokedexNumber;

    /*!
     * \variable name
     * \brief The name of the Pokemon
     */
    string name;

    /*!
     * \variable species
     * \brief The species of the Pokemon
     */
    string species;

    /*!
     * \variable priType
     * \brief The primary type of the Pokemon
     */
    string priType;

    /*!
     * \variable secType
     * \brief The secondary type of the Pokemon
     */
    string secType;

    /*!
     * \variable description
     * \brief The description of the Pokemon
     */
    string description;

    /*!
     * \variable abilites
     * \brief The amount of abilities the Pokemon has
     */
    unsigned int abilites;

    /*!
     * \variable ability
     * \brief The name of the first ability
     */
    string ability;

    /*!
     * \variable abilityDesc
     * \brief The description of the first ability
     */
    string abilityDesc;

    /*!
     * \variable altAbility
     * \brief The name of the alternative ability
     */
    string altAbility;

    /*!
     * \variable altAbilityDesc
     * \brief The description of the alternative ability
     */
    string altAbilityDesc;

    /*!
     * \variable hiddenAbility
     * \brief The name of the hidden ability
     */
    string hiddenAbility;

    /*!
     * \variable hiddenAbilityDesc
     * \brief The description of the hidden ability
     */
    string hiddenAbilityDesc;

    /*!
     * \variable versionOneLocation
     * \brief Version one game location
     */
    string versionOneLocation;

    /*!
     * \variable versionTwoLocation
     * \brief Version two game location
     */
    string versionTwoLocation;
};

/*!
 * \brief The struct that holds the information pertaining to the Pokemon's evolutions
 */
struct evolutionInfo{
    /*!
     * \variable evolutions
     * \brief The amount of evolutions that can be achieved
     */
    unsigned int evolutions;

    /*!
     * \variable secondEvo
     * \brief If the Pokemon is the second evolution
     */
    bool secondEvo;

    /*!
     * \variable finalEvo
     * \brief If the Pokemon is the final evolution
     */
    bool finalEvo;

    /*!
     * \variable branchEvo
     * \brief If the Pokemon is the branch evolution
     */
    bool branchEvo;

    /*!
     * \variable evoThroughLvl
     * \brief If the Pokemon evolves through leveling up
     */
    bool evoThroughLvl;

    /*!
     * \variable evoThroughCond
     * \brief If the Pokemon evolves through special conditions
     */
    bool evoThroughCond;

    /*!
     * \variable evoLvl
     * \brief The level that the Pokemon evolves at
     */
    unsigned int evoLvl;

    /*!
     * \variable finalEvoLvl
     * \brief The final evolution level to evolve
     */
    unsigned int finalEvoLvl;

    /*!
     * \variable firstEvoNum
     * \brief The pokedex number of the first evolution
     */
    unsigned int firstEvoNum;

    /*!
     * \variable secondEvoNum
     * \brief The pokedex number of the second evolution
     */
    unsigned int secondEvoNum;

    /*!
     * \variable finalEvoNum
     * \brief The pokedex number of the final evolution
     */
    unsigned int finalEvoNum;

    /*!
     * \variable branchEvoNum
     * \brief The pokedex number of the branch evolution
     */
    unsigned int branchEvoNum;

    /*!
     * \variable secondEvoCond
     * \brief The second evolution condition
     */
    string secondEvoCond;

    /*!
     * \variable finalEvoCond
     * \brief The final evolution condition
     */
    string finalEvoCond;
};

/*!
 * \class Pokemon
 * \brief This class represents a Pokemon object with basic and evolutionary info
 */
class Pokemon{
    public:
       /*!
        * \fn ifstream& operator >>(std::ifstream&, Pokemon&)
        * \brief File extraction of Pokemon data
        * \param isObject - the input object
        * \param cObject - the class object
        */
        friend std::ifstream& operator >>(std::ifstream& isObject,
                                                Pokemon& cObject);

        /*!
         * \fn Pokemon()
         * \brief This is the default constructor for the Pokemon
         */
        Pokemon();

        /*!
         * \fn Pokemon(const basicInfo& BI, const evolutionInfo& EI)
         * \brief This is the non-default the constructor for the Pokemon
         * \param BI - a struct of the basic information of the Pokemon
         * \param EI - a struct of the evolutionary information of the Pokemon
         */
        Pokemon(const basicInfo& BI, const evolutionInfo& EI);

        /*!
         * \fn ~Pokemon()
         * \brief This is deconstructor for the Pokemon
         */
        virtual ~Pokemon();

        /*!
         * \fn GetPokedexNumber() const
         * \brief This returns the Pokemon's pokedex number
         */
        unsigned int GetPokedexNumber() const{return basic.pokedexNumber;}

        /*!
         * \fn GetName() const
         * \brief This returns the Pokemon's name
         */
        string GetName()const{return basic.name;}

        /*!
         * \fn GetSpecies() const
         * \brief This returns the Pokemon's species
         */
        string GetSpecies()const{return basic.species;}

        /*!
         * \fn GetPriType() const
         * \brief This returns the Pokemon's primary typing
         */
        string GetPriType()const{return basic.priType;}

        /*!
         * \fn GetSecType() const
         * \brief This returns the Pokemon's secondary typing
         */
        string GetSecType()const{return basic.secType;}

        /*!
         * \fn GetDescription() const
         * \brief This returns a description of the Pokemon
         */
        string GetDescription()const{return basic.description;}

        /*!
         * \fn GetAbilites() const
         * \brief This returns the number of abilities the Pokemon has
         */
        unsigned int GetAbilites()const{return basic.abilites;}

        /*!
         * \fn GetAbility() const
         * \brief This returns the name of first ability of the Pokemon
         */
        string GetAbility()const{return basic.ability;}

        /*!
         * \fn GetAbilityDesc() const
         * \brief This returns the description of first ability of the Pokemon
         */
        string GetAbilityDesc()const{return basic.abilityDesc;}

        /*!
         * \fn GetAltAbility() const
         * \brief This returns the name of alternative ability of the Pokemon
         */
        string GetAltAbility()const{return basic.altAbility;}

        /*!
         * \fn GetAltAbilityDesc() const
         * \brief This returns the description of alt ability of the Pokemon
         */
        string GetAltAbilityDesc()const{return basic.altAbilityDesc;}

        /*!
         * \fn GetHiddenAbility() const
         * \brief This returns the name of hidden ability of the Pokemon
         */
        string GetHiddenAbility()const{return basic.hiddenAbility;}

        /*!
         * \fn GetHiddenAbilityDesc() const
         * \brief This returns the description of hidden ability of the Pokemon
         */
        string GetHiddenAbilityDesc()const{return basic.hiddenAbilityDesc;}

        /*!
         * \fn GetVersionOneLocation() const
         * \brief This returns the name of version one of the current game
         */
        string GetVersionOneLocation() const{return basic.versionOneLocation;}

        /*!
         * \fn GetVersionTwoLocation() const
         * \brief This returns the name of version two of the current game
         */
        string GetVersionTwoLocation() const{return basic.versionTwoLocation;}

        /*!
         * \fn GetEvolutions() const
         * \brief This returns amount of evolutions available
         */
        unsigned int GetEvolutions()const {return evol.evolutions;}

        /*!
         * \fn GetSecondEvo() const
         * \brief This returns T/F if the Pokemon is the second evolution
         */
        bool GetSecondEvo()const {return evol.secondEvo;}

        /*!
         * \fn GetFinalEvo() const
         * \brief This returns T/F if the Pokemon is the final evolution
         */
        bool GetFinalEvo()const {return evol.finalEvo;}

        /*!
         * \fn GetBranchEvo() const
         * \brief This returns T/F if the Pokemon is a branch evolution
         */
        bool GetBranchEvo()const {return evol.branchEvo;}

        /*!
         * \fn GetEvoThroughLvl() const
         * \brief This returns T/F if the Pokemon evolves through leveling up
         */
        bool GetEvoThroughLvl()const {return evol.evoThroughLvl;}

        /*!
         * \fn GetEvoThroughCond() const
         * \brief This returns T/F if the Pokemon evolves through conditions
         */
        bool GetEvoThroughCond()const {return evol.evoThroughCond;}

        /*!
         * \fn GetEvoLvl() const
         * \brief This returns what level the Pokemon evolves at
         */
        unsigned int GetEvoLvl()const {return evol.evoLvl;}

        /*!
         * \fn GetFinalEvoLvl() const
         * \brief This returns the Pokemon's final level of the last evolution
         */
        unsigned int GetFinalEvoLvl()const {return evol.finalEvoLvl;}

        /*!
         * \fn GetFirstEvoNum() const
         * \brief This returns the pokedex number of the first evolution
         */
        unsigned int GetFirstEvoNum()const {return evol.firstEvoNum;}

        /*!
         * \fn GetSecondEvoNum() const
         * \brief This returns the pokedex number of the second evolution
         */
        unsigned int GetSecondEvoNum()const {return evol.secondEvoNum;}

        /*!
         * \fn GetFinalEvoNum() const
         * \brief This returns the pokedex number of the final evolution
         */
        unsigned int GetFinalEvoNum()const {return evol.finalEvoNum;}

        /*!
         * \fn GetBranchEvoNum() const
         * \brief This returns the pokedex number of the branch evolution
         */
        unsigned int GetBranchEvoNum()const {return evol.branchEvoNum;}

        /*!
         * \fn GetSecondEvoCond() const
         * \brief This returns the condition to reach the second evolution
         */
        string GetSecondEvoCond()const {return evol.secondEvoCond;}

        /*!
         * \fn GetFinalEvoCond() const
         * \brief This returns the condition to reach the final evolution
         */
        string GetFinalEvoCond()const {return evol.finalEvoCond;}

        /*!
         * \fn PrintAbility() const
         * \brief This returns all information of the Pokemon's abilities
         */
        string PrintAbility() const;

    private:
        /*!
         * \variable basic
         * \brief The basic information of a Pokemon
         */
        basicInfo       basic;

        /*!
         * \variable evol
         * \brief The evolution information of a Pokemon
         */
        evolutionInfo   evol;
};

#endif /* POKEMON_H_ */
