#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    vector<Pkmn> everyRegionVect;   //PROC - the vector of every region
    vector<Pkmn> kantoVect;         //PROC - the vector of the Kanto region
    vector<Pkmn> johtoVect;         //PROC - the vector of the Johto region
    vector<Pkmn> hoennVect;         //PROC - the vector of the Hoenn region
    vector<Pkmn> sinnohVect;        //PROC - the vector of the Sinnoh region
    vector<Pkmn> unovaVect;         //PROC - the vector of the Unova region
    vector<Pkmn> kalosVect;         //PROC - the vector of the Kalos region
    vector<Pkmn> alolaVect;         //PROC - the vector of the Alola region
    vector<Pkmn> galarVect;         //PROC - the vector of the Galar region

    //Enables Dark Mode
    this->DarkMode();

    //PROCESSING - Reserve enough space for each vector
    everyRegionVect .reserve(WORLD_AR_SIZE);
    kantoVect       .reserve(KANTO_AR_SIZE);
    johtoVect       .reserve(JOHTO_AR_SIZE);
    hoennVect       .reserve(HOENN_AR_SIZE);
    sinnohVect      .reserve(SINNOH_AR_SIZE);
    unovaVect       .reserve(UNOVA_AR_SIZE);
    kalosVect       .reserve(KALOS_AR_SIZE);
    alolaVect       .reserve(ALOLA_AR_SIZE);
    galarVect       .reserve(GALAR_AR_SIZE);

    this->pokedex  = new Pokedex;

    //PROCESSING - Read in data from the input files
    this->CreatePokedex();

    //PROCESSING - Store each region in its corresponding vector
    everyRegionVect = pokedex->GetRegion(0,             ENDING_DEX);
    kantoVect       = pokedex->GetRegion(0,             KANTO_DEX);
    johtoVect       = pokedex->GetRegion(KANTO_DEX,     JOHTO_DEX);
    hoennVect       = pokedex->GetRegion(JOHTO_DEX,     HOENN_DEX);
    sinnohVect      = pokedex->GetRegion(HOENN_DEX,     SINNOH_DEX);
    unovaVect       = pokedex->GetRegion(SINNOH_DEX,    UNOVA_DEX);
    kalosVect       = pokedex->GetRegion(UNOVA_DEX,     KALOS_DEX);
    alolaVect       = pokedex->GetRegion(KALOS_DEX,     ALOLA_DEX);
    galarVect       = pokedex->GetRegion(ALOLA_DEX,     GALAR_DEX);

    //PROCESSING - Create the region UIs using their corresponding vectors
    everyRegionUi = new Region(this, everyRegionVect);
    kantoUi       = new Region(this, kantoVect);
    johtoUi       = new Region(this, johtoVect);
    hoennUi       = new Region(this, hoennVect);
    sinnohUi      = new Region(this, sinnohVect);
    unovaUi       = new Region(this, unovaVect);
    kalosUi       = new Region(this, kalosVect);
    alolaUi       = new Region(this, alolaVect);
    galarUi       = new Region(this, galarVect);
    typeChart     = new TypeEffectChart(this);
    natureChart   = new NatureEffectChart(this);

    //PROCESSING - Connect the objects with the signals
    connect(everyRegionUi, SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));
    connect(ui->allPokemonButton, SIGNAL(clicked()),
            this,          SLOT(on_everyRegionButtonClicked()));
    connect(kantoUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(johtoUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(hoennUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(sinnohUi,      SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(unovaUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(kalosUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(alolaUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    connect(galarUi,       SIGNAL(evolutionNumberSig(int)),
            this,          SLOT  (CatchSignal       (int)));

    this->setCentralWidget(ui->regionBox);
;}

MainWindow::~MainWindow()
{
    delete ui;
    delete everyRegionUi;
    delete kantoUi;
    delete johtoUi;
    delete hoennUi;
    delete sinnohUi;
    delete unovaUi;
    delete kalosUi;
    delete alolaUi;
    delete galarUi;
    delete pokedex;
    delete typeChart;
    delete natureChart;
}

//Create the necessary functions to make a Pokedex work
void MainWindow::CreatePokedex()
{
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
    this->pokedex->LoadRegion(GALAR_INPUT_FILE, GALAR_DEX, GALAR_ATTACK_FILE);

    //PROCESSING - Create a copy of the Pokedex with only Pokemon values
    this->pokedex->CreatePokedexCopy();

    //PROCESSING - Set the evolutions for all Pokemon that can evolve
    this->pokedex->SetEvolutions();
}

void MainWindow::DarkMode(){
    // Create a palette for a dark theme
    QPalette darkPalette;

    //Creates a different GUI interface with a Fusion style
    qApp->setStyle(QStyleFactory::create("Fusion"));

    // Customize the color palette for the interface elements
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    // Install this palette
    qApp->setPalette(darkPalette);
}

void MainWindow::on_everyRegionButtonClicked(){
    this->everyRegionUi->showMaximized();
}

void MainWindow::on_kantoButton_clicked() {
    this->kantoUi->showMaximized();}

void MainWindow::on_johtoButton_clicked() {
    this->johtoUi->showMaximized();
}

void MainWindow::on_hoennButton_clicked() {
    this->hoennUi->showMaximized();
}

void MainWindow::on_sinnohButton_clicked(){
    this->sinnohUi->showMaximized();
}

void MainWindow::on_unovaButton_clicked() {
    this->unovaUi->showMaximized();
}

void MainWindow::on_kalosButton_clicked() {
    this->kalosUi->showMaximized();
}

void MainWindow::on_alolaButton_clicked() {
    this->alolaUi->showMaximized();
}

void MainWindow::on_galarButton_clicked() {
    this->galarUi->showMaximized();
}

//Search through the pokedex for a pokemon matching the input
void MainWindow::on_actionSearch_triggered()
{
    bool ok;
    bool found = false;

    unsigned int index  = 0;

    QString text;

    string name;

    text  = QInputDialog::getText(this, tr("Search!"),
                                  tr("Pokemon Name:"), QLineEdit::Normal,
                                  "", &ok);

    if (ok && !text.isEmpty())
    {
        //Capitalize the name of the Pokemon
        name    = text.toStdString();
        name[0] = std::toupper(name[0]);

        while(!found && index < globalPDexConsts::AR_SIZE)
        {
            if(!(*pokedex)[index].currentPkmn.GetName().compare(name) &&
                (*pokedex)[index].currentPkmn.GetVersionOneLocation() != "None")
            {
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
            QMessageBox::warning(this, "Warning",text +" is an invalid name or "
                                 "not found in this region of the dex");
        }
    }
}

//Catch the signal that is thrown
void MainWindow::CatchSignal(const int& POKEMON_NUMBER)
{
    if(POKEMON_NUMBER <= KANTO_DEX){
        this->kantoUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER <= JOHTO_DEX){
        this->johtoUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER <= HOENN_DEX){
        this->hoennUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER <= SINNOH_DEX){
        this->sinnohUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER <= UNOVA_DEX){
        this->unovaUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER <= KALOS_DEX){
        this->kalosUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else if(POKEMON_NUMBER <= ALOLA_DEX){
        this->alolaUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }

    else{
        this->galarUi->LoadSpecificPokemon((*pokedex)[POKEMON_NUMBER-1]);
    }
}

void MainWindow::on_actionType_Chart_triggered(){
    this->typeChart->showMaximized();
}

void MainWindow::on_actionNature_Chart_triggered(){
    this->natureChart->showMaximized();
}
