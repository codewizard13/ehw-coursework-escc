/**
 * @file multi_fill_3_divisions_test.cpp
 * @brief Tests three generated `std::fill()` statements in a 99-element array.
 *
 * @details
 * This self-directed practice program tests generated `std::fill()` statements
 * from the Generate-Multi-Fill-Code project. It divides a 99-element string
 * array into three equal sections and assigns one fruit name to each section.
 *
 * Because 99 divides evenly by 3, each fruit name fills 33 array elements.
 *
 * @note This personal practice project was created while studying C++ in
 *       ESCC CIS-251; it was not an assigned course exercise.
 *
 * @note The project applies concepts independently studied through Bro Code's
 *       “C++ Full Course for Free,” lesson 39: `fill()` function.
 *
 * Learning focus:
 * - Divide an array into equal `std::fill()` ranges.
 * - Use `[begin, end)` range boundaries without overlap or gaps.
 * - Verify the generated output by printing each array element and its position.
 *
 * @todo Add divider output after each 33-element fruit section.
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

int main() {

    const int LINES = 99;
    string fruits[LINES];

    fill(fruits + (LINES/3)*0, fruits + (LINES/3)*1, "apple");
    fill(fruits + (LINES/3)*1, fruits + (LINES/3)*2, "orange");
    fill(fruits + (LINES/3)*2, fruits + (LINES/3)*3, "kiwi");

    for (int i = 0; i < LINES; i++) {
        cout << i+1 << ": " << fruits[i] << endl;

    }

    return 0;
}

