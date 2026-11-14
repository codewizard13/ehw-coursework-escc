/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 12: Files, Streams, Persistence, and Program Testing

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12
    Updated: 2026-11-14

    VERSION: 0.04

    STATUS: WIP - Display existing payment records and append test
            records. Interactive record entry, numeric validation,
            and total/average calculations remain unfinished.

    Instructions:
    (continuing from previous version)
    5. Read several numeric records and calculate a total or average.

    Project:
    - Develop a payment-record program using payment-records.txt.
    - Store records in the format: full name | payment amount.
    - Preserve existing records when appending new entries.

    Current Progress:
    - Define function prototypes and separate helper functions for
      checking read availability, displaying records, and appending.
    - Attempt to open existing records for input.
    - Open an output stream in append mode.
    - Display existing file contents line by line.
    - Validate complete y/n responses using getline().
    - Append a hard-coded name and payment amount when Yes is selected.
    - Define a separate output stream with a nonexistent parent folder
      for file-opening failure tests.

    Known Limitations:
    - openFileForRead() checks stream state but does not open or reopen
      the input stream after the output stream creates a missing file.
    - main() does not check helper-function return values.
    - readFileLineByLine() uses the global existingRecords stream
      instead of its file parameter.
    - addRecord() inserts an unconditional leading newline, which can
      create unwanted blank lines, and always returns true without
      checking whether writing succeeded.
    - The missing-folder test stream is not checked.
    - Success and exit messages do not always reflect actual outcomes.
    - The displayed count tracks affirmative choices, not verified
      records written.

    Next Steps:
    - Collect a full name and validate a numeric payment amount.
    - Correct file-opening recovery and propagate failure results.
    - Use the supplied stream parameters consistently.
    - Separate appended records without adding unwanted blank lines.
    - Read payment amounts and calculate a total and average.

    Notes:
    - The exercise follows the assigned steps; the payment-record
      business domain was created by Eric Hepperle.
    - Versions 0.00-0.02 were cumulative. Work on instruction 5 began
      as a separate program written from scratch for practice.

    Lessons Learned: ./03__lessons-learned.md

    GitHub: https://github.com/codewizard13
 ************************************************************ */

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
