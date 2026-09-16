/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.2.8 LAB:  Some actual evaluations – finding the value of π

    Student: Eric Hepperle
    Created: 2026-09-16

    VERSION: 1.0

    STATUS: WIP

    Instructions:
     Write...

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - 

    - Full lessons learned: ./01__lessons-learned.md
    
    FUTURE IMPROVEMENTS:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>

using namespace std;

int main(void) {
	double pi4 = 0.;
	long   n;

	cout << "Number of iterations? ";
	cin >> n;

	// Insert your code here

	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	return 0;
}
