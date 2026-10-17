An underscore at the beginning of a variable name—such as `_count`—is called a **leading underscore**. In C++, it often serves as a naming convention for a class member variable, especially a private one. It does not, by itself, make the variable private or change how it behaves. [stackoverflow](https://stackoverflow.com/questions/3136594/naming-convention-underscore-in-c-and-c-sharp-variables)

## 🔎 Useful search terms

These phrases should produce more relevant results than searching for the `_` character itself:

- `C++ leading underscore naming convention`
- `C++ underscore prefix member variables`
- `C++ reserved identifiers underscore` — for the language rules and restrictions. [stackoverflow](https://stackoverflow.com/questions/3136594/naming-convention-underscore-in-c-and-c-sharp-variables)

## 💻 What it usually means in code

For example:

```cpp
class Counter {
private:
    int _count;

public:
    Counter(int count) : _count(count) {}
};
```

Here, `_count` is the object's member variable, while `count` is the constructor parameter. The underscore helps a reader distinguish them. The `private:` access specifier—not the underscore—makes `_count` private. Different projects use different naming conventions, so the prefix is a clue rather than a guarantee. [stackoverflow](https://stackoverflow.com/questions/3136594/naming-convention-underscore-in-c-and-c-sharp-variables)

## ⚠️ C++ has special restrictions

Some underscore-containing names are reserved for the implementation—the compiler and its supporting libraries: [devblogs.microsoft](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685/)

| Name pattern | C++ restriction |
|---|---|
| `_count` | Reserved when used as a name in the global namespace; permitted as a class member or local variable. |
| `_Count` | An underscore followed by an uppercase letter is reserved everywhere. |
| `__count` or `some__count` | A double underscore anywhere in the name is reserved everywhere. |

Consequently, a common alternative for member variables is a trailing underscore, such as `count_`. This still distinguishes the member from a parameter named `count`, without the leading-underscore pitfalls above. [stackoverflow](https://stackoverflow.com/questions/3136594/naming-convention-underscore-in-c-and-c-sharp-variables)