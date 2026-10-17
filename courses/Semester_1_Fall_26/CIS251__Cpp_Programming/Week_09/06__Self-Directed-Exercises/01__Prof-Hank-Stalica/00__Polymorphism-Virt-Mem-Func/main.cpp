/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - PROF HANK STALICA:
    
    POLYMORPHISM & VIRTUAL FUNCTIONS:
   
    Source: https://www.youtube.com/watch?v=4NPOIaUxnnk

    Student: Eric Hepperle
    Created: 2026-10-17

    PURPOSE: My notes on Professor Hank Stalica topics.
    - Demonstrate understanding of polymorphism & virtual functions

    VERSION: 1.0
    STATUS: WIP

    NOTES:
    - polymorphism: allows object reference variable or object pointer to
        reference objects of different types and to call the correct
        member functions depending on the type of object being referenced;
        can assign different types of objects to the same pointer or
        reference type (?)

    

    EX OUTPUT:
    ...

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
 ************************************************************ */

 #include <iostream>
 #include <string>
 using namespace std;


// base class
class Square {

    private:
    int x;

    public: // interface
    Square(int _x) : x(_x) {

    }

    void setX(int _x) { x = _x; }
    int getX() const { return x; }
    void print() const { cout << "Square!\n|"; }

};


 int main() {


    return 0;
 }