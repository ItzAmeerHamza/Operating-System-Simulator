#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#include<unistd.h>
using namespace std;

int main () {
cout<<"\t\t\tWELCOME TO THE NOTEPAD "<<endl;
string read;
getline(cin,read);
cout<<"\n\n you want to save enter 1 else 0 : ";
int choice=0;
cin>>choice;
if(choice==1)
{
string filename;
cout<<"enter your filename : ";
cin>>filename;
  ofstream myfile(filename);
  if (myfile.is_open())
  {
    myfile<<read;
    myfile.close();
    sleep(3);
  }
  
  else 
  {
  cout << "Unable to open file";
  }
  }
  else 
  {
  return 0;
  }
}
