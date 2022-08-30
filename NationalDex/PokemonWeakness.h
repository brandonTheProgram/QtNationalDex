#ifndef POKEMONWEAKNESS_H_
#define POKEMONWEAKNESS_H_

#include <iomanip> /** setw          **/
#include <sstream> /** ostringstream **/
#include <string>  /** string        **/
using std::string;

/*!
 * \namespace globalWeakConsts
 * \brief global constants to be used for a Pokemon Weakness
 */
namespace globalWeakConsts
{
    /*!
     * \variable MAX_TYPES
     * \brief The maximum amount of Pokemon types available
     */
    const unsigned int MAX_TYPES = 18;

    /*!
     * \variable TYPE_COL
     * \brief The size of the column to display a type
     */
    const unsigned int TYPE_COL = 10;

    /*!
     * \variable TYPES[MAX_TYPES]
     * \brief An array that holds the name of every Pokemon type
     */
    const string TYPES[MAX_TYPES] = {
        "NORMAL", "FIGHTING", "FLYING", "POISON", "GROUND", "ROCK",
        "BUG", "GHOST", "STEEL", "FIRE", "WATER", "GRASS",
        "ELETRIC", "PSYCHIC", "ICE", "DRAGON", "DARK", "FAIRY"
    };
}

/*!
 * \enum options
 *
 * This enum type that represent the available Pokemon types
 *
 * \value NORMAL
 *        the enum that represents a Normal Pokemon Type
 *
 * \value FIGHTING
 *        the enum that represents a Fighting Pokemon Type
 *
 * \value FLYING
 *        the enum that represents a Flying Pokemon Type
 *
 * \value POISON
 *        the enum that represents a Poison Pokemon Type
 *
 * \value GROUND
 *        the enum that represents a Ground Pokemon Type
 *
 * \value ROCK
 *        the enum that represents a Rock Pokemon Type
 *
 * \value BUG
 *        the enum that represents a Bug Pokemon Type
 *
 * \value GHOST
 *        the enum that represents a Ghost Pokemon Type
 *
 * \value STEEL
 *        the enum that represents a Steel Pokemon Type
 *
 * \value FIRE
 *        the enum that represents a Fire Pokemon Type
 *
 * \value WATER
 *        the enum that represents a Water Pokemon Type
 *
 * \value GRASS
 *        the enum that represents a Grass Pokemon Type
 *
 * \value ELECTRIC
 *        the enum that represents a Electric Pokemon Type
 *
 * \value PSYCHIC
 *        the enum that represents a Psychic Pokemon Type
 *
 * \value ICE
 *        the enum that represents a Ice Pokemon Type
 *
 * \value DRAGON
 *        the enum that represents a Dragon Pokemon Type
 *
 * \value DARK
 *        the enum that represents a Dark Pokemon Type
 *
 * \value FAIRY
 *        the enum that represents a Fairy Pokemon Type
 */
enum PokemonTypes{
    NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK,
    BUG, GHOST, STEEL, FIRE, WATER, GRASS,
    ELECTRIC, PSYCHIC, ICE, DRAGON, DARK, FAIRY
};

/*!
 * \class PokemonWeakness
 * \brief This class represents the weakness of a Pokemon based on their type
 *        and the type of the attack that would hit the Pokemon.
 */
class PokemonWeakness{
    public:
        /*!
         * \fn operator[]
         * \brief This returns the assigned damage based on the typing
         */
        float operator[] (const unsigned int &INDEX){return damageAr[INDEX];}

        /*!
         * \fn PokemonWeakness()
         * \brief This is the default constructor for the PokemonWeakness
         */
        PokemonWeakness();

        /*!
         * \fn PokemonWeakness(const string &PRI_TYPE, const string &SEC_TYPE)
         * \brief This is the non-default constructor for the PokemonWeakness
         * \param PRI_TYPE - the primary typing of the Pokemon
         * \param SEC_TYPE - the secondary typing of the Pokemon
         */
        PokemonWeakness(const string &PRI_TYPE, const string &SEC_TYPE);

        /*!
         * \fn ~PokemonWeakness()
         * \brief This is the deconstructor for the PokemonWeakness
         */
        virtual ~PokemonWeakness();

        /*!
         * \fn InitializePriTypeEnum(const string &PRI_TYPE)
         * \brief This method initilizes the Primary type enum
         * \param PRI_TYPE - the primary typing of the Pokemon
         */
        void InitializePriTypeEnum(const string &PRI_TYPE);

        /*!
         * \fn InitializeSecTypeEnum(const string &SEC_TYPE)
         * \brief This method initilizes the secondary type enum
         * \param SEC_TYPE - the secondary typing of the Pokemon
         */
        void InitializeSecTypeEnum(const string &SEC_TYPE);

