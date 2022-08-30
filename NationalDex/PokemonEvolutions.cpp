#include "PokemonEvolutions.h"

PokemonEvolutions::PokemonEvolutions(){}

PokemonEvolutions::PokemonEvolutions(const vector<Pokemon>& POKEDEX,
                                     const Pokemon        & CURRENT_POKEMON)
{
    this->mainPokemon = CURRENT_POKEMON;

    //If the pokemon is a special branch evolution with more evolutions
    if(this->mainPokemon.GetEvolutions() > 2){
        pokedexCopy = POKEDEX;
    }
    else{
        this->firstEvo = POKEDEX[mainPokemon.GetFirstEvoNum() - 1];
        this->finalEvo = POKEDEX[mainPokemon.GetFinalEvoNum() - 1];

        //If the Pokemon has a second evolution, then store it
        if(mainPokemon.GetEvolutions() == 2){
            this->secondEvo = POKEDEX[mainPokemon.GetSecondEvoNum() - 1];
        }

        //If the Pokemon only has one branch evo, then store it
        if(mainPokemon.GetBranchEvo()  == true){
            this->branchEvo = POKEDEX[mainPokemon.GetBranchEvoNum() - 1];
        }
    }
}

PokemonEvolutions::~PokemonEvolutions()
{
    vector<Pokemon>().swap(pokedexCopy);

    pokedexCopy.clear();
}

void PokemonEvolutions::SetInitialValues(const vector<Pokemon>& POKEDEX,
                                         const Pokemon        & CURRENT_POKEMON)
{
    this->mainPokemon = CURRENT_POKEMON;

    //If the pokemon is a special branch evolution with more evolutions
    if(this->mainPokemon.GetEvolutions() > 2){
        pokedexCopy = POKEDEX;
    }
    else{
        this->firstEvo = POKEDEX[mainPokemon.GetFirstEvoNum() - 1];
        this->finalEvo = POKEDEX[mainPokemon.GetFinalEvoNum() - 1];

        //If the Pokemon has a second evolution, then store it
        if(mainPokemon.GetEvolutions() == 2){
            this->secondEvo = POKEDEX[mainPokemon.GetSecondEvoNum() - 1];
        }

        //If the Pokemon only has one branch evo, then store it
        if(mainPokemon.GetBranchEvo()  == true){
            this->branchEvo = POKEDEX[mainPokemon.GetBranchEvoNum() - 1];
        }
    }
}

string PokemonEvolutions::PrintEvoTree() const
{
    string evoString;   //PROC - the evolution tree as a single string

    //PROCESSING - If the pokemon has a branch evolution tree, then display that
    if(mainPokemon.GetBranchEvo()){
        evoString = PrintBranchEvos();
    }
    else{
        //PROCESSING - If the pokemon has only one evolution, then display that
        if(mainPokemon.GetEvolutions() == 1){
            evoString = PrintTwoEvos();
        }

        //PROCESSING - If the pokemon has only two evolution, then display that
        else{
            evoString = PrintThreeEvos();
        }
    }

    return evoString;
}

string PokemonEvolutions::PrintTwoEvos() const
{
    std::ostringstream evoTree; //PROC & OUT - The evolution tree

    evoTree << firstEvo.GetName() << " evolves by ";

    //PROCESSING - If the Pokemon evolves through special conditions
    if(firstEvo.GetEvoThroughCond() == true){
            evoTree << firstEvo.GetFinalEvoCond();
    }

    else if(firstEvo.GetEvoThroughLvl()  == true  &&
            firstEvo.GetEvoThroughCond() == false){
        evoTree << "leveling up to level " << firstEvo.GetEvoLvl();
    }

    else{
        evoTree << "\nERROR\n";
    }

    evoTree << " into " << finalEvo.GetName() << ".";

    //If the Pokemon has a branch evolution, then print their information
    if(mainPokemon.GetBranchEvo() == true)
    {
        evoTree << " A branch evolution is available by evolving "
             << firstEvo.GetName() << " by ";

        //PROCESSING - If the Pokemon evolves through special conditions
        if(branchEvo.GetEvoThroughCond() == true){
                evoTree << branchEvo.GetFinalEvoCond();
        }
        else if(branchEvo.GetEvoThroughLvl()  == true &&
                branchEvo.GetEvoThroughCond() == false){
            evoTree << "leveling up to level " << branchEvo.GetFinalEvoLvl();
        }

        else{
            evoTree << "\nERROR\n";
        }

        evoTree << " into " << branchEvo.GetName() << ".";
    }

    return (evoTree.str());
}

