#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::MainWindow){
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

    this->pokedex  = new Pokedex;

    this->CreatePokedex();

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
            this,    SLOT  (CatchSignal       (int)));

    connect(johtoUi, SIGNAL(evolutionNumberSig(int)),
            this,    SLOT  (CatchSignal       (int)));

    connect(hoennUi, SIGNAL(evolutionNumberSig(int)),
            this,    SLOT  (CatchSignal       (int)));

    connect(sinnohUi, SIGNAL(evolutionNumberSig(int)),
            this,     SLOT  (CatchSignal       (int)));

    connect(unovaUi, SIGNAL(evolutionNumberSig(int)),
            this,    SLOT  (CatchSignal       (int)));

    connect(kalosUi, SIGNAL(evolutionNumberSig(int)),
            this,    SLOT  (CatchSignal       (int)));

    connect(alolaUi, SIGNAL(evolutionNumberSig(int)),
            this,    SLOT  (CatchSignal       (int)));

    this->setCentralWidget(ui->regionBox);
;}

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

//Create the necessary functions to make a Pokedex work
void MainWindow::CreatePokedex()
{
    using namespace globalPDexConsts;

    //PROCESSING - Create the AttackDex
    this->pokedex->CreateAttackList(ATTACKDEX_FILE);

    //INPUT - Read in the data for each region from its file
    this->pokedex->LoadRegion(KANTO_INPUT_FILE, KANTO_DEX, KANTO_ATTACK_FILE);
    this->pokedex->LoadRegion(JOHTO_INPUT_FILE, JOHTO_DEX, JOHTO_ATTACK_FILE);
    this->pokedex->LoadRegion(HOENN_INPUT_FILE, HOENN_DEX, HOENN_ATTACK_FILE);
    this->pokedex->LoadRegion(SINNOH_INPUT_FILE,SINNOH_DEX,SINNOH_ATTACK_FILE);
    this->pokedex->LoadRegion(UNOVA_INPUT_FILE, UNOVA_DEX, UNOVA_ATTACK_FILE);
    this->pokedex->LoadRegion(KALOS_INPUT_FILE, KALOS_DEX, KALOS_ATTACK_FILE);
    this->pokedex->LoadRegion(ALOLA_INPUT_FILE, ALOLA_DEX, ALOLA_ATTACK_FILE);

    //PROCESSING - Create a copy of the Pokedex with only Pokemon values
    this->pokedex->CreatePokedexCopy();

    this->pokedex->SetEvolutions();
}

void MainWindow::on_kantoButton_clicked() {this->kantoUi->showMaximized();}

void MainWindow::on_johtoButton_clicked() {this->johtoUi->showMaximized();}

void MainWindow::on_hoennButton_clicked() {this->hoennUi->showMaximized();}

void MainWindow::on_sinnohButton_clicked(){this->sinnohUi->showMaximized();}

void MainWindow::on_unovaButton_clicked() {this->unovaUi->showMaximized();}

void MainWindow::on_kalosButton_clicked() {this->kalosUi->showMaximized();}

void MainWindow::on_alolaButton_clicked() {this->alolaUi->showMaximized();}

//Search through the pokedex for a pokemon matching the input
void MainWindow::on_actionSearch_triggered()
{
    bool ok;             //PROC       - the condition if ok was pressed
    bool found = false;  //PROC       - the condition if the pokemon was found

    int index  = 0;      //PROC       - the position where the pokemon was found

    QString text;        //IN         - the text entered from the user

    string name;         //PROC & OUT - the name of the Pokemon

    //Get the name of the Pokemon from the user
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
            if(!(*pokedex)[index].currentPkmn.GetName().compare(name)){
                found = true;
            }
            else{
                index++;
            }
        }

        //If the pokemon is found then emit the pokedex number
        if(found){
            CatchSignal((*pokedex)[index].currentPkmn.GetPokedexNumber());
        }
        else{
            QMessageBox::warning(this, "Warning",text +" is an invalid name");
        }
    }
}

//Catch the signal that is thrown
void MainWindow::CatchSignal(const int& POKEMON_NUMBER)
{
    if(POKEMON_NUMBER < JOHTO_START){
        this->kantoUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER < HOENN_START){
        this->johtoUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER < SINNOH_START){
        this->hoennUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER < UNOVA_START){
        this->sinnohUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER < KALOS_START){
        this->unovaUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER < ALOLA_START){
        this->kalosUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else{
        this->alolaUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);}
}

void MainWindow::on_actionType_Chart_triggered(){
    this->typeChart->showMaximized();
}

void MainWindow::on_actionNature_Chart_triggered(){
    this->natureChart->showMaximized();
}
