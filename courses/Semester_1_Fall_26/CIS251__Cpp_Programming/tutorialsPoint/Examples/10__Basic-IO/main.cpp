// Source: https://www.tutorialspoint.com/cplusplus/cpp_basic_input_output.htm
#include <bits/stdc++.h>
using namespace std;
int main() {
  int number;
  string name;

  // #include <iostream>
  // #include <string>
  cout << "Welcome to TutorialsPoint!" << endl;

  // Input of user's name and number
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Please enter a number: ";
  cin >> number;
  cout << "Hello," << name << " You entered " << number << endl;

  // Demonstrating some STL features
  // #include <vector>
  vector<int> numbers;
  cout << "Enter 4 numbers: ";

  for (int i = 0; i < 4; ++i) {
    int temp;
    cin >> temp;
    numbers.push_back(temp);
  }
  cout << "You entered the following numbers: ";
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  // Sort and display the numbers
  // #include <algorithm>
  sort(numbers.begin(), numbers.end());
  cout << "Sorted numbers: ";
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}