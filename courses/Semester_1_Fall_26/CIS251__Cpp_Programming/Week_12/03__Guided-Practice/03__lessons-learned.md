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

- Include `<fstream>` and use `std::ofstream` so the compiler recognizes the file-output stream type; use `std::ios::app` when you want to append rather than overwrite.

- getline() is necessary when reading values with space, and/or a different delimiter like `|`

- When switching from `>>` to `getline()`, remember `std::ws`: `std::getline(inputFile >> std::ws, line);` removes leftover whitespace, including newlines, before reading the line. Reminder: `ws` skips all leading whitespace and blank lines—omit it when those must be preserved.

- `getline(stream >> ws, destination)` still requires a string destination; **`ws`** skips leading whitespace—it does not convert text to a number. It also skips blank lines, so use it only when that is intended.

- `clear()` resets stream flags, `seekg()` repositions an open stream, and `open()` opens a file. You cannot rewind a closed file without reopening it. Your existing `ws` usage can stay—it skips the space after `|` before reading the amount.

- When switching from `>>` to `getline()`, remember `std::ws`: `std::getline(inputFile >> std::ws, line);` removes leftover whitespace, including newlines, before reading the line. Reminder: `ws` skips all leading whitespace and blank lines—omit it when those must be preserved.

- The programmer should distinguish file existence from stream-opening success: `ofstream` can create a missing file before an `if` checks its state, and its default opening mode erases existing contents. An initial `ifstream` check avoids creating the file, while `ios::app` protects existing contents when opening for output.

- The programmer can test file-opening failure by specifying a nonexistent parent folder; a missing filename alone does not trigger failure because `ofstream` can create the file.

- Single quotes represent a character (`'Y'`), while double quotes represent a string literal (`"Y"`). Character-conversion functions such as `tolower()` require an individual character value rather than a string.

- A single character becomes a string through construction, such as `string(1, choice)`, rather than `static_cast<string>(choice)`. Formatted character input with `>>` skips whitespace, so detecting blank input requires a different input approach.

- `continue` skips the remaining statements in the current loop iteration, but the next step depends on the loop: a `do...while` checks its bottom condition, a `while` checks its top condition, and a conventional `for` executes its update expression before checking its condition. The loop body runs again only if the condition permits it.
