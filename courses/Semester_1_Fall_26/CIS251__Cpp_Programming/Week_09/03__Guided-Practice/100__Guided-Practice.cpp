/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 9: Inheritance, Overriding, and Polymorphism

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-10-18

    VERSION: 1.0

    STATUS: BROKEN - Demonstrates errors encountered with pointers
        and object references, etc.

    Instructions:
    1. Create Person and Student classes using public inheritance.
    2. Add a field specific to Student.
    3. Override a virtual display/describe method.
    4. Use a base-class pointer or reference to call an overridden function.
    5. Write one is-a example and one has-a example from everyday life.

    Lessons Learned:
    # ⚠️ Common Beginner Pitfalls

    - Thinking pointers and references are the same thing: a reference is an alias; a pointer stores an address.

    - Using `.` with a pointer, such as `pStudent.name`; pointers require `->`.

    - Thinking a base-class pointer cannot point to a child object: `Person* p = new Student;` is valid.

    - Thinking a base-class pointer can access child-only fields: `Person*` cannot directly access `Student::courseload`.

    - Expecting polymorphism without actually overriding the base class’s `virtual` function in `Student`.

    - Trying to use `courseload[]` without an index; use a specific slot such as `courseload[0]`.

    - Trying to assign an initializer list to a raw fixed-size array after it has already been declared.

    - Assuming every class must have a custom constructor; the compiler-provided default constructor is often enough for a small practice exercise.

    - Confusing the assignment’s learning goal with “production-quality” design; first demonstrate inheritance, overriding, and polymorphism clearly.

    GitHub: https://github.com/codewizard13
 ************************************************************ */

/*
    ALGORITHM:



*/

#include <iostream>
#include <string>
using namespace std;

/*
    @class Person

*/
class Person
{
public:
    string name;

    virtual void introduce() const { cout << "Hi, I'm " << name << "\n"; }
};

class Student : public Person
{
public:
    string courseload[3]; // Student-specific field

    virtual void introduce() const { cout << "Hi, I'm " << name;
        cout << " and I'm a student\n"; }

};

int main()
{

    Person person1;
    person1.name = "Fiona";
    person1.introduce();


    Student

    Person *pStudent = new Student; // base-class pointer
    if (pStudent == nullptr) { cout << "Null Pointer: pStudent cannot be null\n"; return 0;}
    pStudent->name = "Bob";
    pStudent->introduce();

    // Doesn't work!
    // pStudent->courseload[] = {"Calculus", "History", "English"};

    // Also Doesn't work!
    // student->courseload[0] = "Calculus";
    // student->courseload[1] = "History";
    // student->courseload[2] = "English";

    pStudent->courseload[0] = "Calculus";


    delete pStudent;

    pStudent = nullptr;

    return 0;
}
