/*
    Student: Eric Hepperle
    Date: 2026-08-22
    Status: DONE

    Assignment: Week 1 - Getting Started - Practice Exercise 3 - Calculator

    - Ask the user for two numbers. Compute:
       - Addition
       - Subtraction
       - Multiplication
       - Division

*/
#include <iostream>
using namespace std;

int main()
{
    // Declare numbers without initializing
    int num_1, num_2;

    cout << "Please enter your first of two numbers: ";
    cin >> num_1;

    cout << "Now enter your second number: ";
    cin >> num_2;

    cout << "The your first number is " << num_1 << '\n';
    cout << "Your second number is " << num_2 << endl;

    // Do the math calculations
    double nums_added = num_1 + num_2;
    double nums_subtracted = num_1 - num_2;
    double nums_mult = num_1 * num_2;
    double nums_div = num_1 / num_2;

    cout << num_1 << " added to " << num_2 << " = " << nums_added << endl;

    cout << num_1 << " minus " << num_2 << " = " << nums_subtracted << endl;

    cout << num_1 << " times " << num_2 << " = " << nums_mult << endl;

    // #GOTCHA: This returns 0 when num 1 smaller than num 2. 
    //  It also doesn't handle divide by zero, but we've not learned those topics yet.
    cout << num_1 << " divided by " << num_2 << " = " << nums_div << endl;

    return 0;
}