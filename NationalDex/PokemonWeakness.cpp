#include "PokemonWeakness.h"

PokemonWeakness::PokemonWeakness(){
    this->priTypeEnum = PokemonTypes::NORMAL;
    this->secTypeEnum = PokemonTypes::NORMAL;

    for(int index = 0; index < globalWeakConsts::MAX_TYPES; ++index){
        damageAr[index] = 0.0;
    }
}

PokemonWeakness::PokemonWeakness(const string &PRI_TYPE,
                                 const string &SEC_TYPE){
    this->InitializePriTypeEnum(PRI_TYPE);
    this->InitializeSecTypeEnum(SEC_TYPE);
}

PokemonWeakness::~PokemonWeakness(){}

void PokemonWeakness::InitializePriTypeEnum(const string &PRI_TYPE){
    if(PRI_TYPE == "Normal"){
        this->priTypeEnum = PokemonTypes::NORMAL;
    }
    else if(PRI_TYPE == "Fighting"){
        this->priTypeEnum = PokemonTypes::FIGHTING;
    }
    else if(PRI_TYPE == "Flying"){
        this->priTypeEnum = PokemonTypes::FLYING;
    }
    else if(PRI_TYPE == "Poison"){
        this->priTypeEnum = PokemonTypes::POISON;
    }
    else if(PRI_TYPE == "Ground"){
        this->priTypeEnum = PokemonTypes::GROUND;
    }
    else if(PRI_TYPE == "Rock"){
        this->priTypeEnum = PokemonTypes::ROCK;
    }
    else if(PRI_TYPE == "Bug"){
        this->priTypeEnum = PokemonTypes::BUG;
    }
    else if(PRI_TYPE == "Ghost"){
        this->priTypeEnum = PokemonTypes::GHOST;
    }
    else if(PRI_TYPE == "Steel"){
        this->priTypeEnum = PokemonTypes::STEEL;
    }
    else if(PRI_TYPE == "Fire"){
        this->priTypeEnum = PokemonTypes::FIRE;
    }
    else if(PRI_TYPE == "Water"){
        this->priTypeEnum = PokemonTypes::WATER;
    }
    else if(PRI_TYPE == "Grass"){
        this->priTypeEnum = PokemonTypes::GRASS;
    }
    else if(PRI_TYPE == "Electric"){
        this->priTypeEnum = PokemonTypes::ELECTRIC;
    }
    else if(PRI_TYPE == "Psychic"){
        priTypeEnum = PokemonTypes::PSYCHIC;
    }
    else if(PRI_TYPE == "Ice"){
        this->priTypeEnum = PokemonTypes::ICE;
    }

    else if(PRI_TYPE == "Dragon"){
        this->priTypeEnum = PokemonTypes::DRAGON;
    }
    else if(PRI_TYPE == "Dark"){
        this->priTypeEnum = PokemonTypes::DARK;
    }
    else if(PRI_TYPE == "Fairy"){
        this->priTypeEnum = PokemonTypes::FAIRY;
    }
}

void PokemonWeakness::InitializeSecTypeEnum(const string &SEC_TYPE){
    if(SEC_TYPE == "Normal"){
        this->secTypeEnum = PokemonTypes::NORMAL;
    }
    else if(SEC_TYPE == "Fighting"){
        this->secTypeEnum = PokemonTypes::FIGHTING;
    }
    else if(SEC_TYPE == "Flying"){
        this->secTypeEnum = PokemonTypes::FLYING;
    }
    else if(SEC_TYPE == "Poison"){
        this->secTypeEnum = PokemonTypes::POISON;
    }
    else if(SEC_TYPE == "Ground"){
        this->secTypeEnum = PokemonTypes::GROUND;
    }
    else if(SEC_TYPE == "Rock"){
        this->secTypeEnum = PokemonTypes::ROCK;
    }
    else if(SEC_TYPE == "Bug"){
        this->secTypeEnum = PokemonTypes::BUG;
    }
    else if(SEC_TYPE == "Ghost"){
        this->secTypeEnum = PokemonTypes::GHOST;
    }
    else if(SEC_TYPE == "Steel"){
        this->secTypeEnum = PokemonTypes::STEEL;
    }
    else if(SEC_TYPE == "Fire"){
        this->secTypeEnum = PokemonTypes::FIRE;
    }
    else if(SEC_TYPE == "Water"){
        this->secTypeEnum = PokemonTypes::WATER;
    }
    else if(SEC_TYPE == "Grass"){
        this->secTypeEnum = PokemonTypes::GRASS;
    }
    else if(SEC_TYPE == "Electric"){
        this->secTypeEnum = PokemonTypes::ELECTRIC;
    }
    else if(SEC_TYPE == "Psychic"){
        this->secTypeEnum = PokemonTypes::PSYCHIC;
    }
    else if(SEC_TYPE == "Ice"){
        this->secTypeEnum = PokemonTypes::ICE;
    }
    else if(SEC_TYPE == "Dragon"){
        this->secTypeEnum = PokemonTypes::DRAGON;
    }
    else if(SEC_TYPE == "Dark"){
        this->secTypeEnum = PokemonTypes::DARK;
    }
    else if(SEC_TYPE == "Fairy"){
        this->secTypeEnum = PokemonTypes::FAIRY;
    }
}

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
                                      const float &FAIRY_DMG){
    this->damageAr[PokemonTypes::NORMAL]   = NORMAL_DMG;
    this->damageAr[PokemonTypes::FIGHTING] = FIGHT_DMG;
    this->damageAr[PokemonTypes::FLYING]   = FLY_DMG;
    this->damageAr[PokemonTypes::POISON]   = POI_DMG;
    this->damageAr[PokemonTypes::GROUND]   = GRD_DMG;
    this->damageAr[PokemonTypes::ROCK]     = ROCK_DMG;
    this->damageAr[PokemonTypes::BUG]      = BUG_DMG;
    this->damageAr[PokemonTypes::GHOST]    = GHOST_DMG;
    this->damageAr[PokemonTypes::STEEL]    = STEEL_DMG;
    this->damageAr[PokemonTypes::FIRE]     = FIRE_DMG;
    this->damageAr[PokemonTypes::WATER]    = WATER_DMG;
    this->damageAr[PokemonTypes::GRASS]    = GRASS_DMG;
    this->damageAr[PokemonTypes::ELECTRIC] = ELEC_DMG;
    this->damageAr[PokemonTypes::PSYCHIC]  = PSY_DMG;
    this->damageAr[PokemonTypes::ICE]      = ICE_DMG;
    this->damageAr[PokemonTypes::DRAGON]   = DRGN_DMG;
    this->damageAr[PokemonTypes::DARK]     = DARK_DMG;
    this->damageAr[PokemonTypes::FAIRY]    = FAIRY_DMG;
}

