#ifndef HELLO_H
#define HELLO_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QProcess>
#include <QTimer>
#include <QThread>
#include <QTcpSocket>


#include "ui_qt1.h"
class Qt1;

class MyThread : public QThread
 {
 	Q_OBJECT
 public:
 	 MyThread(void *arg);
     void run();
	 Qt1 *p;
signals:

	 void threadsig(int);
 };



class Qt1: public QDialog,public Ui_Qt1
{
	Q_OBJECT
public:
	Qt1(QWidget *parent = 0);
	~Qt1();
	int value;
	MyThread *pt;

	QProcess *pr;

	QTcpSocket  *newSocket;

	int pid;

	QColor c;

	QTimer *timer;

	int timerid;
	int timerid2;

	//void paintEvent(QPaintEvent *);
	
	void timerEvent(QTimerEvent *);


signals:

	void mysig(int);
	
public slots:
	   void mainwinslot(int);

	    void myslot(int);
		void closefun();

		void inputfun();
		void fontfun();
		void colorfun();
		void te1fun();
		void filefun();
		void tstartfun();
		void tstopfun();
		void timeoutfun();

		void tstartfun2();
		void tstopfun2();


	void fun();
	void fun2();
	void thstart();
	void thstop();

	void thstart2();
	void thstop2();

	void prstart();
	void prstop();

	void prstart2();
	void prstop2();

	void netfun();
	void netfun2();

	void recvfun();


private:
	int id;// Ïß³ÌID
	
	
};


#endif 
