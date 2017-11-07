//Basically this program has three parts 
//1.checkconnection 
//2.checkqueryexecution 
//3.and if proper connection then print diskwrites


#include<stdio.h>
#include<string.h>
#include<mysql.h>
//this function is used to check the connection status
void checkconnectionstatus(MYSQL *connection,char *servername,char *username, char * password,char *database)
//this function is used to check if query write is possible with C++
void checkqueryexecution(MYSQL *connection){
//this section checks for a diskwrite
void printdisk_writes(MYSQL *connection,MYSQL_RES *result)



int main(int argc,char *argv[])
{        

    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW *row;


    //Initialize username
    char *servername = "localhost";
    char *username = "leobjacob";
    char *password = "WELCOME123";
    char *database = "employeedatabase";

    //to create an object to initialize a connection with MYSQL
    connection = mysql_init(NULL);
    //mysql_real_connect if 0 means connection to MYSQL has failed
    checkconnectionstatus(connection,servername,username,password,database);
        
    checkqueryexecution(connection);
    //Fetching result    
    result = mysql_use_result(connection);
    //this line will iterate over the result row    
    while((row = mysql_fetch_row(result)) != NULL)
                {
                    if((strcmp(row[0], "InnoDB") == 0) && strcmp(row[1], "YES") == 0)
                            Inno_flag=1;
                        
                }
        
    //Inno flag tells us if innodb plugin is installed    
    if(!Inno_flag)
        printf("InnoDB plug-in is not installed\n");
    else
        printf("InnoDB plug-in is installed\n");
    //Freeing the buffer 
    mysql_free_result(result); 
    //if connection is established and query execution works properly.//since connection is established and diskwrites are possible                
    if(!checkqueryexecution(connection))
        {
             printdisk_writes(connection,result);                
        }
  
    mysql_free_result(result);
    mysql_close(connection);    
    return 0;

}



void checkconnectionstatus(MYSQL *connection,char *servername,char *username, char * password,char *database)
{
    if (!mysql_real_connect(connection,servername,username,password,database,0,NULL,0))
    {
        
            printf("\nConnection error");
    }

}
//this function is used to check if query write is possible with C++
void checkqueryexecution(MYSQL *connection){
    if(mysql_query(connection,"show engines"))
    {
        
            printf("\nQuery execution failed:");
        
    }
}
void printdisk_writes(MYSQL *connection,MYSQL_RES *result)
{
    result = mysql_use_result(connection);//fetching result 
    while((row = mysql_fetch_row(result)) != NULL)//Iterating result row
                {
                     if(strcmp(row[0], "Handler_write") == 0)
                     printf("\nTotal number of Disk = %d", row[1]);
                 }
}

     