/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Guided Practice: Week 2, #2: Compare 5 / 2 with 5.0 / 2
    
    Student: Eric Hepperle
    Created: 2026-08-30

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	
    // Check 5/2
    cout << "5/2 = " << 5/2 << endl;

    // Check 5.0/2
    cout << "5.0/2 = " << 5.0/2 << endl;


    // ******* BONUS ********

    // Check 5.0/2.0
    cout << "5.0/2.0 = " << 5.0/2.0 << endl;

    // Check 5f/2f
    // ERROR: unable to find numeric literal operator 'operator""f'
    //
    // cout << "5f/2f = " << 5f/2f << endl;

    // Check 5.0f/2.0f
    cout << "5.0f/2.0f = " << 5.0f/2.0f << endl; 

    /*
        NOTE: It appears that you only the NUMERATOR (top number) needs to have a decimal point
        for the result to be a decimal point (float).

        5/2 = 2
        5.0/2 = 2.5
        5.0/2.0 = 2.5
        5.0f/2.0f = 2.5
    */

	return 0;
}