/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    FOR LOOPS
   
    Source: https://youtu.be/-TkoO8Z07hI?si=0P1wVnU9K0m8VoEo&t=6139

    Student: Eric Hepperle
    Created: 2026-09-13

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate a basic for loop that prints HAPPY NEW YEAR 3 times

    NOTES:
        - for loop: executes a block of code a specified amount of time
        - for (index, stopping condition, increment/decrement)
        - #GOTCHA: Accidentally making the stopping condition `1 <= 3` instead of `i <= 3` results in an infinite loop

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

    for ( int i = 1; i <= 3; i++  ) {
        cout << "HAPPY NEW YEAR!!!\n";
    }

    return 0;
}