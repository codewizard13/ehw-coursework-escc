# 🛠️ Incremental Development Log

## 📘 Assignment Information

- Course: CIS-251 — C++ Programming
- Assignment: Week 12 — Files, Streams, Persistence, and Program Testing
- Author: Eric L. Hepperle
- Program: Persistent Contact List, version 1.01

## 📋 Initial Design and Planning

I planned a program that writes hard-coded contact records to a text file, closes the file, and reads the records back for display. I figured some operations should be converted to reusablefunction, but I didn't know what to encapsulate until I had written the first draft. Ultimately I created helper functions for write file and read file functions because of all the validations needed, for better code organization.

- Used a comma to separate each contact’s name and email.
- Chose hard-coded test operations so the instructor could run the demonstrations without editing the source.
- Kept the implementation within introductory C++: functions, conditions, loops, strings, and file streams.
- Documented the program’s control flow in a separate algorithm.

## 🏗️ Incremental Implementation

### 1. Build the Basic File Operations

- Created output and input streams for writing and reading contacts.
- Added hard-coded contact records and displayed the stored names and emails.
- Used two `getline()` calls to read each comma-delimited name and its email.
- Changed the contact filename from `records.txt` to `contacts-list.txt`.

### 2. Extract the Record Functions

- Added `writeRecord()` to write one contact through an output-stream reference.
- Added `readFile()` to read and display contacts through an input-stream reference.
- Replaced manual record-writing statements with calls to `writeRecord()`.
- Kept file opening and closing in `main()`.

### 3. Add Error Checks

- Added checks for closed streams and stream failure states.
- Added a check after writing each record.
- Corrected `readFile()` to return `false` for failure rather than `1`, which means `true` in a Boolean function.
- Corrected the initial output-opening error message to describe the operation actually attempted.

### 4. Demonstrate Closing, Reopening, and Appending

- Added an intentional test that passes closed streams to both helpers.
- Reopened the output stream in append mode before adding James Brown.
- Reopened the input stream before displaying the updated contacts.
- Confirmed through code review that supplying a stream to a helper does not automatically reopen it.

### 5. Add a Startup Reset Choice

- Added a choice to clear existing contacts or preserve them before testing.
- Extracted the prompt and response validation into `getYesNo()`.
- Kept the overwrite-versus-append decision in `main()`.
- Corrected output-stream capitalization and scope issues.
- Reused the declared input stream instead of redeclaring it.

### 6. Add Backup and Empty-File Cases

- Added a backup operation that copies `contacts-list.txt` to `bkp_contacts.txt` using binary mode and `rdbuf()`.
- Added checks for backup file opening and output completion.
- Created `test_empty.txt` to exercise reading a file containing zero contacts.
- Displayed PASS or FAIL based on the empty-file reading function’s returned value.
- Replaced the unused cleanup-test placeholder with the empty-file case.

## 🔧 Troubleshooting and Lessons Learned

### Stream State Is Not File Existence

I clarified that `!file` checks the stream’s recorded failure state rather than directly checking whether a file exists. Checking immediately after opening provides context for identifying an opening failure.

### Closed Streams Must Be Reopened

An early append attempt reused streams that had already been closed. I corrected the sequence to explicitly reopen output before writing and input before reading again.

### Keep File Responsibilities Clear

I removed closing from `readFile()` so that `main()` consistently manages opening and closing. The helper functions use the supplied streams and report their results.

### Keep Error Handling Proportional

I retained simple helper calls for the writing demonstrations rather than adding a separate failure-exit block around every call. The helpers display errors, but `main()` does not stop on every returned `false`.

## 🧪 Current Test Coverage

1. Write three hard-coded contacts.
2. Read and display stored contacts.
3. Reject closed input and output streams.
4. Reopen the file and append one contact.
5. Copy the contact file to a backup.
6. Read an empty file without displaying contacts.

Actual results and pass/fail decisions belong in the test table after running the program.

## 🧹 Documentation and Remaining Cleanup

- Updated the algorithm to include the startup choice, helper functions, backup, and empty-file demonstration.
- Kept algorithm descriptions consistent with implemented checks rather than proposed improvements.
- Identified that the empty-file “Verified” message is unconditional and should not be treated as an automated check of console output.
- Retained manual inspection for contact contents and backup equality.

---