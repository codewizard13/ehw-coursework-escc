/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** READING AI TUTORIAL EXERCISE ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrate writing files in C++

    Lessons Learned:
    - ofstream can be declared / initialized in the global space,
        but the if conditional and any other decision-making logic
        needs to be encapsulated in some function or module/class/
        enum, etc.
    - #GOTCHA: Declaring ofstream object without the std:: prefix,
        or having `using namespace std` results in 

        `error: 'ofstream' does not name a type`

    - #GOTCHA: Not encapsulating the ofstream decision logic in
        main() results in

        `error: 'ofstream' was not declared in this scope; did you mean 'std::ofstream'?`

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
