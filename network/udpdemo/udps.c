#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#define MAXSIZE 80
#define MYPORT  5000
#define MYIP  "192.168.1.254"
//#define BACKLOG 10
#define BUFSIZE 100

int main(int argc, char *argv[])
{
	   	int sockfd;
		int	new_fd,numbytes,ret;
    	struct sockaddr_in udp_addr;
    	struct sockaddr_in their_addr;
		int their_addr_len=sizeof(their_addr);
    	int sin_size,con_fd,pid;
    	char buf[BUFSIZE];
		char send[BUFSIZE];
		int i;
		
		sockfd=socket(AF_INET,SOCK_DGRAM,0);
		
    	if(sockfd<0)
		{
         	printf("error in socket");
         	exit(1);
     	}

		udp_addr.sin_family=AF_INET;
     	udp_addr.sin_port=htons(MYPORT);
     	udp_addr.sin_addr.s_addr=htonl(INADDR_ANY);

     	ret=bind(sockfd,(struct sockaddr *)&udp_addr,sizeof(udp_addr));
     	if(ret<0)
		{
          printf("error in binding\n");
          exit(1);
	    }
		
		while(1)
		{  // 
			ret = recvfrom(sockfd,buf,BUFSIZE,0,(struct sockaddr *)&their_addr,&their_addr_len);
			if(ret<0)
			{
				printf("error recive\n");
				exit(1);
			}
			buf[ret]='\0';
			printf("UDP server recive:%s\n",buf);

			for (i=0;i<ret;i++)
				send[i]=buf[ret-1-i];
			send[ret]='\0';
			sendto(sockfd,send,ret,0,(struct sockaddr *)&their_addr,sizeof(their_addr));
			printf("UDP server sent: %s\n",send);
		    sleep(1);

		}
		
		return 0;
}
