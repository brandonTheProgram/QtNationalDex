#include "mainwindow.h"
#include <QApplication>

/*!
 * \fn int main(int argc, char *argv[])
 * \brief This is main for the program
 * \param argc
 * \param *argv[]
 *
 * This program will allow the user to choose a region and then a Pokemon to
 *  find information pertaining to that Pokemon. This is meant to emulate
 *  the functions of the Pokedex that can be found within the Pokemon games
 *  and anime
 */
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;

    w.showMaximized();

    return a.exec();
}
