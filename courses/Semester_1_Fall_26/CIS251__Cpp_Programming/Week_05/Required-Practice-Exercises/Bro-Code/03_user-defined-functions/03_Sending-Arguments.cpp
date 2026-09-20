/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    USER-DEFINED FUNCTIONS:
   
    Source: https://www.youtube.com/watch?v=vKTYM-DJDiw

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate passing arguments to a function.

    NOTES:
        - when you call a function you can send it some info ( a value, name, or object )
        - arguments: the info you are sending a function; like mail
        - set up functions to take arguments by using function parameters
        - when you call a function with a set of parameters you need to send a matching set of
            arguments when you call it

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
void welcome(string name, int age)
{
    cout << "Welcome to my program! " << name << endl;
    cout << "You are " << age  << " years old." << endl;
};

void goodbye()
{
    cout << "Goodbye!" << endl;
};

int main() {

    welcome("Bro", 18);
    goodbye();

    cout << endl;
    return 0;
}