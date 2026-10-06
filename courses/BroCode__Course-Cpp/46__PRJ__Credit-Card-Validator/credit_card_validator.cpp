/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=RTZV2vmUfDQRp0dF&t=14875

    **** PROJECT: Credit Card Validator ****

    Student: Eric Hepperle
    Created: 2026-10-05

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Portfolio Project : Use Luhn Algorithm to validate credit card numbers
        1. Double every second digit from right to left
           If doubled number is 2 digits, split them
        2. Add all single digits from step 1
        3. Add all odd numbered digits from right to left
        4. Sum results from steps 2 & 3
        5. If step 4 is divisible by 10, # is valid

    📝 Lessons Learned:
    - #GOTCHA #TIP: If we create a function with no body returning nothing we
      will get a warning; good practice to temporarily return 0 if the return
      type is int.
    - Can treat a string as an array of characters and we can iterate over that.
    - Find length of a string with [stringname].size()
    - The index of the last character in a string = myString.size() -1
    - For the credit card number, since there are an even number of characters,
      summing the even digits, to grab the 2nd to last even digit, we use
      myString.size() -2
    - #TIP: #DESIGN_RATIONALE: Using a string is a good design here because a
      card number is an identifier whose individual digits must be examined. 
      It also avoids issues such as losing leading zeroes or treating the whole
      value as a giant arithmetic number.
    - Subtracting '0' converts a digit character—such as '9'—into the 
      corresponding numeric digit—9.Subtracting '0' converts a digit
      character—such as '9'—into the corresponding numeric digit—9.
    
    References:
    - Blue Snap - Test Card Numbers: https://developers.bluesnap.com/reference/test-credit-cards
    - Concerning Reality - The Secret Algorithm in Your Credit Card Number: https://www.youtube.com/watch?v=Yr9s5NjsVAo
    - IBM - ASCII conversion table: https://www.ibm.com/docs/en/aix/7.2.0?topic=adapters-ascii-decimal-hexadecimal-octal-binary-conversion-table
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

const string CC_NUM = "6011000990139424";

int getDigit(const int number);
int sumOddDigits(const string cardNumber);
int sumEvenDigits(const string cardNumber);

int main() {

    string cardNumber;
    int result = 0;

    cout << "Enter a credit card #: ";
    cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if (result % 10 == 0) {
        cout << cardNumber << " is valid ";
    } else {
        cout << cardNumber << " is NOT valid ";
    }

    return 0;
}

// This name is vauge — a better name would be reduceDoubledDigit()
int getDigit(const int number) {

    // eg, 18 mod 10 = 8   and  
    //     18/10 = 1 (because int division drops the decimal) 
    //     1 mod 10 = 1
    //
    // Finally sum both numbers 8 + 1 = 9
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const string cardNumber) {

    int sum = 0;

    for (int i = cardNumber.size() - 1; i >= 0; i-=2) {

        // There's no need to double the odd digits
        sum += cardNumber[i] - '0';
    }

    return sum;
}

int sumEvenDigits(const string cardNumber) {

    int sum = 0;

    // Iterate over card number in reverse order
    // 1. Begin i at the 2nd to last position
    // 2. Continue while i greater than or equal to 0
    // 3. Decrement i by two to get every even digit
    
    // Plain Language: start at second digit from right,
    //  as long as current index is not less than zero,
    //  subtract two from index and repeat.
    for (int i = cardNumber.size() - 2; i >= 0; i-=2) {

        // Char '0' has a decimal value of 48 according to ASCII table,
        //  so we can subtract the character zero to get the INT value
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;

}
