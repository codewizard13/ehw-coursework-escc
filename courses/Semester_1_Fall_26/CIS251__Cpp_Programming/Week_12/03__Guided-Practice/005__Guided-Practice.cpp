/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 12: Files, Streams, Persistence, and Program Testing

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12
    Updated: 2026-11-14

    VERSION: 0.05

    STATUS: WIP - Display existing payment records and append test
            records. Interactive record entry, numeric validation,
            and total/average calculations remain unfinished.

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

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <fstream>
#include <iostream>
using namespace std;

int main() {

  // Define stream variables
  ifstream iFile; // input file
  ofstream oFile; // output file

  string inputFilename = "numbers.txt";
  string outputFilename = "calculations.txt";

  // Open input file
  iFile.open(inputFilename);
  if (!iFile.is_open()) {
    cout << "Error opening input file " << inputFilename << endl;
    return 1;
  }

  // Open output file
  oFile.open(outputFilename);
  if (!oFile.is_open()){
    cout << "Error opening output file " << outputFilename << endl;
  }

  // Read from input file
  int i_fromFile = 0;

  while (iFile >> i_fromFile) {
    cout << "Reading another line.\n";
  }



  return 0;
}
