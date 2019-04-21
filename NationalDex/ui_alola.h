/********************************************************************************
** Form generated from reading UI file 'alola.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALOLA_H
#define UI_ALOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Alola
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Alola)
    {
        if (Alola->objectName().isEmpty())
            Alola->setObjectName(QString::fromUtf8("Alola"));
        Alola->resize(800, 600);
        actionExit = new QAction(Alola);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Alola);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Alola->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Alola);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Alola->setMenuBar(menubar);
        statusbar = new QStatusBar(Alola);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Alola->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Alola);

        QMetaObject::connectSlotsByName(Alola);
    } // setupUi

    void retranslateUi(QMainWindow *Alola)
    {
        Alola->setWindowTitle(QApplication::translate("Alola", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Alola", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Alola", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Alola", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Alola: public Ui_Alola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALOLA_H