void PokemonWeakness::BugTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 0.5, 2.0,
                                        1.0, 0.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 0.5, 4.0, 1.0, 0.5, 1.0,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.25, 2.0, 1.0, 0.0, 4.0,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.25, 2.0, 0.5, 1.0, 2.0,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 0.5, 2.0, 0.5, 0.5, 1.0,
                                        1.0, 1.0, 1.0, 2.0, 2.0, 1.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ROCK:	    this->SetDamageValues(
                                        0.5, 1.0, 1.0, 0.5, 1.0, 2.0,
                                        1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                                        1.0, 1.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GHOST:	    this->SetDamageValues(
                                        0.0, 0.0, 2.0, 0.5, 0.5, 2.0,
                                        0.5, 2.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.0, 0.0, 2.0, 0.5, 0.5, 2.0,
                                        0.5, 2.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 1.0, 4.0,
                                        0.5, 1.0, 0.5, 1.0, 2.0, 0.25,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 0.5, 1.0,
                                        2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 0.5, 4.0, 2.0, 0.25, 2.0,
                                        2.0, 1.0, 1.0, 4.0, 0.5, 0.25,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 0.5, 2.0, 1.0, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:    this->SetDamageValues(
                                        1.0, 0.25, 2.0, 1.0, 0.5, 2.0,
                                        2.0, 2.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ICE:        this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 0.5, 4.0,
                                        1.0, 1.0, 2.0, 4.0, 1.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::DRAGON:     this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 0.5, 0.25,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::DARK:	   this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 0.5, 2.0,
                                        2.0, 0.5, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:	   this->SetDamageValues(
                                        1.0, 0.25, 2.0, 2.0, 0.5, 2.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                   );
                                   break;
    }
}

void PokemonWeakness::DarkTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                                        1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 0.25, 4.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 0.0, 2.0,
                                        1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 0.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                                        1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 0.0, 1.0, 1.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                                        2.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 0.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::ROCK:        this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                                        2.0, 0.5, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 1.0, 2.0,
                                        2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.0, 2.0, 0.5,
                                        1.0, 0.5, 0.5, 2.0, 1.0, 0.5,
                                        1.0, 0.0, 0.5, 0.5, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        1.0, 0.5, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 0.0, 0.5, 1.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.5, 0.5, 0.5, 0.5, 2.0,
                                        2.0, 0.0, 0.5, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                                        4.0, 0.5, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 0.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                                        2.0, 0.5, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 0.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:    this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        4.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::ICE:        this->SetDamageValues(
                                        1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                                        2.0, 0.5, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 0.0, 0.5, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::DRAGON:     this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.5, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 0.0, 2.0, 2.0, 0.5, 4.0
                                   );
                                   break;

    case PokemonTypes::DARK:	   this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 0.0, 0.25, 2.0
                                   );
                                   break;
    }
}

void PokemonWeakness::DragonTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 2.0, 2.0, 2.0, 0.5, 4.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                                        1.0, 1.0, 4.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                                        0.5, 2.0, 2.0, 2.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 0.5, 1.0, 1.0,
                                        0.0, 1.0, 4.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::ROCK:        this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                                        1.0, 1.0, 2.0, 0.25, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 0.5, 0.25,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        0.5, 2.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 2.0, 2.0, 2.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.0, 2.0, 0.5,
                                        0.5, 1.0, 0.5, 1.0, 0.5, 0.25,
                                        0.5, 0.5, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 1.0, 0.5, 0.25, 1.0, 0.25,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 0.25, 0.25, 1.0,
                                        1.0, 1.0, 1.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 1.0, 2.0, 2.0, 1.0, 1.0,
                                        2.0, 1.0, 1.0, 1.0, 0.5, 0.5,
                                        0.5, 1.0, 4.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 1.0, 0.5, 1.0, 21.0, 1.0,
                                        1.0, 1.0, 0.5, 0.5, 0.5, 0.5,
                                        0.25, 1.0, 2.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:     this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 2.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 0.5, 2.0, 1.0, 2.0, 2.0
                                    );
                                    break;

    case PokemonTypes::ICE:         this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::DRAGON:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::DARK:        this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.5, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 0.0, 2.0, 2.0, 0.5, 4.0
                                    );
                                    break;

    case PokemonTypes::FAIRY:       this->SetDamageValues(
                                        1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 0.0, 0.5, 2.0
                                    );
                                   break;
    }
}

