# C++ Output (Print Text)

The `cout` object, together with the `<<` operator, is used to output values and print text.

Just remember to surround the text with double quotes (`""`):

### Example

```cpp
#include <iostream>  
using namespace std;  
  
int main() {  
  **cout** << "Hello World!";  
  return 0;  
}
```

You can add as many `cout` objects as you want. However, note that it does not insert a new line at the end of the output:

### Example

```cpp
#include <iostream>  
using namespace std;  
  
int main() {  
  **cout** << "Hello World!";  
  **cout** << "I am learning C++";  
  return 0;  
}
```

**Tip:** You will learn how to add new lines in the [C++ New Lines chapter](cpp_new_lines.asp).

- - -

