#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int lock_var=1;
time_t end_time;

void pthread1(void *arg);
void pthread2(void *arg);

int main(int argc, char *argv[])
{
	pthread_t id1,id2;
	pthread_t mon_th_id;
	int ret;
	end_time = time(NULL)+10;

	pthread_mutex_init(&mutex,NULL);
	
	ret=pthread_create(&id1,NULL,(void *)pthread1, NULL);
	if(ret!=0)
		perror("pthread cread1");

	ret=pthread_create(&id2,NULL,(void *)pthread2, NULL);
	if(ret!=0)
		perror("pthread cread2");
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	exit(0);
}

void pthread1(void *arg)
{
	int i;
	while(time(NULL) < end_time)
	{
		if(pthread_mutex_lock(&mutex)!=0)
		{
			perror("pthread_mutex_lock");
		}
		 else
		 {
			printf("pthread1:pthread1 lock the variable\n");
		 }
		 
		 for(i=0;i<1;i++)
		 {
			sleep(1);
			lock_var+=2;
		 }
		 
		if(pthread_mutex_unlock(&mutex)!=0)
		{
			perror("pthread_mutex_unlock");
		}
		else
		{
			printf("pthread1:pthread1 unlock the variable\n");
		}
		
	sleep(1);
	}
}

void pthread2(void *arg)
{
	int nolock=0;
	int ret;
	while(time(NULL) < end_time)
	{	
		ret=pthread_mutex_trylock(&mutex);
		if(ret==EBUSY)	
		{
			printf("pthread2:the variable is locked by pthread1\n");
		}
		else
		{
			if(ret!=0)
			{
				perror("pthread-mutex_trylock");
				exit(1);
			}
			else
			{
				printf("pthread2 got lock.the variable is %d\n",lock_var);
			}
			if(pthread_mutex_unlock(&mutex)!=0)
			{
				perror("pthread_mutex_unlock");
			}
			else
			{
				printf("pthread2:pthread2 unlock the variable\n");
			}
		}
		sleep(2);
	}
}