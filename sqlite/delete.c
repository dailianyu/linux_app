// name： delete.c
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
	
	rc = sqlite3_open("zieckey.db", &db); //打开指定的数据库文件,如果不存在将创建一个同名的数据库文件
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else printf("You have opened a sqlite3 database named zieckey.db successfully!\nCongratulations! Have fun !  ^-^ \n");
	

	//创建一个表,如果该表存在，则不创建，并给出提示信息，存储在 zErrMsg 中
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
	
	//插入数据	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 1 , 1 , '200605011206', 18.9 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 23 , 45 , '200605011306', 16.4 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 34 , 45 , '200605011306', 15.4 );" ;
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );
	
		
	int nrow = 0, ncolumn = 0;
	char **azResult; //二维数组存放结果

	//查询数据
	sql = "SELECT * FROM SensorData ";
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	int i = 0 ;
	printf( "row:%d column=%d \n" , nrow , ncolumn );
	printf( "\nThe result of querying is : \n" );
	for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
		printf( "azResult[%d] = %s\n", i , azResult[i] );
	//释放掉	 azResult 的内存空间
	sqlite3_free_table( azResult );

	//删除数据
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
	//释放掉	 azResult 的内存空间
		sqlite3_free_table( azResult );


	printf( "\nSATRT UPDATE  \n" );
	//更新数据
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


	//释放掉	 azResult 的内存空间
	sqlite3_free_table( azResult );
		
	#ifdef _DEBUG_
        printf("zErrMsg = %s \n", zErrMsg);
    #endif

	sqlite3_close(db); //关闭数据库
	return 0;
	
}
