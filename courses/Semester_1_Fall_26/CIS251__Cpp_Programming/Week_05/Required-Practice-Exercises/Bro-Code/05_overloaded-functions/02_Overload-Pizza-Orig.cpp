/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    PRACTICE EXERCISES - BRO CODE:
    
    OVERLOADED FUNCTIONS:
   
    Source: https://www.youtube.com/watch?v=Mfyt_x9MjiY

    Student: Eric Hepperle
    Created: 2026-09-20

    PURPOSE: My notes on BroCode C++ topics.
    - This is Bro Code's actual code from the comments section.

    NOTES:
        - function overloading: using the same function name with different parameter sets.


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

void bakePizza(string bread) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << "pizza";
}

void bakePizza(string bread, string sauce) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << sauce << " ";
    cout << "pizza";
}

void bakePizza(string bread, string sauce, string cheese) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << sauce << " ";
    cout << cheese << " ";
    cout << "pizza";
}

void bakePizza(string bread,string sauce,string cheese,string topping) {

    cout << "Here is your ";
    cout << bread << " ";
    cout << sauce << " ";
    cout << cheese << " ";
    cout << topping << " ";
    cout << "pizza";
}

int main()
{
    string bread = "thicc crust";
    string sauce = "bbq";
    string cheese = "mozzerella";
    string topping = "chicken";

    bakePizza(bread,sauce,cheese,topping);

    cout << endl;
    return 0;
}

