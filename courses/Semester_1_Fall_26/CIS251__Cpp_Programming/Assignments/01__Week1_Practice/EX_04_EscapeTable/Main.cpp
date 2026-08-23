/*
    Student: Eric Hepperle
    Date: 2026-08-22
    Status: 

    Assignment: Week 1 - Getting Started - Practice Exercise 4 - Data Table / Columns

    - Use escape sequences to create a table with name and age

*/
#include <iostream>
using namespace std;

int main()
{
    int age = 10;
    string name = "Angie";

    cout << "Name" << '\t' << "Age" << '\n';
    cout << "Alice" << '\t' << 20 << '\n';
    cout << "Bob" << '\t' << 22 << '\n';

    return 0;
}