/********************************************************************************
** Form generated from reading UI file 'sinnoh.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINNOH_H
#define UI_SINNOH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sinnoh
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Sinnoh)
    {
        if (Sinnoh->objectName().isEmpty())
            Sinnoh->setObjectName(QString::fromUtf8("Sinnoh"));
        Sinnoh->resize(800, 600);
        actionExit = new QAction(Sinnoh);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Sinnoh);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Sinnoh->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Sinnoh);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Sinnoh->setMenuBar(menubar);
        statusbar = new QStatusBar(Sinnoh);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Sinnoh->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Sinnoh);

        QMetaObject::connectSlotsByName(Sinnoh);
    } // setupUi

    void retranslateUi(QMainWindow *Sinnoh)
    {
        Sinnoh->setWindowTitle(QApplication::translate("Sinnoh", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Sinnoh", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Sinnoh", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Sinnoh", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sinnoh: public Ui_Sinnoh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINNOH_H
