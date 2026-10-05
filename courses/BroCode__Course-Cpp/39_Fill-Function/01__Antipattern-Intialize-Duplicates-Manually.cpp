/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=OjXe2S4kmmYnr21_&t=12404

    **** Fill Function ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates how to manually initialize a sequence of repeated values

    📝 Lessons Learned:
    - fill() = fills a range of elements with a specified value

        fill (begin, end, value)

    - it is not practically to manually initialize a sequence/range of repeated values
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    // Not practical to initialize all these elements manually, but does work
    // What if you wanted to repeat 100 times instead — it would be very laborious and error prone in the code because you are managing many more characters and lines of code.
    string foods[10] = {"pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza"};

    for (string food : foods) {
        cout << food << endl;
    }

    return 0;
}