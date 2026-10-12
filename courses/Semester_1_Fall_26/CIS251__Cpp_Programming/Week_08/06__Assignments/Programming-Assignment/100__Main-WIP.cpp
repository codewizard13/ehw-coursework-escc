/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 8 PROGRAMMING ASSIGNMENT — Object-Oriented Programming: Classes, Objects, and Encapsulation

    Student: Eric Hepperle
    Created: 2026-10-11

    VERSION: 1.0

    STATUS: WIP - Algorithm in progress; CODE to come

    Instructions:
      BankAccount Class: define a class with private account holder/balance
      data, a constructor, getters, and deposit/withdraw methods that
      preserve a nonnegative balance. Create and test multiple objects
      in main().

    Notes:
    - FIRST crack at figuring out the algorithm without using AI

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
******************** ALGORITHM: *********************

INCLUDE iostream
INCLUDE string

USING NAMESPACE STD

Define CLASS BankAccount:
- Constructor: STRING account_holder, DOUBLE balance

Declare Functions:
- void showBalance( double balance )
- double deposit()
- double withdraw( double balance )

## MAIN: -----------------------


Declare Variables:
  - double balance = 0
  - int menu_choice = 0

[DO]

  Show pretty banking menu with numbered choices:
  Welcome user to the program and identify the program as Banking ATM simulator

    1. Show Balance
    2. Deposit Money
    3. Withdraw Money
    4. Exit

  SWITCH menu_choice
    CASE 1 (Show Balance): showBalance(balance) then BREAK
    CASE 2 (Deposit Money): Add deposit amount to current balance
    CASE 3 (Withdraw Money): 
    CASE 4 (Exit): Print "Thanks for visiting - come back again!"
    DEFAULT: Print "Invalid Choice."

[WHILE menu_choice NOT 4 (the exit option)]

## SHOW BALANCE: ---------------

## MAKE DEPOSIT: ---------------

## WITHDRAW: -------------------

---
1. Create BankAccount class
  - private: username, password, account name, last transaction, balance
  - constructor: username

Show Balance
Make Deposit
Withdraw

*/

#include <iostream>
using namespace std;


class BankAccount {

};


int main() {


  return 0;
}