#include "dialog.h"
#include "ui_dialog.h"

//Constructor
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Create the layout
    mainLayout      = new QVBoxLayout;
    topLayout       = new QHBoxLayout;
    middleLayout    = new QGridLayout;
    bottomLayout    = new QGridLayout;
    topBox          = new QGroupBox;
    middleBox       = new QGroupBox;
    bottomBox       = new QGroupBox;
    idNumber        = new QLabel;
    name            = new QLabel;
    classification  = new QLabel;
    priType         = new QLabel;
    secType         = new QLabel;
    image           = new QLabel;
    description     = new QLabel;
    comboBox        = new QComboBox;
    options         = new QTextEdit;
    movie           = new QMovie;

    mainLayout->addWidget(topBox);
    mainLayout->addWidget(middleBox);
    mainLayout->addWidget(bottomBox);

    setLayout(mainLayout);

    //TopBoxLayout
    topLayout->addWidget(idNumber);
    topLayout->addWidget(name);
    topLayout->addWidget(classification);
    topLayout->addWidget(priType);
    topLayout->addWidget(secType);

    topBox->setLayout(topLayout);

    //MiddleBoxLayout
    middleLayout->addWidget(image);
    middleLayout->addWidget(description);

    middleBox->setLayout(middleLayout);

    //BottomBoxLayout
    options->setReadOnly(true);

    options->setPlainText(tr("Pick an option below"));

    //Set the options for the ComboBox
    comboBox->addItem("Pick an option");
    comboBox->addItem("Abilities");
    comboBox->addItem("Evolutions");
    comboBox->addItem("Weakness");
    comboBox->addItem("Lvl Moveset");
    comboBox->addItem("TM Moveset");

    //Connect the ComboBox so that it can display different options
    connect(comboBox, SIGNAL(activated(int)), this, SLOT(ComboBoxOptions(int)));

    bottomLayout->addWidget(options);
    bottomLayout->addWidget(comboBox);

    bottomBox->setLayout(bottomLayout);

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

//Deconstructor
Dialog::~Dialog()
{
    delete ui;
    delete image;
    delete topBox;
    delete middleBox;
    delete bottomBox;
    delete idNumber;
    delete name;
    delete options;
    delete classification;
    delete priType;
    delete secType;
    delete comboBox;
    delete description;
    delete mainLayout;
    delete topLayout;
    delete middleLayout;
    delete bottomLayout;
    delete movie;
}

//Inititalize the Pokemon for the Dialog
void Dialog::SetPokemon(const Pkmn &POKEMON)
{
    currentPokemon = POKEMON;

    //PROCESSING - Set the values of the Pokemon for the Dialog
    SetPokemonValues();
}

//Set the values of the Pokemon in the corresponding places in the Dialog
void Dialog::SetPokemonValues()
{
    QString path;   //PROC - the path to the gif of the Pokemon

    Pokemon pokemon = currentPokemon.currentPkmn;

    QString pokemonNumber = QString::number(pokemon.GetPokedexNumber());

    idNumber      ->setText(pokemonNumber);
    name          ->setText(QString::fromStdString(pokemon.GetName()));
    classification->setText(QString::fromStdString(pokemon.GetSpecies()));

    //OUTPUT - If the Pokemon has different Types, than display both
    if(pokemon.GetPriType().compare(pokemon.GetSecType()))
    {
        priType->setText(QString::fromStdString(pokemon.GetPriType()));
        secType->setText(QString::fromStdString(pokemon.GetSecType()));
    }
    else
    {
        priType->setText(QString::fromStdString(pokemon.GetPriType()));
    }

    description->setText(QString::fromStdString(pokemon.GetDescription()));

    //PROCESSING - Create the path for the Pokemon gif
    path = (PokemonGifs::PATH + pokemonNumber + ".gif");

    movie->setFileName(path);

    movie->start();

    image->setAttribute(Qt::WA_NoSystemBackground);
    image->setMovie(movie);
}

//Display the default message in the options area
void Dialog::DisplayDefault() const
{
    options->setPlainText(tr("This Pokemon has no known evolutions"));
}

//Display the Pokemon's abilities in the options area
void Dialog::DisplayAbilities() const
{
    options->setPlainText(QString::fromStdString(currentPokemon.currentPkmn.PrintAbility()));
}

//Display the Pokemon's evolutions in the options area
void Dialog::DisplayEvolutions() const
{
    //PROCESSING - If the Pokemon has evolutions, then display them
    if(currentPokemon.currentPkmn.GetEvolutions() != 0)
        options->setPlainText(QString::fromStdString(currentPokemon.pkmnEvos.PrintEvoTree()));
    else
        options->setPlainText(tr("This Pokemon has no known evolutions"));
}

//Display the Pokemon's Weaknesses in the options area
void Dialog::DisplayWeakness() const
{
    options->setPlainText(QString::fromStdString(currentPokemon.pkmnWeakness.PrintWeaknesses()));
}

//Display the Pokemon's level moveset in the options area
void Dialog::DisplayLvlMoveset() const
{
    options->setPlainText(QString::fromStdString(currentPokemon.pkmnMoves.PrintLvl()));
}

//Display the Pokemon's TM moveset in the options area
void Dialog::DisplayTMMoveset() const
{
    options->setPlainText(QString::fromStdString(currentPokemon.pkmnMoves.PrintTM()));
}

//Display the option selected based on the index in the QComboBox
void Dialog::ComboBoxOptions(int argument)
{
    switch (argument)
    {
    case DISPLAY  :     DisplayDefault();
                        break;
    case ABILITIES:     DisplayAbilities();
                        break;
    case EVOLUTIONS:    DisplayEvolutions();
                        break;
    case WEAKNESS:      DisplayWeakness();
                        break;
    case LVL_MOVESET:   DisplayLvlMoveset();
                        break;
    case TM_MOVESET:    DisplayTMMoveset();
                        break;
    default:            break;
    }
}
