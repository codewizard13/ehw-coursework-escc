/**
 * @file oop-cube-class-demo.cpp
 * @brief Personal Project: OOP Cube Class.
 *
 * @details
 * This program defines a basic object-oriented `Cube` class. The class
 * declares method prototypes and private properties, with member functions
 * defined outside the class definition. A setter changes the side length and
 * recalculates the cube's measurements; the print method displays them with
 * the selected units.
 *
 * This personal project was inspired by Cisco Networking Academy's
 * C++ Essentials 1, Module 1, Lab 1.0.8.
 *
 * Demonstrates:
 * - Creating a basic object-oriented class.
 * - Defining private properties.
 * - Declaring class method prototypes.
 * - Defining class member functions outside the class definition.
 * - Using a setter to modify private properties and recalculate measurements.
 *
 * Sample Output:
 * 
 * Side = 4 in.
 * - Lateral Area: 64 in.
 * - Total Area: 96 in.
 * - Volume: 64 in. cu.
 * 
 * Side = 2 ft.
 * - Lateral Area: 16 ft.
 * - Total Area: 24 ft.
 * - Volume: 8 ft. cu.
 * 
 * Side = 1.25 m.
 * - Lateral Area: 6.25 m.
 * - Total Area: 9.375 m.
 * - Volume: 1.95312 m. cu.
 * 
 * @author Eric Hepperle
 * @date 2026-10-31
 * @version 1.0
 
  * @status Fully working
 *
 * @see 1.0.8 LAB Restricting access to object data
 *      https://www.netacad.com/launch?id=c9801f54-4d0c-44f9-b4ee-3f2d9c6306bf&tab=curriculum&view=b2a966be-9306-5897-b5b8-30b22678a25c
 *
 * Repository: https://github.com/codewizard13
 */

#include <iostream>
#include <string>
using namespace std;

class Cube
{
public:
    Cube(double side, string units);
    void set_side(double new_side);
    void print();
    string units;

private:
    double side;
    double lateral_area;
    double total_area;
    double volume;
    double perimeter;
};

// Constructor
Cube::Cube(double side, string units)
{
    this->side = side;
    this->units = units;
    this->lateral_area = 4 * (side * side);
    this->total_area = 6 * (side * side);
    this->volume = side * side * side;
}

void Cube::set_side(double new_side)
{
    if (new_side >= 0)
    {
        side = new_side;
        lateral_area = 4 * (side * side);
        total_area = 6 * (side * side);
        volume = side * side * side;
    }
}

void Cube::print()
{
    cout << "************* Cube Details: **************\n";
    cout << "Side = " << this->side << " " << units << endl;
    cout << "- Lateral Area: " << this->lateral_area << " " << units << endl;
    cout << "- Total Area: " << this->total_area << " " << units << endl;
    cout << "- Volume: " << this->volume << " " << units << " cu." << endl;
    cout << endl;
}

int main()
{

    // Create cube
    Cube c(4, "in.");

    c.print();

    c.set_side(2);
    c.units = "ft.";
    c.print();

    c.set_side(1.25);
    c.units = "m.";
    c.print();

    return 0;
}