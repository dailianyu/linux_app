/********************************************************************************
** Form generated from reading ui file 'qt1.ui'
**
** Created: Wed Jan 4 19:06:18 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_Qt1
{
public:
    QGroupBox *groupBox;
    QRadioButton *rbAdd;
    QRadioButton *rbSub;
    QCheckBox *cbKk;
    QCheckBox *cbIi;
    QTableWidget *tableWidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QPushButton *pbqqqq;
    QLabel *image;
    QWidget *tab_2;
    QTextEdit *textEdit;
    QPushButton *pbqt2;
    QWidget *tab3;
    QComboBox *comboBox;
    QPushButton *pbanniu;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    QWidget *widget;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLineEdit *le1;
    QLabel *label;
    QLineEdit *le2;
    QLabel *label_2;
    QLineEdit *leRes;
    QHBoxLayout *hboxLayout1;
    QPushButton *pbOK;
    QSpacerItem *spacerItem;
    QPushButton *pbExit;

    void setupUi(QDialog *Qt1)
    {
    if (Qt1->objectName().isEmpty())
        Qt1->setObjectName(QString::fromUtf8("Qt1"));
    Qt1->resize(587, 418);
    groupBox = new QGroupBox(Qt1);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(0, 80, 251, 61));
    rbAdd = new QRadioButton(groupBox);
    rbAdd->setObjectName(QString::fromUtf8("rbAdd"));
    rbAdd->setGeometry(QRect(20, 20, 51, 23));
    rbSub = new QRadioButton(groupBox);
    rbSub->setObjectName(QString::fromUtf8("rbSub"));
    rbSub->setGeometry(QRect(20, 40, 51, 23));
    cbKk = new QCheckBox(groupBox);
    cbKk->setObjectName(QString::fromUtf8("cbKk"));
    cbKk->setGeometry(QRect(140, 20, 82, 23));
    cbIi = new QCheckBox(groupBox);
    cbIi->setObjectName(QString::fromUtf8("cbIi"));
    cbIi->setGeometry(QRect(140, 40, 82, 23));
    tableWidget = new QTableWidget(Qt1);
    tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
    tableWidget->setGeometry(QRect(0, 150, 251, 111));
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    tabWidget = new QTabWidget(Qt1);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(0, 270, 251, 121));
    tab1 = new QWidget();
    tab1->setObjectName(QString::fromUtf8("tab1"));
    pbqqqq = new QPushButton(tab1);
    pbqqqq->setObjectName(QString::fromUtf8("pbqqqq"));
    pbqqqq->setGeometry(QRect(0, 10, 80, 27));
    image = new QLabel(tab1);
    image->setObjectName(QString::fromUtf8("image"));
    image->setGeometry(QRect(100, 10, 131, 81));
    tabWidget->addTab(tab1, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    textEdit = new QTextEdit(tab_2);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setGeometry(QRect(10, 10, 104, 75));
    pbqt2 = new QPushButton(tab_2);
    pbqt2->setObjectName(QString::fromUtf8("pbqt2"));
    pbqt2->setGeometry(QRect(130, 30, 80, 27));
    tabWidget->addTab(tab_2, QString());
    tab3 = new QWidget();
    tab3->setObjectName(QString::fromUtf8("tab3"));
    comboBox = new QComboBox(tab3);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(10, 10, 78, 26));
    pbanniu = new QPushButton(tab3);
    pbanniu->setObjectName(QString::fromUtf8("pbanniu"));
    pbanniu->setGeometry(QRect(110, 10, 80, 27));
    spinBox = new QSpinBox(tab3);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setGeometry(QRect(10, 50, 55, 27));
    spinBox->setSingleStep(2);
    horizontalSlider = new QSlider(tab3);
    horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
    horizontalSlider->setGeometry(QRect(80, 40, 160, 16));
    horizontalSlider->setOrientation(Qt::Horizontal);
    lcdNumber = new QLCDNumber(tab3);
    lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
    lcdNumber->setGeometry(QRect(80, 60, 141, 23));
    tabWidget->addTab(tab3, QString());
    widget = new QWidget(Qt1);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(0, 0, 251, 78));
    vboxLayout = new QVBoxLayout(widget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    le1 = new QLineEdit(widget);
    le1->setObjectName(QString::fromUtf8("le1"));

    hboxLayout->addWidget(le1);

    label = new QLabel(widget);
    label->setObjectName(QString::fromUtf8("label"));

    hboxLayout->addWidget(label);

    le2 = new QLineEdit(widget);
    le2->setObjectName(QString::fromUtf8("le2"));

    hboxLayout->addWidget(le2);

    label_2 = new QLabel(widget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    hboxLayout->addWidget(label_2);

    leRes = new QLineEdit(widget);
    leRes->setObjectName(QString::fromUtf8("leRes"));

    hboxLayout->addWidget(leRes);


    vboxLayout->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    pbOK = new QPushButton(widget);
    pbOK->setObjectName(QString::fromUtf8("pbOK"));

    hboxLayout1->addWidget(pbOK);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    pbExit = new QPushButton(widget);
    pbExit->setObjectName(QString::fromUtf8("pbExit"));

    hboxLayout1->addWidget(pbExit);


    vboxLayout->addLayout(hboxLayout1);


    retranslateUi(Qt1);

    tabWidget->setCurrentIndex(1);


    QMetaObject::connectSlotsByName(Qt1);
    } // setupUi

    void retranslateUi(QDialog *Qt1)
    {
    Qt1->setWindowTitle(QApplication::translate("Qt1", "Dialog", 0, QApplication::UnicodeUTF8));
    Qt1->setStyleSheet(QApplication::translate("Qt1", "QPushButton { \n"
"		color: red ;\n"
"/*		border-radius : 6px;  */\n"
"}", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Qt1", "GroupBox", 0, QApplication::UnicodeUTF8));
    rbAdd->setText(QApplication::translate("Qt1", "\345\212\240\346\263\225", 0, QApplication::UnicodeUTF8));
    rbSub->setText(QApplication::translate("Qt1", "\345\207\217\346\263\225", 0, QApplication::UnicodeUTF8));
    cbKk->setText(QApplication::translate("Qt1", "kk", 0, QApplication::UnicodeUTF8));
    cbIi->setText(QApplication::translate("Qt1", "ii", 0, QApplication::UnicodeUTF8));
    pbqqqq->setText(QApplication::translate("Qt1", "qqqq", 0, QApplication::UnicodeUTF8));
    image->setText(QApplication::translate("Qt1", "TextLabel", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("Qt1", "\347\254\254\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
    pbqt2->setText(QApplication::translate("Qt1", "Qt2", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Qt1", "\347\254\254\344\272\214\351\241\265", 0, QApplication::UnicodeUTF8));
    comboBox->clear();
    comboBox->insertItems(0, QStringList()
     << QApplication::translate("Qt1", "+", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Qt1", "-", 0, QApplication::UnicodeUTF8)
    );
    pbanniu->setText(QApplication::translate("Qt1", "anniu", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("Qt1", "\347\254\254\344\270\211\351\241\265", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Qt1", "+", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Qt1", "=", 0, QApplication::UnicodeUTF8));
    pbOK->setText(QApplication::translate("Qt1", "Add", 0, QApplication::UnicodeUTF8));
    pbExit->setText(QApplication::translate("Qt1", "exit", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Qt1);
    } // retranslateUi

};

namespace Ui {
    class Qt1: public Ui_Qt1 {};
} // namespace Ui

#endif // UI_QT1_H
