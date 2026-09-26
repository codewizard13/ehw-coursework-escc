/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Self-Directed (Not Assigned) Practice Exercises

    YT: Tech with Tim - https://youtu.be/RXzzE2wnnlo?si=KdSi0FSE7rPMMKd5&t=651

    Student: Eric Hepperle
    Created: 2026-09-26

    VERSION: 1.0

    STATUS: Fully Working

    Purpose / Instructions:
    - Demonstrate how to iterate over a vector

    📝 Lessons Learned:
    - with vectors use size() not capacity() in your loop condition


    FUTURE IMPROVEMENTS:
    - ...

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v1 = {1, 2, 3, 4};

    cout << "*****************************" << endl;
    cout << "ITERATING OVER A VECTOR" << endl;

    cout << "*****************************" << endl;
    cout << "For loop method: " << endl;

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << endl;
    }

    cout << "*****************************" << endl;
    cout << "ITR method (with pointer): " << endl;

    v1.insert(v1.begin(), 10);

    for (auto itr = v1.begin(); itr != v1.end(); ++itr) {
        cout << *itr << endl; // dereferencing the pointer
    }

    return 0;
}
