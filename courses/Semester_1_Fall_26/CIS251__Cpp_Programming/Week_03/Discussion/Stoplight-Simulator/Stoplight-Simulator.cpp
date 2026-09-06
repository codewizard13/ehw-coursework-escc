/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 3 DISCUSSION ASSIGNMENT Helper Demo - Stoplight Simulator
    Student: Eric Hepperle
    Created: 2026-09-05

    Instructions:
    Demonstrates edge-cases and boundary conditions.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {

    int light_value;
    string light_label;
    bool light_value_valid = true;

    cout << endl;
    cout << "Enter a number to set the stoplight values (1=green, 2=yellow, 3=red): ";
    cin >> light_value;

    switch (light_value) {
        case 1:
            light_label = "Green";
            break;
        case 2:
            light_label = "Yellow";
            break;
        case 3:
            light_label = "Red";
            break;
        default:
            light_value_valid = false;
    }

    if (! light_value_valid) {

        cout << "You have entered an invalid choice";
        return 0;

    }

    cout << "The light is " << light_label << "\n";

    cout << "*******************\n\n";

	return 0;
}