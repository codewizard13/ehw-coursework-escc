/**
 * @brief Persistent Contact List — Week 12 C++ programming assignment:
 *        Files, Streams, Persistence, and Program Testing.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 12 Programming Assignment
 * @lesson_focus Files, Streams, Persistence, and Program Testing
 *
 * @instructions Persistent Contact List: write several contact records to a
 *    text file and read them back for display. Check that the file opened
 *    successfully and submit a five-case test table covering normal and
 *    failure-oriented cases already demonstrated in the readings.
 *
 * @status WIP
 *
 * @author Eric L. Hepperle
 * @date 2026-11-15
 * @updated --
 * @version 1.01
 *
 * @see https://github.com/codewizard13
 */

/*
ALGORITHM — CONTACT LIST

Set the output and input filenames.

Open the output file.
If opening fails:
    Display an output-opening error.
    Return failure.

Write the contact records.
Close the output file.
If writing or closing failed:
    Display an output error.
    Return failure.

Open the input file.
If opening fails:
    Display an input-opening error.
    Return failure.

While a comma-delimited name and its email can be read:
    Display the name and email.

Close the input file.
Return success.

*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool writeRecord(ofstream &file, string fullName, string email);
bool readFile(ifstream &file, string filename);

int main()
{
  cout << "******** START PROGRAM *****************************************\n";

  string outputFilename = "contacts-list.txt";

  // Open output file in append mode to prevent overwriting existing records
  ofstream oFile(outputFilename, ios::app);

  if (!oFile)
  {
    cerr << "Error: File " << outputFilename
         << " could not be written or closed successfully.\n";
    return 1;
  }

  // TEST 1: Write 3 records to outfile
  cout << "\n============ TEST CASE: 1 ============\n";

  writeRecord(oFile, "Michael Jackson", "mjackson@gmail.com");
  writeRecord(oFile, "Scottie Pippin", "greatscott91@yahoo.com");
  writeRecord(oFile, "Janet Jackson", "imjanet@aol.com");

  oFile.close();

  // TEST 2: Print the contacts from the file to the console
  cout << "\n============ TEST CASE: 2 ============\n";

  ifstream iFile(outputFilename);

  readFile(iFile, outputFilename);

  iFile.close();

  // TEST 3: Write a single record - it should append to the end and not
  //    blank out the existing records.
  cout << "\n============ TEST CASE: 3 ============\n";

  writeRecord(oFile, "James Brown", "funkfather@gmail.com");

  readFile(iFile, outputFilename);

  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}

bool writeRecord(ofstream &file, string fullName, string email)
{
    if (!file.is_open())
    {
        cerr << "Error: Output file is not open.\n";
        return false;
    }

    if (!file)
    {
        cerr << "Error: Output stream is in a failure state.\n";
        return false;
    }

    file << fullName << ", " << email << endl;

    if (!file)
    {
        cerr << "Error: Contact could not be written.\n";
        return false;
    }

    cout << "... wrote record for: " << fullName << endl;

    return true;
}

bool readFile(ifstream &file, string filename = "")
{
  // Check whether the stream reports any failures.
  if (!file)
  {
    cerr << "Error: File " << filename
         << " could not be opened for reading.\n";
    return false;
  }

  string fullName;
  string email;

  while (getline(file, fullName, ',') &&
         getline(file, email))
  {
    cout << "Name: " << fullName << " | Email: " << email << endl;
  }

  file.close();

  return true;
}
