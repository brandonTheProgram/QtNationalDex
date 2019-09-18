#include "dialog.h"
#include "ui_dialog.h"

using namespace PokemonDialog;

/************************************************************************
* Method Dialog: Class Dialog
*----------------------------------------------------------------------
* 	 This method creates the Dialog object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       parent (QWidget) - the invoking object
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Create the layout
    mainLayout      = new QVBoxLayout;

    topLayout       = new QHBoxLayout;

    middleLayout    = new QGridLayout;

    midBtmLayout    = new QHBoxLayout;

    bottomLayout    = new QGridLayout;

    topBox          = new QGroupBox;
    middleBox       = new QGroupBox;
    midBtmBox       = new QGroupBox;
    bottomBox       = new QGroupBox;

    idNumber        = new QLabel;
    name            = new QLabel;
    classification  = new QLabel;
    priType         = new QLabel;
    secType         = new QLabel;
    image           = new QLabel;
    description     = new QLabel;
    versionOneLoc     = new QLabel;
    versionTwoLoc    = new QLabel;

    firstEvoBut     = new QPushButton;
    secEvoBut       = new QPushButton;
    finalEvoBut     = new QPushButton;
    branchEvoBut    = new QPushButton;

    comboBox        = new QComboBox;

    options         = new QTextEdit;

    movie           = new QMovie;

    //Set the Fonts/Alignment
    idNumber        ->setFont(PokemonDialog::FONT);
    name            ->setFont(PokemonDialog::FONT);
    classification  ->setFont(PokemonDialog::FONT);
    priType         ->setFont(PokemonDialog::FONT);
    secType         ->setFont(PokemonDialog::FONT);
    description     ->setFont(PokemonDialog::FONT);
    versionOneLoc     ->setFont(PokemonDialog::FONT);
    versionTwoLoc    ->setFont(PokemonDialog::FONT);
    options         ->setFont(PokemonDialog::FONT);
    comboBox        ->setFont(PokemonDialog::FONT);

    idNumber        ->setAlignment(Qt::AlignHCenter);
    name            ->setAlignment(Qt::AlignHCenter);
    classification  ->setAlignment(Qt::AlignHCenter);
    priType         ->setAlignment(Qt::AlignHCenter);
    secType         ->setAlignment(Qt::AlignHCenter);

    //Set the options for the ComboBox
    comboBox->addItem("Pick an option");
    comboBox->addItem("Abilities");
    comboBox->addItem("Evolutions");
    comboBox->addItem("Weakness");
    comboBox->addItem("Lvl Moveset");
    comboBox->addItem("TM Moveset");

    //Set the options so that they can not be edited
    options->setReadOnly(true);
    options->setPlainText(tr("Pick an option below!"));

    //Edit the layouts
    mainLayout  ->addWidget(topBox);
    mainLayout  ->addWidget(middleBox);
    mainLayout  ->addWidget(midBtmBox);
    mainLayout  ->addWidget(bottomBox);

    topLayout   ->addWidget(idNumber);
    topLayout   ->addWidget(name);
    topLayout   ->addWidget(classification);
    topLayout   ->addWidget(priType);
    topLayout   ->addWidget(secType);

    middleLayout->addWidget(image);
    middleLayout->addWidget(description);
    middleLayout->addWidget(versionOneLoc);
    middleLayout->addWidget(versionTwoLoc);

    bottomLayout->addWidget(options);
    bottomLayout->addWidget(comboBox);

    //Set the definite layouts
               setLayout(mainLayout);
    topBox   ->setLayout(topLayout);
    middleBox->setLayout(middleLayout);
    bottomBox->setLayout(bottomLayout);

    //Connect the ComboBox so that it can display different options
    connect(comboBox, SIGNAL(activated      (int)),
            this,     SLOT  (ComboBoxOptions(int)));

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

/************************************************************************
* Method ~Dialog: Class Dialog
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
Dialog::~Dialog()
{
    delete ui;
    delete image;
    delete topBox;
    delete middleBox;
    delete midBtmBox;
    delete bottomBox;
    delete idNumber;
    delete name;
    delete options;
    delete classification;
    delete priType;
    delete secType;
    delete comboBox;
    delete description;
    delete versionOneLoc;
    delete versionTwoLoc;
    delete mainLayout;
    delete topLayout;
    delete middleLayout;
    delete midBtmLayout;
    delete bottomLayout;
    delete firstEvoBut;
    delete secEvoBut;
    delete finalEvoBut;
    delete branchEvoBut;
    delete movie;

    for(auto it: evoList){delete (it);}

    evoList.clear();

    QVector<QPushButton*>().swap(evoList);
}

/************************************************************************
* Method SetPokemon: Class Dialog
*----------------------------------------------------------------------
* 	 This method inititalizes the Pokemon for the Dialog
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		POKEMON (Pkmn) - the current Pokemon
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::SetPokemon(const Pkmn &POKEMON)
{
    currentPokemon = POKEMON;

    //PROCESSING - Set the values of the Pokemon for the Dialog
    SetPokemonValues();
}

/************************************************************************
* Method SetPokemonValues: Class Dialog
*----------------------------------------------------------------------
* 	 This method set the values of the Pokemon in the corresponding
*    places in the Dialog
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::SetPokemonValues()
{
    QString gifPath;        //PROC - the path to the gif of the Pokemon
    QString firstEvoPath;   //PROC - the path of the first evo image
    QString secEvoPath;     //PROC - the path of the second evo image
    QString finalEvoPath;   //PROC - the path of the final evo image
    QString branchEvoPath;  //PROC - the path of the branch evo image
    QString pokemonNumber;  //PROC - the pokemon number as a QString
    QString firstEvoNum;    //PROC - the first evolution number as a QString
    QString secEvoNum;      //PROC - the second evolution number as a QString
    QString finalEvoNum;    //PROC - the final evolution number as a QString
    QString branchEvoNum;   //PROC - the branch evolution number as a QString
    QString versionOneLoc;  //OUT  - the location of the pokemon in version one
                            //       of the current game
    QString versionTwoLoc;  //OUT  - the location of the pokemon in version two
                            //       of the current game

    QPixmap firstEvoPixmap; //PROC - the pixmap of the first evo
    QPixmap secEvoPixmap;   //PROC - the pixmap of the second evo
    QPixmap finalEvoPixmap; //PROC - the pixmap of the final evo
    QPixmap branchEvoPixmap;//PROC - the pixmap of the branch evo

    QIcon   firstEvoIcon;   //PROC - the icon of the first evo
    QIcon   secEvoIcon;     //PROC - the icon of the second evo
    QIcon   finalEvoIcon;   //PROC - the icon of the final evo
    QIcon   branchEvoIcon;  //PROC - the icon of the branch evo

    Pokemon pokemon;        //PROC - the basic pokemon without the extra classes

    //PROCESSING - store the necessary values for the method
    pokemon       = this->currentPokemon.currentPkmn;
    pokemonNumber = QString::number(pokemon.GetPokedexNumber());
    gifPath       = (PokemonDialog::GIF_PATH + pokemonNumber + ".gif");
    versionOneLoc = WordWrap(pokemon.GetVersionOneLocation(), WORD_WRAP_LIMIT);
    versionTwoLoc = WordWrap(pokemon.GetVersionOneLocation(), WORD_WRAP_LIMIT);

    //OUTPUT - set the text for the ui objects
    idNumber      ->setText(pokemonNumber);
    name          ->setText(QString::fromStdString(pokemon.GetName()));
    classification->setText(QString::fromStdString(pokemon.GetSpecies()));

    //OUTPUT - If the Pokemon has different Types, than display both
    if(pokemon.GetPriType().compare(pokemon.GetSecType()))
    {
        priType->setText(QString::fromStdString(pokemon.GetPriType()));
        secType->setText(QString::fromStdString(pokemon.GetSecType()));
    }
    else{priType->setText(QString::fromStdString(pokemon.GetPriType()));}

    description->setText(QString::fromStdString(pokemon.GetDescription()));

    this->versionOneLoc->setText(GAME_VER_ONE + "   : "  + versionOneLoc);
    this->versionTwoLoc->setText(GAME_VER_TWO + ": "     + versionTwoLoc);
    //Set up and start playing the gif
    movie->setFileName(gifPath);
    movie->start();
    movie->setScaledSize(PokemonDialog::IMAGE_SIZE);

    image->setAttribute(Qt::WA_NoSystemBackground);
    image->setMovie(movie);

    //If the pokemon is not a special branch evo with more than 2 seperate
    //evolutions like Eevee, than prepare the ui for that
    if(pokemon.GetEvolutions() <= 2)
    {
        firstEvoNum   = QString::number(pokemon.GetFirstEvoNum());
        secEvoNum     = QString::number(pokemon.GetSecondEvoNum());
        finalEvoNum   = QString::number(pokemon.GetFinalEvoNum());
        branchEvoNum  = QString::number(pokemon.GetBranchEvoNum());

        //MiddleBottomBoxLayout
        midBtmLayout->addWidget(firstEvoBut);
        midBtmLayout->addWidget(secEvoBut);
        midBtmLayout->addWidget(finalEvoBut);
        midBtmLayout->addWidget(branchEvoBut);

        //PROCESSING - Connect the button with the slot
        connect(firstEvoBut,  SIGNAL(clicked         ()),
                this,         SLOT  (EvolutionClicked()));
        connect(secEvoBut,    SIGNAL(clicked         ()),
                this,         SLOT  (EvolutionClicked()));
        connect(finalEvoBut,  SIGNAL(clicked         ()),
                this,         SLOT  (EvolutionClicked()));
        connect(branchEvoBut, SIGNAL(clicked         ()),
                this,         SLOT  (EvolutionClicked()));

        //PROCESSING - Make the buttons checkable to check later
        firstEvoBut ->setCheckable(true);
        secEvoBut   ->setCheckable(true);
        finalEvoBut ->setCheckable(true);
        branchEvoBut->setCheckable(true);

        //Set up the button for the first evolution
        firstEvoPath   = (PokemonDialog::IMAGE_PATH + firstEvoNum + ".png");
        firstEvoPixmap.load(firstEvoPath);
        firstEvoIcon  .addPixmap(firstEvoPixmap);
        firstEvoBut  ->setIcon(firstEvoIcon);
        firstEvoBut  ->setIconSize(firstEvoPixmap.rect().size());

        //Based on how many evolutions, hide or present the buttons
        switch(pokemon.GetEvolutions())
        {
        case 0:     secEvoBut   ->hide();
                    finalEvoBut ->hide();

                    break;
        case 1:     //Set up the button for the final evolution
                    finalEvoPath = (PokemonDialog::IMAGE_PATH +
                                    finalEvoNum + ".png");

                    finalEvoPixmap.load(finalEvoPath);
                    finalEvoIcon  .addPixmap(finalEvoPixmap);
                    finalEvoBut  ->setIcon(finalEvoIcon);
                    finalEvoBut  ->setIconSize(finalEvoPixmap.rect().size());

                    secEvoBut    ->hide();

                    break;
        case 2:     //Set up the button for the second evolution
                    secEvoPath  =(PokemonDialog::IMAGE_PATH +
                                  secEvoNum + ".png");

                    finalEvoPath=(PokemonDialog::IMAGE_PATH +
                                  finalEvoNum + ".png");

                    secEvoPixmap.load(secEvoPath);
                    secEvoIcon.addPixmap(secEvoPixmap);
                    secEvoBut->setIcon(secEvoIcon);
                    secEvoBut->setIconSize(secEvoPixmap.rect().size());

                    //Set up the button for the final evolution
                    finalEvoPixmap.load(finalEvoPath);
                    finalEvoIcon.addPixmap(finalEvoPixmap);
                    finalEvoBut->setIcon(finalEvoIcon);
                    finalEvoBut->setIconSize(finalEvoPixmap.rect().size());

                    break;
        default:    break;
        }

        //If the pokemon has a branch evolution, than set it up
        if(pokemon.GetBranchEvo())
        {
           branchEvoPath = (PokemonDialog::IMAGE_PATH +
                            branchEvoNum + ".png");

           branchEvoPixmap.load(branchEvoPath);
           branchEvoIcon.addPixmap(branchEvoPixmap);
           branchEvoBut->setIcon(branchEvoIcon);
           branchEvoBut->setIconSize(branchEvoPixmap.rect().size());
        }
        else{branchEvoBut->hide();}
    }
    else{this->CreateBranchEvolutionButtons();}

    //Set the layout with all the necessary buttons
    midBtmBox->setLayout(midBtmLayout);
}

/************************************************************************
* Method CreateBranchEvolutionButtons: Class Dialog
*----------------------------------------------------------------------
* 	 This method creates the necessary amount of special evolution buttons
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::CreateBranchEvolutionButtons()
{
    using namespace globalPkmEvoConsts; /**WURPLE_EVOLUTIONS,TYROGUE_EVOLUTIONS,
                                           EEVEELUTIONS**/

    QPushButton* newButton;             //PROC -the new pokemon button

    QString branchEvoPath;              //PROC - the path to the branch evo pic

    QPixmap branchEvoPixmap;            //PROC - the pixmap for the branch evo

    QIcon   branchEvoIcon;              //PROC - the icon for the branch evo

    int pokemonNum;

    bool wurmpleEvo;
    bool tyrougeEvo;
    bool eeveeEvo;

    //PROCESSING - Set inital values
    pokemonNum = currentPokemon.currentPkmn.GetPokedexNumber();
    wurmpleEvo = false;
    tyrougeEvo = false;
    eeveeEvo   = false;

    for(auto wurmpleIt: WURPLE_EVOLUTIONS)
    {
        if(wurmpleIt == pokemonNum)
        {
            wurmpleEvo = true;
            evoList.reserve(WURPLE_EVOLUTIONS.size());
        }
    }

    if(!wurmpleEvo)
    {
        for(auto tyrougeIt: TYROGUE_EVOLUTIONS)
        {
            if(tyrougeIt == pokemonNum)
            {
                tyrougeEvo = true;
                evoList.reserve(TYROGUE_EVOLUTIONS.size());
            }
        }
    }
    if(!tyrougeEvo)
    {
        for(auto eeveeIt: EEVEELUTIONS)
        {
            if(eeveeIt == pokemonNum)
            {
                eeveeEvo = true;
                evoList.reserve(EEVEELUTIONS.size());
            }
        }
    }

    //PROCESSING - depending on the special evos, create buttons for them
    if(wurmpleEvo)
    {
        for(auto branchIt: WURPLE_EVOLUTIONS)
        {
            newButton     = new QPushButton;

            branchEvoPath = (PokemonDialog::IMAGE_PATH +
                             QString::number(branchIt) + ".png");

            branchEvoPixmap .load(branchEvoPath);
            branchEvoIcon   .addPixmap(branchEvoPixmap);
            newButton      ->setIcon(branchEvoIcon);
            newButton      ->setIconSize(branchEvoPixmap.rect().size());

            connect(newButton, SIGNAL(clicked         ()),
                    this,      SLOT  (EvolutionClicked()));

            newButton ->setCheckable(true);
            newButton ->setText(QString::number(branchIt));

            evoList.push_back(newButton);
        }
    }
    else if(tyrougeEvo)
    {
        for(auto branchIt: TYROGUE_EVOLUTIONS)
        {
            newButton = new QPushButton;

            branchEvoPath = (PokemonDialog::IMAGE_PATH +
                             QString::number(branchIt) + ".png");

            branchEvoPixmap.load(branchEvoPath);
            branchEvoIcon  .addPixmap(branchEvoPixmap);
            newButton     ->setIcon(branchEvoIcon);
            newButton     ->setIconSize(branchEvoPixmap.rect().size());

            connect(newButton, SIGNAL(clicked         ()),
                    this,      SLOT  (EvolutionClicked()));

            newButton ->setCheckable(true);
            newButton ->setText(QString::number(branchIt));

            evoList.push_back(newButton);
        }
    }
    else if(eeveeEvo)
    {
        for(auto branchIt: EEVEELUTIONS)
        {
            newButton = new QPushButton;

            branchEvoPath = (PokemonDialog::IMAGE_PATH +
                             QString::number(branchIt) + ".png");

            branchEvoPixmap.load(branchEvoPath);
            branchEvoIcon  .addPixmap(branchEvoPixmap);
            newButton     ->setIcon(branchEvoIcon);
            newButton     ->setIconSize(branchEvoPixmap.rect().size());

            connect(newButton, SIGNAL(clicked         ()),
                    this,      SLOT  (EvolutionClicked()));

            newButton ->setCheckable(true);
            newButton ->setText(QString::number(branchIt));

            evoList.push_back(newButton);
        }
    }

    //MiddleBottomBoxLayout
    for(auto evoIt: evoList){midBtmLayout->addWidget(evoIt);}
}

