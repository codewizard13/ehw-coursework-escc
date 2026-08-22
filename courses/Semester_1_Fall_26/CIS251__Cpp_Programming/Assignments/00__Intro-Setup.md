<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# ✅ CIS 251 - C++ Programming:  Introduction & Setup

> This doc covers the introductory course/topic orientation, environment setup, etc...


## Create First C++ Hello World Program

> - [ ] Accept **Cyber Central** invite ⚠️ #GOTCHA: No invite received - Emailed instructor yesterday and today


The "Hello World" program is the quintessential introductory application the student will build to get a quick feel for the basics of displaying text on the screen.

- [x] Create student collab Discord server

- [x] Installed VSCODE
- [x] Install [MYSYS2](https://www.msys2.org/) C++ compiler and run this command at the end `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`
- [x] Add mysys64 to the Windows PATH environment variable

**Install VSCODE Extensions**

- [x] Install [Microsoft C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extension  
- [x] Install [Code Runner (by Jun Han)](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
- [x] Reboot PC for PATH variables to propagate and take effect

**Create and run first program**

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

#### **💡 Crucial Student Troubleshooting & Tips**

- **📌 #TIP**: The Code Runner "Play" button is not a blue pause (⏸️) emoji, but rather a triangle play button outline that is barely visible in the top right. Easiest to use the keyboard shortcut of `CTRL + ALT + N`
- **Code Runner Terminal Fix (Required for User Inputs)**: By default, Code Runner displays output in a read-only tab. If your assignment requires typing inputs into the program, you must change this setting:
    1.  Open VS Code Settings (`Ctrl+,` or `Cmd+,`).
    2.  Search for `code-runner.runInTerminal`.
    3.  **Check the box** to enable it. This forces your code to execute in the interactive Terminal.
- **⚠️ #GOTCHA**: Reboot your Windows PC so the systems can register the new path variables, else you might get the 'g++ not found` error when trying to run in console

