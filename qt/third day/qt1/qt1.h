#ifndef HELLO_H
#define HELLO_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QProcess>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
//#include <sqlite3.h>
#include "ui_qt1.h"



class Qt1: public QDialog,public Ui_Qt1
{
	Q_OBJECT
public:
	Qt1(QWidget *parent = 0);
	~Qt1();

//	void creatdatabase();
	void creatsqldatabase();
	void displayTable();
//	void displayDatabase();
signals:

	//mysig();
	
public slots:

	void fun();
	void fun1(QString);
	void fun3(QString);
	void fun2();

	void tellme(int);
	void textchange();
	void addtext();
	void settext(int);
	void settext1(QString);
	void settext2(int);

	void displayimage();
	void displayqt2();
private:

//	sqlite3 *db;
	QSqlDatabase database;
	QSqlQuery *query;

};

#endif 
