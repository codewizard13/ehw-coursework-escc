/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    BREAK & CONTINUE
   
    Source: https://youtu.be/-TkoO8Z07hI?si=Th4pG9tuJm9FO-gl&t=6357

    Student: Eric Hepperle
    Created: 2026-09-13

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrates break

    NOTES:
        - STOPS and ENDS program when it sees 'unlucky' number 13

    EX OUTPUT:

    USE CASES:
    - 

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

    // break = break out of a loop
    // continue = skip current iteration

    for ( int i = 1; i <= 20; i++ ) {

        if ( i == 13 ) {
            break;
        }

        cout << i << '\n';

    }

    return 0;
}