void PokemonWeakness::ElectricTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                                        1.0, 0.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.5, 0.5, 1.0, 0.0, 2.0,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                                        1.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.5, 0.5, 0.5, 4.0, 1.0,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                                        0.5, 2.0, 1.0, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 1.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ROCK:	    this->SetDamageValues(
                                        0.5, 2.0, 0.25, 0.5, 4.0, 1.0,
                                        1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 0.5, 2.0, 1.0, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 0.5, 0.5, 2.0, 1.0,
                                        0.5, 2.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.5, 2.0, 0.25, 0.0, 4.0, 0.5,
                                        0.5, 1.0, 0.25, 2.0, 1.0, 0.5,
                                        0.5, 0.5, 0.5, 0.5, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 1.0, 0.5, 1.0, 4.0, 2.0,
                                        0.5, 1.0, 0.25, 0.5, 2.0, 0.5,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                                        1.0, 1.0, 0.25, 0.5, 0.5, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        2.0, 1.0, 0.5, 2.0, 0.5, 0.5,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:     this->SetDamageValues(
                                        1.0, 0.5, 0.5, 1.0, 2.0, 1.0,
                                        2.0, 2.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 0.5, 1.0, 1.0, 2.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ICE:         this->SetDamageValues(
                                        1.0, 2.0, 0.5, 1.0, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::DRAGON:      this->SetDamageValues(
                                        1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                                        1.0, 1.0, 0.5, 0.5, 0.5, 0.5,
                                        0.25, 1.0, 2.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::DARK:	   this->SetDamageValues(
                                        1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                                        2.0, 0.5, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 0.0, 1.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:	   this->SetDamageValues(
                                        1.0, 0.5, 0.5, 2.0, 2.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 0.0, 0.5, 1.0
                                   );
                                   break;
    }
}

void PokemonWeakness::FairyTypeDmg(){
    switch(secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 0.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 0.5, 2.0, 2.0, 1.0, 0.5,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 0.0, 0.25, 2.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.25, 1.0, 2.0, 0.0, 2.0,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.25, 1.0, 1.0, 2.0, 1.0,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 0.0, 0.5, 0.5
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::ROCK:        this->SetDamageValues(
                                        0.5, 1.0, 0.5, 1.0, 2.0, 1.0,
                                        0.5, 1.0, 4.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.25, 2.0, 2.0, 0.5, 2.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        0.25, 2.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 0.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                                        0.25, 1.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 0.5, 0.5, 0.0, 0.5, 0.5
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 0.5, 1.0, 2.0, 2.0, 2.0,
                                        0.25, 1.0, 1.0, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 0.0, 0.5, 0.5
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 2.0,
                                        2.0, 1.0, 0.5, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 0.5, 2.0, 4.0, 0.5, 1.0,
                                        1.0, 1.0, 2.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 0.5, 0.5, 2.0, 2.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:     this->SetDamageValues(
                                        1.0, 0.25, 1.0, 2.0, 1.0, 1.0,
                                        1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 0.5, 1.0, 0.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ICE:         this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 2.0,
                                        0.5, 1.0, 4.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 0.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::DRAGON:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 0.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::DARK:        this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 0.0, 0.25, 2.0
                                    );
                                    break;

    case PokemonTypes::FAIRY:       this->SetDamageValues(
                                        1.0, 0.5, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                    );
                                    break;
    }
}

void PokemonWeakness::FightingTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 0.0, 1.0,
                                        0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 2.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.5, 2.0, 0.5, 2.0, 0.5,
                                        0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 4.0, 1.0, 1.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 1.0, 0.25,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 2.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::ROCK:        this->SetDamageValues(
                                        0.5, 2.0, 1.0, 0.5, 2.0, 0.5,
                                        0.5, 1.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.5, 4.0, 1.0, 0.5, 1.0,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 2.0, 0.5, 1.0, 0.5,
                                        0.25, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.5, 2.0, 1.0, 0.0, 2.0, 0.25,
                                        0.25, 1.0, 0.5, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 0.5, 0.5, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                                        0.25, 1.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 2.0, 0.5, 1.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        0.5, 1.0, 0.5, 0.5, 0.5, 2.0,
                                        2.0, 2.0, 0.5, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 1.0, 4.0, 2.0, 0.5, 1.0,
                                        1.0, 1.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 2.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 2.0, 1.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:     this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::ICE:         this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 2.0, 0.5, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::DRAGON:      this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 2.0, 2.0, 2.0, 0.5, 4.0
                                    );
                                    break;

    case PokemonTypes::DARK:        this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                                        1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 0.25, 4.0
                                    );
                                    break;

    case PokemonTypes::FAIRY:       this->SetDamageValues(
                                        1.0, 0.5, 2.0, 2.0, 1.0, 0.5,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 0.0, 0.25, 2.0
                                    );
                                    break;
    }
}

void PokemonWeakness::FireTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 0.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                                        0.25, 1.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 2.0, 0.5, 1.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 0.0, 4.0,
                                        0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                                        2.0, 1.0, 1.0, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 4.0, 2.0,
                                        0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                                        1.0, 2.0, 0.5, 1.0, 1.0, 0.25
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 1.0, 0.5, 0.5, 4.0, 1.0,
                                        0.0, 1.0, 1.0, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::ROCK:        this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.5, 4.0, 2.0,
                                        0.5, 1.0, 1.0, 0.25, 4.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 1.0, 4.0,
                                        0.5, 1.0, 0.5, 1.0, 2.0, 0.25,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 2.0, 2.0,
                                        0.25, 2.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 2.0, 0.5
                                    );
                                    break;

    case PokemonTypes::STEEL:	    this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.0, 4.0, 1.0,
                                        0.25, 1.0, 0.25, 1.0, 2.0, 0.25,
                                        1.0, 0.5, 0.25, 0.5, 1.0, 0.25
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 1.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 1.0, 0.25, 0.25, 1.0, 1.0,
                                        2.0, 1.0, 0.25, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 1.0, 2.0, 2.0, 1.0, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.25,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 1.0, 0.5, 1.0, 4.0, 2.0,
                                        0.5, 1.0, 0.25, 0.5, 2.0, 0.5,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:     this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                                        1.0, 2.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 0.5, 0.5, 1.0, 2.0, 0.5
                                    );
                                    break;

    case PokemonTypes::ICE:         this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 2.0, 4.0,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 0.5,
                                        1.0, 1.0, 0.25, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::DRAGON:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 1.0, 0.5, 0.25, 1.0, 0.25,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::DARK:        this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        1.0, 0.5, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 0.0, 0.5, 1.0, 0.5, 1.0
                                    );
                                    break;

    case PokemonTypes::FAIRY:       this->SetDamageValues(
                                        1.0, 0.5, 1.0, 2.0, 2.0, 2.0,
                                        0.25, 1.0, 1.0, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 0.0, 0.5, 0.5
                                    );
                                    break;
    }
}

