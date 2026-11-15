# C++ Files

The `fstream` library allows us to work with files.

To use the `fstream` library, include both the standard `<iostream>` **AND** the `<fstream>` header file:

### Example

#include <iostream>  
#include <fstream>

There are three classes included in the `fstream` library, which are used to create, write or read files:

| Class | Description |
| --- | --- |
| `ofstream` | Creates and writes to files |
| `ifstream` | Reads from files |
| `fstream` | A combination of ofstream and ifstream: creates, reads, and writes to files |

- - -

## Create and Write To a File

To create a file, use either the `ofstream` or `fstream` class, and specify the name of the file.

To write to the file, use the insertion operator (`<<`).

### Example

#include <iostream>  
#include <fstream>  
using namespace std;  
  
int main() {  
  // Create and open a text file  
  ofstream MyFile("filename.txt");  
  
  // Write to the file  
  MyFile << "Files can be tricky, but it is fun enough!";  
  
  // Close the file  
  MyFile.close();  
}

#### Why do we close the file?

It is considered good practice, and it can clean up unnecessary memory space.

- - -

Ad

[REMOVE ADS](https://order.w3schools.com/plans)

- - -

## Read a File

To read from a file, use either the `ifstream` or `fstream` class, and the name of the file.

Note that we also use a `while` loop together with the `getline()` function (which belongs to the `ifstream` class) to read the file line by line, and to print the content of the file:

### Example

// Create a text string, which is used to output the text file  
string myText;  
  
// Read from the text file  
ifstream MyReadFile("filename.txt");  
  
// Use a while loop together with the getline() function to read the file line by line  
while (getline (MyReadFile, myText)) {  
  // Output the text from the file  
  cout << myText;  
}  
  
// Close the file  
MyReadFile.close();

[Run example »](showcpp.asp?filename=demo_files_read)

- - -

## Exercise?**What is this?**  
Test your skills by answering a few questions about the topics of this page

Which C++ library allows us to work with files?

  

filestreams

fstream

string

vector

  
Submit Answer »

- - -

## Complete <fstream> Reference

For a complete reference of <fstream> classes and functions, go to our [C++ fstream Reference](cpp_ref_fstream.asp).

- - -

  
