#ifndef HELLO_H
#define HELLO_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QProcess>
#include <QTimer>


#include "ui_qt1.h"



class Qt1: public QDialog,public Ui_Qt1
{
	Q_OBJECT
public:
	Qt1(QWidget *parent = 0);
	~Qt1();


signals:

	//mysig();
	
public slots:

	void fun1();
	void fun2();

private:
	
};


#endif 
