#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void fun(int sig)
{
	if (sig == SIGALRM)
	{
		printf("SIGALARM !!!\n");
	}
	else if(sig == SIGINT)
	{
		printf("Ctrl + c  pressed !!!\n");
	}
}

int main()
{
	alarm(3);  // SIGALARM

	signal(SIGALRM,fun);

	signal(SIGINT,fun);

	printf("AAAAA\n");

	pause();

	printf("BBBBBB\n");

	pause();

	printf("CCCCCC\n");
}



