/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    3.0.8 LAB:  Exceptions: input validation

    Student: Eric Hepperle
    Created: 2026-11-10

    VERSION: 1.0

    STATUS: WIP

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
using namespace std;
const int DivideByZero = 111;
int main(void)
{
    int a = 8, b = 0, c = 0;
    cin >> b;
    try
    {
        if (b == 0)
        {
            throw DivideByZero;
        }
        c = a / b;
    }
    catch (int ex)
    {
        if (ex == DivideByZero)
            cout << "Your input is not valid, you can't divide by zero." << endl;
    }

    cout << c << endl;
    return 0;
}