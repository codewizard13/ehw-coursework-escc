/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=p_WmtH6xUpGMT842&t=14505

    **** PASS BY VALUE VS PASS BY REFERENCE ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates swapping two string variables using a custom function FAILS when using
      pass-by-value.
    - Demonstrates FAILURE

    📝 Lessons Learned:
    - #GOTCHA: If you don't add the function prototype (the declaration at the top), swap() actually does appear to work!
        this is because my code uses namespace std which has its own built-in swap() function, and that function
        passes by reference. We can make the demo correctly show the issue the tutorial points out by
        changing the custom function name to swap_str(), which is not a built-in c++ std library function

    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

void swap_str(string x, string y);

int main() {

    string x = "Kool-Aid";
    string y = "Water";


    cout << "******************************\n";
    cout << "Starting Values: X = " << x << "  Y = " << y << '\n';

    swap_str(x, y);

    cout << "After Swap: X = " << x << "  Y = " << y << '\n';
    cout << "******************************\n";    

    return 0;
}

void swap_str(string x, string y) {
    string temp;
    temp = x;
    x = y;
    y = temp;
}