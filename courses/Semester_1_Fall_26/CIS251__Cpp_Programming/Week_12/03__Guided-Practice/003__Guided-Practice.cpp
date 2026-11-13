/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 10: Operator Overloading, Enumerations, & Interface Design

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-11-12

    VERSION: 0.03

    STATUS: WIP - Read numeric records from a file and calculate total and avg.

    Instructions:
    (continuing from previous version)
    5.  Read several numeric records and calculate a total or average.

    Note:
    - The steps were followed, but the topic and business domain concept
        were created by Eric Hepperle

    - While the previous versions 0-2 were cumulative, for instruction 5 I'm 
        actually testing myself and writing a whole program from scratch.

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
 ************************************************************ */

/*
**** ALGORITHM ****

IF file doesn't exist,
    CREATE OUTPUT STREAM FILE: filename = "payment-records.txt"
    
WRITE VALUES TO OUTPUT STREAM

    DO UNTIL choice = lower("N")

        Ask user to input a name (full name, spaces allowed)
            Display error if name is not a string and end program

        Ask user to input a dollar amount (without the $ sign or punctuation)
            Display error if payment is not a number or has punctuation

        Ask user if they want to enter another record


    ... MORE TO COME ...


*/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {

    return 0;
}