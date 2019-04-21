#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMovie>
#include "Pokedex.h"

enum options
{
    DISPLAY,
    ABILITIES,
    EVOLUTIONS,
    WEAKNESS,
    LVL_MOVESET,
    TM_MOVESET
};

//namespace holding the path to the pokemon gifs
namespace PokemonGifs {
    const QString PATH = ":/pokemonGifs/pokemonGifs/";
}

namespace Ui {
class Dialog;
}

/************************************************************************
* Dialog Class
* 	This class represents a Dialog screen that will display a Pokemon's
*   information. It manages 19 attributes:
* 		ui, mainLayout, topLayout, middleLayout, bottomLayout, topBox,
*       middleBox, bottomBox,image, idNumber, name, classification, priType
*       ,secType, comboBox, description, options, movie, and currentPokemon
*************************************************************************/
class Dialog : public QDialog
{
    Q_OBJECT

public:
    //Constructor
    explicit Dialog(QWidget *parent = nullptr);

    //Deconstructor
    ~Dialog();

    /****************************************************************
     * 	void SetPokemon(const Pkmn& POKEMON);
     *
     *   Mutator; this initializes the Dialog with the Pokemon
     *   Parameters: POKEMON (Pkmn) - The Pokemon for the Dialog
     *   Return: none
     ***************************************************************/
    void SetPokemon(const Pkmn& POKEMON);

    /****************************************************************
     * 	void SetPokemonValues();
     *
     *   Mutator; this initializes the Dialog with the Pokemon's info
     *   Parameters:
     *   Return: none
     ***************************************************************/
    void SetPokemonValues();

    /****************************************************************
     * 	void DisplayDefault() const;
     *
     *   Accessor; this display's the default message for the QComboBox
     *   Return: none
     ***************************************************************/
    void DisplayDefault() const;

    /****************************************************************
     * 	void DisplayAbilities() const;
     *
     *   Accessor; this display's the Pokemon's abilities in the QComboBox
     *   Return: none
     ***************************************************************/
    void DisplayAbilities() const;

    /****************************************************************
     * 	void DisplayEvolutions() const;
     *
     *   Accessor; this display's the Pokemon's evolutions in the QComboBox
     *   Return: none
     ***************************************************************/
    void DisplayEvolutions() const;

    /****************************************************************
     * 	void DisplayWeakness() const;
     *
     *   Accessor; this display's the Pokemon's weakness in the QComboBox
     *   Return: none
     ***************************************************************/
    void DisplayWeakness() const;

    /****************************************************************
     * 	void DisplayLvlMoveset() const;
     *
     *   Accessor; this display's the Pokemon's level moveset in the QComboBox
     *   Return: none
     ***************************************************************/
    void DisplayLvlMoveset() const;

    /****************************************************************
     * 	void DisplayTMMoveset() const;
     *
     *   Accessor; this display's the Pokemon's TM moveset in the QComboBox
     *   Return: none
     ***************************************************************/
    void DisplayTMMoveset() const;

public slots:
    /****************************************************************
     * 	void ComboBoxOptions(int argument);
     *
     *   Slots; this chooses the option based on whihc QComboBox option
     *          was chosen
     *   Parameters: argument (int) - the index in the QComboBox
     *   Return: none
     ***************************************************************/
    void ComboBoxOptions(int argument);

private:
    Ui::Dialog  *ui;            //The UI for the Dialog
    QVBoxLayout *mainLayout;    //The mainlayout for the Dialog
    QHBoxLayout *topLayout;     //The Layout for the top half
    QGridLayout *middleLayout;  //The Layout for the middle half
    QGridLayout *bottomLayout;  //The Layout for the bottom half
    QGroupBox   *topBox;        //The top box in the display
    QGroupBox   *middleBox;     //The middle box in the display
    QGroupBox   *bottomBox;     //The bottom box in the display
    QLabel      *image;         //The image of the Pokemon
    QLabel      *idNumber;      //The Pokemon's Pokedex number
    QLabel      *name;          //The Name of the Pokemon
    QLabel      *classification;//The Dpecies of the Pokemon
    QLabel      *priType;       //The Primary Type of the Pokemon
    QLabel      *secType;       //The Secondary Type of the Pokemon
    QComboBox   *comboBox;      //The combobox that holds the options
    QLabel      *description;   //The Description of the Pokemon
    QTextEdit   *options;       //The different options that can be displayed
                                //by the QComboBox
    QMovie      *movie;         //The animated gif of the Pokemon
    Pkmn        currentPokemon; //The current Pokemon of the Dialog
};

#endif // DIALOG_H
