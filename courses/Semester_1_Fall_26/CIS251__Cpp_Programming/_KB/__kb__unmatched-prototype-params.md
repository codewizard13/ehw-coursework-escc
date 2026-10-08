## 🧠 C++ Sidebar: Prototype Parameter Names Don’t Have to Match

**#GOTCHA:**
A function prototype tells the compiler how a function can be called. Parameter **names** are optional in the prototype and do not have to match the names in the definition.

### Example

```cpp
// Prototype
void printGroceryItems(string *foods, int size);

// Definition
void printGroceryItems(string *pFoods, int itemsAddedCount)
{
    // Use pFoods and itemsAddedCount here.
}
```

These match because they have the same:

- Function name: `printGroceryItems`
- Return type: `void`
- Parameter types, in order: `string*`, then `int`

The different names—`foods` versus `pFoods`, and `size` versus `itemsAddedCount`—do not cause a compiler error.

### Names Can Be Omitted

This prototype describes the same function:

```cpp
void printGroceryItems(string*, int);
```

### Practical Rule

Use matching, meaningful parameter names for readability, but remember: the compiler checks the types and order, not whether the parameter names match.