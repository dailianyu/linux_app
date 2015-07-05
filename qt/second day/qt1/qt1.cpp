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
	connect(pbOK,SIGNAL(clicked()),this,SLOT(fun()));
	connect(pbExit,SIGNAL(clicked()),this,SLOT(fun2()));

	le1->setAlignment(Qt::AlignRight);
//	le1->setMaxLength(4) ;
//	le2->setEchoMode(2);
	leRes->setReadOnly(true);

//	textchanged信号和textedit信号两者的一个区别在于，
//	textchanged信号是在文本有任何改变的时候就会触发这样的一个信号，
//	无论是编辑还是设置，都会触发这样的一个textchanged信号;
//	而textedit信号只是在编辑的时候才会发出这样的一个信号。
//	信号带参数的时候，不要给出参数名，只须给出参数类型即可。
	connect(le1,SIGNAL(textEdited(const QString &)),this,SLOT(fun1(QString)));
	connect(le2,SIGNAL(textChanged(const QString &)),this,SLOT(fun3(QString)));
	displayTable();

	connect(pbqqqq,SIGNAL(clicked()),tabWidget,SLOT(hide()));
	//qtabwidget当前页的改变，将会发送一个currentChanged信号
	connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tellme(int)));
}

void Qt1::tellme(int index)
{
	le1->setText(QString::number(index));
}

void Qt1::displayTable()
{
	//设置qtablewidget的行数和列数
	tableWidget->setColumnCount(4);
	tableWidget->setRowCount(4);
	//设置qtablewidget首部的内容
	tableWidget->setHorizontalHeaderItem(2, &QTableWidgetItem(tr("Column")));
	QTableWidgetItem *newitem = new QTableWidgetItem(tr("123"));
	//设置一个项的文本显示位置
	newitem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
	//把一个qtablewidgetitem项设置到qtablewidget上去
	tableWidget->setItem(1, 1, newitem);
}

void Qt1::fun3(QString text1)
{
//	le2->setText(le1->text());
	leRes->setText(text1);
}

void Qt1::fun1(QString text1)
{
//	le2->setText(le1->text());
	le2->setText(text1);

}

void Qt1::fun()
{
#if 0
	qDebug("funnnnn\n");
    QString a,b;

	a = le1->text();
	b = le2->text();

	double c = a.toDouble() + b.toDouble();
	qDebug("c=%lf\n",c);

	//char buf[100];
	//sprintf(buf,"%lf",c);

	leRes->setText(QString::number(c));
	label->setText(tr("hello world!"));	


	if(rbAdd->isChecked())
	{
		leRes->setText(QString::number(le1->text().toInt() + le2->text().toInt()));
	}

	if(rbSub->isChecked())
	{
		leRes->setText(QString::number(le1->text().toInt() - le2->text().toInt()));
	}
#endif

	//判断qcheckbox是否被选中
	if(cbKk->isChecked())
	{
		if(cbIi->isChecked())
		{
			leRes->setText(QString::number(le1->text().toInt() / le2->text().toInt()));
		}
		else
		{
			leRes->setText(QString::number(le1->text().toInt() - le2->text().toInt()));
		}
	}
	else
	{
		if(cbIi->isChecked())
		{
			leRes->setText(QString::number(le1->text().toInt() * le2->text().toInt()));
		}
		else
		{
			leRes->setText(QString::number(le1->text().toInt() + le2->text().toInt()));
		}		
	}
}

void Qt1::fun2()
{
	qDebug("fun22\n");
	 QString a,b;

	a = le1->text();
	b = le2->text();

	leRes->setText(a+b);

	//显示qtabwidget
	tabWidget->show();
	//获取qtabwidget当前页的索引值
	int index = tabWidget->currentIndex();
	qDebug()<<index;
	if(index == 2)
	{
		//设置索引值为当前页的索引为index
		tabWidget->setCurrentIndex(index - 2);
	}
	if(index >= 0 && index < 2)
	{
		tabWidget->setCurrentIndex(index + 1);
	}
}


Qt1::~Qt1()
{
 
}



