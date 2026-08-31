/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Guided Practice: Week 2, #1: Predict the value of 10 + 4 * 3, then verify it in C++.
    
    Student: Eric Hepperle
    Created: 2026-08-30

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	
    // Since multiplication takes operator precedence over addition,
    // 10 + 4 * 3 should be 10 + (4 * 3) = 10 + 12 = 22
    cout << "Guided Practice 1: Predict the value of 10 + 4 * 3, then verify it in C++" << "\n\n";

    cout << "10 + 4 * 3 = " << 10 + 4 * 3 << endl;
    // Yep, 22 is the answer

	return 0;
}