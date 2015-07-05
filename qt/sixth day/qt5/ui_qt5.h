/********************************************************************************
** Form generated from reading ui file 'qt5.ui'
**
** Created: Mon Jan 9 18:33:27 2012
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QT5_H
#define UI_QT5_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

class Ui_Qt5
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPast;
    QAction *actionAbout;
    QWidget *centralwidget;
    QLabel *lb1;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Qt5)
    {
    if (Qt5->objectName().isEmpty())
        Qt5->setObjectName(QString::fromUtf8("Qt5"));
    Qt5->resize(790, 521);
    actionOpen = new QAction(Qt5);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    actionExit = new QAction(Qt5);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    actionCopy = new QAction(Qt5);
    actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
    actionPast = new QAction(Qt5);
    actionPast->setObjectName(QString::fromUtf8("actionPast"));
    actionAbout = new QAction(Qt5);
    actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
    centralwidget = new QWidget(Qt5);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    lb1 = new QLabel(centralwidget);
    lb1->setObjectName(QString::fromUtf8("lb1"));
    lb1->setGeometry(QRect(370, 200, 54, 18));
    Qt5->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Qt5);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 790, 26));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuEdit = new QMenu(menubar);
    menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    Qt5->setMenuBar(menubar);
    statusbar = new QStatusBar(Qt5);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Qt5->setStatusBar(statusbar);
    toolBar = new QToolBar(Qt5);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    Qt5->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuEdit->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionExit);
    menuEdit->addAction(actionCopy);
    menuEdit->addAction(actionPast);
    menuEdit->addSeparator();
    menuHelp->addAction(actionAbout);
    toolBar->addSeparator();

    retranslateUi(Qt5);

    QMetaObject::connectSlotsByName(Qt5);
    } // setupUi

    void retranslateUi(QMainWindow *Qt5)
    {
    Qt5->setWindowTitle(QApplication::translate("Qt5", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("Qt5", "Open", 0, QApplication::UnicodeUTF8));
    actionExit->setText(QApplication::translate("Qt5", "Exit", 0, QApplication::UnicodeUTF8));
    actionCopy->setText(QApplication::translate("Qt5", "Copy", 0, QApplication::UnicodeUTF8));
    actionPast->setText(QApplication::translate("Qt5", "Past", 0, QApplication::UnicodeUTF8));
    actionAbout->setText(QApplication::translate("Qt5", "About", 0, QApplication::UnicodeUTF8));
    lb1->setText(QApplication::translate("Qt5", "TextLabel", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("Qt5", "File", 0, QApplication::UnicodeUTF8));
    menuEdit->setTitle(QApplication::translate("Qt5", "Edit", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("Qt5", "Help", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("Qt5", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Qt5: public Ui_Qt5 {};
} // namespace Ui

#endif // UI_QT5_H
