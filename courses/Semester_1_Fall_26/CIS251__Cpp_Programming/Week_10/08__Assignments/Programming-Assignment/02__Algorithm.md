## 📊 Pseudocode Algorithm

# WEEK 10 PROGRAMMING ASSIGNMENT — Operator Overloading, Enumerations, and Interface Design

### 🏗️ Define the Class and Units

1. Define a `Unit` enum with inch, foot, and mile choices.
2. Create the `Distance` class with private endpoints, unit, and distance members; default numeric values to zero and the unit to inches.
3. Provide constructors for default values or supplied endpoints and an optional unit; calculate distance as the absolute endpoint difference.
4. Provide a display method for the endpoint calculation, distance, and singular or plural unit label.
5. Overload `+` to add corresponding endpoints, recalculate distance, retain the left operand’s unit, and return the result.

### 🧪 Run and Display Tests

6. Start the program, display the opening message, and set numeric output to two decimal places.
7. Create and display tests for default construction, supplied endpoints, two-object addition, temporary-object addition, and chained addition.
8. Create and display tests for reversed and negative endpoints, singular and plural unit labels, opposite endpoint differences, and addition retaining feet.

### 🏁 Finish

9. Display the end-program message and end the program.
