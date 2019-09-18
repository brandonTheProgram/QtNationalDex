#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QMovie>
#include "Pokedex.h"    /** Pkmn **/

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR SPECIFC VALUES
 * ------------------------------------------------------------------------
 * GIF_PATH         : The path to the pokemon gif
 * IMAGE_PATH       : The path to the pokemon image
 * GAME_VER_ONE     : The first version of the game in the current generation
 * GAME_VER_TWO     : The second version of the game in the current generation
 * FONT             : The font of the text
 * IMAGE_SIZE       : The size of the image
 * WORD_WRAP_LIMIT  : The size of the work wrap limit
 *************************************************************************/
namespace PokemonDialog
{
    const QString GIF_PATH   = ":/pokemonGifs/pokemonGifs/";
    const QString IMAGE_PATH = ":/pokemonImages/pokemonImages/";
    const QString GAME_VER_ONE = "Ultra Sun";
    const QString GAME_VER_TWO = "Ultra Moon";
    const QFont   FONT("Times", 10, QFont::Bold);
    const QSize   IMAGE_SIZE(250, 250);
    const int     WORD_WRAP_LIMIT = 150;

    //The enum of the menu options
    enum options
    {
        DISPLAY,
        ABILITIES,
        EVOLUTIONS,
        WEAKNESS,
        LVL_MOVESET,
        TM_MOVESET
    };
}

namespace Ui {
class Dialog;
}

/************************************************************************
* Dialog Class
* 	This class represents a Dialog screen that will display a Pokemon's
*   information. It manages 26 attributes: ui, mainLayout, topLayout,
*   middleLayout, midBtmLayout, bottomLayout, topBox, middleBox, midBtmBox,
*   bottomBox, image, idNumber, name, classification, priType, secType,
*   firstEvoBut, secEvoBut, finalEvoBut, branchEvoBut, comboBox, description,
*   options, movie, evoList and currentPokemon
*************************************************************************/
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Dialog (QWidget *parent = nullptr);
     *
     *   Constructor; this method initializes the QDialog object
     * --------------------------------------------------------------
     *   Parameters: parent (QWidget) - the invoking object
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    explicit Dialog(QWidget *parent = nullptr);//Constructor

    /****************************************************************
     * ~Dialog ();
     *
     *   Deconstructor; does not perform any specific function
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    ~Dialog();//Deconstructor

    /******************
     **** MUTATORS ****
     ******************/

    /****************************************************************
     * 	void SetPokemon(const Pkmn& POKEMON);
     *
     *   Mutator; this initializes the Dialog with the Pokemon
     * --------------------------------------------------------------
     *   Parameters: POKEMON (Pkmn) - The Pokemon for the Dialog
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void SetPokemon(const Pkmn& POKEMON);

    /****************************************************************
     * 	void SetPokemonValues();
     *
     *   Mutator; this initializes the Dialog with the Pokemon's info
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void SetPokemonValues();

    /****************************************************************
     * 	void CreateBranchEvolutionButtons();
     *
     *   Mutator; this create the buttons for the special pokemon Evos
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void CreateBranchEvolutionButtons();

    /*******************
     **** ACCESSORS ****
     *******************/

    /****************************************************************
     * 	void DisplayDefault() const;
     *
     *   Accessor; this display's the default message for the QComboBox
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void DisplayDefault() const
        {options->setPlainText(tr("Pick an option below!"));}

    /****************************************************************
     * 	void DisplayAbilities() const;
     *
     *   Accessor; this display's the Pokemon's abilities in the QComboBox
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void DisplayAbilities() const;

    /****************************************************************
     * 	void DisplayEvolutions() const;
     *
     *   Accessor; this display's the Pokemon's evolutions in the QComboBox
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void DisplayEvolutions() const;

    /****************************************************************
     * 	void DisplayWeakness() const;
     *
     *   Accessor; this display's the Pokemon's weakness in the QComboBox
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void DisplayWeakness() const;

    /****************************************************************
     * 	void DisplayLvlMoveset() const;
     *
     *   Accessor; this display's the Pokemon's level moveset in the QComboBox
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void DisplayLvlMoveset() const;

    /****************************************************************
     * 	void DisplayTMMoveset() const;
     *
     *   Accessor; this display's the Pokemon's TM moveset in the QComboBox
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void DisplayTMMoveset() const;

    QString WordWrap(const string& SEN, const int& LENGTH) const;

public slots:
    /****************************************************************
     * 	void ComboBoxOptions(const int& ARGUMENT);
     *
     *   Slots; this chooses the option based on which QComboBox option
     *          was chosen
     * --------------------------------------------------------------
     *   Parameters: ARGUMENT (int) - the index in the QComboBox
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void ComboBoxOptions(const int& ARGUMENT);

    /****************************************************************
     * 	void EvolutionClicked();
     *
     *   Slots; this finds the button that was pressed and emits a signal
     *          holding a pokedex number of the pokemon that was chosen from
     *          the evolution tree
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void EvolutionClicked();

signals:
    /****************************************************************
     * 	void evolutionNumber(const int& POKEMON_NUMBER);
     *
     *   Signals; this emits a signal holding a pokedex number of the pokemon
     *            that was chosen from the evolution tree
     * --------------------------------------------------------------
     *   Parameters: POKEMON_NUMBER (int) - the pokedex number
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void evolutionNumber(const int& POKEMON_NUMBER);

private:
    Ui::Dialog           *ui;             //The UI for the Dialog
    QVBoxLayout          *mainLayout;     //The mainlayout for the Dialog
    QHBoxLayout          *topLayout;      //The Layout for the top half
    QGridLayout          *middleLayout;   //The Layout for the middle half
    QHBoxLayout          *midBtmLayout;   //The Layout for the middle bottom
                                          //half
    QGridLayout          *bottomLayout;   //The Layout for the bottom half
    QGroupBox            *topBox;         //The top box in the display
    QGroupBox            *middleBox;      //The middle box in the display
    QGroupBox            *midBtmBox;      //The middle bottom box in the display
    QGroupBox            *bottomBox;      //The bottom box in the display
    QLabel               *image;          //The image of the Pokemon
    QLabel               *idNumber;       //The Pokemon's Pokedex number
    QLabel               *name;           //The Name of the Pokemon
    QLabel               *classification; //The Dpecies of the Pokemon
    QLabel               *priType;        //The Primary Type of the Pokemon
    QLabel               *secType;        //The Secondary Type of the Pokemon
    QPushButton          *firstEvoBut;    //Button for the first evolution
    QPushButton          *secEvoBut;      //Button for the second evolution
    QPushButton          *finalEvoBut;    //Button for the final evolution
    QPushButton          *branchEvoBut;   //Button for the branch evolution
    QComboBox            *comboBox;       //The combobox that holds the options
    QLabel               *description;    //The Description of the Pokemon
    QLabel               *versionOneLoc;  //The location of the Pokemon in
                                          //version one
    QLabel               *versionTwoLoc;  //The location of the Pokemon in
                                          //version two
    QTextEdit            *options;        //The different options that can be
                                          //displayed by the QComboBox
    QMovie               *movie;          //The animated gif of the Pokemon
    QVector<QPushButton*> evoList;        //The list of QPushButtons for special
                                          //evos
    Pkmn                  currentPokemon; //The current Pokemon of the Dialog
};

#endif // DIALOG_H
