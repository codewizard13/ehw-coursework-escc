/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 6 PROGRAMMING ASSIGNMENT — Arrays, Strings, and Sequential Data Processing

    Student: Eric Hepperle
    Created: 2026-09-23

    VERSION: 1.0

    STATUS: WIP

    Instructions:
        Score List Analyzer: store a fixed set of quiz scores in an array,
        use loops to calculate total/average and locate highest/lowest, and use
        std::string for the student's name and report heading.

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
    *** ALGORITHM: ***

    DEFINE array of double as quiz_scores

    LOOP through each score




















---


*/

#include <iostream>
#include <iomanip>
using namespace std;

// Declare Variables
double quiz_scores[] = {90, 100, 100, 85.5, 46};

double highest = 9999.0;
double lowest = -9999.0;
double total;
double avg;

string student_name = "Joe Blo";
string report_heading;

int array_len = sizeof(quiz_scores) / sizeof(double);

int main(void)
{

    cout << "*********************************\n";
    cout << "Grade Report for: " << student_name << "\n";

    for (int i = 0; i < array_len; i++)
    {

        // DEBUG OUT QUIZ SCORES
        cout << quiz_scores[i] << "\n";

        // UPDATE TOTAL
        total += quiz_scores[i];
    }

    // CALC AVG
    avg = total / array_len;

    // OUTPUT STATS
    cout << "Total: " << total << "\n";
    cout << "Average: " << avg << "\n";

    cout << "*********************************\n";

    return 0;
}

/*** CUSTOM FUNCTIONS  ***/
