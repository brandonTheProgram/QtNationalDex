#ifndef MOVESET_H
#define MOVESET_H

#include <vector>   /** vector        **/
#include <iomanip>  /** setw          **/
#include <string>   /** string        **/
#include <QString>
#include <QTextStream>
#include <iostream>
using std::string;
using std::vector;

/*!
 * \namespace PokemonDialog
 * \brief global constants to be used for a Moveset about a Pokemon
 */
namespace movesetGlobalConsts{
    /*!
     * \variable GENERATION
     * \brief The current generation of the Pokemon games
     */
    const QString GENERATION = "Generation VIII";

    /*!
     * \variable LVL_COL
     * \brief The amount of spaces allocated for the Level Column
     */
    const unsigned int LVL_COL = 5;

    /*!
     * \variable NAME_COL
     * \brief The amount of spaces allocated for the Name Column
     */
    const unsigned int NAME_COL = 30;

    /*!
     * \variable DES_COL
     * \brief The amount of spaces allocated for the Description Column
     */
    const unsigned int DES_COL = 6;

    /*!
     * \variable TYPE_COL
     * \brief The amount of spaces allocated for the Typing Column
     */
    const unsigned int TYPE_COL = 10;

    /*!
     * \variable CAT_COL
     * \brief The amount of spaces allocated for the Category Column
     */
    const unsigned int CAT_COL = 10;

    /*!
     * \variable ATK_COL
     * \brief The amount of spaces allocated for the Attack Column
     */
    const unsigned int ATK_COL = 4;

    /*!
     * \variable ACC_COL
     * \brief The amount of spaces allocated for the Accuracy Column
     */
    const unsigned int ACC_COL = 4;

    /*!
     * \variable PP_COL
     * \brief The amount of spaces allocated for the PP Column
     */
    const unsigned int PP_COL = 3;

    /*!
     * \variable EFFECT_COL
     * \brief The amount of spaces allocated for the Effect Column
     */
    const unsigned int EFFECT_COL = 10;
}

/*!
 * \brief The basic information for a Pokemon attack
 */
struct Attack{
    /*!
     * \variable name
     * \brief The name of the attack
     */
    string name;

    /*!
     * \variable desc
     * \brief The description of the attack
     */
    string desc;

    /*!
     * \variable type
     * \brief The typing of the attack
     */
    string type;

    /*!
     * \variable category
     * \brief The category of the attack
     */
    string category;

    /*!
     * \variable pwr
     * \brief The power of the attack
     */
    unsigned int pwr;

    /*!
     * \variable acc
     * \brief The accuracy of the attack
     */
    unsigned int acc;

    /*!
     * \variable pp
     * \brief The pp of the attack
     */
    unsigned int pp;

    /*!
     * \variable effRate
     * \brief The effect rate of the attack
     */
    unsigned int effRate;

    /*!
     * \variable TM
     * \brief The condition if the move is a TM
     */
    bool TM;

    /*!
     * \variable TR
     * \brief The condition if the move is a TR
     */
    bool TR;

    /*!
     * \variable TMNum
     * \brief The move's TM number
     */
    unsigned int TMNum;

    /*!
     * \variable TRNum
     * \brief The move's TR number
     */
    unsigned int TRNum;
};

/*!
 * \brief A Pokemon move that it learns through leveling
 */
struct LvlAttack{
    /*!
     * \variable lvl
     * \brief The level the Pokemon learns the attack
     */
    unsigned int lvl;

    /*!
     * \variable attack
     * \brief The attack the Pokemon learnsc
     */
    Attack attack;
};

/*!
 * \class Moveset
 * \brief This class represents a moveset that a Pokemon can learn.
 */
class Moveset{
    public:
        /*!
         * \fn Moveset()
         * \brief This is the default constructor for the Moveset
         */
        Moveset();

        /*!
         * \fn Moveset(const vector<Attack>& ATTACK_DEX,
                       const vector<string>& MOVES,
                       const vector<unsigned int>& LVLS)
         * \brief This is the non-default constructor for the Moveset
         */
        Moveset(const vector<Attack>& ATTACK_DEX,
                const vector<string>& MOVES,
                const vector<unsigned int>& LVLS);

        /*!
         * \fn ~Moveset()
         * \brief This is the deconstructor for the Moveset
         */
        virtual ~Moveset();

        /*!
         * \fn InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                  const vector<string>& MOVES,
                                  const vector<unsigned int>& LVLS)
         * \brief This method initializes the moveset
         */
        void InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                const vector<string>& MOVES,
                                const vector<unsigned int>& LVLS);

        /*!
         * \fn GetLvlMoveSet() const
         * \brief This imethod returns the moveset learned through leveling up
         */
        vector<LvlAttack> GetLvlMoveSet() const {return this->lvlMoveset;}

        /*!
         * \fn GetTMMoveset() const
         * \brief This imethod returns the moveset learned through TMs/TRs
         */
        vector<Attack> GetTMMoveset() const {return this->TMMoveset;}

        /*!
         * \fn PrintTM() const
         * \brief This imethod prints the list of moves learned through TMs/TRs
         */
        QString PrintTM() const;

        /*!
         * \fn PrintLvl() const
         * \brief This imethod prints the list of moves learned through leveling
         */
        QString PrintLvl() const;

    private:
        /*!
         * \variable lvlMoveset
         * \brief The moves that the Pokemon learns leveling up
         */
        vector<LvlAttack> lvlMoveset;

        /*!
         * \variable TMMoveset
         * \brief The moves that the Pokemon learns through TMs/TRs
         */
        vector<Attack>    TMMoveset;
};

#endif // MOVESET_H
