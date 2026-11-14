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

Create output filename

Create output file stream
  if fails, show error and return 1 (failure code)

Write 5 contact records to ouput file

Read the records back in the console

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
    cerr << "Error: File " << outputFilename << " failed to open.\n";
    return 1;
  }

  oFile << "Michael Jackson, mjackson@gmail.com" << endl;
  oFile << "Scottie Pippin, greatscott91@yahoo.com" << endl;

  ifstream iFile(outputFilename);

  if (!iFile)
  {
    cerr << "Error: File " << outputFilename << " could not be read.\n";
    return 1;
  }

  string fullName;
  string email;

  while ( getline(iFile, fullName, ',') &&
          getline(iFile, email))
  {
    cout << "Name: " << fullName << " | Email: " << email << endl;
  }

  return 0;
}
