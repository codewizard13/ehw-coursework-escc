/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PERSONAL PROJECT: Demo of setprecision() and table display

    Student: Eric Hepperle
    Created: 2026-09-20

    Purpose: Demonstates custom function basics, decision logic, and
      input validation

    Notes:
    - 

    References:
    - VIDEO: Bro Code - C++ user defined functions (https://www.youtube.com/watch?v=vKTYM-DJDiw)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// DECLARE CUSTOM FUNCTION BEFORE MAIN()
void launch_delorean(bool has_flux_cap, bool has_plutonium, bool has_marty) {
    if (has_flux_cap && has_plutonium && has_marty) {
        cout << "Hold tight Marty, where we're going we don't need roads!\n\n";
    }
}

int main() {

    // VARIABLES
    int proceed = 0;
    bool has_flux_cap = false;
    bool has_plutonium = false;
    bool has_marty = false;


    cout << "Are you ready to launch the Delorean and go \"Back to the Future!\"?\n";
    cout << "Answer the following ( 1-yes, 0-no )" << endl;
    
    cout << "Do you have flux cap? ";
    if (!(cin >> proceed) || proceed != 1) {
        cout << "Bummer. Can't launch DeLorean this time.\n" << endl;
        return 0;
    } 
    has_flux_cap = true;

    cout << "Do you have plutonium? ";
    if (!(cin >> proceed) || proceed != 1) {
        cout << "Bummer. Can't launch DeLorean this time.\n" << endl;
        return 0;
    } 
    has_plutonium = true;

    cout << "Is Marty with you? ";
    if (!(cin >> proceed) || proceed != 1) {
        cout << "Bummer. Can't launch DeLorean this time.\n" << endl;
        return 0;
    } 
    has_marty = true;

    launch_delorean(has_flux_cap, has_plutonium, has_marty);


    cout << endl;
    return 0;
}
