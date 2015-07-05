#include <math.h>
#include <QPainter>
#include <stdio.h>
#include <QTimer>
#include <unistd.h>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QInputDialog>
#include <QFileDialog>
#include <QColor>
#include <QDir>
#include <QFontDialog>
#include "qt5.h"

Menu::Menu(QWidget *parent):QMainWindow(parent)
{
  // ui = new Ui_MainWindow;

  // ui->setupUi(this);
      setupUi(this);
  


#if 1  
   // ¹¤¾ßÀ¸
   QAction *act1 = toolBar->addAction(QIcon("pic/dgt-1.png"), "dgt1");
   toolBar->addSeparator();
   QAction *act2 = toolBar->addAction(QIcon("pic/dgt-2.png"), "dgt2");
   connect(act1,SIGNAL(triggered()),this,SLOT(f3())); 
   connect(act2,SIGNAL(triggered()),this,SLOT(f4())); 
#endif

    // ²Ëµ¥
   connect(actionOpen,SIGNAL(triggered()),this,SLOT(f1())); 
   connect(actionCopy,SIGNAL(triggered()),this,SLOT(f2())); 
   connect(actionExit,SIGNAL(triggered()),this,SLOT(close())); 


  translator = new QTranslator;

 }



void Menu::f1()
{
#if 1
  qDebug("f1\n");
  lb1->setText("Open");
  statusbar->showMessage("open",3000); // ×´Ì¬À¸
#endif
} 


void Menu::f2()
{
#if 1
   qDebug("f2\n");
   lb1->setText("Copy");
   statusbar->showMessage("Copy");
#endif
}


void Menu::f3()
{
	qDebug("f3\n");
	 lb1->setText("f3");
	f5(QString("en"));

   
}

void Menu::f4()
{
	qDebug("f4\n");
	 lb1->setText("f4");
	f5(QString("zh_CN"));

   
}

#if 1


void Menu::f5(QString s)
{

    if (translator->load(s))
    {
    	qApp->installTranslator(translator);
    }

	retranslateUi(this);

}

#endif



