/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 3 PROGRAMMING ASSIGNMENT — Decision Structures and Boolean Logic - TRY 2
    Student: Eric Hepperle
    Created: 2026-09-05
    Updated: 2026-09-09

    Instructions:
    Shipping Charge Decision Program: ask for an order amount and shipping option, use if/else and/or switch to select the correct charge from a supplied decision table, and print the final amount. Include boundary tests for every branch.

    NOTE this version includes the following updates based on instructor feedback:
    - Adds input validation that rejects zero, negative numbers, and non-numeric input
    - Expanded, more detailed algorithm showing decision making and validation process

    CHALLENGES:
    - I had to determine how to test for not a number without using fancy functions we've not learned yet. I used Perplexity to help me brainstorm this structure: `if (!(cin >> x))`

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
            If order amount is negative, zero, or non-numeric reject it with error message and end program.
        
        Display shipping option menu
        Get shipping option ( standard, express, overnight) from user
            If NOT EXACT a, b, or c chars, then display error msg and end program

        Calculate final amout
        
        Print final amount     
    */

    // DECLARE VARIABLES
    double order_amount, shipping_amount, final_amount;
    char shipping_option;
    bool valid_shipping_choice = true;

    // Ensure dollar values display rounded to 2 decimal places
    cout << setprecision(2) << fixed;

    cout << endl;

    // GET ORDER AMOUNT FROM USER
    cout << "Enter the order amount in USD: $";
    
    // VALIDATE ORDER AMOUNT IS A NUMBER
    if (!(cin >> order_amount)) {
        cout << "Order amount cannot be non-numeric.\n\n";
        return 0;
    }

    // VALIDATE THAT ORDER AMOUNT IS GREATER THAN ZERO
    if (!(order_amount > 0)) {
        cout << "Invalid input: order amount must be a positive number (no negatives, no zero).\n\n";
        return 0;
    }

    cout << endl;

    // DISPLAY SHIPPING OPTIONS TABLE
    cout << "**** Shipping Rates ****\n\n";
    cout << "a) Standard\t$5 (7-10 day, lowest cost)" << endl;
    cout << "b) Express\t$30 (2-day delivery)" << endl;
    cout << "c) Overnight\t$120 (guaranteed 10 AM the next morning)" << endl;
    cout << endl;

    // GET ORDER OPTION FROM USER
    cout << "Choose the letter for your desired shipping option: ";
    cin >> shipping_option;
    cout << endl;

    // VALIDATE ORDER OPTION
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


    // CALCULATE FINAL AMOUNT IF SHIPPING CHOICE VALID
    if (valid_shipping_choice) {
        
        // cout << "Your order amount is $" << order_amount << " and you chose shipping option \"" << shipping_option << "\"" << "\n\n";
        
        final_amount = order_amount + shipping_amount;
        cout << "Final Amount: $" << final_amount << endl;

    }

    cout << "*******************\n\n";

	return 0;
}