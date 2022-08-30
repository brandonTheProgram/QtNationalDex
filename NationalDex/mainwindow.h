#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "region.h"
#include "typeeffectchart.h"
#include "natureeffectchart.h"
#include <QMainWindow>
#include <QStyleFactory>

/*!
 * \variable KANTO_INPUT_FILE
 * \brief The name of the input file for the Pokemon of the Kanto region
 */
const string KANTO_INPUT_FILE = "Kanto.txt";

/*!
 * \variable KANTO_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Kanto region
 */
const string KANTO_ATTACK_FILE = "KantoAttacks.txt";

/*!
 * \variable JOHTO_INPUT_FILE
 * \brief The name of the input file for the Pokemon of the Johto region
 */
const string JOHTO_INPUT_FILE = "Johto.txt";

/*!
 * \variable JOHTO_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Johto region
 */
const string JOHTO_ATTACK_FILE = "JohtoAttacks.txt";

/*!
 * \variable HOENN_INPUT_FILE
 * \brief The name of the input file for the Pokemon of the Hoenn region
 */
const string HOENN_INPUT_FILE = "Hoenn.txt";

/*!
 * \variable HOENN_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Hoenn region
 */
const string HOENN_ATTACK_FILE = "HoennAttacks.txt";

/*!
 * \variable SINNOH_INPUT_FILE
 * \brief The name of the input file for the Pokemon of the Sinnoh region
 */
const string SINNOH_INPUT_FILE = "Sinnoh.txt";

/*!
 * \variable SINNOH_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Sinnoh region
 */
const string SINNOH_ATTACK_FILE = "SinnohAttacks.txt";

/*!
 * \variable UNOVA_INPUT_FILE
 * \brief The name of the input file for the Pokemon of the Unova region
 */
const string UNOVA_INPUT_FILE = "Unova.txt";

/*!
 * \variable SINNOH_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Unova region
 */
const string UNOVA_ATTACK_FILE = "UnovaAttacks.txt";

/*!
 * \variable KALOS_INPUT_FILE
 * \brief The name of the input file for the Pokemon of the Kalos region
 */
const string KALOS_INPUT_FILE = "Kalos.txt";

/*!
 * \variable KALOS_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Kalos region
 */
const string KALOS_ATTACK_FILE = "KalosAttacks.txt";

/*!
 * \variable ALOLA_INPUT_FILE
 * \brief The name of the input file for the Pokemon moves of the Alola region
 */
const string ALOLA_INPUT_FILE = "Alola.txt";

/*!
 * \variable ALOLA_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Alola region
 */
const string ALOLA_ATTACK_FILE = "AlolaAttacks.txt";

/*!
 * \variable GALAR_INPUT_FILE
 * \brief The name of the input file for the Pokemon moves of the Galar region
 */
const string GALAR_INPUT_FILE = "Galar.txt";

/*!
 * \variable GALAR_ATTACK_FILE
 * \brief The name of the input file for the Pokemon moves of the Galar region
 */
const string GALAR_ATTACK_FILE = "GalarAttacks.txt";

/*!
 * \variable ATTACKDEX_FILE
 * \brief The name of the input file for every Pokemon move that exists
 */
const string ATTACKDEX_FILE = "AttackDex.txt";

/*!
 * \variable KANTO_AR_SIZE
 * \brief The amount of Pokemon in the Kanto region
 */
const unsigned short KANTO_AR_SIZE = 151;

/*!
 * \variable JOHTO_AR_SIZE
 * \brief The amount of Pokemon in the Johto region
 */
const unsigned short JOHTO_AR_SIZE = 100;

/*!
 * \variable HOENN_AR_SIZE
 * \brief The amount of Pokemon in the Hoenn region
 */
const unsigned short HOENN_AR_SIZE = 135;

/*!
 * \variable SINNOH_AR_SIZE
 * \brief The amount of Pokemon in the Sinnoh region
 */
const unsigned short SINNOH_AR_SIZE = 107;

/*!
 * \variable UNOVA_AR_SIZE
 * \brief The amount of Pokemon in the Unova region
 */
const unsigned short UNOVA_AR_SIZE = 156;

/*!
 * \variable KALOS_AR_SIZE
 * \brief The amount of Pokemon in the Kalos region
 */
const unsigned short KALOS_AR_SIZE = 72;

/*!
 * \variable ALOLA_AR_SIZE
 * \brief The amount of Pokemon in the Alola region
 */
const unsigned short ALOLA_AR_SIZE = 88;

/*!
 * \variable GALAR_AR_SIZE
 * \brief The amount of Pokemon in the Galar region
 */
const unsigned short GALAR_AR_SIZE = 89;

/*!
 * \variable WORLD_AR_SIZE
 * \brief The amount of Pokemon in the entire world
 */
const unsigned short WORLD_AR_SIZE = 898;

/*!
 * \variable KANTO_DEX
 * \brief The last pokedex number for the Kanto region
 */
const unsigned short KANTO_DEX = 151;

/*!
 * \variable JOHTO_DEX
 * \brief The last pokedex number for the Johto region
 */
const unsigned short JOHTO_DEX = 251;

/*!
 * \variable HOENN_DEX
 * \brief The last pokedex number for the Hoenn region
 */
const unsigned short HOENN_DEX = 386;

/*!
 * \variable SINNOH_DEX
 * \brief The last pokedex number for the Sinnoh region
 */
const unsigned short SINNOH_DEX = 493;

