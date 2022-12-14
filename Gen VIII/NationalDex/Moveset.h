#ifndef MOVESET_H
#define MOVESET_H

#include <vector>   /** vector        **/
#include <iostream> /** ostream       **/
#include <fstream>  /** fin           **/
#include <iomanip>  /** setw          **/
#include <sstream>  /** ostringstream **/
#include <string>   /** string        **/
#include <QString>
#include <QTextStream>
using std::string;
using std::vector;

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR MAX REGION DEX SIZES
 * ------------------------------------------------------------------------
 * USED FOR COLUMN SIZE
 * ------------------------------------------------------------------------
 * LVL_COL    : The column for displaying levels
 * NAME_COL   : The column for displaying the attack name
 * DES_COL    : The column for displaying the attack description
 * TYPE_COL   : The column for displaying the attack type
 * CAT_COL    : The column for displaying the attack category
 * ATK_COL    : The column for displaying the attack power
 * ACC_COL    : The column for displaying the attack accuracy
 * PP_COL     : The column for displaying the attack power points
 * EFFECT_COL : The column for displaying the attack effect
 * LINE_COL   : The column for the entire line
 * ------------------------------------------------------------------------
 * USED FOR SPECIFIC VALUES
 * ------------------------------------------------------------------------
 * GENERATION     : The name of the current generation
 *************************************************************************/
namespace movesetGlobalConsts{
    const QString GENERATION = "Generation VIII";
    const QString LINE = "----------------------------------------------------"
                         "-----------------------------";
    const int LVL_COL       = 5;
    const int NAME_COL      = 30;
    const int DES_COL       = 6;
    const int TYPE_COL      = 10;
    const int CAT_COL       = 10;
    const int ATK_COL       = 4;
    const int ACC_COL       = 4;
    const int PP_COL        = 3;
    const int EFFECT_COL    = 10;
    const int LINE_COL      = (LVL_COL + NAME_COL + TYPE_COL + CAT_COL
                               + ATK_COL + ACC_COL + PP_COL + EFFECT_COL + 5);
}

//The basic information for a Pokemon attack
struct Attack{
    string name;
    string desc;
    string type;
    string category;
    int    pwr;
    int    acc;
    int    pp;
    int    effRate;
    bool   TM;
    bool   TR;
    int    TMNum;
    int    TRNum;
};

//A Pokemon move that it learns through leveling
struct LvlAttack{
    int    lvl;
    Attack attack;
};

/************************************************************************
* Moveset Class
* 	This class represents a moveset that a Pokemon can learn object.
*************************************************************************/
class Moveset{
    public:
        Moveset(); //Default Constructor

        Moveset(const vector<Attack>& ATTACK_DEX,
                const vector<string>& MOVES,
                const vector<int>   & LVLS);//Non-Deafult Constructor

        virtual ~Moveset(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        void InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                const vector<string>& MOVES,
                                const vector<int>   & LVLS);

        /*******************
         **** ACCESSORS ****
         *******************/
        vector<LvlAttack> GetLvlMoveSet() const {return this->lvlMoveset;}

        vector<Attack> GetTMMoveset() const {return this->TMMoveset;}

        //Return the TM moveset as a string
        QString PrintTM() const;

        //Return the Level moveset as a string
        QString PrintLvl() const;

    private:
        vector<LvlAttack> lvlMoveset; //The moves that the Pokemon
                                      //learns leveling up
        vector<Attack>    TMMoveset;  //The moves that the Pokemon
                                      //learns via TMs
};

#endif // MOVESET_H
