#include <math.h>
#include <signal.h>

#include <QPainter>
#include <stdio.h>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QLineEdit>
#include <QTimer>
#include <unistd.h>
#include <pthread.h>
#include <QColor>


#include <QProcess>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include "qt1.h"

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 					
#include <fcntl.h>
#include <arpa/inet.h>	

#include <QHostAddress>
#include <QDateTime>



#define SERVER_IP_ADDR  "192.168.1.235"
#define SERVER_PORT  	8000



MyThread::MyThread(void *arg)
{
	qDebug("MyThread created");
	p = (Qt1 *)arg;
}


void MyThread::run()
{
    int i = 0;
	qDebug("MyThread run");
	while(1)
	{
		i++;
		p->value++;
		qDebug("%d",p->value);

		//p->update(); // 此处引起paintevent
		emit threadsig(i);
		
		QThread::sleep(1);

	}
}



Qt1::Qt1(QWidget *parent):QDialog(parent)
{
  setupUi(this);
  connect(pbOK,SIGNAL(clicked()),this,SLOT(fun()));
  connect(pbExit,SIGNAL(clicked()),this,SLOT(closefun()));

  //////  线程方法1
  connect(pbthstart,SIGNAL(clicked()),this,SLOT(thstart()));
  connect(pbthstop,SIGNAL(clicked()),this,SLOT(thstop()));


  
  //////  线程方法2
	connect(pbthstart2,SIGNAL(clicked()),this,SLOT(thstart2()));
	connect(pbthstop2,SIGNAL(clicked()),this,SLOT(thstop2()));

    value = 100;


	 //////  进程方法1
	connect(pbprstart,SIGNAL(clicked()),this,SLOT(prstart()));
	connect(pbprstop,SIGNAL(clicked()),this,SLOT(prstop()));


	 //////  进程方法2
	connect(pbprstart2,SIGNAL(clicked()),this,SLOT(prstart2()));
	connect(pbprstop2,SIGNAL(clicked()),this,SLOT(prstop2()));


	 //////  网络
	connect(pbNet,SIGNAL(clicked()),this,SLOT(netfun()));

	 //////  网络2
	connect(pbNet2,SIGNAL(clicked()),this,SLOT(netfun2()));


	  //////  input
	connect(pbinput,SIGNAL(clicked()),this,SLOT(inputfun()));


	    //////  font
	connect(pbfont,SIGNAL(clicked()),this,SLOT(fontfun()));

		//////  color
	connect(pbcolor,SIGNAL(clicked()),this,SLOT(colorfun()));

		
	//connect(te1,SIGNAL(textChanged()),this,SLOT(te1fun()));

    // 多行框设置颜色，在获取焦点的时候先设置
	connect(te1,SIGNAL(selectionChanged()),this,SLOT(te1fun()));


	//////  file
	connect(pbfile,SIGNAL(clicked()),this,SLOT(filefun()));


	//// 定时器1

	timer =  new QTimer();
	connect(tstart,SIGNAL(clicked()),this,SLOT(tstartfun()));
	connect(tstop,SIGNAL(clicked()),this,SLOT(tstopfun()));
	connect(timer,SIGNAL(timeout()),this,SLOT(timeoutfun()));



	//// 定时器2
	connect(tstart2,SIGNAL(clicked()),this,SLOT(tstartfun2()));
	connect(tstop2,SIGNAL(clicked()),this,SLOT(tstopfun2()));
	


	//// 自定义信号和槽，所有者是 this
	connect(this,SIGNAL(mysig(int)),this,SLOT(myslot(int)));


	  le1->setAlignment(Qt::AlignRight);
	 // le1->setMaxLength(4) ;
	  le2->setEchoMode(2);
	  leRes->setReadOnly(true);
   
}


void Qt1::myslot(int x)
{
	qDebug("myslot:%d",x);

}


//// 定时器2
void Qt1::timerEvent(QTimerEvent *t1)
{
	 value++;

	 if (t1->timerId() == timerid)
	 {
	
		QString t;

		QDateTime dt = QDateTime::currentDateTime ();

		t = dt.toString("yyyy-MM-dd hh:mm:ss AP");
		
		lbtime->setText(t);

	
	 }
	 

	 if (t1->timerId() == timerid2)
		{
		    emit mysig(value); // 用户自己发射信号，这个信号将触发对应的槽
		    qDebug("%d",value);

			
		}
}

void Qt1::tstartfun2()
{
	timerid = startTimer(1000);
	timerid2 = startTimer(3000);
	value = 0;
}
void Qt1::tstopfun2()
{
	killTimer(timerid);
	killTimer(timerid2);
}



//// 定时器1

void Qt1::tstartfun()
{
	timer->start(1000);

	value = 0;
}
void Qt1::tstopfun()
{
	timer->stop();
}
void Qt1::timeoutfun()
{

    value++;
	
	QString t;

	QDateTime dt = QDateTime::currentDateTime ();

	t = dt.toString("yyyy-MM-dd hh:mm:ss AP");
	
	lbtime->setText(t);

	if (value % 3 == 0)
		{
		    qDebug("%d",value);
		}


	
}



void Qt1::filefun()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "/home",
                                                 tr("Images (*.png *.xpm *.jpg)"));


    le1->setText(fileName);
}



void Qt1::te1fun()
{
	te1->setTextColor(c); 

}

void Qt1::colorfun()
{
	c = QColorDialog::getColor ( Qt::red, this );

	qDebug("%d",c.red());
	
}

