#include <math.h>
#include <QPainter>
#include <stdio.h>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QLineEdit>
#include <QTimer>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>
#include <QProcess>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include "qt1.h"

Qt1::Qt1(QWidget *parent):QDialog(parent)
{
	setupUi(this);
	connect(pbOK,SIGNAL(clicked()),this,SLOT(fun1()));
	connect(pbExit,SIGNAL(clicked()),this,SLOT(fun2()));

	le1->setAlignment(Qt::AlignRight);
	le1->setMaxLength(4);
	le2->setEchoMode(2);
	leRes->setReadOnly(true);
}

void Qt1::fun()
{
	qDebug("funnnnn\n");
    QString a,b;

	a = le1->text();
	b = le2->text();

	double c = a.toDouble() + b.toDouble();
	qDebug("c=%lf\n",c);

	//char buf[100];
	//sprintf(buf,"%lf",c);

	leRes->setText(QString::number(c));
}

void Qt1::fun2()
{
	qDebug("fun22\n");
	QString a,b;

	a = le1->text();
	b = le2->text();

	leRes->setText(a+b);
}


Qt1::~Qt1()
{
 
}

