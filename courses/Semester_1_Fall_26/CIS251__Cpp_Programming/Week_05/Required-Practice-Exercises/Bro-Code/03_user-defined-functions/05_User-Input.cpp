/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    USER-DEFINED FUNCTIONS:
   
    Source: https://youtu.be/vKTYM-DJDiw?si=ozIq5J6ga65h16mD&t=639

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate handling user input.

    NOTES:
        - Arguments (the variables in the receiving function parens) don't need
        to have the same name as the parameters
        - #GOTCHA: Custom functions must be declared BEFORE the MAIN method!
        - #TIP: If you for some reason DO want your custom functions to appear
        AFTER the main method, you can by declaring the function before the
        main() and defining the function AFTER the main

    EX OUTPUT:

        

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

double add(double num1, double num2) {
    double result = num1 + num2;
    return result;
};


int main() {

    // functions

    double number1;
    double number2;

    cout << "Enter in #1 : " << endl;
    cin >> number1;
    cout << "Enter in #2 : " << endl;
    cin >> number2;
    
    double result = add(number1, number2);

    cout << "Your result is: " << result << endl;

    cout << endl;
    return 0;
}