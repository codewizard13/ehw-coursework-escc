/**
 *
 *
 * ## Level of difficulty

Hard

## Objectives

Familiarize the student with:

*   using vectors in interactive problems;
*   and improve the student's skills in combining different kinds of loops.

## Scenario

Once upon a time there was a country called Plusplusland. The monetary system they used there was simple: the currency name was the "plussar" and their central bank issued five different banknotes of values 50, 20, 10, 5 and 1 plussar.

Your task is to write a driver for the ATMs of Plusplusland. The driver should find the minimal number of banknotes needed to deliver any amount of money to the client.

The Treasury Minister has asked you personally to do this. He expects your code to print the values of all the needed banknotes in a row – this is the format accepted by all ATMs in Plusplusland.

Test your code using the data we've provided.
 */

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

    // How many 50s?
    fifties = amount / 50;
    remainder = amount % 50;
    cout << "$" << amount << " needs " << fifties << " $50's | REMAINDER: $" << remainder << "\n";

    // twenties
    twenties = remainder / 20;
    cout << "$" << remainder << " needs " << twenties << " $20's";
    remainder = amount % 20;
     cout << " | REMAINDER: $" << remainder << "\n";

    // // tens
    // tens = remainder / 10;
    // remainder = amount % 10;
    // cout << "$" << amount << " needs " << tens << " $10's | REMAINDER: $" << remainder << "\n";

    // // 20s
    // twenties = remainder / 20;
    // remainder = amount % 20;

    // cout << "$" << amount << " needs " << fifties << " $50's | REMAINDER: $" << remainder << "\n";
    // cout << "$" << remainder << " needs " << twenties << " $20's\n";

    // // 20s
    // twenties = remainder / 20;
    // remainder = amount % 20;

    return 0;
}