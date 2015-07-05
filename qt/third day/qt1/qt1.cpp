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
//创建qt自带的数据库
	creatsqldatabase();
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
//	connect(le2,SIGNAL(textChanged(const QString &)),this,SLOT(fun3(QString)));
	displayTable();
//	displayDatabase();
//	connect(pbqqqq,SIGNAL(clicked()),tabWidget,SLOT(hide()));
	connect(pbqqqq,SIGNAL(clicked()),this,SLOT(displayimage()));
//qtabwidget当前页的改变，将会发送一个currentChanged信号
	connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tellme(int)));
	connect(textEdit,SIGNAL(textChanged()),this,SLOT(textchange()));

	connect(pbanniu,SIGNAL(clicked()),this,SLOT(addtext()));

//spinBox的值的改变，发送一个valueChanged()信号
//	connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(settext(int)));
	connect(spinBox,SIGNAL(valueChanged(const QString &)),this,SLOT(settext1(QString)));

//slider的值的改变，发送一个valueChanged(int)信号
	connect(horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(settext2(int)));
//弹出二级界面
	connect(pbqt2,SIGNAL(clicked()),this,SLOT(displayqt2()));
}

void Qt1::creatsqldatabase()
{
//建立与SQLITE数据库驱动的连接
	database = QSqlDatabase::addDatabase("QSQLITE");
//	database.setHostName("fff");   设置主机名
	database.setDatabaseName("123.db");   //创建数据库文件名
//	database.setUserName("123");      //设置用户名
//	database.setPassword("123");      //设置密码
	database.open();        //打开数据库

//创建一个qsqlquery对象，通过它来对数据库文件进行操作，通过它来执行SQL语句
	query = new QSqlQuery();
	QString sqlquery = QString("CREATE TABLE StudentData(\
				ID INTEGER PRIMARY KEY,\
				SID TNTEGER);");

//执行SQL语句，执行失败返回false，执行成功返回true
	ok = query->exec(sqlquery);
	if(!ok)
	{
		//显示最后一次错误的信息
		qDebug()<<database.lastError().text();
	}

	sqlquery = QString("INSERT INTO StudentData VALUES(NULL, 22);");
	query->exec(sqlquery);

//使用prepare来指定一个包含占位符的查询，使用的是oracle的风格。
	query->prepare("INSERT INTO StudentData (ID, SID)"
				  "VALUES (:ID, :SID)");
//把数据和上面语句的点位符进行绑定，在执行SQL语句之前进行替换	
	query->bindValue(":SID", "Bart");
	query->exec();

	sqlquery = QString("SELECT * FROM StudentData");
	query->exec(sqlquery);

//执行完面的SQL语句，得到的结果在query这个对象上，通过对query进行调用next()
//这个函数，会把query指向第一个消息，这里说的是一行数据，然后用value()这个
//函数来获取到每一行消息当中的每一个字段的内容。当query指向了结果的最后时，
//会返回一个false。
	while(query->next())
	{	
//获取第一个字段的内容，从0开始计数
		QString country = query->value(0).toString();
		qDebug()<<country;
		QString iii = query->value(1).toString();
		qDebug()<<iii;
	}
}

#if 0
//这个是使用的自己安装的SQLITE数据库
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
//显示二级界面，并且把this指针传递到第二级界面去，供二级界面使用
	Qt2 *kk = new Qt2(this);
//	kk->show();     非模态显示二级界面
	kk->exec();     //模态显示二级界面
}
void Qt1::displayimage()
{
//在LABEL上面显示图片，并且以LABEL的大小来对图片进缩放
	image->setPixmap(QPixmap("./image/1.gif").scaled(image->width(), image->height()));
}

void Qt1::settext2(int value)
{
//设置spinbox的值
	spinBox->setValue(value);
//设置lcdnumber的值
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
//获取当前combobox的标签
	if(0 == comboBox->currentIndex())
	{
		leRes->setText(QString::number(le1->text().toInt() + le2->text().toInt()));
//设置combobox的当前标签
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
	//设置qtablewidget的行数和列数
	tableWidget->setColumnCount(4);
	tableWidget->setRowCount(4);
	//设置qtablewidget首部的内容
	tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Column")));
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
//	le2->setText(text1);
//	textEdit->setText(text1);  
//	textEdit->setFocus();   设置焦点
//	textEdit->append(text1); 设置追加
//把消息内容追加到textedit的后面，不进行覆盖，不进行换行
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