/************************************************************************
* Method DisplayAbilities: Class Dialog
*----------------------------------------------------------------------
* 	 This method displays the abilities in the options area
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::DisplayAbilities() const
{
    options->setPlainText(QString::fromStdString
                          (currentPokemon.currentPkmn.PrintAbility()));
}

/************************************************************************
* Method DisplayEvolutions: Class Dialog
*----------------------------------------------------------------------
* 	 This method displays the evolutions in the options area
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::DisplayEvolutions() const
{
    //PROCESSING - If the Pokemon has evolutions, then display them
    if(currentPokemon.currentPkmn.GetEvolutions() != 0)
    {
        options->setPlainText(QString::fromStdString
                              (currentPokemon.pkmnEvos.PrintEvoTree()));
    }
    else{options->setPlainText(tr("This Pokemon has no known evolutions"));}
}

/************************************************************************
* Method DisplayWeakness: Class Dialog
*----------------------------------------------------------------------
* 	 This method displays the weaknesses in the options area
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::DisplayWeakness() const
{
    options->setPlainText(QString::fromStdString
                          (currentPokemon.pkmnWeakness.PrintWeaknesses()));
}

/************************************************************************
* Method DisplayLvlMoveset: Class Dialog
*----------------------------------------------------------------------
* 	 This method displays the level moveset in the options area
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::DisplayLvlMoveset() const
{
    options->setPlainText(QString::fromStdString
                          (currentPokemon.pkmnMoves.PrintLvl()));
}

/************************************************************************
* Method DisplayTMMoveset: Class Dialog
*----------------------------------------------------------------------
* 	 This method displays the TM/HM moveset in the options area
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::DisplayTMMoveset() const
{
    options->setPlainText(QString::fromStdString(
                              currentPokemon.pkmnMoves.PrintTM()));
}

QString Dialog::WordWrap(const string &SEN, const int &LENGTH) const
{
    std::istringstream words(SEN); //PROC - the words in the sentence

    std::ostringstream wrapped;			//PROC - the wrapped text

    string        word;					//PROC - the word

    if (words >> word)
    {
        wrapped << word;

        size_t space_left = LENGTH - word.length();

        while (words >> word)
        {
            if (space_left < word.length() + 1)
            {
                wrapped << '\n' << word;

                space_left = LENGTH - word.length();
            }
            else
            {
                wrapped << ' ' << word;

                space_left -= word.length() + 1;
            }
        }
    }

    return QString::fromStdString(wrapped.str());
}

/************************************************************************
* Method ComboBoxOptions: Class Dialog
*----------------------------------------------------------------------
* 	 This method displays the option selected based on
*       the index in the QComboBox
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       ARGUMENT (int) - the current index of the QComboBox
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::ComboBoxOptions(const int& ARGUMENT)
{
    using namespace PokemonDialog; /** enum::options **/

    switch (ARGUMENT)
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

