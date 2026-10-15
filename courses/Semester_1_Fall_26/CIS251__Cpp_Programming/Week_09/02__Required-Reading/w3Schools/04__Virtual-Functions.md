# C++ Virtual Functions


## C++ Virtual Functions

A **virtual function** is a member function in the base class that can be **overridden** in derived classes.

Virtual functions are a key part of [polymorphism](https://w3schools.com/cpp/cpp_polymorphism.asp) in C++. They let different objects respond differently to the same function call.

- - -

## Why Use Virtual Functions?

Without `virtual`, C++ decides which function to call based on the pointer type, not the actual object type.

With `virtual`, it checks the actual object the pointer is pointing to.

Or to put it even more simply:

*   **Without** `virtual`: the base function runs, even if the object is from a child class.
*   **With** `virtual`: the child's version runs, like you expect.

- - -

## Without Virtual Function

### Example (No virtual keyword)

```cpp
class Animal {  
  public:  
    void sound() {  
      cout << "Animal sound\\n";  
    }  
};  
  
class Dog : public Animal {  
  public:  
    void sound() {  
      cout << "Dog barks\\n";  
    }  
};  
  
int main() {  
  Animal\* a;  // Declare a pointer to the base class (Animal)  
  Dog d;  // Create an object of the derived class (Dog)  
  a = &d;  // Point the base class pointer to the Dog object  
  a->sound(); // Call the sound() function using the pointer. Since sound() is not virtual, this calls Animal's version  
  return 0;  
}
```

Even though `a` points to a `Dog`, it still calls `Animal::sound()` because the function is not virtual.

## With Virtual Function

### Example (With virtual keyword)

```cpp
class Animal {  
  public:  
    **virtual** void sound() {  
      cout << "Animal sound\\n";  
    }  
};  
  
class Dog : public Animal {  
  public:  
    void sound() override {  
      cout << "Dog barks\\n";  
    }  
};  
  
int main() {  
  Animal\* a;  
  Dog d;  
  a = &d;  
  a->sound(); // Outputs: Dog barks  
  return 0;  
}
```

**Now it works!** Because `sound()` is `virtual`, the call uses the actual object's function and not just the pointer type.

*   Use `virtual` only in the base class
*   Use `override` (optional, but recommended) in the derived class for clarity

## The `->` Operator in C++

You might be wondering why we used `->` in the examples above.

The `->` operator is used to access members (like functions or variables) through a [pointer](https://w3schools.com/cpp/cpp_pointers.asp).

It's a shortcut for writing `(*pointer).member`:

```cpp
Animal\* a = new Animal();  
a->sound(); // Same as (\*a).sound();
```

**Tip:** If you are using a pointer to an object, use `->` to access its members.

- - -

  

[❮ Previous](https://w3schools.com/cpp/cpp_inheritance_access.asp) [Next ❯](https://w3schools.com/cpp/cpp_templates.asp)

[★ +1](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_virtual_functions.asp "Your W3Schools Profile")

[Sign in to track progress](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fpathfinder.w3schools.com&origin=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_virtual_functions.asp "Sign in to track your progress")
