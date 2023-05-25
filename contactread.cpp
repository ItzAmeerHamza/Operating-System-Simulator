#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#include<unistd.h>
using namespace std;

int main () {
string myText;
cout<<"\t\t\tWELCOME TO CONTACTS DIARY "<<endl;
  ifstream myfile("contacts.txt");
  if (myfile.is_open())
  {
    while (getline (myfile, myText)) {
  // Output the text from the file
  cout << myText;
  cout<<endl;
}}
  
  else 
  {
  cout << "Unable to open file";
  }

  sleep(3);
  return 0;
  
}
