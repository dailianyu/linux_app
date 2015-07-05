/********************************************************************************
** Form generated from reading ui file 'qt1.ui'
**
** Created: Thu Dec 29 19:36:56 2011
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QT1_H
#define UI_QT1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

class Ui_Qt1
{
public:
    QPushButton *pbOK;
    QPushButton *pbExit;
    QLineEdit *le1;
    QLineEdit *le2;
    QLineEdit *leRes;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Qt1)
    {
    if (Qt1->objectName().isEmpty())
        Qt1->setObjectName(QString::fromUtf8("Qt1"));
    Qt1->resize(514, 377);
    pbOK = new QPushButton(Qt1);
    pbOK->setObjectName(QString::fromUtf8("pbOK"));
    pbOK->setGeometry(QRect(150, 130, 80, 28));
    pbExit = new QPushButton(Qt1);
    pbExit->setObjectName(QString::fromUtf8("pbExit"));
    pbExit->setGeometry(QRect(160, 220, 80, 28));
    le1 = new QLineEdit(Qt1);
    le1->setObjectName(QString::fromUtf8("le1"));
    le1->setGeometry(QRect(30, 70, 91, 28));
    le2 = new QLineEdit(Qt1);
    le2->setObjectName(QString::fromUtf8("le2"));
    le2->setGeometry(QRect(180, 70, 91, 28));
    leRes = new QLineEdit(Qt1);
    leRes->setObjectName(QString::fromUtf8("leRes"));
    leRes->setGeometry(QRect(340, 70, 91, 28));
    label = new QLabel(Qt1);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(140, 80, 41, 18));
    label_2 = new QLabel(Qt1);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(300, 80, 31, 18));

    retranslateUi(Qt1);

    QMetaObject::connectSlotsByName(Qt1);
    } // setupUi

    void retranslateUi(QDialog *Qt1)
    {
    Qt1->setWindowTitle(QApplication::translate("Qt1", "Dialog", 0, QApplication::UnicodeUTF8));
    pbOK->setText(QApplication::translate("Qt1", "Add", 0, QApplication::UnicodeUTF8));
    pbExit->setText(QApplication::translate("Qt1", "exit", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Qt1", "+", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Qt1", "=", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Qt1);
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

#endif // UI_QT1_H
