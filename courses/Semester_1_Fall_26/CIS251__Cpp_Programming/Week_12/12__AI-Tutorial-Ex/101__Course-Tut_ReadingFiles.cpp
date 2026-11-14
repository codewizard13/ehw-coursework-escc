/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** READING AI TUTORIAL EXERCISE ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 1.01

    STATUS: Fully Working

    Purpose:
    - Demonstrate reading files in C++

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <fstream>
using namespace std;

ifstream inputFile("scores.txt");

int main()
{

    string name;
    int score;

    if (inputFile) {
        while (inputFile >> name >> score) {
            cout << name << ": " << score << endl;
        }
        inputFile.close();
    }

    return 0;
}
