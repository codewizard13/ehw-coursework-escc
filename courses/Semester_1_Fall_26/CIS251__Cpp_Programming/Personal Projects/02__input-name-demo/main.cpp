#include <iostream>
using namespace std;

int main() {

	// Declare name variable
    string name;

	// Get name from user
    cout << "What is your name? ";
    
    // Store value
    cin >> name;
    
    // Output result with name
    cout << "Hi, " << name << ", nice to meet you!";

	return 0;
}