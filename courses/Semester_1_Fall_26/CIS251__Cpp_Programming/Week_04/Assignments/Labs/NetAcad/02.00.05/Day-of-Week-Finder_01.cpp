/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.5 LAB:  Some actual evaluations - finding day of week

    Student: Eric Hepperle
    Created: 2026-09-15

    VERSION: 1.0

    STATUS: WIP

    Instructions:
     Write a code which finds a weekday number for a date entered by a user.
     The program should ask the user for the year, month and day (in this
     order) and output a value indicating a weekday.

    * Make your code as smart as possible.

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - 
    
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
    int year_num, month_num, day_num;

    cout << "Enter a date in MM DD YYYY format: ";

    // READ & VALIDATE MONTH NUMBER
    if ( !((cin >> month_num) && (month_num > 0 && month_num < 13)) ) {
        cout << "Invalid month - only 1-12 allowed.\n\n";
        return 0;
    } 
    
    // READ & VALIDATE DAY NUMBER
    if ( !((cin >> day_num) && (day_num > 0 && day_num < 32)) ) {
        cout << "Invalid day - only 1-31 allowed.\n\n";
        return 0;
    }

    // READ & VALIDATE YEAR NUMBER
    if ( !((cin >> year_num) && (year_num > 1899 && year_num < 2027)) ) {
        cout << "Invalid year - Only 1900-2026 allowed.\n\n";
        return 0;
    }

    cout << "You entered "
     << month_num << "/" << day_num << "/" << year_num << endl;


    /*
        DO CALCULATIONS
    */
    





    cout << "\n\n";
	return 0;
}

