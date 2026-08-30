/* ************************************************************
    1.3.20 LAB Ints: operators and expressions
    Student: Eric Hepperle
    Created: 2026-08-29

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	int i, j, k;
	
	cout << "Enter i: ";
	cin >> i;
	cout << "Enter j: ";
	cin >> j;

    // // DEBUGGING: Fixed i, j values
    // i = 100;
    // j = 3;
	
	// increment i by 2
    i += 2;

    cout << "i += 2: " << i << endl;

	// decrement j by i
    j -= i;

    cout << "j -= i: " << j << endl;

	// divide i by j giving k
    k = i/j;

    cout << "k = i/j: " << k << endl;

	// increment k by k
    k += k;

	// decrement k by 1
    k--;

	// assign k modulo i to j
    j = k % i;

	// increment k by k added to i
    k += k + i;

	// increment k by k divided by j
    k += k/j;

	// assign k times k times k to k
    k = k * k * k;

	// increment k by i times j
    k += i * j;
	
	cout << "k = " << k << endl;
	return 0;
}