#ifndef JOHTO_H
#define JOHTO_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPalette>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include "dialog.h"

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR ARRAY/VECTOR SIZE
 * ------------------------------------------------------------------------
 * JOHTO_AR_SIZE	: The size of the array/vector
 * ------------------------------------------------------------------------
 * USED FOR SPECIFIC VALUES
 * ------------------------------------------------------------------------
 * JOHTO_START	: The starting index in the region pokedex
 *************************************************************************/
const int JOHTO_AR_SIZE = 100;
const int JOHTO_START = 152;

//namespace holding the path to the johto pokemon images
namespace JohtoImages {
const QString IMAGE_PATH = ":/pokemonImages/pokemonImages/";
}

namespace Ui {
class Johto;
}

/************************************************************************
* Alola Class
* 	This class represents the Johto region screen. It manages 8 attributes:
* 		ui, scrollArea, gridLayout, mainLayout, list, mainWidget,
*       pokemonDialog, regionVect
*************************************************************************/
class Johto : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor
    explicit Johto(QWidget *parent = nullptr);

    //Deconstructor
    ~Johto();

    /****************************************************************
     * 	void CreateList();
     *
     *   Mutator; this creates the list of QPushButtons
     *   Return: none
     ***************************************************************/
    void CreateList();

    /****************************************************************
     * 	void SetRegionVect(const vector<Pkmn>& regionV);
     *
     *   Mutator; Inititalizes the region vector
     *   Parameters: regionV (vector<Pkmn>) - the vector of Pokemon
     *                                        for the region
     *   Return: none
     ***************************************************************/
    void SetRegionVect(const vector<Pkmn>& regionV){regionVect = regionV;}

    /****************************************************************
     * 	void CreateList() const;
     *
     *   Accessor; this prints the list of QPushButtons
     *   Return: none
     ***************************************************************/
    void PrintList() const;

public slots:
    /****************************************************************
     * 	void GoToDialog();
     *
     *   Slots; this creates the Dialog with the selected button
     *   Return: none
     ***************************************************************/
    void GoToDialog();

private slots:
    /****************************************************************
     * 	void on_actionExit_triggered();
     *
     *   Slots; this hides the window when selected
     *   Return: none
     ***************************************************************/
    void on_actionExit_triggered();

private:
    Ui::Johto            *ui;           //The UI for the region
    QScrollArea          *scrollArea;   //The scroll area for the window
    QGridLayout          *gridLayout;   //The grid layout for the window
    QHBoxLayout          *mainLayout;   //The horizontal box layout
    QVector<QPushButton*> list;         //The list of QPushButtons
    QWidget              *mainWidget;   //The main QWidget where the window
                                        //is placed
    Dialog               *pokemonDialog;//The Dialog that appears to display
                                        //the Pokemon's information
    vector<Pkmn>          regionVect;   //The list of Pokemon for the region
};

#endif // JOHTO_H
