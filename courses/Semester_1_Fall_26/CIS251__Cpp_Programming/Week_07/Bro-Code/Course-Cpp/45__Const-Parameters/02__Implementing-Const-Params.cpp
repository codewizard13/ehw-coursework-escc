/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=dYVY1vnVWc54Czr0&t=14770

    **** CONST PARAMETERS ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates ...

    📝 Lessons Learned:
    - const parameter means we / others can't maliciously or inadvertently or 
      accidentally change the values we receive
    - with pass-by-value, const parameters clarify intent
    - with pass-by-reference, const parameters enforce security
    - useful so nobody can change values a reference is pointing to
    - useful so nobody can change the address a pointer is pointing to
    - #GOTCHA: With VSCODE and coderunning extension: if a previously-compiled
      program fails to re-compile and you know there are no errors, you must
      delete both the EXE file and tempCoderunner file

    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

void printInfo(const string name, const int age);

int main() {

    string name = "Bro";
    int age = 21;

    printInfo(name, age);

    return 0;
}

void printInfo(const string name, const int age) {
    // Without const params, these variables would be changeable.
    //  But, with const params we get an `assignment of read-only parameter`
    //  error.
    //
    // name = "";
    // age = 0;
    cout << name << '\n';
    cout << age << '\n';
}