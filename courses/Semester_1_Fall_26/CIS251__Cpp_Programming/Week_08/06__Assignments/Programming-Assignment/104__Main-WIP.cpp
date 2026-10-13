/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 8 PROGRAMMING ASSIGNMENT — Object-Oriented Programming: Classes, Objects, and Encapsulation

    Student: Eric Hepperle
    Created: 2026-10-11
    Updated: 2026-10-13

    VERSION: 1.04

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



#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * 
 */
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