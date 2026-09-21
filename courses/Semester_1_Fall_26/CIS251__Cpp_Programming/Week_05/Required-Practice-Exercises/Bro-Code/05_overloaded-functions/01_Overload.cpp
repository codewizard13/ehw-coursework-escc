/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    OVERLOADED FUNCTIONS:
   
    Source: https://www.youtube.com/watch?v=Mfyt_x9MjiY

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - Demonstrate function overloading.

    NOTES:
        - function overloading: using the same function name with different
        parameter sets. (THIS is what he said, but it's imprecise)

        - Function overloading means creating more than one function with the
        same name, but giving each one a different kind of input pattern—such
        as a different number of inputs or different input data types.

        - #GOTCHA: A two functions with the same number and type of parameters
        is NOT overloading and will cause a 'redefinition' compile error.


    EX OUTPUT:

    USE CASES:
    - 

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void bakePizza(string bread, string sauce, string cheese, string topping) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << sauce << " ";
    cout << cheese << " ";
    cout << topping << " ";
    cout << " pizza" << endl;
}

void bakePizza(string bread, string sauce, string cheese) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << sauce << " ";
    cout << cheese << " ";
    cout << " pizza" << endl;
}

void bakePizza(string bread, string sauce) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << sauce << " ";
    cout << " pizza" << endl;
}

void bakePizza(string bread) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << " pizza" << endl;
}



int main() {

    string bread = "thicc crust";
    string sauce = "marinara";
    string cheese = "mozarella";
    string topping = "pepperoni";

    bakePizza(bread, sauce, cheese);

    cout << endl;
    return 0;
}

