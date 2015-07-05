#ifndef Qt5_H
#define Qt5_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QMainWindow>
#include <QPushButton>
#include <QTranslator>

#include "ui_qt5.h"

class Menu: public QMainWindow,public Ui_Qt5
{
	Q_OBJECT
public:
	Menu(QWidget *parent = 0);

	
public slots:
        void f1();
        void f2();
		void f3();
        void f4();
		void f5(QString s);

private:
	 QTranslator *translator;
	

};


#endif 
