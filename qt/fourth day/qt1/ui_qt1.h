/********************************************************************************
** Form generated from reading ui file 'qt1.ui'
**
** Created: Thu Jan 5 19:46:11 2012
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
    QPushButton *pbthstart;
    QPushButton *pbthstop;
    QPushButton *pbthstart2;
    QPushButton *pbthstop2;
    QPushButton *pbprstart;
    QPushButton *pbprstop;
    QPushButton *pbprstart2;
    QPushButton *pbprstop2;
    QPushButton *pbNet;
    QPushButton *pbNet2;

    void setupUi(QDialog *Qt1)
    {
    if (Qt1->objectName().isEmpty())
        Qt1->setObjectName(QString::fromUtf8("Qt1"));
    Qt1->resize(514, 377);
    pbOK = new QPushButton(Qt1);
    pbOK->setObjectName(QString::fromUtf8("pbOK"));
    pbOK->setGeometry(QRect(30, 130, 80, 28));
    pbExit = new QPushButton(Qt1);
    pbExit->setObjectName(QString::fromUtf8("pbExit"));
    pbExit->setGeometry(QRect(170, 130, 80, 28));
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
    pbthstart = new QPushButton(Qt1);
    pbthstart->setObjectName(QString::fromUtf8("pbthstart"));
    pbthstart->setGeometry(QRect(30, 190, 80, 28));
    pbthstop = new QPushButton(Qt1);
    pbthstop->setObjectName(QString::fromUtf8("pbthstop"));
    pbthstop->setGeometry(QRect(30, 240, 80, 28));
    pbthstart2 = new QPushButton(Qt1);
    pbthstart2->setObjectName(QString::fromUtf8("pbthstart2"));
    pbthstart2->setGeometry(QRect(150, 190, 80, 28));
    pbthstop2 = new QPushButton(Qt1);
    pbthstop2->setObjectName(QString::fromUtf8("pbthstop2"));
    pbthstop2->setGeometry(QRect(150, 240, 80, 28));
    pbprstart = new QPushButton(Qt1);
    pbprstart->setObjectName(QString::fromUtf8("pbprstart"));
    pbprstart->setGeometry(QRect(270, 190, 80, 28));
    pbprstop = new QPushButton(Qt1);
    pbprstop->setObjectName(QString::fromUtf8("pbprstop"));
    pbprstop->setGeometry(QRect(270, 240, 80, 28));
    pbprstart2 = new QPushButton(Qt1);
    pbprstart2->setObjectName(QString::fromUtf8("pbprstart2"));
    pbprstart2->setGeometry(QRect(390, 190, 80, 28));
    pbprstop2 = new QPushButton(Qt1);
    pbprstop2->setObjectName(QString::fromUtf8("pbprstop2"));
    pbprstop2->setGeometry(QRect(390, 240, 80, 28));
    pbNet = new QPushButton(Qt1);
    pbNet->setObjectName(QString::fromUtf8("pbNet"));
    pbNet->setGeometry(QRect(30, 310, 80, 28));
    pbNet2 = new QPushButton(Qt1);
    pbNet2->setObjectName(QString::fromUtf8("pbNet2"));
    pbNet2->setGeometry(QRect(160, 310, 80, 28));

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
    pbthstart->setText(QApplication::translate("Qt1", "threadstart", 0, QApplication::UnicodeUTF8));
    pbthstop->setText(QApplication::translate("Qt1", "threadstop", 0, QApplication::UnicodeUTF8));
    pbthstart2->setText(QApplication::translate("Qt1", "threadstart2", 0, QApplication::UnicodeUTF8));
    pbthstop2->setText(QApplication::translate("Qt1", "threadstop2", 0, QApplication::UnicodeUTF8));
    pbprstart->setText(QApplication::translate("Qt1", "procssstart", 0, QApplication::UnicodeUTF8));
    pbprstop->setText(QApplication::translate("Qt1", "processstop", 0, QApplication::UnicodeUTF8));
    pbprstart2->setText(QApplication::translate("Qt1", "procssstart2", 0, QApplication::UnicodeUTF8));
    pbprstop2->setText(QApplication::translate("Qt1", "processstop2", 0, QApplication::UnicodeUTF8));
    pbNet->setText(QApplication::translate("Qt1", "net", 0, QApplication::UnicodeUTF8));
    pbNet2->setText(QApplication::translate("Qt1", "net2", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Qt1);
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

#endif // UI_QT1_H
