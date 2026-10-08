## 📌 Sidebar: Null, Uninitialized, and Dangling Pointers in C++

A pointer stores an address, but having an address does not guarantee that an object can safely be accessed through it. Three important problem states are null, uninitialized, and dangling pointers. [cs.odu](https://www.cs.odu.edu/~zeil/cs260/latest/Public/pointers/index.html)

### 🔍 Three pointer states compared

| State | Beginner-friendly meaning | Example inside a function |
|---|---|---|
| Null | “I am explicitly pointing to nothing.” | `int* p = nullptr;` |
| Uninitialized | “No starting value was assigned, so my value is not reliable.” | `int* p;` |
| Dangling | “I used to point to a valid object, but that object no longer exists.” | A pointer after the object it pointed to was deleted |

A **dangling pointer** retains an outdated address after its target object’s lifetime ends. Unlike an uninitialized pointer, it previously pointed to a valid object. Unlike a null pointer, it has not been explicitly set to point to nothing. [learncpp](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)

### 💻 Example: An array pointer after deletion

```cpp
#include <iostream>
#include <string>

int main() {
    std::string* foods = nullptr; // Null: points to no object.

    foods = new std::string [learncpp](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/){"Apples", "Bread"};
    std::cout << foods[0] << '\n'; // Safe: the array exists.

    delete[] foods;               // The array is gone; foods is dangling.

    // std::cout << foods[0];     // Unsafe: accessing a deleted array.

    foods = nullptr;             // Null again: clears the outdated address.
}
```

`delete[] foods` destroys the array and releases its memory. It does not automatically change the address stored in `foods`. The following assignment to `nullptr` clears that outdated address; it does not free the memory a second time. [cs.odu](https://www.cs.odu.edu/~zeil/cs260/latest/Public/pointers/index.html)

### ⚠️ Why a null check is not enough

This check only asks whether a pointer is null:

```cpp
if (foods != nullptr) {
    // This alone does NOT prove the array still exists.
}
```

After deletion—and before assigning `nullptr`—the pointer can still pass that check even though the array is gone. Accessing the deleted array causes undefined behavior: C++ does not guarantee a particular outcome. [cs.odu](https://www.cs.odu.edu/~zeil/cs260/latest/Public/pointers/index.html)

### 🧠 Dangling pointer versus memory leak

- Dangling pointer: The object no longer exists, but a pointer still holds its old address.
- Memory leak: Dynamically allocated memory was not released when it was no longer needed, often because the program lost track of it. [ouyi.github](https://ouyi.github.io/post/2011/03/01/typical-cpp-pointer-issues.html)

Remember the distinction: “released memory, outdated pointer” versus “memory never released.”