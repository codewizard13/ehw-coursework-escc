/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    INHERITANCE:
   
    Source: https://youtu.be/5HYIFFuGcvk?si=TzE-xTsqs8CA1YrM&t=322

    Student: Eric Hepperle
    Created: 2026-10-15

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate class inheritance.
    - Multiple shapes inheriting from Shape parent class
    - Creates Shape parent class, & children Cube & Sphere

    VERSION: 1.02
    STATUS: Fully Working

    NOTES:
    - Prints area and volume for Cube and Sphere
    - If you have multiple classes that share similar attributes and methods,
        you can place them within a parent class and all those individual
        classes can inherit from that one parent class.

    EX OUTPUT:
    ...

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

class Shape {
    public:
        double area;
        double volume;
};

class Cube : public Shape {
    public:
        double side;
    Cube(double side){
        // length = width = height
        // - 6 sides to a cube
        this->side = side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }

};

class Sphere : public Shape {
    public:
        double radius;
        const double PI = 3.14159;
    Sphere(double radius) {
        this->radius = radius;
        this->area = 4 * PI * (radius * radius);
        this->volume = (4/3.0) * PI * (radius * radius * radius);
    }
};

int main() {

    Cube cube(10);
    Sphere sphere(5);
    
    cout << "Area: " << cube.area << "cm\n";
    cout << "Volume: " << cube.volume << "cm\n";

    cout << "Area: " << sphere.area << "cm\n";
    cout << "Volume: " << sphere.volume << "cm\n";

    return 0;
}