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


#define SERVER_IP_ADDR  "192.168.1.235"
#define SERVER_PORT  	8000



MyThread::MyThread(void *arg)
{
	qDebug("MyThread created");
	p = (Qt1 *)arg;
}


void MyThread::run()
{
	qDebug("MyThread run");
	while(1)
	{
		
		p->value++;
		qDebug("%d",p->value);

		p->update(); // 此处引起paintevent
		
		QThread::sleep(1);

	}
}



Qt1::Qt1(QWidget *parent):QDialog(parent)
{
  setupUi(this);
  connect(pbOK,SIGNAL(clicked()),this,SLOT(fun()));
  connect(pbExit,SIGNAL(clicked()),this,SLOT(close()));

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


  le1->setAlignment(Qt::AlignRight);
  le1->setMaxLength(4) ;
  le2->setEchoMode(2);
  leRes->setReadOnly(true);
   
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
	qDebug("123");
	pt->start();
	
	
}
void Qt1::thstop2()
{
	pt->terminate();
	delete pt;
}

//////  线程方法2 结束


void Qt1::paintEvent(QPaintEvent *)
{
	 leRes->setText(QString::number(value));
}


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



