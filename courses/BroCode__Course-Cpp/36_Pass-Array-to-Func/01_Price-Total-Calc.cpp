/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=7e7Hwc6RK2R5TlgV&t=11316

    **** Pass array to a function ****

    Student: Eric Hepperle
    Created: 2026-10-01

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrate passing array to a function
    - Simple price total calculator demo

    📝 Lessons Learned:
    - when you pass an array to a function you only need the function name, not the square brackets
    - typically he uses the first element of the array as the sizeof() divisor argument, eg:
    
        sizeof(myArr)/sizeof(myArr[0])

    - #GOTCHA: When we pass an array to a function, it decays into what's known as a `pointer`
    - #GOTCHA: The function no longer knows how big the array is so you need to pass the array size as a separate argument

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

double getTotal(double prices[], int size);

int main()
{
    double prices[] = {49.99, 15.05, 75, 9.99};
    int size = sizeof(prices)/sizeof(prices[0]);
    double total = getTotal(prices, size);

    cout << "Total: $" << total;

    return 0;
}

double getTotal(double prices[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total+= prices[i];
    }

    return total;

}