/**
 * @file multi_fill_5_divisions_test.cpp
 * @brief Tests five generated `std::fill()` statements in a 125-element array.
 *
 * @details
 * This self-directed practice program tests generated `std::fill()` statements
 * from the Generate-Multi-Fill-Code project. It divides a 125-element string
 * array into five equal sections and assigns one car name to each section.
 *
 * Because 125 divides evenly by 5, each car name fills 25 array elements.
 *
 * @note This personal practice project was created while studying C++ in
 *       ESCC CIS-251; it was not an assigned course exercise.
 *
 * @note The project applies concepts independently studied through Bro Code's
 *       “C++ Full Course for Free,” lesson 39: `fill()` function.
 *
 * Learning focus:
 * - Divide an array into equal `std::fill()` ranges.
 * - Use `[begin, end)` range boundaries without overlap.
 * - Print a divider after each completed array section with the modulus operator.
 *
 * @todo Refactor the repeated `std::fill()` calls into a loop or reusable
 *       helper function after validating the generated-code test.
 *
 * @author Eric Hepperle
 * @date 2026-10-03
 * @version 1.0
 * @status Fully working
 *
 * @see Bro Code, “C++ Full Course for Free,” lesson 39: `fill()` function:
 *      https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551
 *
 * Repository: https://github.com/codewizard13
 */


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

