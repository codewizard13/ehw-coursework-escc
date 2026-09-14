/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    DO WHILE LOOPS
   
    Source: https://youtu.be/-TkoO8Z07hI?si=_hPaaE0X24ArJ1_Z&t=5941

    Student: Eric Hepperle
    Created: 2026-09-13

    PURPOSE: My notes on BroCode C++ topics.
    - This code demonstrates why a while won't work in this case, thus
        necessitating the do-while

    NOTES:
        - #GOTCHA: Declaring an integer without intializing to a value defaults to ZERO.
            This may cause while conditional tests to fail if testing < or > 0.

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

    while (numberd < 0) {
        cout << "Enter a positive #: ";
        cin >> number;
    }

    cout << "The # is: " << number;

    return 0;
}