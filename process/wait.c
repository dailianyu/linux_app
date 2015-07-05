#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
		printf("child process,my pid:%d,my parent pid:%d.\n",getpid(),getppid());// 1

        sleep(1);

		printf("22child process,my pid:%d,my parent pid:%d.\n",getpid(),getppid()); // 3

		return 10;
	}
	else
	{
		// fu

		int s,pid;
		printf("father process,my pid:%d,my child pid:%d.\n",getpid(),ret);  // 2
   
		//pid = wait(&s);
		pid = waitpid(-1,&s,WNOHANG);  

		// ×èÈûÓë·Ç×èÈû

	    printf("father process,pid:%d,s:%d.\n",pid,WEXITSTATUS(s));  // 5
         }

	printf("AAAAAAAAAAA\n");// 4 6
}


