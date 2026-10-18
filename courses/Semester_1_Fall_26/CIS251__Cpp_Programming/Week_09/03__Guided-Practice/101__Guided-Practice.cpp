/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 9: Inheritance, Overriding, and Polymorphism

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-10-18

    VERSION: 1.01

    STATUS: WIP

    Instructions:
    1. Create Person and Student classes using public inheritance.
    2. Add a field specific to Student.
    3. Override a virtual display/describe method.
    4. Use a base-class pointer or reference to call an overridden function.
    5. Write one is-a example and one has-a example from everyday life.

    Lessons Learned:
    - 

    GitHub: https://github.com/codewizard13
 ************************************************************ */


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

    // ------------------------------------------------------------------------
    // NOTE: The 'override' keyword is not necessary, but it is a safety-check
    //       for the compiler.
    //   1) Without `override`, C++ creates a different `Student::introduce()`
    //      function and may silently call `Person::introduce()`
    //      through `Person*`.
    //
    //   2) With `override`, the compiler stops and tells you that no base
    //      virtual function was overridden.
    //
    virtual void introduce() const override { cout << "Hi, I'm " << name;
        cout << " and I'm a student.\n"; }

};

int main()
{

    // Create pointer to a student object
    Student* student = new Student;

    // Populate student values
    student->name = "Michael";
    student->courseload[0] = "Calculus";
    student->courseload[1] = "History";
    student->courseload[2] = "English";

    student->introduce(); // this works

    Person* pStudent = student; // this also works
    pStudent->introduce();

    // Release memory
    delete student;
    student = nullptr;
    pStudent = nullptr;  

    return 0;
}
