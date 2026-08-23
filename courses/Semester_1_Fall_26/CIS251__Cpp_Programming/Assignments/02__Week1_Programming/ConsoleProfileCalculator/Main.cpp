/*
    Student: Eric Hepperle
    Date: 2026-08-22
    Status: DONE

    Week 1 Programming Assignment: Console Profile Calculator: write a program
     that asks for a student's name and two numeric values, stores them in 
     appropriately typed variables, performs one arithmetic calculation, and
     prints clearly labeled results. Use only program structure, variables,
     arithmetic, cin, and cout.

    ALGORITHM:

        declare all three variables below without initializing

        Get student name
        Get num 1
        Get num 2

        Divide the numbers

        Print results
*/

#include <iostream>
using namespace std;

int main()
{

    // Declare variables without initializing
    string name;
    int num_1, num_2;

    cout << "What is your name? ";
    cin >> name;

    cout << "Hi, " << name << ", " << "welcome to the Console Profile Calculator!" << "\n\n";

    cout << "Please enter your first of two numbers: ";
    cin >> num_1;

    cout << "Now enter your second number: ";
    cin >> num_2;
    cout << "\n";

    cout << "Your first number is " << num_1 << '\n';
    cout << "Your second number is " << num_2 << "\n\n";

    // One arithmetic calculation - I chose division because it has more risk 
    //  reveal problems and edge cases.
    double nums_div = num_1 / num_2;

    // #GOTCHA: This returns 0 when num 1 smaller than num 2. 
    //  It also doesn't handle divide by zero, but we've not learned those topics yet.
    //  (See test table for a few other observations)
    cout << num_1 << " divided by " << num_2 << " = " << nums_div << endl;

    return 0;
}