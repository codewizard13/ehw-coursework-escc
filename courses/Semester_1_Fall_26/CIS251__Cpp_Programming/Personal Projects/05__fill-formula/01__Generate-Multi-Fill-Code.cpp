/**
 * @file multi_fill_code_builder.cpp
 * @brief Generates C++ `std::fill()` statements that divide an array into
 *        equal-sized sections.
 *
 * @details
 * This personal project explores the formula needed to generate multiple
 * `std::fill()` statements for an array. Given an array name and a list of
 * unique string values, `build_str_fill()` prints one `fill()` statement per
 * value. Each generated statement targets one fractional section of a
 * theoretical array whose size is represented by `SIZE`.
 *
 * For example, an input list containing three values produces three generated
 * statements. Each statement uses `SIZE / 3` as its section size and adjusts
 * the beginning and ending offsets using the current iteration number.
 *
 * @note This program currently generates source-code text; it does not execute
 *       the generated `fill()` statements.
 *
 * @todo Test output when `SIZE` is and is not evenly divisible by the number
 *       of values.
 * @todo Evaluate boundary behavior for the first and final generated sections.
 * @todo Consider `std::vector<std::string>` and `std::size_t` in a later
 *       revision.
 *
 * Learning context:
 * This is a self-directed practice project created while studying C++ in
 * ESCC CIS-251. It was not an assigned course exercise.
 *
 * The project applies concepts explored independently through Bro Code's
 * “C++ Full Course for Free,” lesson 39: `fill()` function.
 *
 * @author Eric Hepperle
 * @date 2026-10-03
 * @version 1.0
 * @copyright 2026 Eric Hepperle
 *
 * @see Bro Code, “C++ Full Course for Free,” lesson 39: `fill()` function:
 *      https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551
 *
 * Repository: https://github.com/codewizard13
 */

#include <iostream>
using namespace std;

void build_str_fill(string arr_name, string arr[], int size);

int main()
{

    string fruits[] = {"apple", "orange", "kiwi"};
    int fruits_size = sizeof(fruits) / sizeof(fruits[0]);

    // string cars[] = {"Honda", "Toyota", "Ford", "Chevy", "Buick"};
    string cars[] = {"Honda", "Toyota", "Ford", "Chevy", "Buick", "Datsun", "Mazda"};

    int cars_size = sizeof(cars) / sizeof(cars[0]);

    build_str_fill("fruits", fruits, fruits_size);
    build_str_fill("cars", cars, cars_size);

    return 0;
}

// Each unique element should fill 1/sizeth of the the total
void build_str_fill(string arr_name, string arr[], int size)
{

    string begin, end;

    for (int i = 0; i < size; i++)
    {

        // Iteration = index + 1
        int iter = i + 1;

        cout << "fill(";

        // Build arg for 'begin'
        cout << arr_name << " + (SIZE/" << size << ")*" << i;

        cout << ", ";

        // Build arg for 'end'
        cout << arr_name << " + (SIZE/" << size << ")*" << iter;

        // Add element name and close statement
        cout << ", \"" << arr[i] << "\")" << ";\n";
    }

    cout << "*************************************\n\n";
}