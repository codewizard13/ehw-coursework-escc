/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 0.0

    STATUS: WIP - Writes to output file, but fails to read because of spaces in
        full names.

    Instructions:
    1.  Write two lines to a text file.
    2.  Open the file manually to confirm its contents.
    3.  Read the file back into the program.

    (NOTE: these next two will be implemented in a new file because
       it will radically reorganize the code)

    4.  Handle a missing file with an error message.
    5.  Read several numeric records and calculate a total or average.

    Note:
    - The steps were followed, but the topic and business domain concept
        were created by Eric Hepperle

    Lessons Learned:
    - Lesson learned: Include `<fstream>` and use `std::ofstream` so the compiler recognizes the file-output stream type; use `std::ios::app` when you want to append rather than overwrite.
    
    - getline() is necessary when reading values with space, and/or a different delimiter like `|`

    - Lesson learned: When switching from `>>` to `getline()`, remember `std::ws`: `std::getline(inputFile >> std::ws, line);` removes leftover whitespace, including newlines, before reading the line. Reminder: `ws` skips all leading whitespace and blank lines—omit it when those must be preserved.

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string fileName = "overdue-accounts.txt";

int main() {

    ofstream outputFile(fileName);

    // Write 2 lines to text file
    if (outputFile) {
        
        // Write two lines to out file
        outputFile << "Amelia Johson | $10.00" << endl;
        outputFile << "Larry Holmes | $253.95" << endl;
        cout << "Wrote to output file!\n";

    }

    ifstream inputFile(fileName);
    string name;
    int amountOwed;

    // Read the file and output results to console
    // #GOTCHA: Tried this -- didn't work because the values being read have spaces
    if (inputFile) {
        cout << "Reading from input file ...\n";
        while (inputFile >> name >> amountOwed) {
            cout << "Name: " << name << ", Amount Owed: " << amountOwed << endl;
        }
        inputFile.close();
    }

    return 0;
}


