#include<iostream>
#include<unistd.h>
#include <stdlib.h> // for opening a new terminal window
#include<errno.h> // for perrors
#include <cstdlib>
#include<curses.h>
#include <semaphore.h>
#include <stdio.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;
// the criticle section
float ramValue, hardValue, coreValue;
float hardDrive;
float cores;
int fcfs[15]; // the process waiting queue
int fccount = 0;
int processes[15]; // the 15 tasks
string tasks[15] = { "Clock", "Date", "Calculator", "notepad", "File Copy", "File Delete", "File Move", "My Contacts",
 "Games"};
int processesRam[15] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
////////////////////////////////////////
int status;
int waitingQueue[15];
pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;
void *menuPannel( void *arg )
{
    pthread_mutex_lock(&lock);
    ramValue -= 0.5;
    cout<<"***************************** Welcome *****************************"<<endl;
    cout<<"Press 1 to start to see the clock "<<endl
    <<"Press 2 see the date "<<endl
    <<"Press 3 to see the calender"<<endl
    <<"Press 4 to open a note pad"<<endl
    <<"Press 5 to copy a txt file"<<endl
    <<"Press 6 to delete a txt file"<<endl
    <<"Press 7 to move a file from one directory to another directoy"<<endl
    <<"Press 8 to see my contacts"<<endl
    <<"Press 9 to start the stop watch"<<endl
    <<"Press 10 to see the calender"<<endl
    <<"************* Game Section *************"<<endl
    <<"Press 11 to play number guess game"<<endl
    <<"Press 12 to Play catch game in bash"<<endl
    <<"Press 13 to Play Tic Tac Toe"<<endl
    <<"Press 14 to Play Music"<<endl
    <<"Press 15 to Play catch game in bash"<<endl;
    cout<<"*****************************************************************"<<endl;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);

}
void ShowRam()
{
    if(ramValue > 0)
    {
        cout<< "*********  Available Ram : "<<ramValue<<"  *********"<<endl;
    }
}
int main(int argc, char** argv)
{
    while (1)
    {
        system("clear");
        system("g++ makePipe.cpp -o fifo");
     system("./fifo");
    ramValue = atoi(argv[1])*1000;
    hardValue = atoi(argv[2])*1000;
    coreValue = atoi(argv[3]);
    int inp;
    pid_t child_pid, wpid;
    if( ramValue <=0 || hardValue <= 0 || coreValue <= 0 )
    {
        cout<<"Invalid Specifications Aborting....."<<endl;
        exit(0);
    }
    // the splash of the os
    int status = system("./splash.sh");

    pthread_t threadHandlers[15];
    pthread_create(&threadHandlers[0], NULL, menuPannel, NULL);
    cout<<endl<<"You are using ram value of : "<<ramValue <<" Mbs "<<endl<<"The Hard Drive Of : "<<hardValue<<" Mbs "<<endl<<"And Total Number Of "<<coreValue<<" Cores"<<endl;
    pthread_join(threadHandlers[0], NULL);
    cout<<"Enter the input to start the program"<<endl;
    cin>>inp;
    pid_t pid;
    printf("before fork\n");
    pid=fork();
    if(pid==0)
    {
         if( inp == 1 ) // the user have opted to open the clock
         {
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ clock.cpp -o clock");
            system("gnome-terminal --  \"./clock\"");
            char const *cmd = "./clock";
            char const *args[]={ "./clock" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);
         }
         else if(inp == 2)
         {
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ date.cpp -o date");
            system("gnome-terminal --  \"./date\"");
            char const *cmd = "./date";
            char const *args[]={ "./date" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 3)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ calculator.cpp -o calculator");
            system("gnome-terminal --  \"./calculator\"");
            char const *cmd = "./calculator";
            char const *args[]={ "./calculator" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 4)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ notepad.cpp -o notepad");
            system("gnome-terminal --  \"./notepad\"");
            char const *cmd = "./notepad";
            char const *args[]={ "./notepad" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 5)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ copyFile.cpp -o copyfile");
            system("gnome-terminal --  \"./copyfile\"");
            char const *cmd = "./copyfile";
            char const *args[]={ "./copyfile" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 6)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ deleteFile.cpp -o deletefile");
            system("gnome-terminal --  \"./deletefile\"");
            char const *cmd = "./deletefile";
            char const *args[]={ "./deletefile" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 7)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
           else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ moveFile.cpp -o movefile");
            system("gnome-terminal --  \"./movefile\"");
            char const *cmd = "./movefile";
            char const *args[]={ "./movefile" , NULL };
            execvp(args[0], argv); //replacing childs image
            ramValue += processesRam[inp - 1];
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 8)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ contactread.cpp -o contactread");
            system("gnome-terminal --  \"./contactread\"");
            char const *cmd = "./contactread";
            char const *args[]={ "./contactread" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 9)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ stopwatch.cpp -o stopwatch");
            system("gnome-terminal --  \"./stopwatch\"");
            char const *cmd = "./stopwatch";
            char const *args[]={ "./stopwatch" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 10)
         {
             pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ calender.cpp -o calender");
            system("gnome-terminal --  \"./calender\"");
            char const *cmd = "./calender";
            char const *args[]={ "./calender" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 11)
         {
             cout<<"********* Welcome to the game section *********"<<endl;
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ numberGuessGame.cpp -o numberguess");
            system("gnome-terminal --  \"./numberguess\"");
            char const *cmd = "./numberguess";
            char const *args[]={ "./numberguess" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 12)
         {
             cout<<"********* Welcome to the game section *********"<<endl;
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("gnome-terminal --  \"./menu.sh\"");

         }
         else if(inp == 13)
         {
             cout<<"********* Welcome to the game section *********"<<endl;
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ zombiekilled.cpp -o zombiekilled");
            system("gnome-terminal --  \"./zombiekilled\"");
            char const *cmd = "./zombiekilled";
            char const *args[]={ "./zombiekilled" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 14)
         {
             cout<<"********* Welcome to the game section *********"<<endl;
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("g++ ticTacToe.cpp -o tictactoe");
            system("gnome-terminal --  \"./tictactoe\"");
            char const *cmd = "./tictactoe";
            char const *args[]={ "./tictactoe" , NULL };
            execvp(args[0], argv); //replacing childs image
            perror("ERROR: Something wents wrong in replacing the child image of process");
            _exit(EXIT_FAILURE);

         }
         else if(inp == 15)
         {
             cout<<"*************** Enjoy the music ***************"<<endl;
            pthread_mutex_lock(&lock);
            if((ramValue > 0) && (ramValue > processesRam[inp -1]))
            {
                ramValue -= processesRam[inp - 1];
            }
            else
            {
                fcfs[fccount] = inp -1;
                fccount++;
            }
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
        
            system("gnome-terminal");
            system("canberra-gtk-play -f audio.ogg");

         }
    }
    else{

        wait(NULL);
        if(inp == 1)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 2)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 3)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 4)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 5)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 6)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 7)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 8)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 9)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 10)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 11)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 12)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 13)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 14)
        {
            ramValue += processesRam[inp - 1];
        }
        else if(inp == 15)
        {
            ramValue += processesRam[inp - 1];
        }

    //     int res,n=100;
    //     char str[100];
    //     cout<<"Opened the file"<<endl; 
    //     res=open("fifo",O_RDONLY);
    //     if (res < 0 )
    //     {
    //         perror("ERROR: Error in opening the file");
    //         exit(0);
    //     }
    //     cout<<"Reading";



    //     read(res,&str,sizeof(str));
        
        
    //     if(n < 0)
    //     {
    //         perror("ERROR: Error in opening the pipe");
    //         exit(0);
    //     }
    //     cout<<endl<<"Read Data : "<<str[0]<<endl;
    //     int readData= int((str[0]));
    //    // readData = *(str[0]) - '0';
    //     ramValue += readData;

         printf("My child's id is %d\n",pid);
         printf("I am parent having id %d\n",getpid());
    }
        /* code */
    }
    
    
    return 0;
}