/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    
    PERSONAL PROJECT: 

    **** TEST: fill-builder with 5 divisions, 125 els total ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Tests copy-pasting from Generate-Multi-Fill-Code.cpp into a file; this is for 5 divisions

    📝 Lessons Learned:
    - To print a divider every time the element changes, use a condition testing,

        if ( (i+1) % (LINES/unique_arr_size) == 0 )
    
    References:
    - VIDEO: Bro Code - C++ Full Course for free | 39. Fill() function (https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */


#include <iostream>
using namespace std;

string cars[] = {"Honda", "Toyota", "Ford", "Chevy", "Buick"};
int cars_size = sizeof(cars)/sizeof(cars[0]);

int main() {

    const int LINES = 125;
    string cars[LINES];

    const int lines_div_cars_size = LINES/cars_size;
    cout << "## \t\t lines_div_cars_size = " << lines_div_cars_size << endl;

    fill(cars + (LINES/cars_size)*0, cars + (LINES/cars_size)*1, "Honda");
    fill(cars + (LINES/cars_size)*1, cars + (LINES/cars_size)*2, "Toyota");
    fill(cars + (LINES/cars_size)*2, cars + (LINES/cars_size)*3, "Ford");
    fill(cars + (LINES/cars_size)*3, cars + (LINES/cars_size)*4, "Chevy");
    fill(cars + (LINES/cars_size)*4, cars + (LINES/cars_size)*5, "Buick");

    for (int i = 0; i < LINES; i++) {

        int iter = i + 1;

        cout << iter << ": " << cars[i] << endl;

        // Print pretty divider every 5th section
        if (iter % lines_div_cars_size == 0) {
            cout << "**************************************\n";

        }

    }

    return 0;
}

