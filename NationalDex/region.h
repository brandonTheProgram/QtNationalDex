#ifndef REGION_H
#define REGION_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPalette>
#include <QGridLayout>
#include <QVector>
#include <QInputDialog>
#include <QMessageBox>
#include "dialog.h"

/*!
 * \namespace GlobalRegionConsts
 * \brief global constants to be used for a Pokemon Region
 */
namespace GlobalRegionConsts {
const QString IMAGE_PATH = ":/PokemonImages/pokemonImages/";
}

namespace Ui {
class Region;
}

/*!
 * \class Region
 * \brief This class represents displaying all the Pokemon avilable from that
 *        specific region of the Pokedex
 */
class Region : public QMainWindow{
    Q_OBJECT

public:
    /*!
     * \fn Region(QWidget *parent = nullptr
     *            const vector<Pkmn>& REGION_VECT = vector<Pkmn>())
     * \brief This is the default constructor for the Region
     * \param parent - the widget parent of the child object
     * \param REGION_VECT - a vector containing all the Pokemon for the Region
     */
    explicit Region(QWidget *parent = nullptr,
                    const vector<Pkmn>& REGION_VECT = vector<Pkmn>());

    /*!
     * \fn ~Region()
     * \brief This is the deconstructor for the Region
     */
    ~Region();

    /*!
     * \fn CreateList()
     * \brief This method creates the list of QPushButtons that allow the user
     *        to choose which Pokemon to display information about
     */
    void CreateList();

    /*!
     * \fn SetRegionVect(const vector<Pkmn>& REGION_VECT)
     * \brief This method initializes the Region to have all the Pokemon for the
     *        given region to display
     * \param REGION_VECT - a vector containing all the Pokemon for the Region
     */
    void SetRegionVect(const vector<Pkmn>& REGION_VECT){
        this->regionVect = REGION_VECT;
    }

    /*!
     * \fn LoadSpecificPokemon(const Pkmn& POKEMON)
     * \brief This method loads the information about a specific Pokemon in the
     *        region
     * \param POKEMON - the given Pokemon that needs to display its data
     */
    void LoadSpecificPokemon(const Pkmn& POKEMON);

    /*!
     * \fn PrintList() const
     * \brief This method prints the list of QPushButtons that allow the user
     *        to choose which Pokemon to display information about
     */
    void PrintList() const;

public slots:
    /*!
     * \fn GoToDialog()
     * \brief This method is triggered when a user selects a Pokemon from the
     *        list which causes this method to create a Dialog object with the
     *        choosen Pokemon's information for viewing
     */
    void GoToDialog();

    /*!
     * \fn CatchSignal(const  int& POKEMON_NUMBER)
     * \brief This method catches the Pokemon Number that is given and triggers
     *        another method to emits it as a signal to use back on MainWindow
     */
    void CatchSignal(const  int& POKEMON_NUMBER){
        emit evolutionNumberSig(POKEMON_NUMBER);
    }

private slots:

    /*!
     * \fn on_actionExit_triggered()
     * \brief This method hides the screen when the user is done
     */
    void on_actionExit_triggered(){hide();}

    /*!
     * \fn on_actionSearch_triggered()
     * \brief This method allows the user to search for a given Pokemon
     */
    void on_actionSearch_triggered();

signals:

    /*!
     * \fn evolutionNumberSig(const int& POKEMON_NUMBER)
     * \brief This method sends the signal of the Pokemon Number back to the
     *        MainWindow
     */
    void evolutionNumberSig(const int& POKEMON_NUMBER);

private:
    /*!
     * \variable ui
     * \brief The UI for the Region
     */
    Ui::Region *ui;

    /*!
     * \variable scrollArea
     * \brief The scroll area for the Region that has the QPushButtons
     */
    QScrollArea *scrollArea;

    /*!
     * \variable gridLayout
     * \brief The grid layout for the Region
     */
    QGridLayout *gridLayout;

    /*!
     * \variable mainLayout
     * \brief The horizontal box layout for the Region
     */
    QHBoxLayout *mainLayout;

    /*!
     * \variable list
     * \brief The list of Pokemon QPushButtons for the Region
     */
    QVector<QPushButton*> list;

    /*!
     * \variable dialogList
     * \brief The list of every Dialog that was opened up in the Region
     */
    QVector<Dialog*> dialogList;

    /*!
     * \variable mainWidget
     * \brief The main QWidget of the Region where the window is placed
     */
    QWidget *mainWidget;

    /*!
     * \variable pokemonDialog
     * \brief The Dialog that appears to display the Pokemon's information
     */
    Dialog *pokemonDialog;

    /*!
     * \variable regionVect
     * \brief The list of Pokemon for the Region
     */
    vector<Pkmn> regionVect;
};

#endif // REGION_H
