/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.3 LAB:  Some actual evaluations - taxes
    Student: Eric Hepperle
    Created: 2026-09-10

    VERSION: 1.0

    STATUS: FULLY WORKING & TESTED

    Instructions:
        Write a simple "tax calculator" – it should accept two values: a gross price and a tax rate expressed as a percentage (i.e. a value greater than 0 and, let's be optimistic, less than 100).

        Look at the code below – it only reads two input values and outputs the results, so you need to complete it with a few smart calculations.

        It would be good to verify if the values entered are reasonable (e.g. gross price is greater than zero and tax rate falls into the previously mentioned range).

        Full instructions: ./00_instructions.md

    Lessons Learned:
    - I had to manually figure out the formula for tax value, and the algebra refactoring is the part of the program that took the longest because I did it by hand with pencil and paper so I'd understand it better.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	float grossprice, taxrate, netprice, taxvalue;

	
	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;
	
	// VALIDATE GROSS PRICE
    if (grossprice <= 0.0) {
        cout << "Warning: Gross price must be a postive value greater than zero.\n";
        return 0;
    }

    // VALIDATE TAX RATE
    if (taxrate <= 0.0 || taxrate >= 100.0) {
        cout << "Warning: Tax rate must be greater than zero and less than 100.\n";
        return 0;
    }

    // CALCULATE TAX VALUE
    taxvalue = (grossprice / (1 + (taxrate/100.00))) * (taxrate/100.00);
    netprice = grossprice - taxvalue;
	
    cout << setprecision(4) << fixed;

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	return 0;
}
