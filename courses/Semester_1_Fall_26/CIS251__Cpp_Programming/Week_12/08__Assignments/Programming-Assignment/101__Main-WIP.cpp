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
bool getYesNo(string prompt, string &answer);

int main()
{
  cout << "******** START PROGRAM *****************************************\n";

  // Filename Variables
  string outputFilename = "contacts-list.txt";
  string backupFilename = "bkp_contacts.txt";

  // Stream Variables
  ifstream iFile;
  ofstream oFile;

  string answer;

  // Let user choose whether to reset the contact-list.txt file or continue
  //   with the existing data.
  if (!getYesNo("Clear existing contacts before testing (y, n):", answer)) {
    cerr << "Error: Could not read your response\n";
    return 1;
  }

  if (answer == "y")
  {
    cout << "Clearing/deleting the contents of " << outputFilename << " to start fresh." << endl;
    oFile.open(outputFilename);
  }
  else
  {
    // Open output file in append mode to prevent overwriting existing records
    oFile.open(outputFilename, ios::app);
  }

  if (!oFile)
  {
    cerr << "Error: File " << outputFilename
         << " could not be opened for writing.\n";
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
  cout << "... Reading " << outputFilename << ": " << endl;

 iFile.open(outputFilename);

  if (!readFile(iFile, outputFilename))
  {
    iFile.close();
    return 1;
  }

  iFile.close();

  // TEST 3: Attempt to write a single record in append mode, without
  //   resetting / opening the file for write (remember we closed
  //   oFile earlier).
  //
  // Expect: Errors for outfile not open and file couldnt be opened
  //   for reading.
  cout << "\n============ TEST CASE: 3 ============\n";
  cout << "... This test expects several failures: " << endl;
  writeRecord(oFile, "James Brown", "funkfather@gmail.com");

  readFile(iFile, outputFilename);

  // TEST 4: Write a single record - it should append to the end and not
  //    blank out the existing records.
  cout << "\n============ TEST CASE: 4 ============\n";
  cout << "This test appends a single record to the end of the existing list,\n";
  cout << " demonstating data persistence.\n";
  oFile.open(outputFilename, ios::app);

  writeRecord(oFile, "James Brown", "funkfather@gmail.com");
  oFile.close();

  // Q: Do I have to close oFile here before I can open iFiel? NOPE!

  iFile.open(outputFilename);
  readFile(iFile, outputFilename);
  iFile.close();

  // TEST 5: Clone the output file using binary mode and rdbuf()
  cout << "\n============ TEST CASE: 5 ============\n";
  cout << "Cloning " << outputFilename << " to " << backupFilename << endl;

  iFile.open(outputFilename, ios::binary);
  ofstream dest(backupFilename, ios::binary);

  // Copy entire stream buffer in one line
  dest << iFile.rdbuf();
  dest.close();
  iFile.close();

  // TEST 6: Make the file blank to reset for next run
  cout << "\n============ TEST CASE: 6 ============\n";

  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}

bool writeRecord(ofstream &file, string fullName, string email)
{
  if (!file.is_open())
  {
    cerr << "Error: Output file could not be opened.\n";
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

  if (!file.is_open())
  {
    cerr << "Error: Input file " << filename
         << " is not open.\n";
    return false;
  }

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

  return true;
}

bool getYesNo(string prompt, string &answer)
{
    cout << prompt;

    while (cin >> answer)
    {
        if (answer == "y" || answer == "n")
        {
            return true;
        }

        cerr << "Please enter y or n: ";
    }

    return false;
}