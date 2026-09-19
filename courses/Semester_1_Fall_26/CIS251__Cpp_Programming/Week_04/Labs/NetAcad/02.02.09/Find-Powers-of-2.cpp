/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.2.9 LAB:  Finding positive powers of 2

    Student: Eric Hepperle
    Created: 2026-09-18

    VERSION: 1.0

    STATUS: FULLY WORKING

    Instructions:
     Write a program which shows the n-th power of two (n will be the input for
     the program). We'll use the following assumptions:

     - the largest value of n to take into consideration is 63, as unsigned
     long integers use exactly 64 bits to represent their values (note: a value
     of 2n needs n+1 bits – can you explain why?);

     - we won't use any actual exponentiation – we're going to substitute it
     with repeated multiplications.

    - Full instructions: ./00_instructions.md

    📝 Lessons Learned:
    - On Windows, use `unsigned long long` rather than `unsigned long` when calculating \(2^{32}\) or larger. Windows keeps `unsigned long` at 32 bits—even in a 64-bit program—so its maximum is `4,294,967,295`; \(2^{32}\) overflows and wraps to `0`. `unsigned long long` is 64 bits and correctly holds \(2^{32} = 4,294,967,296\). Verify with `sizeof(unsigned long)` (usually `4`) and `sizeof(unsigned long long)` (`8`).

    - Full lessons learned: ./01__lessons-learned.md
    
    FUTURE IMPROVEMENTS:
    - ...

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */


/*
    ALGORITHM:

    DEFINE  an long int 'result' and initialize it to 2
    How many powers of two do you want to calculate? (pow)
    Receive and validate input from user
        if not int and not positive, print error and stop program

    Start an interation counter (i) at zero
    REPEAT until iteration count (i) >= the pow value
        result *=2
        increment i by 1

    PRINT result to console

*/

#include <iostream>
#include <iomanip>
using namespace std;


int main () {

    // DEFINE VARIABLES
    unsigned long long result = 1;
    int pow;
    
    // GET POWER NUBMER FROM USER
    cout << endl;
    cout << "Enter the power of 2 to calculate: ";

    // RECEIVE & VALIDATE INPUT
    if (!(cin >> pow) || pow <= 0) {
        cout << "Invalid input: Must be a positive number - You entered [ " << pow <<  " ]\n\n";
        return 0;
    }

    // PROCESS EXPONENT VALUE
    for ( int i = 0; i < pow; i++) {

        result*= 2;

        // cout << "i: " << i+1 << " | result: " << result << endl;

    }

    cout << result << endl;
    cout << "\n\n";
    return 0;
}

