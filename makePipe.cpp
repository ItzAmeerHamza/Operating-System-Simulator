#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

using namespace std;        
int main()
{
    int res;
    res = mkfifo("fifo",0777); //creates a named pipe with the name fifo1
    if(errno != EEXIST)
    {
        perror("ERROR: Error in creating the fifo pipe");
    }
    cout<<"named pipe created\n";
    sleep(3);
}