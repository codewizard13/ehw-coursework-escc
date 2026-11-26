/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: What is INHERITANCE in C++? https://www.youtube.com/watch?v=5HYIFFuGcvk

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate class inheritance.
    - Dog class inherits from Animal

    VERSION: 1.0
    STATUS: Fully Working

    NOTES:
    - inheritance = a class can receive attributes and methods from
        another class; children classes inherit from a parent class;
        Helps to reuse similar code found within multiple classes.

    - To inherit from a class use a colon (:) operator. eg,

        class Dog : public Animal // Dog inherits from Animal

    EX OUTPUT:
    ...

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

class Animal {
    public:
        bool alive = true;
    void eat() {
        cout << "This animal is eating\n";
    }
};

class Dog : public Animal {
    public:

    void bark() {
        cout << "The dog goes woof!\n";
    }

};

int main() {

    Dog dog; // create dog object

    cout << dog.alive << '\n'; // gives 1 = true
    dog.eat();
    dog.bark();

    return 0;
}