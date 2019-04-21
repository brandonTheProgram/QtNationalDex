/********************************************************************************
** Form generated from reading UI file 'kalos.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KALOS_H
#define UI_KALOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Kalos
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Kalos)
    {
        if (Kalos->objectName().isEmpty())
            Kalos->setObjectName(QString::fromUtf8("Kalos"));
        Kalos->resize(800, 600);
        actionExit = new QAction(Kalos);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Kalos);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Kalos->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Kalos);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Kalos->setMenuBar(menubar);
        statusbar = new QStatusBar(Kalos);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Kalos->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Kalos);

        QMetaObject::connectSlotsByName(Kalos);
    } // setupUi

    void retranslateUi(QMainWindow *Kalos)
    {
        Kalos->setWindowTitle(QApplication::translate("Kalos", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Kalos", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Kalos", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Kalos", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kalos: public Ui_Kalos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KALOS_H
