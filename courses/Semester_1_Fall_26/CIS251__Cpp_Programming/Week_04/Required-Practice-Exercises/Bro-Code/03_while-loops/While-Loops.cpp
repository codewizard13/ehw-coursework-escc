/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    WHILE LOOPS
    
    Source: https://www.youtube.com/watch?v=-TkoO8Z07hI&t=2433s

    Student: Eric Hepperle
    Created: 2026-09-13

    PURPOSE: My notes on BroCode C++ topics

    NOTES:
        - var.empty()
        - getline(cin, [var])
        - while()
        - infinite loop
        - A great use of while loop is to force a user to do something in order to be able to execute the code

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    /*
        ALGORITHM:

        //TODO
    */

    string name;

    while (name.empty()) {
        cout << "Enter your name: ";
        getline(cin, name);
    }

    cout << "Hello " << name;

    return 0;
}