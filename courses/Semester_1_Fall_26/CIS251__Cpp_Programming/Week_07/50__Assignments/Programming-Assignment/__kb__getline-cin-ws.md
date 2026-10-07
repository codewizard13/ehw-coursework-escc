> ___________________
> ## Excerpt:
>
> ### 🧹 `cin >> ws`
> In `getline(cin >> ws, pFoods[i]);`, `ws` skips leftover newlines and leading spaces before reading your text. This prevents the newline left by `cin >> size` from becoming an empty entry. Spaces between words stay intact. [en.cppreference](https://en.cppreference.com/w/cpp/io/manip/ws)
> ___________________

### 🧹 `cin >> ws`: Clean up whitespace

Use this when switching from `cin >>` to `getline()`:

```cpp
getline(cin >> ws, pFoods[i]);
```

After `cin >> size`, the newline from pressing Enter remains in the input stream. Without cleanup, `getline()` reads that newline immediately and stores an empty string.

`ws` means “whitespace.” The expression `cin >> ws` skips leading whitespace—including spaces, tabs, and newlines—before `getline()` reads your text. [en.cppreference](https://en.cppreference.com/w/cpp/io/manip/ws)

For example, entering `peanut butter` stores the whole food name, including the space between the words.

Remember: `ws` also skips blank lines and spaces at the beginning of your input. It does not remove spaces between words. [en.cppreference](https://en.cppreference.com/w/cpp/io/manip/ws)