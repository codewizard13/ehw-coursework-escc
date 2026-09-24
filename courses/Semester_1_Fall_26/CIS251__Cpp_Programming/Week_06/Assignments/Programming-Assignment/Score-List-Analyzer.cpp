/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 6 PROGRAMMING ASSIGNMENT — Arrays, Strings, and Sequential Data Processing

    Student: Eric Hepperle
    Created: 2026-09-23
    Updated: 2026-09-24

    VERSION: 1.0

    STATUS: Fully Working

    Instructions:
        Score List Analyzer: store a fixed set of quiz scores in an array,
        use loops to calculate total/average and locate highest/lowest, and use
        std::string for the student's name and report heading.

    Notes:
    - "Fixed set" to me implies hard-coded values and therefore I
    didn't use any input statements for the scores
    - Although not absolutely necessary, I created sentinel values for
    highest/lowest
    - Because the algorithm / pseudocode is so long, I moved it to
    its own file ./02__Algorithm.md

    Lessons Learned:
    - max and min must be reserved terms because I received compiler errors
    when I had originally had the "highest" and "lowest" named "max" and "min".

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */



#include <iostream>
#include <iomanip>
using namespace std;

// Declare Variables
double quiz_scores[] = {90, 100, 100, 85.5, 46}; // fixed set of scores

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

    cout << "\n*********************************";

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

