/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    FOR LOOPS
   
    Source: https://youtu.be/-TkoO8Z07hI?si=7sIzAOneT66cM8o8&t=6271

    Student: Eric Hepperle
    Created: 2026-09-13

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrates using different indexes and step values

    NOTES:
        - step value: how much you increment or decrement by in a loop
        - #GOTCHA: odd decrement counter only works if you start with an odd index number

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

    // ODD INCREMENT COUNTER
    //
    // INCREMENT by 2 instead of 1 (step value)

    cout << "*** ODD INCREMENT COUNTER ***\n";

    for ( int i = 1; i <= 10; i+=2  ) {
        cout << i << "\n";
    }

    // EVEN INCREMENT COUNTER
    //
    // INDEX initialized to 0 instead of 1

    cout << "*** EVEN INCREMENT COUNTER ***\n";

    for ( int i = 0; i <= 10; i+=2  ) {
        cout << i << "\n";
    }

    // DECREMENT COUNTER
    //
    // INDEX = starting value, i >= zero, subtract one from i each iteration

    cout << "*** DECREMENT COUNTER (step = -1) ***\n";

    for ( int i = 10; i >= 0; i--  ) {
        cout << i << "\n";
    }

    // EVEN DECREMENT COUNTER
    //
    // INDEX = starting value, i >= zero, subtract one from i each iteration

    cout << "*** EVEN DECREMENT COUNTER (step = -2) ***\n";

    for ( int i = 10; i >= 0; i-=2  ) {
        cout << i << "\n";
    }

    // ODD DECREMENT COUNTER
    //

    cout << "*** ODD DECREMENT COUNTER (step = -2) ***\n";

    for ( int i = 9; i >= 0; i-=2  ) {
        cout << i << "\n";
    }

    // FINAL OUTPUT MSG

    cout << "HAPPY NEW YEAR!!!\n";

    return 0;
}