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
