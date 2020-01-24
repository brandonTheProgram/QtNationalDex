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

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR IMAGE PATH
 * ------------------------------------------------------------------------
 * IMAGE_PATH  : The path to the image
 *************************************************************************/
namespace GlobalRegionConsts {
const QString IMAGE_PATH = ":/PokemonImages/pokemonImages/";
}

namespace Ui {
class Region;
}

/************************************************************************
* Region Class
* 	This class represents the region screen
*************************************************************************/
class Region : public QMainWindow{
    Q_OBJECT

public:
    explicit Region(QWidget *parent = nullptr,
                    const vector<Pkmn>& REGION_VECT = vector<Pkmn>());
    ~Region();

    /******************
     **** MUTATORS ****
     ******************/

    void CreateList();

    void LoadSpecificPokemon(const Pkmn& POKEMON);

    /*******************
     **** ACCESSORS ****
     *******************/
    void PrintList() const;

public slots:
    void GoToDialog();

    void CatchSignal(const int& POKEMON_NUMBER){
        emit evolutionNumberSig(POKEMON_NUMBER);
    }

private slots:

    //Exit the window
    void on_actionExit_triggered(){hide();}

    //Search through the vector for a pokemon by name
    void on_actionSearch_triggered();

signals:

    //Throw a signal that has the index of the Pokemon in the Pokedex
    void evolutionNumberSig(const int& POKEMON_NUMBER);

private:
    Ui::Region           *ui;           //The UI for the region
    QScrollArea          *scrollArea;   //The scroll area for the window
    QGridLayout          *gridLayout;   //The grid layout for the window
    QHBoxLayout          *mainLayout;   //The horizontal box layout
    QVector<QPushButton*> list;         //The list of QPushButtons
    QVector<Dialog*>      dialogList;
    QWidget              *mainWidget;   //The main QWidget where the window
                                        //is placed
    Dialog               *pokemonDialog;//The Dialog that appears to display
                                        //the Pokemon's information
    vector<Pkmn>          regionVect;   //The list of Pokemon for the region
};

#endif // REGION_H
