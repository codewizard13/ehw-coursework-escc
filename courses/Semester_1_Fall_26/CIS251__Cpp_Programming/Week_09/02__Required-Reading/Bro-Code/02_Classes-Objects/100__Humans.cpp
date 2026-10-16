/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: C++ CLASSES & OBJECTS explained easy https://youtu.be/_8H2n0nDfd4?si=Z97vPD8MxoOvd6N5

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate understanding of classes and objects
    - Create single Human class with properties and methods

    VERSION: 1.0
    STATUS: Fully Working

    NOTES:
    - object = Collection of attributes and methods; can have characteristics
      and could perform actions; can be used to mimic real world items 
      (ex. Phone, Book, Car); created from a class which acts as "blueprint".

    - class: acts as the blueprint of the object.

    - Characterics examples: version number, charge level, service provider, author, total pages, name, age, breed
    
    - Methods examples: make calls, receive calls, play games,  open, close, eat, bark, sleep, play fetch

    - How are classes different than structs? A: structs don't have actions/methods - classes do

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

    human1.name = "Rick";
    human1.occupation = "scientist";
    human1.age = 70;

    cout << human1.name << "\n";
    cout << human1.occupation << "\n";
    cout << human1.age << '\n';

    human1.eat();
    human1.drink();
    human1.sleep();

}