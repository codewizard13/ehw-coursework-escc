/**
 * @brief Safe Division — Week 11 C++ programming assignment:
 *        Input Validation & Exception Handling.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 11 Programming Assignment
 * @lesson_focus Decisions, Input Validation, and try/throw/catch.
 *
 * @instructions Safe Division: validate routine numeric input with decisions
 *    and use try/throw/catch to handle division by zero. Explain why the
 *    exception is appropriate. Plan with pseudocode, compile incrementally,
 *    and test normal, boundary, and invalid inputs.
 *
 * @status WIP - Creating and implementing the code incrementally
 *
 * @author Eric L. Hepperle
 * @date 2026-11-11
 * @updated --
 * @version 1.01
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{

    cout << "\n******** START DIVIDE BY ZERO ERROR HANDLING DEMO ****************************\n";

    double numerator = 0.0;
    double denominator = 0.0;

    // Validate that numerator is a number
    cout << "Enter a numerator: ";
    if (!(cin >> numerator))
    {
        cout << "Input error: numerator must be a number.\n";
        cout << "\n******** END PROGRAM *******************************************\n";
        return 1;
    }

    // cout << "The numerator is: " << numerator << endl;


    // Validate that denominator is a number
    cout << "Enter a denominator: ";
    if (!(cin >> denominator))
    {
        cout << "Input error: denominator must be a number.\n";
        cout << "\n******** END PROGRAM *******************************************\n";
        return 1;
    }

    // cout << "The denominator is: " << denominator << endl;    

    try {
        if (denominator == 0.0)
            throw runtime_error("Cannot divide by zero.");

        double quotient = numerator / denominator;
        cout << "Quotient: " << quotient << endl;
    }
    catch (const runtime_error& e) {
        cout << "\nRuntime Error: " << e.what() << endl;
    }


    cout << "\n******** END PROGRAM *******************************************\n";

    return 0;
}
