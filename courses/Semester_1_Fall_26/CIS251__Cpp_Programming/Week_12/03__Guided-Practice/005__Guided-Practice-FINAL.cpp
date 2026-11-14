/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 12: Files, Streams, Persistence, and Program Testing

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12
    Updated: 2026-11-14

    VERSION: 0.05

    STATUS: Fully Working

    Demonstrates:
    - Basic C++ File I/O (input/output)

    Instructions:
    (continuing from previous version)
    5. Read several numeric records and calculate a total or average.

    Design Approach:
    - v.03-04 #MAYBE were overly complex — and are currently uncomplete —,
      due to badly scoped Perplexity advice. This version follows
      Shmeowlex's tutorial and is much simpler.

    Notes & Limitations:
    - The exercise follows the assigned steps and is very basic.

    - Versions 0.00-0.02 were cumulative. Work on instruction 5 began
      as a separate program written from scratch for practice.

    Lessons Learned: ./03__lessons-learned.md

    @see: Shmeowlex | C++ File Input and Output: https://www.youtube.com/watch?v=LIxwbvKRFAg
    @see: Kenny Yip Coding | C++ String Stream: https://www.youtube.com/watch?v=KexW0HJD8OY

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

  // Define stream variables
  ifstream iFile; // input file
  ofstream oFile; // output file

  string inputFilename = "numbers.txt";
  string outputFilename = "calculations.txt";

  // Open input file
  iFile.open(inputFilename);
  if (!iFile.is_open())
  {
    cerr << "Error opening input file " << inputFilename << endl;
    return 1;
  }

  // Open output file
  oFile.open(outputFilename);
  if (!oFile.is_open())
  {
    cerr << "Error opening output file " << outputFilename << endl;
    return 1;
  }

  // Read from input file
  int i_fromFile = 0;
  string line;

  int lineCount = 0;
  int calcTotal = 0;

  while (iFile >> line)
  {
    cout << "Reading another line.\n";

    //  Here, find_first_not_of() looks for a character that is not in the
    //   supplied whitespace set. If it finds none, it returns
    //   std::string::npos, so the line is skipped. This approach also handles
    //   a leftover carriage return ('\r') from Windows-style line endings when
    //   the stream has not translated it.
    if (line.find_first_not_of(" \t\r\n\v\f") == std::string::npos)
    {
      continue;
    }

    calcTotal += stoi(line);

    lineCount++;
  }

  cout << setprecision(2) << fixed;

  cout << "Total: " << calcTotal << endl;

  double calcAvg = calcTotal / static_cast<double>(lineCount);

  cout << "Numbers Counted: " << lineCount << endl;

  cout << "Average (total/lines): " << calcAvg << endl;

  return 0;
}
