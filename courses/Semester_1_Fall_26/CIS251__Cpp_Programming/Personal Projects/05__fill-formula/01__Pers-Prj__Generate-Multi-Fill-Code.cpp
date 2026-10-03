/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming

    PERSONAL PROJECT:

    **** Extrapolating a formula / function for multi-fill ****

    Student: Eric Hepperle
    Created: 2026-10-03

    VERSION: 1.0

    STATUS: WIP - Code-builder function seems to work; Next: test

    Purpose:
    - Demonstrates building 'fill()' nths code snippet

    📝 Lessons Learned:
    -

    References:
    - VIDEO: Bro Code - C++ Full Course for free | 39. Fill() function (https://youtu.be/-TkoO8Z07hI?si=9D79T2XMJIIbNUrz&t=12551)

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

// #include <iostream>
// using namespace std;

// int main() {

//     const int SIZE = 99;
//     string foods[SIZE];

//     fill(foods, foods + (SIZE/3), "pizza");
//     fill(foods + (SIZE/3), foods + (SIZE/3)*2, "hamburgers");
//     fill(foods + (SIZE/3)*2, foods + SIZE, "hotdogs");

//     int count = 1;

//     for (string food : foods) {
//         cout << count << ": " << food << endl;

//         count++;
//     }

//     return 0;
// }

/*
ALGORITHM:

SET total SIZE const

create an array sized to SIZE

// FOR 4ths

there should be 4 fill statements

SIZE/4

FOREACH unique element:
    create a unique fill statement
    int section size = SIZE/num unique elements

    end multiplier is line num ; eg, line 3 should multiply section size by 3




*/

#include <iostream>
using namespace std;

void build_str_fill(string arr_name, string arr[], int size);

int main()
{

    string fruits[] = {"apple", "orange", "kiwi"};
    int fruits_size = sizeof(fruits) / sizeof(fruits[0]);

    // string cars[] = {"Honda", "Toyota", "Ford", "Chevy", "Buick"};
    string cars[] = {"Honda", "Toyota", "Ford", "Chevy", "Buick", "Datsun", "Mazda"};

    int cars_size = sizeof(cars) / sizeof(cars[0]);

    build_str_fill("fruits", fruits, fruits_size);
    build_str_fill("cars", cars, cars_size);

    return 0;
}

// Each unique element should fill 1/sizeth of the the total
void build_str_fill(string arr_name, string arr[], int size)
{

    string begin, end;

    for (int i = 0; i < size; i++)
    {

        // Iteration = index + 1
        int iter = i + 1;

        cout << "fill(";

        // Build arg for 'begin'
        cout << arr_name << " + (SIZE/" << size << ")*" << i;

        cout << ", ";

        // Build arg for 'end'
        cout << arr_name << " + (SIZE/" << size << ")*" << iter;

        // Add element name and close statement
        cout << ", \"" << arr[i] << "\")" << ";\n";
    }

    cout << "*************************************\n\n";
}