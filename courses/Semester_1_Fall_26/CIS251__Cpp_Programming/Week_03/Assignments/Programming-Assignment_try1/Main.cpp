/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 3 PROGRAMMING ASSIGNMENT — Decision Structures and Boolean Logic
    Student: Eric Hepperle
    Created: 2026-09-05

    Instructions:
    Shipping Charge Decision Program: ask for an order amount and shipping option, use if/else and/or switch to select the correct charge from a supplied decision table, and print the final amount. Include boundary tests for every branch.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {

    /*
        ALGORITHM:

        Get order amount from user
        Get shipping option ( standard, express, overnight) from user
        Print final amount     

    
    */

    // Declare Variables
    double order_amount;
    char shipping_option;

    cout << "Enter the order amount in USD: ";
    cin >> order_amount;

    cout << "Choose the leter for your desired shipping option:" << endl;
    cout << "a) Standard (lowest cost)" << endl;
    cout << "b) Express (2-day delivery)" << endl;
    cout << "c) Overnight (guaranteed 10 AM the next morning)" << endl;
    cin >> shipping_option;

    // TEMP ...
    cout << "Your order amount is $" << order_amount << " and you chose shipping option " << shipping_option << endl;

	return 0;
}