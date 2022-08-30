/********************************************************************************
** Form generated from reading UI file 'region.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGION_H
#define UI_REGION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Region
{
public:
    QAction *actionExit;
    QAction *actionSearch;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuExit;
    QMenu *menuSearch;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Region)
    {
        if (Region->objectName().isEmpty())
            Region->setObjectName(QString::fromUtf8("Region"));
        Region->resize(800, 600);
        actionExit = new QAction(Region);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionSearch = new QAction(Region);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/Search Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon1);
        centralwidget = new QWidget(Region);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Region->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Region);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuSearch = new QMenu(menubar);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        Region->setMenuBar(menubar);
        statusbar = new QStatusBar(Region);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Region->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menubar->addAction(menuSearch->menuAction());
        menuExit->addAction(actionExit);
        menuSearch->addAction(actionSearch);

        retranslateUi(Region);

        QMetaObject::connectSlotsByName(Region);
    } // setupUi

    void retranslateUi(QMainWindow *Region)
    {
        Region->setWindowTitle(QApplication::translate("Region", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("Region", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Region", "Go Back To The Main Scene", nullptr));
#endif // QT_NO_TOOLTIP
        actionSearch->setText(QApplication::translate("Region", "Search", nullptr));
        menuExit->setTitle(QApplication::translate("Region", "Exit", nullptr));
        menuSearch->setTitle(QApplication::translate("Region", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Region: public Ui_Region {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGION_H
