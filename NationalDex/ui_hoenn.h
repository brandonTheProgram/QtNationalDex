/********************************************************************************
** Form generated from reading UI file 'hoenn.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOENN_H
#define UI_HOENN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hoenn
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Hoenn)
    {
        if (Hoenn->objectName().isEmpty())
            Hoenn->setObjectName(QString::fromUtf8("Hoenn"));
        Hoenn->resize(800, 600);
        actionExit = new QAction(Hoenn);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(Hoenn);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Hoenn->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Hoenn);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        Hoenn->setMenuBar(menubar);
        statusbar = new QStatusBar(Hoenn);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Hoenn->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(Hoenn);

        QMetaObject::connectSlotsByName(Hoenn);
    } // setupUi

    void retranslateUi(QMainWindow *Hoenn)
    {
        Hoenn->setWindowTitle(QApplication::translate("Hoenn", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Hoenn", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Hoenn", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        menuExit->setTitle(QApplication::translate("Hoenn", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hoenn: public Ui_Hoenn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOENN_H
