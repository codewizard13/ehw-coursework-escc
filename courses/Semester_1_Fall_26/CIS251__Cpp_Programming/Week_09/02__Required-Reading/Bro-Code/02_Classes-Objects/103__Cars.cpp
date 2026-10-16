/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: https://youtu.be/_8H2n0nDfd4?si=Yhed-iSM9PqmdRw3&t=443

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate understanding of classes and objects
    - Creates car objects

    VERSION: 1.03
    STATUS: Full Working

    NOTES:
    - attributes: characteristics of an object
    - methods: functions an object can perform

    EX OUTPUT:
    ...

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
 ************************************************************ */

#include <iostream>
#include <string>
using namespace std;

class Car {
    public:
        string make;
        string model;
        int year;
        string color;

        void accelerate() {
            cout << "You step on the gas!\n";
        }
        void brake(){
            cout << "You step on the brakes!\n";
        }

};


int main() {

    Car car1;
    Car car2;

    car1.make = "Ford";
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "silver";

    cout << car1.make << '\n';
    cout << car1.model << '\n';
    cout << car1.year << '\n';
    cout << car1.color << '\n';

    car1.accelerate();
    car1.brake();

    
    return 0;
}