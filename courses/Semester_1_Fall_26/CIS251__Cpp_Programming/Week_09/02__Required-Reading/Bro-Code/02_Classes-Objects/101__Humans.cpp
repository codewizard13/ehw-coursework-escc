/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: https://youtu.be/_8H2n0nDfd4?si=E4XtL1_GmoErYJuj&t=347

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate understanding of classes and objects
    - Creates multiple Human objects and set different properties

    VERSION: 1.01
    STATUS: Fully Working

    NOTES:
    - 

    EX OUTPUT:
    ...

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <string>
using namespace std;

class Human {
    public:
        string name;
        string occupation;
        int age;

    void eat() {
        cout << "This person is eating\n";
    }
    void drink() {
        cout << "This person is drinking\n";
    }
    void sleep() {
        cout << "This person is sleeping\n";
    }

};

int main() {

    Human human1; // human1 is an object
    Human human2;

    human1.name = "Rick";
    human1.occupation = "scientist";
    human1.age = 70;

    human2.name = "Morty";
    human2.occupation = "student";
    human2.age = 15;

    // Display Human1
    cout << "******* Human 1 ********\n";
    cout << human1.name << "\n";
    cout << human1.occupation << "\n";
    cout << human1.age << '\n';

    human1.eat();
    human1.drink();
    human1.sleep();

    // Display Human2
    cout << "\n******* Human 2 ********\n";
    cout << human2.name << "\n";
    cout << human2.occupation << "\n";
    cout << human2.age << '\n';

    human2.eat();
    human2.drink();
    human2.sleep();

}