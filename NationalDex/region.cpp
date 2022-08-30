#include "region.h"
#include "ui_region.h"

Region::Region(QWidget *parent, const vector<Pkmn>& REGION_VECT)
        :QMainWindow(parent), ui(new Ui::Region){
    ui->setupUi(this);
    this->regionVect  = REGION_VECT;

    CreateList();

    //PROCESSING - Set the layout for the window
    mainWidget = new QWidget(ui->centralwidget);
    gridLayout = new QGridLayout;
    mainWidget->setLayout(gridLayout);

    scrollArea = new QScrollArea;
    scrollArea->setWidget(mainWidget);
    scrollArea->setWidgetResizable( true );
    scrollArea->setBackgroundRole(QPalette::Dark);

    mainLayout = new QHBoxLayout(ui->centralwidget);
    ui->centralwidget->setLayout(mainLayout);
    mainLayout->addWidget(scrollArea);

    PrintList();

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - connect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this,          SLOT  (CatchSignal    (int)));

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

Region::~Region(){
    delete ui;
    delete scrollArea;
    delete gridLayout;
    delete mainLayout;
    delete mainWidget;
    delete pokemonDialog;

    for(auto it: list){delete (it);}
    for(auto it: dialogList){delete (it);}

    QVector<QPushButton*>().swap(list);
    QVector<Dialog*>().swap(dialogList);

    list.clear();
    dialogList.clear();
}

void Region::CreateList(){
    unsigned int regionSize = this->regionVect.size();

    unsigned int currentPokemonNumber;

    unsigned int newIndex = 0;

    QString path;

    list.reserve(regionSize);

    //PROCESSING - Loop through each Pokemon in the region and create the
    //             QPushButtons
    for(unsigned int index = 0; index < regionSize; ++index)
    {
        if(regionVect[index].currentPkmn.GetVersionOneLocation() != "None"){
            currentPokemonNumber = regionVect[index].currentPkmn.GetPokedexNumber();

            path = (GlobalRegionConsts::IMAGE_PATH +
                    QString::number(currentPokemonNumber) + ".png");
            QPixmap pixmap(path);
            QIcon pokemonIcon(pixmap);

            QPushButton *pokemonButton = new QPushButton;

            pokemonButton->setIcon(pokemonIcon);

            pokemonButton->setIconSize(pixmap.rect().size());

            //PROCESSING - Make it so that I know which button is clicked
            pokemonButton->setCheckable(true);

            //PROCESSING - Connect the button with the Dialog
            connect(pokemonButton, SIGNAL(clicked()), this, SLOT(GoToDialog()));

            //OUTPUT - put the name of the pokemon and number on the button
            pokemonButton->setText
            ( QString::number(currentPokemonNumber)
              + " " +
              QString::fromStdString(regionVect[index].currentPkmn.GetName())
            );

            list.push_back(pokemonButton);
            regionVect[newIndex++] = regionVect[index];
        }
    }
}

void Region::LoadSpecificPokemon(const Pkmn &POKEMON){
    //PROCESSING - Intitialize the Dialog with the Pokemon's information
    pokemonDialog->SetPokemonValues(POKEMON);

    pokemonDialog->showMaximized();
    dialogList.push_back(pokemonDialog);

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - connect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this,          SLOT  (CatchSignal    (int)));
}

void Region::PrintList() const{
    unsigned int regionSize = this->list.size(); //PROC - size of the list
    for(unsigned int index = 0; index < regionSize; ++index){
        gridLayout->addWidget(list[index]);
    }
}

void Region::GoToDialog(){
    unsigned int index      = 0;
    unsigned int foundIndex = 0;
    unsigned int regionSize = this->list.size();

    bool found = false;

    Pkmn foundPokemon;

    while(!found && index < regionSize){
        if(list[index]->isChecked()){
            list[index]->setChecked(false);
            foundIndex = index;
            found      = true;
        }
        else{
            ++index;
        }
    }

    foundPokemon = regionVect[foundIndex];

    pokemonDialog->SetPokemonValues(foundPokemon);

    pokemonDialog->showMaximized();

    dialogList.push_back(pokemonDialog);

    pokemonDialog = new Dialog(this);

    //PROCESSING - reconnect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this,          SLOT  (CatchSignal    (int)));
}

void Region::on_actionSearch_triggered()
{
    bool ok;
    bool found = false;

    unsigned int index      = 0;
    unsigned int regionSize = this->regionVect.size();

    QString text;

    string name;

    text  = QInputDialog::getText(this, tr("Search for a Pokemon"),
                                  tr("Pokemon Name:"), QLineEdit::Normal,
                                  "", &ok);

    if (ok && !text.isEmpty()){
        //PROCESSING - Capitalize the name
        name    = text.toStdString();
        name[0] = std::toupper(name[0]);

        while(!found && index < regionSize){
            if(!regionVect[index].currentPkmn.GetName().compare(name) &&
                regionVect[index].currentPkmn.GetVersionOneLocation() != "None")
            {
                found = true;
            }
            else{
                ++index;
            }
        }

        if(found){
            this->CatchSignal(regionVect[index].currentPkmn.GetPokedexNumber());
        }
        else{
            QMessageBox::warning(this, "Warning",text +" is an invalid name or "
                                 "not found in this region of the dex");
        }
    }
}
