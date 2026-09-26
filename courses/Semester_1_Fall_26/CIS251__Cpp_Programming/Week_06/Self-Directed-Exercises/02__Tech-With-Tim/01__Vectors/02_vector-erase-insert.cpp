/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Self-Directed (Not Assigned) Practice Exercises

    YT: Tech with Tim - https://youtu.be/RXzzE2wnnlo?si=SLYl2ET-OtxAbVan&t=505

    Student: Eric Hepperle
    Created: 2026-09-26

    VERSION: 1.0

    STATUS: Fully Working

    Purpose / Instructions:
    - Demonstrate how to insert and erase elements

    📝 Lessons Learned:
    - you need a pointer to position of the element you want to insert the element before to insert an element


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

    // Insert

    v1.insert(v1.begin(), 5);
    v1.insert(v1.begin(), 7);
    cout << v1[0] << endl;

    v1.insert(v1.begin() + 1, 5);
    cout << v1[0] << endl;
    cout << v1[1] << endl;

    // Erase    
    v1.erase(v1.begin());
    cout << v1[0] << endl;

    return 0;
}
