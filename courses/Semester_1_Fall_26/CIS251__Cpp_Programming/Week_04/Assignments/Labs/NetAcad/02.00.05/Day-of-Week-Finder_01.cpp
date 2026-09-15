/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.5 LAB:  Some actual evaluations - finding day of week

    Student: Eric Hepperle
    Created: 2026-09-15

    VERSION: 1.0

    STATUS: FULLY WORKING

    Instructions:
     Write a code which finds a weekday number for a date entered by a user.
     The program should ask the user for the year, month and day (in this
     order) and output a value indicating a weekday. (Use Zeller's Congruence)

    * Make your code as smart as possible.

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - Must use `mn = mn * 83/32` because `mn *= 83/32` drops the decimal portion due to integer division before multiplying my mn.
    - Zeller's Congruence apparently depends of the integer division dropping decimal portions

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
    int year_num, month_num, day_num;

    cout << "Enter a date in YYYY MM DD format: ";

        // READ & VALIDATE YEAR NUMBER
    if ( !((cin >> year_num) && (year_num > 1899 && year_num < 2027)) ) {
        cout << "Invalid year - Only 1900-2026 allowed.\n\n";
        return 0;
    }

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


    cout << "You entered "
     << month_num << "/" << day_num << "/" << year_num << endl;


    /*
        DO CALCULATIONS
    */

    // 1. Decrease month num by 2
    month_num -= 2;

    // 2. if month number becomes less than 0, increment it by 12 and decrement year by 1;
    if (month_num <= 0) {
        month_num += 12;
        year_num--;
    }

    // 3. take month number and multiply it by 83 and divide it by 32;
    month_num = month_num * 83 / 32;

    // 4. add day number to month;
    month_num += day_num;

    // 5. add year number to month;
    month_num += year_num;

    // 6. add year/4 to month;
    month_num += year_num/4;

    // 7. subtract year/100 from month;
    month_num -= year_num/100;

    // 8. add year/400 to month;
    month_num += year_num/400;

    // 9. find the remainder of dividing month by 7;
    int remainder = month_num % 7;

    cout << "Weekday number is: " << remainder;


    cout << "\n\n";
	return 0;
}

