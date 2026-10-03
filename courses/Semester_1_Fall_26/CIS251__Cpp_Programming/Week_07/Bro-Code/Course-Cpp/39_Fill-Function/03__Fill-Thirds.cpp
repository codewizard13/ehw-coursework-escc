/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551

    **** Fill Function ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates how to fill mutlitple thirds of a whole

    📝 Lessons Learned:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    const int SIZE = 99;
    string foods[SIZE];

    fill(foods, foods + (SIZE/3), "pizza");
    fill(foods + (SIZE/3), foods + (SIZE/3)*2, "hamburgers");
    fill(foods + (SIZE/3)*2, foods + SIZE, "hotdogs");

    int count = 1;

    for (string food : foods) {
        cout << count << ": " << food << endl;

        count++;
    }

    return 0;
}