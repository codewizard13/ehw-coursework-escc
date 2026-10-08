### 🔍 Pointer dereferencing versus array size

In C++, a dynamically allocated array can be accessed through a pointer:

```cpp
int count = 3;
string* items = new string[count];
items[0] = "apple";
items [tool.oschina](https://tool.oschina.net/uploads/apidocs/cpp/en/cpp/string/basic_string/size.html) = "bread";
items [en.cppreference](https://en.cppreference.com/cpp/language/new) = "milk";
```

The variable `items` holds the address of the first string. Calling `items.size()` fails because a pointer has no `.size()` member function.

Dereferencing the pointer accesses the first string—not the whole array. These expressions are equivalent:

```cpp
(*items).size()
items->size()
items[0].size()
```

Each returns `5`: the number of characters in `"apple"`. A string’s `.size()` measures its character count, not how many strings an array contains. [tool.oschina](https://tool.oschina.net/uploads/apidocs/cpp/en/cpp/string/basic_string/size.html)

Keep three measurements separate:

- Allocated slots: retain the requested array length in `count`.
- Successfully stored entries: increment a separate counter after each successful read.
- Characters in one entry: use `items[i].size()`.

Dereferencing does not recover an array’s length. It only accesses the object at the pointed-to address.

When finished, release the array:

```cpp
delete[] items;
```

### 💻 Complete MVP example

Using your course’s `<iostream>`-only convention:

```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int stored = 0;

    cout << "How many foods (1-10)? ";
    if (!(cin >> count) || count < 1 || count > 10) {
        cout << "Invalid count.\n";
        return 1;
    }

    string* items = new string[count];

    for (int i = 0; i < count; i++) {
        cout << "Enter food #" << i + 1 << ": ";
        if (!getline(cin >> ws, items[i])) {
            break;
        }
        stored++;
    }

    cout << "Allocated slots: " << count << '\n';
    cout << "Stored entries: " << stored << '\n';

    for (int i = 0; i < stored; i++) {
        cout << items[i] << ": "
             << items[i].size() << " characters\n";
    }

    delete[] items;
    return 0;
}
```