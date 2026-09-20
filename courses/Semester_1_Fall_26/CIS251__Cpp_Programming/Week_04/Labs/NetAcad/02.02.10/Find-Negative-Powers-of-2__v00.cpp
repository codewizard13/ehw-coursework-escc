/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.2.10 LAB:  Finding negative powers of 2

    Student: Eric Hepperle
    Created: 2026-09-20

    VERSION: 0.0

    STATUS: FULLY WORKING

    PURPOSE: This is the sample solution from the course.

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

using namespace std;

int main(void) {
	int n;

	// 2 to the power of 0 is 1
	double pow = 1;

	cout << "n? ";
	cin >> n;
	for(int i = 0; i < n; i++) 

		// evaluate next negative power of 2
		pow /= 2.0;
	
	cout.precision(20);
	cout << pow << endl;
	return 0;
}
