/**
 * @file 104__Main-WIP.cpp
 *
 * @brief Week 8 C++ programming assignment: BankAccount class, objects,
 *        and encapsulation.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 8 Programming Assignment
 * @lesson_focus Object-Oriented Programming: Classes, Objects, and Encapsulation
 *
 * @instructions BankAccount Class: define a class with private account
 * holder/balance data, a constructor, getters, and deposit/withdraw methods
 * that preserve a nonnegative balance. Create and test multiple objects
 * in main().
 *
 * This program defines a BankAccount class with private account-holder
 * and balance data. Public getters provide controlled read access, while
 * deposit() and withdraw() validate transactions and preserve a nonnegative
 * balance.
 *
 * The program creates multiple BankAccount objects in main(), displays
 * their initial balances, tests valid and invalid deposits, tests valid
 * and excessive withdrawals, and displays the resulting balances.
 *
 * @author Eric L. Hepperle
 * @date 2026-10-11
 * @updated 2026-10-13
 * @version 1.04
 * @copyright Eric L. Hepperle
 *
 * @note This implementation uses hard-coded transaction values for testing.
 *       It does not implement PIN authentication, an interactive ATM menu,
 *       or transaction history.
 *
 * @warning The constructor does not currently reject a negative opening balance.
 * 
 * @par Lessons Learned
 * - 
 *
 * @par Bug Reports
 * Please report issues through GitHub:
 * https://github.com/codewizard13
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * @brief Models a simple bank account for the Week 8 OOP assignment.
 *
 * BankAccount demonstrates encapsulation by keeping the account holder's
 * name and balance private. Public getters provide read-only access to
 * that data, while deposit() and withdraw() control all balance changes.
 *
 * A deposit is accepted only when its amount is positive. A withdrawl is
 * accepted only when its amount is positive and does not exceed the
 * current balance, preserving a nonnegative balance.
 *
 * @note This class does not implement authentication , PIN entry, or an
 *       interactive ATM menu; main() creates and tests multiple
 *       account objects.
 *
 * @warning The constructor currently accepts a negative opening balance.
 *          Future work should validate it during object construction.
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


