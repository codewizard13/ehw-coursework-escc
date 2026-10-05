/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=ghtdgKwCTcMNnAk3&t=14275

    **** MEMORY ADDRESSES ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates accessing memory addresses with address-of operator

    📝 Lessons Learned:
    - memory address = a location in memory where data is stored
    - a memory address can be accessed with & (address-of operator)
    - variable: container for some data; exist in computer memory at a given address
    - can find the address of a variable using the address-of operator
    - every time we run the program the address is likely to change (?)
    - memory addresses are in HEXADECIMAL
    - To calc bytes used for consecutive variables, convert to decimal and subtract
    - integers take 4 BYTES of memory
    - booleans only take 1 BYTE of memory
    - We need to know how much memory we need to ALLOCATE to fit a certain value


    References:
    - Rapid Tables Hex to Decimal Converter: https://www.rapidtables.com/convert/number/hex-to-decimal.html
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    string name = "Bro";
    int age = 21;
    bool student = true;

    cout << &name << '\n';
    cout << &age << '\n';
    cout << &student << '\n';
    

    return 0;
}