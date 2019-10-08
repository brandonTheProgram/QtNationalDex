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

        //If the Pokemon has a second evolution, then store it
        if(mainPokemon.GetEvolutions() == 2){
            this->secondEvo 	= POKEDEX[mainPokemon.GetSecondEvoNum() - 1];
            this->finalEvo  	= POKEDEX[mainPokemon.GetFinalEvoNum() - 1];
        }

        //If the Pokemon is not a special branch pokemon like Eevee which has
        //multiple final evolution forms, then store it
        else if(mainPokemon.GetEvolutions() == 1){
            this->finalEvo = POKEDEX[mainPokemon.GetFinalEvoNum() - 1];
        }

        //If the Pokemon only has one branch evo, then store it
        else if(mainPokemon.GetBranchEvo() == true &&
                mainPokemon.GetEvolutions() <= 2){
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

        //If the Pokemon has a second evolution, then store it
        if(mainPokemon.GetEvolutions() == 2){
            this->secondEvo 	= POKEDEX[mainPokemon.GetSecondEvoNum() - 1];
            this->finalEvo  	= POKEDEX[mainPokemon.GetFinalEvoNum() - 1];
        }

        //If the Pokemon is not a special branch pokemon like Eevee which has
        //multiple final evolution forms, then store it
        else if(mainPokemon.GetEvolutions() == 1){
            this->finalEvo = POKEDEX[mainPokemon.GetFinalEvoNum() - 1];
        }

        //If the Pokemon only has one branch evo, then store it
        else if(mainPokemon.GetBranchEvo() && mainPokemon.GetEvolutions() <= 2){
            this->branchEvo = POKEDEX[mainPokemon.GetBranchEvoNum() - 1];
        }
    }
}

//Return the evolution tree as a string
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

    return (evoString);
}

