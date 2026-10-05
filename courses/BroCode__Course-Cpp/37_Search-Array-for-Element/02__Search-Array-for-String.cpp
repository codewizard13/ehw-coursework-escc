/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=K1u5DZ-lxHeDLTSd&t=11904

    **** Search array for element ****

    Student: Eric Hepperle
    Created: 2026-10-01

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrate searching an array for an element
    - Search array for string

    📝 Lessons Learned:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int searchArray(string array[], int size, string element);

int main() {

    string foods[] = {"pizza", "hamburger", "hotdog"};
    int size = sizeof(foods)/sizeof(foods[0]);
    int index; // the index we found the element at; -1 if not found
    string myFood; // the needle; the string we are looking for

    cout << "Enter element to search for: " << '\n';
    getline(cin, myFood);

    index = searchArray(foods, size, myFood);

    if (index != -1) {
        cout << "myFood: " << myFood << " is at index " << index;
    } else {
        cout << myFood << " is not in the array." << endl;
    }

    return 0;
}

// Linear search
int searchArray(string array[], int size, string element) {

    for (int i=0; i < size; i++) {
    if (array[i] == element) {
            return i;
        }
    }

    return -1;

}