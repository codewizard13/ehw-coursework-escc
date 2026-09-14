/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.4 LAB:  Some actual evaluations - converting measurement systems

    Student: Eric Hepperle
    Created: 2026-09-13

    VERSION: 1.0

    STATUS: WIP - WORKS but due to a formatting quirk the result_string builds the inches without rounding.

    Instructions:
    Write a simple "measurement converter". We want it to perform the following actions:

    *   ask the user which system she/he uses to input data; we assume that 0 means "metric" and 1 means "imperial";
    *   depending on the user's answer, ask either for meters or feet and inches;
    *   output the distance in proper (different) units: either in feet and inches or in meters;
    *   a result outputted as metric should look like **123.4m**;
    *   a result outputted as imperial should look like **12'3.5"**.

    - Full instructions: ./00_instructions.md

    Lessons Learned:
    - #GOTCHA: You can't use `<<` in an assignment statement, you need to use `+` instead. However, you cannot add a number and a string -- it will give `integral or unscoped enum type` error. The solution is to convert your numbers to strings by using to_string([my_num]).

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

#include <iostream>

using namespace std;

int main(void) {
	int sys;
	float m, ft, in;

    string sys_name, units_used, result_string;
    const float FEET_PER_METER = 3.28084;
    float calculated_decimal_feet;

	cout << "Which measurement system (0 = metric, 1 = imperial): ";

    // VALIDATE SYS (if not int or greater than 1)
    if (!(cin >> sys) || !(sys == 0 || sys == 1 )) {
        cout << "Invalid input.\n";
        return 0;
    }

    switch (sys) {
        case 0:
            sys_name = "metric";
            units_used = "meters";
            break;
        case 1:
            sys_name = "imperial";
            units_used = "feet and inches";
            break;
    }

    cout << "You entered: (" << sys << ") " << sys_name << endl;

    cout << setprecision(4) << fixed;

    // ASK FOR starting value to convert
    switch (sys) {
        case 0: // metric
            cout << "Please enter the value in meters: ";
            cin >> m;
            calculated_decimal_feet = m * FEET_PER_METER; 
            ft = (int) calculated_decimal_feet;
            cout << m << "m ~= " << ft << " ft" << endl;;
            in = (calculated_decimal_feet - ft) * 12;
            cout << "Inches = " << in << endl;
            result_string = to_string((int)ft) + "'" + to_string(in) + "\"";
            break;
        case 1: // imperial
            break;
    }

    cout << result_string;
    
    cout << "\n\n";

	
	return 0;
}

