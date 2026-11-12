/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** READING AI TUTORIAL EXERCISE ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 1.01

    STATUS: WIP

    Purpose:
    - Demonstrate reading files in C++

    Lessons Learned:
    - 

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <fstream>
using namespace std;

ofstream outputFile("scores.txt");

int main()
{

    if (outputFile)
    {
        outputFile << "Jordan 92" << endl;
        outputFile << "Taylor 88" << endl;
        outputFile.close();
    }

    return 0;
}
