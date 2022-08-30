#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QMovie>
#include <QTextToSpeech>

#include "Pokedex.h"    /** Pkmn **/

/*!
 * \namespace PokemonDialog
 * \brief global constants to be used for a Dialog about a Pokemon
 */
namespace PokemonDialog{
    /*!
     * \variable GIF_PATH
     * \brief The path to the GIF of the Pokemon
     */
    const QString GIF_PATH = ":/PokemonGifs/pokemonGifs/";

    /*!
     * \variable IMAGE_PATH
     * \brief The path to the image of the Pokemon
     */
    const QString IMAGE_PATH = ":/PokemonImages/pokemonImages/";

    /*!
     * \variable GAME_VER_ONE
     * \brief The name of the first version of the game
     */
    const QString GAME_VER_ONE = "Sword";

    /*!
     * \variable GAME_VER_TWO
     * \brief The name of the second version of the game
     */
    const QString GAME_VER_TWO = "Shield";

    /*!
     * \variable FONT
     * \brief The prefered font for the text of the GUI
     */
    const QFont FONT ("Times", 12, QFont::Bold);

    /*!
     * \variable IMAGE_SIZE
     * \brief The prefered size for the images of the GUI
     * \
     */
    const QSize IMAGE_SIZE (150, 150);

    /*!
     * \variable WORD_WRAP_LIMIT
     * \brief The limit on how far text should be word wrapped
     */
    const unsigned int WORD_WRAP_LIMIT = 150;

    /*!
     * \variable VOICE_PITCH
     * \brief The prefered pitch for the voice in text to speech
     */
    const double VOICE_PITCH = 0.7;

    /*!
     * \variable VOICE_VOLUME
     * \brief The prefered volume for the voice in text to speech
     */
    const double VOICE_VOLUME = 1.0;

    /*!
     * \variable VOICE_RATE
     * \brief The prefered rate for the voice in text to speech
     */
    const double VOICE_RATE = 0.2;

    /*!
     * \enum options
     *
     * This enum type specifies options for the user to pick
     *
     * \value DISPLAY
     *        the default value
     *
     * \value ABILITIES
     *        display information about the Pokemon's abilities
     *
     * \value EVOLUTIONS
     *        display information about the Pokemon's evolutions
     *
     * \value WEAKNESS
     *        display information about the Pokemon's weaknesses
     *
     * \value LVL_MOVESET
     *        display information about the Pokemon's level moveset
     *
     * \value TM_MOVESET
     *        display information about the Pokemon's TM/TR moveset
     */
    enum options{
        DISPLAY,
        ABILITIES,
        EVOLUTIONS,
        WEAKNESS,
        LVL_MOVESET,
        TM_MOVESET
    };
}

namespace Ui {
class Dialog;
}

/*!
 * \class Dialog
 * \brief This class represents a Dialog screen that will display a Pokemon's
 *        information
 */
class Dialog : public QDialog{
    Q_OBJECT

public:
    /*!
     * \fn Dialog(QWidget *parent = nullptr)
     * \brief This is the default constructor for the Dialog
     * \param parent - the widget parent of the child object
     */
    explicit Dialog(QWidget *parent = nullptr);

    /*!
     * \fn ~Dialog()
     * \brief This is the deconstructor for the Dialog
     */
    ~Dialog();

    /*!
     * \fn SetPokemonValues()
     * \brief This method sets the Pokemon's information into the Dialog object
     * \param POKEMON - the Pokemon
     */
    void SetPokemonValues(const Pkmn& POKEMON);

    /*!
     * \fn CreateBranchEvolutionButtons()
     * \brief This method creates the necessary amount of buttons for
     *        multiple branch evolutions
     */
    void CreateBranchEvolutionButtons();

    /*!
     * \fn DisplayDefault() const
     * \brief This method displays the default message
     */
    void DisplayDefault() const{
        options->setPlainText(tr("Pick an option below!"));
    }

    /*!
     * \fn DisplayAbilities() const
     * \brief This method displays the Pokemon's abilities
     */
    void DisplayAbilities() const;

    /*!
     * \fn DisplayEvolutions() const
     * \brief This method displays the Pokemon's evolutions
     */
    void DisplayEvolutions() const;

    /*!
     * \fn DisplayWeakness() const
     * \brief This method displays the Pokemon's weaknesses
     */
    void DisplayWeakness() const;

    /*!
     * \fn DisplayLvlMoveset() const
     * \brief This method displays the Pokemon's moveset while leveling up
     */
    void DisplayLvlMoveset() const;

    /*!
     * \fn DisplayTMMoveset() const
     * \brief This method displays the Pokemon's moveset through TMs/TRs
     */
    void DisplayTMMoveset() const;

