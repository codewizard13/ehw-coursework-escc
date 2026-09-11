/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.2 LAB:  Essentials of if-else statement
    Student: Eric Hepperle
    Created: 2026-09-10
    Updated: 2026-09-10

    VERSION: 2.0

    STATUS: FULLY WORKING & TESTED

    Instructions:
        Since the introduction of the Gregorian calendar (in 1582), the following rule is used to determine the kind of year:

        - if the year number isn't divisible by 4, it is a common year;
        - otherwise, if the year number isn't divisible by 100, it is a leap year;
        - otherwise, if the year number isn't divisible by 400, it is a common year;
        - otherwise, it is a leap year.
        
        The code should output one of two possible messages, which are Leap year or Common year, depending on the value entered.

        It would be good to verify if the year entered falls into the Gregorian era and to output a warning otherwise.

        Full instructions: ./00_instructions.md

    Improvements:
    - simplifies and combines the validation code into a single multi-branch conditional

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int year;

    // DEFINE VARIABLES
    cout << "Enter a year: ";
    cin >> year;
    const string MSG_LEAP_YEAR = "Leap Year";
    const string MSG_COMMON_YEAR = "Common Year";

    // VALIDATE YEAR FALLS IN GREGORIAN ERA
    if (year < 1582) {
        cout << "Warning: Year " << year << " falls outside the Gregorian era.\n\n";
    } else if ( (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0) ) {
        cout << MSG_LEAP_YEAR << endl;
    } else {
        cout << MSG_COMMON_YEAR << endl;
    }

    cout << endl;

    return 0;
}