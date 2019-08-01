#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "region.h"
#include <QMainWindow>

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * NAMES OF THE INPUT FILES
 * ------------------------------------------------------------------------
 * KANTO_INPUT_FILE   : the name of the input file for the Kanto region
 * KANTO_ATTACK_FILE  : the name of the input file for the Kanto attacks
 * JOHTO_INPUT_FILE   : the name of the input file for the Johto region
 * JOHTO_ATTACK_FILE  : the name of the input file for the Johto attacks
 * HOENN_INPUT_FILE   : the name of the input file for the Hoenn region
 * HOENN_ATTACK_FILE  : the name of the input file for the Hoenn attacks
 * SINNOH_INPUT_FILE  : the name of the input file for the Sinnoh region
 * SINNOH_ATTACK_FILE : the name of the input file for the Sinnoh attacks
 * UNOVA_INPUT_FILE	  : the name of the input file for the Unova region
 * UNOVA_ATTACK_FILE  : the name of the input file for the Unova attacks
 * KALOS_INPUT_FILE   : the name of the input file for the Kalos region
 * KALOS_ATTACK_FILE  : the name of the input file for the Kalos attacks
 * ALOLA_INPUT_FILE   : the name of the input file for the Alola region
 * ALOLA_ATTACK_FILE  : the name of the input file for the Alola attacks
 * ATTACKDEX_FILE     : the name of the input file for the Pokemon Attacks
 * ------------------------------------------------------------------------
 * ARRAY SIZES FOR EACH REGION
 * ------------------------------------------------------------------------
 * KANTO_DEX	: The size of the Kanto Pokedex
 * JOHTO_DEX	: The size of the Johto Pokedex
 * HOENN_DEX	: The size of the Hoenn Pokedex
 * SINNOH_DEX	: The size of the Sinnoh Pokedex
 * UNOVA_DEX	: The size of the Unova Pokedex
 * KALOS_DEX	: The size of the Kalos Pokedex
 * ALOLA_DEX	: The size of the Alola Pokedex
 * ------------------------------------------------------------------------
 * STARTING DEX NUMBER FOR EACH REGION
 * ------------------------------------------------------------------------
 * KANTO_START  : The starting pokedex number of the Kanto region
 * JOHTO_START  : The starting pokedex number of the Johto region
 * HOENN_START  : The starting pokedex number of the Hoenn region
 * SINNOH_START : The starting pokedex number of the Sinnoh region
 * UNOVA_START  : The starting pokedex number of the Unova region
 * KALOS_START  : The starting pokedex number of the Kalos region
 * ALOLA_START  : The starting pokedex number of the Alola region
 *************************************************************************/
const string KANTO_INPUT_FILE   = "Kanto.txt";
const string KANTO_ATTACK_FILE  = "KantoAttacks.txt";
const string JOHTO_INPUT_FILE   = "Johto.txt";
const string JOHTO_ATTACK_FILE  = "JohtoAttacks.txt";
const string HOENN_INPUT_FILE   = "Hoenn.txt";
const string HOENN_ATTACK_FILE  = "HoennAttacks.txt";
const string SINNOH_INPUT_FILE  = "Sinnoh.txt";
const string SINNOH_ATTACK_FILE = "SinnohAttacks.txt";
const string UNOVA_INPUT_FILE   = "Unova.txt";
const string UNOVA_ATTACK_FILE  = "UnovaAttacks.txt";
const string KALOS_INPUT_FILE   = "Kalos.txt";
const string KALOS_ATTACK_FILE  = "KalosAttacks.txt";
const string ALOLA_INPUT_FILE   = "Alola.txt";
const string ALOLA_ATTACK_FILE  = "AlolaAttacks.txt";
const string ATTACKDEX_FILE     = "AttackDex.txt";

const short KANTO_AR_SIZE = 151;
const short JOHTO_AR_SIZE = 100;
const short HOENN_AR_SIZE = 135;
const short SINNOH_AR_SIZE = 107;
const short UNOVA_AR_SIZE = 156;
const short KALOS_AR_SIZE = 72;
const short ALOLA_AR_SIZE = 86;

const short KANTO_START = 1;
const short JOHTO_START = 152;
const short HOENN_START = 252;
const short SINNOH_START = 387;
const short UNOVA_START = 494;
const short KALOS_START = 650;
const short ALOLA_START = 722;

namespace Ui {
class MainWindow;
}

/************************************************************************
* MainWindow Class
* 	This class represents the MainWindow. It manages 9 attributes:
* 		ui, kantoUi, johtoUi, hoennUi, sinnohUi, unovaUi, kalosUi
*       alolaUi, pokedex
*************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * MainWindow (QWidget *parent = nullptr);
     *
     *   Constructor; this method initializes the QMainWindow object
     * --------------------------------------------------------------
     *   Parameters: parent (QWidget) - the invoking object
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    explicit MainWindow(QWidget *parent = nullptr); //Constructor

    /****************************************************************
     * ~MainWindow ();
     *
     *   Deconstructor; does not perform any specific function
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    ~MainWindow();//Deconstructor

    /****************************************************************
     * 	void CreatePokedex();
     *
     *   Mutator; this creates the Pokedex needed for all functions
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void CreatePokedex();

private slots:

    /****************************************************************
     * 	void on_kantoButton_clicked();
     *
     *   Slots; this shows the Kanto region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_kantoButton_clicked();

    /****************************************************************
     * 	void on_johtoButton_clicked();
     *
     *   Slots; this shows the Johto region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_johtoButton_clicked();

    /****************************************************************
     * 	void on_hoennButton_clicked();
     *
     *   Slots; this shows the Hoenn region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_hoennButton_clicked();

    /****************************************************************
     * 	void on_sinnohButton_clicked();
     *
     *   Slots; this shows the Sinnoh region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_sinnohButton_clicked();

    /****************************************************************
     * 	void on_unovaButton_clicked();
     *
     *   Slots; this shows the Unova region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_unovaButton_clicked();

    /****************************************************************
     * 	void on_kalosButton_clicked();
     *
     *   Slots; this shows the Kalos region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_kalosButton_clicked();

    /****************************************************************
     * 	void on_alolaButton_clicked();
     *
     *   Slots; this shows the Alola region
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_alolaButton_clicked();

    /****************************************************************
     * 	void on_actionSearch_triggered();
     *
     *   Slots; this prompts the user to enter a pokemon name and then searches
     *          for it. If found, the pokemon is displayed and if not,
     *          an error message is displayed
     * --------------------------------------------------------------
     *   Parameters: none
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void on_actionSearch_triggered();

    /****************************************************************
     * 	void CatchSignal(const int& POKEMON_NUMBER);
     *
     *   Slots; this catches the signal that is thrown and displays the given
     *          Pokemon that is found
     * --------------------------------------------------------------
     *   Parameters: POKEMON_NUMBER (int) - the pokedex number of the pokemon
     * --------------------------------------------------------------
     *   Return: none
     ***************************************************************/
    void CatchSignal(const int& POKEMON_NUMBER);

private:
    Ui::MainWindow  *ui;        //The ui for the main window
    Region          *kantoUi;   //The ui for the Kanto Region
    Region          *johtoUi;   //The ui for the Johto Region
    Region          *hoennUi;   //The ui for the Hoenn Region
    Region          *sinnohUi;  //The ui for the Sinnoh Region
    Region          *unovaUi;   //The ui for the Unova Region
    Region          *kalosUi;   //The ui for the Kalos Region
    Region          *alolaUi;   //The ui for the Alola Region
    Pokedex         *pokedex;   //The Pokedex
};

#endif // MAINWINDOW_H
