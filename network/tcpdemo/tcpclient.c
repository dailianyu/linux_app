#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 					
#include <fcntl.h>
#include <arpa/inet.h>		

#define SERVER_IP_ADDR  "192.168.1.84"
#define SERVER_PORT  	8000

int main()
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

	ret = connect(socketfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
	if (ret < 0)
	{
		printf("TCP_client:connect failed.\r\n");
		return -1;
	}
		
	while (1)
	{		
		ret = send(socketfd, pBuf, strlen(pBuf), 0);
		printf("TCP_client:send %s.\r\n",pBuf);
		sleep(1);
		memset(pBuf2,0,sizeof(pBuf2));
		ret = recv(socketfd, pBuf2, sizeof(pBuf2), 0);
		if (ret>0)
		{
			pBuf2[ret]=0;
			printf("TCP_client:recv %s.\r\n",pBuf2);
		}
			
	}

	return 0;
}
