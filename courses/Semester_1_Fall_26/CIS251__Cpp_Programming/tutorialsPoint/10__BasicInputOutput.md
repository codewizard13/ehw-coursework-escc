# C++ Basic Input/Output

The C++ standard libraries provide an extensive set of input/output capabilities which we will see in subsequent chapters. This chapter will discuss very basic and most common I/O operations required for C++ programming.

C++ I/O occurs in streams, which are sequences of bytes. If bytes flow from a device like a keyboard, a disk drive, or a network connection etc. to main memory, this is called **input operation** and if bytes flow from main memory to a device like a display screen, a printer, a disk drive, or a network connection, etc., this is called **output operation**.

## I/O Library Header Files

There are following header files important to C++ programs −

| Sr.No | Header File & Function and Description                                                                                                                                                                                                                                                             |
| ----- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1     | [**<iostream>**](/cpp_standard_library/iostream.htm)<br><br>This file defines the **cin, cout, cerr** and **clog** objects, which correspond to the standard input stream, the standard output stream, the un-buffered standard error stream and the buffered standard error stream, respectively. |
| 2     | [**<iomanip>**](/cpp_standard_library/iomanip.htm)<br><br>This file declares services useful for performing formatted I/O with so-called parameterized stream manipulators, such as **setw** and **setprecision**.                                                                                 |
| 3     | [**<fstream>**](/cpp_standard_library/fstream.htm)<br><br>This file declares services for user-controlled file processing. We will discuss about it in detail in File and Stream related chapter.                                                                                                  |
| 4     | **<bits/stdc++.h>**<br><br>This header file includes most of the standard C++ libraries, which adds a wide range of functionalities without the need to specify each library individually. This is particularly helpful during coding contests.                                                    |


## The Standard Output Stream (cout)

The predefined object **cout** is an instance of **ostream** class. The cout object is said to be "connected to" the standard output device, which usually is the display screen. The **cout** is used in conjunction with the stream insertion operator, which is written as << which are two less than signs as shown in the following example.

### Example

```cpp
#include <iostream>

using namespace std;

int main() {
char str\[\] = "Hello C++";

cout << "Value of str is : " << str << endl;
}
```

When the above code is compiled and executed, it produces the following result −

`Value of str is : Hello C++`

The C++ compiler also determines the data type of variable to be output and selects the appropriate stream insertion operator to display the value. The << operator is overloaded to output data items of built-in types integer, float, double, strings and pointer values.

The insertion operator `<<` may be used more than once in a single statement as shown above and **endl** is used to add a new-line at the end of the line.

## The Standard Input Stream (cin)

The predefined object **cin** is an instance of **istream** class. The cin object is said to be attached to the standard input device, which usually is the keyboard. The **cin** is used in conjunction with the stream extraction operator, which is written as >> which are two greater than signs as shown in the following example.

### Example


```cpp
#include <iostream>

using namespace std;

int main() {
char name\[50\];

cout << "Please enter your name: ";
cin \>> name;
cout << "Your name is: " << name << endl;

}
```

When the above code is compiled and executed, it will prompt you to enter a name. You enter a value and then hit enter to see the following result −

Please enter your name: cplusplus
Your name is: cplusplus

The C++ compiler also determines the data type of the entered value and selects the appropriate stream extraction operator to extract the value and store it in the given variables.

The stream extraction operator >> may be used more than once in a single statement. To request more than one datum you can use the following −

```cpp
cin >> name >> age;
```

This will be equivalent to the following two statements −

```cpp
cin >> name;
cin >> age;
```

## The Standard Error Stream (cerr)

The predefined object **cerr** is an instance of **ostream** class. The cerr object is said to be attached to the standard error device, which is also a display screen but the object **cerr** is un-buffered and each stream insertion to cerr causes its output to appear immediately.

The **cerr** is also used in conjunction with the stream insertion operator as shown in the following example.

### Example

```cpp
#include <iostream>

using namespace std;

int main() {
char str[] = "Unable to read....";

cerr << "Error message : " << str << endl;
}
```

When the above code is compiled and executed, it produces the following result −

```sh
Error message : Unable to read....
```

## The Standard Log Stream (clog)

The predefined object **clog** is an instance of **ostream** class. The clog object is said to be attached to the standard error device, which is also a display screen but the object **clog** is buffered. This means that each insertion to clog could cause its output to be held in a buffer until the buffer is filled or until the buffer is flushed.

The **clog** is also used in conjunction with the stream insertion operator as shown in the following example.

### Example

```cpp
#include <iostream>

using namespace std;

int main() {
char str[] = "Unable to read....";

clog << "Error message : " << str << endl;
}
```

When the above code is compiled and executed, it produces the following result −

```sh
Error message : Unable to read....
```

You would not be able to see any difference in cout, cerr and clog with these small examples, but while writing and executing big programs the difference becomes obvious. So it is good practice to display error messages using cerr stream and while displaying other log messages then clog should be used.

## Input/Output Using bits/stdc++

The **bits/stdc++.h** is a non-standard header file in C++, as it does not belong to the official C++ Standard Library. Instead, it is a GCC-specific header file that includes most of the standard libraries in C++. You can also use bits/stdc++.h for the input and output without using another library.

### Example

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
int number;
string name;

// #include <iostream>
// #include <string>
cout << "Welcome to TutorialsPoint!" << endl;

// Input of user's name and number
cout << "Please enter your name: ";
cin \>> name;
cout << "Please enter a number: ";
cin \>> number;
cout << "Hello," << name << " You entered " << number << endl;

// Demonstrating some STL features
// #include <vector>
vector<int\> numbers;
cout << "Enter 4 numbers: ";

for (int i = 0; i < 4; ++i) {
int temp;
cin \>> temp;
numbers.push_back(temp);
}
cout << "You entered the following numbers: ";
for (int num : numbers) {
cout << num << " ";
}
cout << endl;

// Sort and display the numbers
// #include <algorithm>
sort(numbers.begin(), numbers.end());
cout << "Sorted numbers: ";
for (int num : numbers) {
cout << num << " ";
}
cout << endl;

return 0;
}
```

When the above code is compiled and executed, it produces the following result −

```sh
Welcome to TutorialsPoint!
Please enter your name: Aman
Please enter a number: 2006
Hello, Aman You 2006
Enter 4 numbers: 2
0
0
6
You entered the following numbers: 2 0 0 6
Sorted numbers: 0 0 2 6
```

So here, instead of using these multiple headers such as,

```sh
- #include <iostream>
- #include <string>
- #include <vector>
- #include <algorithm>
```

We used simply `<bits/stdc++.h>` as it includes all the necessary standard libraries for input/output operations, string handling, dynamic arrays, and algorithms which simplifies your code and makes it cleaner and more convenient. It is especially used for competitive programming.
