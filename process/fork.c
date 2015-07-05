#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t ret;

	ret = fork();

	if(ret < 0)
	{
		printf("fail!\n");
		return -1;
	}
	else if(ret == 0)
	{
		// zi
		printf("child process,my pid:%d,my parent pid:%d.\n",getpid(),getppid());

		//execl("/bin/ls","ls","/",NULL);
		chmod("./zuhe",0755);
		if (execl("./zuhe","zuhe",NULL) < 0)
		{
			execl("./zuhe","zuhe",NULL);
		}

		printf("22child process,my pid:%d,my parent pid:%d.\n",getpid(),getppid());
	}
	else
	{
		// fu
		printf("father process,my pid:%d,my child pid:%d.\n",getpid(),ret);
	}

	printf("AAAAAAAAAAA\n");
}


