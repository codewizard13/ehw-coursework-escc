/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Video Example: Bro code - What is C++ type conversion?
    Source: https://youtu.be/Fj9HjbqHto8?si=EkcIi0BBpWyVYcHx&t=127
    
    Student: Eric Hepperle
    Created: 2026-08-30

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	
    /*
    int correct = 8;
    int questions = 10;
    double score = correct/questions * 100;

    cout << score << "%";
    // #GOTCHA: Returns 0%! Issue is that int div by int truncates the decimal portion!
    // Solve by casting the denominator    
    */

    int correct = 8;
    int questions = 10;
    double score = correct/ (double) questions * 100;

    cout << score << "%"; // RETURNS 80% as expected :)

    return 0;
}