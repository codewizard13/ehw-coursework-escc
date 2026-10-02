/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=XN579bQOj8ZRZbSt&t=12045

    **** Sort and Array ****

    Student: Eric Hepperle
    Created: 2026-10-01

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrate sorting array, ASCENDING
    - Demonstrate basic bubble sort algorithm

    📝 Lessons Learned:
    - Bubble sort:
        - Begin at index 0
        - Examine element to right. If element on left greater than element on right, then swap the two elements
            - Put left in temp var
            - move right into left
            - move temp into right
        - repeat until last element reached
    - Foreach loop uses colon, eg: `for (int element : array)`
    - #TIP: Reason the sort() condition is `size - 1` is because once we don't need to compare the last element to anything because the largest value will naturally float to the right (???)
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

void sort(int array[], int size);

int main() {

    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size);

    for (int element : array) {
        cout << element << " ";
    }

    return 0;
}

void sort(int array[], int size) {

    int temp;
    for (int i = 0; i < size -1; i++ ) {
        for (int  j = 0; j < size - i -1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }

    }

}