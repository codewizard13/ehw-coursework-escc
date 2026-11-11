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
 * @status WIP - THE CODE BELOW WAS 100% created by Perplexity.
 *    - Implementation written; compilation and testing pending.
 *    - Will rebuild from scratch, or create a different example.
 *
 * @author Eric L. Hepperle
 * @date 2026-11-11
 * @updated --
 * @version 1.0
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <stdexcept>

int main()
{
    double numerator = 0.0;
    double denominator = 0.0;

    std::cout << "Enter the numerator: ";
    if (!(std::cin >> numerator))
    {
        std::cout << "Input error: the numerator must be a number.\n";
        return 1;
    }

    std::cout << "Enter the denominator: ";
    if (!(std::cin >> denominator))
    {
        std::cout << "Input error: the denominator must be a number.\n";
        return 1;
    }

    try
    {
        if (denominator == 0.0)
        {
            throw std::runtime_error("Cannot divide by zero.");
        }

        double quotient = numerator / denominator;
        std::cout << "Quotient: " << quotient << '\n';
    }
    catch (const std::runtime_error& error)
    {
        std::cout << "Division error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}