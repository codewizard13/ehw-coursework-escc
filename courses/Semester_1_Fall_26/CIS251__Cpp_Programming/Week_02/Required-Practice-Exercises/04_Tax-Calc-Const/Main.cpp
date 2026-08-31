/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Guided Practice: Week 2, #4: Build a subtotal, tax, and total calculation using a named constant.
    
    Student: Eric Hepperle
    Created: 2026-08-30

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	
    const double TAX_RATE = 0.09;

    double subtotal;
    cout << "Enter your subtotal and I will return your total: ";
    cin >> subtotal;
    
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;

    cout << "**** At a tax rate of " << TAX_RATE << " ****" << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << total << endl;

	return 0;
}