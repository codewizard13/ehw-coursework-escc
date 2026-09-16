/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.0.3 LAB:  Some actual evaluations - taxes
    Student: Eric Hepperle
    Created: 2026-09-10

    VERSION: 2.0

    STATUS: FULLY WORKING & TESTED

    Instructions:
        Write a simple "tax calculator" – it should accept two values: a gross price and a tax rate expressed as a percentage (i.e. a value greater than 0 and, let's be optimistic, less than 100).

        Look at the code below – it only reads two input values and outputs the results, so you need to complete it with a few smart calculations.

        It would be good to verify if the values entered are reasonable (e.g. gross price is greater than zero and tax rate falls into the previously mentioned range).

        Full instructions: ./00_instructions.md

    NOTE: This is the verbatim suggested answer from the course

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

int main(void) {
    float grossprice, taxrate, netprice, taxvalue;
    
    cout << "Enter a gross price: ";
    cin >> grossprice;
    cout << "Enter a tax rate: ";
    cin >> taxrate;
    
    if(grossprice <= 0.0 || taxrate < 0.0 || taxrate > 100.0) {
        cout << "Input data doesn't look correct - I refuse calculations." << endl;
    } else {
        netprice = grossprice / (1.0 + taxrate / 100.0);
        taxvalue = grossprice - netprice;
        
        cout << fixed << setprecision(4); // Set precision to 4 decimal places
        cout << "Net price: " << netprice << endl;
        cout << "Tax value: " << taxvalue << endl;
    }
    
    return 0;
}
