
/*shmadd.c*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSZ 2048

int main()
{
	int shmid;
	char *shmadd;

	key_t key;

	/*根据不同的路径和关键表示产生标准的key*/
	if ((key = ftok(".", 'a')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	
	/* 创建共享内存 */
	if ((shmid = shmget(key, BUFSZ, IPC_CREAT|0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}
	else
	{
		printf("Create shared-memory: %d\n",shmid);
	}
	
	/* 显示共享内存情况 */
	system("ipcs -m");
	
	/*映射共享内存*/
	if ((shmadd = shmat(shmid, 0, 0)) < (char *)0)
	{
		perror("shmat");
		exit(1);
	}
	else
	{
		printf("Attach shared-memory\n");
	}
	
	system("ipcs -m");
	
	/* 解除共享内存映射 */
	if ((shmdt(shmadd)) < 0)
	{
		perror("shmdt");
		exit(1);
	}
	else
	{
		printf("Deattach shared-memory\n");
	}
	
  	system("ipcs -m");
	
  	/* 删除共享内存 */
  	if (shmctl(shmid, IPC_RMID, NULL) == -1)
	{
		perror("shmctl(IPC_RMID)\n");
		exit(1);
	}
	else
	{
		printf("Delete shared-memory\n");
	}
	
	system("ipcs -m");
  	exit(0);
}