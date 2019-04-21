#include "PokemonWeakness.h"

/************************************************************************
* Method PokemonWeakness: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method creates the Pokemon Weakness object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
PokemonWeakness::PokemonWeakness()
{
    priTypeEnum = NORMAL;
    secTypeEnum = NORMAL;

    //PROCESSING - Initialize the array to 0
    for(int index = 0; index < globalWeakConsts::MAX_TYPES; index++)
        damageAr[index] = 0.0;
}

/************************************************************************
* Method PokemonWeakness: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method creates the Pokemon Weakness object with values
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		priType (string) - the name of the Pokemon's
*		   			       primary type
*		secType (string) - the name of the Pokemon's
*		    			   secondary type
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
PokemonWeakness::PokemonWeakness(const string &priType,
                                 const string &secType)
{
    InitializePriTypeEnum(priType);

    InitializeSecTypeEnum(secType);
}

/************************************************************************
* Method ~PokemonWeakness: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method deletes the Pokemon weakness object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
PokemonWeakness::~PokemonWeakness()
{

}

/************************************************************************
* Method InitializePriTypeEnum: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method will initialize the priTypeEnum using priType
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*  	 	priType (string) - the name of the Pokemon's primary type
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::InitializePriTypeEnum(const std::string &priType)
{
    //Based on the name of the Pokemon's type, initialize the corresponding enum
    if(priType == "Normal")
    {
        priTypeEnum = NORMAL;
    }
    else if(priType == "Fighting")
    {
        priTypeEnum = FIGHTING;
    }
    else if(priType == "Flying")
    {
        priTypeEnum = FLYING;
    }
    else if(priType == "Poison")
    {
        priTypeEnum = POISON;
    }
    else if(priType == "Ground")
    {
        priTypeEnum = GROUND;
    }
    else if(priType == "Rock")
    {
        priTypeEnum = ROCK;
    }
    else if(priType == "Bug")
    {
        priTypeEnum = BUG;
    }
    else if(priType == "Ghost")
    {
        priTypeEnum = GHOST;
    }
    else if(priType == "Steel")
    {
        priTypeEnum = STEEL;
    }
    else if(priType == "Fire")
    {
        priTypeEnum = FIRE;
    }
    else if(priType == "Water")
    {
        priTypeEnum = WATER;
    }
    else if(priType == "Grass")
    {
        priTypeEnum = GRASS;
    }
    else if(priType == "Electric")
    {
        priTypeEnum = ELECTRIC;
    }
    else if(priType == "Psychic")
    {
        priTypeEnum = PSYCHIC;
    }
    else if(priType == "Ice")
    {
        priTypeEnum = ICE;
    }
    else if(priType == "Dragon")
    {
        priTypeEnum = DRAGON;
    }
    else if(priType == "Dark")
    {
        priTypeEnum = DARK;
    }
    else if(priType == "Fairy")
    {
        priTypeEnum = FAIRY;
    }
}

/************************************************************************
* Method InitializeSecTypeEnum: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method will initialize the secTypeEnum using secType
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*  	 	secType (string) - the name of the Pokemon's secondary type
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::InitializeSecTypeEnum(const std::string &secType)
{
    //Based on the name of the Pokemon's type, initialize the corresponding enum
    if(secType == "Normal")
    {
        secTypeEnum = NORMAL;
    }
    else if(secType == "Fighting")
    {
        secTypeEnum = FIGHTING;
    }
    else if(secType == "Flying")
    {
        secTypeEnum = FLYING;
    }
    else if(secType == "Poison")
    {
        secTypeEnum = POISON;
    }
    else if(secType == "Ground")
    {
        secTypeEnum = GROUND;
    }
    else if(secType == "Rock")
    {
        secTypeEnum = ROCK;
    }
    else if(secType == "Bug")
    {
        secTypeEnum = BUG;
    }
    else if(secType == "Ghost")
    {
        secTypeEnum = GHOST;
    }
    else if(secType == "Steel")
    {
        secTypeEnum = STEEL;
    }
    else if(secType == "Fire")
    {
        secTypeEnum = FIRE;
    }
    else if(secType == "Water")
    {
        secTypeEnum = WATER;
    }
    else if(secType == "Grass")
    {
        secTypeEnum = GRASS;
    }
    else if(secType == "Electric")
    {
        secTypeEnum = ELECTRIC;
    }
    else if(secType == "Psychic")
    {
        secTypeEnum = PSYCHIC;
    }
    else if(secType == "Ice")
    {
        secTypeEnum = ICE;
    }
    else if(secType == "Dragon")
    {
        secTypeEnum = DRAGON;
    }
    else if(secType == "Dark")
    {
        secTypeEnum = DARK;
    }
    else if(secType == "Fairy")
    {
        secTypeEnum = FAIRY;
    }
}

/************************************************************************
* Method SetDamageValues: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage array with the corresponding type values
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*  	 	NORMAL_DMG  (float) - the damage taken from a normal type move
*
*  	 	FIGHT_DMG   (float) - the damage taken from a fighting type move
*
*  	 	FLY_DMG     (float) - the damage taken from a flying type move
*
*   	POI_DMG     (float) - the damage taken from a poison type move
*
*   	GRD_DMG     (float) - the damage taken from a ground type move
*
*   	ROCK_DMG    (float) - the damage taken from a rock type move
*
*   	BUG_DMG     (float) - the damage taken from a bug type move
*
*   	GHOST_DMG   (float) - the damage taken from a ghost type move
*
*   	STEEL_DMG   (float) - the damage taken from a steel type move
*
*   	FIRE_DMG    (float) - the damage taken from a fire type move
*
*   	WATER_DMG   (float) - the damage taken from a water type move
*
*   	GRASS_DMG	(float) - the damage taken from a grass type move
*
*   	ELEC_DMG    (float) - the damage taken from a electric type move
*
*   	PSY_DMG     (float) - the damage taken from a psychic type move
*
*   	ICE_DMG     (float) - the damage taken from a ice type move
*
*   	DRGN_DMG    (float) - the damage taken from a dragon type move
*
*   	DARK_DMG    (float) - the damage taken from a dark type move
*
*   	FAIRY_DMG   (float) - the damage taken from a fairy type move
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::SetDamageValues(const float &NORMAL_DMG,
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
                                      const float &FAIRY_DMG)
{
    damageAr[NORMAL]   = NORMAL_DMG;
    damageAr[FIGHTING] = FIGHT_DMG;
    damageAr[FLYING]   = FLY_DMG;
    damageAr[POISON]   = POI_DMG;
    damageAr[GROUND]   = GRD_DMG;
    damageAr[ROCK]     = ROCK_DMG;
    damageAr[BUG]      = BUG_DMG;
    damageAr[GHOST]    = GHOST_DMG;
    damageAr[STEEL]    = STEEL_DMG;
    damageAr[FIRE]     = FIRE_DMG;
    damageAr[WATER]    = WATER_DMG;
    damageAr[GRASS]    = GRASS_DMG;
    damageAr[ELECTRIC] = ELEC_DMG;
    damageAr[PSYCHIC]  = PSY_DMG;
    damageAr[ICE]      = ICE_DMG;
    damageAr[DRAGON]   = DRGN_DMG;
    damageAr[DARK]     = DARK_DMG;
    damageAr[FAIRY]    = FAIRY_DMG;
}

/************************************************************************
* Method BugTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a bug type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::BugTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 0.5, 2.0,
                            1.0, 0.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 0.5, 4.0, 1.0, 0.5, 1.0,
                            0.5, 1.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.25, 2.0, 1.0, 0.0, 4.0,
                            0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.25, 2.0, 0.5, 1.0, 2.0,
                            0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 0.5, 2.0, 0.5, 0.5, 1.0,
                            1.0, 1.0, 1.0, 2.0, 2.0, 1.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 1.0, 1.0, 0.5, 1.0, 2.0,
                            1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                            1.0, 1.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 2.0, 0.5, 0.5, 2.0,
                            0.5, 2.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.0, 0.0, 2.0, 0.5, 0.5, 2.0,
                            0.5, 2.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 1.0, 4.0,
                            0.5, 1.0, 0.5, 1.0, 2.0, 0.25,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                            1.0, 1.0, 0.5, 1.0, 0.5, 1.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 0.5, 4.0, 2.0, 0.25, 2.0,
                            2.0, 1.0, 1.0, 4.0, 0.5, 0.25,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 0.5, 2.0, 1.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.25, 2.0, 1.0, 0.5, 2.0,
                            2.0, 2.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 1.0, 2.0, 1.0, 0.5, 4.0,
                            1.0, 1.0, 2.0, 4.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                            1.0, 1.0, 1.0, 1.0, 0.5, 0.25,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 1.0, 2.0, 1.0, 0.5, 2.0,
                            2.0, 0.5, 1.0, 2.0, 1.0, 0.5,
                            1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.25, 2.0, 2.0, 0.5, 2.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method DarkTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a dark type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::DarkTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 0.25, 4.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 0.0, 2.0,
                            1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                            2.0, 0.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                            1.0, 0.0, 1.0, 1.0, 0.5, 1.0
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                            2.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                            0.0, 0.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                            2.0, 0.5, 2.0, 0.5, 2.0, 2.0,
                            1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 1.0, 2.0,
                            2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.0, 2.0, 0.5,
                            1.0, 0.5, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.0, 0.5, 0.5, 0.5, 1.0
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                            1.0, 0.5, 0.5, 0.5, 2.0, 0.5,
                            1.0, 0.0, 0.5, 1.0, 0.5, 1.0
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.5, 0.5, 0.5, 0.5, 2.0,
                            2.0, 0.0, 0.5, 1.0, 0.5, 2.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                            4.0, 0.5, 1.0, 2.0, 0.5, 0.5,
                            0.5, 0.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                            2.0, 0.5, 0.5, 1.0, 1.0, 1.0,
                            0.5, 0.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            4.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                            2.0, 0.5, 2.0, 2.0, 1.0, 1.0,
                            1.0, 0.0, 0.5, 1.0, 0.5, 2.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.5, 1.0, 0.5, 0.5, 0.5,
                            0.5, 0.0, 2.0, 2.0, 0.5, 4.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 0.0, 0.25, 2.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method DragonTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a dragon type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::DragonTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 2.0, 2.0, 2.0, 0.5, 4.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                            0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                            1.0, 1.0, 4.0, 2.0, 1.0, 2.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                            0.5, 2.0, 2.0, 2.0, 1.0, 1.0
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 1.0, 1.0, 0.5, 1.0, 1.0,
                            0.0, 1.0, 4.0, 2.0, 1.0, 2.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 1.0, 2.0, 0.25, 1.0, 1.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                            1.0, 1.0, 1.0, 1.0, 0.5, 0.25,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 2.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 2.0, 2.0, 2.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.0, 2.0, 0.5,
                            0.5, 1.0, 0.5, 1.0, 0.5, 0.25,
                            0.5, 0.5, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 1.0, 0.5, 0.25, 1.0, 0.25,
                            0.5, 1.0, 1.0, 2.0, 1.0, 1.0
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 0.25, 0.25, 1.0,
                            1.0, 1.0, 1.0, 2.0, 1.0, 2.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 2.0, 1.0, 1.0,
                            2.0, 1.0, 1.0, 1.0, 0.5, 0.5,
                            0.5, 1.0, 4.0, 2.0, 1.0, 2.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 0.5, 1.0, 21.0, 1.0,
                            1.0, 1.0, 0.5, 0.5, 0.5, 0.5,
                            0.25, 1.0, 2.0, 2.0, 1.0, 2.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            2.0, 2.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 0.5, 2.0, 1.0, 2.0, 2.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                            0.5, 1.0, 1.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.5, 1.0, 0.5, 0.5, 0.5,
                            0.5, 0.0, 2.0, 2.0, 0.5, 4.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                            0.5, 1.0, 2.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 0.0, 0.5, 2.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method ElectricTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is an electric type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::ElectricTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                            1.0, 0.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
                            0.5, 1.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 0.5, 1.0, 0.0, 2.0,
                            0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                            1.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 0.5, 0.5, 4.0, 1.0,
                            0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                            0.5, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 0.25, 0.5, 4.0, 1.0,
                            1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 0.5, 2.0, 1.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 0.5, 0.5, 2.0, 1.0,
                            0.5, 2.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 0.25, 0.0, 4.0, 0.5,
                            0.5, 1.0, 0.25, 2.0, 1.0, 0.5,
                            0.5, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 0.5, 1.0, 4.0, 2.0,
                            0.5, 1.0, 0.25, 0.5, 2.0, 0.5,
                            0.5, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                            1.0, 1.0, 0.25, 0.5, 0.5, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            2.0, 1.0, 0.5, 2.0, 0.5, 0.5,
                            0.25, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 0.5, 1.0, 2.0, 1.0,
                            2.0, 2.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 0.5, 1.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 0.5, 1.0, 2.0, 2.0,
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            0.5, 1.0, 0.5, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                            1.0, 1.0, 0.5, 0.5, 0.5, 0.5,
                            0.25, 1.0, 2.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                            2.0, 0.5, 0.5, 1.0, 1.0, 1.0,
                            0.5, 0.0, 1.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 0.5, 2.0, 2.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method FairyTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a fairy type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::FairyTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            0.5, 0.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 0.5, 2.0, 2.0, 1.0, 0.5,
                            0.25, 1.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 0.0, 0.25, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.25, 1.0, 2.0, 0.0, 2.0,
                            0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 0.0, 0.5, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.25, 1.0, 1.0, 2.0, 1.0,
                            0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 0.0, 0.5, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 2.0, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 0.0, 0.5, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 1.0, 2.0, 1.0,
                            0.5, 1.0, 4.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.25, 2.0, 2.0, 0.5, 2.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                            0.25, 2.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 0.0, 1.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                            0.25, 1.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.0, 0.5, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 2.0, 2.0, 2.0,
                            0.25, 1.0, 1.0, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 0.0, 0.5, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 0.0, 0.5, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 0.5, 2.0, 4.0, 0.5, 1.0,
                            1.0, 1.0, 2.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 0.0, 0.5, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 0.5, 0.5, 2.0, 2.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 0.0, 0.5, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.25, 1.0, 2.0, 1.0, 1.0,
                            1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 0.0, 1.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 2.0, 1.0, 2.0,
                            0.5, 1.0, 4.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 0.0, 0.5, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                            0.5, 1.0, 2.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 0.0, 0.5, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 0.0, 0.25, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method FightingTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a fighting type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::FightingTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 0.0, 1.0,
                            0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 2.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 2.0, 0.5, 2.0, 0.5,
                            0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 4.0, 1.0, 1.0, 0.5, 1.0
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 1.0, 0.25,
                            0.5, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 2.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 1.0, 0.5, 2.0, 0.5,
                            0.5, 1.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 4.0, 1.0, 0.5, 1.0,
                            0.5, 1.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 2.0, 0.5, 1.0, 0.5,
                            0.25, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 1.0, 0.0, 2.0, 0.25,
                            0.25, 1.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 0.5, 0.5, 1.0
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                            0.25, 1.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 2.0, 0.5, 1.0, 0.5, 1.0
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 2.0, 0.5, 1.0, 0.5, 2.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 4.0, 2.0, 0.5, 1.0,
                            1.0, 1.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 2.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
                            0.5, 1.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 2.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 2.0, 0.5, 1.0, 0.5, 2.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 2.0, 2.0, 2.0, 0.5, 4.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 0.25, 4.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 2.0, 2.0, 1.0, 0.5,
                            0.25, 1.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 0.0, 0.25, 2.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method FireTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a fire type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::FireTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 0.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                            0.25, 1.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 2.0, 0.5, 1.0, 0.5, 1.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 0.0, 4.0,
                            0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                            2.0, 1.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 4.0, 2.0,
                            0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                            1.0, 2.0, 0.5, 1.0, 1.0, 0.25
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 0.5, 0.5, 4.0, 1.0,
                            0.0, 1.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.5, 4.0, 2.0,
                            0.5, 1.0, 1.0, 0.25, 4.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 1.0, 4.0,
                            0.5, 1.0, 0.5, 1.0, 2.0, 0.25,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 2.0, 2.0,
                            0.25, 2.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 2.0, 0.5
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.0, 4.0, 1.0,
                            0.25, 1.0, 0.25, 1.0, 2.0, 0.25,
                            1.0, 0.5, 0.25, 0.5, 1.0, 0.25
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 1.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 1.0, 0.25, 0.25, 1.0, 1.0,
                            2.0, 1.0, 0.25, 1.0, 1.0, 0.5
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 2.0, 1.0, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.25,
                            0.5, 1.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 0.5, 1.0, 4.0, 2.0,
                            0.5, 1.0, 0.25, 0.5, 2.0, 0.5,
                            0.5, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                            1.0, 2.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 0.5, 0.5, 1.0, 2.0, 0.5
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 2.0, 4.0,
                            0.5, 1.0, 1.0, 1.0, 2.0, 0.5,
                            1.0, 1.0, 0.25, 1.0, 1.0, 0.5
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 1.0, 0.5, 0.25, 1.0, 0.25,
                            0.5, 1.0, 1.0, 2.0, 1.0, 1.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                            1.0, 0.5, 0.5, 0.5, 2.0, 0.5,
                            1.0, 0.0, 0.5, 1.0, 0.5, 1.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 2.0, 2.0, 2.0,
                            0.25, 1.0, 1.0, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 0.0, 0.5, 0.5
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method FlyingTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a flying type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::FlyingTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 0.0, 2.0,
                            0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 0.0, 1.0,
                            0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 2.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 0,
                            2.0, 2.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 0.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                            0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.5, 0.0, 2.0,
                            0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.25, 2.0, 1.0, 0.0, 4.0,
                            0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 0.0, 2.0,
                            0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 0.0, 1.0,
                            0.25, 1.0, 0.5, 2.0, 1.0, 0.25,
                            2.0, 0.5, 1.0, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 0.0, 4.0,
                            0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                            2.0, 1.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 0.25, 1.0, 1.0, 0.0, 2.0,
                            0.25, 1.0, 0.25, 0.25, 0.25, 1.0,
                            4.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 0.5, 2.0, 2.0, 0.0, 2.0,
                            1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                            1.0, 1.0, 4.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 0.5, 0.5, 1.0, 0.0, 2.0,
                            0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                            1.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.25, 1.0, 1.0, 0.0, 2.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 0.5, 2.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 0.0, 4.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                            2.0, 1.0, 1.0, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                            0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                            1.0, 1.0, 4.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 0.0, 2.0,
                            1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                            2.0, 0.0, 2.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.25, 1.0, 2.0, 0.0, 2.0,
                            0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method GhostTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a ghost type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::GhostTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            0.0, 0.0, 2.0, 0.5, 1.0, 0.5,
                            0.25, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 0.0, 2.0,
                            0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.25, 2.0, 1.0,
                            0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 2.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.25, 1.0, 0.5,
                            0.5, 2.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.0, 0.0, 0.5, 0.25, 2.0, 1.0,
                            0.5, 2.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            0.0, 0.0, 2.0, 0.5, 0.5, 2.0,
                            0.5, 2.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.0, 0.0, 0.5, 0.0, 2.0, 0.5,
                            0.25, 2.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.5, 2.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 2.0, 2.0,
                            0.25, 2.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 2.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 2.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 1.0, 2.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            0.0, 0.0, 2.0, 1.0, 0.5, 1.0,
                            1.0, 2.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            0.0, 0.0, 0.5, 0.5, 2.0, 1.0,
                            0.5, 2.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            1.0, 4.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 4.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            0.0, 0.0, 1.0, 0.5, 1.0, 2.0,
                            0.5, 2.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 2.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 2.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 2.0, 2.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                            0.25, 2.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 0.0, 1.0, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method GrassTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a grass type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::GrassTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                            2.0, 0.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 4.0, 2.0, 0.5, 0.5,
                            1.0, 1.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 2.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 2.0, 2.0, 0.0, 2.0,
                            1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                            1.0, 1.0, 4.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                            0.5, 2.0, 2.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                            2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 4.0, 2.0, 0.25, 2.0,
                            2.0, 1.0, 1.0, 4.0, 0.5, 0.25,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 2.0, 1.0, 0.5, 1.0,
                            1.0, 2.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 1.0, 0.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 4.0, 0.5, 0.25,
                            0.5, 0.5, 1.0, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 2.0, 1.0, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.25,
                            0.5, 1.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                            2.0, 1.0, 0.5, 1.0, 0.25, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                            2.0, 1.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            2.0, 1.0, 0.5, 2.0, 0.5, 0.5,
                            0.25, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 2.0, 2.0, 0.5, 1.0,
                            4.0, 2.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 0.5, 2.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 2.0, 2.0, 0.5, 2.0,
                            2.0, 1.0, 2.0, 4.0, 0.5, 0.5,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                            2.0, 1.0, 1.0, 1.0, 0.25, 0.25,
                            0.25, 1.0, 4.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                            4.0, 0.5, 1.0, 2.0, 0.5, 0.5,
                            0.5, 0.0, 2.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 2.0, 4.0, 0.5, 1.0,
                            1.0, 1.0, 2.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method GroundTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a ground type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::GroundTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 0.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 2.0, 0.5, 1.0, 0.25,
                            0.5, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 2.0, 2.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 0.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                            0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.25, 2.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                            0.0, 2.0, 2.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.25, 2.0, 0.5,
                            1.0, 1.0, 2.0, 0.5, 4.0, 4.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 2.0, 0.5, 0.5, 1.0,
                            1.0, 1.0, 1.0, 2.0, 2.0, 1.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.25, 1.0, 0.5,
                            0.5, 2.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.0, 2.0, 0.25,
                            0.5, 1.0, 0.5, 2.0, 2.0, 1.0,
                            0.0, 0.5, 1.0, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 0.5, 0.5, 4.0, 1.0,
                            0.0, 1.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 1.0, 0.5, 0.5, 1.0, 4.0,
                            0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                            2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 1.0, 0.5, 1.0, 0.5,
                            2.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 0.5, 2.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 0.5, 1.0, 1.0,
                            1.0, 1.0, 2.0, 2.0, 2.0, 2.0,
                            0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 1.0, 1.0, 0.5, 1.0, 1.0,
                            0.0, 1.0, 4.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                            2.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                            0.0, 0.0, 2.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 2.0, 1.0, 2.0, 2.0,
                            0.0, 1.0, 2.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method IceTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is an ice type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::IceTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 0.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 2.0, 0.5, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 0.0, 4.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                            2.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                            1.0, 2.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 0.5, 1.0, 1.0,
                            1.0, 1.0, 2.0, 2.0, 2.0, 2.0,
                            0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.5, 2.0, 2.0,
                            1.0, 1.0, 4.0, 1.0, 2.0, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 0.5, 4.0,
                            1.0, 1.0, 2.0, 4.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 2.0,
                            0.5, 2.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.0, 2.0, 1.0,
                            0.5, 1.0, 1.0, 4.0, 1.0, 0.5,
                            1.0, 0.5, 0.25, 1.0, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 2.0, 4.0,
                            0.5, 1.0, 1.0, 1.0, 2.0, 0.5,
                            1.0, 1.0, 0.25, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 0.5, 2.0,
                            2.0, 1.0, 0.25, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 2.0, 2.0, 2.0, 0.5, 2.0,
                            2.0, 1.0, 2.0, 4.0, 0.5, 0.5,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 2.0, 0.5, 1.0, 2.0, 2.0,
                            1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                            0.5, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 1.0, 2.0,
                            2.0, 2.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 0.5, 0.5, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                            0.5, 1.0, 1.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                            2.0, 0.5, 2.0, 2.0, 1.0, 1.0,
                            1.0, 0.0, 0.5, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 2.0, 1.0, 2.0,
                            0.5, 1.0, 4.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method NormalTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a normal type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::NormalTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 0.0, 2.0,
                            0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 0.5, 2.0, 1.0,
                            0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 0.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 0.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 0.5, 2.0,
                            1.0, 0.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            1.0, 4.0, 0.5, 0.0, 2.0, 0.5,
                            0.5, 0.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 0.0, 0.5, 0.5, 2.0, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                            2.0, 0.0, 1.0, 2.0, 0.5, 0.5,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                            1.0, 0.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 0.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 4.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 2.0, 1.0, 1.0,
                            0.5, 0.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method PoisonTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a poison type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::PoisonTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                            0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 0.5, 2.0, 0.5, 2.0, 0.5,
                            0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 4.0, 1.0, 1.0, 0.5, 1.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.25, 1.0, 0.5, 0.0, 2.0,
                            0.25, 1.0, 1.0, 1.0, 1.0, 0.25,
                            2.0, 2.0, 2.0, 1.0, 1.0, 0.5
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.25, 2.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                            0.0, 2.0, 2.0, 1.0, 1.0, 0.5
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.25, 2.0, 1.0,
                            0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.25, 2.0, 0.5, 1.0, 2.0,
                            0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.25, 2.0, 1.0,
                            0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 2.0, 0.5
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 4.0, 0.5,
                            0.25, 1.0, 0.5, 2.0, 1.0, 0.25,
                            1.0, 1.0, 0.5, 0.5, 1.0, 0.25
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 4.0, 2.0,
                            0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                            1.0, 2.0, 0.5, 1.0, 1.0, 0.25
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
                            2.0, 2.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                            0.5, 2.0, 2.0, 1.0, 1.0, 0.5
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 0.5, 0.5, 0.5, 4.0, 1.0,
                            0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                            0.5, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.25, 1.0, 0.5, 2.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 2.0, 0.5
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                            1.0, 2.0, 0.5, 1.0, 1.0, 0.5
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                            0.5, 2.0, 2.0, 2.0, 1.0, 1.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                            1.0, 0.0, 1.0, 1.0, 0.5, 1.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.25, 1.0, 1.0, 2.0, 1.0,
                            0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 0.0, 0.5, 0.5
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method PsychicTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a psychic type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::PsychicTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 1.0, 0.5,
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.25, 1.0, 1.0, 0.0, 2.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                            2.0, 0.5, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.25, 1.0, 0.5, 2.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                            1.0, 1.0, 1.0, 1.0, 2.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 1.0, 0.5,
                            2.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                            0.0, 0.5, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.5, 2.0, 1.0,
                            2.0, 2.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.25, 2.0, 1.0, 0.5, 2.0,
                            2.0, 2.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            1.0, 4.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 4.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                            1.0, 2.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.25, 0.5, 0.5, 2.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                            1.0, 2.0, 0.5, 0.5, 2.0, 0.5,
                            1.0, 0.5, 0.5, 1.0, 2.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            2.0, 2.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 0.5, 0.5, 1.0, 2.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 0.5, 2.0, 2.0, 0.5, 1.0,
                            4.0, 2.0, 1.0, 2.0, 0.5, 1.0,
                            0.5, 0.5, 2.0, 1.0, 2.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 0.5, 0.5, 1.0, 2.0, 1.0,
                            2.0, 2.0, 0.5, 1.0, 1.0, 1.0,
                            0.5, 0.5, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            2.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 1.0, 2.0,
                            2.0, 2.0, 2.0, 2.0, 1.0, 1.0,
                            1.0, 0.5, 0.5, 1.0, 2.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            2.0, 2.0, 1.0, 0.5, 0.5, 0.5,
                            0.5, 0.5, 2.0, 2.0, 2.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            4.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.25, 1.0, 2.0, 1.0, 1.0,
                            1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                            1.0, 0.5, 1.0, 0.0, 1.0, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method RockTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a rock type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::RockTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 0.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            0.5, 2.0, 1.0, 0.5, 2.0, 0.5,
                            0.5, 1.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.5, 0.0, 2.0,
                            0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.25, 4.0, 1.0,
                            0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                            1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.25, 2.0, 0.5,
                            1.0, 1.0, 2.0, 0.5, 4.0, 4.0,
                            0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 1.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            0.5, 1.0, 1.0, 0.5, 1.0, 2.0,
                            1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 0.5, 0.25, 2.0, 1.0,
                            0.5, 2.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.25, 4.0, 0.25, 0.0, 4.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                            1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.5, 4.0, 2.0,
                            0.5, 1.0, 1.0, 0.25, 4.0, 1.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 1.0, 1.0, 0.25, 1.0, 4.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 1.0, 2.0, 1.0, 1.0, 1.0,
                            0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            0.5, 2.0, 0.25, 0.5, 4.0, 1.0,
                            1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                            0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            0.5, 1.0, 0.5, 0.5, 2.0, 1.0,
                            2.0, 2.0, 2.0, 0.5, 2.0, 2.0,
                            1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            0.5, 4.0, 0.5, 0.5, 2.0, 2.0,
                            1.0, 1.0, 4.0, 1.0, 2.0, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 1.0, 2.0, 0.25, 1.0, 1.0,
                            0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                            2.0, 0.5, 2.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            0.5, 1.0, 0.5, 1.0, 2.0, 1.0,
                            0.5, 1.0, 4.0, 0.5, 2.0, 2.0,
                            1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method SteelTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a steel type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::SteelTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            0.5, 4.0, 0.5, 0.0, 2.0, 0.5,
                            0.5, 0.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            0.5, 2.0, 1.0, 0.0, 2.0, 0.25,
                            0.25, 1.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 0.5, 0.5, 1.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 0.0, 1.0,
                            0.5, 1.0, 0.5, 2.0, 1.0, 0.5,
                            2.0, 0.5, 1.0, 0.5, 1.0, 0.5
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 4.0, 0.5,
                            1.0, 1.0, 0.5, 2.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 0.5, 1.0, 1.0
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.0, 2.0, 0.25,
                            0.5, 1.0, 0.5, 2.0, 2.0, 1.0,
                            0.0, 0.5, 1.0, 0.5, 1.0, 0.5
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.25, 4.0, 0.25, 0.0, 4.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                            1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            0.5, 1.0, 1.0, 0.0, 1.0, 1.0,
                            0.5, 1.0, 0.5, 4.0, 1.0, 0.25,
                            1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 0.5, 0.0, 2.0, 0.5,
                            0.25, 2.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.5, 2.0, 0.5
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.0, 2.0, 0.5,
                            0.5, 1.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.0, 4.0, 1.0,
                            0.25, 1.0, 0.25, 1.0, 2.0, 0.25,
                            1.0, 0.5, 0.25, 0.5, 1.0, 0.25
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            0.5, 1.0, 0.5, 0.0, 1.0, 0.5,
                            0.5, 1.0, 0.25, 1.0, 0.5, 1.0,
                            1.0, 0.5, 0.25, 0.5, 1.0, 0.5
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            0.5, 2.0, 1.0, 0.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 4.0, 0.5, 0.25,
                            0.5, 1.0, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            0.5, 2.0, 0.25, 0.0, 1.0, 0.5,
                            0.5, 1.0, 0.25, 2.0, 1.0, 0.5,
                            0.5, 0.5, 0.5, 0.5, 1.0, 0.5
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                            1.0, 2.0, 0.5, 2.0, 1.0, 0.5,
                            1.0, 1.0, 0.5, 0.5, 2.0, 0.5
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            0.5, 4.0, 0.5, 0.0, 2.0, 1.0,
                            0.5, 1.0, 1.0, 4.0, 1.0, 0.5,
                            1.0, 0.5, 0.25, 0.5, 1.0, 0.5
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            0.5, 2.0, 0.5, 0.0, 2.0, 0.5,
                            0.5, 1.0, 0.5, 1.0, 0.5, 0.25,
                            0.5, 0.5, 1.0, 1.0, 1.0, 1.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            0.5, 4.0, 0.5, 0.0, 2.0, 0.5,
                            1.0, 0.5, 0.5, 2.0, 1.0, 0.5,
                            1.0, 0.0, 0.5, 0.5, 0.5, 1.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                            0.25, 1.0, 1.0, 2.0, 1.0, 0.5,
                            1.0, 0.5, 0.5, 0.0, 0.5, 0.5
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method WaterTypeDmg: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method initializes the damage if the Pokemon is a water type
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::WaterTypeDmg()
{
    switch(secTypeEnum)
    {
    case NORMAL:    SetDamageValues
                    (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 0.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case FIGHTING:  SetDamageValues
                    (
                            1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                            0.5, 1.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 2.0, 0.5, 1.0, 0.5, 2.0
                    );
                    break;

    case FLYING:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                            0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
                            4.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case POISON:    SetDamageValues
                    (
                            1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                            0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
                            2.0, 2.0, 0.5, 1.0, 1.0, 0.5
                    );
                    break;

    case GROUND:    SetDamageValues
                    (
                            1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                            1.0, 1.0, 0.5, 0.5, 1.0, 4.0,
                            0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ROCK:	    SetDamageValues
                    (
                            0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                            1.0, 1.0, 1.0, 0.25, 1.0, 4.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case BUG:       SetDamageValues
                    (
                            1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                            1.0, 1.0, 0.5, 1.0, 0.5, 1.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GHOST:	    SetDamageValues
                    (
                            0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                            0.5, 2.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 1.0, 2.0, 1.0
                    );
                    break;

    case STEEL:		SetDamageValues
                    (
                            0.5, 2.0, 0.5, 1.0, 2.0, 0.5,
                            0.5, 1.0, 1.0, 1.0, 0.5, 1.0,
                            2.0, 0.5, 1.0, 0.5, 1.0, 0.5
                    );
                    break;

    case FIRE:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            0.5, 1.0, 0.25, 0.25, 1.0, 1.0,
                            2.0, 1.0, 0.25, 1.0, 1.0, 0.5
                    );
                    break;

    case WATER:		SetDamageValues
                    (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case GRASS:		SetDamageValues
                    (
                            1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                            2.0, 1.0, 0.5, 1.0, 0.25, 1.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                    );
                    break;

    case ELECTRIC:  SetDamageValues
                    (
                            1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                            1.0, 1.0, 0.25, 0.5, 0.5, 2.0,
                            1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                    );
                    break;

    case PSYCHIC:  SetDamageValues
                   (
                            1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                            2.0, 2.0, 0.5, 0.5, 0.5, 2.0,
                            2.0, 0.5, 0.5, 1.0, 1.0, 1.0
                   );
                   break;

    case ICE:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                            1.0, 1.0, 1.0, 1.0, 0.5, 2.0,
                            2.0, 1.0, 0.25, 1.0, 1.0, 1.0
                   );
                   break;

    case DRAGON:   SetDamageValues
                   (
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                            1.0, 1.0, 0.5, 0.25, 0.25, 1.0,
                            1.0, 1.0, 1.0, 2.0, 1.0, 2.0
                   );
                   break;

    case DARK:	   SetDamageValues
                   (
                            1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                            2.0, 0.5, 0.5, 0.5, 0.5, 2.0,
                            2.0, 0.0, 0.5, 1.0, 0.5, 2.0
                   );
                   break;

    case FAIRY:	   SetDamageValues
                   (
                            1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                            0.5, 1.0, 1.0, 0.5, 0.5, 2.0,
                            2.0, 1.0, 0.5, 0.0, 0.5, 1.0
                   );
                   break;

    default:	   break;
    }
}

/************************************************************************
* Method CalcDamageTaken: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This method calculate the damage based on the Pokemon's primary type
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void PokemonWeakness::CalcDamageTaken()
{
    switch(priTypeEnum)
    {
    case NORMAL:	NormalTypeDmg();
                    break;
    case FIGHTING:	FightingTypeDmg();
                    break;
    case FLYING:	FlyingTypeDmg();
                    break;
    case POISON:	PoisonTypeDmg();
                    break;
    case GROUND:	GroundTypeDmg();
                    break;
    case ROCK:		RockTypeDmg();
                    break;
    case BUG:		BugTypeDmg();
                    break;
    case GHOST:		GhostTypeDmg();
                    break;
    case STEEL:		SteelTypeDmg();
                    break;
    case FIRE:		FireTypeDmg();
                    break;
    case WATER:		WaterTypeDmg();
                    break;
    case GRASS:		GrassTypeDmg();
                    break;
    case ELECTRIC:	ElectricTypeDmg();
                    break;
    case PSYCHIC:	PsychicTypeDmg();
                    break;
    case ICE:		IceTypeDmg();
                    break;
    case DRAGON:	DragonTypeDmg();
                    break;
    case DARK:		DarkTypeDmg();
                    break;
    case FAIRY:		FairyTypeDmg();
                    break;
    }
}

/************************************************************************
* Method PrintWeaknesses: Class PokemonWeakness
*----------------------------------------------------------------------
* 	 This prints the weakness format then returns it
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns the weakness format
*************************************************************************/
string PokemonWeakness::PrintWeaknesses() const
{
    std::ostringstream weaknesses;        //OUT

    int index;							  //PROC - The index in the array

    weaknesses << "\nDamage Taken:\n";

    weaknesses << std::left;

    //OUTPUT - Print the damage the pokemon would take
    for(index = NORMAL; index < globalWeakConsts::MAX_TYPES; index++)
    {
        weaknesses << std::setw(globalWeakConsts::TYPE_COL)
                   << globalWeakConsts::TYPES[index] << ": *"
                   << damageAr[index] << std::endl;
    }

    weaknesses << std::right;

    return (weaknesses.str());
}
