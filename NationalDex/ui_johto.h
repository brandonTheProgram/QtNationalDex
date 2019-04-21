/********************************************************************************
** Form generated from reading UI file 'johto.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOHTO_H
#define UI_JOHTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Johto
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Johto)
    {
        if (Johto->objectName().isEmpty())
            Johto->setObjectName(QString::fromUtf8("Johto"));
        Johto->resize(800, 600);
        actionExit = new QAction(Johto);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Johto);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Johto->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Johto);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Johto->setMenuBar(menubar);
        statusbar = new QStatusBar(Johto);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Johto->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Johto);

        QMetaObject::connectSlotsByName(Johto);
    } // setupUi

    void retranslateUi(QMainWindow *Johto)
    {
        Johto->setWindowTitle(QApplication::translate("Johto", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Johto", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Johto", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Johto", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Johto: public Ui_Johto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOHTO_H
