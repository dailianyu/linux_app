#include <math.h>
#include <QPainter>
#include <stdio.h>
#include <QSqlError>
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
#include "qt2.h"

Qt1::Qt1(QWidget *parent):QDialog(parent)
{
	setupUi(this);
//����qt�Դ������ݿ�
	creatsqldatabase();
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
//	connect(le2,SIGNAL(textChanged(const QString &)),this,SLOT(fun3(QString)));
	displayTable();
//	displayDatabase();
//	connect(pbqqqq,SIGNAL(clicked()),tabWidget,SLOT(hide()));
	connect(pbqqqq,SIGNAL(clicked()),this,SLOT(displayimage()));
//qtabwidget��ǰҳ�ĸı䣬���ᷢ��һ��currentChanged�ź�
	connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tellme(int)));
	connect(textEdit,SIGNAL(textChanged()),this,SLOT(textchange()));

	connect(pbanniu,SIGNAL(clicked()),this,SLOT(addtext()));

//spinBox��ֵ�ĸı䣬����һ��valueChanged()�ź�
//	connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(settext(int)));
	connect(spinBox,SIGNAL(valueChanged(const QString &)),this,SLOT(settext1(QString)));

//slider��ֵ�ĸı䣬����һ��valueChanged(int)�ź�
	connect(horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(settext2(int)));
//������������
	connect(pbqt2,SIGNAL(clicked()),this,SLOT(displayqt2()));
}

void Qt1::creatsqldatabase()
{
//������SQLITE���ݿ�����������
	database = QSqlDatabase::addDatabase("QSQLITE");
//	database.setHostName("fff");   ����������
	database.setDatabaseName("123.db");   //�������ݿ��ļ���
//	database.setUserName("123");      //�����û���
//	database.setPassword("123");      //��������
	database.open();        //�����ݿ�

//����һ��qsqlquery����ͨ�����������ݿ��ļ����в�����ͨ������ִ��SQL���
	query = new QSqlQuery();
	QString sqlquery = QString("CREATE TABLE StudentData(\
				ID INTEGER PRIMARY KEY,\
				SID TNTEGER);");

//ִ��SQL��䣬ִ��ʧ�ܷ���false��ִ�гɹ�����true
	ok = query->exec(sqlquery);
	if(!ok)
	{
		//��ʾ���һ�δ������Ϣ
		qDebug()<<database.lastError().text();
	}

	sqlquery = QString("INSERT INTO StudentData VALUES(NULL, 22);");
	query->exec(sqlquery);

//ʹ��prepare��ָ��һ������ռλ���Ĳ�ѯ��ʹ�õ���oracle�ķ��
	query->prepare("INSERT INTO StudentData (ID, SID)"
				  "VALUES (:ID, :SID)");
//�����ݺ��������ĵ�λ�����а󶨣���ִ��SQL���֮ǰ�����滻	
	query->bindValue(":SID", "Bart");
	query->exec();

	sqlquery = QString("SELECT * FROM StudentData");
	query->exec(sqlquery);

//ִ�������SQL��䣬�õ��Ľ����query��������ϣ�ͨ����query���е���next()
//������������queryָ���һ����Ϣ������˵����һ�����ݣ�Ȼ����value()���
//��������ȡ��ÿһ����Ϣ���е�ÿһ���ֶε����ݡ���queryָ���˽�������ʱ��
//�᷵��һ��false��
	while(query->next())
	{	
//��ȡ��һ���ֶε����ݣ���0��ʼ����
		QString country = query->value(0).toString();
		qDebug()<<country;
		QString iii = query->value(1).toString();
		qDebug()<<iii;
	}
}

#if 0
//�����ʹ�õ��Լ���װ��SQLITE���ݿ�
void Qt1::creatdatabase()
{
	int ret;
	char *zErrMsg;
	ret = sqlite3_open("student.db",&db);
	
	if(ret)
	{
		fprintf(stderr,"cannot open database:%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(-1); 
	}
	else
	{
		printf("you are right\n");
	}
	
	char *sql = (char *)"CREATE TABLE StudentData(\
				ID INTEGER PRIMARY KEY,\
				SID TNTEGER,\
				Name VARCHAR(20),\
				Score INTEGER\
				);";

	sqlite3_exec(db,sql,0,0,&zErrMsg);		
}
#endif

void Qt1::displayqt2()
{
//��ʾ�������棬���Ұ�thisָ�봫�ݵ��ڶ�������ȥ������������ʹ��
	Qt2 *kk = new Qt2(this);
//	kk->show();     ��ģ̬��ʾ��������
	kk->exec();     //ģ̬��ʾ��������
}
void Qt1::displayimage()
{
//��LABEL������ʾͼƬ��������LABEL�Ĵ�С����ͼƬ������
	image->setPixmap(QPixmap("./image/1.gif").scaled(image->width(), image->height()));
}

void Qt1::settext2(int value)
{
//����spinbox��ֵ
	spinBox->setValue(value);
//����lcdnumber��ֵ
	lcdNumber->display(value);
}

void Qt1::settext1(QString value)
{
	leRes->setText(value);
}

void Qt1::settext(int value)
{
	leRes->setText(QString::number(value));
}

void Qt1::addtext()
{
//��ȡ��ǰcombobox�ı�ǩ
	if(0 == comboBox->currentIndex())
	{
		leRes->setText(QString::number(le1->text().toInt() + le2->text().toInt()));
//����combobox�ĵ�ǰ��ǩ
		comboBox->setCurrentIndex(1);
	}
	else if(1 == comboBox->currentIndex())
	{
		leRes->setText(QString::number(le1->text().toInt() - le2->text().toInt()));
		comboBox->setCurrentIndex(0);
	}
}

void Qt1::textchange()
{
#if 0
	QTextDocument *text = textEdit->document();
	qDebug()<<text->toPlainText();
#endif
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
	tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Column")));
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
//	le2->setText(text1);
//	textEdit->setText(text1);  
//	textEdit->setFocus();   ���ý���
//	textEdit->append(text1); ����׷��
//����Ϣ����׷�ӵ�textedit�ĺ��棬�����и��ǣ������л���
	textEdit->textCursor().insertText(text1);
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



