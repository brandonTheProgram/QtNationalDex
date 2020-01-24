#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "region.h"
#include "typeeffectchart.h"
#include "natureeffectchart.h"
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
 * GALAR_INPUT_FILE   : the name of the input file for the Galar region
 * GALAR_ATTACK_FILE  : the name of the input file for the Galar attacks
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
 * GALAR_DEX    : The size of the Galar Pokedex
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
 * GALAR_START  : The starting pokedex number of the Galar region
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
const string GALAR_INPUT_FILE   = "Galar.txt";
const string GALAR_ATTACK_FILE  = "GalarAttacks.txt";
const string ATTACKDEX_FILE     = "AttackDex.txt";

const unsigned short KANTO_AR_SIZE  = 151;
const unsigned short JOHTO_AR_SIZE  = 100;
const unsigned short HOENN_AR_SIZE  = 135;
const unsigned short SINNOH_AR_SIZE = 107;
const unsigned short UNOVA_AR_SIZE  = 156;
const unsigned short KALOS_AR_SIZE  = 72;
const unsigned short ALOLA_AR_SIZE  = 88;
const unsigned short GALAR_AR_SIZE  = 81;

const unsigned short KANTO_START  = 1;
const unsigned short JOHTO_START  = 152;
const unsigned short HOENN_START  = 252;
const unsigned short SINNOH_START = 387;
const unsigned short UNOVA_START  = 494;
const unsigned short KALOS_START  = 650;
const unsigned short ALOLA_START  = 722;
const unsigned short GALAR_START  = 810;

namespace Ui {
class MainWindow;
}

/************************************************************************
* MainWindow Class
* 	This class represents the MainWindow.
*************************************************************************/
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); //Constructor

    ~MainWindow();//Deconstructor

    void CreatePokedex();

private slots:

    //Show the Kanto region
    void on_kantoButton_clicked();

    //Show the Johto region
    void on_johtoButton_clicked();

    //Show the Hoenn region
    void on_hoennButton_clicked();

    //Show the Sinnoh region
    void on_sinnohButton_clicked();

    //Show the Unova region
    void on_unovaButton_clicked();

    //Show the Kalos region
    void on_kalosButton_clicked();

    //Show the Alola region
    void on_alolaButton_clicked();

    //Show the Galar region
    void on_galarButton_clicked();

    //Ask the user for input to serach for a Pokemon by name and perform
    void on_actionSearch_triggered();

    //Catch a thrown signal holding the index of the Pokemon in the Pokedex
    void CatchSignal(const int& POKEMON_NUMBER);

    //Show the type chart
    void on_actionType_Chart_triggered();

    //Show the nature chart
    void on_actionNature_Chart_triggered();

private:
    Ui::MainWindow    *ui;            //The ui for the main window
    Region            *kantoUi;       //The ui for the Kanto Region
    Region            *johtoUi;       //The ui for the Johto Region
    Region            *hoennUi;       //The ui for the Hoenn Region
    Region            *sinnohUi;      //The ui for the Sinnoh Region
    Region            *unovaUi;       //The ui for the Unova Region
    Region            *kalosUi;       //The ui for the Kalos Region
    Region            *alolaUi;       //The ui for the Alola Region
    Region            *galarUi;       //The ui for the Galar Region
    Pokedex           *pokedex;       //The Pokedex
    TypeEffectChart   *typeChart;     //The Type Weakness Chart
    NatureEffectChart *natureChart;   //The Nature Chart
};

#endif // MAINWINDOW_H
