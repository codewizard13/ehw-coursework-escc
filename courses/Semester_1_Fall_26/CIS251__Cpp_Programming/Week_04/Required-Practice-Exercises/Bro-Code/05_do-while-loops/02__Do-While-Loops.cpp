/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    DO WHILE LOOPS
   
    Source: https://youtu.be/-TkoO8Z07hI?si=_hPaaE0X24ArJ1_Z&t=5941

    Student: Eric Hepperle
    Created: 2026-09-13

    PURPOSE: My notes on BroCode C++ topics.

    NOTES:
        - #GOTCHA: Declaring an integer without intializing to a value defaults to ZERO.
            This may cause while conditional tests to fail if testing < or > 0. A do-while loop
            avoids this initialization issue.

    EX OUTPUT:

        Enter a positive #: -1
        Enter a positive #: -2
        Enter a positive #: -567
        Enter a positive #: 3
        The # is: 3

    USE CASES:
    - Run game once, then based on users Y/N input at the end when can keep running the game repeatedly.
        "Would you like to play a game?" (War Games) - Eric's note

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

/*
    ALGORITHM:

    //TODO
*/


int main() {

    // dO while loop = do some block of code first,
    //          THEN repeat again if condition is true

    int number;

    do {
        cout << "Enter a positive #: ";
        cin >> number;
    } while (number < 0);

    cout << "The # is: " << number;

    return 0;
}