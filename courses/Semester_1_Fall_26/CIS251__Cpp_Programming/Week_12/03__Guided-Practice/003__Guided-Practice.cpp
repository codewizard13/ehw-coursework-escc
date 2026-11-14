/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12
    Updated: 2026-11-14

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

    Lessons Learned: ./03__lessons-learned.md


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

bool openFileForRead(string filename, ifstream &file);
bool readFileLineByLine(ifstream &file);
bool addRecord(string full_name, double amount, ofstream &file);

string recordsFilename = "payment-records.txt";
string missingFilename = "apples/missing-file.txt";

/* DEFINE STREAMS */
// Define filename where existing records should exist as a read stream
ifstream existingRecords(recordsFilename);

// Create file as ofstream with append to prevent erasing entire file.
// - Append mode preserves existing contents if file exists.
ofstream recordsFile(recordsFilename, ios::app);

// Creat missing file by adding a nonexistent parent folder path
//  for testing.
ofstream missingFile(missingFilename);

int main()
{

    cout << "\n******** START PROGRAM *****************************************\n";

    openFileForRead(recordsFilename, existingRecords);

    string line;

    // Otherwise records file exists, so lets do something with it
    // first, let's read the current contents, line by line
    cout << "File " << recordsFilename << " opened sucessfully.\n";

    cout << "\n======== READING existing records line by line ====\n";

    readFileLineByLine(existingRecords);

    string choice;
    int count = 1;

    cout << "  - Iteration number: " << count << endl;

    do
    {
        cout << "Add another? (y, n): ";

        if (!getline(cin, choice))
        {
            break; // Exit if input cannot be read.
        }

        // Only increment record count if choice was yes
        if (choice == "y" || choice == "Y")
        {
            cout << "Yes selected. Looping again.\n";
            count++;
            cout << "  - Iteration number: " << count << endl;

            // ADD THE RECORD
            addRecord("Appleby Johsnon", 42.50, recordsFile);
        }
        else if (choice != "n" && choice != "N")
        {
            cout << "Invalid choice. Please enter y or n.\n";
        }

    } while (choice != "n" && choice != "N");

    cout << "You chose No and the program ended\n";

    cout << "\n******** END PROGRAM *******************************************\n";

    return 0;
}

bool openFileForRead(string filename, ifstream &file)
{

    // Try to open file for read -- if that fails, give an error that the file couldn't be found
    if (!file)
    {
        cout << "\nFile " << filename
             << " could not be opened for reading, or may not exist.\n"
             << "... attempting to create it ...\n\n";

        // Print an error if we can't open or create the file and exit program
        if (!recordsFile)
        {
            cerr << "Could not open or create "
                 << filename << endl;
            return false;
        }

        // Otherwise, print success message
        cout << "File " << filename << " opened or created sucessfully.\n"
             << "Ready for writing in append mode.\n\n";
    }

    return true;
}

bool readFileLineByLine(ifstream &file)
{

    string line;

    while (getline(existingRecords, line))
    {
        cout << line << endl;
    }
    cout << "\nDone reading file.\n";

    return true;
}

bool addRecord(string full_name, double amount, ofstream &file)
{
    cout << "Adding new record ...\n";

    file << "\n"
         << full_name << " | " << amount << endl;

    return true;
}
