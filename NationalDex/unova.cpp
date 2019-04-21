#include "unova.h"
#include "ui_unova.h"

//Constructor
Unova::Unova(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Unova)
{
    ui->setupUi(this);

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

    //OUTPUT - Display hte list of Pokemon QPushButtons
    PrintList();

    //PROCESSING - Create the Dialog that will display the Pokemon's info
    pokemonDialog = new Dialog;

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

//Deconstructor
Unova::~Unova()
{
    delete ui;
    delete scrollArea;
    delete gridLayout;
    delete mainLayout;
    delete mainWidget;
    delete pokemonDialog;

    for(auto it: list)
        delete (it);
    list.clear();
    QVector<QPushButton*>().swap(list);
}

//Create a list of Pokemon QPushButtons for the region
void Unova::CreateList()
{
    //PROCESSING - Reserve space for the region's Pokemon
    list.reserve(UNOVA_AR_SIZE);

    QString path;   //PROC - the path of the Pokemon image

    //PROCESSING - Loop through each Pokemon in the region and create the
    //             QPushButtons
    for(int index = 0; index < UNOVA_AR_SIZE; index++)
    {
        path = (UnovaImages::IMAGE_PATH + QString::number(index + UNOVA_START) + ".png");

        QPixmap pixmap(path);
        QIcon pokemonIcon(pixmap);

        QPushButton *pokemonButton = new QPushButton;

        pokemonButton->setIcon(pokemonIcon);

        pokemonButton->setIconSize(pixmap.rect().size());

        //PROCESSING - Make it so that I know which button is clicked
        pokemonButton->setCheckable(true);

        //PROCESSING - Connect the button with the Dialog
        connect(pokemonButton, SIGNAL(clicked()), this, SLOT(GoToDialog()));

        list.push_back(pokemonButton);
    }
}

//Print the list of Pokemon QPushButtons
void Unova::PrintList() const
{
    for(int index = 0; index < UNOVA_AR_SIZE; index++)
    {
        gridLayout->addWidget(list[index]);
    }
}

//Create the Dialog for the Pokemon to display their information
void Unova::GoToDialog()
{
    int index      = 0;     //PROC - the index in the array
    int foundIndex = 0;     //PROC - the index of the found QPushButton

    bool found     = false; //PROC - the condition if the Button was found

    Pkmn foundPokemon;      //PROC - the found Pokemon

    //PROCESSING - Loop through the buttons to find which one was clicked
    while(!found && index < UNOVA_AR_SIZE)
    {
        if(list[index]->isChecked())
        {
            list[index]->setChecked(false);
            foundIndex = index;
            found = true;
        }
        else
            index++;
    }

    foundPokemon = regionVect[foundIndex];

    //PROCESSING - Intitialize the Dialog with the Pokemon's information
    pokemonDialog->SetPokemon(foundPokemon);

    pokemonDialog->show();
    pokemonDialog->resize(800, 800);

    pokemonDialog = new Dialog;
}

//If the user clicks exit, then hide this window
void Unova::on_actionExit_triggered()
{
    hide();
}
