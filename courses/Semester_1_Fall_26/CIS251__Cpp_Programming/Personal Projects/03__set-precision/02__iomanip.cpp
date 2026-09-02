/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PERSONAL PROJECT: Demo of setprecision() and table display

    Student: Eric Hepperle
    Created: 2026-09-01

    Purpose: Demonstrates why setprecision() alone won't format decimals correctly (hint: you also need `fixed`)

    Notes:
    - Must include <iomanip> at top
    - setprecision() is a type of "string manipulator"
    - setprecision() has to come before the field you are modifying
    - setprecision() automatically rounds
    - The furthest left digit is called the "most significant digit"; precision digits is counted from the msd

    References:
    - VIDEO: Professor hank Stalica - Mastering C++ Manipulators (https://www.youtube.com/watch?v=SXLwnZG3KPI)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
#include <iomanip> // allows setprecision and the other table display operators
using namespace std;

int main(void) {
	
  double pi = 3.141592653;

  cout << setprecision(1) << pi << endl; // 3
  cout << setprecision(2) << pi << endl; // 3.1
  cout << setprecision(3) << pi << endl; // 3.14
  cout << setprecision(4) << pi << endl; // 3.142
  cout << setprecision(5) << pi << endl; // 3.1416

  // #GOTCHA: If the most significant digit is more than one digit (eg, 164), the decimal places wont work

  // pause the program
  cin.ignore();
  cin.get();

	return 0;
}