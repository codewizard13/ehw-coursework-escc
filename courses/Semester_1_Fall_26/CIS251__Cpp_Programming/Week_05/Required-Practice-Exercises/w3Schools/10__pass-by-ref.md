# C++ Functions - Pass By Reference

## Pass By Reference

In the examples from the previous page, we used normal variables when we passed parameters to a function.

You can also pass a [reference](cpp_references.asp) to the function.

This can be useful when you need to change the value of the argument(s):

### Example

Pass an integer by reference:

```cpp
void changeValue(int &num) {  
  num = 50;  
}  
  
int main() {  
  int value = 10;  
  changeValue(value);  // Call the function and change the value to 50  
  cout << value;   
  return 0;  
}  
```


### Example

Pass two integers by reference:

```cpp
void swapNums(int &x, int &y) {  
  int z = x;  
  x = y;  
  y = z;  
}  
  
int main() {  
  int firstNum = 10;  
  int secondNum = 20;  
  
  cout << "Before swap: " << "\\n";  
  cout << firstNum << secondNum << "\\n";  
  
  // Call the function, which will change the values of firstNum and secondNum  
  swapNums(firstNum, secondNum);  
  
  cout << "After swap: " << "\\n";  
  cout << firstNum << secondNum << "\\n";  
  
  return 0;  
}  
```


### Example

Pass a string by reference:

```cpp
void modifyStr(string &str) {  
  str += " World!";  
}  
  
int main() {  
  string greeting = "Hello";  
  modifyStr(greeting);  
  cout << greeting;  
  return 0;  
}  
```

