/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    USER-DEFINED FUNCTIONS:
   
    Source: https://youtu.be/vKTYM-DJDiw?si=ozIq5J6ga65h16mD&t=639

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate defining custom functions below the main function

    NOTES:
        - 

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

// DECLARE CUSTOM FUNCTION BEFORE MAIN()
double add(double num1, double num2);

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

double add(double num1, double num2) {
    double result = num1 + num2;
    return result;
};