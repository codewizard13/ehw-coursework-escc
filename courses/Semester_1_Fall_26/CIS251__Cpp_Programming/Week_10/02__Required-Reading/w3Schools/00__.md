# C++ Inheritance


## Inheritance

**Inheritance** allows one class to reuse attributes and methods from another class. It helps you write cleaner, more efficient code by avoiding duplication.

We group the "inheritance concept" into two categories:

*   **derived class** (child) - the class that inherits from another class
*   **base class** (parent) - the class being inherited from

To inherit from a class, use the `:` symbol.

In the example below, the `Car` class (child) inherits the attributes and methods from the `Vehicle` class (parent):

### Example

```cpp
// Base class  
class Vehicle {  
  public:  
    string brand = "Ford";  
    void honk() {  
      cout << "Tuut, tuut! \\n" ;  
    }  
};  
  
// Derived class  
**class Car: public Vehicle** {  
  public:  
    string model = "Mustang";  
};  
  
int main() {  
  Car myCar;  
  myCar.honk();  
  cout << myCar.brand + " " + myCar.model;  
  return 0;  
}
```


#### Why And When To Use "Inheritance"?

- It is useful for code reusability: reuse attributes and methods of an existing class when you create a new class.

## Exercise? **What is this?**  
Test your skills by answering a few questions about the topics of this page

> In C++, inheritance allows a class to attributes and methods from another class.

`print` `delete` `inherit` `remove`

  

[❮ Previous](https://w3schools.com/cpp/cpp_friend_function.asp) [Next ❯](https://w3schools.com/cpp/cpp_inheritance_multilevel.asp)

