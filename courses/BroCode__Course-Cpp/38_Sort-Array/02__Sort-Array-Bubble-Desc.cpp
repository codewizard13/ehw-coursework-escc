/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=byU0L9vjeg43j5gL&t=12372

    **** Sort an Array ****

    Student: Eric Hepperle
    Created: 2026-10-01

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrate sorting array, DESCENDING
    - Demonstrate basic bubble sort algorithm

    📝 Lessons Learned:
    - To sort descending, just make the j condition on the ASCENDING code less than. eg,

        if (array[j] < array[j + 1]) {
    
    
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
            if (array[j] < array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }

    }

}