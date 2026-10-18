/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 9: Inheritance, Overriding, and Polymorphism

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-10-18

    VERSION: 1.02

    STATUS: Fully Working - printCourseload() works in Student class.

    Instructions:
    1. Create Person and Student classes using public inheritance.
    2. Add a field specific to Student.
    3. Override a virtual display/describe method.
    4. Use a base-class pointer or reference to call an overridden function.
    5. Write one is-a example and one has-a example from everyday life.

    Lessons Learned:
    - C++ must know a fixed array’s size before it creates any `Student`
        objects, so a per-object variable cannot be used as that size.
      - NEXT: Add Teacher version and test creating a collection
        of different types of Person objects
        
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
    virtual void introduce() const override
    {
        cout << "Hi, I'm " << name;
        cout << " and I'm a student.\n";
    }

    void printCourseload()
    {
        // Calculate courseload array size as if it was unknown
        int size = sizeof(courseload) / sizeof(string); // should equal 3

        cout << "My courseload is ";
        for (int i = 0; i < size; i++)
        {
            cout << courseload[i];

            // Create intelligent comma-separated and-list
            if (i < size - 2)
            {
                cout << ", ";
            }
            if (i == size - 2)
            {
                cout << ", and ";
            }
        }
    }
};

int main()
{

    Student test_student;
    test_student.name = "Fiona";
    test_student.courseload[0] = "Artillery";

    cout << "\n******** test_student is a direct Student object **************\n";
    test_student.introduce();

    // Create pointer to a student object
    Student *student = new Student;

    // Populate student values
    student->name = "Michael";
    student->courseload[0] = "Calculus";
    student->courseload[1] = "History";
    student->courseload[2] = "English";

    cout << "\n******** student is a pointer to Student **********************\n";
    student->introduce(); // this works

    cout << "\n******** pStudent is a pointer to the student pointer? ********\n";
    Person *pStudent = student; // this also works
    pStudent->introduce();

    student->printCourseload();


    // Release memory
    delete student;
    student = nullptr;
    pStudent = nullptr;

    cout << "\n\n******** END PROGRAM ******************************************\n";

    return 0;
}
