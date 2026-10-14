/**
 * @brief Self-directed practice exercise: Oct, Hex, Dec Manipulators.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @practice Self-Directed (Not Assigned) Practice Exercises
 * @reference Danny Hardin — https://www.youtube.com/watch?v=jz5QEkKpfmM
 *
 * @purpose Demonstrate how to iterate over a vector.
 * @instructions ...
 *
 * @status WIP - BROKEN because instructor has hidden important sections
 *               of code in the video.
 *
 * @author Eric Hepperle
 * @contact https://github.com/codewizard13
 * @contact codewizard13@gmail.com
 * @date 2026-09-26
 * @version 1.0
 *
 * @par Lessons Learned
 * - With vectors, use size() rather than capacity() in the loop condition.
 *
 * @par Future Improvements
 * - ...
 *
 * @link https://github.com/codewizard13
 */

 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <string>

 using namespace std;

 int main(void) {

    int number = 64;
    int octval = 017; // precede value with zero is interpreted as base 8 value

    // system("pause"); // Program pauses here. Windows only

    // cout << "Number Base Conversion" << endl;
    cout << "Enter a number in decimal and it will be converted to hexadecimal and octal. " << endl;

    // int i;

    // cin >> i;
    // cout << i << hex << endl;
    // cout << i << oct << endl;

    int i = 8;

    // cout << i << hex << i + i << oct << i;
    cout << i << endl; // decimal i
    cout << hex << i << endl; // hex i
    cout << oct << i << endl; // oct i
    cout << dec << i << endl; // back to decimal
    return 0;
 }