/*!
 * \variable UNOVA_DEX
 * \brief The last pokedex number for the Unova region
 */
const unsigned short UNOVA_DEX = 649;

/*!
 * \variable KALOS_DEX
 * \brief The last pokedex number for the Kalos region
 */
const unsigned short KALOS_DEX = 721;

/*!
 * \variable ALOLA_DEX
 * \brief The last pokedex number for the Alola region
 */
const unsigned short ALOLA_DEX = 809;

/*!
 * \variable GALAR_DEX
 * \brief The last pokedex number for the Galar region
 */
const unsigned short GALAR_DEX = 898;

/*!
 * \variable ENDING_DEX
 * \brief The last pokedex number for the entire world
 */
const unsigned short ENDING_DEX = 898;

namespace Ui {
class MainWindow;
}

/*!
 * \class MainWindow
 * \brief This class represents the MainWindow. It presents the regions and
 *        other options.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    /*!
     * \fn MainWindow(QWidget *parent = nullptr)
     * \brief This is the default constructor for the MainWindow
     * \param parent - the widget parent of the child object
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /*!
     * \fn ~MainWindow()
     * \brief This is the Deconstructor for the MainWindow
     */
    ~MainWindow();

    /*!
     * \fn CreatePokedex()
     * \brief This method reads and stores data from all the input files
     */
    void CreatePokedex();

    /*!
     * \fn DarkMode()
     * \brief This method creates the dark mode effects on the UI
     */
    void DarkMode();

private slots:
    /*!
     * \fn on_everyRegionButtonClicked()
     * \brief This method opens up the UI of every Pokemon in the world
     */
    void on_everyRegionButtonClicked();

    /*!
     * \fn on_kantoButton_clicked()
     * \brief This method opens up the UI of the Kanto region
     */
    void on_kantoButton_clicked();

    /*!
     * \fn on_johtoButton_clicked()
     * \brief This method opens up the UI of the Johto region
     */
    void on_johtoButton_clicked();

    /*!
     * \fn on_hoennButton_clicked()
     * \brief This method opens up the UI of the Hoenn region
     */
    void on_hoennButton_clicked();

    /*!
     * \fn on_sinnohButton_clicked()
     * \brief This method opens up the UI of the Sinnoh region
     */
    void on_sinnohButton_clicked();

    /*!
     * \fn on_unovaButton_clicked()
     * \brief This method opens up the UI of the Unova region
     */
    void on_unovaButton_clicked();

    /*!
     * \fn on_kalosButton_clicked()
     * \brief This method opens up the UI of the Kalos region
     */
    void on_kalosButton_clicked();

    /*!
     * \fn on_alolaButton_clicked()
     * \brief This method opens up the UI of the Alola region
     */
    void on_alolaButton_clicked();

    /*!
     * \fn on_galarButton_clicked()
     * \brief This method opens up the UI of the Galar region
     */
    void on_galarButton_clicked();

    /*!
     * \fn on_actionSearch_triggered()
     * \brief This method ask the user for input to serach for a Pokemon by name
     */
    void on_actionSearch_triggered();

    /*!
     * \fn atchSignal(const int& POKEMON_NUMBER)
     * \brief This method catches a thrown signal holding the index
     *        of a specific Pokemon in the Pokedex
     * \param POKEMON_NUMBER - the index number of the specific Pokemon
     */
    void CatchSignal(const int& POKEMON_NUMBER);

    /*!
     * \fn on_actionType_Chart_triggered()
     * \brief This method shows the Pokemon weakness type chart
     */
    void on_actionType_Chart_triggered();

    /*!
     * \fn on_actionNature_Chart_triggered()
     * \brief This method shows the Pokemon nature chart
     */
    void on_actionNature_Chart_triggered();

private:
    /*!
     * \variable ui
     * \brief The UI for the MainWindow
     */
    Ui::MainWindow *ui;

    /*!
     * \variable everyRegionUi
     * \brief The UI for the every Pokemon region
     */
    Region *everyRegionUi;

    /*!
     * \variable kantoUi
     * \brief The UI for the Pokemon of the Kanto region
     */
    Region *kantoUi;

    /*!
     * \variable johtoUi
     * \brief The UI for the Pokemon of the Johto region
     */
    Region *johtoUi;

    /*!
     * \variable hoennUi
     * \brief The UI for the Pokemon of the Hoenn region
     */
    Region *hoennUi;

    /*!
     * \variable sinnohUi
     * \brief The UI for the Pokemon of the Sinnoh region
     */
    Region *sinnohUi;

    /*!
     * \variable sinnohUi
     * \brief The UI for the Pokemon of the Unova region
     */
    Region *unovaUi;

    /*!
     * \variable kalosUi
     * \brief The UI for the Pokemon of the Kalos region
     */
    Region *kalosUi;

    /*!
     * \variable alolaUi
     * \brief The UI for the Pokemon of the Alola region
     */
    Region *alolaUi;

    /*!
     * \variable galarUi
     * \brief The UI for the Pokemon of the Galar region
     */
    Region *galarUi;

    /*!
     * \variable pokedex
     * \brief The encyclopedia which contains the information of every Pokemon
     */
    Pokedex *pokedex;

    /*!
     * \variable typeChart
     * \brief The Type Weakness Chart
     */
    TypeEffectChart *typeChart;

    /*!
     * \variable natureChart
     * \brief The Nature Chart
     */
    NatureEffectChart *natureChart;
};

#endif // MAINWINDOW_H
