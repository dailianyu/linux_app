// name�� delete.c
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
        printf("zErrMsg = %s \n", zErrMsg);
    #endif
	
	//��������	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 1 , 1 , '200605011206', 18.9 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 23 , 45 , '200605011306', 16.4 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 34 , 45 , '200605011306', 15.4 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
		
	int nrow = 0, ncolumn = 0;
	char **azResult; //��ά�����Ž��

	//��ѯ����
	sql = "SELECT * FROM SensorData ";
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	int i = 0 ;
	printf( "row:%d column=%d \n" , nrow , ncolumn );
	printf( "\nThe result of querying is : \n" );
	for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		printf( "azResult[%d] = %s\n", i , azResult[i] );
	//�ͷŵ�	 azResult ���ڴ�ռ�
	sqlite3_free_table( azResult );

	//ɾ������
	sql = "DELETE FROM SensorData WHERE SensorID = 1 ;" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	#ifdef _DEBUG_
        printf("zErrMsg = %s \n", zErrMsg);
    #endif
	sql = "SELECT * FROM SensorData ";
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	printf( "\n\n\n\nrow:%d column=%d " , nrow , ncolumn );
	printf( "\nAfter deleting , the result of querying is : \n" );
	for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		printf( "azResult[%d] = %s\n", i , azResult[i] );
	//�ͷŵ�	 azResult ���ڴ�ռ�
		sqlite3_free_table( azResult );


	printf( "\nSATRT UPDATE  \n" );
	//��������
		sql = "UPDATE SensorData SET  SensorParameter = 100.0,SiteNum = 90 WHERE SensorID = 23 ;" ;
		sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	#ifdef _DEBUG_
			printf("zErrMsg = %s \n", zErrMsg);
    #endif
		sql = "SELECT * FROM SensorData ";
		sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
		printf( "\n\n\n\nrow:%d column=%d " , nrow , ncolumn );
		printf( "\nAfter UPDATE , the result of querying is : \n" );
		for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
			printf( "azResult[%d] = %s\n", i , azResult[i] );


	//�ͷŵ�	 azResult ���ڴ�ռ�
	sqlite3_free_table( azResult );
		
	#ifdef _DEBUG_
        printf("zErrMsg = %s \n", zErrMsg);
    #endif

	sqlite3_close(db); //�ر����ݿ�
	return 0;
	
}
