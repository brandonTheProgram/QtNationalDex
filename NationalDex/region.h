#ifndef REGION_H
#define REGION_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPalette>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QInputDialog>
#include <QMessageBox>
#include "dialog.h"

//namespace holding the path to the region pokemon images
namespace PokemonImages {
const QString IMAGE_PATH = ":/pokemonImages/pokemonImages/";
}

namespace Ui {
class Region;
}

/************************************************************************
* Region Class
* 	This class represents the region screen. It manages 9 attributes:
* 		ui, scrollArea, gridLayout, mainLayout, list, mainWidget,
*       pokemonDialog, regionStart, and regionVect
*************************************************************************/
class Region : public QMainWindow
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Region (QWidget *parent = nullptr, const int& REGION_SIZE = 0,
     *         const int& REGION_START = 0,
     *         const vector<Pkmn>& REGION_VECT = vector<Pkmn>());
     *
     *   Constructor; this method initializes the QDialog object
     * --------------------------------------------------------------
     *   Parameters: parent       (QWidget)      - the invoking object
     *               REGION_START (int)          - the starting pokedex number
     *                                             of the region
     *               REGION_VECT  (vector<Pkmn>) - the vector holding the
     *                                             pokemon in the region
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    explicit Region(QWidget *parent = nullptr, const int& REGION_START = 0,
                    const vector<Pkmn>& REGION_VECT = vector<Pkmn>());

    /****************************************************************
     * ~Region ();
     *
     *   Deconstructor; does not perform any specific function
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    ~Region();

    /******************
     **** MUTATORS ****
     ******************/

    /****************************************************************
     * 	void CreateList();
     *
     *   Mutator; this method creates the list of QPushButtons
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void CreateList();

    /****************************************************************
     * 	void LoadSpecificPokemon(const Pkmn& POKEMON);
     *
     *   Mutator; this method loads a specific pokemon for displau
     * --------------------------------------------------------------
     *   Parameters: POKEMON (Pkmn) - the pokemon to be displayed
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void LoadSpecificPokemon(const Pkmn& POKEMON);

    /****************************************************************
     * 	void PrintList() const;
     *
     *   Accessor; this method prints the list of QPushButtons
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void PrintList() const;

public slots:
    /****************************************************************
     * 	void GoToDialog();
     *
     *   Slots; this slot creates the Dialog with the selected button
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void GoToDialog();

    /****************************************************************
     * 	void GoToDialog();
     *
     *   Slots; this slot catches the signal that is thrown from the Dialog
     * --------------------------------------------------------------
     *   Parameters: POKEMON_NUMBER (int) - the Pokemon number
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void CatchSignal(const int& POKEMON_NUMBER)
        {emit evolutionNumberSig(POKEMON_NUMBER);}

private slots:
    /****************************************************************
     * 	void on_actionExit_triggered();
     *
     *   Slots; this slot hides the window when selected
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_actionExit_triggered(){hide();}

    /****************************************************************
     * 	void on_actionSearch_triggered();
     *
     *   Slots; this slot prompts the user to search for a pokemon within the
     *          given region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_actionSearch_triggered();

signals:
    /****************************************************************
     * 	void evolutionNumberSig(const int& POKEMON_NUMBER);
     *
     *   Slots; this signal throws the pokedex number of the pokemon selected
     * --------------------------------------------------------------
     *   Parameters: POKEMON_NUMBER (int) - the Pokemon number
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void evolutionNumberSig(const int& POKEMON_NUMBER);

private:
    Ui::Region           *ui;           //The UI for the region
    QScrollArea          *scrollArea;   //The scroll area for the window
    QGridLayout          *gridLayout;   //The grid layout for the window
    QHBoxLayout          *mainLayout;   //The horizontal box layout
    QVector<QPushButton*> list;         //The list of QPushButtons
    QWidget              *mainWidget;   //The main QWidget where the window
                                        //is placed
    Dialog               *pokemonDialog;//The Dialog that appears to display
                                        //the Pokemon's information
    int                   regionStart;  //The starting index for the region
    vector<Pkmn>          regionVect;   //The list of Pokemon for the region
};

#endif // REGION_H
