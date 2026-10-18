/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Cisco Networking Academy - C++
    2.8.5 LAB:  Collecting banknotes

    Student: Eric Hepperle
    Created: 2026-10-18

    VERSION: 1.0

    STATUS: WIP

    Instructions:
     - Write a C++ ATM program that dispenses a requested amount of plussars
         using the **minimum** number of banknotes, with available
         denominations of 50, 20, 10, 5, and 1.
     - Practice using vectors and combining different kinds of loops to
         determine which banknotes to dispense.
     - Print the value of each required banknote in a single row, then test
         your program using the provided test data.

    - Full instructions: ./00_instructions.md

    Sample Output:

    $125 needs 2 $50's | REMAINDER: $25
    $25 needs 1 $20's | REMAINDER: $5
    $5 needs 0 $10's | REMAINDER: $5
    $5 needs 1 $5's | REMAINDER: $0
    $0 needs 0 $1's | REMAINDER: $0

    Lessons Learned & Notes:
    - 

    FUTURE IMPROVEMENTS:
    - ...

    GitHub: https://github.com/codewizard13
 ************************************************************ */


/*

#include <iostream>
using namespace std;

int findMinNoteSet(int amount);

int main()
{
    // Your code goes here.

    // Print how many bills needed and what denominations
    findMinNoteSet(125);

    return 0;
}

/**
 * @input amount amount of money
 */

int findMinNoteSet(int amount)
{

    int remainder,
        fifties, twenties, tens, fives, ones;

    cout << "************ BILLS for $" << amount << " ***********\n";

    // How many 50s?
    fifties = amount / 50;
    remainder = amount % 50;
    cout << "$" << amount << " needs " << fifties << " $50's | REMAINDER: $" << remainder << "\n";

    // twenties
    twenties = remainder / 20;
    cout << "$" << remainder << " needs " << twenties << " $20's";
    remainder = amount % 20;
    cout << " | REMAINDER: $" << remainder << "\n";

    // tens
    tens = remainder / 10;
    cout << "$" << remainder << " needs " << tens << " $10's";
    remainder = amount % 10;
    cout << " | REMAINDER: $" << remainder << "\n";

    // fives
    fives = remainder / 5;
    cout << "$" << remainder << " needs " << fives << " $5's";
    remainder = amount % 5;
    cout << " | REMAINDER: $" << remainder << "\n";

    // ones
    ones = remainder / 1;
    cout << "$" << remainder << " needs " << ones << " $1's";
    remainder = amount % 1;
    cout << " | REMAINDER: $" << remainder << "\n";


    return 0;
}