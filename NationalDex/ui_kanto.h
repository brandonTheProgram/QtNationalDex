/********************************************************************************
** Form generated from reading UI file 'kanto.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KANTO_H
#define UI_KANTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Kanto
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Kanto)
    {
        if (Kanto->objectName().isEmpty())
            Kanto->setObjectName(QString::fromUtf8("Kanto"));
        Kanto->resize(632, 486);
        actionExit = new QAction(Kanto);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Kanto);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Kanto->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Kanto);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 632, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Kanto->setMenuBar(menubar);
        statusbar = new QStatusBar(Kanto);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Kanto->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Kanto);

        QMetaObject::connectSlotsByName(Kanto);
    } // setupUi

    void retranslateUi(QMainWindow *Kanto)
    {
        Kanto->setWindowTitle(QApplication::translate("Kanto", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Kanto", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Kanto", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Kanto", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kanto: public Ui_Kanto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KANTO_H
