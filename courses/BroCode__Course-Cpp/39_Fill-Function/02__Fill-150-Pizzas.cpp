/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=XZqPeKJJgot2gV5i&t=12478

    **** Fill Function ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates using fill() to display 'pizza' SIZE times

    📝 Lessons Learned:
    - The `begin` argument is the array name (without brackets)
    - The `end` argument is the array name + the size
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    const int SIZE = 150;
    string foods[SIZE];

    fill(foods, foods + SIZE, "pizza");

    int count = 1;

    for (string food : foods) {
        cout << count << ": " << food << endl;

        count++;
    }

    return 0;
}