/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRYAN MALLOYON:

    INITIALIZATION LISTS:

    Source: https://www.youtube.com/watch?v=BYWGdRuy1Uw

    Student: Eric Hepperle
    Created: 2026-10-17

    PURPOSE: My notes on Bryan MalloyOn topics.
    - Demonstrate understanding of C++ initialization lists
    - Demonstrate initialization vs assignment constructions

    VERSION: 1.0
    STATUS: Fully Working

    NOTES:
    - prefer initialization to assignment
    - in some instances, initialization can be much more efficient than
        assignment; initialization happens BEFORE you get to the body
    - colon: says to the compiler 'here comes an initialization list'
    - initialization list: works but putting a colon, then the data attributes
        you want to initialize, then the value to initialize to in parens.

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
    Student(int a) : age(a)
    {
    }
    int getAge() const { return age; }

private:
    int age;
};

int main()
{
    Student bob(21);

    cout << bob.getAge() << '\n';
}