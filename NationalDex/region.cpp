#include "region.h"
#include "ui_region.h"

/************************************************************************
* Method Dialog: Class Dialog
*----------------------------------------------------------------------
* 	 This method creates the Dialog object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       parent       (QWidget)      - the invoking object
*       REGION_START (int)          - the starting pokedex number of the region
*       REGION_VECT  (vector<Pkmn>) - the vector holding the pokemon in
*                                     the region
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Region::Region(QWidget *parent, const int& REGION_START,
               const vector<Pkmn>& REGION_VECT) :
    QMainWindow(parent),
    ui(new Ui::Region)
{
    ui->setupUi(this);
    this->regionStart = REGION_START;
    this->regionVect  = REGION_VECT;

    //PROCESSING - Create the list of Pokemon QPushButtons
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

    //OUTPUT - Display the list of Pokemon QPushButtons
    PrintList();

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - connect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this, SLOT(CatchSignal(int)));

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

/************************************************************************
* Method ~Region: Class Region
*----------------------------------------------------------------------
* 	 This method deletes the Region object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Region::~Region()
{
    delete ui;
    delete scrollArea;
    delete gridLayout;
    delete mainLayout;
    delete mainWidget;
    delete pokemonDialog;

    for(auto it: list){delete (it);}

    list.clear();

    QVector<QPushButton*>().swap(list);
}

/************************************************************************
* Method CreateList: Class Region
*----------------------------------------------------------------------
* 	 This method creates the list of QPushButtons for the region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Region::CreateList()
{
    int     regionSize;     //PROC - the size of the region vector

    QString path;           //PROC - the path of the Pokemon image

    regionSize = this->regionVect.size();

    //PROCESSING - Reserve space for the region's Pokemon
    list.reserve(regionSize);

    //PROCESSING - Loop through each Pokemon in the region and create the
    //             QPushButtons
    for(int index = 0; index < regionSize; index++)
    {
        path = (PokemonImages::IMAGE_PATH + QString::number(index              +
                                                            this->regionStart) +
                                                            ".png");
        QPixmap pixmap(path);
        QIcon pokemonIcon(pixmap);

        QPushButton *pokemonButton = new QPushButton;

        pokemonButton->setIcon(pokemonIcon);

        pokemonButton->setIconSize(pixmap.rect().size());

        //PROCESSING - Make it so that I know which button is clicked
        pokemonButton->setCheckable(true);

        //PROCESSING - Connect the button with the Dialog
        connect(pokemonButton, SIGNAL(clicked()), this, SLOT(GoToDialog()));

        //OUTPUT - put the name of the pokemon on the button
        pokemonButton->setText
        (QString::fromStdString
         (regionVect[index].currentPkmn.GetName())
        );

        list.push_back(pokemonButton);
    }
}

/************************************************************************
* Method LoadSpecificPokemon: Class Region
*----------------------------------------------------------------------
* 	 This method will load a specific pokemon for the region
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       POKEMON (Pkmn) - the current pokemon
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Region::LoadSpecificPokemon(const Pkmn &POKEMON)
{
    //PROCESSING - Intitialize the Dialog with the Pokemon's information
    pokemonDialog->SetPokemon(POKEMON);

    pokemonDialog->show();
    pokemonDialog->resize(800, 800);

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - connect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this, SLOT(CatchSignal(int)));
}

/************************************************************************
* Method PrintList: Class Region
*----------------------------------------------------------------------
* 	 This method will print the list of Pokemon QPushButtons
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Region::PrintList() const
{
    int     regionSize;     //PROC - the size of the region vector

    regionSize = this->regionVect.size();

    for(int index = 0; index < regionSize; index++)
        {gridLayout->addWidget(list[index]);}
}

/************************************************************************
* Method GoToDialog: Class Region
*----------------------------------------------------------------------
* 	 This method will create the Dialog for the pokemon to display their info
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Region::GoToDialog()
{
    int index;          //PROC - the index in the array
    int foundIndex;     //PROC - the index of the found QPushButton

    bool found;         //PROC - the condition if the Button was found

    Pkmn foundPokemon;  //PROC - the found Pokemon

    int     regionSize; //PROC - the size of the region vector

    index      = 0;
    foundIndex = 0;
    found      = false;
    regionSize = this->regionVect.size();

    //PROCESSING - Loop through the buttons to find which one was clicked
    while(!found && index < regionSize)
    {
        if(list[index]->isChecked())
        {
            list[index]->setChecked(false);
            foundIndex = index;
            found = true;
        }
        else{index++;}
    }

    foundPokemon = regionVect[foundIndex];

    //PROCESSING - Intitialize the Dialog with the Pokemon's information
    pokemonDialog->SetPokemon(foundPokemon);

    pokemonDialog->show();
    pokemonDialog->resize(800, 800);

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog(this);

    //PROCESSING - connect the signal to open a new Pokemon
    connect(pokemonDialog, SIGNAL(evolutionNumber(int)),
            this, SLOT(CatchSignal(int)));
}

/************************************************************************
* Method on_actionSearch_triggered: Class Region
*----------------------------------------------------------------------
* 	 This method prompts the user to enter a pokemon name and then searches
*       for it in the given region. If found, the pokemon is displayed and if
*       not, an error message is displayed
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Region::on_actionSearch_triggered()
{
    bool ok;        //PROC - the condition if ok was pressed
    bool found;     //PROC - the condition if the pokemon was found

    int index;      //PROC - the position in the array
    int regionSize; //PROC - the size of the region vector

    QString text;   //IN   - the name that the user inputs

    string name;    //PROC - the name of the pokemon

    found = false;
    index = 0;
    text  = QInputDialog::getText(this, tr("Search for a Pokemon"),
                                  tr("Pokemon Name:"), QLineEdit::Normal,
                                  "", &ok);
    regionSize = this->regionVect.size();

    if (ok && !text.isEmpty())
    {
        //PROCESSING - Capitalize the name
        name    = text.toStdString();
        name[0] = std::toupper(name[0]);

        while(!found && index < regionSize)
        {
            if(!regionVect[index].currentPkmn.GetName().compare(name))
                found = true;

            else{index++;}
        }

        //PROCESSING - If the pokemon is found then emit the signal of
        //             the pokedex number
        if(found)
          {this->CatchSignal(regionVect[index].currentPkmn.GetPokedexNumber());}
        else
        {
            QMessageBox::warning(this, "Warning",text +" is an invalid name or "
                                 "not found in this region of the dex");
        }
    }
}
