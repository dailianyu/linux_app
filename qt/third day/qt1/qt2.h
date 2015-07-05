#ifndef TT_H
#define TT_H

#include <QDialog>
#include <QWidget>

#include "ui_qt2.h"
#include "qt1.h"



class Qt2: public QDialog,public Ui_Qt2
{
	Q_OBJECT
public:
	Qt2(QWidget *parent = 0);
	
public slots:
	void sendmessage(QString);
private:
	Qt1 *qt1;
};

#endif 

