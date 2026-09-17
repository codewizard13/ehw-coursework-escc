/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.2.8 LAB:  Some actual evaluations – finding the value of π

    Student: Eric Hepperle
    Created: 2026-09-16

    VERSION: 1.0

    STATUS: FULLY WORKING

    Instructions:
     Write code using the Leibnitz formula that should ask the user to enter
     a number of totaled fractions (in other words, the number of iterations)
     and to print the computed value of π. 
     
     As we need good accuracy and a very
     large number of iterations, we use a double instead of a float and a long
     instead of an int.

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - You can avoid integer division truncation by adding a decimal in either
      or both the numertor and/or denominator (#GOTCHA: I previously thought
      it only worked with the decimal was in the DENOMINATOR)
    - For the Leibnitz formula calculation it is best use use a separate
      variable to calculate the denominator
    - For any integer counter that increases by 1, 2 * i + 1 produces an odd-number sequence that increases by 2.
    - The % operator returns a remainder and works with integer types—not double.
    - If the divisor is larger than a positive numerator, the remainder is the numerator:

    - Full lessons learned: ./01__lessons-learned.md
    
    FUTURE IMPROVEMENTS:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>

using namespace std;


/*
    ALGORITHM:

    Ask user for a number of times to run the calc loop (n)
    IF not a positive int and not zero, print error and stop program

    ELSE, LOOP n times. For each iteration (i)

        IF iteration number (i) is odd, then
            add 1/i to pi/4
        ELSE
            subtract 1/i from pi/4

    Output PI as pi4 * 4 in a decimal format



*/


int main(void) {
	double pi4 = 0.;
	long   n;

    long denom = 1;

	cout << "Number of iterations? ";
	cin >> n;

	// LOOP N TIMES
    for ( long i = 0; i < n; i++ ) {

        // UPDATE DENOMINATOR
        denom = (2 * i) + 1;

        // IF iteration number is even
        if ( i % 2 == 0) {
            pi4 += 1.0/denom;
        } else {
            pi4 -= 1.0/denom;
        }

    }

	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	return 0;
}
