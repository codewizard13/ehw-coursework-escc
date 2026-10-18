/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Week 9: Inheritance, Overriding, and Polymorphism

    **** GUIDED PRACTICE BEFORE GRADED WORK ****

    Student: Eric Hepperle
    Created: 2026-10-18

    VERSION: 1.03

    STATUS: WIP

    Instructions:
    1. Create Person and Student classes using public inheritance.
    2. Add a field specific to Student.
    3. Override a virtual display/describe method.
    4. Use a base-class pointer or reference to call an overridden function.
    5. Write one is-a example and one has-a example from everyday life.

    Notes & Lessons Learned:
    - Removes the test_student direct object

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

    // NOTE: `override` is optional, but recommended.
    // It tells C++ that this function should replace a virtual function
    // from the parent class. If the function does not match correctly,
    // C++ shows an error instead of quietly using Person::introduce().
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

    // Create pointer to a student object
    Student *student1 = new Student;

    // Populate student1 values
    student1->name = "Michael";
    student1->courseload[0] = "Calculus";
    student1->courseload[1] = "History";
    student1->courseload[2] = "English";

    cout << "\n******** student1 is a pointer to Student **********************\n";
    student1->introduce(); // Calls Student::introduce()

    cout << "\n******** pStudent is a pointer to the student1 pointer? ********\n";
    Person *pStudent = student1; // Points to the same Student object
    pStudent->introduce();       // Calls Student::introduce() via polymorphism

    student1->printCourseload();

    // Release the Student object
    delete student1;
    student1 = nullptr;
    pStudent = nullptr;

    cout << "\n\n******** END PROGRAM ******************************************\n";

    return 0;
}
