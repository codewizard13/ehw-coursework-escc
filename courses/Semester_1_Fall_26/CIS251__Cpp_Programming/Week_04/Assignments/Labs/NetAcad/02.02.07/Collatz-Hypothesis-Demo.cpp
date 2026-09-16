/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.2.7 LAB:  Collatz's hypothesis

    Student: Eric Hepperle
    Created: 2026-09-16

    VERSION: 1.0

    STATUS: FULLY WORKING

    Instructions:
     Write a program to demo Collatz's hypothesis which reads one natural
      number and executes the above steps as long as c0 remains different
      from 1. Moreover, we'll give you another task – we want you to count the
      steps needed to achieve the goal. Your code should output all
      intermediate values of c0, too – it'll be very illustrative, won't it?

     1. take any non-negative and non-zero integer number and name it c0;
     2. if it's even, evaluate a new c0 as c0 / 2
     3. otherwise, if it's odd, evaluate a new c0 as 3 ⋅ c0 + 1
     4. if c0 ≠ 1, skip to point 2

     Hint: the most important part of the problem is how to transform Collatz's
      idea into a "while" loop – this is the key to success.

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - NONE. This was fairly easy using a do-while loop
    - didn't require break/continue

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

    // DEFINE VARIABLES
    int num;
    int counter = 0;

    int c0;

    // RECEIVE & VALIDATE num
    cout << endl;
    cout << "Enter any number greater than zero: ";
    if (!(cin >> num) || (num <= 0)) {
        cout << "Invalid input:  Must be number greater than zero.\n\n";
        return 0;
    }

    // CALCULATE
    c0 = num;
    cout << "You entered " << c0 << "\n\n";

    do {

        if (c0 % 2 == 0) {
            c0 /= 2;
        } else {
            c0 = 3 * c0 + 1;
        }

        counter++;

        cout << c0 << endl;

    } while (c0 != 1);

    cout << "steps = " << counter;

    // cout << "--- END ---\n\n";
    return 0;
}
