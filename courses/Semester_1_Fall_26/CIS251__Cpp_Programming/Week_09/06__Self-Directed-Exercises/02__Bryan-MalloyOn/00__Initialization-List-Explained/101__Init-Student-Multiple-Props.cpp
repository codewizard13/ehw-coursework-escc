/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRYAN MALLOYON:

    INITIALIZATION LISTS:

    Source: https://youtu.be/BYWGdRuy1Uw?si=Ugz8bbNy83GS8z8m&t=193

    Student: Eric Hepperle
    Created: 2026-10-17

    PURPOSE: My notes on Bryan MalloyOn topics.
    - Demonstrate initializing multiple attributes

    VERSION: 1.01
    STATUS: Fully Working

    NOTES:
    - #GOTCHA: Compiler will initialize in the order the private members appear
        declared under the 'private' section label, NOT in the order you put
        them in the constructor!
    - #TIP: Initialize properties in the order you declare them.
    - Constructor initializes the data attributes and allocate space
       (e.g., for pointers)
    - compiler does that before it gets to the body

    EX OUTPUT:
    ...

    USE CASES:
    -

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <string>
using namespace std;

// class Student {
//     public:
//         Student(int a) {
//             age = a; // uses assignment
//         }
//     private:
//         int age;
// };

class Student
{
public:
    Student(int a) : age(a), iq(5*age)
    {
    }
    int getAge() const { return age; }
    int getIq() const { return iq; }

private:
    int age;
    int iq;
};

int main()
{
    Student bob(21);

    cout << bob.getAge() << '\n';
    cout << bob.getIq() << '\n';
}