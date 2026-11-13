/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12
    Updated: 2026-11-13

    VERSION: 0.03

    STATUS: WIP - Read numeric records from a file and calculate total and avg.

    Instructions:
    (continuing from previous version)
    5.  Read several numeric records and calculate a total or average.

    Note:
    - The steps were followed, but the topic and business domain concept
        were created by Eric Hepperle

    - While the previous versions 0-2 were cumulative, for instruction 5 I'm
        actually testing myself and writing a whole program from scratch.

    Lessons Learned:
    - When switching from `>>` to `getline()`, remember `std::ws`: `std::getline(inputFile >> std::ws, line);` removes leftover whitespace, including newlines, before reading the line. Reminder: `ws` skips all leading whitespace and blank lines—omit it when those must be preserved.

    - The programmer should distinguish file existence from stream-opening success: `ofstream` can create a missing file before an `if` checks its state, and its default opening mode erases existing contents. An initial `ifstream` check avoids creating the file, while `ios::app` protects existing contents when opening for output.

    - The programmer can test file-opening failure by specifying a nonexistent parent folder; a missing filename alone does not trigger failure because `ofstream` can create the file.

    - Single quotes represent a character (`'Y'`), while double quotes represent a string literal (`"Y"`). Character-conversion functions such as `tolower()` require an individual character value rather than a string.

    GitHub: https://github.com/codewizard13
 ************************************************************ */

/*
**** ALGORITHM ****

IF file doesn't exist,
    CREATE OUTPUT STREAM FILE: filename = "payment-records.txt"

WRITE VALUES TO OUTPUT STREAM

    DO UNTIL choice = lower("N")

        Ask user to input a name (full name, spaces allowed)
            Display error if name is not a string and end program

        Ask user to input a dollar amount (without the $ sign or punctuation)
            Display error if payment is not a number or has punctuation

        Ask user if they want to enter another record


    ... MORE TO COME ...


*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

string recordsFilename = "payment-records.txt";
string missingFilename = "apples/missing-file.txt";

int main()
{

    // Define filename where existing records should exist as a read stream
    ifstream existingRecords(recordsFilename);

    // Try to open file for read -- if that fails, give an error that the file couldn't be found
    if (!existingRecords)
    {
        cout << "\nFile " << recordsFilename
             << " could not be opened for reading, or may not exist.\n"
             << "... attempting to create it ...\n\n";

        // Create file as ofstream with append to prevent erasing entire file.
        // - Append mode preserves existing contents if file exists.
        ofstream recordsFile(recordsFilename, ios::app);

        // Creat missing file by adding a nonexistent parent folder path
        //  for testing.
        ofstream missingFile(missingFilename);

        // Print an error if we can't open or create the file and exit program
        if (!recordsFile)
        {
            cerr << "Could not open or create "
                 << recordsFilename << endl;
            return 1;
        }

        // Otherwise, print success message
        cout << "File " << recordsFilename << " opened or created sucessfully.\n"
             << "Ready for writing in append mode.\n\n";
    }

    string line;

    // Otherwise records file exists, so lets do something with it
    // first, let's read the current contents, line by line
    while (getline(existingRecords, line))
    {
        cout << line << endl;
    }
    cout << "- - - Reached End of file.\n";

    char choice = 'y';
    int count = 0;

    /* WRITE TO OUT FILE */
    do
    {
        count++;
        cout << "Ran do loop " << count << " times.\n";
        cout << "Add another? (y, n): ";

        if (!(cin >> choice))
        {
            cout << "Please enter either 'y' or 'n'.\n";
        }

    } while (tolower(choice) != 'n');

    cout << "*********** End Program ************\n\n";

    return 0;
}