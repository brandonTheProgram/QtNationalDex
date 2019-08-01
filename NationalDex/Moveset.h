#ifndef MOVESET_H
#define MOVESET_H

#include <vector>   /** vector        **/
#include <iostream> /** ostream       **/
#include <fstream>  /** fin           **/
#include <iomanip>  /** setw          **/
#include <sstream>  /** ostringstream **/
#include <string>   /** string        **/
using std::string;
using std::vector;

//Namespace for the global constants in the class
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
namespace movesetGlobalConsts
{
    const string GENERATION = "Generation VII";
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
struct Attack
{
    string name;
    string desc;
    string type;
    string category;
    int    pwr;
    int    acc;
    int    pp;
    int    effRate;
    bool   TM;
    int    TMNum;
};

//A Pokemon move that it learns through leveling
struct LvlAttack
{
    int    lvl;
    Attack attack;
};

/************************************************************************
* Pokedex Class
* 	This class represents a Pokedex object. It manages 2 attributes:
* 		lvlMoveset and TMMoveset
*************************************************************************/
class Moveset //Base Class
{
    public:

        /******************************
         ** CONSTRUCTOR & DESTRUCTOR **
         ******************************/

        /****************************************************************
         * Moveset ();
         *   Constructor; this method initializes the Moveset of the Pokemon
         *   			  object
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        Moveset(); //Default Constructor

        /****************************************************************
         * Moveset ();
         *   Constructor; this method initializes the Moveset of the Pokemon
         *   			  object with values
         *   Parameters: ATTACK_DEX (vector<Attack>) - the attackdex
         *   			 MOVES      (vector<string>) - the moves the Pokemon
         *   			 							   learns
         *   			 LVLS       (vector<int>)    - the levels when the
         *   			 							   Pokemon learns the move
         *   Return: none
         ***************************************************************/
        Moveset(const vector<Attack>& ATTACK_DEX,
                const vector<string>& MOVES,
                const vector<int>   & LVLS);//Non-Deafult Constructor

        /****************************************************************
         * ~Pokedex ();
         *   Deconstructor; does not perform any specific function
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        virtual ~Moveset(); //Deconstructor

        /******************
         **** MUTATORS ****
         ******************/

        /****************************************************************
         * 	void InitializeMoveSets(const vector<Attack>& attackDex,
         *							const vector<string>& moves,
         *							const vector<int>   & lvls);
         *
         *   Mutator; this method initializes the pokemon's moves
         *   Parameters: ATTACK_DEX (vector<Attack>) - the attackdex
         *   			 MOVES      (vector<string>) - the moves the Pokemon
         *   			 							   learns
         *   			 LVLS       (vector<int>)    - the levels the Pokemon
         *   			 							   learns the move
         *   Return: none
         ***************************************************************/
        void InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                const vector<string>& MOVES,
                                const vector<int>   & LVLS);

        /*******************
         **** ACCESSORS ****
         *******************/

        /****************************************************************
         * 	vector<LvlAttack> GetLvlMoveSet() const;
         *
         *   Accessor; this method returns the level moveset
         *   Parameters: none
         *   Return: the level moveset
         ***************************************************************/
        vector<LvlAttack> GetLvlMoveSet() const {return lvlMoveset;}

        /****************************************************************
         * 	vector<Attack> GetTMMoveset() const;
         *
         *   Accessor; this method returns the TM moveset
         *   Parameters: none
         *   Return: TM moveset
         ***************************************************************/
        vector<Attack> GetTMMoveset() const {return TMMoveset;}

        /****************************************************************
         * 	string PrintTM() const;
         *
         *   Accessor; this method returns the printed format of the TM moveset
         *   Parameters: none
         *   Return: TM Moveset format
         ***************************************************************/
        string PrintTM() const;

        /****************************************************************
         * 	string PrintLvl() const;
         *
         *   Accessor; this method returns the printed format of the
         *             level moveset
         *   Parameters: none
         *   Return: Level Moveset format
         ***************************************************************/
        string PrintLvl() const;

    private:
        vector<LvlAttack> lvlMoveset; //The moves that the Pokemon
                                      //learns leveling up
        vector<Attack>    TMMoveset;  //The moves that the Pokemon
                                      //learns via TMs
};

#endif // MOVESET_H
