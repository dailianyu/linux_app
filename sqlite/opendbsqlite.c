// name�� opendbsqlite.c
// This prog is used to test C/C++ API for sqlite3.It is very simple,ha!
// Author : zieckey
// data : 2006/11/13

#include <stdio.h>
#include <sqlite3.h>

int main( void )
{
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	
	//��ָ�������ݿ��ļ�,��������ڽ�����һ��ͬ�������ݿ��ļ�
	rc = sqlite3_open("zieckey.db", &db); 
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	else printf("You have opened a sqlite3 database named zieckey.db successfully!\nCongratulations! Have fun !  ^-^ \n");
	
	sqlite3_close(db); //�ر����ݿ�
	return 0;
}
