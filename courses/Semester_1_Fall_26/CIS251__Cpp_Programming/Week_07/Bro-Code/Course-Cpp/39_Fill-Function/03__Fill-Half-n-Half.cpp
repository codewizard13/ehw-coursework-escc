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
    - Demonstrates how to fill half one thing and half another

    📝 Lessons Learned:
    - To fill half, set size arg as array_name + SIZE/2
    - To fill last half, RESUME with begin arg at wherever you left off, in this case, foods + SIZE/2; Set your end value as array_name + SIZE
    - #TIP: Your final component whether it is from halves, thirds, tenths, 100ths, etc., should be array_name + SIZE
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    const int SIZE = 150;
    string foods[SIZE];

    fill(foods, foods + (SIZE/2), "pizza");
    fill(foods + (SIZE/2), foods + SIZE, "hamburgers");

    int count = 1;

    for (string food : foods) {
        cout << count << ": " << food << endl;

        count++;
    }

    return 0;
}