### 🔍 `NULL` versus `nullptr`

Both make a pointer point to no object:

```cpp
int* first = NULL;
int* second = nullptr;
```

The difference is how C++ understands the value:

- `NULL` is a macro, often defined as integer `0`. That can cause confusion when choosing between functions accepting integers or pointers. [en.cppreference](https://en.cppreference.com/cpp/types/NULL)
- `nullptr` is a keyword introduced in C++11 specifically for null pointers. It requires no extra header and avoids that integer confusion. [cppreference](https://cppreference.com/cpp/language/nullptr)

Prefer `nullptr` in modern C++, unless your course requires `NULL`.

### 💻 Complete MVP example

```cpp
#include <iostream>
using namespace std;

int main() {
    int* number = nullptr;  // No object yet.

    number = new int(42);
    cout << *number << '\n';

    delete number;         // Release the object.
    number = nullptr;      // Reset the pointer.

    return 0;
}
```

Assigning `nullptr` does not free allocated memory. Delete the allocation first; otherwise, you can lose access to it and leak memory.