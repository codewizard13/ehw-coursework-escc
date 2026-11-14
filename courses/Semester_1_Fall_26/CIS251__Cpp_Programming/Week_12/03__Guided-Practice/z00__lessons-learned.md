<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren
>
> Week 12 Overview - Files, Streams, Persistence, and Program Testing

# 🎓 Lessons Learned > Guided Practice

## 📁 File Streams and Opening Modes

- File-stream types require `<fstream>`. `std::ofstream` opens files for output; its default mode creates missing files and erases existing contents. `std::ios::app` preserves existing contents and appends new output.
  - 🪝 Gotcha: Opening an existing file with the default output mode can erase its contents before any new records are written.

- File existence and successful opening are different checks. An `ofstream` may create a missing file before its state is checked. An initial `ifstream` check avoids creating the file, but an opening failure does not necessarily mean the file is absent.
  - 🪝 Gotcha: A successful output-stream check does not prove the file existed beforehand. Likewise, a failed opening should not automatically produce a “file does not exist” message.

- A nonexistent parent folder provides a way to test file-opening failure. A missing filename alone may not cause failure because `ofstream` can create the file.
  - 🪝 Gotcha: Testing with a new filename in an existing, writable folder may exercise successful file creation instead of the intended error-handling branch.

## 📖 Reading Lines and Handling Whitespace

- `std::getline()` reads text containing spaces and supports a custom character delimiter, such as `'|'`.
  - 🪝 Gotcha: Formatted string input with `>>` stops at whitespace. Also, a custom delimiter is a character (`'|'`), not a string literal (`"|"`).

- When switching from formatted input (`>>`) to `getline()`, `std::getline(stream >> std::ws, destination)` skips leftover whitespace before reading. However, `std::ws` skips all leading whitespace—including newlines and blank lines—so it should be omitted when those must be preserved or detected.
  - 🪝 Gotcha: Without handling a leftover newline, `getline()` may immediately read an empty line. Adding `std::ws` indiscriminately creates a different problem: blank responses are skipped instead of being available for validation.

- `getline()` requires a string destination. Adding `std::ws` changes whitespace handling; it does not convert text into a number.
  - 🪝 Gotcha: A field containing digits is still text when read with `getline()`. An `int` or `double` cannot replace its string destination; numeric conversion or numeric extraction is a separate operation.

- After reading through a delimiter such as `'|'`, `std::ws` can skip spaces before the next field when that behavior is intended.
  - 🪝 Gotcha: `std::ws` is not limited to the single space after the delimiter. It can also skip newlines, potentially moving into the next record if the expected field is empty.

## 🔄 Stream State and Repositioning

- `clear()` resets stream-state flags, `seekg()` repositions an open input stream, and `open()` opens a file. To reread an open file after reading to failure at its end, the stream flags should be cleared before seeking back to the beginning. A closed file must be reopened before it can be read again.
  - 🪝 Gotcha: `clear()` does not rewind the file, and `seekg(0)` does not reopen a closed file. Repositioning alone is also insufficient when a failed read has left the stream’s failure flag set.

## 🔤 Characters, Strings, and Input Validation

- Single quotes represent a character (`'Y'`); double quotes represent a string literal (`"Y"`). Character-conversion functions such as `tolower()` operate on individual character values rather than entire strings.
  - 🪝 Gotcha: Changing a choice variable from `char` to `std::string` also requires changing its comparisons from `'y'` to `"y"`. Passing the entire string to `tolower()` does not convert it.

- A single character can become a string through construction, such as `std::string(1, choice)`, rather than `static_cast<std::string>(choice)`.
  - 🪝 Gotcha: A cast is not a universal conversion tool. In this constructor, `1` specifies the number of copies, and `choice` supplies the character—not a numeric value to format.

- Formatted character input with `>>` skips whitespace. Detecting blank input requires a different approach, such as reading a complete line with `getline()` without `std::ws`.
  - 🪝 Gotcha: Pressing Enter does not provide a character for `cin >> choice`; the extraction continues waiting for non-whitespace input. Reading a complete line also allows validation to reject the entire answer `"yes"` rather than accepting only its first character.

## ⏭️ Loop Control

- `continue` skips the remaining statements in the current iteration. The next step depends on the loop:
  - A `do...while` checks its bottom condition.
  - A `while` checks its top condition.
  - A conventional `for` executes its update expression before checking its condition.

  The loop body runs again only if the condition permits it.

  - 🪝 Gotcha: `continue` does not jump directly to the first statement in the loop body. In a `do...while`, the bottom condition is still evaluated. If no statements remain before that condition, `continue` is unnecessary.


- - - - - - - -

## UNSORTED

- File-output streams should be passed to functions by reference, such as `ofstream& file`, so the function uses the existing stream.
  - 🪝 Gotcha: `ofstream file` attempts to copy the stream, but `ofstream` cannot be copied. The `&` belongs in the function parameter; the call remains `addRecord(name, amount, recordsFile)`.



- **Declaration / prototype**: A declaration introduces the function’s name, return type, and parameter types to the compiler; tells the compiler **how the function can be called**, but does not provide its implementation, A standalone declaration like this is commonly called a **function prototype**:

    ```cpp
    bool addRecord(string full_name, double amount, ofstream& file);
    ```

