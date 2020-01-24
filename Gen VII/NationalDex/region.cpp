#include "region.h"
#include "ui_region.h"

Region::Region(QWidget *parent, const int& REGION_START,
               const vector<Pkmn>& REGION_VECT)
        :QMainWindow(parent), ui(new Ui::Region){
    ui->setupUi(this);
    this->regionStart = REGION_START;
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

    QVector<QPushButton*>().swap(list);

    list.clear();
}

void Region::CreateList(){
    int     regionSize = this->regionVect.size(); //PROC - size of the region

    QString path;                                 //PROC - Pokemon image path

    list.reserve(regionSize);

    //PROCESSING - Loop through each Pokemon in the region and create the
    //             QPushButtons
    for(int index = 0; index < regionSize; ++index)
    {
        path = (GlobalRegionConsts::IMAGE_PATH +
                QString::number(index + this->regionStart) + ".png");
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
        ( QString::number(regionVect[index].currentPkmn.GetPokedexNumber())
          + " " +
          QString::fromStdString(regionVect[index].currentPkmn.GetName())
        );

        list.push_back(pokemonButton);
    }
}

void Region::LoadSpecificPokemon(const Pkmn &POKEMON){
    //PROCESSING - Intitialize the Dialog with the Pokemon's information
    pokemonDialog->SetPokemon(POKEMON);

    pokemonDialog->show();
    pokemonDialog->resize(GlobalRegionConsts::DIALOG_SIZE.x(),
                          GlobalRegionConsts::DIALOG_SIZE.y());

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - connect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this,          SLOT  (CatchSignal    (int)));
}

void Region::PrintList() const{
    int regionSize = this->regionVect.size(); //PROC - size of the region vector

    for(int index = 0; index < regionSize; ++index){
        gridLayout->addWidget(list[index]);
    }
}

void Region::GoToDialog(){
    int index      = 0;                       //PROC - the index in the array
    int foundIndex = 0;                       //PROC - found QPushButton index
    int regionSize = this->regionVect.size(); //PROC - size of the region

    bool found = false;                       //PROC - the found condition

    Pkmn foundPokemon;                        //PROC - the found Pokemon

    //PROCESSING - Loop through the buttons to find which one was clicked
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

    //PROCESSING - Intitialize the Dialog with the Pokemon's information
    pokemonDialog->SetPokemon(foundPokemon);

    pokemonDialog->show();
    pokemonDialog->resize(GlobalRegionConsts::DIALOG_SIZE.x(),
                          GlobalRegionConsts::DIALOG_SIZE.y());

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - reconnect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this,          SLOT  (CatchSignal    (int)));
}

//Search through the vector for a Pokemon name
void Region::on_actionSearch_triggered()
{
    bool ok;                                  //PROC - the condition of Ok
    bool found = false;                       //PROC - the found condition

    int index = 0;                            //PROC - the position in the array
    int regionSize = this->regionVect.size(); //PROC - size of the region

    QString text;                             //IN   - the name input user

    string name;                              //PROC - the name of the pokemon

    text  = QInputDialog::getText(this, tr("Search for a Pokemon"),
                                  tr("Pokemon Name:"), QLineEdit::Normal,
                                  "", &ok);

    if (ok && !text.isEmpty()){
        //PROCESSING - Capitalize the name
        name    = text.toStdString();
        name[0] = std::toupper(name[0]);

        while(!found && index < regionSize){
            if(!regionVect[index].currentPkmn.GetName().compare(name)){
                found = true;
            }
            else{
                ++index;
            }
        }

        //PROCESSING - If the pokemon is found then emit the signal of
        //             the pokedex number
        if(found){
            this->CatchSignal(regionVect[index].currentPkmn.GetPokedexNumber());
        }
        else{
            QMessageBox::warning(this, "Warning",text +" is an invalid name or "
                                 "not found in this region of the dex");
        }
    }
}
