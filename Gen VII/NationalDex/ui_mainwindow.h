/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSearch;
    QAction *actionType_Chart;
    QAction *actionNature_Chart;
    QWidget *centralWidget;
    QGroupBox *regionBox;
    QVBoxLayout *verticalLayout;
    QPushButton *kantoButton;
    QPushButton *johtoButton;
    QPushButton *hoennButton;
    QPushButton *sinnohButton;
    QPushButton *unovaButton;
    QPushButton *kalosButton;
    QPushButton *alolaButton;
    QMenuBar *menuBar;
    QMenu *menuSearch;
    QMenu *menuType_Chart;
    QMenu *menuNature_Chart;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(474, 362);
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/Search Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon);
        actionType_Chart = new QAction(MainWindow);
        actionType_Chart->setObjectName(QString::fromUtf8("actionType_Chart"));
        actionNature_Chart = new QAction(MainWindow);
        actionNature_Chart->setObjectName(QString::fromUtf8("actionNature_Chart"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        regionBox = new QGroupBox(centralWidget);
        regionBox->setObjectName(QString::fromUtf8("regionBox"));
        regionBox->setGeometry(QRect(20, 20, 441, 291));
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        font.setPointSize(15);
        regionBox->setFont(font);
        regionBox->setAutoFillBackground(false);
        regionBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(regionBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        kantoButton = new QPushButton(regionBox);
        kantoButton->setObjectName(QString::fromUtf8("kantoButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Impact"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        kantoButton->setFont(font1);

        verticalLayout->addWidget(kantoButton);

        johtoButton = new QPushButton(regionBox);
        johtoButton->setObjectName(QString::fromUtf8("johtoButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Impact"));
        font2.setPointSize(15);
        johtoButton->setFont(font2);

        verticalLayout->addWidget(johtoButton);

        hoennButton = new QPushButton(regionBox);
        hoennButton->setObjectName(QString::fromUtf8("hoennButton"));
        hoennButton->setFont(font2);

        verticalLayout->addWidget(hoennButton);

        sinnohButton = new QPushButton(regionBox);
        sinnohButton->setObjectName(QString::fromUtf8("sinnohButton"));
        sinnohButton->setFont(font2);

        verticalLayout->addWidget(sinnohButton);

        unovaButton = new QPushButton(regionBox);
        unovaButton->setObjectName(QString::fromUtf8("unovaButton"));
        unovaButton->setFont(font2);

        verticalLayout->addWidget(unovaButton);

        kalosButton = new QPushButton(regionBox);
        kalosButton->setObjectName(QString::fromUtf8("kalosButton"));
        kalosButton->setFont(font2);

        verticalLayout->addWidget(kalosButton);

        alolaButton = new QPushButton(regionBox);
        alolaButton->setObjectName(QString::fromUtf8("alolaButton"));
        alolaButton->setFont(font2);

        verticalLayout->addWidget(alolaButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 474, 17));
        menuSearch = new QMenu(menuBar);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        menuType_Chart = new QMenu(menuBar);
        menuType_Chart->setObjectName(QString::fromUtf8("menuType_Chart"));
        menuNature_Chart = new QMenu(menuBar);
        menuNature_Chart->setObjectName(QString::fromUtf8("menuNature_Chart"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSearch->menuAction());
        menuBar->addAction(menuType_Chart->menuAction());
        menuBar->addAction(menuNature_Chart->menuAction());
        menuSearch->addAction(actionSearch);
        menuType_Chart->addAction(actionType_Chart);
        menuNature_Chart->addAction(actionNature_Chart);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSearch->setText(QApplication::translate("MainWindow", "Search", nullptr));
        actionType_Chart->setText(QApplication::translate("MainWindow", "Type Chart", nullptr));
        actionNature_Chart->setText(QApplication::translate("MainWindow", "Nature Chart", nullptr));
        regionBox->setTitle(QApplication::translate("MainWindow", "REGIONS", nullptr));
        kantoButton->setText(QApplication::translate("MainWindow", "KANTO: 001-151", nullptr));
        johtoButton->setText(QApplication::translate("MainWindow", "JOHTO: 152 - 251", nullptr));
        hoennButton->setText(QApplication::translate("MainWindow", "HOENN: 252 - 386", nullptr));
        sinnohButton->setText(QApplication::translate("MainWindow", "SINNOH: 387 - 493", nullptr));
        unovaButton->setText(QApplication::translate("MainWindow", "UNOVA: 494 - 649", nullptr));
        kalosButton->setText(QApplication::translate("MainWindow", "KALOS: 650 - 721", nullptr));
        alolaButton->setText(QApplication::translate("MainWindow", "ALOLA: 722 - 807", nullptr));
        menuSearch->setTitle(QApplication::translate("MainWindow", "Search", nullptr));
        menuType_Chart->setTitle(QApplication::translate("MainWindow", "Type Chart", nullptr));
        menuNature_Chart->setTitle(QApplication::translate("MainWindow", "Nature Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
