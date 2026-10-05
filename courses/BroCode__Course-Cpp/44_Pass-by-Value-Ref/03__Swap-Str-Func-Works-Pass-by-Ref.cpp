/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=jegOn22J6TWCxAYR&t=14569

    **** PASS BY VALUE VS PASS BY REFERENCE ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates swapping two string variables using a custom function
    - Demonstrates changing original values with pass-by-reference
    - Demonstrates using address-of operator

    📝 Lessons Learned:
    - To change ORIGINAL value (not a copy), use pass-by-value
    - #TIP: Use PASS-BY-REFERENCE as often as possible, unlesss you have a good reason to pass-by-value

    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

void swap_str(string &x, string &y);

int main() {

    string x = "Kool-Aid";
    string y = "Water";


    cout << "******************************\n";
    cout << "Starting Values: X = " << x << "  Y = " << y << '\n';

    swap_str(x, y);

    cout << "After Swap: X = " << x << "  Y = " << y << '\n';
    cout << "******************************\n";    

    return 0;
}

void swap_str(string &x, string &y) {
    string temp;
    temp = x;
    x = y;
    y = temp;
}