void PokemonWeakness::FlyingTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 0.0, 2.0,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::FIGHTING:    this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 0.0, 1.0,
                                        0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 2.0, 2.0, 1.0, 0.5, 2.0
                                    );
                                    break;

    case PokemonTypes::FLYING:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::POISON:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 0,
                                        2.0, 2.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GROUND:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 0.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                                        0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ROCK:        this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.5, 0.0, 2.0,
                                        0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::BUG:         this->SetDamageValues(
                                        1.0, 0.25, 2.0, 1.0, 0.0, 4.0,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GHOST:       this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 0.0, 2.0,
                                        0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 1.0, 2.0, 1.0
                                    );
                                    break;

    case PokemonTypes::STEEL:		this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.0, 0.0, 1.0,
                                        0.25, 1.0, 0.5, 2.0, 1.0, 0.25,
                                        2.0, 0.5, 1.0, 0.5, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::FIRE:		this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 0.0, 4.0,
                                        0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                                        2.0, 1.0, 1.0, 1.0, 1.0, 0.5
                                    );
                                    break;

    case PokemonTypes::WATER:		this->SetDamageValues(
                                        1.0, 0.25, 1.0, 1.0, 0.0, 2.0,
                                        0.25, 1.0, 0.25, 0.25, 0.25, 1.0,
                                        4.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::GRASS:		this->SetDamageValues(
                                        1.0, 0.5, 2.0, 2.0, 0.0, 2.0,
                                        1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                                        1.0, 1.0, 4.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ELECTRIC:    this->SetDamageValues(
                                        1.0, 0.5, 0.5, 1.0, 0.0, 2.0,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                                        1.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::PSYCHIC:     this->SetDamageValues(
                                        1.0, 0.25, 1.0, 1.0, 0.0, 2.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 0.5, 2.0, 1.0, 2.0, 1.0
                                    );
                                    break;

    case PokemonTypes::ICE:         this->SetDamageValues
                                    (
                                        1.0, 1.0, 1.0, 1.0, 0.0, 4.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                                        2.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                    );
                                    break;

    case PokemonTypes::DRAGON:      this->SetDamageValues
                                    (
                                        1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                                        1.0, 1.0, 4.0, 2.0, 1.0, 2.0
                                    );
                                    break;

    case PokemonTypes::DARK:       this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 0.0, 2.0,
                                        1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 0.0, 2.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:      this->SetDamageValues(
                                        1.0, 0.25, 1.0, 2.0, 0.0, 2.0,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 0.0, 0.5, 1.0
                                   );
                                   break;
    }
}

void PokemonWeakness::GhostTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:     this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::FIGHTING:   this->SetDamageValues(
                                        0.0, 0.0, 2.0, 0.5, 1.0, 0.5,
                                        0.25, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::FLYING:     this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 0.0, 2.0,
                                        0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::POISON:     this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.25, 2.0, 1.0,
                                        0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 2.0, 0.5
                                   );
                                   break;

    case PokemonTypes::GROUND:     this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.25, 1.0, 0.5,
                                        0.5, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ROCK:	   this->SetDamageValues(
                                        0.0, 0.0, 0.5, 0.25, 2.0, 1.0,
                                        0.5, 2.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::BUG:        this->SetDamageValues(
                                        0.0, 0.0, 2.0, 0.5, 0.5, 2.0,
                                        0.5, 2.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GHOST:	   this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::STEEL:	   this->SetDamageValues(
                                        0.0, 0.0, 0.5, 0.0, 2.0, 0.5,
                                        0.25, 2.0, 0.5, 2.0, 1.0, 0.5,
                                        1.0, 0.5, 0.5, 0.5, 2.0, 0.5
                                   );
                                   break;

    case PokemonTypes::FIRE:	   this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 2.0, 2.0,
                                        0.25, 2.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 2.0, 0.5
                                   );
                                   break;

    case PokemonTypes::WATER:	   this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        0.5, 2.0, 0.5, 0.5, 0.5, 2.0,
                                        2.0, 1.0, 0.5, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GRASS:	   this->SetDamageValues(
                                        0.0, 0.0, 2.0, 1.0, 0.5, 1.0,
                                        1.0, 2.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ELECTRIC:   this->SetDamageValues(
                                        0.0, 0.0, 0.5, 0.5, 2.0, 1.0,
                                        0.5, 2.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::PSYCHIC:    this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        1.0, 4.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.5, 1.0, 1.0, 4.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ICE:        this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 2.0,
                                        0.5, 2.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::DRAGON:     this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        0.5, 2.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 2.0, 2.0, 2.0
                                   );
                                   break;

    case PokemonTypes::DARK:	   this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:	   this->SetDamageValues(
                                        0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        0.25, 2.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 0.0, 1.0, 1.0
                                   );
                                   break;
    }
}

void PokemonWeakness::GrassTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:     this->SetDamageValues(
                                        1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                                        2.0, 0.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::FIGHTING:   this->SetDamageValues(
                                        1.0, 1.0, 4.0, 2.0, 0.5, 0.5,
                                        1.0, 1.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 2.0, 2.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FLYING:     this->SetDamageValues(
                                        1.0, 0.5, 2.0, 2.0, 0.0, 2.0,
                                        1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                                        1.0, 1.0, 4.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::POISON:     this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                                        0.5, 2.0, 2.0, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::GROUND:     this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                                        2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ROCK:	   this->SetDamageValues(
                                        0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::BUG:        this->SetDamageValues(
                                        1.0, 0.5, 4.0, 2.0, 0.25, 2.0,
                                        2.0, 1.0, 1.0, 4.0, 0.5, 0.25,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GHOST:	   this->SetDamageValues(
                                        0.0, 0.0, 2.0, 1.0, 0.5, 1.0,
                                        1.0, 2.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::STEEL:	   this->SetDamageValues(
                                        0.5, 2.0, 1.0, 0.0, 1.0, 0.5,
                                        1.0, 1.0, 0.5, 4.0, 0.5, 0.25,
                                        0.5, 0.5, 1.0, 0.5, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::FIRE:	   this->SetDamageValues(
                                        1.0, 1.0, 2.0, 2.0, 1.0, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.25,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::WATER:	   this->SetDamageValues(
                                        1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                                        2.0, 1.0, 0.5, 1.0, 0.25, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GRASS:	   this->SetDamageValues(
                                        1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                                        2.0, 1.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ELECTRIC:   this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        2.0, 1.0, 0.5, 2.0, 0.5, 0.5,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::PSYCHIC:    this->SetDamageValues(
                                        1.0, 0.5, 2.0, 2.0, 0.5, 1.0,
                                        4.0, 2.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 0.5, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ICE:        this->SetDamageValues(
                                        1.0, 2.0, 2.0, 2.0, 0.5, 2.0,
                                        2.0, 1.0, 2.0, 4.0, 0.5, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::DRAGON:     this->SetDamageValues(
                                        1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                                        2.0, 1.0, 1.0, 1.0, 0.25, 0.25,
                                        0.25, 1.0, 4.0, 2.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::DARK:	   this->SetDamageValues(
                                        1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                                        4.0, 0.5, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 0.0, 2.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:	   this->SetDamageValues(
                                        1.0, 0.5, 2.0, 4.0, 0.5, 1.0,
                                        1.0, 1.0, 2.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 0.0, 0.5, 1.0
                                   );
                                   break;
    }
}

void PokemonWeakness::GroundTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:     this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                                        1.0, 0.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::FIGHTING:   this->SetDamageValues(
                                        1.0, 1.0, 2.0, 0.5, 1.0, 0.25,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 2.0, 2.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FLYING:     this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 0.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                                        0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::POISON:     this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.25, 2.0, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                                        0.0, 2.0, 2.0, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::GROUND:     this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ROCK:	   this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.25, 2.0, 0.5,
                                        1.0, 1.0, 2.0, 0.5, 4.0, 4.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::BUG:        this->SetDamageValues(
                                        1.0, 0.5, 2.0, 0.5, 0.5, 1.0,
                                        1.0, 1.0, 1.0, 2.0, 2.0, 1.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GHOST:	   this->SetDamageValues
                                   (
                                        0.0, 0.0, 1.0, 0.25, 1.0, 0.5,
                                        0.5, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::STEEL:	   this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.0, 2.0, 0.25,
                                        0.5, 1.0, 0.5, 2.0, 2.0, 1.0,
                                        0.0, 0.5, 1.0, 0.5, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::FIRE:	   this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 1.0, 0.5, 0.5, 4.0, 1.0,
                                        0.0, 1.0, 1.0, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::WATER:	   this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                                        1.0, 1.0, 0.5, 0.5, 1.0, 4.0,
                                        0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GRASS:	   this->SetDamageValues(
                                        1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                                        2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        0.0, 1.0, 4.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ELECTRIC:   this->SetDamageValues(
                                        1.0, 1.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::PSYCHIC:    this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 1.0, 0.5,
                                        2.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 0.5, 2.0, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ICE:        this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 1.0, 1.0,
                                        1.0, 1.0, 2.0, 2.0, 2.0, 2.0,
                                        0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::DRAGON:     this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 0.5, 1.0, 1.0,
                                        0.0, 1.0, 4.0, 2.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::DARK:	   this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                                        2.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 0.0, 2.0, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FAIRY:	   this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 2.0, 2.0,
                                        0.0, 1.0, 2.0, 0.0, 0.5, 1.0
                                   );
                   break;
    }
}

void PokemonWeakness::IceTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:     this->SetDamageValues(
                                        1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 0.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::FIGHTING:   this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 2.0, 0.5, 1.0, 0.5, 2.0
                                   );
                                   break;

    case PokemonTypes::FLYING:     this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 0.0, 4.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                                        2.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::POISON:     this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                                        1.0, 2.0, 0.5, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::GROUND:     this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 1.0, 1.0,
                                        1.0, 1.0, 2.0, 2.0, 2.0, 2.0,
                                        0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ROCK:	   this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 4.0, 1.0, 2.0, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::BUG:        this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 0.5, 4.0,
                                        1.0, 1.0, 2.0, 4.0, 1.0, 0.5,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GHOST:	   this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 2.0,
                                        0.5, 2.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::STEEL:	   this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.0, 2.0, 1.0,
                                        0.5, 1.0, 1.0, 4.0, 1.0, 0.5,
                                        1.0, 0.5, 0.25, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::FIRE:	   this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 2.0, 4.0,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 0.5,
                                        1.0, 1.0, 0.25, 1.0, 1.0, 0.5
                                   );
                                   break;

    case PokemonTypes::WATER:	   this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 0.5, 2.0,
                                        2.0, 1.0, 0.25, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::GRASS:	   this->SetDamageValues(
                                        1.0, 2.0, 2.0, 2.0, 0.5, 2.0,
                                        2.0, 1.0, 2.0, 4.0, 0.5, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ELECTRIC:   this->SetDamageValues(
                                        1.0, 2.0, 0.5, 1.0, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::PSYCHIC:    this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 1.0, 2.0,
                                        2.0, 2.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 0.5, 0.5, 1.0, 2.0, 1.0
                                   );
                                   break;

    case PokemonTypes::ICE:        this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                   );
                                   break;

    case PokemonTypes::DRAGON:     this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 2.0
                                   );
                                   break;

    case PokemonTypes::DARK:	  this->SetDamageValues(
                                        1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                                        2.0, 0.5, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 0.0, 0.5, 1.0, 0.5, 2.0
                                  );
                                  break;

    case PokemonTypes::FAIRY:	  this->SetDamageValues(
                                        1.0, 1.0, 1.0, 2.0, 1.0, 2.0,
                                        0.5, 1.0, 4.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 0.0, 0.5, 1.0
                                  );
                                  break;
    }
}

void PokemonWeakness::NormalTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:    this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::FIGHTING:  this->SetDamageValues(
                                        1.0, 2.0, 2.0, 1.0, 1.0, 0.5,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                  );
                                  break;

    case PokemonTypes::FLYING:    this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 0.0, 2.0,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::POISON:    this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::GROUND:    this->SetDamageValues(
                                        1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
                                        1.0, 0.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::ROCK:	  this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                                        1.0, 0.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::BUG:       this->SetDamageValues
                                  (
                                        1.0, 1.0, 2.0, 1.0, 0.5, 2.0,
                                        1.0, 0.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::GHOST:	  this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::STEEL:     this->SetDamageValues
                                  (
                                        1.0, 4.0, 0.5, 0.0, 2.0, 0.5,
                                        0.5, 0.0, 0.5, 2.0, 1.0, 0.5,
                                        1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::FIRE:	  this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        0.5, 0.0, 0.5, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::WATER:     this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 0.5, 0.5, 0.5, 2.0,
                                        2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::GRASS:	  this->SetDamageValues(
                                        1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
                                        2.0, 0.0, 1.0, 2.0, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::ELECTRIC:  this->SetDamageValues(
                                        1.0, 2.0, 0.5, 1.0, 2.0, 1.0,
                                        1.0, 0.0, 0.5, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::PSYCHIC:   this->SetDamageValues
                                  (
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::ICE:	      this->SetDamageValues(
                                        1.0, 4.0, 1.0, 1.0, 1.0, 2.0,
                                        1.0, 0.0, 2.0, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::DRAGON:    this->SetDamageValues(
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 0.5, 0.5, 0.5,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                  );
                                  break;

    case PokemonTypes::DARK:	  this->SetDamageValues(
                                        1.0, 4.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.0, 1.0, 1.0, 0.5, 2.0
                                  );
                                  break;

    case PokemonTypes::FAIRY:	  this->SetDamageValues(
                                        1.0, 2.0, 1.0, 2.0, 1.0, 1.0,
                                        0.5, 0.0, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                  );
                                  break;
    }
}

void PokemonWeakness::PoisonTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:    this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 0.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::FIGHTING:  this->SetDamageValues(
                                        1.0, 0.5, 2.0, 0.5, 2.0, 0.5,
                                        0.25, 1.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 4.0, 1.0, 1.0, 0.5, 1.0
                                  );
                                  break;

    case PokemonTypes::FLYING:    this->SetDamageValues(
                                        1.0, 0.25, 1.0, 0.5, 0.0, 2.0,
                                        0.25, 1.0, 1.0, 1.0, 1.0, 0.25,
                                        2.0, 2.0, 2.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::POISON:    this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::GROUND:    this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.25, 2.0, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                                        0.0, 2.0, 2.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::ROCK:	  this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.25, 2.0, 1.0,
                                        0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::BUG:       this->SetDamageValues(
                                        1.0, 0.25, 2.0, 0.5, 1.0, 2.0,
                                        0.5, 1.0, 1.0, 2.0, 1.0, 0.25,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::GHOST:	  this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.25, 2.0, 1.0,
                                        0.25, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 2.0, 0.5
                                  );
                                  break;

    case PokemonTypes::STEEL:     this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.0, 4.0, 0.5,
                                        0.25, 1.0, 0.5, 2.0, 1.0, 0.25,
                                        1.0, 1.0, 0.5, 0.5, 1.0, 0.25
                                  );
                                  break;

    case PokemonTypes::FIRE:	  this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 4.0, 2.0,
                                        0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
                                        1.0, 2.0, 0.5, 1.0, 1.0, 0.25
                                  );
                                  break;

    case PokemonTypes::WATER:	  this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
                                        2.0, 2.0, 0.5, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::GRASS:	  this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
                                        0.5, 2.0, 2.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::ELECTRIC:  this->SetDamageValues(
                                        1.0, 0.5, 0.5, 0.5, 4.0, 1.0,
                                        0.5, 1.0, 0.5, 1.0, 1.0, 0.5,
                                        0.5, 2.0, 1.0, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::PSYCHIC:   this->SetDamageValues(
                                        1.0, 0.25, 1.0, 0.5, 2.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 0.5
                                  );
                                  break;

    case PokemonTypes::ICE:	      this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 0.5,
                                        1.0, 2.0, 0.5, 1.0, 1.0, 0.5
                                  );
                                  break;

    case PokemonTypes::DRAGON:    this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                                        0.5, 1.0, 1.0, 0.5, 0.5, 0.25,
                                        0.5, 2.0, 2.0, 2.0, 1.0, 1.0
                                  );
                                  break;

    case PokemonTypes::DARK:	  this->SetDamageValues(
                                        1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
                                        1.0, 0.5, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 0.0, 1.0, 1.0, 0.5, 1.0
                                  );
                                  break;

    case PokemonTypes::FAIRY:	  this->SetDamageValues(
                                        1.0, 0.25, 1.0, 1.0, 2.0, 1.0,
                                        0.25, 1.0, 2.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 0.0, 0.5, 0.5
                                  );
                                  break;
    }
}

void PokemonWeakness::PsychicTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:    this->SetDamageValues(
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 0.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::FIGHTING:  this->SetDamageValues(
                                        1.0, 0.5, 2.0, 1.0, 1.0, 0.5,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 2.0
                                  );
                                  break;

    case PokemonTypes::FLYING:    this->SetDamageValues(
                                        1.0, 0.25, 1.0, 1.0, 0.0, 2.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        2.0, 0.5, 2.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::POISON:    this->SetDamageValues(
                                        1.0, 0.25, 1.0, 0.5, 2.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 0.5
                                  );
                                  break;

    case PokemonTypes::GROUND:    this->SetDamageValues(
                                        1.0, 0.5, 1.0, 0.5, 1.0, 0.5,
                                        2.0, 2.0, 1.0, 1.0, 2.0, 2.0,
                                        0.0, 0.5, 2.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::ROCK:	  this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.5, 2.0, 1.0,
                                        2.0, 2.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::BUG:       this->SetDamageValues(
                                        1.0, 0.25, 2.0, 1.0, 0.5, 2.0,
                                        2.0, 2.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::GHOST:	  this->SetDamageValues(
                                        0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                        1.0, 4.0, 1.0, 1.0, 1.0, 1.0,
                                        1.0, 0.5, 1.0, 1.0, 4.0, 1.0
                                  );
                                  break;

    case PokemonTypes::STEEL:	  this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                                        1.0, 2.0, 0.5, 2.0, 1.0, 0.5,
                                        1.0, 0.25, 0.5, 0.5, 2.0, 0.5
                                  );
                                  break;

    case PokemonTypes::FIRE:      this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 2.0, 2.0,
                                        1.0, 2.0, 0.5, 0.5, 2.0, 0.5,
                                        1.0, 0.5, 0.5, 1.0, 2.0, 0.5
                                  );
                                  break;

    case PokemonTypes::WATER:	  this->SetDamageValues(
                                        1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 2.0, 0.5, 0.5, 0.5, 2.0,
                                        2.0, 0.5, 0.5, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::GRASS:	  this->SetDamageValues(
                                        1.0, 0.5, 2.0, 2.0, 0.5, 1.0,
                                        4.0, 2.0, 1.0, 2.0, 0.5, 1.0,
                                        0.5, 0.5, 2.0, 1.0, 2.0, 1.0
                                  );
                                  break;

    case PokemonTypes::ELECTRIC: this->SetDamageValues(
                                    1.0, 0.5, 0.5, 1.0, 2.0, 1.0,
                                    2.0, 2.0, 0.5, 1.0, 1.0, 1.0,
                                    0.5, 0.5, 1.0, 1.0, 2.0, 1.0
                                 );
                                 break;

    case PokemonTypes::PSYCHIC:  this->SetDamageValues(
                                    1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                    2.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                    1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ICE:	     this->SetDamageValues(
                                    1.0, 1.0, 1.0, 1.0, 1.0, 2.0,
                                    2.0, 2.0, 2.0, 2.0, 1.0, 1.0,
                                    1.0, 0.5, 0.5, 1.0, 2.0, 1.0
                                 );
                                 break;

    case PokemonTypes::DRAGON:   this->SetDamageValues(
                                    1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                    2.0, 2.0, 1.0, 0.5, 0.5, 0.5,
                                    0.5, 0.5, 2.0, 2.0, 2.0, 2.0
                                 );
                                 break;

    case PokemonTypes::DARK:	 this->SetDamageValues(
                                    1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                    4.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                    1.0, 0.0, 1.0, 1.0, 1.0, 2.0
                                 );
                                 break;

    case PokemonTypes::FAIRY:	 this->SetDamageValues(
                                    1.0, 0.25, 1.0, 2.0, 1.0, 1.0,
                                    1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
                                    1.0, 0.5, 1.0, 0.0, 1.0, 1.0
                                 );
                                 break;
    }
}

void PokemonWeakness::RockTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:   this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                                        1.0, 0.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::FIGHTING: this->SetDamageValues(
                                        0.5, 2.0, 1.0, 0.5, 2.0, 0.5,
                                        0.5, 1.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 2.0, 1.0, 1.0, 0.5, 2.0
                                 );
                                 break;

    case PokemonTypes::FLYING:   this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.5, 0.0, 2.0,
                                        0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::POISON:   this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.25, 4.0, 1.0,
                                        0.5, 1.0, 2.0, 0.5, 2.0, 1.0,
                                        1.0, 2.0, 1.0, 1.0, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::GROUND:   this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.25, 2.0, 0.5,
                                        1.0, 1.0, 2.0, 0.5, 4.0, 4.0,
                                        0.0, 1.0, 2.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ROCK:	 this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                                        1.0, 1.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::BUG:      this->SetDamageValues(
                                        0.5, 1.0, 1.0, 0.5, 1.0, 2.0,
                                        1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
                                        1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::GHOST:	 this->SetDamageValues(
                                        0.0, 0.0, 0.5, 0.25, 2.0, 1.0,
                                        0.5, 2.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 2.0, 1.0
                                 );
                                 break;

    case PokemonTypes::STEEL:    this->SetDamageValues(
                                        0.25, 4.0, 0.25, 0.0, 4.0, 0.5,
                                        0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                                        1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::FIRE:	 this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.5, 4.0, 2.0,
                                        0.5, 1.0, 1.0, 0.25, 4.0, 1.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::WATER:	 this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                                        1.0, 1.0, 1.0, 0.25, 1.0, 4.0,
                                        2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::GRASS:	 this->SetDamageValues(
                                        0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
                                        2.0, 1.0, 2.0, 1.0, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ELECTRIC: this->SetDamageValues(
                                        0.5, 2.0, 0.25, 0.5, 4.0, 1.0,
                                        1.0, 1.0, 1.0, 0.5, 2.0, 2.0,
                                        0.5, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::PSYCHIC:  this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.5, 2.0, 1.0,
                                        2.0, 2.0, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 0.5, 1.0, 1.0, 2.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ICE:	     this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 4.0, 1.0, 2.0, 2.0,
                                        1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::DRAGON:   this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                                        1.0, 1.0, 2.0, 0.25, 1.0, 1.0,
                                        0.5, 1.0, 2.0, 2.0, 1.0, 2.0
                                 );
                                 break;

    case PokemonTypes::DARK:	 this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.5, 2.0, 1.0,
                                        2.0, 0.5, 2.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 1.0, 0.5, 2.0
                                 );
                                 break;

    case PokemonTypes::FAIRY:	 this->SetDamageValues(
                                        0.5, 1.0, 0.5, 1.0, 2.0, 1.0,
                                        0.5, 1.0, 4.0, 0.5, 2.0, 2.0,
                                        1.0, 1.0, 1.0, 0.0, 0.5, 1.0
                                 );
                                 break;
    }
}

void PokemonWeakness::SteelTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:   this->SetDamageValues(
                                        0.5, 4.0, 0.5, 0.0, 2.0, 0.5,
                                        0.5, 0.0, 1.0, 2.0, 1.0, 0.5,
                                        1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::FIGHTING: this->SetDamageValues(
                                        0.5, 2.0, 1.0, 0.0, 2.0, 0.25,
                                        0.25, 1.0, 0.5, 2.0, 1.0, 0.5,
                                        1.0, 1.0, 0.5, 0.5, 0.5, 1.0
                                 );
                                 break;

    case PokemonTypes::FLYING:   this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.0, 0.0, 1.0,
                                        0.5, 1.0, 0.5, 2.0, 1.0, 0.5,
                                        2.0, 0.5, 1.0, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::POISON:   this->SetDamageValues(
                                        0.5, 1.0, 0.5, 0.0, 4.0, 0.5,
                                        1.0, 1.0, 0.5, 2.0, 1.0, 1.0,
                                        1.0, 1.0, 0.5, 0.5, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::GROUND:   this->SetDamageValues(
                                        0.5, 2.0, 0.5, 0.0, 2.0, 0.25,
                                        0.5, 1.0, 0.5, 2.0, 2.0, 1.0,
                                        0.0, 0.5, 1.0, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::ROCK:	 this->SetDamageValues(
                                    0.25, 4.0, 0.25, 0.0, 4.0, 0.5,
                                    0.5, 1.0, 1.0, 1.0, 2.0, 1.0,
                                    1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::BUG:      this->SetDamageValues(
                                    0.5, 1.0, 1.0, 0.0, 1.0, 1.0,
                                    0.5, 1.0, 0.5, 4.0, 1.0, 0.25,
                                    1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::GHOST:	 this->SetDamageValues(
                                    0.0, 0.0, 0.5, 0.0, 2.0, 0.5,
                                    0.25, 2.0, 0.5, 2.0, 1.0, 0.5,
                                    1.0, 0.5, 0.5, 0.5, 2.0, 0.5
                                 );
                                 break;

    case PokemonTypes::STEEL:	 this->SetDamageValues(
                                    0.5, 2.0, 0.5, 0.0, 2.0, 0.5,
                                    0.5, 1.0, 0.5, 2.0, 1.0, 0.5,
                                    1.0, 0.5, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::FIRE:     this->SetDamageValues(
                                    0.5, 2.0, 0.5, 0.0, 4.0, 1.0,
                                    0.25, 1.0, 0.25, 1.0, 2.0, 0.25,
                                    1.0, 0.5, 0.25, 0.5, 1.0, 0.25
                                 );
                                 break;

    case PokemonTypes::WATER:	 this->SetDamageValues(
                                    0.5, 1.0, 0.5, 0.0, 1.0, 0.5,
                                    0.5, 1.0, 0.25, 1.0, 0.5, 1.0,
                                    1.0, 0.5, 0.25, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::GRASS:    this->SetDamageValues(
                                    0.5, 2.0, 1.0, 0.0, 1.0, 0.5,
                                    1.0, 1.0, 0.5, 4.0, 0.5, 0.25,
                                    0.5, 1.0, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::ELECTRIC: this->SetDamageValues(
                                    0.5, 2.0, 0.25, 0.0, 1.0, 0.5,
                                    0.5, 1.0, 0.25, 2.0, 1.0, 0.5,
                                    0.5, 0.5, 0.5, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::PSYCHIC:  this->SetDamageValues(
                                    0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                                    1.0, 2.0, 0.5, 2.0, 1.0, 0.5,
                                    1.0, 1.0, 0.5, 0.5, 2.0, 0.5
                                 );
                                 break;

    case PokemonTypes::ICE:	     this->SetDamageValues(
                                    0.5, 4.0, 0.5, 0.0, 2.0, 1.0,
                                    0.5, 1.0, 1.0, 4.0, 1.0, 0.5,
                                    1.0, 0.5, 0.25, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::DRAGON:   this->SetDamageValues(
                                    0.5, 2.0, 0.5, 0.0, 2.0, 0.5,
                                    0.5, 1.0, 0.5, 1.0, 0.5, 0.25,
                                    0.5, 0.5, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::DARK:	 this->SetDamageValues(
                                    0.5, 4.0, 0.5, 0.0, 2.0, 0.5,
                                    1.0, 0.5, 0.5, 2.0, 1.0, 0.5,
                                    1.0, 0.0, 0.5, 0.5, 0.5, 1.0
                                 );
                                 break;

    case PokemonTypes::FAIRY:	 this->SetDamageValues(
                                    0.5, 1.0, 0.5, 0.0, 2.0, 0.5,
                                    0.25, 1.0, 1.0, 2.0, 1.0, 0.5,
                                    1.0, 0.5, 0.5, 0.0, 0.5, 0.5
                                 );
                                 break;
    }
}

void PokemonWeakness::WaterTypeDmg(){
    switch(this->secTypeEnum){
    case PokemonTypes::NORMAL:   this->SetDamageValues(
                                    1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                    1.0, 0.0, 0.5, 0.5, 0.5, 2.0,
                                    2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::FIGHTING: this->SetDamageValues(
                                    1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
                                    0.5, 1.0, 0.5, 0.5, 0.5, 2.0,
                                    2.0, 2.0, 0.5, 1.0, 0.5, 2.0
                                 );
                                 break;

    case PokemonTypes::FLYING:   this->SetDamageValues(
                                    1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
                                    0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
                                    4.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::POISON:   this->SetDamageValues(
                                    1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
                                    0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
                                    2.0, 2.0, 0.5, 1.0, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::GROUND:   this->SetDamageValues(
                                    1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
                                    1.0, 1.0, 0.5, 0.5, 1.0, 4.0,
                                    0.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ROCK:	 this->SetDamageValues(
                                    0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
                                    1.0, 1.0, 1.0, 0.25, 1.0, 4.0,
                                    2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::BUG:      this->SetDamageValues(
                                    1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
                                    1.0, 1.0, 0.5, 1.0, 0.5, 1.0,
                                    2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::GHOST:	 this->SetDamageValues(
                                    0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
                                    0.5, 2.0, 0.5, 0.5, 0.5, 2.0,
                                    2.0, 1.0, 0.5, 1.0, 2.0, 1.0
                                 );
                                 break;

    case PokemonTypes::STEEL:	 this->SetDamageValues(
                                    0.5, 2.0, 0.5, 1.0, 2.0, 0.5,
                                    0.5, 1.0, 1.0, 1.0, 0.5, 1.0,
                                    2.0, 0.5, 1.0, 0.5, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::FIRE:	 this->SetDamageValues(
                                    1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                                    0.5, 1.0, 0.25, 0.25, 1.0, 1.0,
                                    2.0, 1.0, 0.25, 1.0, 1.0, 0.5
                                 );
                                 break;

    case PokemonTypes::WATER:	 this->SetDamageValues(
                                    1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                    1.0, 1.0, 0.5, 0.5, 0.5, 2.0,
                                    2.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::GRASS:	 this->SetDamageValues(
                                    1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
                                    2.0, 1.0, 0.5, 1.0, 0.25, 1.0,
                                    1.0, 1.0, 1.0, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ELECTRIC: this->SetDamageValues(
                                    1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
                                    1.0, 1.0, 0.25, 0.5, 0.5, 2.0,
                                    1.0, 1.0, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::PSYCHIC:  this->SetDamageValues(
                                    1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
                                    2.0, 2.0, 0.5, 0.5, 0.5, 2.0,
                                    2.0, 0.5, 0.5, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::ICE:	     this->SetDamageValues(
                                    1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
                                    1.0, 1.0, 1.0, 1.0, 0.5, 2.0,
                                    2.0, 1.0, 0.25, 1.0, 1.0, 1.0
                                 );
                                 break;

    case PokemonTypes::DRAGON:   this->SetDamageValues(
                                    1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                                    1.0, 1.0, 0.5, 0.25, 0.25, 1.0,
                                    1.0, 1.0, 1.0, 2.0, 1.0, 2.0
                                 );
                                 break;

    case PokemonTypes::DARK:	 this->SetDamageValues(
                                    1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
                                    2.0, 0.5, 0.5, 0.5, 0.5, 2.0,
                                    2.0, 0.0, 0.5, 1.0, 0.5, 2.0
                                 );
                                 break;

    case PokemonTypes::FAIRY:	 this->SetDamageValues(
                                    1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
                                    0.5, 1.0, 1.0, 0.5, 0.5, 2.0,
                                    2.0, 1.0, 0.5, 0.0, 0.5, 1.0
                                 );
                                 break;
    }
}

void PokemonWeakness::CalcDamageTaken(){
    switch(this->priTypeEnum){
    case PokemonTypes::NORMAL:      this->NormalTypeDmg();
                                    break;

    case PokemonTypes::FIGHTING:    this->FightingTypeDmg();
                                    break;

    case PokemonTypes::FLYING:      this->FlyingTypeDmg();
                                    break;

    case PokemonTypes::POISON:      this->PoisonTypeDmg();
                                    break;

    case PokemonTypes::GROUND:      this->GroundTypeDmg();
                                    break;

    case PokemonTypes::ROCK:		this->RockTypeDmg();
                                    break;

    case PokemonTypes::BUG:         this->BugTypeDmg();
                                    break;

    case PokemonTypes::GHOST:		this->GhostTypeDmg();
                                    break;

    case PokemonTypes::STEEL:		this->SteelTypeDmg();
                                    break;

    case PokemonTypes::FIRE:		this->FireTypeDmg();
                                    break;

    case PokemonTypes::WATER:		this->WaterTypeDmg();
                                    break;

    case PokemonTypes::GRASS:		this->GrassTypeDmg();
                                    break;

    case PokemonTypes::ELECTRIC:	this->ElectricTypeDmg();
                                    break;

    case PokemonTypes::PSYCHIC:     this->PsychicTypeDmg();
                                    break;

    case PokemonTypes::ICE:         this->IceTypeDmg();
                                    break;

    case PokemonTypes::DRAGON:      this->DragonTypeDmg();
                                    break;

    case PokemonTypes::DARK:		this->DarkTypeDmg();
                                    break;

    case PokemonTypes::FAIRY:		this->FairyTypeDmg();
                                    break;
    }
}

string PokemonWeakness::PrintWeaknesses() const
{
    std::ostringstream weaknesses;              //OUT  - the weaknesses

    unsigned int index;

    weaknesses << "\nDamage Taken:\n";

    weaknesses << std::left;

    for(index = NORMAL; index < globalWeakConsts::MAX_TYPES; ++index)
    {
        weaknesses << std::setw(globalWeakConsts::TYPE_COL)
                   << globalWeakConsts::TYPES[index] << ": *"
                   << damageAr[index] << std::endl;
    }

    weaknesses << std::right;

    return (weaknesses.str());
}
