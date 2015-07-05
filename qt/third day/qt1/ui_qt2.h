/********************************************************************************
** Form generated from reading ui file 'qt2.ui'
**
** Created: Wed Jan 4 19:15:49 2012
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QT2_H
#define UI_QT2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLineEdit>

class Ui_Qt2
{
public:
    QLineEdit *lineEdit;

    void setupUi(QDialog *Qt2)
    {
    if (Qt2->objectName().isEmpty())
        Qt2->setObjectName(QString::fromUtf8("Qt2"));
    Qt2->resize(400, 300);
    lineEdit = new QLineEdit(Qt2);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(90, 80, 113, 27));

    retranslateUi(Qt2);

    QMetaObject::connectSlotsByName(Qt2);
    } // setupUi

    void retranslateUi(QDialog *Qt2)
    {
    Qt2->setWindowTitle(QApplication::translate("Qt2", "Dialog", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Qt2);
    } // retranslateUi

};

namespace Ui {
    class Qt2: public Ui_Qt2 {};
} // namespace Ui

#endif // UI_QT2_H
