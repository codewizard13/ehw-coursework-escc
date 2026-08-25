# C++ Basic Syntax

When we consider a C++ program, it can be defined as a collection of objects that communicate via invoking each other's methods. Let us now briefly look into what a class, object, method, and instance variable mean.

- **Object** − Objects have states and behaviors. Example: A dog has states (color, name, breed) as well as behaviors (wagging, barking, eating). An object is an instance of a class.
- **Class** − A class can be defined as a template/blueprint that describes the behaviors or states that object of its type supports.
- **Methods** − A method is basically a behavior. A class can contain many methods. It is in methods where the logics are written, data is manipulated, and all the actions are executed.
- **Instance Variables** − Each object has its own unique set of instance variables. An object's state is created by the values assigned to these instance variables.

## C++ Program Structure

The basic structure of a C++ program consists of the following parts:

- **Header file inclusion section**: This is the section where we include all required header files whose functions we are going to use in the program.
- **Namespace section**: This is the section where we use the namespace.
- **The main() section**: In this section, we write our main code. The main() function is an entry point of any C++ programming code from where the program's execution starts.

To learn more about it, read: [C++ Hello, World Program](/cplusplus/cpp_hello_world_program.htm).

### Example

Let us look at a simple code that would print the words _Hello World_.

```cpp
#include <iostream>
using namespace std;

// main() is where program execution begins.
int main() {
   cout << "Hello World"; // prints Hello World
   return 0;
}
```

### Example Explanation

Let us look at the various parts of the above program −

- The C++ language defines several headers, which contain information that is either necessary or useful to your program. For this program, the header [**<iostream>**](/cpp_standard_library/iostream.htm) is needed.
- The line **using namespace std;** tells the compiler to use the std namespace. Namespaces are a relatively recent addition to C++.
- The next line '**// main() is where program execution begins.**' is a single-line comment available in C++. Single-line comments begin with // and stop at the end of the line.
- The line **int main()** is the main function where program execution begins.
- The next line **cout << "Hello World";** causes the message "Hello World" to be displayed on the screen.
- The next line **return 0;** terminates main() function and causes it to return the value 0 to the calling process.

## Compile and Execute C++ Program

Let's look at how to save the file, compile and run the program. Please follow the steps given below −

- Open a text editor and add the code as above.
- Save the file as: hello.cpp
- Open a command prompt and go to the directory where you saved the file.
- Type **`g++ hello.cpp`** and press enter to compile your code. If there are no errors in your code the command prompt will take you to the next line and would generate a.out executable file.
- Now, type 'a.out' to run your program.
- You will be able to see ' Hello World ' printed on the window.

```sh
$ g++ hello.cpp
$ ./a.out
Hello World
```

Make sure that g++ is in your path and that you are running it in the directory containing file hello.cpp.

