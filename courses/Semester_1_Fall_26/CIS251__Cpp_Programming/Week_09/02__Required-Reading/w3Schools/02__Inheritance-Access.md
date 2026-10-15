# C++ Inheritance Access

## Access Specifiers

You learned from the [Access Specifiers](https://w3schools.com/cpp/cpp_access_specifiers.asp) chapter that there are three specifiers available in C++.

Until now, we have only used `public` (members of a class are accessible from outside the class) and `private` (members can only be accessed within the class).

The third specifier, `protected`, is similar to `private`, but it can also be accessed in the **inherited** class:

### Example

```cpp
// Base class  
class Employee {  
  **protected: // Protected access specifier**  
    int salary;  
};  
  
// Derived class  
class Programmer: public Employee {  
  public:  
    int bonus;  
    void setSalary(int s) {  
      salary = s;  
    }  
    int getSalary() {  
      return salary;  
    }  
};  
  
int main() {  
  Programmer myObj;  
  myObj.setSalary(50000);  
  myObj.bonus = 15000;  
  cout << "Salary: " << myObj.getSalary() << "\\n";  
  cout << "Bonus: " << myObj.bonus << "\\n";  
  return 0;  
}
```

## Exercise? **What is this?**  
Test your skills by answering a few questions about the topics of this page

What is the purpose of the protected access specifier in C++?

  

- ( ) To allow access from outside the class

- ( ) To allow access only within the class

- ( ) To allow access within the class and in derived classes

- ( ) To create a private copy of class attributes

  
Submit Answer »

- - -

  

[❮ Previous](https://w3schools.com/cpp/cpp_inheritance_multiple.asp) [Next ❯](https://w3schools.com/cpp/cpp_polymorphism.asp)

[★ +1](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_inheritance_access.asp "Your W3Schools Profile")

[Sign in to track progress](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fpathfinder.w3schools.com&origin=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_inheritance_access.asp "Sign in to track your progress")
