/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Guided Practice: Week 2, #3: Convert a number of inches into feet and remaining inches using / and %
    
    Student: Eric Hepperle
    Created: 2026-08-30

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	
    int start_inches, feet, remaining_inches;

    cout << "Enter the number of inches to convert to feet-and-remaining-inches: ";
    cin >> start_inches;

    // Convert
    feet = start_inches / 12;
    remaining_inches = start_inches % 12;

    cout << start_inches << " inches converts to " << feet << " ft. and " << remaining_inches << " in." << "\n\n";

	return 0;
}