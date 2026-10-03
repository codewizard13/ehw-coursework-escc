/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    
    PERSONAL PROJECT: 

    **** TEST: fill-builder with 3 divisions, 99 els total ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Tests copy-pasting from Generate-Multi-Fill-Code.cpp into a file; this is for 3 divisions

    📝 Lessons Learned:
    - 
    
    References:
    - VIDEO: Bro Code - C++ Full Course for free | 39. Fill() function (https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */


#include <iostream>
using namespace std;

int main() {

    const int LINES = 99;
    string fruits[LINES];

    fill(fruits + (LINES/3)*0, fruits + (LINES/3)*1, "apple");
    fill(fruits + (LINES/3)*1, fruits + (LINES/3)*2, "orange");
    fill(fruits + (LINES/3)*2, fruits + (LINES/3)*3, "kiwi");

    for (int i = 0; i < LINES; i++) {
        cout << i+1 << ": " << fruits[i] << endl;

    }

    return 0;
}

