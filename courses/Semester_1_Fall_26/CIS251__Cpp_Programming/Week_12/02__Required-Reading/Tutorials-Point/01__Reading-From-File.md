# C++ Reading From File

[Previous](https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm) | 
[Quiz](https://www.tutorialspoint.com/cplusplus/quiz_on_cpp_reading_from_file.htm "Practice Quiz on C++ Reading From File") | 
[Next](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)

File I/O (Input/Output) in C++ is the process of reading and writing to files. C++ provides this for handling files through the standard library with `<fstream>` header file. [File I/O](https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm) allows programs to persist data, interact with external resources, and store/retrieve information beyond the scope of program execution.

## Types of File Streams

There are three primary types of file streams, where each is associated with different operations −

*   **ifstream (Input File Stream)** − This is used for reading data from a file.
*   **ofstream (Output File Stream)** − This is used for writing data to a file.
*   [**fstream (File Stream)**](https://www.tutorialspoint.com/cpp_standard_library/fstream.htm) − This is used for both input and output operations on a file. It combines the functionality of both ifstream and ofstream.

## Basic Steps in File I/O

Heres the given basic steps in file I/O −

### Opening a File

Before reading or writing to a file, it must be opened using one of the file stream classes. If the file is successfully opened, the program will proceed with I/O operations.

### Performing File Operations

You can read from or write to a file using the appropriate methods.

### Closing the File

After the file operations are completed, ***you should close the file to make sure that all data is flushed and the file is properly released.***

## Reading with ifstream (Stream Extraction Operator)

Using stream extraction operator (`>>`) is the simplest way to read data from a file in C++. This operator reads formatted data from a file, similar to how data is read from standard input.

### Example

Heres the given example for Reading with ifstream −

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
   std::ifstream inputFile("example.txt");  // Open the file for reading
   if (!inputFile) {
      std::cerr << "Error opening file!" << std::endl;
      return 1;
   }

   std::string word;
   while (inputFile >> word) {  // Reads until a whitespace is encountered
      std::cout << word << std::endl;  // Print each word from the file
   }

   inputFile.close();  // Close the file when done
   return 0;
}
```

Here, The `>>` operator reads data word by word, stopping at whitespace (spaces, newlines, etc.).

But it doesn't handle reading lines of text (as it stops at whitespace), and it can be tricky for reading complex data formats (like lines containing spaces).

## Using getline() to Read Lines

If you want to read an entire line or text, including steps you can use the getline() function. This function will read characters from the file until a newline character ('`\n`') is encountered.

### Example

Heres the given example for using `getline()` to read lines −

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
   std::ifstream inputFile("example.txt");  // Open the file for reading
   if (!inputFile) {
      std::cerr << "Error opening file!" << std::endl;
      return 1;
   }

   std::string line;
      while (std::getline(inputFile, line)) {  // Read a full line of text
      std::cout << line << std::endl;  // Output the line to the console
   }

   inputFile.close();  // Close the file when done
   return 0;
}
```

## Reading Binary Files (using read())

The above discussed methods are for text files, for binary files you can use the `read()` function to read raw binary data from a file.

### Example

Heres the given example for Reading Binary Files (using [read()](https://www.tutorialspoint.com/cpp_standard_library/cpp_basic_ios_read.htm)) −

```cpp
#include <iostream>
#include <fstream>

int main() {
   std::ifstream file("example.bin", std::ios::binary);

   // Check if the file was successfully opened
   if (!file) {
      std::cerr << "Error opening file!" << std::endl;
      return 1;
   }

   // Get the length of the file
   file.seekg(0, std::ios::end);
   std::streamsize size \= file.tellg();
   file.seekg(0, std::ios::beg);

   // Read the entire file content into a buffer
   char* buffer \= new char\[size\];
   file.read(buffer, size);

   // Print raw data (optional, for demonstration)
   for (std::streamsize i \= 0; i < size; ++i) {
      std::cout << std::hex << (0xFF & buffer\[i\]) << " ";  // Print byte in hex
   }

   delete\[\] buffer;
   file.close();
   return 0;
}
```

## Handling Errors in File I/O

Handling errors is important to ensure that your program behaves correctly when files are not available, can't be opened, or when unexpected conditions occur during reading/writing.

### Checking for Errors with `fail()`, `eof()`, and `good()`.

C++ provides several member functions of the ifstream/ofstream objects to check for various conditions.

*   **fail()**: Checks if a non-recoverable error occurred during I/O.
*   **eof()**: Checks if the end of file (EOF) was reached.
*   **good()**: Returns true if no error has occurred.

### Handling End-of-File (EOF)

When reading from a file, it's important to handle the case when you reach the end of the file. The standard approach is to use **[eof()](https://www.tutorialspoint.com/cpp_standard_library/cpp_ios_event_eof.htm) or [std::getline()](https://www.tutorialspoint.com/cpp_standard_library/cpp_basic_ios_getline.htm)** operators, which automatically stop when the end of the file is reached.

### Handling I/O Errors Gracefully

During file operations, you should check for **fail() or bad()** states to detect errors like unexpected end-of-file or data corruption.