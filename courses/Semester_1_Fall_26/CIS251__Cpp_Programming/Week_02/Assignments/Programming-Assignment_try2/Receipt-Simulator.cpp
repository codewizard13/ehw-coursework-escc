/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    (TRY 2)

    WEEK 2 PROGRAMMING ASSIGNMENT — Data Types, Constants, Operators, Expressions, and Numeric Calculations
    Student: Eric Hepperle
    Created: 2026-08-30
    Updated: 2026-09-01

    Instructions:
    Write a console program that asks the user for a product name, quantity, and unit price. Store a tax rate in a const double. Calculate subtotal, tax amount, and final total. Display a clearly labeled receipt-style summary.

    Notes:
    - Based on instructor feedback (see try 1), this version ensures 2-digit decimal precision,
      and consistent 10% tax rate for testing. 
    - Previous rationale comments have been removed from this version for code hygeine.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	
    // Declare Variables
    string product_name = "";
    int quantity;
    double unit_price;

    const double TAX_RATE = 0.10;

    cout << setprecision(2) << fixed;

    cout << "\n" << "****************************" << "\n";
    cout << "Welcome to Eric Hepperle's Product Purchase Simulator!" << "\n\n";
    cout << "Please enter a product name: ";
    getline(cin, product_name);

    cout << "Enter the unit price: $";
    cin >> unit_price;

    cout << "Enter the quantity: ";
    cin >> quantity;
    cout << "\n";

    double item_total_price = unit_price * quantity;
    double subtotal = item_total_price;

    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;

    // Final receipt printout
    cout << product_name << "\tQTY " << quantity << "\t$" << item_total_price << "\n\n";
    cout << "SUBTOTAL:\t$" << subtotal << endl;
    cout << "SALES TAX:\t$" << tax << endl;
    cout << "TOTAL:\t\t$" << total << endl;

    cout << endl;

	return 0;
}