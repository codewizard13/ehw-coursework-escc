/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=nLkDotVenv-gXXz_&t=14438

    **** PASS BY VALUE VS PASS BY REFERENCE ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates swapping two string variables

    📝 Lessons Learned:
    - Swap works by using a temp var

    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    string x = "Kool-Aid";
    string y = "Water";

    string temp;

    cout << "******************************\n";
    cout << "Starting Values: X = " << x << "  Y = " << y << '\n';

    temp = x;
    x = y;
    y = temp;

    cout << "After Swap: X = " << x << "  Y = " << y << '\n';
    cout << "******************************\n";    

    return 0;
}