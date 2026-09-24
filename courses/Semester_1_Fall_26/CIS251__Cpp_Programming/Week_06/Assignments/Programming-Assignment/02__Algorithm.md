### 📊 Pseudocode Algorithm

# Week 6 Programming Assignment - Arrays, Strings, and Sequential Data Processing

/*
    *** ALGORITHM: ***

    // DEFINE GLOBAL VARIABLES
    quiz_scores - array of doubles - Lets just use a fixed set of 5 scores
    (Scores: 90, 100, 100, 85.5, 46)

    // Set highest / lowest using sentinel values
    double highest = -999
    double lowest = 999
    double total
    double average

    // Since the array size/length is a calculation that
    takes up many chars, lets give it a shorter variable
    handle, making it easier to reuse:

    int array_len = sizeof(quiz_scores) / sizeof(double)

    // MAIN() return INT

    // DEFINE VARIABLES
    string student_name = "Joe Smith"
    - CREATE a string to store the 'Grade report for: ' part of the report heading (report_heading)
    - APPEND the student name onto report_heading - the construction lets us easily convert to recive the name as input if we chose at some point. it is "forward-thinking"

    // INITIATE the screen output decoration for a nicer UX using a line
    of asterisks.
    cout << "*********************************\n";
    - Display report_heading
    
    - Display the scores as a row for a sanity check. This would be a good candidate for abstracting to a function, but I didn't want to overthink the assignment and time is limited.

    // LOOP THROUGH EACH SCORE
        - NOTE: This is a fixed loop with zero input statements so
        there is not much tesiting needed past ensuring it works, since
        it will be the same result every time.

        // PRINT the current score
        // print a comma and a space as a separator, except for the last element

        // UPDATE TOTAL
        total = total + current score

        // UPDATE HIGHEST
        if current score is greater than highest, then highest is current score

        // UPDATE LOWEST
        if current score is lower than lowest, then lowest is current score

    END LOOP

    cout << "*********************************\n";

    // CALCULATE AVERAGE
    average = total / total number of elements in the array

    // SET PRECISION to 2 decimal places for correct decimal display

    // OUTPUT FINAL CALCULATIONS
    - Total
    - Average
    - Lowest Score
    - Highest Score

    cout << "*********************************\n";

    RETURN 0 for SUCCESS

*/