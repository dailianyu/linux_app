#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#define MAXSIZE 80
#define MYPORT  5000
#define MYIP  "192.168.1.235"
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
    	char *buf="HelloWorld!";
		int buflen;		
		char recive[BUFSIZE];
		
		sockfd=socket(AF_INET,SOCK_DGRAM,0);
    	if(sockfd<0)
		{
         	printf("error in socket");
         	exit(1);
     	}

		udp_addr.sin_family=AF_INET;
     	udp_addr.sin_port=htons(MYPORT);
     	udp_addr.sin_addr.s_addr=inet_addr(MYIP);
		buflen=strlen(buf);
		
		while(1)
		{
			ret = sendto(sockfd,buf,buflen,0,(struct sockaddr *)&udp_addr,sizeof(udp_addr));
			if(ret<0)
			{
				printf("error recive\n");
				exit(1);
			}
			printf("UDP client sent:%s\n",buf);
			sleep(1);

			ret = recvfrom(sockfd,recive,BUFSIZE,0,(struct sockaddr *)&their_addr,&their_addr_len);
			if(ret<0)
			{
				printf("error recive\n");
				exit(1);
			}
			recive[ret]='\0';

			printf("UDP client recive:%s\n",recive);
			
		}
		
		return 0;
}
