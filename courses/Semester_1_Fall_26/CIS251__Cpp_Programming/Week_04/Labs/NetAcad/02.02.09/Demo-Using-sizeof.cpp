/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++

    Student: Eric Hepperle
    Created: 2026-09-18

    VERSION: 1.0

    STATUS: FULLY WORKING

    PURPOSE: Demonstate how to use sizeof() to debug longs, doubles, ints, etc.


    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
#include <limits>
using namespace std;

int main()
{

    cout << "sizeof(unsigned long): "
         << sizeof(unsigned long) << " bytes\n";

    cout << "Maximum unsigned long: "
         << numeric_limits<unsigned long>::max() << '\n';

    return 0;
}
