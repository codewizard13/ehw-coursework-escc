#include <iostream>
using namespace std;

// Swap values in a with b
int main() {
  int a = 9;
  int b = 7;
  
  // store a in temp var
  int temp = a;
  a = b;
  b = temp;
  
  // Result: A = 7 and B = 9
  cout << "A = " << a << " and B = " << b;
  return 0;
}
