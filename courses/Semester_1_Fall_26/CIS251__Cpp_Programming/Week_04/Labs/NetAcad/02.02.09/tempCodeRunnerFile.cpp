#include <iostream>
#include <iomanip>
using namespace std;


int main () {

    // DEFINE VARIABLES
    unsigned long result = 2;
    short pow;
    
    // GET POWER NUBMER FROM USER
    cout << endl;
    cout << "Enter the power of 2 to calculate: ";

    // RECEIVE & VALIDATE INPUT
    if (!(cin >> result) || result <= 0) {
        cout << "Invalid input: Must be a positive number - You entered [ " << pow <<  " ]\n\n";
        return 0;
    }

    // PROCESS EXPONENT VALUE
    for ( int i = 0; i < pow; i++) {
        cout << "i: " << i << " | pow: " << pow << endl;
    }


    cout << "\n\n";
    return 0;
}