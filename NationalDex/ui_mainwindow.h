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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(474, 362);
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
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        regionBox->setTitle(QApplication::translate("MainWindow", "REGIONS", nullptr));
        kantoButton->setText(QApplication::translate("MainWindow", "KANTO", nullptr));
        johtoButton->setText(QApplication::translate("MainWindow", "JOHTO", nullptr));
        hoennButton->setText(QApplication::translate("MainWindow", "HOENN", nullptr));
        sinnohButton->setText(QApplication::translate("MainWindow", "SINNOH", nullptr));
        unovaButton->setText(QApplication::translate("MainWindow", "UNOVA", nullptr));
        kalosButton->setText(QApplication::translate("MainWindow", "KALOS", nullptr));
        alolaButton->setText(QApplication::translate("MainWindow", "ALOLA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
