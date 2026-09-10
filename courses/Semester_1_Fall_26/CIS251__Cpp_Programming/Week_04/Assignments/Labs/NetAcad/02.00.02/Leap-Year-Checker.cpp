/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.2 LAB:  Essentials of if-else statement
    Student: Eric Hepperle
    Created: 2026-09-10

    Instructions:
    --

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int year;

    cout << "Enter a year: ";
    cin >> year;

    // TEST IF CODE IS LEAP YEAR
    if (year % 4 > 0 ) {
        // cout << "Year " << year << " is NOT a leap year." << endl;
        cout << "Common Year" << endl;
    } else {
        // cout << "Year " << year << "is a LEAP YEAR!" << endl;
        cout << "Leap Year" << endl;
    }

    /*
        #GOTCHA: 1900 is reading as leap year
    */

    cout << "\n\n";

    return 0;
}