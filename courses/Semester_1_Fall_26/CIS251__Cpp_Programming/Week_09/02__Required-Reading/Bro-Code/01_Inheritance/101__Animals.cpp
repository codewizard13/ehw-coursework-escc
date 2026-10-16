/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: https://youtu.be/5HYIFFuGcvk?si=u_2plx3iD3kjRPIN&t=188

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate class inheritance.
    - Demonstrate Dog and Cat instances

    VERSION: 1.01
    STATUS: Fully Working

    NOTES:
    - Technically, you CAN legally add the same methods to children that are in
        the parent, but then you have to manually edit all those methods
        if you ever need to make the change. With inheritance, you only need
        to make the change to the parent.

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

class Cat : public Animal {
    public:

    void meow() {
        cout << "The cat goes meow.\n";
    }
};


int main() {

    Dog dog; // create dog object
    Cat cat;

    cout << dog.alive << '\n'; // gives 1 = true
    dog.eat();
    dog.bark();

    // The first two statements work because cat inherits those properties from
    //   the Animal parent class. But, Cat doesn't have a bark() method,
    //   so the compiler errors out.
    cout << cat.alive << '\n'; // works
    cat.eat(); // works
    // cat.bark(); // gives error 'no member named bark'
    cat.meow();

    return 0;
}