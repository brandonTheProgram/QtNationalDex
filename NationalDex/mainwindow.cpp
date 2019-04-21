#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vector<Pkmn> kantoVect; //PROC - the vector of the Kanto region
    vector<Pkmn> johtoVect; //PROC - the vector of the Johto region
    vector<Pkmn> hoennVect; //PROC - the vector of the Hoenn region
    vector<Pkmn> sinnohVect;//PROC - the vector of the Sinnoh region
    vector<Pkmn> unovaVect; //PROC - the vector of the Unova region
    vector<Pkmn> kalosVect; //PROC - the vector of the Kalos region
    vector<Pkmn> alolaVect; //PROC - the vector of the Alola region

    //PROCESSING - Reserve enough space for each vector
    kantoVect.reserve(KANTO_AR_SIZE);
    johtoVect.reserve(JOHTO_AR_SIZE);
    hoennVect.reserve(HOENN_AR_SIZE);
    sinnohVect.reserve(SINNOH_AR_SIZE);
    unovaVect.reserve(UNOVA_AR_SIZE);
    kalosVect.reserve(KALOS_AR_SIZE);
    alolaVect.reserve(ALOLA_AR_SIZE);

    ui->setupUi(this);

    kantoUi  = new Kanto(this);
    johtoUi  = new Johto(this);
    hoennUi  = new Hoenn(this);
    sinnohUi = new Sinnoh(this);
    unovaUi  = new Unova(this);
    kalosUi  = new Kalos(this);
    alolaUi  = new Alola(this);
    pokedex  = new Pokedex;

    //PROCESSING - Create the Pokedex for the program
    CreatePokedex();

    //PROCESSING - Store each region in its corresponding vector
    kantoVect  = pokedex->GetRegion(0, globalPDexConsts::KANTO_DEX);
    johtoVect  = pokedex->GetRegion(globalPDexConsts::KANTO_DEX, globalPDexConsts::JOHTO_DEX);
    hoennVect  = pokedex->GetRegion(globalPDexConsts::JOHTO_DEX, globalPDexConsts::HOENN_DEX);
    sinnohVect = pokedex->GetRegion(globalPDexConsts::HOENN_DEX, globalPDexConsts::SINNOH_DEX);
    unovaVect  = pokedex->GetRegion(globalPDexConsts::SINNOH_DEX, globalPDexConsts::UNOVA_DEX);
    kalosVect  = pokedex->GetRegion(globalPDexConsts::UNOVA_DEX, globalPDexConsts::KALOS_DEX);
    alolaVect  = pokedex->GetRegion(globalPDexConsts::KALOS_DEX, globalPDexConsts::ALOLA_DEX);

    this->setCentralWidget(ui->regionBox);

    //Set the region vecotrs for each region
    kantoUi->SetRegionVect(kantoVect);
    johtoUi->SetRegionVect(johtoVect);
    hoennUi->SetRegionVect(hoennVect);
    sinnohUi->SetRegionVect(sinnohVect);
    unovaUi->SetRegionVect(unovaVect);
    kalosUi->SetRegionVect(kalosVect);
    alolaUi->SetRegionVect(alolaVect);
;}

//Deconstructor
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
}

//Create the Pokedex
void MainWindow::CreatePokedex()
{
    using namespace globalPDexConsts;
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
    const string OUTPUT_FILE        = "OFile.txt";
    const string ATTACKDEX_FILE     = "AttackDex.txt";

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

//Display the Kanto Region
void MainWindow::on_kantoButton_clicked()
{
    kantoUi->show();
    kantoUi->showMaximized();
}

//Display the Johto Region
void MainWindow::on_johtoButton_clicked()
{
    johtoUi->show();
    johtoUi->showMaximized();
}

//Display the Hoenn Region
void MainWindow::on_hoennButton_clicked()
{
    hoennUi->show();
    hoennUi->showMaximized();
}

//Display the Sinnoh Region
void MainWindow::on_sinnohButton_clicked()
{
    sinnohUi->show();
    sinnohUi->showMaximized();
}

//Display the Unova Region
void MainWindow::on_unovaButton_clicked()
{
    unovaUi->show();
    unovaUi->showMaximized();
}

//Display the Kalos Region
void MainWindow::on_kalosButton_clicked()
{
    kalosUi->show();
    kalosUi->showMaximized();
}

//Display the Alola Region
void MainWindow::on_alolaButton_clicked()
{
    alolaUi->show();
    alolaUi->showMaximized();
}
