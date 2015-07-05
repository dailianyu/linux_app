// name�� insert.c
// This prog is used to test C/C++ API for sqlite3 .It is very simple,ha !
// Author : zieckey
// data : 2006/11/18

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h" 
//#define _DEBUG_

int main( void )
{
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	
	rc = sqlite3_open("zieckey.db", &db); //��ָ�������ݿ��ļ�,��������ڽ�����һ��ͬ�������ݿ��ļ�
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else printf("You have opened a sqlite3 database named zieckey.db successfully!\nCongratulations! Have fun !  ^-^ \n");
	

	//����һ����,����ñ���ڣ��򲻴�������������ʾ��Ϣ���洢�� zErrMsg ��
	char *sql = "	CREATE TABLE SensorData(\
				 	ID INTEGER PRIMARY KEY,\
					SensorID INTEGER,\
				 	SiteNum INTEGER,\
				 	Time VARCHAR(12),\
				 	SensorParameter REAL\
				 	);" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

	#ifdef _DEBUG_
        printf("%s\n",zErrMsg);
    #endif
	
	//��������	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 1 , 1 , '200605011206', 18.9 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
	sql = "INSERT INTO SensorData VALUES(NULL , 1 , 1 , '200605011306', 16.4 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );

	int sid,sit;
	char t[12];
	char sql2[500]={0};
	
	scanf("%d%d%s",&sid,&sit,t);

	sprintf(sql2,"INSERT INTO SensorData VALUES(NULL , %d , %d , '%s', 12.8 );",sid,sit,t);
	printf("%s\n",sql2);
	sqlite3_exec( db , sql2 , 0 , 0 , &zErrMsg );
	
	sqlite3_close(db); //�ر����ݿ�
	return 0;
	
}
