#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int ret;

	ret = fork();
	if (ret < 0)
	{
	}
	else if (ret > 0)
	{
		exit(0);
	}
	else
	{
		int i;
		setsid();
		chdir("/");
		umask(0);
		for(i=3;i<1024;i++)
		{
			close(i);
		}

		while(1)
		{
			printf("AAAAA\n");
			sleep(1);
		}
		
	}
	return 0;
}

