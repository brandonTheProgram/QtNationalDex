#ifndef POKEMONWEAKNESS_H_
#define POKEMONWEAKNESS_H_

#include <iomanip> /** setw          **/
#include <sstream> /** ostringstream **/
#include <string>  /** string        **/
using std::string;

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR COLUMN SIZE
 * ------------------------------------------------------------------------
 * TYPE_COL  : The size of the column to display a type
 * ------------------------------------------------------------------------
 * USED FOR MAX/MIN VALUES
 * ------------------------------------------------------------------------
 * MAX_TYPES : The maximum amount of Pokemon types available
 * ------------------------------------------------------------------------
 * USED FOR SPECIFIC VALUES
 * ------------------------------------------------------------------------
 * TYPES[MAX_TYPES] : A string array holding the name of every pokemon type
 *************************************************************************/
namespace globalWeakConsts
{
    const int MAX_TYPES = 18;
    const int TYPE_COL  = 10;

    const string TYPES[MAX_TYPES] = {
        "NORMAL",
        "FIGHTING",
        "FLYING",
        "POISON",
        "GROUND",
        "ROCK",
        "BUG",
        "GHOST",
        "STEEL",
        "FIRE",
        "WATER",
        "GRASS",
        "ELETRIC",
        "PSYCHIC",
        "ICE",
        "DRAGON",
        "DARK",
        "FAIRY"
    };
}

//The enumerated type that represent the available Pokemon types
enum PokemonTypes{
    NORMAL,
    FIGHTING,
    FLYING,
    POISON,
    GROUND,
    ROCK,
    BUG,
    GHOST,
    STEEL,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    PSYCHIC,
    ICE,
    DRAGON,
    DARK,
    FAIRY
};

/************************************************************************
* PokemonWeakness Class
* 	This class represents the weakness of a Pokemon based on their type and the
* 		type of the attack that would hit the Pokemon.
*************************************************************************/
class PokemonWeakness{
    public:
        //Overloading the array operator
        float& operator[] (const int &INDEX){return damageAr[INDEX];}

        PokemonWeakness(); //Default Constructor

        //Non-default constructor
        PokemonWeakness(const string &PRI_TYPE,
                        const string &SEC_TYPE);

        virtual ~PokemonWeakness(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        void InitializePriTypeEnum(const string &PRI_TYPE);

        void InitializeSecTypeEnum(const string &SEC_TYPE);

        void SetDamageValues(const float &NORMAL_DMG,
                             const float &FIGHT_DMG,
                             const float &FLY_DMG,
                             const float &POI_DMG,
                             const float &GRD_DMG,
                             const float &ROCK_DMG,
                             const float &BUG_DMG,
                             const float &GHOST_DMG,
                             const float &STEEL_DMG,
                             const float &FIRE_DMG,
                             const float &WATER_DMG,
                             const float &GRASS_DMG,
                             const float &ELEC_DMG,
                             const float &PSY_DMG,
                             const float &ICE_DMG,
                             const float &DRGN_DMG,
                             const float &DARK_DMG,
                             const float &FAIRY_DMG);

        void BugTypeDmg();

        void DarkTypeDmg();

        void DragonTypeDmg();

        void ElectricTypeDmg();

        void FairyTypeDmg();

        void FightingTypeDmg();

        void FireTypeDmg();

        void FlyingTypeDmg();

        void GhostTypeDmg();

        void GrassTypeDmg();

        void GroundTypeDmg();

        void IceTypeDmg();

        void NormalTypeDmg();

        void PoisonTypeDmg();

        void PsychicTypeDmg();

        void RockTypeDmg();

        void SteelTypeDmg();

        void WaterTypeDmg();

        void CalcDamageTaken();

        /*******************
         **** ACCESSORS ****
         *******************/

        PokemonTypes GetPriTypeEnum() const{return this->priTypeEnum;}

        PokemonTypes GetSecTypeEnum() const{return this->secTypeEnum;}

        //Return the weakness as a string
        string PrintWeaknesses() const;

    private:
        PokemonTypes priTypeEnum;					//The primary type of the
                                                    //Pokemon as an enum
        PokemonTypes secTypeEnum;					//The secondary type of the
                                                    //Pokemon as an enum
        float damageAr[globalWeakConsts::MAX_TYPES];//The array of damages for
                                                    //the Pokemon
};

#endif /* POKEMONWEAKNESS_H_ */
