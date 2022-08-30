#include "dialog.h"
#include "ui_dialog.h"

using namespace PokemonDialog;

Dialog::Dialog(QWidget *parent)
    :QDialog(parent), ui(new Ui::Dialog){
    ui->setupUi(this);

    //Create voice bot
    voice = new QTextToSpeech(this);
    voice->setVolume(VOICE_VOLUME);
    voice->setPitch (VOICE_PITCH);
    voice->setRate  (VOICE_RATE);

    //Create the layout
    mainLayout      = new QVBoxLayout;

    topLayout       = new QHBoxLayout;
    midBtmLayout    = new QHBoxLayout;

    middleLayout    = new QGridLayout;
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
    versionOneLoc   = new QLabel;
    versionTwoLoc   = new QLabel;

    firstEvoBut     = new QPushButton;
    secEvoBut       = new QPushButton;
    finalEvoBut     = new QPushButton;
    branchEvoBut    = new QPushButton;

    comboBox        = new QComboBox;

    options         = new QTextEdit;

    movie           = new QMovie;

    //Set the Fonts and Alignment
    idNumber        ->setFont(PokemonDialog::FONT);
    name            ->setFont(PokemonDialog::FONT);
    classification  ->setFont(PokemonDialog::FONT);
    priType         ->setFont(PokemonDialog::FONT);
    secType         ->setFont(PokemonDialog::FONT);
    description     ->setFont(PokemonDialog::FONT);
    versionOneLoc   ->setFont(PokemonDialog::FONT);
    versionTwoLoc   ->setFont(PokemonDialog::FONT);
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
    comboBox->addItem("TM/TR Moveset");

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

    bottomLayout->addWidget(comboBox);
    bottomLayout->addWidget(options);

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

Dialog::~Dialog(){
    delete ui;
    delete voice;
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

    //Delete every evolution button created
    for(auto it: evoList){delete (it);}

    QVector<QPushButton*>().swap(evoList);
    evoList.clear();
}

void Dialog::SetPokemonValues(const Pkmn &POKEMON){
    QString gifPath;
    QString firstEvoPath;
    QString secEvoPath;
    QString finalEvoPath;
    QString branchEvoPath;
    QString pokemonNumber;
    QString firstEvoNum;
    QString secEvoNum;
    QString finalEvoNum;
    QString branchEvoNum;
    QString versionOneLoc;
    QString versionTwoLoc;

    QPixmap firstEvoPixmap;
    QPixmap secEvoPixmap;
    QPixmap finalEvoPixmap;
    QPixmap branchEvoPixmap;

    QIcon   firstEvoIcon;
    QIcon   secEvoIcon;
    QIcon   finalEvoIcon;
    QIcon   branchEvoIcon;

    Pokemon pokemon;

    //PROCESSING - store the necessary values for the method
    currentPokemon = POKEMON;
    pokemon        = this->currentPokemon.currentPkmn;
    pokemonNumber  = QString::number(pokemon.GetPokedexNumber());
    gifPath        = (PokemonDialog::GIF_PATH + pokemonNumber + ".gif");
    versionOneLoc  = WordWrap(pokemon.GetVersionOneLocation(), WORD_WRAP_LIMIT);
    versionTwoLoc  = WordWrap(pokemon.GetVersionTwoLocation(), WORD_WRAP_LIMIT);

    //OUTPUT - set the text for the ui objects
    idNumber      ->setText(pokemonNumber);
    name          ->setText(QString::fromStdString(pokemon.GetName()));
    classification->setText(QString::fromStdString(pokemon.GetSpecies()));

    //OUTPUT - If the Pokemon has different Types, than display both
    if(pokemon.GetPriType().compare(pokemon.GetSecType())){
        priType->setText(QString::fromStdString(pokemon.GetPriType()));
        secType->setText(QString::fromStdString(pokemon.GetSecType()));
    }
    else{
        priType->setText(QString::fromStdString(pokemon.GetPriType()));
    }

    description->setText(QString::fromStdString(pokemon.GetDescription()));

    this->versionOneLoc->setText(GAME_VER_ONE + ": "  + versionOneLoc);
    this->versionTwoLoc->setText(GAME_VER_TWO + ": "  + versionTwoLoc);

    //Set up and start playing the gif
    movie->setFileName(gifPath);
    movie->start();
    movie->setScaledSize(PokemonDialog::IMAGE_SIZE);

    image->setAttribute(Qt::WA_NoSystemBackground);
    image->setMovie(movie);

    //If the pokemon is not a special branch evo with more than 2 seperate
    //evolutions like Eevee, than prepare the ui for that
    if(pokemon.GetEvolutions() <= 2){
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
        switch(pokemon.GetEvolutions()){
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
        if(pokemon.GetBranchEvo()){
           branchEvoPath = (PokemonDialog::IMAGE_PATH +
                            branchEvoNum + ".png");

           branchEvoPixmap.load(branchEvoPath);
           branchEvoIcon.addPixmap(branchEvoPixmap);
           branchEvoBut->setIcon(branchEvoIcon);
           branchEvoBut->setIconSize(branchEvoPixmap.rect().size());
        }
        else{
            branchEvoBut->hide();}
    }
    else{
        this->CreateBranchEvolutionButtons();}

    midBtmBox->setLayout(midBtmLayout);

    voiceDialog = (QString::fromStdString(pokemon.GetName() + ", the " +
                   pokemon.GetSpecies() + ", "
                   + pokemon.GetDescription() + "."));

    voice->say(voiceDialog);
}

void Dialog::CreateBranchEvolutionButtons(){
    using namespace globalPkmEvoConsts;

    QPushButton* newButton;

    QString branchEvoPath;

    QPixmap branchEvoPixmap;

    QIcon   branchEvoIcon;

    unsigned int pokemonNum;

    bool wurmpleEvo = false;
    bool tyrougeEvo = false;
    bool eeveeEvo   = false;

    pokemonNum = this->currentPokemon.currentPkmn.GetPokedexNumber();

    for(auto wurmpleIt: WURMPLE_EVOLUTIONS){
        if(wurmpleIt == pokemonNum){
            wurmpleEvo = true;
            evoList.reserve(WURMPLE_EVOLUTIONS.size());
        }
    }

    if(!wurmpleEvo){
        for(auto tyrougeIt: TYROGUE_EVOLUTIONS){
            if(tyrougeIt == pokemonNum){
                tyrougeEvo = true;
                evoList.reserve(TYROGUE_EVOLUTIONS.size());
            }
        }
    }

    if(!tyrougeEvo){
        for(auto eeveeIt: EEVEELUTIONS){
            if(eeveeIt == pokemonNum){
                eeveeEvo = true;
                evoList.reserve(EEVEELUTIONS.size());
            }
        }
    }

    //PROCESSING - depending on the special evos, create buttons for them
    if(wurmpleEvo){
        for(auto branchIt: WURMPLE_EVOLUTIONS){
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
    else if(tyrougeEvo){
        for(auto branchIt: TYROGUE_EVOLUTIONS){
            newButton     = new QPushButton;

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
    else if(eeveeEvo){
        for(auto branchIt: EEVEELUTIONS){
            newButton     = new QPushButton;

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

void Dialog::DisplayAbilities() const{
    options->setPlainText(QString::fromStdString
                          (currentPokemon.currentPkmn.PrintAbility()));
}

void Dialog::DisplayEvolutions() const{
    //PROCESSING - If the Pokemon has evolutions, then display them
    if(currentPokemon.currentPkmn.GetEvolutions() != 0){
        options->setPlainText(QString::fromStdString
                              (currentPokemon.pkmnEvos.PrintEvoTree()));
    }
    else{
        options->setPlainText(tr("This Pokemon has no known evolutions"));}
}

void Dialog::DisplayWeakness() const{
    options->setPlainText(QString::fromStdString
                          (currentPokemon.pkmnWeakness.PrintWeaknesses()));
}

void Dialog::DisplayLvlMoveset() const{
    options->setPlainText(currentPokemon.pkmnMoves.PrintLvl());
}

void Dialog::DisplayTMMoveset() const{
    options->setPlainText(currentPokemon.pkmnMoves.PrintTM());
}

QString Dialog::WordWrap(const string &SEN, const unsigned int &LENGTH) const{
    std::istringstream words(SEN);

    std::ostringstream wrapped;

    string        word;

    if (words >> word){
        wrapped << word;

        size_t space_left = LENGTH - word.length();

        while (words >> word){
            if (space_left < word.length() + 1){
                wrapped << '\n' << word;

                space_left = LENGTH - word.length();
            }
            else{
                wrapped << ' ' << word;

                space_left -= word.length() + 1;
            }
        }
    }

    return QString::fromStdString(wrapped.str());
}

void Dialog::ComboBoxOptions(const int& ARGUMENT){
    switch (ARGUMENT){
    case PokemonDialog::DISPLAY:    this->DisplayDefault();
                                    break;

    case PokemonDialog::ABILITIES:  this->DisplayAbilities();
                                    break;

    case PokemonDialog::EVOLUTIONS: this->DisplayEvolutions();
                                    break;

    case PokemonDialog::WEAKNESS:   this->DisplayWeakness();
                                    break;

    case PokemonDialog::LVL_MOVESET:this->DisplayLvlMoveset();
                                    break;

    case PokemonDialog::TM_MOVESET: this->DisplayTMMoveset();
                                    break;

    default:                        break;
    }
}

void Dialog::EvolutionClicked(){
    bool      found = false;
    unsigned  index = 0;

    if(firstEvoBut->isChecked()){
        emit evolutionNumber(currentPokemon.currentPkmn.GetFirstEvoNum());}

    else if(secEvoBut->isChecked()){
        emit evolutionNumber(currentPokemon.currentPkmn.GetSecondEvoNum());}

    else if(finalEvoBut->isChecked()){
        emit evolutionNumber(currentPokemon.currentPkmn.GetFinalEvoNum());}

    else if(branchEvoBut->isChecked()){
        emit evolutionNumber(currentPokemon.currentPkmn.GetBranchEvoNum());}

    else{
        //PROCESSING - Loop through the buttons to find which one was clicked
        while(!found && index < unsigned(evoList.size())){
            if(evoList[index]->isChecked()){
                found = true;}
            else{
                index++;}
        }

        emit evolutionNumber(evoList[index]->text().toInt());
    }

    this->movie->stop();
    close();
}

void Dialog::reject(){
    this->voice->stop();
    this->movie->stop();
    QDialog::reject();
}
