#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "kanto.h"
#include "johto.h"
#include "hoenn.h"
#include "sinnoh.h"
#include "unova.h"
#include "kalos.h"
#include "alola.h"
#include <QMainWindow>

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
    //Constructor
    explicit MainWindow(QWidget *parent = nullptr);

    //Deconstructor
    ~MainWindow();

    /****************************************************************
     * 	void CreatePokedex();
     *
     *   Mutator; this creates the Pokedex needed for all functions
     *   Return: none
     ***************************************************************/
    void CreatePokedex();

private slots:

    /****************************************************************
     * 	void on_kantoButton_clicked();
     *
     *   Slots; this shows the Kanto region
     *   Return: none
     ***************************************************************/
    void on_kantoButton_clicked();

    /****************************************************************
     * 	void on_johtoButton_clicked();
     *
     *   Slots; this shows the Johto region
     *   Return: none
     ***************************************************************/
    void on_johtoButton_clicked();

    /****************************************************************
     * 	void on_hoennButton_clicked();
     *
     *   Slots; this shows the Hoenn region
     *   Return: none
     ***************************************************************/
    void on_hoennButton_clicked();

    /****************************************************************
     * 	void on_sinnohButton_clicked();
     *
     *   Slots; this shows the Sinnoh region
     *   Return: none
     ***************************************************************/
    void on_sinnohButton_clicked();

    /****************************************************************
     * 	void on_unovaButton_clicked();
     *
     *   Slots; this shows the Unova region
     *   Return: none
     ***************************************************************/
    void on_unovaButton_clicked();

    /****************************************************************
     * 	void on_kalosButton_clicked();
     *
     *   Slots; this shows the Kalos region
     *   Return: none
     ***************************************************************/
    void on_kalosButton_clicked();

    /****************************************************************
     * 	void on_alolaButton_clicked();
     *
     *   Slots; this shows the Alola region
     *   Return: none
     ***************************************************************/
    void on_alolaButton_clicked();

private:
    Ui::MainWindow  *ui;        //The ui for the main window
    Kanto           *kantoUi;   //The ui for the Kanto Region
    Johto           *johtoUi;   //The ui for the Johto Region
    Hoenn           *hoennUi;   //The ui for the Hoenn Region
    Sinnoh          *sinnohUi;  //The ui for the Sinnoh Region
    Unova           *unovaUi;   //The ui for the Unova Region
    Kalos           *kalosUi;   //The ui for the Kalos Region
    Alola           *alolaUi;   //The ui for the Alola Region
    Pokedex         *pokedex;   //The Pokedex
};

#endif // MAINWINDOW_H