You can compile C/C++ programs using makefile. For more details, you can check our ['Makefile Tutorial'](https://www.tutorialspoint.com/makefile/index.htm).

## Semicolons and Blocks in C++

In C++, the semicolon is a **statement terminator**. That is, each individual statement must be ended with a semicolon. It indicates the end of one logical entity.

For example, following are three different statements −

```cpp
x = y;
y = y + 1;
add(x, y);
```

A block is a set of logically connected statements that are surrounded by opening and closing braces. For example −

```cpp
{
   cout << "Hello World"; // prints Hello World
   return 0;
}
```

C++ does not recognize the end of the line as a terminator. For this reason, it does not matter where you put a statement in a line. For example −

```cpp
x = y;
y = y + 1;
add(x, y);
```

is the same as

```cpp
x = y; y = y + 1; add(x, y);
```

## C++ Identifiers

A C++ identifier is a name used to identify a variable, function, class, module, or any other user-defined item. An identifier starts with a letter A to Z or a to z or an underscore (\_) followed by zero or more letters, underscores, and digits (0 to 9).

C++ does not allow punctuation characters such as @, $, and % within identifiers. C++ is a case-sensitive programming language. Thus, **Manpower** and **manpower** are two different identifiers in C++.

Here are some examples of acceptable identifiers −

> mohd zara abc move_name a_123
> myname50 \_temp j a23b9 retVal

## C++ Keywords

The following list shows the reserved words in C++. These reserved words may not be used as constant or variable or any other identifier names.

|              |           |                  |          |
| ------------ | --------- | ---------------- | -------- |
| asm          | else      | new              | this     |
| auto         | enum      | operator         | throw    |
| bool         | explicit  | private          | true     |
| break        | export    | protected        | try      |
| case         | extern    | public           | typedef  |
| catch        | false     | register         | typeid   |
| char         | float     | reinterpret_cast | typename |
| class        | for       | return           | union    |
| const        | friend    | short            | unsigned |
| const_cast   | goto      | signed           | using    |
| continue     | if        | sizeof           | virtual  |
| default      | inline    | static           | void     |
| delete       | int       | static_cast      | volatile |
| do           | long      | struct           | wchar_t  |
| double       | mutable   | switch           | while    |
| dynamic_cast | namespace | template         |          |

## Trigraphs

A few characters have an alternative representation, called a trigraph sequence. A trigraph is a three-character sequence that represents a single character and the sequence always starts with two question marks.

Trigraphs are expanded anywhere they appear, including within string literals and character literals, in comments, and in preprocessor directives.

Following are most frequently used trigraph sequences −

| Trigraph | Replacement |
| -------- | ----------- |
| ??=      | #           |
| ??/      | \\          |
| ??'      | ^           |
| ??(      | \[          |
| ??)      | \]          |
| ??!      | \|          |
| ??<      | {           |
| ??>      | }           |
| ??-      | ~           |

- ⚠️ #GOTCHA: **All the compilers do not support trigraphs** and they are not advised to be used because of their confusing nature.

## Whitespace in C++

A line containing only whitespace, possibly with a comment, is known as a blank line, and C++ compiler totally ignores it.

Whitespace is the term used in C++ to describe blanks, tabs, newline characters and comments. Whitespace separates one part of a statement from another and enables the compiler to identify where one element in a statement, such as int, ends and the next element begins.

### Statement 1

```cpp
int age;
```

In the above statement there must be at least one whitespace character (usually a space) between int and age for the compiler to be able to distinguish them.

### Statement 2

```cpp
fruit = apples + oranges; // Get the total fruit
```

In the above statement 2, no whitespace characters are necessary between fruit and =, or between = and apples, although you are free to include some if you wish for readability purpose.

## C++ Program Structure with Object-oriented Approach

C++ also supports the object-oriented programming approach along with the procedural programming approach.

### Example

This example demonstrates the C++ program based on an object-oriented approach.

```cpp
#include <iostream>
using namespace std;

class Numbers {
private:
int a;
int b;

public:
// Function to set values
void setValues(int x, int y) {
a = x;
b = y;
}

// Function to add these numbers
double addition() { return a + b; }

// Function to display values
void display() { cout << "a: " << a << ", b: " << b << endl; }
};

int main() {
// Create an object of Numbers class
Numbers num;

// Set values
num.setValues(10, 20);

// Display the values
num.display();

// Find the addition
int sum = num.addition();
cout << "Sum of numbers: " << sum << endl;

return 0;
}
```

## Parts of C++ Program Structure with Object-oriented Approach

The different parts of the C++ program structure with an object-oriented approach are as follows:

### 1. Class Declaration

A [class](/cplusplus/cpp_classes_objects.htm) is a template for an object, or we can say a class is a factory to produce an object. It is a kind of custom data type, where you construct a structure for an object.

A class declaration has the following parts:

- [**Access modifiers**](/cplusplus/cpp_class_access_modifiers.htm): C++ supports three types of access modifiers: _**private**_, _**public**_, and _**protected**_. Accessibilities of the data members and member functions are defined by the access modifiers.
- **Data members and member functions**: The variables used in the class declaration are known as data members, and the member functions are those functions that work on the data members.

### Example

As per the above example, the following part of the declaration of a class –

```cpp
class Numbers {
private:
int a;
int b;

public:
// Function to set values
void setValues(int x, int y) {
a = x;
b = y;
}

// Function to add these numbers
double addition() { return a + b; }

// Function to display values
void display() { cout << "a: " << a << ", b: " << b << endl; }
};
```

The following are the data members which are defined under the _**private**_ access modifier i.e., these data members can be used by the member functions within the class –

```cpp
private:
int a;
int b;
```

The following are the member functions used in the class –

```cpp
void setValues(int x, int y);
double addition();
void display();
```

### 2. Object Creation

In the above example, the following statement is the object creation statement −

```cpp
Numbers num;
```
