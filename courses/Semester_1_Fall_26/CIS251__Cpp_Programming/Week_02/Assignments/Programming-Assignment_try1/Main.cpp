/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 2 PROGRAMMING ASSIGNMENT — Data Types, Constants, Operators, Expressions, and Numeric Calculations
    Student: Eric Hepperle
    Created: 2026-08-30

    Instructions:
    Write a console program that asks the user for a product name, quantity, and unit price. Store a tax rate in a const double. Calculate subtotal, tax amount, and final total. Display a clearly labeled receipt-style summary.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	
    // Declare Variables
    string product_name = "";
    int quantity;
    double unit_price;

    const double TAX_RATE = 0.10;

    /*
    OUTPUT DESIGN: #GOTCHA: This was the design I was going for, but we haven't
     learned sprintf and those type of string formatting constructions yet, so
     I opted for a simpler output format.

     #GOTCHA: Another thing that tripped me up was as soon as the product name cin
     saw a space it puked and jumped right to the last line execution. But, then
     I remembered we learned the getline() function in week 1 that handles spaces.

     Also, I examined many supermarket receipts and they often omit the dollar
     sign, but I added it for clarity in this assignment.

    *** Hepperle Market ***

        CUSTOMER RECEIPT

    Item                                QTY        PRICE 
    Pampers Baby Dry Jumbo Diapers      1          23.99
    Tropicana Orange Juice, Pulp        2          9.98


    SUBTOTAL:                                      112.97
    SALES TAX:                                      11.39
    TOTAL:                                         124.36
    
    */

    cout << "Welcome to Eric Hepperle's Product Purchase Simulator!" << "\n\n";
    cout << "Please enter a product name: ";
    // cin >> product_name;
    getline(cin, product_name);

    cout << "Enter the unit price: $";
    cin >> unit_price;

    cout << "Enter the quantity: ";
    cin >> quantity;
    cout << "\n";

    // #IDEA: A future improvement to the program would be a loop to allow
    // the user to keep adding line items until a certian stop signal,
    // like "No". The "item_total_price" is the line item total, and the loop
    // would sum all the line item totals for a final "subtotal".
    //
    // For now, I'm copying the item_total_price into subtotal for convenience,
    // since this assignment only allows a single item.
    //
    double item_total_price = unit_price * quantity;
    double subtotal = item_total_price;

    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;


    cout << product_name << "\tQTY " << quantity << "\t$" << item_total_price << "\n\n";
    cout << "SUBTOTAL:\t$" << subtotal << endl;
    cout << "SALES TAX:\t$" << tax << endl;
    cout << "TOTAL:\t\t$" << total << endl;


	return 0;
}