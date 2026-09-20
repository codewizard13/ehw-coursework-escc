/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    USER-DEFINED FUNCTIONS:
   
    Source: https://youtu.be/vKTYM-DJDiw?si=ozIq5J6ga65h16mD&t=639

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate handling user input.

    NOTES:
        - Arguments (the variables in the receiving function parens) don't need
        to have the same name as the parameters

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
void welcome(string user_name, int user_age)
{
    cout << "Welcome to my program! " << user_name << endl;
    cout << "You are " << user_age << " years old." << endl;
};

void goodbye()
{
    cout << "Goodbye!" << endl;
};

int main() {

    // functions
    string name;
    int age;

    cout << "Enter your name: " << endl;
    getline(cin, name);
    cout << "Enter your age: " << endl;
    cin >> age;

    welcome(name, age);
    goodbye();

    cout << endl;
    return 0;
}