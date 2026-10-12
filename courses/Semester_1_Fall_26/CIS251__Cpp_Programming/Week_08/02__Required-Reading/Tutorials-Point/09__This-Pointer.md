# C++ this Pointer

- - -

- - -

[Previous](https://tutorialspoint.com/cplusplus/cpp_inline_functions.htm) | 
[Quiz](https://tutorialspoint.com/cplusplus/quiz_on_cpp_this_pointer.htm "Practice Quiz on C++ this Pointer") | 
[Next](https://tutorialspoint.com/cplusplus/cpp_friend_functions.htm)

## this Pointer

Every object in C++ has access to its own address through an important pointer called **this** pointer. The **this** pointer is an implicit parameter for all member functions. Therefore, inside a member function, this may be used to refer to the invoking object.

[Friend functions](https://tutorialspoint.com/cplusplus/cpp_friend_functions.htm) do not have a **this** pointer because friends are not members of a class. Only [member functions](https://tutorialspoint.com/cplusplus/cpp_class_member_functions.htm) have **this** pointer.


## Example of this Pointer

Let us try the following example to understand the concept of this pointer −

```cpp
#include <iostream>
 
using namespace std;

class Box {
   public:
      // Constructor definition
      Box(double l \= 2.0, double b \= 2.0, double h \= 2.0) {
         cout <<"Constructor called." << endl;
         length \= l;
         breadth \= b;
         height \= h;
      }
      double Volume() {
         return length \* breadth \* height;
      }
      int compare(Box box) {
         return this\->Volume() \> box.Volume();
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   if(Box1.compare(Box2)) {
      cout << "Box2 is smaller than Box1" <<endl;
   } else {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   
   return 0;
}
```

When the above code is compiled and executed, it produces the following result −

Constructor called.
Constructor called.
Box2 is equal to or larger than Box1

## Return Calling Object's Reference Using this Pointer

To implement chain function calls, you need the reference of a calling object. You can use the "**this**" pointer to return the reference of the calling object.

### Syntax

Here is the syntax:

```cpp
Test& Test::func ()
{
   return \*this;
}
```

### Example

The following example demonstrates how you can return the reference to the calling object:

```cpp
#include <iostream>
using namespace std;

class Coordinates {
 private:
  int latitude;
  int longitude;

 public:
  Coordinates(int lat \= 0, int lon \= 0) {
    this\->latitude \= lat;
    this\->longitude \= lon;
  }

  Coordinates& setLatitude(int lat) {
    latitude \= lat;
    return \*this;
  }

  Coordinates& setLongitude(int lon) {
    longitude \= lon;
    return \*this;
  }

  void display() const {
    cout << "Latitude = " << latitude << ", Longitude = " << longitude << endl;
  }
};

int main() {
  Coordinates location(15, 30);

  // Chained function calls modifying the same object
  location.setLatitude(40).setLongitude(70);

  location.display();
  return 0;
}
```

When the above code is compiled and executed, it produces the following result −

Latitude = 40, Longitude = 70

## Characteristics of the "this" Pointer

*   The **"this"** pointer refers to the current instance of the object, where it allows the member function to access the object's attributes and methods.
*   The **"this"** pointer is implicitly passed to all non-static member functions, where you don't need to explicitly write this in code.
*   **this** points to the memory location of the current object.
*   If there is a name conflict between a parameter and a member variable, this can be used to differentiate the member variable from the local parameter.
*   the **"this"** pointer is constant (const), meaning it cannot be modified.
*   Since **this** is a pointer, it can be dereferenced to access the current object.

## this Pointer in Const Member Functions Vs Static Member Functions

In const member functions, **this** pointer is a pointer to a constant object (const MyClass\*), where the object’s members cannot be modified within the function, resulting in an object remaining unchanged when calling const functions.

Whereas static member functions don't have **this** pointer because they are not associated with any specific instance of the class, they belong to the class itself and can only access static members or methods, as they do not operate on object-specific data.

### Example

Here is the given example representing both with **this** pointer in the Const member function Vs static member function.

```cpp
#include <iostream>

class MyClass {
   public:
      MyClass(int val) : data(val) {}

      // Const member function (has 'this' pointer, but it's a const pointer)
      void printData() const {
         std::cout << "Data: " << data << std::endl;  // 'this' points to a const object
         // Uncommenting the next line will cause an error because 'this' is const
         // data = 10;  // Error: cannot modify 'data' in a const member function
      }

      // Static member function (no 'this' pointer, operates on class-level data)
      static void showMessage() {
         std::cout << "This is a static function!" << std::endl;
         // Uncommenting the next line will cause an error because static functions can't access instance members
         // std::cout << "Data: " << data << std::endl;  // Error: 'data' is not accessible
      }

   private:
      int data;
};

int main() {
   MyClass obj(5);

   // Calling const member function (can access 'this' as const)
   obj.printData();  

   // Calling static member function (no 'this' pointer available)
   MyClass::showMessage();  

   return 0;
}
```

**Output**

```sh
Data: 5
This is a static function!
```

## Common Use Cases of this Pointer

In C++, **this** pointer is a special pointer, which refers to the current instances of a class in non-static member functions.

Here we will see its common use cases in the following.

*   **this** pointer helps in preventing self-assignment in assignment operators making sure that an object doesn’t assign itself to itself.
*   **this** pointer makes method chaining possible by returning the current object (usually through \*this), allowing you to call several methods on the same object in a single line of code.
*   It allows for direct access to the object’s members within member functions.
*   It is important in copy constructors and assignment operators, as it helps return the current object during assignments.
*   it is also useful in Polymorphism, Inherited Classes, and Implement Fluent Interfaces, allowing smooth method chaining.

## Limitations of this Pointer

The "**this"** pointer is a powerful feature in C++, but it has certain limitations and potential pitfalls that developers should keep in mind to prevent errors or unexpected behavior.

*   **this** pointer isn’t available in static member functions because static functions are tied to the class itself, not to any specific object.
*   It can help differentiate between member variables and local variables when their names overlap. However, if a local variable shadows a member variable, it can still lead to confusion or ambiguity.
*   **this** pointer always refers to the current object, but using it after the object is destroyed or while it’s being destroyed can cause undefined behavior.
*   When dealing with multiple inheritance, conflicts can occur if different base classes share members with identical names. This can make it unclear which member the **this** pointer is pointing to, leading to ambiguity.
*   Returning **\*this** from a temporary object can be risky since it might leave behind a dangling reference, which could cause unexpected or undefined behavior.