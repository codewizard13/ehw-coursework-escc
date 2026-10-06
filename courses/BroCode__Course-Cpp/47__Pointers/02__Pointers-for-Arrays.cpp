/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=bvMzE9VdkXgQ3H1-&t=15611

    **** POINTERS ****

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates pointers fro ints and arrays

    📝 Lessons Learned:
    - #GOTCHA: arrays are already addresses so address-of operator not needed
    - cout << [arrName] - gives memory address (eg, 0xa1cd9ff650)
    - cout << *[arrName] - gives first element of array
    
    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    string name = "Bro";
    int age = 21;
    string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

    string *pName = &name;
    int *pAge = &age;
    // string *pFreePizzas = &freePizzas; // this won't work because array is already an address

    cout << "*pName: " << *pName << '\n';
    cout << "*pAge: " << *pAge << '\n';
    cout << "freePizzas: " << freePizzas << '\n'; // already a mem address like 0xa1cd9ff650
    cout << "*freePizzas: " << *freePizzas << '\n'; // gives first element in array


    return 0;
}
