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