#include <iostream>
#include<math.h>
#include<unistd.h>
#include <curses.h>
using namespace std;  
// Main program
int main(void)
{
    int opChoice; // the choice of option
    float numArray[30]; // the maximum numbers
    char inp;
    int count = 0;
    int arrSize = sizeof(numArray)/sizeof(numArray[0]); // the size of the array
    float sum = 0, diff, mul, div, power;
    do
    {
        cout<<"Press 1 for Addition"<<endl
    <<"Press 2 for Subtraction"<<endl
    <<"Press 3 for Multiplication"<<endl
    <<"Press 4 for Division"<<endl
    <<"Press 5 for Power"<<endl
    <<"Press 6 for clear"<<endl
    <<"Press 7 for reset"<<endl;
    cin >> opChoice;
    switch (opChoice) {
          
        // If user enter + 
        case 1:
            while (true)
            {
                /* code */
                cout<<"Enter the number to add (press = to exit)"<<endl;
                cin>>inp;
                while ((inp != '=') && (count < arrSize) ) {
                    numArray[count] = inp - '0';
                    cout<<"Value : "<<numArray[count]<<endl;;
                    count++;
                    cin>>inp;             
                }
                for (size_t i = 0; i < count; i++)
                {
                    /* code */
                    sum += numArray[i];
                }
                system("cls");
                cout<<"*****************************"<<endl;
                cout<<"The sum of entered numbers : "<<endl;
                for (size_t i = 0; i < count; i++)
                {
                    /* code */
                    cout<<numArray[i];
                    if(i != count -1)
                    {
                        cout<<"+";
                    }
                }
                cout<<" = "<<sum<<endl;
                cout<<"*****************************"<<endl;
                cout<<endl<<endl;
                cout<<"Press '0' to exit"<<endl<<"press '1' to continue"<<endl<<"press '2' to reset"<<endl;;
                cin>>inp;

                if(inp == '0')
                {
                    cout<<"Escape has been pressed"<<endl;
                    break;

                }
                else if(inp == '1')
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }
                else if(inp == '2')
                {
                    // reset all the vaiables
                    sum=0;
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }

            }
            

            ;
            break;
          
        // If user enter - 
        case '2':
            //cout << num1 - num2;
            while (true)
            {
                /* code */
                cout<<"Enter the number to add (press = to exit)"<<endl;
                cin>>inp;
                while ((inp != '=') && (count < arrSize) ) {
                    numArray[count] = inp - '0';
                    cout<<"Value : "<<numArray[count]<<endl;;
                    count++;
                    cin>>inp;             
                }
                diff = numArray[0];
                for (size_t i = 1; i < count; i++)
                {
                    /* code */
                    diff -= numArray[i];
                }
                system("cls");
                cout<<"*****************************"<<endl;
                cout<<"The diffrence of entered numbers : "<<endl;
                for (size_t i = 0; i < count; i++)
                {
                    /* code */
                    cout<<numArray[i];
                    if(i != count -1)
                    {
                        cout<<"-";
                    }
                }
                cout<<" = "<<diff<<endl;
                cout<<"*****************************"<<endl;
                cout<<endl<<endl;
                cout<<"Press '0' to exit"<<endl<<"press '1' to continue"<<endl<<"press '2' to reset"<<endl;;
                cin>>inp;

                if(inp == '0')
                {
                    cout<<"Escape has been pressed"<<endl;
                    break;

                }
                else if(inp == '1')
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }
                else if(inp == '2')
                {
                    // reset all the vaiables
                    diff=0;
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }

            }




            break;
          
        // If user enter *
        case '3':
            //cout << num1 * num2;
            while (true)
            {
                /* code */
                cout<<"Enter the number to add (press = to exit)"<<endl;
                cin>>inp;
                while ((inp != '=') && (count < arrSize) ) {
                    numArray[count] = inp - '0';
                    cout<<"Value : "<<numArray[count]<<endl;;
                    count++;
                    cin>>inp;             
                }
                mul = 1;
                for (size_t i = 0; i < count; i++)
                {
                    /* code */
                    mul *= numArray[i];
                }
                system("cls");
                cout<<"*****************************"<<endl;
                cout<<"The multiple of entered numbers : "<<endl;
                for (size_t i = 0; i < count; i++)
                {
                    /* code */
                    cout<<numArray[i];
                    if(i != count -1)
                    {
                        cout<<" * ";
                    }
                }
                cout<<" = "<<mul<<endl;
                cout<<"*****************************"<<endl;
                cout<<endl<<endl;
                cout<<"Press '0' to exit"<<endl<<"press '1' to continue"<<endl<<"press '2' to reset"<<endl;;
                cin>>inp;

                if(inp == '0')
                {
                    cout<<"Escape has been pressed"<<endl;
                    break;

                }
                else if(inp == '1')
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }
                else if(inp == '2')
                {
                    // reset all the vaiables
                    mul=1;
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }

            }



            break;
          
        // If user enter /
        case '4':
            //cout << num1 / num2;
            while (true)
            {
                /* code */
                cout<<"Enter the number to add (press = to exit)"<<endl;
                for (size_t i = 0; i < 2; i++)
                {
                    /* code */
                    cin>>inp;
                    numArray[count] = inp - '0';
                    cout<<"Value : "<<numArray[count]<<endl;
                    if(numArray[count] == 0 && i == 1)
                    {
                        cout<<"Invalid input can`t divide the number by zero !!!!!"<<endl;
                        i--;
                        count--;
                    }
                }
                div = numArray[0] / numArray[1]; // the division
                system("cls");
                cout<<"*****************************"<<endl;
                cout<<"The division of entered numbers : "<<endl;
                for (size_t i = 0; i < count; i++)
                {
                    /* code */
                    cout<<numArray[i];
                    if(i != count -1)
                    {
                        cout<<" / ";
                    }
                }
                cout<<" = "<<div<<endl;
                cout<<"*****************************"<<endl;
                cout<<endl<<endl;
                cout<<"Press '0' to exit"<<endl<<"press '1' to continue"<<endl<<"press '2' to reset"<<endl;;
                cin>>inp;

                if(inp == '0')
                {
                    cout<<"Escape has been pressed"<<endl;
                    break;

                }
                else if(inp == '1')
                {
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }
                else if(inp == '2')
                {
                    // reset all the vaiables
                    div=1;
                    for (size_t i = 0; i < count; i++)
                    {
                        /* code */
                        numArray[i] = 0;
                    }
                    continue;

                }

            }
            break;

        case '5':
            //cout << pow(num1, num2);
            char inp2;
            cout<<"Enter the number to add (press = to exit)"<<endl;
            cin>>inp;

            cout<<"Enter the number to add (press = to exit)"<<endl;
            cin>>inp2;
            int n1, n2;
            n1 = inp - '0';
            n2 = inp2 - '0';

            cout<<inp <<" ^ "<<inp2<<" = "<<pow(n1, n2);
            
            break;
          
        // If the operator is other than +, -, * or /, 
        // error message will display
        default:
            cout << "Error! operator is not correct";
            break;
    } // switch statement ends

        /* code */
    } while (opChoice);
    sleep(3);
}