/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 5 PROGRAMMING ASSIGNMENT — Functions, Scope, Decomposition, and Reuse

    Student: Eric Hepperle
    Created: 2026-09-20

    VERSION: 1.0

    STATUS: WIP

    Instructions:
        Modular Grade Calculator: create separate functions to read/validate a
        score, calculate a letter grade, and display the result. main() must
        coordinate the program rather than contain all logic.

    Lessons Learned:
    - Returning `0` for invalid input fails because `0` is also a valid score. `calcGradeLetter(0)` correctly returns `F`, so the program cannot distinguish “invalid input” from a real zero-grade. Use an out-of-range sentinel like `-1.0` instead.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
    *** ALGORITHM: ***

    DEFINE FUNCTION PROTOTYPES:
    - readScore(double score) - return score if valid else, end program with error
    - calcGradeLetter(double score) - return char
    - displayGrade() - return void; display grade_ltr char

    // MAIN

    DEFINE double score = 0;
    DEFINE char grade_ltr;

    readScore()
    calcGradeLetter()
    displayGrade()



    // READSCORE

    Ask user for the number score - double type grade_score
        if not a double then exit program with error

    ASSIGN double score_num to result of readScore()



    // CALC GRADE LETTER

    Use switch statement to determine grade letter

    CASE score < 100 && score >=90, A
    CASE score < 90 && >=80, B
    CASE score < 80 && >=70, C
    CASE score < 70 && >=60, D
    CASS score <60, F

    RETURN grade_ltr


    // DISPLAY GRADE LETTER

    Display grade letter

*/

#include <iostream>
#include <iomanip>
using namespace std;

const double INVALID_SCORE = -1.0;

// FUNCTION PROTOTYPES
double readScore(double score);
char calcGradeLetter(double score);
void displayGrade(char grade_ltr);

int main(void)
{

    // Declare Variables
    double score = 0;
    char grade_ltr;

    cout << "*******************\n";

    grade_ltr = calcGradeLetter( readScore(score) );

    if (!(grade_ltr == '\0')) {
        displayGrade( grade_ltr );
    }
    

    cout << "*******************\n\n";
    return 0;
}

/*** CUSTOM FUNCTIONS  ***/

double readScore(double score)
{
    cout << "Enter the score (0-100, decimals allowed): ";

    if (!(cin >> score) || score < 0 || score > 100) {
        cout << "Invalid input: score must be a positive double or int 0-100." << endl;
        return 0;
    }

    return score;
};

char calcGradeLetter(double score)
{

    if (score < 0.0 || score > 100.0) {
        return '?';
    }
    else if (score >= 90.0) {
        return 'A';
    }
    else if (score >= 80.0) {
        return 'B';
    }
    else if (score >= 70.0) {
        return 'C';
    }
    else if (score >= 60.0) {
        return 'D';
    }
    else {
        return 'F';
    }

};

void displayGrade(char grade_ltr) {

    if (!(grade_ltr == '\0')) {
        cout << "Your grade = " << grade_ltr << endl;
    }

};