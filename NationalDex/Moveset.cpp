#include "Moveset.h"

Moveset::Moveset(){}

Moveset::Moveset(const vector<Attack>& ATTACK_DEX,
                 const vector<string>& MOVES,
                 const vector<int>   & LVLS){
    int index      = 0;           //PROC - The index in the array
    int levelIndex = 0;           //PROC - The index in the level array

    bool found     = false;       //PROC - The condition if the move was found

    LvlAttack newAttack;          //PROC - The attack with a level

    auto size = ATTACK_DEX.size(); //PROC - The size of the attackdex

    //PROCESSING - for every move that the Pokemon has, find it in the
    //			   attackdex and store it as a TM move or a level move
    for(auto moveIt: MOVES){
        while(!found && (index != signed(size))){
            if(!(ATTACK_DEX[index].name.compare(moveIt))){

                //If the move found is a TM, store it
                if((ATTACK_DEX[index].TM == 1) && (LVLS[levelIndex] == 0)){
                    this->TMMoveset.push_back(ATTACK_DEX[index]);
                }
                //If the move is a level move, then store the level and attack
                else{
                    newAttack.attack = ATTACK_DEX[index];
                    newAttack.lvl    = LVLS      [levelIndex];

                    this->lvlMoveset.push_back(newAttack);

                    levelIndex++;
                }

                found = true;
            }
            else{
                ++index;
            }
        }
        index = 0;
        found = false;
    }
}

Moveset::~Moveset(){
    vector<LvlAttack>().swap(this->lvlMoveset);
    vector<Attack>   ().swap(this->TMMoveset);

    this->lvlMoveset.clear();
    this->TMMoveset .clear();
}

void Moveset::InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                 const vector<string>& MOVES,
                                 const vector<int>   & LVLS){
    int index      = 0;           //PROC - The index in the array
    int levelIndex = 0;           //PROC - The index in the level array

    bool found     = false;       //PROC - The condition if the move was found

    LvlAttack newAttack;          //PROC - The attack with a level

    auto size = ATTACK_DEX.size(); //PROC - The size of the attackdex

    //PROCESSING - for every move that the Pokemon has, find it in the
    //			   attackdex and store it as a TM move or a level move
    for(auto moveIt: MOVES){
        while(!found && (index != signed(size))){
            if(!(ATTACK_DEX[index].name.compare(moveIt))){

                //If the move found is a TM, store it
                if((ATTACK_DEX[index].TM == 1) && (LVLS[levelIndex] == 0)){
                    TMMoveset.push_back(ATTACK_DEX[index]);
                }
                //If the move is a level move, then store the level and attack
                else{
                    newAttack.attack = ATTACK_DEX[index];
                    newAttack.lvl    = LVLS      [levelIndex];

                    this->lvlMoveset.push_back(newAttack);
                    levelIndex++;
                }

                found = true;
            }
            else{
                ++index;
            }
        }
        index = 0;
        found = false;
    }
}

//Return the TM Moveset as a string
string Moveset::PrintTM() const{
    using namespace movesetGlobalConsts; //Using the column constants

    using std::setw; 					 //Used for output column sizes

    std::ostringstream out;              //OUT  - the output stream var

    string tm;                           //PROC - the number of the TM

    //If the Pokemon knows TM moves, then output them
    if(!TMMoveset.empty()){
        out << "TM Attacks\n";

        out << std::left;

        out << setw(LVL_COL)    << "TM #"        << " "
            << setw(NAME_COL)   << "Attack Name"  << " "
            << setw(TYPE_COL)   << "Type"		  << " "
            << setw(CAT_COL)    << "Cat."		  << " "
            << setw(ATK_COL)    << "Att."		  << " "
            << setw(ACC_COL)    << "Acc."		  << " "
            << setw(PP_COL)     << "PP"			  << " "
            << setw(EFFECT_COL) << "Effect %";

        out << std::endl << std::setfill('-') << setw(LINE_COL) << "-\n"
            << std::setfill(' ');

        for(auto it: TMMoveset){
            //Punctuate the TM number
            if(it.TMNum < 10){
                tm = ("TM0" + std::to_string(it.TMNum));
            }
            else{
                tm = ("TM"  + std::to_string(it.TMNum));
            }

            out << setw(LVL_COL)    << tm	         << " "
                << setw(NAME_COL)   << (it.name)     << " "
                << setw(TYPE_COL)   << (it.type)     << " "
                << setw(CAT_COL)    << (it.category) << " "
                << setw(ATK_COL)    << it.pwr		 << " "
                << setw(ACC_COL)    << it.acc		 << " "
                << setw(PP_COL)     << it.pp		 << " "
                << setw(EFFECT_COL) << it.effRate	 << " " << std::endl;

            out << setw(DES_COL) << " " << (it.desc) << std::endl << std::endl;
        }

        out << std::endl;
    }

    return (out.str());
}

//Return the Level Moveset as a string
string Moveset::PrintLvl() const
{
    using namespace movesetGlobalConsts; //Using the column constants

    using std::setw; 					 //Used for output column sizes

    std::ostringstream out;              //OUT  - the output stream var

    //If the Pokemon knows moves by leveling up, then output them
    if(!lvlMoveset.empty()){
        out << std::endl << std::endl << (GENERATION) << " Level Up\n\n"
            << std::left;

        out << setw(LVL_COL)    << "Level"        << " "
            << setw(NAME_COL)   << "Attack Name"  << " "
            << setw(TYPE_COL)   << "Type"		  << " "
            << setw(CAT_COL)    << "Cat."		  << " "
            << setw(ATK_COL)    << "Att."		  << " "
            << setw(ACC_COL)    << "Acc."		  << " "
            << setw(PP_COL)     << "PP"			  << " "
            << setw(EFFECT_COL) << "Effect %";

        out << std::endl << std::setfill('-') << setw(LINE_COL) << "-\n"
            << std::setfill(' ');

        for(auto it: lvlMoveset){

            out << setw(LVL_COL)    << it.lvl               << " "
                << setw(NAME_COL)   << (it.attack.name)	    << " "
                << setw(TYPE_COL)   << (it.attack.type)	    << " "
                << setw(CAT_COL)    << (it.attack.category) << " "
                << setw(ATK_COL)    << it.attack.pwr	    << " "
                << setw(ACC_COL)    << it.attack.acc	    << " "
                << setw(PP_COL)     << it.attack.pp		    << " "
                << setw(EFFECT_COL) << it.attack.effRate    << std::endl;

            out << setw(DES_COL) << " " << (it.attack.desc)
                << std::endl << std::endl;
        }

        out << std::endl;
    }
    return (out.str());
}
