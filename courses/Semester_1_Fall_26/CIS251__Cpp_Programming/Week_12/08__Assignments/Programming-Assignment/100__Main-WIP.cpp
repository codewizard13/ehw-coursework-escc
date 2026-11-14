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
 * @date 2026-11-14
 * @updated --
 * @version 1.0
 *
 * @see https://github.com/codewizard13
 */

/*
ALGORITHM

Set the contact filename.

Open the file for writing.
If opening fails:
    Display an error.
    End with failure status.

Write five contact records.
Close the output file.

Open the same file for reading.
If opening fails:
    Display an error.
    End with failure status.

While both a comma-delimited name and the remaining email can be read:
    Display the name and email.

End with success status.

*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{

  // Filename variables
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

  oFile.close();

  ifstream iFile(outputFilename);

  if (!iFile)
  {
    cerr << "Error: File " << outputFilename
         << " could not be opened for reading.\n";
    return 1;
  }

  string fullName;
  string email;

  while ( getline(iFile, fullName, ',') &&
          getline(iFile, email))
  {
    cout << "Name: " << fullName << " | Email: " << email << endl;
  }
  
  iFile.close();

  return 0;
}