        /*!
         * \fn SetDamageValues(const float &NORMAL_DMG,
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
                               const float &FAIRY_DMG
         * \brief This method sets the damage valules into the array
         * \param NORMAL_DMG - the damage taken from a Normal type move
         * \param FIGHT_DMG - the damage taken from a Fighting type move
         * \param FLY_DMG - the damage taken from a Flying type move
         * \param POI_DMG - the damage taken from a Poison type move
         * \param GRD_DMG - the damage taken from a Ground type move
         * \param ROCK_DMG - the damage taken from a Rock type move
         * \param BUG_DMG - the damage taken from a Bug type move
         * \param GHOST_DMG - the damage taken from a Ghost type move
         * \param STEEL_DMG - the damage taken from a Steel type move
         * \param FIRE_DMG - the damage taken from a Fire type move
         * \param WATER_DMG - the damage taken from a Water type move
         * \param GRASS_DMG - the damage taken from a Grass type move
         * \param ELEC_DMG - the damage taken from a Electric type move
         * \param PSY_DMG - the damage taken from a Psychic type move
         * \param ICE_DMG - the damage taken from a Ice type move
         * \param DRGN_DMG - the damage taken from a Dragon type move
         * \param DARK_DMG - the damage taken from a Dark type move
         * \param FAIRY_DMG - the damage taken from a Fairy type move
         */
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

        /*!
         * \fn BugTypeDmg
         * \brief This calculates damage based on being a Bug Type
         */
        void BugTypeDmg();

        /*!
         * \fn DarkTypeDmg
         * \brief This calculates damage based on being a Dark Type
         */
        void DarkTypeDmg();

        /*!
         * \fn DragonTypeDmg
         * \brief This calculates damage based on being a Dragon Type
         */
        void DragonTypeDmg();

        /*!
         * \fn ElectricTypeDmg
         * \brief This calculates damage based on being a Electric Type
         */
        void ElectricTypeDmg();

        /*!
         * \fn FairyTypeDmg
         * \brief This calculates damage based on being a Fairy Type
         */
        void FairyTypeDmg();

        /*!
         * \fn FightingTypeDmg
         * \brief This calculates damage based on being a Fighting Type
         */
        void FightingTypeDmg();

        /*!
         * \fn FireTypeDmg
         * \brief This calculates damage based on being a Fire Type
         */
        void FireTypeDmg();

        /*!
         * \fn FlyingTypeDmg
         * \brief This calculates damage based on being a Flying Type
         */
        void FlyingTypeDmg();

        /*!
         * \fn GhostTypeDmg
         * \brief This calculates damage based on being a Ghost Type
         */
        void GhostTypeDmg();

        /*!
         * \fn GrassTypeDmg
         * \brief This calculates damage based on being a Grass Type
         */
        void GrassTypeDmg();

        /*!
         * \fn GroundTypeDmg
         * \brief This calculates damage based on being a Ground Type
         */
        void GroundTypeDmg();

        /*!
         * \fn IceTypeDmg
         * \brief This calculates damage based on being a Ice Type
         */
        void IceTypeDmg();

        /*!
         * \fn NormalTypeDmg
         * \brief This calculates damage based on being a Normal Type
         */
        void NormalTypeDmg();

        /*!
         * \fn PoisonTypeDmg
         * \brief This calculates damage based on being a Poison Type
         */
        void PoisonTypeDmg();

        /*!
         * \fn PsychicTypeDmg
         * \brief This calculates damage based on being a Psychic Type
         */
        void PsychicTypeDmg();

        /*!
         * \fn RockTypeDmg
         * \brief This calculates damage based on being a Rock Type
         */
        void RockTypeDmg();

        /*!
         * \fn SteelTypeDmg
         * \brief This calculates damage based on being a Steel Type
         */
        void SteelTypeDmg();

        /*!
         * \fn WaterTypeDmg
         * \brief This calculates damage based on being a Water Type
         */
        void WaterTypeDmg();

        /*!
         * \fn CalcDamageTaken
         * \brief This method calculates how much damage should be taken based
         *        on the Pokemon's primary and secondary typing
         */
        void CalcDamageTaken();

        /*!
         * \fn GetPriTypeEnum() const
         * \brief This method returns the enum of the Pokemon's primary typing
         */
        PokemonTypes GetPriTypeEnum() const{return this->priTypeEnum;}

        /*!
         * \fn GetSecTypeEnum() const
         * \brief This method returns the enum of the Pokemon's secondary typing
         */
        PokemonTypes GetSecTypeEnum() const{return this->secTypeEnum;}

        /*!
         * \fn PrintWeaknesses
         * \brief This method prints out the entire typing weakness
         *        of the Pokemon
         */
        string PrintWeaknesses() const;

    private:
        /*!
         * \variable priTypeEnum
         * \brief The primary type of the Pokemon as an enum
         */
        PokemonTypes priTypeEnum;

        /*!
         * \variable secTypeEnum
         * \brief The secondary type of the Pokemon as an enum
         */
        PokemonTypes secTypeEnum;

        /*!
         * \variable damageAr[globalWeakConsts::MAX_TYPES]
         * \brief The array of damages for a Pokemon
         */
        float damageAr[globalWeakConsts::MAX_TYPES];
};

#endif /* POKEMONWEAKNESS_H_ */
