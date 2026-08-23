/*
    Student: Eric Hepperle
    Date: 2026-08-22

    NOTE: This program is deliberate broken to show the resulting error when not using to_string() on price.

    ⚠️ #GOTCHA: C++ String Concatenation with `+` and `std::to_string()`

    In C++, the `+` operator's behavior depends on the types it's working with.
    `std::string` + `std::string` = Concatenation.
    `numeric` + `numeric` = Arithmetic Addition.
    `std::string` + `numeric` = Compiler Error ("no match for operator+").

    The compiler doesn't automatically convert numbers to `std::string` when using the `+` operator for `std::string` concatenation. Therefore, you must explicitly convert any numeric variable (e.g., `int`, `double`) to a `std::string` using `std::to_string()` before attempting to concatenate it with other `std::string`s. This ensures all operands are `std::string` type, allowing the `+` operator to perform string concatenation correctly.
*/
#include <iostream>
#include <string>

int main() {
    std::string item = "book";
    double price = 19.99;

    std::string message = "The " + item + " costs $" + price + ".";
    std::cout << message << std::endl;
    return 0;
}