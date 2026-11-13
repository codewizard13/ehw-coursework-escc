/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 0.01

    STATUS: WIP - Reads file one line at a time and parses delimiters (1-3 complete).
        NEXT: Implement 4 and 5.

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
    - `getline(stream >> ws, destination)` still requires a string destination; **`ws`** skips leading whitespace—it does not convert text to a number. It also skips blank lines, so use it only when that is intended.

    - `clear()` resets stream flags, `seekg()` repositions an open stream, and `open()` opens a file. You cannot rewind a closed file without reopening it. Your existing `ws` usage can stay—it skips the space after `|` before reading the amount.

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string fileName = "overdue-accounts.txt";

int main()
{

    ofstream outputFile(fileName);

    // Write 2 lines to text file
    if (outputFile)
    {

        // Write two lines to out file
        outputFile << "Amelia Johson | $10.00" << endl;
        outputFile << "Larry Holmes | $253.95" << endl;
        cout << "Wrote to output file!\n";
    }

    ifstream inputFile(fileName);
    string name;
    string line;
    string amountOwed;

    // Read file one line at a time

    if (inputFile)
    {
        cout << "Reading from input file ...\n";

        while (getline(inputFile, line))
        {
            cout << line << endl;
        }
        // inputFile.close();
    }

    // Reset the file for a second pass
    inputFile.clear();
    inputFile.seekg(0);


    // Read file one line at a time with parsing by delimiter

    if (inputFile)
    {
        cout << "\nReading with delimiter parsing ...\n";

        while (getline(inputFile, name, '|') &&
               getline(inputFile >> ws, amountOwed))
        {

            // Remove space before the | in file format
            if (!name.empty() && name.back() == ' ')
            {
                name.pop_back();
            }

            cout << "Name: " << name << ", Amount Owed: " << amountOwed << endl;
        }

        inputFile.close();
    }

    return 0;
}
