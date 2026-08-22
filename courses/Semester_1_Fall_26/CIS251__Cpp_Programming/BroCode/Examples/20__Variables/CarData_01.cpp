/*
    DATA TYPES

    - integer (int):   whole numbers; no decimals; ex: age, year
    - double (double):  decimal; double floating-point precision; ex; price
    - character (char): 1 character; ex: letter, symbol
    - string (string): 1 or more characters; ex: name, sentence
    - boolean (bool): true or false; ex: on/of, yes/no

    - Use descriptive variable names

    - #GOTCHA: Always put char value within in single quotes!
    - #GOTCHA: Strings always double quotes!

*/

#include <iostream>
using namespace std;

int main()
{
    int year = 2020;
    double price = 9999.99;
    char status = 'N';
    string model = "Mustang";
    bool for_sale = true;

    cout << year << endl;
    cout << price << endl;
    cout << status << endl;
    cout << model << endl;
    cout << for_sale << endl;

    return 0;
}