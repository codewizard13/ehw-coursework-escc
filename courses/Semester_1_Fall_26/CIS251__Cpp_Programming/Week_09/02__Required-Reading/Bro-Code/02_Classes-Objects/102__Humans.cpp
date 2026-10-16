/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: https://youtu.be/_8H2n0nDfd4?si=et8Q035tyNzXTK2J&t=394

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate understanding of classes and objects
    - Creates multiple Human objects with default properties,
        and no custom properties = clones

    VERSION: 1.02
    STATUS: Fully Working

    NOTES:
    - Classes can be instantiated with default properties/values

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
        // Every human is clone of Rick by default
        string name = "Rick";
        string occupation = "scientist";
        int age = 70;

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