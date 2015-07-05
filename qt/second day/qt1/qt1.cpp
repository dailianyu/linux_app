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

//	textchanged�źź�textedit�ź����ߵ�һ���������ڣ�
//	textchanged�ź������ı����κθı��ʱ��ͻᴥ��������һ���źţ�
//	�����Ǳ༭�������ã����ᴥ��������һ��textchanged�ź�;
//	��textedit�ź�ֻ���ڱ༭��ʱ��Żᷢ��������һ���źš�
//	�źŴ�������ʱ�򣬲�Ҫ������������ֻ������������ͼ��ɡ�
	connect(le1,SIGNAL(textEdited(const QString &)),this,SLOT(fun1(QString)));
	connect(le2,SIGNAL(textChanged(const QString &)),this,SLOT(fun3(QString)));
	displayTable();

	connect(pbqqqq,SIGNAL(clicked()),tabWidget,SLOT(hide()));
	//qtabwidget��ǰҳ�ĸı䣬���ᷢ��һ��currentChanged�ź�
	connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tellme(int)));
}

void Qt1::tellme(int index)
{
	le1->setText(QString::number(index));
}

void Qt1::displayTable()
{
	//����qtablewidget������������
	tableWidget->setColumnCount(4);
	tableWidget->setRowCount(4);
	//����qtablewidget�ײ�������
	tableWidget->setHorizontalHeaderItem(2, &QTableWidgetItem(tr("Column")));
	QTableWidgetItem *newitem = new QTableWidgetItem(tr("123"));
	//����һ������ı���ʾλ��
	newitem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
	//��һ��qtablewidgetitem�����õ�qtablewidget��ȥ
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

	//�ж�qcheckbox�Ƿ�ѡ��
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

	//��ʾqtabwidget
	tabWidget->show();
	//��ȡqtabwidget��ǰҳ������ֵ
	int index = tabWidget->currentIndex();
	qDebug()<<index;
	if(index == 2)
	{
		//��������ֵΪ��ǰҳ������Ϊindex
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



