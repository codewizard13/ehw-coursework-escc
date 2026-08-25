/*
    DATA TYPES

    - integer (int):   whole numbers; no decimals; ex: age, year
    - double (double):  decimal; double floating-point precision; ex; price; 64-bits of precision; doubles are more accurate than floats
    - float (float): decimal with 32-bit precision
    - character (char): 1 character; ex: letter, symbol
    - string (string): 1 or more characters; ex: name, sentence
    - boolean (bool): true or false; ex: on/of, yes/no

    - Use descriptive variable names

    - #GOTCHA: Always put char value within in single quotes!
    - #GOTCHA: Strings always double quotes!
    - #GOTCHA: Always save your .cpp before running -- besides potential data loss, you will look at your correct code on screen and wonder why it's still giving you old results -- because you have to save the code to be able to run the latest version

    - Can use `+` to concatenate strings

*/

#include <iostream>
using namespace std;

int main()
{
    int year = 2020;
    double price = 9999.99;
    char status = 'N';
    string make = "Ford";
    string model = "Mustang";
    bool for_sale = true;

    for_sale = false;

    // 10% discount applied
    price = price * 0.9;

    string car = make + " " + model;

    cout << "Year: " << year << endl;
    cout << "Price: " << price << endl;
    cout << "New/Used: " << status << endl;
    cout << "Car: " << car << endl;
    cout << "Availability: " << for_sale << endl;

    return 0;
}