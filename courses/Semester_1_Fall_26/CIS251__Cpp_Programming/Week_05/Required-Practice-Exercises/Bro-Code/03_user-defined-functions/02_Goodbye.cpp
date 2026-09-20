/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    USER-DEFINED FUNCTIONS
   
    Source: https://www.youtube.com/watch?v=vKTYM-DJDiw

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate calling multiple functions.

    NOTES:
        - functions he introduced previously: 
          - printf(), length(), at()
        - functions perform some sort of task for you

    EX OUTPUT:

        

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
    ALGORITHM:

    //TODO
*/


// HOW TO DECLARE A FUNCTION
void welcome()
{
    cout << "Welcome to my program!" << endl;
};

void goodbye()
{
    cout << "Goodbye!" << endl;
};

int main() {

    welcome();
    goodbye();

    cout << endl;
    return 0;
}