string PokemonEvolutions::PrintThreeEvos() const
{
    std::ostringstream evoTree; //PROC & OUT - The evolution tree

    evoTree << firstEvo.GetName() << " evolves by ";

    //PROCESSING - If the Pokemon evolves through special conditions
    if(firstEvo.GetEvoThroughCond() == true){
            evoTree << firstEvo.GetSecondEvoCond();
    }

    else if(firstEvo.GetEvoThroughLvl()  == true &&
            firstEvo.GetEvoThroughCond() == false){
        evoTree << "leveling up to level " << firstEvo.GetEvoLvl();
    }

    else{
        evoTree << "\nERROR\n";
    }

    evoTree << " into " << secondEvo.GetName() << " then by ";

    //PROCESSING - If the Pokemon evolves through special conditions
    if(secondEvo.GetEvoThroughCond() == true){
            evoTree << secondEvo.GetFinalEvoCond();
    }

    //If the second evolution evolves through leveling and not condition
    else if(secondEvo.GetEvoThroughLvl()  == true &&
            secondEvo.GetEvoThroughCond() == false){
        evoTree << "leveling up to level " << secondEvo.GetEvoLvl();
    }

    else{
        evoTree << "\nERROR\n";
    }

    evoTree << " into " << finalEvo.GetName() << ".";

    //If the Pokemon has a branch evolution, then print their information
    if(mainPokemon.GetBranchEvo() == true){
        evoTree << " A branch evolution is available by evolving "
                << secondEvo.GetName() << " by ";

        if(branchEvo.GetEvoThroughCond() == true){
                evoTree << branchEvo.GetFinalEvoCond();
        }

        else if(branchEvo.GetEvoThroughLvl()  == true &&
                branchEvo.GetEvoThroughCond() == false){
            evoTree << "leveling up to level " << branchEvo.GetFinalEvoLvl();
        }

        else{
            evoTree << "\nERROR\n";
        }

        evoTree << " into " << branchEvo.GetName() << ".";
    }

    return (evoTree.str());
}

//Return the evolution tree as a string for pokemon with a branch evolution
string PokemonEvolutions::PrintBranchEvos() const
{
    using namespace globalPkmEvoConsts;

    bool specialBranchs = false;	//PROC       - The condition if the Pokemon
                                    //             is a special branch with more
                                    //             evolutions than normal(>2)

    std::ostringstream evoTree;     //PROC & OUT - The evolution tree

    string functionString;          //PROC & OUT - The string containing the
                                    //             fucntion called

    if((std::find(SPECIAL_BRANCHE_EVOS.begin(), SPECIAL_BRANCHE_EVOS.end(),
        mainPokemon.GetPokedexNumber())) != SPECIAL_BRANCHE_EVOS.end()){
        functionString = PrintSpecialEvosBranch();
        specialBranchs = true;
    }

    //PROCESSING - If the pokemon is not a special branch evo, then print the
    //			   evo branch for that pokemon
    if(specialBranchs == false){
        //PROCESSING - Pokemon with only 2 normal evolutions and 1 branch evo
        if(mainPokemon.GetEvolutions() == 1){
            functionString = PrintTwoEvos();
        }

        //PROCESSING - Pokemon with only 3 normal evolutions and 1 branch evo
        else{
            functionString = PrintThreeEvos();
        }
    }

    evoTree << functionString;

    return (evoTree.str());
}

