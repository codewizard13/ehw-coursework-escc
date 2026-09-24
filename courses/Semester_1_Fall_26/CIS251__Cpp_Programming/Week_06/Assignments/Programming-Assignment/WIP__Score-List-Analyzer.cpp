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

double highest = -999;
double lowest = 999;
double total;
double avg;



int array_len = sizeof(quiz_scores) / sizeof(double);

int main(void)
{

    string student_name = "Eric Hepperle";
    string report_heading = "Grade Report for: ";
    report_heading.append(student_name);

    cout << "*********************************\n";
    cout << report_heading << "\n";
    cout << "Scores: ";

    for (int i = 0; i < array_len; i++)
    {

        // PRINT QUIZ SCORES HORIZONTALLY FOR REFERENCE
        cout << quiz_scores[i];

        // Separate scores by commas except after the last one
        if (i < array_len-1) {
            cout << ", ";
        }

        // UPDATE TOTAL
        total += quiz_scores[i];

        // UPDATE HIGHEST
        if (quiz_scores[i] > highest) {
            highest = quiz_scores[i];
        }

        // UPDATE LOWEST
        if (quiz_scores[i] < lowest) {
            lowest = quiz_scores[i];
        }

    }

    // CALC AVG
    avg = total / array_len;

    cout << setprecision(2) << fixed;

    // OUTPUT STATS
    cout << endl;
    cout << "Total: " << total << "\n";
    cout << "Average: " << avg << "\n";
    cout << "Lowest Score: " << lowest << "\n";
    cout << "Highest Score : " << highest << "\n";

    cout << "*********************************\n";

    return 0;
}

/*** CUSTOM FUNCTIONS  ***/
