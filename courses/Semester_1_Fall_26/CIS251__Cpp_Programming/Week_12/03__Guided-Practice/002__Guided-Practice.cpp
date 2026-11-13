/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 0.02

    STATUS: WIP - Displays error message and stops program if inputFile2 is
        not found.  NEXT: Read numeric records from a file and calculate
        total or average.

    Instructions:
    (continuing from previous version)
    4.  Handle a missing file with an error message.
    5.  Read several numeric records and calculate a total or average.

    Note:
    - The steps were followed, but the topic and business domain concept
        were created by Eric Hepperle

    Lessons Learned:
    -

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
        cout << "\n**** Writing 2 lines of text to a file ****\n";

        // Write two lines to out file
        outputFile << "Amelia Johson | $10.00" << endl;
        outputFile << "Larry Holmes | $253.95" << endl;
        cout << "Wrote to output file " << fileName << "!\n";
    }

    ifstream inputFile(fileName);
    string name;
    string line;
    string amountOwed;

    // Read file one line at a time

    if (inputFile)
    {
        cout << "\n**** Reading from input file, one line at a time ****\n";

        cout << "Reading from input file ...\n";

        while (getline(inputFile, line))
        {
            cout << line << endl;
        }
        // inputFile.close();
    }

    // Reset the file for a second pass
    cout << "\n**** Resetting the file for a second pass ****\n";

    inputFile.clear();
    inputFile.seekg(0);

    // Temporarily select missing input file for testing
    cout << "\n**** Testing error display when input file not found ****\n";

    string fileName2 = "missing-file.txt";
    ifstream inputFile2(fileName2);

    // Handle error if file can't be found
    if (!inputFile2)
    {
        cout << "File not found: " << fileName2 << endl;
        inputFile2.close();
        // return 1;
    }

    // Read file one line at a time with parsing by delimiter

    if (inputFile)
    {
        cout << "\n**** Reading inputFile with delimiter parsing ****\n";

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