//Return the evolution tree as a string for pokemon with 2+ branch evos
string PokemonEvolutions::PrintSpecialEvosBranch() const
{
    using namespace globalPkmEvoConsts;

    std::ostringstream evoTree;     //PROC & OUT - The evolution tree

    unsigned int wurmpleEvoIndex;   //PROC - The index in the Wurmple Vector
    unsigned int tyroEvoIndex;      //PROC - The index in the Tyrogue Vector
    unsigned int eeveeEvoIndex;     //PROC - The index in the Eevee Vector

    bool continueChecking = true;	//PROC - The condition to keep checking
    bool wurmpleFamily    = false;	//PROC - The index in the Eevee Vector
    bool tyrogueFamily    = false;  //PROC - The index in the Eevee Vector
    bool eeveeFamily      = false;  //PROC - The index in the Eevee Vector
    bool firstRun         = true;   //PROC - The index in the Eevee Vector

    if((std::find(WURMPLE_EVOLUTIONS.begin(), WURMPLE_EVOLUTIONS.end(),
        mainPokemon.GetPokedexNumber())) != WURMPLE_EVOLUTIONS.end()){
        wurmpleFamily    = true;
        continueChecking = false;
    }

    if(continueChecking){
        if((std::find(TYROGUE_EVOLUTIONS.begin(), TYROGUE_EVOLUTIONS.end(),
            mainPokemon.GetPokedexNumber())) != TYROGUE_EVOLUTIONS.end()){
            tyrogueFamily    = true;
            continueChecking = false;
        }
    }

    if(continueChecking){
        if((std::find(EEVEELUTIONS.begin(), EEVEELUTIONS.end(),
            mainPokemon.GetPokedexNumber())) != EEVEELUTIONS.end()){
            eeveeFamily      = true;
            continueChecking = false;
        }
    }

    //OUTPUT - Print the information in the Wurmple family
    if(wurmpleFamily == true){
        //Check the wurmple evolutions
        for(auto it: WURMPLE_EVOLUTIONS){
            if(firstRun == true){
                evoTree << "Wurmple - first evolution\n\n";
                firstRun = false;
            }

            wurmpleEvoIndex = (int(it) - 1);

            if(pokedexCopy[wurmpleEvoIndex].GetSecondEvo() == true){
                evoTree << pokedexCopy[wurmpleEvoIndex].GetName() << " by "
                     << pokedexCopy[wurmpleEvoIndex].GetSecondEvoCond()
                     << " then leveling up to "
                     << pokedexCopy[wurmpleEvoIndex].GetEvoLvl() << " into "
                     << pokedexCopy[wurmpleEvoIndex + 1].GetName() << ".\n\n";
            }
        }
    }
    //OUTPUT - Print the information in the Tyrogue family
    else if(tyrogueFamily == true){
        for(auto it: TYROGUE_EVOLUTIONS){
            //If the pokemon is not the first evolution in the family
            if(firstRun == true){
                evoTree << "Tyrogue - first evolution\n\n";
                firstRun = false;
            }

            tyroEvoIndex = (int(it) - 1);

            //If the Pokemon is not Tyrogue, then output how to obtain it
            if(tyroEvoIndex != (TYROGUE_EVOLUTIONS[0] - 1)){
                evoTree << pokedexCopy[tyroEvoIndex].GetName()
                        << " obtained by ";

                if(pokedexCopy[tyroEvoIndex].GetEvoThroughCond() == true){
                    evoTree << pokedexCopy[tyroEvoIndex].GetFinalEvoCond()
                         << ".\n\n";
                }
                else if(pokedexCopy[tyroEvoIndex].GetEvoThroughCond() == false
                        &&
                        pokedexCopy[tyroEvoIndex].GetEvoThroughLvl()  == true){
                    evoTree << " leveling up to "
                         << pokedexCopy[tyroEvoIndex].GetEvoLvl() << ".\n\n";
                }
            }
        }
    }
    //OUTPUT - Print the information in the Eevee family
    else if(eeveeFamily == true){
        for(auto it: EEVEELUTIONS){
            //If the pokemon is not the first evolution in the family
            if(firstRun == true){
                evoTree << "Eevee - first evolution\n\n";
                firstRun = false;
            }

            eeveeEvoIndex = (int(it) - 1);

            //If the Pokemon is not Eevee, then output how to obtain it
            if(eeveeEvoIndex != (EEVEELUTIONS[0] - 1)){
                evoTree << pokedexCopy[eeveeEvoIndex].GetName() << " obtained by ";

                if(pokedexCopy[eeveeEvoIndex].GetEvoThroughCond() == true){
                    evoTree << pokedexCopy[eeveeEvoIndex].GetFinalEvoCond()
                         << ".\n\n";
                }
                else if(pokedexCopy[eeveeEvoIndex].GetEvoThroughCond() == false
                        &&
                        pokedexCopy[eeveeEvoIndex].GetEvoThroughLvl()  == true){
                    evoTree << " leveling up to "
                         << pokedexCopy[eeveeEvoIndex].GetEvoLvl() << ".\n\n";
                }
            }
        }
    }
    return evoTree.str();
}
