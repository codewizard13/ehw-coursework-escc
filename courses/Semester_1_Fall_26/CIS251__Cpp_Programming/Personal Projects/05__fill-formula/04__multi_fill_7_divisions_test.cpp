/**
 * @file multi_fill_7_divisions_test.cpp
 * @brief Tests generated `std::fill()` statements with seven divisions in a
 *        125-element string array.
 *
 * @details
 * This self-directed practice program tests `std::fill()` statements generated
 * by the Generate-Multi-Fill-Code project. It fills a 125-element `cars` array
 * with seven car-name values:
 *
 * - Honda, Toyota, Ford, Chevy, Buick, Datsun, Mazda
 *
 * Because 125 does not divide evenly by 7, the program calculates the maximum
 * section size by passing a floating-point quotient to the custom `round_up()`
 * helper function:
 *
 *   `LINES_DIV_ELS = round_up(LINES * 1.0 / cars_size)`
 *
 * With 125 total array elements and 7 unique car-name values, the quotient is
 * approximately 17.857. The custom helper rounds the result up to 18.
 *
 * The first six `std::fill()` statements each fill 18 array elements. The
 * final statement ends at `cars + LINES`, so it fills only the remaining
 * 17 elements and does not write beyond the valid 125-element array.
 *
 * @note This is a self-directed practice project created while studying C++ in
 *       ESCC CIS-251. It was not an assigned course exercise.
 *
 * @note This project applies concepts studied independently through Bro Code's
 *       “C++ Full Course for Free,” lesson 39: `fill()` function.
 *
 * Practical `std::fill()` use cases:
 * - Reset an entire array to a known default value before reuse.
 * - Mark unassigned entries with a sentinel value, such as -1 or "unassigned".
 * - Populate contiguous array sections with category, zone, or test-data labels.
 * - Mask selected characters in a string with a repeated character, such as '*'.
 *
 * @warning The calculated section size is 18, but 18 * 7 equals 126. The final
 *          `std::fill()` range must end at `cars + LINES`, not at
 *          `cars + (LINES_DIV_ELS * cars_size)`, to prevent an out-of-bounds
 *          write.
 *
 * @todo Test another total line count that divides evenly by the number of
 *       unique car-name values.
 * @todo Compare `round_up()` with an integer-only ceiling-division expression.
 * @todo Refactor repeated `std::fill()` statements into a loop or helper
 *       function after validating this generated-code test.
 * @todo Add input validation if `cars_size` could ever be zero.
 *
 * Learning context:
 * This personal challenge tests understanding of C++ arrays, array-range
 * boundaries, integer versus floating-point division, custom upward rounding,
 * and the half-open `[begin, end)` range used by `std::fill()`.
 *
 * @author Eric Hepperle
 * @date 2026-10-03
 * @version 1.0
 * @Status: Fully working.
 * @copyright 2026 Eric Hepperle
 *
 * @see Bro Code, “C++ Full Course for Free,” lesson 39: `fill()` function:
 *      https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551
 *
 * Repository: https://github.com/codewizard13
 */

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
