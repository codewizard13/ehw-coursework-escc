/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PERSONAL PROJECT: Demo of setprecision() and table display

    Student: Eric Hepperle
    Created: 2026-09-01

    Purpose: To try out using setprecision, fixed, showpoint, left, right, and setw.

    References:
    - VIDEO: Professor hank Stalica - Mastering C++ Manipulators (https://www.youtube.com/watch?v=SXLwnZG3KPI)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main(void) {
	
  double pi = 3.141592653;

  cout << pi << endl;
  // result:  3.14159
  // Because C++ by default will only show you 6 digits per field

  // pause the program
  cin.ignore();
  cin.get();

	return 0;
}