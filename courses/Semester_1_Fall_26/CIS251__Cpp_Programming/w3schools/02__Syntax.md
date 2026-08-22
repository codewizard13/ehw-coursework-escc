# C++ Syntax

Let's break up the following code to understand it better:

### Example

```cpp
#include <iostream>  
using namespace std;  
  
int main() {  
  cout << "Hello World!";  
  return 0;  
}
```

### Example explained

**Line 1:** `#include <iostream>` is a **header file library** that lets us work with input and output objects, such as `cout` (used in line 5). Header files add functionality to C++ programs.

**Line 2:** `using namespace std` means that we can use names for objects and variables from the standard library.

Don't worry if you don't understand how `#include <iostream>` and `using namespace std` works. Just think of it as something that (almost) always appears in your program.

**Line 3:** A blank line. C++ ignores white space. But we use it to make the code more readable.

**Line 4:** Another thing that always appear in a C++ program is `int main()`. This is called a **function**. Any code inside its curly brackets `{}` will be executed.

**Line 5:** `cout` (pronounced "see-out") is an **object** used together with the _insertion operator_ (`<<`) to output/print text. In our example, it will output "Hello World!".

**Note:** C++ is case-sensitive: "cout" and "Cout" has different meaning.

**Note:** Every C++ statement ends with a semicolon `;`.

**Note:** The body of `int main()` could also been written as:  
`int main () { cout << "Hello World! "; return 0; }`

**Remember:** The compiler ignores white spaces. However, multiple lines makes the code more readable.

**Line 6:** `return 0;` ends the main function.

**Line 7:** Do not forget to add the closing curly bracket `}` to actually end the main function.

- - -

## Omitting Namespace

You might see some C++ programs that run without the standard namespace line. The `using namespace std;` statement can be omitted, and replaced with the `std` keyword followed by the `::` operator, for some objects (like `std::cout` in the example below):

### Example

```cpp
#include <iostream>  
  
int main() {  
  std::cout << "Hello World!";  
  return 0;  
}
```

Both approaches are valid in C++. Using `std::` makes it clear where names come from and avoids name conflicts in larger programs.

### Which One Do We Use?

In this tutorial, we will mostly use `using namespace std;`

This keeps the code shorter and easier to read while learning the basics of C++. It helps beginners focus on understanding the language itself, instead of repeatedly writing `std::` in every example.

As you write larger or more advanced programs, you may prefer using `std::` explicitly. You will see both styles in real-world C++ code.

