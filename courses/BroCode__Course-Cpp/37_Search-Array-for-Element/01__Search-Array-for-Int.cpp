/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=WVLZIjK9RVRUjaAJ&t=11588

    **** Search array for element ****

    Student: Eric Hepperle
    Created: 2026-10-01

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrate searching an array for an element
    - Search array for integer

    📝 Lessons Learned:
    - In programming `-1` often serves as a sentinel value; typically means something wasn't found

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int searchArray(int array[], int size, int element);

int main() {

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    int index; // the index we found the element at; -1 if not found
    int myNum; // the needle; the number we are looking for

    cout << "Enter element to search for: " << '\n';
    cin >> myNum;

    index = searchArray(numbers, size, myNum);

    if (index != -1) {
        cout << "myNum: " << myNum << " is at index " << index;
    } else {
        cout << myNum << " is not in the array." << endl;
    }

    return 0;
}

// Linear search
int searchArray(int array[], int size, int element) {

    for (int i=0; i < size; i++) {
    if (array[i] == element) {
            return i;
        }
    }

    return -1;

}