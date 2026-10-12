/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 8 PROGRAMMING ASSIGNMENT — Object-Oriented Programming: Classes, Objects, and Encapsulation

    Student: Eric Hepperle
    Created: 2026-10-11
    Updated: 2026-10-12

    VERSION: 1.03

    STATUS: WIP

    Instructions:
      BankAccount Class: define a class with private account holder/balance
      data, a constructor, getters, and deposit/withdraw methods that
      preserve a nonnegative balance. Create and test multiple objects
      in main().

    Notes:
    -

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
******************** ALGORITHM: *********************

## BANKACCOUNT CLASS: ----------

Private Data:
  - account holder
  - balance

Constructor:
  - Set the account holder and starting balance
  - Do not allow a negative starting balance

Getters:
  - Return the account holder
  - Return the balance

Methods:
  - Deposit money
  - Withdraw money


## MAIN: -----------------------

Create two BankAccount objects

Display each account's holder and starting balance

Deposit money into the first account
Withdraw money from the second account

Attempt a withdrawal greater than the available balance

Display both accounts' final balances
Check that the results are correct


## SHOW BALANCE: ---------------

Return the account's balance through its getter


## MAKE DEPOSIT: ---------------

Receive the deposit amount

If the amount is positive:
  Add it to the account's balance
Otherwise:
  Leave the balance unchanged


## WITHDRAW: -------------------

Receive the withdrawal amount

If the amount is positive and does not exceed the balance:
  Subtract it from the account's balance
Otherwise:
  Leave the balance unchanged

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount
{
public:
  // Constructor
  BankAccount(string account_holder, double balance)
  {
    this->account_holder = account_holder;
    this->balance = balance;
  }

  string account_holder;
  double balance;
};

void showBalance(BankAccount account);

int main()
{

  // DECLARE ACOUNT NUMBERS

  BankAccount account_01("Jennifer", 250);
  BankAccount account_02("Eric", 100);

  // Ensure 2 decimal point precision from here on
  cout << setprecision(2) << fixed;

  cout << "\n**************************************\n";

  showBalance(account_01);
  showBalance(account_02);

  cout << "**************************************\n\n";

  return 0;
}

void showBalance(BankAccount account)
{

  cout << account.account_holder;
  cout << " has a balance of $" << account.balance << endl;
}