#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(int argc, char *argv[])
{
    time_t tmNow;
    int inp;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    cout<<"Current Date: "<<t.tm_mday<<"-"<<t.tm_mon+1<<"-"<<t.tm_year+1900<<endl;
    cout<<"Press 1 to cancel"<<endl<<"Press 2 to minimize"<<endl;
    cin>>inp;
    cout<<"******************************************"<<endl;
    int fileDesc;
    char str[100];
    if ( fileDesc = open("fifo", O_WRONLY) < 0 ) { 
        perror("ERROR: Error in opening the pipe");
        exit(0);
    }
    if ( write(fileDesc, &str, sizeof(str)+1) < 0 )
    {
        perror("ERROR: Error in writing the pipe");
    }
    close(fileDesc);
    sleep(3);
    return 0;
}