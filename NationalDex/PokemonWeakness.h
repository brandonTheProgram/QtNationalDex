#ifndef POKEMONWEAKNESS_H_
#define POKEMONWEAKNESS_H_

#include <iomanip> /** setw          **/
#include <sstream> /** ostringstream **/
#include <string>  /** string        **/
using std::string;

//Namespace for the global constants used in the class
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

    const string TYPES[MAX_TYPES] =
    {
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
enum PokemonTypes
{
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
* 		type of the attack that would hit the Pokemon. It manages 3 attributes:
* 		priTypeEnum, secTypeEnum, damageAr[globalWeakConsts::MAX_TYPES]
*************************************************************************/
class PokemonWeakness //Base Class
{
    public:
        /******************************
         **      OVERLOADERS         **
         ******************************/
        //Overloading the array operator
        float& operator[] (const int &INDEX){return damageAr[INDEX];}

        /******************************
         ** CONSTRUCTOR & DESTRUCTOR **
         ******************************/

        /****************************************************************
         * PokemonWeakness ();
         *   Constructor; this method initializes the pokemon weakness object
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        PokemonWeakness(); //Default Constructor

        /****************************************************************
         * PokemonWeakness ();
         *   Constructor; this method initializes the pokemon weakness object
         *   			  with values
         *   Parameters: PRI_TYPE (string) - the name of the Pokemon's
         *   								 primary type
         *   			 SEC_TYPE (string) - the name of the Pokemon's
         *   								 secondary type
         *   Return: none
         ***************************************************************/
        PokemonWeakness(const string &PRI_TYPE,
                        const string &SEC_TYPE); //Non-default constructor

        /****************************************************************
         * ~PokemonWeakness ();
         *   Deconstructor; does not perform any specific function
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        virtual ~PokemonWeakness(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        /****************************************************************
         * 	void InitializePriTypeEnum(const string &PRI_TYPE);
         *
         *   Mutator; this method initializes the priTypeEnum
         *   Parameters: PRI_TYPE (string) - the name of the Pokemon's
         *   						         primary type
         *   Return: none
         ***************************************************************/
        void InitializePriTypeEnum(const string &PRI_TYPE);

        /****************************************************************
         * 	void InitializeSecTypeEnum(const string &SEC_TYPE);
         *
         *   Mutator; this method initializes the secTypeEnum
         *   Parameters: SEC_TYPE (string) - the name of the Pokemon's
         *   						        secondary type
         *   Return: none
         ***************************************************************/
        void InitializeSecTypeEnum(const string &SEC_TYPE);

        /****************************************************************
         * 	void SetDamageValues(const float &NORMAL_DMG,
         *					 	 const float &FIGHT_DMG,
         *					 	 const float &FLY_DMG,
         *					 	 const float &POI_DMG,
         *					 	 const float &GRD_DMG,
         *					  	 const float &ROCK_DMG,
         *					  	 const float &BUG_DMG,
         *					  	 const float &GHOST_DMG,
         *					  	 const float &STEEL_DMG,
         *					  	 const float &FIRE_DMG,
         *					 	 const float &WATER_DMG,
         *					  	 const float &GRASS_DMG,
         *					  	 const float &ELEC_DMG,
         *					  	 const float &PSY_DMG,
         *					  	 const float &ICE_DMG,
         *					  	 const float &DRGN_DMG,
         *					  	 const float &DARK_DMG,
         *					  	 const float &FAIRY_DMG);
         *
         *   Mutator; this method initializes the damage array with the
         *   		  corresponding type values
         *
         *   Parameters: NORMAL_DMG  (float) - the damage taken from a normal
         *   								   type move
         *   			 FIGHT_DMG   (float) - the damage taken from a fighting
         *   								   type move
         *   			 FLY_DMG     (float) - the damage taken from a flying
         *   								   type move
         *   			 POI_DMG     (float) - the damage taken from a poison
         *   								   type move
         *   			 GRD_DMG     (float) - the damage taken from a ground
         *   								   type move
         *   			 ROCK_DMG    (float) - the damage taken from a rock
         *   								   type move
         *   			 BUG_DMG     (float) - the damage taken from a bug
         *   								   type move
         *   		     GHOST_DMG   (float) - the damage taken from a ghost
         *   								   type move
         *   			 STEEL_DMG   (float) - the damage taken from a steel
         *   								   type move
         *   			 FIRE_DMG    (float) - the damage taken from a fire
         *   								   type move
         *   			 WATER_DMG   (float) - the damage taken from a water
         *   								   type move
         *   			 GRASS_DMG	 (float) - the damage taken from a grass
         *   								   type move
         *   			 ELEC_DMG    (float) - the damage taken from a electric
         *   								   type move
         *   			 PSY_DMG     (float) - the damage taken from a psychic
         *   								   type move
         *   			 ICE_DMG     (float) - the damage taken from a ice
         *   								   type move
         *   			 DRGN_DMG    (float) - the damage taken from a dragon
         *   								   type move
         *   			 DARK_DMG    (float) - the damage taken from a dark
         *   								   type move
         *   			 FAIRY_DMG   (float) - the damage taken from a fairy
         *   								   type move
         *   Return: none
         ***************************************************************/
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

        /****************************************************************
         * 	void BugTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  bug type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void BugTypeDmg();

        /****************************************************************
         * 	void DarkTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  dark type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void DarkTypeDmg();

        /****************************************************************
         * 	void DragonTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  dragon type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void DragonTypeDmg();

        /****************************************************************
         * 	void ElectricTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is an
         *   		  electric type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void ElectricTypeDmg();

        /****************************************************************
         * 	void FairyTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  fairy type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void FairyTypeDmg();

        /****************************************************************
         * 	void FightingTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  fighting type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void FightingTypeDmg();

        /****************************************************************
         * 	void FireTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  fire type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void FireTypeDmg();

        /****************************************************************
         * 	void FlyingTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  flying type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void FlyingTypeDmg();

        /****************************************************************
         * 	void GhostTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  ghost type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void GhostTypeDmg();

        /****************************************************************
         * 	void GrassTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  grass type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void GrassTypeDmg();

        /****************************************************************
         * 	void GroundTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  ground type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void GroundTypeDmg();

        /****************************************************************
         * 	void IceTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is an
         *   		  ice type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void IceTypeDmg();

        /****************************************************************
         * 	void NormalTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  normal type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void NormalTypeDmg();

        /****************************************************************
         * 	void PoisonTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  poison type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void PoisonTypeDmg();

        /****************************************************************
         * 	void PsychicTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  psychic type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void PsychicTypeDmg();

        /****************************************************************
         * 	void RockTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  rock type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void RockTypeDmg();

        /****************************************************************
         * 	void SteelTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  steel type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void SteelTypeDmg();

        /****************************************************************
         * 	void WaterTypeDmg();
         *
         *   Mutator; this method initializes the damage if the Pokemon is a
         *   		  water type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void WaterTypeDmg();

        /****************************************************************
         * 	void CalcDamageTaken();
         *
         *   Mutator; this method calculates the Pokemon's weakness based on
         *   		  their primary pokemon type
         *
         *   Parameters: none
         *
         *   Return: none
         ***************************************************************/
        void CalcDamageTaken();

        /*******************
         **** ACCESSORS ****
         *******************/

        /****************************************************************
         * PokemonTypes GetPriTypeEnum() const;
         *
         *   Accessor; This returns the enum of the Pokemon's primary type
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: priTypeEnum
         ***************************************************************/
        PokemonTypes GetPriTypeEnum() const{return priTypeEnum;}

        /****************************************************************
         * PokemonTypes GetSecTypeEnum() const;
         *
         *   Accessor; This returns the enum of the Pokemon's secondary type
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: secTypeEnum
         ***************************************************************/
        PokemonTypes GetSecTypeEnum() const{return secTypeEnum;}

        /****************************************************************
         * string PrintWeaknesses() const;
         *
         *   Accessor; This prints the weakness format then returns it
         *-----------------------------------------------------------------
         *   Parameters: none
         *-----------------------------------------------------------------
         *   Return: returns the weakness format
         ***************************************************************/
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
