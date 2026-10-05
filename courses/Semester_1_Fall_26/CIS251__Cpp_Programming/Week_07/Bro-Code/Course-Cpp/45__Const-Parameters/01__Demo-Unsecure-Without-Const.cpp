/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=lTM0Z3lUv0bYAqmX&t=14688

    **** CONST PARAMETERS ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates how passed in variables are changeable without const params

    📝 Lessons Learned:
    - const parameter: parameter that is effectively read-only; created with `const` keyword; code is more secure & conveys intent
    - const parameters are especially useful for references and pointers
    - Without const params, we can modify the received values in our code (unwantedly)
    
    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

void printInfo(string name, int age);

int main() {

    string name = "Bro";
    int age = 21;

    printInfo(name, age);

    return 0;
}

void printInfo(string name, int age) {
    // Without const params, we can modify the received values in our code (unwantedly)
    name = "";
    age = 0;
    
    cout << name << '\n';
    cout << age << '\n';
}