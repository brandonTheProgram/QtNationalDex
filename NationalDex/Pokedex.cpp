#include "Pokedex.h"

/************************************************************************
* Method Pokedex: Class Pokedex
*----------------------------------------------------------------------
* 	 This method creates the Pokedex object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Pokedex::Pokedex()
{
    pokedex    .clear();
    attackDex  .clear();
    pokedexCopy.clear();
    pokedex    .reserve(globalPDexConsts::AR_SIZE);
    pokedexCopy.reserve(globalPDexConsts::AR_SIZE);
    attackDex  .reserve(globalPDexConsts::MAX_ATTKS);
}

/************************************************************************
* Method ~Pokedex: Class Pokedex
*----------------------------------------------------------------------
* 	 This method deletes the Pokedex object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Pokedex::~Pokedex()
{
    pokedex.clear();
    attackDex.clear();
    pokedexCopy.clear();

    vector<Pkmn>().swap(pokedex);
    vector<Attack>().swap(attackDex);
    vector<Pokemon>().swap(pokedexCopy);
}

/************************************************************************
* Method CreateAttackList: Class Pokedex
*----------------------------------------------------------------------
* 	 This method creates the attackdex
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		INPUT_FILE (string) - the input file
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Pokedex::CreateAttackList(const string& INPUT_FILE)
{
    std::ifstream fin(INPUT_FILE.c_str()); //PROC - Open the input file

    int index;							   //PROC - the index in the array

    Attack *attack = new Attack;	       //PROC - create a new attack

    index = 0;

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

        attackDex.push_back(*attack);

        fin.ignore(1000, '\n');
        fin.ignore(1000, '\n');

        attack = new Attack;

        index++;
    }

    delete attack;
    attack = nullptr;

    fin.close();
}

/************************************************************************
* Method CreatePokedexCopy: Class Pokedex
*----------------------------------------------------------------------
* 	 This method creates a copy of the Pokedex with only a Pokemon and
* 	 	not attacks or weaknesses
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Pokedex::CreatePokedexCopy()
{
    for(auto it: pokedex)
    {
        //PROCESSING - Add only the Pokemon to the list
        pokedexCopy.push_back(it.currentPkmn);
    }
}

/************************************************************************
* Method LoadRegion: Class Pokedex
*----------------------------------------------------------------------
* 	 This method loads in one region at a time and initializes the Pokedex
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		INPUT_FILE  (string) - The name of the input file
* 		REGION_MAX  (int)    - The max number of Pokemon available in the region
* 		ATTACK_FILE (string) - The name of the attack file for the region
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Pokedex::LoadRegion(const string& INPUT_FILE, const int& REGION_MAX,
                         const string& ATTACK_FILE)
{
    static int pokdexIndex = 0;                   //PROC - the position in
                                                  //	   in vector

    std::ifstream fin(INPUT_FILE.c_str());        //IN   - the input file
                                                  //       variable

    std::ifstream attackFin(ATTACK_FILE.c_str()); //IN   - the attack
                                                  //       file variable

    vector<string> attackNames;					  //PROC - the names of the
                                                  //       attacks
    vector<int> attackLvls;						  //PROC - the levels of the
                                                  //       attacks

    Pkmn *newPokemon = new Pkmn;				  //PROC - Create a new Pokemon

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

        //PROCESSING - Load in the Pokemon's moves
        LoadPokemonMoves(attackFin, attackNames, attackLvls);

        //PROCESSING - Initialize the Pokemon's moves
        newPokemon->pkmnMoves.InitializeMoveSets
                                (attackDex, attackNames, attackLvls);

        //PROCESSING - Store the Pokemon in the vector
        pokedex.push_back(*newPokemon);

        //PROCESSING - Clear the arrays for reuse and deallocate memory
        attackNames.clear();
        attackLvls.clear();

        vector<string>().swap(attackNames);
        vector<int>().swap(attackLvls);

        newPokemon = new Pkmn;

        pokdexIndex++;
    }

    delete newPokemon;

    //Close the input files
    fin.close();
    attackFin.close();
}

/************************************************************************
* Method LoadPokemonMoves: Class Pokedex
*----------------------------------------------------------------------
* 	 This method loads the Pokemon's moves
* 	 ==> returns attackNames and attackLvls
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		fin         (ifstream)       - the input file variable
*   	attackNames (vector<string>) - the list of attack names
*   	attackLvls  (vector<int>)    - the list of attack levels
*
* POST-CONDITIONS
* 	==> returns attackNames and attackLvls
*************************************************************************/
void Pokedex::LoadPokemonMoves(std::ifstream& fin, vector<string>& attackNames,
                               vector<int>& attackLvls)
{
    string pokemonName;	//PROC - The name of the Pokemon
    string attackName;  //PROC - The name of the attack

    int moveListSize;   //PROC - The amount of moves the Pokemon knows
    int    attackLvl;	//PROC - The level of the attack

    getline(fin, pokemonName);

    fin >> moveListSize;

    attackNames.reserve(moveListSize);
    attackLvls.reserve(moveListSize);

    for(int index = 0; index < moveListSize; index++)
    {
        fin >> attackLvl;
        fin.ignore(1000, ' ');
        getline(fin, attackName);

        attackNames.push_back(attackName);
        attackLvls.push_back(attackLvl);
    }

    fin.ignore(1000, '\n');
}

/************************************************************************
* Method SetEvolutions: Class Pokedex
*----------------------------------------------------------------------
* 	 This method sets the evolutions to every Pokemon
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Pokedex::SetEvolutions()
{
    for(auto& it: pokedex)
    {
        //If the pokemon has an evloution, then set it
        if(it.currentPkmn.GetEvolutions() != 0)
        {
            it.pkmnEvos.SetInitialValues(pokedexCopy, it.currentPkmn);
        }
    }
}

/************************************************************************
* Method GetRegion: Class Pokedex
*----------------------------------------------------------------------
* 	 This gets a region range of Pokemon from the Pokedex
* 	 ==> returns a vector of the Pokemon specified
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		START  (int) - the starting index of the region
*   	END    (int) - the ending index of the region
*   	attackLvls  (vector<int>)    - the list of attack levels
*
* POST-CONDITIONS
* 	==> returns a vector of the Pokemon specified
*************************************************************************/
vector<Pkmn> Pokedex::GetRegion(const int &START, const int &END) const
{
    vector<Pkmn> regionVec; //PROC - The vector that will be returned

    for (int index = START; index < END;index++)
    {
        regionVec.push_back(pokedex[index]);
    }

    return regionVec;
}