    /*!
     * \fn WordWrap(const string& SEN, const unsigned int& LENGTH) const
     * \brief This method wraps text into paragraph format
     */
    QString WordWrap(const string& SEN, const unsigned int& LENGTH) const;

public slots:

    /*!
     * \fn ComboBoxOptions(const int& ARGUMENT)
     * \brief This method performs methods based on which
     *        QComboBox option was chosen
     * \param ARGUMENT - the choosen menu option
     */
    void ComboBoxOptions(const int& ARGUMENT);

    /*!
     * \fn EvolutionClicked()
     * \brief This method searchs and emits a signal of
     *        the evolution button choosen
     */
    void EvolutionClicked();

    /*!
     * \fn reject()
     * \brief This method stops the voice of the dialog if it
     *        is closed while the bot is still talking
     */
    void reject();

signals:
    /*!
     * \fn evolutionNumber(const int& POKEMON_NUMBER)
     * \brief This method emits a signal of the index of the
     *        choosen Pokemon in the pokedex
     */
    void evolutionNumber(const int& POKEMON_NUMBER);

private:
    /*!
     * \variable ui
     * \brief The UI for the Dialog
     */
    Ui::Dialog *ui;

    /*!
     * \variable ui
     * \brief The UI's voice bot
     */
    QTextToSpeech *voice;

    /*!
     * \variable voiceDialog
     * \brief The message that the voice will say
     */
    QString voiceDialog;

    /*!
     * \variable mainLayout
     * \brief The mainlayout for the Dialog
     */
    QVBoxLayout *mainLayout;

    /*!
     * \variable topLayout
     * \brief The layout for the top half
     */
    QHBoxLayout *topLayout;

    /*!
     * \variable middleLayout
     * \brief The layout for the middle half
     */
    QGridLayout *middleLayout;

    /*!
     * \variable midBtmLayout
     * \brief The layout for the middle bottom half
     */
    QHBoxLayout *midBtmLayout;

    /*!
     * \variable bottomLayout
     * \brief The layout for the bottom half
     */
    QGridLayout *bottomLayout;

    /*!
     * \variable topBox
     * \brief The top box in the display
     */
    QGroupBox *topBox;

    /*!
     * \variable middleBox
     * \brief The middle box in the display
     */
    QGroupBox *middleBox;

    /*!
     * \variable midBtmBox
     * \brief The middle bottom box in the display
     */
    QGroupBox *midBtmBox;

    /*!
     * \variable bottomBox
     * \brief The bottom box in the display
     */
    QGroupBox *bottomBox;

    /*!
     * \variable image
     * \brief The image of the Pokemon
     */
    QLabel *image;

    /*!
     * \variable idNumber
     * \brief The Pokemon's Pokedex number
     */
    QLabel *idNumber;

    /*!
     * \variable name
     * \brief The Pokemon's name
     */
    QLabel *name;

    /*!
     * \variable classification
     * \brief The Pokemon's species
     */
    QLabel *classification;

    /*!
     * \variable priType
     * \brief The Primary Type of the Pokemon
     */
    QLabel *priType;

    /*!
     * \variable secType
     * \brief The Secondary Type of the Pokemon
     */
    QLabel *secType;

    /*!
     * \variable firstEvoBut
     * \brief Button for the first evolution
     */
    QPushButton *firstEvoBut;

    /*!
     * \variable secEvoBut
     * \brief Button for the second evolution
     */
    QPushButton *secEvoBut;

    /*!
     * \variable finalEvoBut
     * \brief Button for the final evolution
     */
    QPushButton *finalEvoBut;

    /*!
     * \variable branchEvoBut
     * \brief Button for the branch evolution
     */
    QPushButton *branchEvoBut;

    /*!
     * \variable comboBox
     * \brief The combobox that holds the options
     */
    QComboBox *comboBox;

    /*!
     * \variable description
     * \brief The description of the Pokemon
     */
    QLabel *description;

    /*!
     * \variable versionOneLoc
     * \brief The location of the Pokemon in version one of the current game
     */
    QLabel *versionOneLoc;

    /*!
     * \variable versionTwoLoc
     * \brief The location of the Pokemon in version two of the current game
     */
    QLabel *versionTwoLoc;

    /*!
     * \variable options
     * \brief The different options that can be displayed by the QComboBox
     */
    QTextEdit *options;

    /*!
     * \variable movie
     * \brief The battle gif of the Pokemon from the video games
     */
    QMovie *movie;

    /*!
     * \variable evoList
     * \brief The list of QPushButtons for special branch evolutions
     */
    QVector<QPushButton*> evoList;

    /*!
     * \variable currentPokemon
     * \brief The current Pokemon of the Dialog
     */
    Pkmn currentPokemon;
};

#endif // DIALOG_H
