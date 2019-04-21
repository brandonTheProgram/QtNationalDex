/********************************************************************************
** Form generated from reading UI file 'introscene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROSCENE_H
#define UI_INTROSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroScene
{
public:
    QAction *actionOpen;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionOpen_Video;
    QAction *actionClose_Window;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuVideo;
    QMenu *menuExit;
    QMenu *menuHow_To;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IntroScene)
    {
        if (IntroScene->objectName().isEmpty())
            IntroScene->setObjectName(QString::fromUtf8("IntroScene"));
        IntroScene->resize(481, 374);
        actionOpen = new QAction(IntroScene);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/folder icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionPlay = new QAction(IntroScene);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/play button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon1);
        actionPause = new QAction(IntroScene);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/pause button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon2);
        actionStop = new QAction(IntroScene);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/stop button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        actionOpen_Video = new QAction(IntroScene);
        actionOpen_Video->setObjectName(QString::fromUtf8("actionOpen_Video"));
        actionClose_Window = new QAction(IntroScene);
        actionClose_Window->setObjectName(QString::fromUtf8("actionClose_Window"));
        centralwidget = new QWidget(IntroScene);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        IntroScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IntroScene);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 481, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuVideo = new QMenu(menubar);
        menuVideo->setObjectName(QString::fromUtf8("menuVideo"));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuHow_To = new QMenu(menubar);
        menuHow_To->setObjectName(QString::fromUtf8("menuHow_To"));
        IntroScene->setMenuBar(menubar);
        statusbar = new QStatusBar(IntroScene);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IntroScene->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuVideo->menuAction());
        menubar->addAction(menuExit->menuAction());
        menubar->addAction(menuHow_To->menuAction());
        menuFile->addAction(actionOpen);
        menuVideo->addAction(actionPlay);
        menuVideo->addAction(actionPause);
        menuVideo->addAction(actionStop);
        menuExit->addAction(actionStop);
        menuHow_To->addAction(actionOpen_Video);
        menuHow_To->addAction(actionClose_Window);

        retranslateUi(IntroScene);

        QMetaObject::connectSlotsByName(IntroScene);
    } // setupUi

    void retranslateUi(QMainWindow *IntroScene)
    {
        IntroScene->setWindowTitle(QApplication::translate("IntroScene", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("IntroScene", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("IntroScene", "Open a File", nullptr));
#endif // QT_NO_TOOLTIP
        actionPlay->setText(QApplication::translate("IntroScene", "Play", nullptr));
        actionPause->setText(QApplication::translate("IntroScene", "Pause", nullptr));
        actionStop->setText(QApplication::translate("IntroScene", "Stop", nullptr));
        actionOpen_Video->setText(QApplication::translate("IntroScene", "Open Video", nullptr));
        actionClose_Window->setText(QApplication::translate("IntroScene", "Close Window", nullptr));
        menuFile->setTitle(QApplication::translate("IntroScene", "File", nullptr));
        menuVideo->setTitle(QApplication::translate("IntroScene", "Video", nullptr));
        menuExit->setTitle(QApplication::translate("IntroScene", "Exit", nullptr));
        menuHow_To->setTitle(QApplication::translate("IntroScene", "How To", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntroScene: public Ui_IntroScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROSCENE_H
