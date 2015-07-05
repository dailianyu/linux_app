 
/*服务器端代码*/
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#define MAXSIZE 20
#define MYPORT  8000
#define MYIP  "192.168.1.84"
#define BACKLOG 10
#define BUFSIZE 100
#define true 1
void str_ser(int);

char recvs[MAXSIZE];
char sends[MAXSIZE];

int main()
{
	int sockfd,new_fd,numbytes,ret;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int sin_size,con_fd,pid;
	char *buf;

	sin_size=sizeof(their_addr);
	
	/*创建监听套接口 */
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
     	printf("error in socket");
     	exit(1);
 	}
	 	
 	my_addr.sin_family=AF_INET;
 	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=inet_addr(MYIP);
//	my_addr.sin_addr.s_addr=htonl(INADDR_ANY);
 	bzero(&(my_addr.sin_zero),8);

	/*绑定监听套接口 */
 	ret=bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr));
 	if(ret<0)
	{
      printf("error in binding\n");
      exit(1);
	}
	
	/* 监听连接请求*/
	ret=listen (sockfd,BACKLOG);
	if(ret<0)
	{
	  printf("error in listening");
	  exit(1);
	}
	
	while(true)
	{
		con_fd=accept(sockfd,(struct sockaddr *)&their_addr,&sin_size);
		if(con_fd<0)
		{
			printf("error in accept");
			exit(1);
		}
		else
		{
			printf("TCP server and client connect successfully...\n");
			printf(" client IP:%s\n",inet_ntoa(their_addr.sin_addr));
		}
		/*创建新的连接 */
		if((pid=fork())==0)
		{
			close(sockfd);
			str_ser(con_fd);
			/*接收并处理数据 */
			close(con_fd);
			exit(0);
		}
		/*子进程代码 */
		else
			close(con_fd);
		/*父进程代码 */
	}
	close(sockfd);
	exit(0);
}

void str_ser(int sockfd)
{
	int n=0,i;	
	while(true)
	{
		memset(recvs,0,sizeof(recvs));
		if((n=recv(sockfd,recvs,MAXSIZE,0))==0)
		return ;
		else 
		{
			recvs[n]='\0';
			printf("TCP server receiced: %s\n",recvs);

			memset(sends,0,sizeof(sends));
			for (i=0;i<n;i++)
			sends[i]=recvs[n-1-i];
			sends[n]=0;
			sleep(1);
			send(sockfd,sends,n,0);
			printf("TCP server sent: %s\n",sends);    
		}
	}		      
}