- A **function definition** supplies the function body—the code executed when the function is called. Your current body simply returns `true`; it does not yet add a record.

    ```cpp
    bool addRecord(string full_name, double amount, ofstream& file)
    {
        // Record-writing code will go here.
        return true;
    }
    ```
  - 🪝 Gotcha: An unfinished body is still a body. “Not implemented yet” does not mean “only a prototype.”
    - Ends with `;` instead of a body → declaration/prototype.
    - Includes `{ ... }` → definition, even when the body is only placeholder code.
    - Adding `{ return true; }` makes it a definition with a placeholder body—not a prototype waiting to be completed.

---


## 📖 Reading Lines and Skipping Blank Input

- `std::getline(inputFile, line)` reads one complete line into a string. An empty line can be skipped with `if (line.empty()) continue;`.
  - 🪝 Gotcha: `getline()` removes the newline delimiter instead of storing it in the string. Test `line.empty()`, not `line == "\n"`.

- An empty string and a whitespace-only string are different. `line.empty()` detects a string containing no characters; it does not detect a line containing spaces or tabs. To skip both, use:

  ```cpp
  if (line.find_first_not_of(" \t\r\n\v\f") == std::string::npos)
  {
      continue;
  }
  ```

  - 🪝 Gotcha: `find_first_not_of()` searches for a character outside the supplied whitespace set. Returning `std::string::npos` means no such character exists, so the line is empty or contains only those whitespace characters.

- `continue` skips the remaining statements in the current loop iteration. In a `while (std::getline(inputFile, line))` loop, the next condition check attempts to read the next line.
  - 🪝 Gotcha: Place the blank-line check before conversion, accumulation, and counting so skipped lines do not reach those operations.


## 🔢 Converting Text to Integers

- `std::stoi(line)` converts text to an `int` and is declared in `<string>`. When input is expected to contain valid integers, conversion can be as simple as:

  ```cpp
  int number = std::stoi(line);
  ```

  - 🪝 Gotcha: Do not add elaborate validation unless the program needs it. Converting expected numeric input and verifying that an entire line contains exactly one integer are different requirements.

- `stoi()` accepts leading whitespace and an optional sign, then converts the numeric beginning of the string.
  - 🪝 Gotcha: Successful conversion does not prove the entire string is an integer. `stoi("42abc")` returns `42`, and `stoi("3.14")` returns `3`.

- `stoi()` throws `std::invalid_argument` when no conversion is possible and `std::out_of_range` when the converted value cannot fit in an `int`.
  - 🪝 Gotcha: Skipping empty strings does not eliminate all conversion failures. Text such as `"hello"` or a whitespace-only string still cannot be converted, and an oversized integer can also fail.

- When strict whole-line validation is required, `std::istringstream` from `<sstream>` can extract an integer, consume trailing whitespace with `std::ws`, and check whether the stream has reached its end:

  ```cpp
  std::istringstream lineStream(line);
  int number;

  if (!(lineStream >> number))
  {
      continue;  // Conversion failed
  }

  lineStream >> std::ws;

  if (!lineStream.eof())
  {
      continue;  // Non-whitespace content remains
  }
  ```

  - 🪝 Gotcha: Integer extraction alone can accept a numeric prefix. Checking the remaining input is what rejects `"42abc"`, `"3.14"`, and `"42 99"` while allowing surrounding whitespace.


## ➗ Integer Division and Average Calculations

- Dividing two integers performs integer division. Assigning the result to a `double` afterward does not restore the discarded fractional part.

  ```cpp
  double average = 7 / 2;  // Stores 3.0, not 3.5
  ```

  - 🪝 Gotcha: The destination variable’s type does not determine how the division on the right-hand side is performed.

- Multiplication and division have equal precedence and group left to right. Therefore:

  ```cpp
  double calcAvg = calcTotal / lineCount * 1.0;
  ```

  groups as:

  ```cpp
  double calcAvg = (calcTotal / lineCount) * 1.0;
  ```

  - 🪝 Gotcha: Multiplying by `1.0` after integer division is too late. The fractional part has already been discarded.

- Make either operand a floating-point value before division. Parenthesizing the denominator multiplication works:

  ```cpp
  double calcAvg = calcTotal / (lineCount * 1.0);
  ```

  An explicit conversion also works:

  ```cpp
  double calcAvg = static_cast<double>(calcTotal) / lineCount;
  ```

  - 🪝 Gotcha: The important distinction is not merely whether `1.0` appears somewhere in the expression. It must affect an operand before the division occurs.

- Check that the count is nonzero before calculating an average:

  ```cpp
  if (lineCount == 0)
  {
      cerr << "No numbers to average.\n";
      return 1;
  }
  ```

  - 🪝 Gotcha: An empty file—or a file whose entries are all skipped—leaves no numbers to average. Handle that case before dividing.


## 🛠️ Code Runner and Stale Temporary Files

- In this debugging session, the stale temporary Code Runner file caused the displayed result not to reflect the updated source.
  - 🪝 Gotcha: A correct source-code change can appear ineffective when a different or outdated file is being compiled or run. Verify the active source and execution target before repeatedly changing valid code.

- This statement was valid in the shown location inside `main()`:

  ```cpp
  double calcAvg = calcTotal / (lineCount * 1.0);
  ```

  - 🪝 Gotcha: The reported “`lineCount` does not name a type” error did not match the valid statement being discussed. That mismatch was a clue to check the actual compilation target rather than assume the parentheses were wrong.