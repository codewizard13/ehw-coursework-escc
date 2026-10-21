# C++ Data Types

[Previous](https://www.tutorialspoint.com/cplusplus/cpp_identifiers.htm) |
[Quiz](https://www.tutorialspoint.com/cplusplus/quiz_on_cpp_data_types.htm "Practice Quiz on C++ Data Types") |
[Next](https://www.tutorialspoint.com/cplusplus/cpp_numeric_data_types.htm)

While writing program in any language, you need to use various [variables](https://www.tutorialspoint.com/cplusplus/cpp_variable_types.htm) to store various information. Variables are nothing but reserved memory locations to store values. This means that when you create a variable you reserve some space in memory.

You may like to store information of various data types like character, wide character, integer, floating point, double floating point, boolean etc. Based on the data type of a variable, the operating system allocates memory and decides what can be stored in the reserved memory.

## Primitive Built-in Types

C++ offers the programmer a rich assortment of built-in as well as user defined data types. Following table lists down seven basic C++ data types −

| Type                                                                                   | Keyword |
| -------------------------------------------------------------------------------------- | ------- |
| [Boolean](https://www.tutorialspoint.com/cplusplus/cpp_boolean_bool_data_type.htm)     | bool    |
| [Character](https://www.tutorialspoint.com/cplusplus/cpp_character_char_data_type.htm) | char    |
| [Integer](https://www.tutorialspoint.com/cplusplus/cpp_numeric_data_types.htm)         | int     |
| Floating point                                                                         | float   |
| Double floating point                                                                  | double  |
| Valueless                                                                              | void    |
| Wide character                                                                         | wchar_t |

Several of the basic types can be modified using one or more of these type modifiers −

- signed
- unsigned
- short
- long

The following table shows the variable type, how much memory it takes to store the value in memory, and what is maximum and minimum value which can be stored in such type of variables.

| Type                   | Typical Bit Width | Typical Range                                |
| ---------------------- | ----------------- | -------------------------------------------- |
| char                   | 1byte             | -127 to 127 or 0 to 255                     |
| unsigned char          | 1byte             | 0 to 255                                     |
| signed char            | 1byte             | -127 to 127                                 |
| int                    | 4bytes            | -2147483648 to 2147483647                   |
| unsigned int           | 4bytes            | 0 to 4294967295                              |
| signed int             | 4bytes            | -2147483648 to 2147483647                   |
| short int              | 2bytes            | -32768 to 32767                             |
| unsigned short int     | 2bytes            | 0 to 65,535                                  |
| signed short int       | 2bytes            | -32768 to 32767                             |
| long int               | 8bytes            | -9223372036854775808 to 9223372036854775807 |
| signed long int        | 8bytes            | same as long int                             |
| unsigned long int      | 8bytes            | 0 to 18446744073709551615                    |
| long long int          | 8bytes            | -(2^63) to (2^63)-1                         |
| unsigned long long int | 8bytes            | 0 to 18,446,744,073,709,551,615              |
| float                  | 4bytes            |                                              |
| double                 | 8bytes            |                                              |
| long double            | 12bytes           |                                              |
| wchar_t                | 2 or 4 bytes      | 1 wide character                             |

The size of variables might be different from those shown in the above table, depending on the compiler and the computer you are using.

### Example

Following is the example, which will produce correct size of various data types on your computer.

```cpp
#include <iostream>
using namespace std;

int main() {
cout << "Size of char : " << sizeof(char) << endl;
cout << "Size of int : " << sizeof(int) << endl;
cout << "Size of short int : " << sizeof(short int) << endl;
cout << "Size of long int : " << sizeof(long int) << endl;
cout << "Size of float : " << sizeof(float) << endl;
cout << "Size of double : " << sizeof(double) << endl;
cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

return 0;
}
```

This example uses **endl**, which inserts a new-line character after every line and << operator is being used to pass multiple values out to the screen. We are also using **sizeof()** operator to get size of various data types.

When the above code is compiled and executed, it produces the following result which can vary from machine to machine −

```sh
Size of char : 1
Size of int : 4
Size of short int : 2
Size of long int : 4
Size of float : 4
Size of double : 8
Size of wchar_t : 4
```

### Example

Following is another example:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {

    std::cout << "Int Min " << std::numeric\_limits<int>::min() << endl;
    std::cout << "Int Max " << std::numeric\_limits<int>::max() << endl;
    std::cout << "Unsigned Int  Min " << std::numeric\_limits<unsigned int>::min() << endl;
    std::cout << "Unsigned Int Max " << std::numeric\_limits<unsigned int>::max() << endl;
    std::cout << "Long Int Min " << std::numeric\_limits<long int>::min() << endl;
    std::cout << "Long Int Max " << std::numeric\_limits<long int>::max() << endl;

    std::cout << "Unsigned Long Int Min " << std::numeric\_limits<unsigned  long int>::min() <<endl;
    std::cout << "Unsigned Long Int Max " << std::numeric\_limits<unsigned  long int>::max() << endl;

}
```

## Derived Data Types

Data types which are obtained from pre-defined data types in C++ are known as Derived Data Types. These can be classified into four categories, namely −

### 1. Function

A [function](https://www.tutorialspoint.com/cplusplus/cpp_functions.htm) is the simplest form of user-defined data type. It includes a return type, a function name and input parameters.

#### Syntax

```cpp
return_type function_name(input_param1, input_param2){
<function_body>
}
```

#### Example

```cpp
#include <iostream>
using namespace std;

string func(int n){
//returns if n is odd or even
if(n%2) return "Given number is Odd !";
else return "Given number is Even !";
}
int main(){
int a;
//enter a number
cin>>a;
cout<<func(a);
//a simple function to check if
//number is odd or even
return 0;
}
```

##### Output

Given number is Even !

### 2. Array

An [array](https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm) is a series of elements of same data type. Elements of an array are stored in contiguous memory locations in the storage.

#### Syntax

```cpp
data_type array_name[array_size];
```

#### Example

```cpp
#include <iostream>
using namespace std;

int main(){
int arr[5]={1,2,3,2,1};
//define an integer array of size 5

for(auto it:arr)
cout<<it<<" ";
//print the elements of array

return 0;
}
```

##### Output

```sh
1 2 3 2 1
```

### 3. Pointer

A [pointer](https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm) is a reference to an element defined previously. The value of the pointer returns the address location of the element which is associated with it.

#### Syntax

```cpp
data_type * pointer_name=& variable_name;
```

#### Example

```cpp
#include <iostream>
using namespace std;

int main() {
int a=20;
//declare variable a
int *p= &a;
//assign pointer to a
cout<<"Address of variable a: "<<p<<endl;
cout<<"Value of variable a: "<<*p<<endl;

return 0;
}
```

##### Output

```sh
Address of variable a: 0x7ffc49a8637c
Value of variable a: 20
```

### 4. Reference

A [reference variable](https://www.tutorialspoint.com/cplusplus/cpp_references.htm) is used to create a copy of a variable with the same reference. Hence, changes made to the reference variable also reflect on the original variable.

#### Syntax

```cpp
data_type & reference_name= variable_name;
```

#### Example

```cpp
#include <iostream>
using namespace std;

int main(){
int c=11;
int& refer=c;

cout<<"Initially value of integer is: "<<c<<endl;

refer=121;
cout<<"After changing value using refer variable :"<<c<<endl;

return 0;
}
```

##### Output

```sh
Initially value of integer is: 11
After changing value using refer variable :121
```

## User-Defined Data Types

Data types which are defined by the user intuitively without using any pre-defined data types are known as User-Defined Data Types. These data types can be further categorized into five types, namely −

### 1. Class

A [class](https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm) is a defined in Object Oriented Programming as a custom data type which is used to construct an object. It is the framework of an object, and it can include constructors, methods and OOP concepts like Polymorphism, Inheritance, etc.

#### Syntax

```cpp
class Class_name{
<class body>

class_name(parameters) {
<constructor body>
}

return_type method_name(paremeters){
<method body>
}

}
```

#### Example

```cpp
#include <iostream>
using namespace std;

class TP{
public:
string tp;

      void print(){
         cout<<tp<<endl;
      }

};
int main(){
TP object;
object.tp="I Love Tutorialspoint !!!";
object.print();

return 0;
}
```

##### Output

```sh
I Love Tutorialspoint !!!
```

### 2. Structure (struct)

In [structure](https://www.tutorialspoint.com/cplusplus/cpp_data_structures.htm) data type, the user can introduce multiple primitive data types inside the struct body.

#### Syntax

```cpp
struct struct_name{
data_type1 var_name1;
data_type2 var_name2;

}
```

#### Example

```cpp
#include <iostream>
using namespace std;

struct TP{
string tp;
int grade;
};
int main(){
TP object;
object.tp="I Love Tutorialspoint !!!";
object.grade=10;

cout<<object.tp<<endl;
cout<<"How much would you rate it?"<<" : "<< object.grade;

return 0;
}
```

##### Output

```sh
I Love Tutorialspoint !!!
How much would you rate it? : 10
```

### 3. Union

Union is similar to a structure. In this, the memory location of all variables is same, and all variables share the same reference. Hence, a change in one value leads to all other values getting changed.

#### Syntax

```cpp
union union_name{
data_type var_name1;
data_type var_name2;
};
```

#### Example

```cpp
#include <iostream>
using namespace std;

union TP{
int tp1,tp2;
};
int main(){
union TP t;
t.tp1=2;
cout<<"Value of tp1 initially: "<<t.tp1<<endl;

t.tp2=4;
cout<<"When we change tp2, value of tp1 is : "<<t.tp1<<endl;

return 0;
}
```

##### Output

```sh
Value of tp1 initially: 2
When we change tp2, value of tp1 is : 4
```

### 4. Enumeration (Enum)

Enumeration or simply enum is a user-defined data type that is used to give name to integer constants in a program. This increases the user-readability of a program.

#### Syntax

```cpp
enum enum_name{
var_name1 , var_name2,
}
```

#### Example

```cpp
#include <iostream>
using namespace std;

enum TP{ C, Java, Python, Ruby, Kotlin, Javascript, TypeScript, Others};

int main(){
enum TP course;
cout<<"Which course do you love the most?"<<endl;

course=Kotlin;
cout<<"I love the "<<course+1<<"th course !!!";

return 0;
}
```

#### Output

```sh
Which course do you love the most?
I love the 5th course !!!
```

## typedef Declarations

You can create a new name for an existing type using **typedef**. Following is the simple syntax to define a new type using typedef −

```cpp
typedef type newname;
```

For example, the following tells the compiler that feet is another name for int −

```cpp
typedef int feet;
```

Now, the following declaration is perfectly legal and creates an integer variable called distance −

```cpp
feet distance;
```

## Enumerated Types

An enumerated type declares an optional type name and a set of zero or more identifiers that can be used as values of the type. Each enumerator is a constant whose type is the enumeration.

Creating an enumeration requires the use of the keyword **enum**. The general form of an enumeration type is −

```cpp
enum enum-name { list of names } var-list;
```

Here, the enum-name is the enumeration's type name. The list of names is comma separated.

For example, the following code defines an enumeration of colors called colors and the variable c of type color. Finally, c is assigned the value "blue".

```cpp
enum color { red, green, blue } c;
c = blue;
```

By default, the value of the first name is 0, the second name has the value 1, and the third has the value 2, and so on. But you can give a name, a specific value by adding an initializer. For example, in the following enumeration, **green** will have the value 5.

```cpp
enum color { red, green = 5, blue };
```

Here, **blue** will have a value of 6 because each name will be one greater than the one that precedes it.
