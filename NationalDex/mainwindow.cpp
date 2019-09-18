#include "mainwindow.h"
#include "ui_mainwindow.h"

/************************************************************************
* Method MainWindow: Class MainWindow
*----------------------------------------------------------------------
* 	 This method creates the MainWindow object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       parent (QWidget) - the invoking object
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vector<Pkmn> kantoVect; //PROC - the vector of the Kanto region
    vector<Pkmn> johtoVect; //PROC - the vector of the Johto region
    vector<Pkmn> hoennVect; //PROC - the vector of the Hoenn region
    vector<Pkmn> sinnohVect;//PROC - the vector of the Sinnoh region
    vector<Pkmn> unovaVect; //PROC - the vector of the Unova region
    vector<Pkmn> kalosVect; //PROC - the vector of the Kalos region
    vector<Pkmn> alolaVect; //PROC - the vector of the Alola region

    //PROCESSING - Reserve enough space for each vector
    kantoVect .reserve(KANTO_AR_SIZE);
    johtoVect .reserve(JOHTO_AR_SIZE);
    hoennVect .reserve(HOENN_AR_SIZE);
    sinnohVect.reserve(SINNOH_AR_SIZE);
    unovaVect .reserve(UNOVA_AR_SIZE);
    kalosVect .reserve(KALOS_AR_SIZE);
    alolaVect .reserve(ALOLA_AR_SIZE);

    pokedex  = new Pokedex;

    //PROCESSING - Create the Pokedex for the program
    CreatePokedex();

    //PROCESSING - Store each region in its corresponding vector
    kantoVect  = pokedex->GetRegion(0, globalPDexConsts::KANTO_DEX);
    johtoVect  = pokedex->GetRegion(   globalPDexConsts::KANTO_DEX,
                                       globalPDexConsts::JOHTO_DEX);
    hoennVect  = pokedex->GetRegion(   globalPDexConsts::JOHTO_DEX,
                                       globalPDexConsts::HOENN_DEX);
    sinnohVect = pokedex->GetRegion(   globalPDexConsts::HOENN_DEX,
                                       globalPDexConsts::SINNOH_DEX);
    unovaVect  = pokedex->GetRegion(   globalPDexConsts::SINNOH_DEX,
                                       globalPDexConsts::UNOVA_DEX);
    kalosVect  = pokedex->GetRegion(   globalPDexConsts::UNOVA_DEX,
                                       globalPDexConsts::KALOS_DEX);
    alolaVect  = pokedex->GetRegion(   globalPDexConsts::KALOS_DEX,
                                       globalPDexConsts::ALOLA_DEX);

    kantoUi     = new Region(this, KANTO_START, kantoVect);
    johtoUi     = new Region(this, JOHTO_START, johtoVect);
    hoennUi     = new Region(this, HOENN_START, hoennVect);
    sinnohUi    = new Region(this, SINNOH_START, sinnohVect);
    unovaUi     = new Region(this, UNOVA_START, unovaVect);
    kalosUi     = new Region(this, KALOS_START, kalosVect);
    alolaUi     = new Region(this, ALOLA_START, alolaVect);
    typeChart   = new TypeEffectChart(this);
    natureChart = new NatureEffectChart(this);

    //PROCESSING - Connect the objects with the signals
    connect(kantoUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    connect(johtoUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    connect(hoennUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    connect(sinnohUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    connect(unovaUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    connect(kalosUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    connect(alolaUi, SIGNAL(evolutionNumberSig(int)),
            this, SLOT(CatchSignal(int)));

    this->setCentralWidget(ui->regionBox);
;}

/************************************************************************
* Method ~MainWindow: Class MainWindow
*----------------------------------------------------------------------
* 	 This method deletes the Dialog object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
    delete kantoUi;
    delete johtoUi;
    delete hoennUi;
    delete sinnohUi;
    delete unovaUi;
    delete kalosUi;
    delete alolaUi;
    delete pokedex;
    delete typeChart;
    delete natureChart;
}

/************************************************************************
* Method CreatePokedex: Class MainWindow
*----------------------------------------------------------------------
* 	 This method creates the Pokedex
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::CreatePokedex()
{
    using namespace globalPDexConsts;

    //PROCESSING - Create the AttackDex
    pokedex->CreateAttackList(ATTACKDEX_FILE);

    //INPUT - Read in the data from the  Kanto file
    pokedex->LoadRegion(KANTO_INPUT_FILE, KANTO_DEX, KANTO_ATTACK_FILE);

    //INPUT - Read in the data from the  Johto file
    pokedex->LoadRegion(JOHTO_INPUT_FILE, JOHTO_DEX, JOHTO_ATTACK_FILE);

    //INPUT - Read in the data from the  Hoenn file
    pokedex->LoadRegion(HOENN_INPUT_FILE, HOENN_DEX, HOENN_ATTACK_FILE);

    //INPUT - Read in the data from the  Sinnoh file
    pokedex->LoadRegion(SINNOH_INPUT_FILE, SINNOH_DEX, SINNOH_ATTACK_FILE);

    //INPUT - Read in the data from the  Unova file
    pokedex->LoadRegion(UNOVA_INPUT_FILE, UNOVA_DEX, UNOVA_ATTACK_FILE);

    //INPUT - Read in the data from the  Kalos file
    pokedex->LoadRegion(KALOS_INPUT_FILE, KALOS_DEX, KALOS_ATTACK_FILE);

    //INPUT - Read in the data from the  Alola file
    pokedex->LoadRegion(ALOLA_INPUT_FILE, ALOLA_DEX, ALOLA_ATTACK_FILE);

    //PROCESSING - Create a copy of the Pokedex with only Pokemon
    pokedex->CreatePokedexCopy();

    //PROCESSING - Set the evolutions for the Pokemon
    pokedex->SetEvolutions();
}

/************************************************************************
* Method on_kantoButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Kanto Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_kantoButton_clicked(){kantoUi->showMaximized();}

/************************************************************************
* Method on_johtoButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Johto Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_johtoButton_clicked(){johtoUi->showMaximized();}

/************************************************************************
* Method on_hoennButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Hoenn Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_hoennButton_clicked(){hoennUi->showMaximized();}

/************************************************************************
* Method on_sinnohButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Sinnoh Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_sinnohButton_clicked(){sinnohUi->showMaximized();}

/************************************************************************
* Method on_unovaButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Unova Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_unovaButton_clicked(){unovaUi->showMaximized();}

/************************************************************************
* Method on_kalosButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Kalos Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_kalosButton_clicked(){kalosUi->showMaximized();}

/************************************************************************
* Method on_alolaButton_clicked: Class MainWindow
*----------------------------------------------------------------------
* 	 This method displays the Alola Region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_alolaButton_clicked(){alolaUi->showMaximized();}

/************************************************************************
* Method on_actionSearch_triggered: Class MainWindow
*----------------------------------------------------------------------
* 	 This method prompts the user to enter a pokemon name and then searches
*       for it. If found, the pokemon is displayed and if not, an error message
*       is displayed
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::on_actionSearch_triggered()
{
    bool ok;        //PROC       - the condition if ok was pressed
    bool found;     //PROC       - the condition if the pokemon was found

    int index;      //PROC       - the position where the pokemon was found

    QString text;   //IN         - the text entered from the user

    string name;    //PROC & OUT - the name of the Pokemon

    found = false;
    index = 0;
    text  = QInputDialog::getText(this, tr("Search!"),
                                  tr("Pokemon Name:"), QLineEdit::Normal,
                                  "", &ok);

    //PROCESSING - If the user pressed Ok and the line is not empty,
    //             search for the given pokemon
    if (ok && !text.isEmpty())
    {
        //Capitalize the name of the Pokemon
        name    = text.toStdString();

        name[0] = std::toupper(name[0]);

        while(!found && index < globalPDexConsts::AR_SIZE)
        {
            if(!(*pokedex)[index].currentPkmn.GetName().compare(name))
                found = true;
            else{index++;}
        }

        //PROCESSING/OUTPUT - If the pokemon is found than emit the given
        //                    signal of the pokedex number
        if(found)
            {CatchSignal((*pokedex)[index].currentPkmn.GetPokedexNumber());}
        else{QMessageBox::warning(this, "Warning",text +" is an invalid name");}
    }
}

/************************************************************************
* Method CatchSignal: Class MainWindow
*----------------------------------------------------------------------
* 	 This method catches the signal that is thrown in order to display
*       the pokemon based off the Pokemon number thrown
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       POKEMON_NUMBER (int) - the pokedex number of the chosen Pokemon
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void MainWindow::CatchSignal(const int& POKEMON_NUMBER)
{
    if(POKEMON_NUMBER < JOHTO_START)
    {kantoUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}

    else if(POKEMON_NUMBER < HOENN_START)
    {johtoUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}

    else if(POKEMON_NUMBER < SINNOH_START)
    {hoennUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}

    else if(POKEMON_NUMBER < UNOVA_START)
    {sinnohUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}

    else if(POKEMON_NUMBER < KALOS_START)
    {unovaUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}

    else if(POKEMON_NUMBER < ALOLA_START)
    {kalosUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}

    else{alolaUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}
}

void MainWindow::on_actionType_Chart_triggered()
{
    typeChart->showMaximized();
}

void MainWindow::on_actionNature_Chart_triggered()
{
    natureChart->showMaximized();
}