/************************************************************************
* Method EvolutionClicked: Class Dialog
*----------------------------------------------------------------------
* 	 This method finds the button that was pressed and emits a signal holding a
*    pokedex number of the pokemon that was chosen from the evolution tree
*       the index in the QComboBox
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Dialog::EvolutionClicked()
{
    bool found;     //PROC - the condition if search is found
    int  index;     //PROC - the index in the array

    index = 0;
    found = false;

    if(firstEvoBut->isChecked())
        {emit evolutionNumber(currentPokemon.currentPkmn.GetFirstEvoNum());}

    else if(secEvoBut->isChecked())
    {emit evolutionNumber(currentPokemon.currentPkmn.GetSecondEvoNum());}

    else if(finalEvoBut->isChecked())
    {emit evolutionNumber(currentPokemon.currentPkmn.GetFinalEvoNum());}

    else if(branchEvoBut->isChecked())
    {emit evolutionNumber(currentPokemon.currentPkmn.GetBranchEvoNum());}

    else
    {
        //PROCESSING - Loop through the buttons to find which one was clicked
        while(!found && index < evoList.size())
        {
            if(evoList[index]->isChecked()){found = true;}
            else                           {index++;}
        }

        emit evolutionNumber(evoList[index]->text().toInt());
    }

    close();
}
