#include<iostream>
#include<time.h>
#include<unistd.h>
#include <cstdio>
#include <ctime>
using namespace std;
int main()
{

std::system("clear");
 int HH=0,MM=0,SS=0;
 cout<<"\n\n\\t\t stopwatch";
 cout<<"\n\t\t HH : MM : SS";
 cout<<"\n\t\t"<<HH<<"\t"<<MM<<"\t"<<SS;
 cout<<"\n\t\t press a key to start";
 string key;
 cin>>key;
 while(key=="a")
 {
  SS++;
 
  if(SS>59)
  {
   MM++;
   SS=0;
  }
  if(MM>59)
  { 
    HH++;
    MM=0;
  }
 std::system("clear");
  cout<<"\n\t\t stopwatch";
  cout<<"\n\t\t HH : MM : SS";
  cout<<"\n\t\t"<<HH<<" : "<<MM<<" : "<<SS;
  
 }
 cout<<"\n\t\t the time after pausing is";
 cout<<"\n\t\t"<<HH<<" : "<<MM<<" : "<<SS;
}
