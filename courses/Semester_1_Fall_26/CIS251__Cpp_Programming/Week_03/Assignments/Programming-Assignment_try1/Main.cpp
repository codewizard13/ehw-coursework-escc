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
#include <iomanip>
using namespace std;

int main(void) {

    /*
        ALGORITHM:

        Get order amount from user
        Get shipping option ( standard, express, overnight) from user
        Print final amount     

    
    */

    // Declare Variables
    double order_amount, shipping_amount, final_amount;
    char shipping_option;
    bool valid_shipping_choice = true;

    // Ensure dollar values display rounded to 2 decimal places
    cout << setprecision(2) << fixed;

    cout << endl;

    cout << "Enter the order amount in USD: $";
    cin >> order_amount;
    cout << endl;

    cout << "**** Shipping Rates ****\n\n";
    cout << "a) Standard\t$5 (7-10 day, lowest cost)" << endl;
    cout << "b) Express\t$30 (2-day delivery)" << endl;
    cout << "c) Overnight\t$120 (guaranteed 10 AM the next morning)" << endl;
    cout << endl;

    cout << "Choose the letter for your desired shipping option: ";
    cin >> shipping_option;
    cout << endl;

    switch (shipping_option) {
        case 'a':
            // Standard shipping is $5
            shipping_amount = 5.00;
            break;
        case 'b':
            // Express is $30
            shipping_amount = 30.00;
            break;
        case 'c':
            // Overnight is $120
            shipping_amount = 120.00;
            break;
        default:
            cout << "You have entered an invalid choice: Please select a, b, or c" << endl;
            valid_shipping_choice = false;
    }

    // Only calculate & display final amount if shipping choice is valid
    // NOTE: The next step here would be loop the program until a
    //      valid choice is entered, and possibly an option to cancel/abort,
    //      but we've not covered loops yet.
    if (valid_shipping_choice) {
        
        // cout << "Your order amount is $" << order_amount << " and you chose shipping option \"" << shipping_option << "\"" << "\n\n";
        
        final_amount = order_amount + shipping_amount;
        cout << "Final Amount: $" << final_amount << endl;

    }

    cout << "*******************\n\n";


	return 0;
}