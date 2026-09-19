/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.2.10 LAB:  Finding negative powers of 2

    Student: Eric Hepperle
    Created: 2026-09-18

    VERSION: 1.0

    STATUS: WIP

    Instructions:
     We want you to modify your previous program (Lab 2.2.9) to make it able to
     evaluate negative powers of two.

     - Hint 1: use division instead of multiplication.

     - Hint 2: use a double to store the result – remember, you operate
     in fractions!

     - Hint 3: don't forget to add cout.precision(20); before printing the
     final result (unless you want to lose the most interesting part of
     the value)

    - Full instructions: ./00_instructions.md

    📝 Lessons Learned:
    - ...

    - Full lessons learned: ./01__lessons-learned.md

    FUTURE IMPROVEMENTS:
    - ...

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
    ALGORITHM:



*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // DEFINE VARIABLES
    unsigned long long result = 1;
    int pow;

    // GET POWER NUBMER FROM USER
    cout << endl;
    cout << "Enter the power of 2 to calculate: ";

    // RECEIVE & VALIDATE INPUT
    if (!(cin >> pow))
    {
        cout << "Invalid input: Must be a positive or negative integer\n\n";
        return 0;
    }

    // CALCULATE RESULT BASED ON POSITIVE EXPONENT
    // NOTE: we'll need this value if negative exponent also
    for (int i = 0; i < pow; i++)
    {

        result /= 2.0;

        // cout << "i: " << i+1 << " | result: " << result << endl;
    }


    cout.precision(20);

    cout << result << endl;
    cout << "\n\n";
    return 0;
}
