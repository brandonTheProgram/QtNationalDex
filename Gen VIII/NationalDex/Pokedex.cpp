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
    std::ifstream fin(INPUT_FILE.c_str()); //PROC - Open the input file

    int index = 0;						   //PROC - the index in the array

    Attack *attack = new Attack;           //PROC - create a new attack

    //PROCESSING - While not at the end of the file and not out of space,
    //             load in every move and add it to the list
    while(!fin.eof() && (index < globalPDexConsts::MAX_ATTKS))
    {
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

void Pokedex::LoadRegion(const string& INPUT_FILE, const int& REGION_MAX,
                         const string& ATTACK_FILE){
    static int     pokdexIndex = 0;                       //PROC - the position in
                                                   //	    in vector

    std::ifstream  fin(INPUT_FILE.c_str());        //IN   - the input file
                                                   //       variable

    std::ifstream  attackFin(ATTACK_FILE.c_str()); //IN   - the attack
                                                   //       file variable

    vector<string> attackNames;					   //PROC - the names of the
                                                   //       attacks
    vector<int>    attackLvls;				       //PROC - the levels of the
                                                   //       attacks

    Pkmn *newPokemon = new Pkmn;                   //PROC - Create a new Pokemon

    //While not at the end of the file and the index doesn't exceed the max
    //number of Pokemon available in the region
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
        vector<int>   ().swap(attackLvls);

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
                               vector<int>& attackLvls){
    string pokemonName;	 //PROC - The name of the Pokemon
    string attackName;   //PROC - The name of the attack

    int    moveListSize; //PROC - The amount of moves the Pokemon knows
    int    attackLvl;	 //PROC - The level of the attack

    getline(fin, pokemonName);

    fin >> moveListSize;

    if(moveListSize == 0){
        fin.ignore(1000, '\n');
    }
    else{
        attackNames.reserve(moveListSize);
        attackLvls .reserve(moveListSize);

        for(int index = 0; index < moveListSize; ++index){
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

vector<Pkmn> Pokedex::GetRegion(const int &START, const int &END) const{
    vector<Pkmn> regionVec; //PROC - The vector that will be returned

    for(int index = START; index < END;index++){
        regionVec.push_back(pokedex[index]);
    }

    return regionVec;
}
