/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming

    PERSONAL PROJECT:

    **** TEST: fill-builder with 7 divisions, 125 els total ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: WIP

    Purpose:
    - Tests copy-pasting from Generate-Multi-Fill-Code.cpp into a file; this is for 7 divisions
    - Specifically demos when the number of unique array elements doesn't divide evenly into the total number of desired lines

    📝 Lessons Learned:
    - Created custom helper 'round_up()' function to avoid using cmath. However, the following would do it in one line, without a custom function,
    
        int LINES_DIV_ELS = LINES % cars_size == 0 ? LINES / cars_size : (LINES/cars_size) + 1;

    - #GOTCHA:  In my round_up() implementation, I correctly recognized that I needed floating-point division. My mistake was overlooking that the integer division happened first, before multiplication by 1.0 could change the type. I knew the rule, but did not immediately notice how it applied in this expression. So I originally had,

        round_up((LINES / cars_size*1.0))

    But, after troubleshooting, realized it should be,

        round_up((LINES*1.0 / cars_size))

    References:
    - VIDEO: Bro Code - C++ Full Course for free | 39. Fill() function (https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

string cars[] = {"Honda", "Toyota", "Ford", "Chevy", "Buick", "Datsun", "Mazda"};
int cars_size = sizeof(cars) / sizeof(cars[0]);

int round_up(double num);


int main()
{

    const int LINES = 125;
    string cars[LINES];

    const int LINES_DIV_ELS = round_up((LINES*1.0 / cars_size));
    cout << "## \t\t LINES_DIV_ELS = " << LINES_DIV_ELS << endl;

    fill(cars + LINES_DIV_ELS * 0, cars + LINES_DIV_ELS * 1, "Honda");
    fill(cars + LINES_DIV_ELS * 1, cars + LINES_DIV_ELS * 2, "Toyota");
    fill(cars + LINES_DIV_ELS * 2, cars + LINES_DIV_ELS * 3, "Ford");
    fill(cars + LINES_DIV_ELS * 3, cars + LINES_DIV_ELS * 4, "Chevy");
    fill(cars + LINES_DIV_ELS * 4, cars + LINES_DIV_ELS * 5, "Buick");
    fill(cars + LINES_DIV_ELS * 5, cars + LINES_DIV_ELS * 6, "Datsun");
    fill(cars + LINES_DIV_ELS * 6, cars + LINES, "Mazda");

    for (int i = 0; i < LINES; i++)
    {

        int iter = i + 1;

        cout << iter << ": " << cars[i] << endl;

        // Print pretty divider every 5th section
        if (iter % LINES_DIV_ELS == 0 || iter == LINES)
        {
            cout << "**************************************\n";
        }
    }

    return 0;
}

// Custom function to round up
int round_up(double num) {
    if (num - (int) num != 0) {
        return (int) num + 1;
    } 
    return (int) num;
}