void Qt1::fontfun()
{

	bool ok;
 	QFont font = QFontDialog::getFont(
                 &ok, QFont("Helvetica [Cronyx]", 10), this);
 	if (ok) 
 	{
    	pbfont->setFont(font);
 	} 
}



void Qt1::inputfun()
{

#if 0
	bool ok;
	QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
										 tr("User name:"), QLineEdit::Normal,
										 "dfdfdf", &ok);
	if (ok && !text.isEmpty())
		le1->setText(text);
#endif

#if 0
      bool ok;
     int i = QInputDialog::getInteger(this, tr("QInputDialog::getInteger()"),
                                      tr("Percentage:"), 25, 0, 100, 1, &ok);
	 int j = 20;
     if (ok)
         le1->setText(tr("%1%+++%2").arg(i).arg(j));

#endif
	 QStringList items;
     items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

     bool ok;
     QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                          tr("Season:"), items, 1, false, &ok);
     if (ok && !item.isEmpty())
         le1->setText(item);

}



void Qt1::closefun()
{
		int ret = QMessageBox::question(this, tr("Quit?"),
                   tr("Do you want to Quit?\n"
                      "XXXXXXXXXXXXXXXXXXX"),
                   QMessageBox::Yes | QMessageBox::No,
                   QMessageBox::No);

	if (ret == QMessageBox::Yes)
	{
	   close();
	}
}




////////// 网络2

void Qt1::netfun2()
{

   QString hostIP = SERVER_IP_ADDR;
   newSocket = new QTcpSocket();
   newSocket->connectToHost(QHostAddress(hostIP),(quint16)SERVER_PORT);
   connect(newSocket,SIGNAL(readyRead()),this,SLOT(recvfun()));
   
   while(1)
   {
	   if(newSocket->isValid())
	   {
		   
		   newSocket->write("helloworld",10);

		   break;
	   }
   	}
}

void Qt1::recvfun()
{
	char buf[20]={0};
	newSocket->read(buf,10);

	qDebug("%s",buf);
}

////////// 网络1
void Qt1::netfun()
{
	int socketfd,ret;
	struct	sockaddr_in	dest_addr;
	char *pBuf="helloworld";
	char pBuf2[20]={0};
	
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd == -1)
	{
		printf("TCP_client:socket create fialed.\r\n");
		return -1;
	}
	
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDR);
	
	dest_addr.sin_port = htons(SERVER_PORT);
	bzero(&(dest_addr.sin_zero), 8);

	ret = ::connect(socketfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
	if (ret < 0)
	{
		printf("TCP_client:connect failed.\r\n");
		return -1;
	}
		
	//while (1)
	{		
			ret = ::send(socketfd, pBuf, strlen(pBuf), 0);
			printf("TCP_client:send %s.\r\n",pBuf);
			sleep(1);
			memset(pBuf2,0,sizeof(pBuf2));
			ret = ::recv(socketfd, pBuf2, sizeof(pBuf2), 0);
			if (ret>0)
			{
					pBuf2[ret]=0;
					printf("TCP_client:recv %s.\r\n",pBuf2);
			}
			
	}
}




//////  jin程方法1

void Qt1::prstart()
{
	int ret = fork();
	if(ret == 0)
	{
		execl("/usr/bin/gedit","gedit",NULL);
	}
	else if(ret > 0)
	{
		pid = ret;
	}
	
}

void Qt1::prstop()
{
	//system("killall gedit");

    kill(pid,SIGKILL);
}

//////  jin程方法2

void Qt1::prstart2()
{
	QString p = "gedit";

	pr = new QProcess;

	pr->start(p);
	
}

void Qt1::prstop2()
{
	pr->terminate();
}



//////  线程方法1

void thread1(void *arg)
{
	Qt1 *p = (Qt1 *)arg;
	while(1)
	{
		
		p->value++;
		qDebug("%d",p->value);
		

	    p->leRes->setText(QString::number(p->value));

		sleep(1);

	}
}


void Qt1::thstart()
{
	pthread_create(&id,NULL,(void *) thread1,this);
	value = 100;
}
void Qt1::thstop()
{
	pthread_cancel(id);
}

//////  线程方法1 结束



//////  线程方法2

void Qt1::thstart2()
{
	pt = new MyThread(this);

	connect(pt,SIGNAL(threadsig(int)),this,SLOT(mainwinslot(int)));
	qDebug("123");
	pt->start();
	
	
}
void Qt1::thstop2()
{
	pt->terminate();
	delete pt;
}

void Qt1::mainwinslot(int x)
{
	qDebug("unnnnn\n");

	leRes->setText(QString::number(x));

}


//////  线程方法2 结束

#if 0
void Qt1::paintEvent(QPaintEvent *)
{
	 leRes->setText(QString::number(value));
}
#endif

void Qt1::fun()
{
	qDebug("funnnnn\n");
    QString a,b;

	a = le1->text();
	b = le2->text();

	double c = a.toDouble() + b.toDouble();
	qDebug("c=%lf\n",c);

	//char buf[100];
	//sprintf(buf,"%lf",c);

	leRes->setText(QString::number(c));

	
}

void Qt1::fun2()
{
	qDebug("fun22\n");
	 QString a,b;

	a = le1->text();
	b = le2->text();

	leRes->setText(a+b);
	
}


Qt1::~Qt1()
{
 
}



