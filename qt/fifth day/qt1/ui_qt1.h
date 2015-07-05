/********************************************************************************
** Form generated from reading ui file 'qt1.ui'
**
** Created: Sun Jan 8 19:57:04 2012
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
#include <QtGui/QTextEdit>

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
    QPushButton *pbinput;
    QPushButton *pbfont;
    QTextEdit *te1;
    QPushButton *pbcolor;
    QPushButton *pbfile;
    QPushButton *tstart;
    QPushButton *tstop;
    QLabel *lbtime;
    QPushButton *tstart2;
    QPushButton *tstop2;

    void setupUi(QDialog *Qt1)
    {
    if (Qt1->objectName().isEmpty())
        Qt1->setObjectName(QString::fromUtf8("Qt1"));
    Qt1->resize(568, 444);
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
    QPalette palette;
    QBrush brush(QColor(255, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(0, 255, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Text, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
    QBrush brush2(QColor(127, 125, 123, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    leRes->setPalette(palette);
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
    pbinput = new QPushButton(Qt1);
    pbinput->setObjectName(QString::fromUtf8("pbinput"));
    pbinput->setGeometry(QRect(30, 20, 80, 28));
    pbfont = new QPushButton(Qt1);
    pbfont->setObjectName(QString::fromUtf8("pbfont"));
    pbfont->setGeometry(QRect(140, 20, 80, 28));
    te1 = new QTextEdit(Qt1);
    te1->setObjectName(QString::fromUtf8("te1"));
    te1->setGeometry(QRect(310, 290, 171, 121));
    pbcolor = new QPushButton(Qt1);
    pbcolor->setObjectName(QString::fromUtf8("pbcolor"));
    pbcolor->setGeometry(QRect(260, 20, 80, 28));
    pbfile = new QPushButton(Qt1);
    pbfile->setObjectName(QString::fromUtf8("pbfile"));
    pbfile->setGeometry(QRect(370, 20, 80, 28));
    tstart = new QPushButton(Qt1);
    tstart->setObjectName(QString::fromUtf8("tstart"));
    tstart->setGeometry(QRect(30, 360, 80, 28));
    tstop = new QPushButton(Qt1);
    tstop->setObjectName(QString::fromUtf8("tstop"));
    tstop->setGeometry(QRect(30, 400, 80, 28));
    lbtime = new QLabel(Qt1);
    lbtime->setObjectName(QString::fromUtf8("lbtime"));
    lbtime->setGeometry(QRect(110, 160, 301, 20));
    tstart2 = new QPushButton(Qt1);
    tstart2->setObjectName(QString::fromUtf8("tstart2"));
    tstart2->setGeometry(QRect(160, 360, 80, 28));
    tstop2 = new QPushButton(Qt1);
    tstop2->setObjectName(QString::fromUtf8("tstop2"));
    tstop2->setGeometry(QRect(160, 400, 80, 28));

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
    pbinput->setText(QApplication::translate("Qt1", "Input", 0, QApplication::UnicodeUTF8));
    pbfont->setText(QApplication::translate("Qt1", "Font", 0, QApplication::UnicodeUTF8));
    pbcolor->setText(QApplication::translate("Qt1", "color", 0, QApplication::UnicodeUTF8));
    pbfile->setText(QApplication::translate("Qt1", "file", 0, QApplication::UnicodeUTF8));
    tstart->setText(QApplication::translate("Qt1", "timer start", 0, QApplication::UnicodeUTF8));
    tstop->setText(QApplication::translate("Qt1", "timer stop", 0, QApplication::UnicodeUTF8));
    lbtime->setText(QApplication::translate("Qt1", "TextLabel", 0, QApplication::UnicodeUTF8));
    tstart2->setText(QApplication::translate("Qt1", "timer start2", 0, QApplication::UnicodeUTF8));
    tstop2->setText(QApplication::translate("Qt1", "timer stop2", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Qt1);
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

#endif // UI_QT1_H
