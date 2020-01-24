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
#include <QTextToSpeech>

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
 * FONT             : The font for the text
 * IMAGE_SIZE       : The size for the image
 * WORD_WRAP_LIMIT  : The size of the work wrap limit
 * VOICE_PITCH		: The pitch for the voice bot
 * VOICE_VOLUME		: The volume for the voice bot
 * VOICE_RATE		: The rate for the voice bot
 *************************************************************************/
namespace PokemonDialog{
    const QString GIF_PATH        = ":/PokemonGifs/pokemonGifs/";
    const QString IMAGE_PATH      = ":/PokemonImages/pokemonImages/";
    const QString GAME_VER_ONE    = "Sword";
    const QString GAME_VER_TWO    = "Shield";
    const QFont   FONT            ("Times", 12, QFont::Bold);
    const QSize   IMAGE_SIZE      (300, 300);
    const unsigned int     WORD_WRAP_LIMIT = 150;
    const double  VOICE_PITCH     = 0.7;
    const double  VOICE_VOLUME    = 1.0;
    const double  VOICE_RATE      = 0.2;

    //The enum of the menu options
    enum options{
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
*   information.
*************************************************************************/
class Dialog : public QDialog{
    Q_OBJECT

public:

    explicit Dialog(QWidget *parent = nullptr);//Constructor

    ~Dialog();//Deconstructor

    /******************
     **** MUTATORS ****
     ******************/

	//Initialize the Dialog Pokemon
    void SetPokemon(const Pkmn& POKEMON);

	//Set Dialog Pokemon values using pokemon's information
    void SetPokemonValues();

    //Create the buttons for Pokemon with more than 1 branch evolutions
    void CreateBranchEvolutionButtons();

    /*******************
     **** ACCESSORS ****
     *******************/

    void DisplayDefault() const{
        options->setPlainText(tr("Pick an option below!"));}

    void DisplayAbilities() const;

    void DisplayEvolutions() const;

    void DisplayWeakness() const;

    void DisplayLvlMoveset() const;

    void DisplayTMMoveset() const;

    QString WordWrap(const string& SEN, const int& LENGTH) const;

public slots:

    //chooses the option based on which QComboBox option was chosen
    void ComboBoxOptions(const int& ARGUMENT);

    //Find the evolution button that was clicked and emits a index signal
    void EvolutionClicked();

    //Stop the voice if the dialog is closed while the bot is still talking
    void reject();

signals:
    //Emits a signal of the index of the Pokemon in the pokedex
    void evolutionNumber(const int& POKEMON_NUMBER);

private:
    Ui::Dialog           *ui;             //The UI for the Dialog
    QTextToSpeech        *voice;		  //The UI voice bot
    QString               voiceDialog;	  //The message that the voice will say
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
