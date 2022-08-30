#include "Pokedex.h"

Pokedex::Pokedex(){
    this->pokedex    .reserve(globalPDexConsts::AR_SIZE);
    this->pokedexCopy.reserve(globalPDexConsts::AR_SIZE);
    this->attackDex  .reserve(globalPDexConsts::MAX_ATTKS);
}

Pokedex::~Pokedex(){
    vector<Pkmn>()    .swap(this->pokedex);
    vector<Attack>()  .swap(this->attackDex);
    vector<Pokemon>() .swap(this->pokedexCopy);

    this->pokedex     .clear();
    this->attackDex   .clear();
    this->pokedexCopy .clear();
}

void Pokedex::CreateAttackList(const string& INPUT_FILE){
    std::ifstream fin(INPUT_FILE.c_str());

    unsigned int index = 0;

    Attack *attack = new Attack;

    while(!fin.eof() && (index < globalPDexConsts::MAX_ATTKS)){
        getline(fin, attack->name);
        getline(fin, attack->desc);
        getline(fin, attack->type);
        getline(fin, attack->category);
        fin >> attack->pwr;
        fin >> attack->acc;
        fin >> attack->pp;
        fin >> attack->effRate;
        fin >> attack->TM;
        fin >> attack->TMNum;
        fin >> attack->TR;
        fin >> attack->TRNum;

        this->attackDex.push_back(*attack);

        fin.ignore(1000, '\n');
        fin.ignore(1000, '\n');

        attack = new Attack;

        ++index;
    }

    delete attack;
    attack = nullptr;

    fin.close();
}

void Pokedex::CreatePokedexCopy(){
    for(auto it: pokedex){pokedexCopy.push_back(it.currentPkmn);}
}

void Pokedex::LoadRegion(const string& INPUT_FILE,
                         const int unsigned& REGION_MAX,
                         const string& ATTACK_FILE){
    static int unsigned pokdexIndex = 0;

    std::ifstream  fin(INPUT_FILE.c_str());

    std::ifstream  attackFin(ATTACK_FILE.c_str());

    vector<string> attackNames;

    vector<unsigned int> attackLvls;

    Pkmn *newPokemon = new Pkmn;

    while(!fin.eof() && pokdexIndex < REGION_MAX)
    {
        //INPUT - Store the information of the Pokemon
        fin >> newPokemon->currentPkmn;

        //PROCESSING - Initialize the Enums using the types
        newPokemon->pkmnWeakness.InitializePriTypeEnum
                                    (newPokemon->currentPkmn.GetPriType());

        newPokemon->pkmnWeakness.InitializeSecTypeEnum
                                    (newPokemon->currentPkmn.GetSecType());

        //PROCESSING - Calculate the damage that the Pokemon would take
        newPokemon->pkmnWeakness.CalcDamageTaken();

        this->LoadPokemonMoves(attackFin, attackNames, attackLvls);

        newPokemon->pkmnMoves.InitializeMoveSets
                              (attackDex, attackNames, attackLvls);

        this->pokedex.push_back(*newPokemon);

        //PROCESSING - Clear the arrays for reuse and deallocate memory
        vector<string>().swap(attackNames);
        vector<unsigned int>   ().swap(attackLvls);

        attackNames.clear();
        attackLvls .clear();

        newPokemon = new Pkmn;

        ++pokdexIndex;
    }

    delete newPokemon;
    newPokemon = nullptr;

    //Close the input files
    fin      .close();
    attackFin.close();
}

void Pokedex::LoadPokemonMoves(std::ifstream& fin, vector<string>& attackNames,
                               vector<unsigned int>& attackLvls){
    string pokemonName;
    string attackName;

    unsigned int moveListSize;
    unsigned int attackLvl;

    getline(fin, pokemonName);

    fin >> moveListSize;

    if(moveListSize == 0){
        fin.ignore(1000, '\n');
    }
    else{
        attackNames.reserve(moveListSize);
        attackLvls .reserve(moveListSize);

        for(unsigned int index = 0; index < moveListSize; ++index){
            fin >> attackLvl;
            fin.ignore(1000, ' ');
            getline(fin, attackName);

            attackNames.push_back(attackName);
            attackLvls .push_back(attackLvl);
        }
    }

    fin.ignore(1000, '\n');
}

void Pokedex::SetEvolutions(){
    for(auto& it: pokedex){
        //If the pokemon has an evloution, then set it
        if(it.currentPkmn.GetEvolutions() != 0){
            it.pkmnEvos.SetInitialValues(pokedexCopy, it.currentPkmn);
        }
    }
}

vector<Pkmn> Pokedex::GetRegion(const unsigned int &START,
                                const unsigned int &END) const{
    vector<Pkmn> regionVec; //PROC - The vector that will be returned

    for(unsigned int index = START; index < END;index++){
        regionVec.push_back(pokedex[index]);
    }

    return regionVec;
}
