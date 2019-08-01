#include "Moveset.h"

/************************************************************************
* Method Moveset: Class Moveset
*----------------------------------------------------------------------
* 	 This method creates the Moveset object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Moveset::Moveset()
{
    lvlMoveset.clear();
    TMMoveset .clear();
}

/************************************************************************
* Method Moveset: Class Moveset
*----------------------------------------------------------------------
* 	 This method creates the Moveset object with values
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*   	ATTACK_DEX (vector<Attack>) - the attackdex
*   	MOVES      (vector<string>) - the moves the Pokemon learns
*   	LVLS       (vector<int>)    - the levels when the Pokemon
*                                     learns the move
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Moveset::Moveset(const vector<Attack>& ATTACK_DEX,
                 const vector<string>& MOVES,
                 const vector<int>   & LVLS)
{
    int index;                    //PROC - The index in the array
    int levelIndex;               //PROC - The index in the level array

    bool found;                   //PROC - The condition if the move was found

    LvlAttack newAttack;          //PROC - The attack with a level

    auto size = ATTACK_DEX.size(); //PROC - The size of the attackdex

    found      = false;
    index      = 0;
    levelIndex = 0;

    //PROCESSING - for every move that the Pokemon has, find it in the
    //			   attackdex and store it as a TM move or a level move
    for(auto moveIt: MOVES)
    {
        while(!found && (index != signed(size)))
        {
            if(!(ATTACK_DEX[index].name.compare(moveIt)))
            {
                //If the move found is a TM, store it
                if((ATTACK_DEX[index].TM == 1) && (LVLS[levelIndex] == 0))
                    {TMMoveset.push_back(ATTACK_DEX[index]);}
                //If the move is a level move, then store the
                //level and attack
                else
                {
                    newAttack.attack = ATTACK_DEX[index];
                    newAttack.lvl    = LVLS     [levelIndex];
                    lvlMoveset.push_back(newAttack);
                    levelIndex++;
                }

                found = true;
            }
            else{++index;}
        }
        index = 0;
        found = false;
    }
}

/************************************************************************
* Method ~Moveset: Class Moveset
*----------------------------------------------------------------------
* 	 This method deletes the Moveset object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Moveset::~Moveset()
{
    lvlMoveset.clear();
    TMMoveset .clear();

    vector<LvlAttack>().swap(lvlMoveset);
    vector<Attack>   ().swap(TMMoveset);
}

/************************************************************************
* Method InitializeMoveSets: Class Moveset
*----------------------------------------------------------------------
* 	 This method initializes the Moveset object with values
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*   	ATTACK_DEX (vector<Attack>) - the attackdex
*   	MOVES      (vector<string>) - the moves the Pokemon learns
*   	LVLS       (vector<int>)    - the levels when the Pokemon
*                                     learns the move
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Moveset::InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                 const vector<string>& MOVES,
                                 const vector<int>   & LVLS)
{
    int index;                    //PROC - The index in the array
    int levelIndex;               //PROC - The index in the level array

    bool found;                   //PROC - The condition if the move was found

    LvlAttack newAttack;          //PROC - The attack with a level

    auto size = ATTACK_DEX.size(); //PROC - The size of the attackdex

    found      = false;
    index      = 0;
    levelIndex = 0;

    //PROCESSING - for every move that the Pokemon has, find it in the
    //			   attackdex and store it as a TM move or a level move
    for(auto moveIt: MOVES)
    {
        while(!found && (index != signed(size)))
        {
            if(!(ATTACK_DEX[index].name.compare(moveIt)))
            {
                //If the move found is a TM, store it
                if((ATTACK_DEX[index].TM == 1) && (LVLS[levelIndex] == 0))
                    {TMMoveset.push_back(ATTACK_DEX[index]);}
                //If the move is a level move,
                //then store the level and attack
                else
                {
                    newAttack.attack = ATTACK_DEX[index];
                    newAttack.lvl    = LVLS      [levelIndex];
                    lvlMoveset.push_back(newAttack);
                    levelIndex++;
                }

                found = true;
            }
            else{++index;}
        }
        index = 0;
        found = false;
    }
}

/************************************************************************
* Method PrintTM: Class Moveset
*----------------------------------------------------------------------
* 	 This method returns the printed format of the TM moveset
* 	 ==> returns the TM Moveset format
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns the TM Moveset format
*************************************************************************/
string Moveset::PrintTM() const
{
    using namespace movesetGlobalConsts; //Using the column constants

    using std::setw; 					 //Used for output column sizes

    std::ostringstream out;              //OUT  - the output stream var

    string tm;                           //PROC - the number of the TM

    //If the Pokemon knows TM moves, then output them
    if(!TMMoveset.empty())
    {
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

        out << std::endl << std::setfill('-')
            << setw(LINE_COL) << "-" << std::endl;

        out << std::setfill(' ');

        for(auto it: TMMoveset)
        {
            //Punctuate the TM number
            if(it.TMNum < 10){tm = ("TM0" + std::to_string(it.TMNum));}
            else             {tm = ("TM"  + std::to_string(it.TMNum));}

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

/************************************************************************
* Method PrintLvl: Class Moveset
*----------------------------------------------------------------------
* 	 This method returns the printed format of the level moveset
* 	 ==> returns the Level Moveset format
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns the Level Moveset format
*************************************************************************/
string Moveset::PrintLvl() const
{
    using namespace movesetGlobalConsts; //Using the column constants

    using std::setw; 					 //Used for output column sizes

    std::ostringstream out;              //OUT  - the output stream var

    //If the Pokemon knows moves by leveling up, then output them
    if(!lvlMoveset.empty())
    {
        out << std::endl << std::endl << (GENERATION) << " Level Up\n\n";

        out << std::left;

        out << setw(LVL_COL)    << "Level"        << " "
            << setw(NAME_COL)   << "Attack Name"  << " "
            << setw(TYPE_COL)   << "Type"		  << " "
            << setw(CAT_COL)    << "Cat."		  << " "
            << setw(ATK_COL)    << "Att."		  << " "
            << setw(ACC_COL)    << "Acc."		  << " "
            << setw(PP_COL)     << "PP"			  << " "
            << setw(EFFECT_COL) << "Effect %";

        out << std::endl << std::setfill('-') << setw(LINE_COL)
            << "-" << std::endl;

        out << std::setfill(' ');

        for(auto it: lvlMoveset)
        {

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
