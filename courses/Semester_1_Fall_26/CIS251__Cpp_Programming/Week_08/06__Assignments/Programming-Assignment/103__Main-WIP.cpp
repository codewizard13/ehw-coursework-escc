/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 8 PROGRAMMING ASSIGNMENT — Object-Oriented Programming: Classes, Objects, and Encapsulation

    Student: Eric Hepperle
    Created: 2026-10-11
    Updated: 2026-10-12

    VERSION: 1.03

    STATUS: WIP — OOP bank accounts with private data, validated
      deposits/withdrawals, overdraft protection, and multiple-object tests.

    Instructions:
      BankAccount Class: define a class with private account holder/balance
      data, a constructor, getters, and deposit/withdraw methods that
      preserve a nonnegative balance. Create and test multiple objects
      in main().

    Notes:
    - CONVERT account_holder and balance to private variables
    - CREATE getters for private variables
    - ADD a public account number variable
    - USE setfill('0') << setw(3) to display the account number as 3 digits
    - USE setfill(' ') to reset setfill() back to default
    - CREATE more descriptive account names, eg, `jen_acct` instead
        of `account_01`
    - METHOD deposit() works! Also, correctly rejects negative values
    - Adds success/failure return values to `deposit()` and `withdraw()`, 
        and captures the prior balance in `old_bal` for
        before-and-after reporting.
    - Validates transaction amounts before modifying `balance`, so rejected
        deposits and withdrawals leave the account unchanged.
    - Prevents overdrafts by rejecting withdrawals that exceed the
        current balance.
    - Adds transaction tests in `main()` and passes `BankAccount` objects to
       `showBalance()` by value, creating copies of the accounts.

    Future Improvements (suggested by AI):
    - Move `showBalance()` into `BankAccount` as a public method so the class 
        owns its display behavior.
    - Make `acct_no` private and expose it through a getter, matching the
        encapsulation used for account holder and balance.
    - Validate the constructor’s opening balance so an account cannot be 
        created with a negative starting balance.
    - Replace hard-coded transaction amounts with a menu or user-input flow so
        the program can accept interactive transactions.

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
  - ??? Do not allow a negative starting balance (not sure if this is necessary?)

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
private:
  string account_holder = "";
  double balance = 0.0;

public:
  int acct_no = 0;

  // Constructor
  BankAccount(int acct_no, string account_holder, double balance)
  {
    this->acct_no = acct_no;
    this->account_holder = account_holder;
    this->balance = balance;
  }

  string getAccountHolder()
  {
    return account_holder;
  }

  double getBalance()
  {
    return balance;
  }

  bool deposit(double amount)
  {
    double old_bal = balance; // temp var to store current balance

    cout << "Depositing $" << amount << " in " << account_holder << "'s account ...\n";
    if (amount <= 0)
    {
      cout << " - Invalid input: deposit amount must be at least $1.\n";
      cout << " - " << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      return false;
    }

    balance += amount;

    cout << " - Success: Deposited $" << amount << ".\n";
    cout << " - Old Balance: $" << old_bal << " | New balance: $" << balance;
    cout << "\n";

    return true;
  }

  bool withdraw(double amount)
  {
    double old_bal = balance; // temp var to store current balance

    cout << "Withdrawing $" << amount << " from " << account_holder << "'s account ...\n";

    // Reject if amount is negative or zero
    if (amount <= 0)
    {
      cout << " - Invalid input: withdrawal amount cannot be negative. ";
      cout << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      cout << endl;
      return false;
    }

    // Reject if (balance minus amount) is negative
    if (balance - amount < 0)
    {
      cout << " - Insufficient Funds. ";
      cout << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      cout << endl;
      return false;
    }
    balance -= amount;

    cout << " - Success: Withdrew $" << amount << ".\n";
    cout << " - Old Balance: $" << old_bal << " | New balance: $" << balance << "\n";
    cout << "\n";

    return true;
  }
};

void showBalance(BankAccount account);

int main()
{

  string bar = "**************************************";

  // DEFINE BANK ACCOUNTS
  BankAccount jen_acct(001, "Jennifer", 250);
  BankAccount eric_acct(002, "Eric", 100);

  // Ensure 2 decimal point precision from here on
  //  so dollar amounts display correctly
  cout << setprecision(2) << fixed;

  // cout << "\n************ SHOW BALANCE ************\n";

  cout << "\n_________BANK ACCOUNT SIMULATOR _____________\n";

  cout << "\n************ SHOW START BALANCE ******\n\n";

  showBalance(jen_acct);
  showBalance(eric_acct);

  cout << "\n************ MAKE DEPOSITS************\n";

  cout << "\n## Testing: Negative deposit\n";
  jen_acct.deposit(-200.00);

  cout << "\n## Testing: Positive deposit\n";
  jen_acct.deposit(70.50);

  cout << "\n\n************ MAKE WITHDRAWaLS *********\n\n";

  jen_acct.withdraw(200.00);
  eric_acct.withdraw(500.00);

  cout << "\n************ SHOW END BALANCE ********\n\n";

  // jen_acct.showBalance()

  cout << "\n_________________ END PROGRAM _______________\n\n";
  return 0;
}

void showBalance(BankAccount account)
{

  cout << "Account #";
  cout << setfill('0') << setw(3) << account.acct_no << setfill(' ');
  cout << " belongs to " << account.getAccountHolder();
  cout << " and has a balance of $" << account.getBalance() << endl;
}