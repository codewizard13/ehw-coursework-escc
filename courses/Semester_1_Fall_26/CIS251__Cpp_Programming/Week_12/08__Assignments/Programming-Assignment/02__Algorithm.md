## 📊 Pseudocode Algorithm

# WEEK 12 PROGRAMMING ASSIGNMENT — Files, Streams, Persistence, and Program Testing

### 🏗️ Define the Helper Functions

1. Define `writeRecord`:
   - Receive an output-stream reference, name, and email.
   - If the file is closed or the stream reports failure, display an error and return `false`.
   - Write the name and email as one comma-delimited record.
   - If writing fails, display an error and return `false`.
   - Display the successful-write message and return `true`.

2. Define `readFile`:
   - Receive an input-stream reference and filename.
   - If the file is closed or the stream reports failure, display an error and return `false`.
   - While a comma-delimited name and its email can be read, display the contact.
   - Return `true`; leave closing to the caller.

3. Define `getYesNo`:
   - Display the supplied prompt.
   - Read responses until lowercase `y` or `n` is entered; then return `true`.
   - Reprompt after invalid responses.
   - Return `false` if input cannot be read.

### ⚙️ Initialize the Program

4. Display the opening message. Set the contact filename to `contacts-list.txt` and the backup filename to `bkp_contacts.txt`. Declare the reusable streams.

5. Ask whether to clear existing contacts:
   - If input cannot be read, display an error and end with failure.
   - For `y`, open the contact file in overwrite mode.
   - For `n`, open it in append mode.
   - If opening fails, display an error and end with failure.

### 🧪 Run the Tests

6. Display a numbered heading before each test.

7. Test writing records:
   - Call `writeRecord` for Michael Jackson, Scottie Pippin, and Janet Jackson using their hard-coded emails.
   - Close output.
   - Expected: three contacts are added, preserving earlier contacts if append mode was chosen.

8. Test reading records:
   - Open the contact file and call `readFile`.
   - Close input; if the function returned `false`, end with failure.
   - Expected: all stored contacts display in order.

9. Test closed-stream rejection:
   - Without reopening either stream, attempt to write James Brown and read the file.
   - Expected: both helpers report errors and return `false`; no contact is added or displayed.

10. Test appending:
    - Reopen output in append mode, write James Brown, and close output.
    - Reopen input, display the contacts, and close input.
    - Expected: existing contacts remain, with James Brown last.

11. Test backup creation:
    - Open the contact file for binary input and the backup for binary output.
    - If either opening fails, display an error and end with failure.
    - Copy the source buffer using `rdbuf()` and close both streams.
    - If backup output reports failure, display an error and end with failure.
    - Expected: the backup matches the contact file.

12. Test an empty file:
    - Create and close `test_empty.txt`, then open it for input.
    - If setup fails, display an error and end with failure.
    - Call `readFile`, close input, and display PASS or FAIL from its result.
    - Display the current verification message.
    - Expected: no contacts display, and `readFile` returns `true`.

### 🏁 Finish

13. Display the ending message and return success.
