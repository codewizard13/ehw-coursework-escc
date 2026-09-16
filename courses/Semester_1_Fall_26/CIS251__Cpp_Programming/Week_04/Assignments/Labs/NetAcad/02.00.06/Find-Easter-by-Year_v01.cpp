/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.6 LAB:  Some actual evaluations - finding date of Easter

    Student: Eric Hepperle
    Created: 2026-09-15

    VERSION: 1.0

    STATUS: FULLY WORKING

    Instructions:
     Write a code to find the date of Easter. The program should ask the user
     for the year number and output a date in the form Month Day, e.g. April 5.

    1.  Divide year by 19 and find the remainder – assign it to a;
    2.  divide year by 4 and find the remainder – assign it to b;
    3.  divide year by 7 and find the remainder – assign it to c;
    4.  take a, multiply it by 19, add 24, divide by 30 and find the remainder – assign it to d
    5.  divide (2b + 4c + 6d + 5) by 7 and find the remainder - assign it to e;
    6.  check the value of d + e;
    7.  if it's less than 10, Easter falls on the (d + e + 22) day of March;
    8.  otherwise it falls on the (d + e – 9) day of April;
    9.  that's all! 

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - NONE. This was pretty easy - just a bunch of modulo operations

    - Full lessons learned: ./01__lessons-learned.md
    
    FUTURE IMPROVEMENTS:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // DECLARE VARIABLES
    int year, day;
    string mo_name;

    int a, b, c, d, e;

    // GET YEAR FROM USER
    cout << "Enter a year: ";
    
    // RECEIVE & VALIDATE year
    if (!(cin >> year) || (year <= 0) ) {
        cout << "Invalid year - must be a positive integer.\n\n";
        return 0;
    }

    // 1.  Divide year by 19 and find the remainder – assign it to a;
    a = year % 19;

    // 2.  divide year by 4 and find the remainder – assign it to b;
    b = year % 4;

    // 3.  divide year by 7 and find the remainder – assign it to c;
    c = year % 7;

    // 4.  take a, multiply it by 19, add 24, divide by 30 and find the remainder
    // – assign it to d
    d = ((a * 19) + 24) % 30;

    // 5.  divide (2b + 4c + 6d + 5) by 7 and find the remainder - assign it to e;
    e = ( (2*b) + (4*c) + (6*d) + 5 ) % 7;

    // 6.  check the value of d + e;
    // 7.  if it's less than 10, Easter falls on the (d + e + 22) day of March;
    // 8.  otherwise it falls on the (d + e – 9) day of April;
    if ( (d + e) < 10 ) {
        day = d + e + 22;
        mo_name = "March";
    } else {
        day = d + e - 9;
        mo_name = "April";
    }

    cout << mo_name << " " << day;

    cout << "\n\n";
	return 0;
}

