/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PERSONAL PROJECT: Demo of setprecision() and table display

    Student: Eric Hepperle
    Created: 2026-09-01

    Purpose: Uses `fixed` to ensure proper decimal precion display

    Notes:
    - `fixed` notation ensures that the decimal point stays in the desired place - you'll get everything to the left of the decimal place, but now the precision only applies to the number of digits to the right of the decimal; this operator is set and forget, so you can declare this one time near the top and unless you cancel/unset it, all numbers will display with this decimal precision
    - `showpoint` is not necessary if you are using fixed + setprecision()

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
  double x = 1505;

  // cout << fixed << setprecision(2) << pi << endl; // 3

  // This is how to set the precision formatting (set-and-forget):
  cout << setprecision(2) << fixed;

  // Testing ouptut
  cout << pi << endl; //  3.14
  cout << x << endl; // 1505.00
  cout << 19.95 << endl; // 19.95
  cout << "$19.98702" << endl; // $19.98702

  cout << endl;

  // How to reset precision back to default
  cout.unsetf(ios::fixed);

  cout << pi << endl; //  3.14


  // pause the program
  cin.ignore();
  cin.get();

	return 0;
}