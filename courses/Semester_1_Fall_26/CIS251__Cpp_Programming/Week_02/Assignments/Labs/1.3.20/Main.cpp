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
	
	// increment i by 2
    i++;

    cout << "i++ = " << i;

	// decrement j by i
    j--;

	// divide i by j giving k
    k = i/j;

	// increment k by k
    k += k;

	// decrement k by 1
    k--;

	// assign k modulo i to j
    j = k % i;

	// increment k by k added to i
    k += i;

	// increment k by k divided by j
    k /= j;

	// assign k times k times k to k
    k *= k * k * k;

	// increment k by i times j
    k += i * j;
	
	cout << k;
	return 0;
}