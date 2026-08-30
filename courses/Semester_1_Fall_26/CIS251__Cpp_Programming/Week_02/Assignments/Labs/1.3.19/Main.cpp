/* ************************************************************
    1.3.19 LAB Floats: operators and expressions
    Student: Eric Hepperle
    Created: 2026-08-29

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	float pi = 3.14159265359;
	float x,y;

	cout << "Enter value for x: ";
	cin >> x;
	
	float x_squared = x*x;
	float pi_squared = pi*pi;

	// put your code here
	float right_den = pi_squared * ((x_squared - (1.0f/2.0f))*(x_squared - (1.0f/2.0f)));
	float right = 1.0f + (x_squared/right_den);
	float left = x_squared / (pi_squared * (x_squared + (1.0f/2.0f)));

	y = left * right;
	
	cout << "y = " << y;

	return 0;
}