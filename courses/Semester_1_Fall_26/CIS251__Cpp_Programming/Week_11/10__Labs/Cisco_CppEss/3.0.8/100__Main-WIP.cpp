/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    3.0.8 LAB:  Exceptions: input validation

    Student: Eric Hepperle
    Created: 2026-11-10

    VERSION: 1.0

    STATUS: WIP - Throws / Catches custom divide by zero exception;
                But sample solution uses `const int DivideByZero = 111`

    Instructions:
     - Improve this simple program so that it prints a message when the user
       inputs invalid data. Add code to throw the exception manually using the
       throw keyword when a user inputs 0.

    - Full instructions: ../../../../_Notes/Cisco_Netacad_CppEss2/Module_03/3.0.8_lab.md

    Sample Output:

    ...

    Lessons Learned & Notes:
    -

    FUTURE IMPROVEMENTS:
    -

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <string>
using namespace std;

int divTwoNums(int a, int b)
{
    if (b == 0)
        throw string("division by zero not allowed");
    return a / b;
}

int main(void)
{

    cout << "****************** LAB START *************\n";

    int a = 8, b = 0, c = 0;
    cin >> b;
    try
    {
        c = divTwoNums(a, b);
        cout << c << endl;
    }
    catch (string problem)
    {
        cout << "Exception caught: " << problem << endl;
    }

    cout << "****************** LAB END ***************\n";

    return 0;
}