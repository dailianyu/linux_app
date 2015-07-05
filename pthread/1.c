#include <stdio.h>
#include <pthread.h>

void thread1(void)
{
	int i=0;
	for(i=0;i<=6;i++)
	{
		printf("This is a pthread1.\n");
		if(i==2)
		{
		   pthread_exit(0);
		}
		sleep(1);
	}
}

void thread2(void *arg) 
{
	int i=0;

//	int id = *(int *)arg;
    int id = (int)arg;

	printf("id = %d\n", id);
	
	for(i=0;i<=3;i++)
	{
		printf("This is a pthread2.\n");
	}

	pthread_cancel(id);
	pthread_exit(0);
}

int main(void)
{
	pthread_t id1,id2;
	int i,ret;
	
	printf("create thread start.\n");
#if 1
	ret=pthread_create(&id1,NULL,(void *) thread1,NULL);
//	ret+=pthread_create(&id2,NULL,(void *) thread2,(int *)&id1);
	ret+=pthread_create(&id2,NULL,(void *) thread2,(int)id1);
	printf("id1 = %d\n",id1);
	if(ret!=0)
	{
		printf("Create pthread error!\n");
		exit(1);
	}
#endif
#if 0
	ret=pthread_create(&id2,NULL,(void *) thread2,NULL);
	ret+=pthread_create(&id1,NULL,(void *) thread1,NULL);
	if(ret!=0)
	{
		printf("Create pthread error!\n");
		exit(1);
	}
#endif
	pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    printf("main will return.\n");
    return 0;
}