//Return the evolution tree as a string for pokemon with 2 evolutions
string PokemonEvolutions::PrintTwoEvos() const
{
    std::ostringstream evoTree; //PROC & OUT - The evolution tree

    //PROCESSING - If the pokemon is the first evolution
    evoTree << firstEvo.GetName() << " evolves by ";

    //PROCESSING - If the Pokemon evolves through special conditions
    if((firstEvo.GetEvoThroughLvl()  == true   &&
        firstEvo.GetEvoThroughCond() == true)  ||
       (firstEvo.GetEvoThroughLvl()  == false  &&
        firstEvo.GetEvoThroughCond() == true)){
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
        if((branchEvo.GetEvoThroughLvl()  == true    &&
            branchEvo.GetEvoThroughCond() == true)   ||
           (branchEvo.GetEvoThroughLvl()  == false   &&
            branchEvo.GetEvoThroughCond() == true)){
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

//Return the evolution tree as a string for pokemon with 3 evolutions
string PokemonEvolutions::PrintThreeEvos() const
{
    std::ostringstream evoTree; //PROC & OUT - The evolution tree

    evoTree << firstEvo.GetName() << " evolves by ";

    //If the first evolution evolves through leveling and condition
    //or just condition
    if((firstEvo.GetEvoThroughLvl()  == true   &&
        firstEvo.GetEvoThroughCond() == true)  ||
       (firstEvo.GetEvoThroughLvl()  == false  &&
        firstEvo.GetEvoThroughCond() == true)){
            evoTree << firstEvo.GetSecondEvoCond();
    }

    //If the first evolution evolves through leveling and not condition
    else if(firstEvo.GetEvoThroughLvl()  == true &&
            firstEvo.GetEvoThroughCond() == false){
        evoTree << "leveling up to level " << firstEvo.GetEvoLvl();
    }

    else{
        evoTree << "\nERROR\n";
    }

    evoTree << " into " << secondEvo.GetName() << " then by ";

    //If the second evolution evolves through leveling and condition
    //or just condition
    if((secondEvo.GetEvoThroughLvl()  == true   &&
        secondEvo.GetEvoThroughCond() == true)  ||
       (secondEvo.GetEvoThroughLvl()  == false  &&
        secondEvo.GetEvoThroughCond() == true)){
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

        if((branchEvo.GetEvoThroughLvl() == true     &&
            branchEvo.GetEvoThroughCond() == true)   ||
           (branchEvo.GetEvoThroughLvl()  == false   &&
            branchEvo.GetEvoThroughCond() == true)){
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
    unsigned int index = 0;			//PROC       - The index in the array

    bool specialBranchs = false;	//PROC       - The condition if the Pokemon
                                    //             is a special branch with more
                                    //             evolutions than normal(>2)

    std::ostringstream evoTree;     //PROC & OUT - The evolution tree

    string functionString;          //PROC & OUT - The string containing the
                                    //             fucntion called

    //PROCESSING - Store the value of the size of the vector
    auto vsize = globalPkmEvoConsts::SPECIAL_BRANCHE_EVOS.size();

    //PROCESSING - Loop through to find if the specificed pokemon has a unique
    //			   branch evolutions
    while(index < vsize && !specialBranchs){
        //If the Pokemon is a special branch evolution, then print their
        //specific information
        if(mainPokemon.GetPokedexNumber() ==
                globalPkmEvoConsts::SPECIAL_BRANCHE_EVOS[index]){
            functionString = PrintSpecialEvosBranch();
            specialBranchs = true;
        }
        ++index;
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
    using namespace globalPkmEvoConsts; //The vectors of the special
                                        //Pokemon pokedex numbers

    std::ostringstream evoTree;     //PROC & OUT - The evolution tree

    int wurmpleEvoIndex;            //PROC - The index in the Wurmple Vector
    int tyroEvoIndex;               //PROC - The index in the Tyrogue Vector
    int eeveeEvoIndex;              //PROC - The index in the Eevee Vector

    bool continueChecking = true;	//PROC - The condition to keep checking
    bool wurmpleFamily    = false;	//PROC - The index in the Eevee Vector
    bool tyrogueFamily    = false;  //PROC - The index in the Eevee Vector
    bool eeveeFamily      = false;  //PROC - The index in the Eevee Vector
    bool firstRun         = true;   //PROC - The index in the Eevee Vector

    //PROCESSING - Check if the pokemon is part of the Wurmple family
    for(auto wurmpleIt: WURPLE_EVOLUTIONS){
        if(continueChecking == true){
            if(mainPokemon.GetPokedexNumber() == (int(wurmpleIt))){
                wurmpleFamily    = true;
                continueChecking = false;
            }
        }
    }

    if(continueChecking == true){
        //PROCESSING - Check if the pokemon is part of the Tyrogue family
        for(auto tyrogueIt: TYROGUE_EVOLUTIONS){
            if(continueChecking == true){
                if(mainPokemon.GetPokedexNumber() == (int(tyrogueIt))){
                    tyrogueFamily    = true;
                    continueChecking = false;
                }
            }
        }
    }

    if(continueChecking == true){
        //PROCESSING - Check if the pokemon is part of the Eevee family
        for(auto eeveeIt: EEVEELUTIONS){
            if(continueChecking == true){
                if(mainPokemon.GetPokedexNumber() == (int(eeveeIt))){
                    eeveeFamily      = true;
                    continueChecking = false;
                }
            }
        }
    }

    //OUTPUT - Print the information in the Wurmple family
    if(wurmpleFamily == true){
        //Check the wurmple evolutions
        for(auto it: WURPLE_EVOLUTIONS){
            if(firstRun == true && (mainPokemon.GetPokedexNumber() !=
               WURPLE_EVOLUTIONS[0])){
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
            if(firstRun == true && (mainPokemon.GetPokedexNumber() !=
               TYROGUE_EVOLUTIONS[0])){
                evoTree << "Tyrogue - first evolution\n\n";
                firstRun = false;
            }

            tyroEvoIndex = (int(it) - 1);

            //If the Pokemon is not Tyrogue, then output how to obtain it
            if(tyroEvoIndex != (TYROGUE_EVOLUTIONS[0] - 1)){
                evoTree << pokedexCopy[tyroEvoIndex].GetName()
                        << " obtained by ";

                if((pokedexCopy[tyroEvoIndex].GetEvoThroughCond() == true  &&
                    pokedexCopy[tyroEvoIndex].GetEvoThroughLvl()  == true) ||
                   (pokedexCopy[tyroEvoIndex].GetEvoThroughCond() == true  &&
                    pokedexCopy[tyroEvoIndex].GetEvoThroughLvl()  == false)){
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
            if(firstRun == true && (mainPokemon.GetPokedexNumber() !=
               EEVEELUTIONS[0])){
                evoTree << "Eevee - first evolution\n\n";
                firstRun = false;
            }

            eeveeEvoIndex = (int(it) - 1);

            //If the Pokemon is not Eevee, then output how to obtain it
            if(eeveeEvoIndex != (EEVEELUTIONS[0] - 1)){
                evoTree << pokedexCopy[eeveeEvoIndex].GetName() << " obtained by ";

                if((pokedexCopy[eeveeEvoIndex].GetEvoThroughCond() == true  &&
                    pokedexCopy[eeveeEvoIndex].GetEvoThroughLvl()  == true) ||
                   (pokedexCopy[eeveeEvoIndex].GetEvoThroughCond() == true  &&
                    pokedexCopy[eeveeEvoIndex].GetEvoThroughLvl()  == false)){
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
