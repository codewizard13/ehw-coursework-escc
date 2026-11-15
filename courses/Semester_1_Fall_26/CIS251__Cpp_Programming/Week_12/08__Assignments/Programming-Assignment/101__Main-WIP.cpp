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

  string outputFilename = "records.txt";

  ofstream oFile(outputFilename);

  if (!oFile)
  {
    cerr << "Error: File " << outputFilename
         << " could not be written or closed successfully.\n";
    return 1;
  }

  oFile << "Michael Jackson, mjackson@gmail.com" << endl;
  oFile << "Scottie Pippin, greatscott91@yahoo.com" << endl;

  writeRecord(oFile, "Janet Jackson", "imjanet@aol.com");

  oFile.close();

  ifstream iFile(outputFilename);

  readFile(iFile, outputFilename);

  return 0;
}

bool writeRecord(ofstream &file, string fullName, string email)
{
  file << fullName << ", " << email << endl;
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
