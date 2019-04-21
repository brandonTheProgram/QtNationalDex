/********************************************************************************
** Form generated from reading UI file 'unova.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNOVA_H
#define UI_UNOVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Unova
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Unova)
    {
        if (Unova->objectName().isEmpty())
            Unova->setObjectName(QString::fromUtf8("Unova"));
        Unova->resize(800, 600);
        actionExit = new QAction(Unova);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Unova);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Unova->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Unova);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Unova->setMenuBar(menubar);
        statusbar = new QStatusBar(Unova);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Unova->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Unova);

        QMetaObject::connectSlotsByName(Unova);
    } // setupUi

    void retranslateUi(QMainWindow *Unova)
    {
        Unova->setWindowTitle(QApplication::translate("Unova", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Unova", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Unova", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Unova", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Unova: public Ui_Unova {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNOVA_H
