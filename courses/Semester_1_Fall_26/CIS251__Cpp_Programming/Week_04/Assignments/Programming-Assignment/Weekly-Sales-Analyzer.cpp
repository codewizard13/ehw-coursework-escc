/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 4 PROGRAMMING ASSIGNMENT — Loops, Repetition, and Algorithmic Tracing

    Student: Eric Hepperle
    Created: 2026-09-20

    VERSION: 1.0

    STATUS: FULLY WORKING

    Instructions:
    Weekly Sales Analyzer: repeatedly read seven daily sales values with a
     loop, calculate total and average, count values meeting a stated
     threshold, and print a simple summary. Use loops and decisions only; no
     arrays are required yet.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

/*
    ALGORITHM:

    DECLARE VARIABLES
    - initialize double accumulator  `total` as zero
    - initialize  double average as null;
    - initialize double day_sales as null;

    - NOTE: The assignment implies the wording of a DO-WHILE loop so it runs at least once,
    however, closer examination shows this is a numbered count loop and is better
    implemented as a for loop.

    SET LOOP iteration (i) at 1
    SET exit condition as when count is 6 (we'll count 0-6 for a total of 7 days)
    EACH ITERATION
        Prompt user to enter a daily sales value (expect a double)
        Recive and validate the sales value
            reject with error if not a number
        Add current sales value to total
        INCREMENT i by one
        EXIT LOOP when i = 6 (i <= 7)
    END LOOP

    Set precision to 2 decimal points
    Print to console 'Total: ' << total
    Print to console 'Average: ' << total / 7
 
*/

    // Declare Variables
    double total = 0;
    double avg, day_sales;

    // Allow exactly 7 values
    for (int i = 1; i <= 7; i++) {

        cout << "Enter sales value for day " << i << ": ";

        if (!(cin >> day_sales)) {
            cout << "Invalid Input: day sales value must be a number\n\n";
            return 0;
        }

        total += day_sales;

    }


    cout << setprecision(2) << fixed;
    cout << "Total: $" << total << endl;
    cout << "Average: $" << total / 7.0 << endl;

    cout << "*******************\n\n";
	return 0;
}